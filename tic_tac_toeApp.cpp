/***************************************************************
 * Name:      tic_tac_toeApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Wang Guibao (wang_guibao@hotmail.com)
 * Created:   2012-05-16
 * Copyright: Wang Guibao (wangguibao.is-programmer.com)
 * License:
 **************************************************************/

#include "tic_tac_toeApp.h"

//(*AppHeaders
#include "tic_tac_toeMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(tic_tac_toeApp);

bool tic_tac_toeApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	tic_tac_toeDialog Dlg(0);
    	SetTopWindow(&Dlg);
    	Dlg.ShowModal();
    	wxsOK = false;
    }
    //*)
    return wxsOK;

}
