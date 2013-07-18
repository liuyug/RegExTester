/***************************************************************
 * Name:      RegExTesterApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Liu Yu Gang ()
 * Created:   2008-08-29
 * Copyright: Liu Yu Gang ()
 * License:
 **************************************************************/

#include "RegExTesterApp.h"

//(*AppHeaders
#include "RegExTesterMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(RegExTesterApp);

bool RegExTesterApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	RegExTesterDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
