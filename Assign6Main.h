/***************************************************************
 * Name:      Assign6Main.h
 * Purpose:   Defines Application Frame
 * Author:    Dylan Sumler ()
 * Created:   2017-04-06
 * Copyright: Dylan Sumler ()
 * License:
 **************************************************************/

#ifndef ASSIGN6MAIN_H
#define ASSIGN6MAIN_H

#include <wx/string.h>
#include <wx/arrstr.h>


//(*Headers(Assign6Frame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/textctrl.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/statusbr.h>
//*)

class Assign6Frame: public wxFrame
{
    public:


        Assign6Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Assign6Frame();
        wxArrayString totUrl;
        wxArrayString totWords;

    private:

        //(*Handlers(Assign6Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnTextCtrl3Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(Assign6Frame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT1;
        static const long ID_BUTTON3;
        static const long ID_GAUGE1;
        static const long ID_STATICTEXT2;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Assign6Frame)
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxGauge* Gauge1;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxButton* Button2;
        wxButton* Button3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // ASSIGN6MAIN_H
