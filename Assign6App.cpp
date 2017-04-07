/***************************************************************
 * Name:      Assign6App.cpp
 * Purpose:   Code for Application Class
 * Author:    Dylan Sumler ()
 * Created:   2017-04-06
 * Copyright: Dylan Sumler ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "Assign6App.h"

//(*AppHeaders
#include "Assign6Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Assign6App);

bool Assign6App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Assign6Frame* Frame = new Assign6Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
