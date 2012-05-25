/***************************************************************
 * Name:      tic_tac_toeMain.h
 * Purpose:   Defines Application Frame
 * Author:    Wang Guibao (wang_guibao@hotmail.com)
 * Created:   2012-05-16
 * Copyright: Wang Guibao (wangguibao.is-programmer.com)
 * License:
 **************************************************************/

#ifndef TIC_TAC_TOEMAIN_H
#define TIC_TAC_TOEMAIN_H

//(*Headers(tic_tac_toeDialog)
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)
#if 1
#include "Robot.h"
#include "Board.h"
#endif

class tic_tac_toeDialog: public wxDialog
{
    public:

        tic_tac_toeDialog(wxWindow* parent,wxWindowID id = -1);
        virtual ~tic_tac_toeDialog();

    private:
        //(*Handlers(tic_tac_toeDialog)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLeftDown(wxMouseEvent& event);
        void OnBitmapButtonClick(wxCommandEvent& event);
        void OnButtonReplayClick(wxCommandEvent& event);
        //*)

#if 1
        void CleanupImages();
        int GetGridId(const long id);
#endif

        //(*Identifiers(tic_tac_toeDialog)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON5;
        static const long ID_BITMAPBUTTON6;
        static const long ID_BITMAPBUTTON7;
        static const long ID_BITMAPBUTTON8;
        static const long ID_BITMAPBUTTON9;
        static const long ID_BUTTON1;
        static const long ID_STATICLINE1;
        static const long ID_BUTTON2;
        //*)
#if 1
        static const int BUTTON_CNT = 9;
        long buttonId[BUTTON_CNT + 1];
#endif
        //(*Declarations(tic_tac_toeDialog)
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton9;
        wxBitmapButton* BitmapButton2;
        wxBitmapButton* BitmapButton8;
        wxBoxSizer* BoxSizer2;
        wxBitmapButton* BitmapButton1;
        wxButton* Button2;
        wxBitmapButton* BitmapButton6;
        wxStaticLine* StaticLine1;
        wxBitmapButton* BitmapButton7;
        wxBitmapButton* BitmapButton4;
        wxBoxSizer* BoxSizer1;
        wxBitmapButton* BitmapButton3;
        wxButton* ButtonReplay;
        //*)
#if 1
        Board board;
        Robot robot;
#endif
        DECLARE_EVENT_TABLE()
};

#endif // TIC_TAC_TOEMAIN_H
