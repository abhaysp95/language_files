#include <wx/wx.h>
#include "mondrian.xpm"

class MyApp: public wxApp
{
	public:
		// called on application startup
		virtual bool OnInit();
};

class MyFrame: public wxFrame
{
	public:
		// constructor
		MyFrame(const wxString& title);

		// event handlers
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
	private:
		// this class handles events
		DECLARE_EVENT_TABLE();
};

//implements MyApp& GetApp()
DECLARE_APP(MyApp)

// Give wxWidgets the means to create a MyApp object
IMPLEMENT_APP(MyApp)

// initialize the application
bool MyApp::OnInit()
{
	// create the main application window
	MyFrame *frame = new MyFrame(wxT("Minimal wxWidgets App"));

	// show it
	frame->Show(true);

	// start the event loop
	return true;
};

// event table for MyFrame
BEGIN_EVENT_TABLE(MyFrame, wxFrame)
	EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
	EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()

void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Hello and welcome to %s"),
			wxVERSION_STRING);
	wxMessageBox(msg, wxT("About Minimal"),
			wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

MyFrame::MyFrame(const wxString& title)
	: wxFrame(NULL, wxID_ANY, title)
{
	// set the frame icon
	SetIcon(wxIcon(mondrian_xpm));

	// create a menu bar
	wxMenu *fileMenu = new wxMenu;

	// the "About" item should be in the help menu
	wxMenu *helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"),\
			wxT("Show about dialog"));
	fileMenu->Append(wxID_EXIT, wxT("E&xit\tAlt-X"),
			wxT("Quit this program"));

	// now append the freshly created menu to the menu bar
	wxMenuBar *menuBar = new wxMenuBar();
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));

	//  ... and attach this menu bar to the frame
	SetMenuBar(menuBar);

	// create a status bar just for fun
	CreateStatusBar(2);
	SetStatusText(wxT("Welcome to wxWidgets!"));
}
