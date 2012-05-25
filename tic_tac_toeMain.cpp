/***************************************************************
 * Name:      tic_tac_toeMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Wang Guibao (wang_guibao@hotmail.com)
 * Created:   2012-05-16
 * Copyright: Wang Guibao (wangguibao.is-programmer.com)
 * License:
 **************************************************************/

#include "tic_tac_toeMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(tic_tac_toeDialog)
#include <wx/settings.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(tic_tac_toeDialog)
const long tic_tac_toeDialog::ID_BITMAPBUTTON1 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON2 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON3 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON4 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON5 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON6 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON7 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON8 = wxNewId();
const long tic_tac_toeDialog::ID_BITMAPBUTTON9 = wxNewId();
const long tic_tac_toeDialog::ID_BUTTON1 = wxNewId();
const long tic_tac_toeDialog::ID_STATICLINE1 = wxNewId();
const long tic_tac_toeDialog::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(tic_tac_toeDialog,wxDialog)
    //(*EventTable(tic_tac_toeDialog)
    //*)
END_EVENT_TABLE()

tic_tac_toeDialog::tic_tac_toeDialog(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(tic_tac_toeDialog)
    wxGridSizer* GridSizer1;

    Create(parent, wxID_ANY, _("wxWidgets app"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxColour(255,204,0));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    BitmapButton1->SetDefault();
    BitmapButton1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton2 = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->SetDefault();
    BitmapButton2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton3 = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    BitmapButton3->SetDefault();
    BitmapButton3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(this, ID_BITMAPBUTTON4, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    BitmapButton4->SetDefault();
    BitmapButton4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(this, ID_BITMAPBUTTON5, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    BitmapButton5->SetDefault();
    BitmapButton5->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(this, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    BitmapButton6->SetDefault();
    BitmapButton6->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton7 = new wxBitmapButton(this, ID_BITMAPBUTTON7, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON7"));
    BitmapButton7->SetDefault();
    BitmapButton7->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton8 = new wxBitmapButton(this, ID_BITMAPBUTTON8, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON8"));
    BitmapButton8->SetDefault();
    BitmapButton8->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton9 = new wxBitmapButton(this, ID_BITMAPBUTTON9, wxNullBitmap, wxDefaultPosition, wxSize(85,85), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON9"));
    BitmapButton9->SetDefault();
    BitmapButton9->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_WINDOW));
    GridSizer1->Add(BitmapButton9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer1->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 3);
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    ButtonReplay = new wxButton(this, ID_BUTTON1, _("Play Again"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(ButtonReplay, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxDefaultPosition, wxSize(10,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    BoxSizer2->Add(StaticLine1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    Button2 = new wxButton(this, ID_BUTTON2, _("About"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    BoxSizer1->Add(BoxSizer2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 4);
    SetSizer(BoxSizer1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BITMAPBUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnBitmapButtonClick);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnButtonReplayClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&tic_tac_toeDialog::OnAbout);
    //*)
#if 1
    buttonId[1] = ID_BITMAPBUTTON1;
    buttonId[2] = ID_BITMAPBUTTON2;
    buttonId[3] = ID_BITMAPBUTTON3;
    buttonId[4] = ID_BITMAPBUTTON4;
    buttonId[5] = ID_BITMAPBUTTON5;
    buttonId[6] = ID_BITMAPBUTTON6;
    buttonId[7] = ID_BITMAPBUTTON7;
    buttonId[8] = ID_BITMAPBUTTON8;
    buttonId[9] = ID_BITMAPBUTTON9;

    CleanupImages();
#endif
}

tic_tac_toeDialog::~tic_tac_toeDialog()
{
    //(*Destroy(tic_tac_toeDialog)
    //*)
}

void tic_tac_toeDialog::OnQuit(wxCommandEvent& event)
{
    Close();
}

void tic_tac_toeDialog::OnAbout(wxCommandEvent& event)
{
    wxString msg(_("TIC TAC TOE"));
    wxMessageBox(msg, _("About"));
}

void tic_tac_toeDialog::OnBitmapButtonClick(wxCommandEvent& event)
{
    int id = GetGridId(event.GetId());
    if (id == -1) {
        wxMessageBox("-1!!!");
        return;
    }

    if (board.Freezed() == true || board.empty(id) == false) {
        return;
    }

    string imagePath;
    Chess::ChessType chessType;
    Board::WhichSideTurn whichSideTurn = board.GetWhichSideTurn();

    if (whichSideTurn == Board::O_SIDE_TURN) {
        imagePath = "wxsmith/o.jpg";
        chessType = Chess::CHESS_TYPE_O;
    }
    else {
        imagePath = "wxsmith/x.jpg";
        chessType = Chess::CHESS_TYPE_X;
    }
    wxBitmap bitmap(imagePath, wxBITMAP_TYPE_JPEG);
    ((wxBitmapButton *)FindWindow(event.GetId()))->SetBitmapLabel(bitmap);

    if (whichSideTurn == Board::O_SIDE_TURN) {
        if (board.OSideWins(id) == true) {
            wxMessageBox("You win!!");
            board.Freeze(true);
            return;
        }
        board.OSideUpdateBoardState(id);
    }
    else {
        if (board.XSideWins(id) == true) {
            wxMessageBox("Robot wins!!");
            board.Freeze(true);
            return;
        }
        board.XSideUpdateBoardState(id);
    }

    if (board.Tied()) {
        wxMessageBox("Tied!!");
        board.Freeze(true);
        return;
    }

    board.FlipWhichSideTurn();

    if (whichSideTurn == Board::O_SIDE_TURN) {
        int robotDecision = robot.Move(board);
        wxCommandEvent newEvent(wxEVT_COMMAND_BUTTON_CLICKED,
                                 buttonId[robotDecision]);
        newEvent.SetEventObject(this);
        GetEventHandler()->ProcessEvent(newEvent);
    }
}

void tic_tac_toeDialog::OnButtonReplayClick(wxCommandEvent& event)
{
    CleanupImages();
    board.InitBoard();
}

int tic_tac_toeDialog::GetGridId(const long id)
{
    for (int i = 1; i <= BUTTON_CNT; i++) {
        if (buttonId[i] == id) {
            return i;
        }
    }

    return -1;
}

void tic_tac_toeDialog::CleanupImages()
{
    wxBitmap bitmap("wxsmith/blank.jpg", wxBITMAP_TYPE_JPEG);
    for (int i = 1; i <= BUTTON_CNT; i++) {
        ((wxBitmapButton *)FindWindow(buttonId[i]))->SetBitmapLabel(bitmap);
    }
}
