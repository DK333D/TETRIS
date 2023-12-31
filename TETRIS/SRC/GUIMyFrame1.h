﻿#ifndef __GUIMyFrame1__
#define __GUIMyFrame1__
/**
@file
Subclass of MyFrame1, which is generated by wxFormBuilder.
*/
#include "GUI.h"
#include <cstdlib>
//// end generated include
#include <wx/dcmemory.h>
#include <wx/dcclient.h>
#include <wx/dcbuffer.h>
#include <wx/msgdlg.h>
#include <wx/wxprec.h>
#include <wx/msgdlg.h>


struct Square
{
	Square() {}
	Square(wxBitmap im, int i, int j) : image{ im }, x{ i }, y{ j } {}

	wxBitmap image;

	//coordinates
	int x;
	int y;
};

/** Implementing MyFrame1 */
class GUIMyFrame1 : public MyFrame1
{
public:
	/** Constructor */
	GUIMyFrame1(wxWindow* parent);

	void OnQuit(wxCommandEvent& event);	//quit event
	void OnButtonStartClicked(wxCommandEvent& WXUNUSED(event));
	void OnRadioImage(wxCommandEvent& event);
	void OnRadioElements(wxCommandEvent& event);
	void OnRadioTempo(wxCommandEvent& event);


	// event functions
	void OnSize(wxSizeEvent& event) override;
	void StartTimer(wxTimerEvent& e) override;
	void Game();

	// is tile on right place
	bool IsOnPlace(wxImage& image, int& i, int& j, int& k,int& rotation,int& mirror);
	void GetStarted();	

	//vector of tiles
	std::vector<Square> v;

	//// end generated class members
	void Repaint();

	~GUIMyFrame1();
	

	//menu
	wxMenuBar* menubar;
	wxMenu* file;
	wxMenu* imp;
	wxMenuItem* quit;
	wxMenuItem* newGame;

	//timer
	wxTimer* timer;

	wxImage img_org;	// original image
	wxImage img_cpy;	// a copy of the original image
	wxImage img_tmp;	// a temporary image


	wxClientDC* dc_right;
	wxClientDC* dc_left;

	int height;
	int width;
	int shiftAmount;
	int moving_y = 0; // tile position
	int moving_y_change = 4; // tile hop

	int row = 0, col = 0;

	//time as second-to check a difference
	wxDateTime started;
	int sec;
	//int now_sec;

	//tiles

	int x;	// tiles in row
	int y;	// tiles in column; counted automatically
	double a;	//tile's width
	double b;	//tile's height
	int l;

	wxImage** images;
	std::vector<Square> squares;

	void DoImageTab();
};
#endif
