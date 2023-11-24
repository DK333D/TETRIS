/*****************************************************************//**
 * \file   main.cpp
 * \brief  The most important file. Initialisation of the game takes place here.
 * 
 * \date   June 2023
 *********************************************************************/

#include <wx/wx.h>
#include "GUIMyFrame1.h"

/**
 * @brief MyApp is a hook that allows us to communicate wxWidget
 * 
 * We know when wxWidget is ready so that we can start calling out initialisation functions.
 */
class MyApp : public wxApp {

public:
	/**
	 * @brief During app initialisation
	 * 
	 * \return Status of initialisation. true means success
	 */
	virtual bool OnInit();

	/**
	 * @brief It is called after 
	 * 
	 * \return 
	 */
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp); //!< We are using macro that initializes wxWidget app and then boots our game functionality

bool MyApp::OnInit()
{
	wxImage::AddHandler(new wxJPEGHandler); //!< adding JPEG handler to be able to use JPEG files
	wxImage::AddHandler(new wxPNGHandler);  //!< adding PNG handler to be able to use PNG files

	wxImage image; //!< variable for background image
	wxLogNull logNo;
	if (!image.LoadFile("mount1_half.png")) //!< loding background image
	{
		wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowa\u0107 obrazka")); //!< in case of failure message box fill be displayed and program is stopped
		//mainFrame->Destroy();
		return false; // $%$&^%@$(^@(*@$*$@&@$$@ ALA, DARIA!! I HAVE CHANGED true -> false to stop program
	}

	GUIMyFrame1* mainFrame = new GUIMyFrame1(NULL); //!< main layout initialisation 
	mainFrame->img_org = image.Copy();              //!< copying image to mainFrame member
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}