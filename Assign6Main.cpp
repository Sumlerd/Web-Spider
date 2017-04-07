/***************************************************************
 * Name:      Assign6Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dylan Sumler ()
 * Created:   2017-04-06
 * Copyright: Dylan Sumler ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assign6Main.h"
#include <wx/textfile.h>
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/url.h>
#include <wx/tokenzr.h>
#include <string>
#define BUFFSIZE 16384

//(*InternalHeaders(Assign6Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Assign6Frame)
const long Assign6Frame::ID_BUTTON1 = wxNewId();
const long Assign6Frame::ID_BUTTON2 = wxNewId();
const long Assign6Frame::ID_TEXTCTRL1 = wxNewId();
const long Assign6Frame::ID_TEXTCTRL2 = wxNewId();
const long Assign6Frame::ID_TEXTCTRL3 = wxNewId();
const long Assign6Frame::ID_STATICTEXT1 = wxNewId();
const long Assign6Frame::ID_BUTTON3 = wxNewId();
const long Assign6Frame::ID_GAUGE1 = wxNewId();
const long Assign6Frame::ID_STATICTEXT2 = wxNewId();
const long Assign6Frame::ID_PANEL1 = wxNewId();
const long Assign6Frame::ID_MENUITEM1 = wxNewId();
const long Assign6Frame::idMenuAbout = wxNewId();
const long Assign6Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Assign6Frame,wxFrame)
    //(*EventTable(Assign6Frame)
    //*)
END_EVENT_TABLE()

Assign6Frame::Assign6Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Assign6Frame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(350,350));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(96,80), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Url"), wxPoint(32,40), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("Word"), wxPoint(32,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("Url file"), wxPoint(168,40), wxSize(136,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Word file"), wxPoint(168,88), wxSize(136,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(Panel1, ID_TEXTCTRL3, wxEmptyString, wxPoint(224,152), wxSize(80,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Hits"), wxPoint(176,160), wxSize(80,17), 0, _T("ID_STATICTEXT1"));
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Start"), wxPoint(40,152), wxSize(64,27), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    Gauge1 = new wxGauge(Panel1, ID_GAUGE1, 100, wxPoint(128,200), wxSize(176,28), 0, wxDefaultValidator, _T("ID_GAUGE1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Progress"), wxPoint(64,208), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Assign6Frame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Assign6Frame::OnButton2Click);
    Connect(ID_TEXTCTRL3,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&Assign6Frame::OnTextCtrl3Text);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Assign6Frame::OnButton3Click);
    Panel1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&Assign6Frame::OnPanel1Paint1,0,this);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assign6Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Assign6Frame::OnAbout);
    //*)
}

Assign6Frame::~Assign6Frame()
{
    //(*Destroy(Assign6Frame)
    //*)
}

void Assign6Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Assign6Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

/*Get the urls*/
void Assign6Frame::OnButton1Click(wxCommandEvent& event)
{
    wxString path;
    int i;
    wxFileDialog FileDialog(this, wxT("Open.."), wxT(""), wxT(""),
                            wxT("Text Files (*.txt)|*.txt"),
                            wxFD_OPEN, wxDefaultPosition );

    if(FileDialog.ShowModal() == wxID_OK)
    {
        wxTextFile file( FileDialog.GetPath());
        path = FileDialog.GetPath();
        file.Open(path);
        TextCtrl1->SetValue(path);
        if( file.IsOpened() )
        {
            for(i = 0; i < file.GetLineCount(); i++)
            {
                totUrl.Add(file.GetLine(i));

            }
        }

    }
}

/*Get the words*/
void Assign6Frame::OnButton2Click(wxCommandEvent& event)
{
    wxString path;
    int i;
    wxFileDialog FileDialog(this, wxT("Open.."), wxT(""), wxT(""),
                            wxT("Text Files (*.txt)|*.txt"),
                            wxFD_OPEN, wxDefaultPosition );

    if(FileDialog.ShowModal() == wxID_OK)
    {

        wxTextFile file( FileDialog.GetPath());
        path = FileDialog.GetPath();
        file.Open(path);
        TextCtrl2->SetValue(path);
        if( file.IsOpened() )
        {
            for(i = 0; i < file.GetLineCount(); i++)
            {
                totWords.Add(file.GetLine(i));
            }
        }

    }
}

/*Start the spider*/
void Assign6Frame::OnButton3Click(wxCommandEvent& event)
{
    //if()
    int range = totUrl.size();
    Gauge1->SetRange(range);    //gauge based on # of urls completed
    int hits = 0;
    int progress = 0;

    int j;
    for(j = 0; j < totUrl.size(); j++)
    {
        wxURL url(totUrl[j]);   //fetch url from url file

        /*Check the url and place it's source code in a buffer*/
        if (url.GetError() == wxURL_NOERR)
        {
            wxInputStream *in_stream;
            in_stream = url.GetInputStream();
            unsigned char buffer[BUFFSIZE];
            do {
                in_stream->Read(buffer, BUFFSIZE);
            } while (!in_stream->Eof());


            /*Place the buffer as a string and tokenize it by space */
            wxString s = buffer;
            wxStringTokenizer tokenizer(s, " ");

            int i;

            /*Check to see if tokens match the words. Make all values upper case becuase isSameAs is case sensitive*/
            while(tokenizer.HasMoreTokens())
            {
                wxString token = tokenizer.GetNextToken();
                for(i = 0; i < totWords.size(); i++)
                {
                    if(token.MakeUpper().IsSameAs(totWords[i].MakeUpper()))
                        hits++;
                }
            }

        }

        Gauge1->SetValue(j+1);  //increment the progress bar
    }
    /*Update the hits*/
    TextCtrl3->SetValue(wxString::Format(wxT("%i"), hits));


}


void Assign6Frame::OnTextCtrl3Text(wxCommandEvent& event)
{
}

void Assign6Frame::OnPanel1Paint1(wxPaintEvent& event)
{
}
