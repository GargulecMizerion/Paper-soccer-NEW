#include "MainFrame.h"
#include "StartFrame.h"
#include "BoardFrame.h"
#include "wx/wx.h"
#include "BoardPanel.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
    /*
    CreateStatusBar();
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    this->setSizer(sizer);


    wxButton* start_btn = new wxButton(this, wxID_ANY, "START", wxPoint(80, 20), wxSize(100, 100));

    if(this->flaga) {
        BoardPanel* boardPanel = new BoardPanel(this, "");
        start_btn->Destroy();
        start_btn->GetParent()->Layout();
        delete start_btn;
    }

    auto startbtn = std::bind(&MainFrame::startOnClick, this, std::placeholders::_1, &(this->flaga));
    start_btn->Bind(wxEVT_BUTTON, startbtn);
    // DO MAINFRAME Przenieœæ

    //BoardFrame* boardFrame = new BoardFrame("Paper Soccer");
    //boardFrame->SetClientSize(400, 500);
    //startFrame->SetClientSize(400, 500);
    //boardFrame->Show();*/
    CreateStatusBar();

    wxButton* start_btn = new wxButton(this, wxID_ANY, "START", wxPoint(80, 20), wxSize(100, 100));
    wxButton* exit_btn = new wxButton(this, wxID_ANY, "EXIT", wxPoint(80, 200), wxSize(100, 100));

    auto startbtn = std::bind(&MainFrame::startOnClick, this, std::placeholders::_1, exit_btn);
    start_btn->Bind(wxEVT_BUTTON, startbtn);
    exit_btn->Bind(wxEVT_BUTTON, &MainFrame::exitOnClick, this);


}

void MainFrame::startOnClick(wxCommandEvent& event, wxButton* exit_btn)
{
    wxButton* start_btn = dynamic_cast<wxButton*>(event.GetEventObject());
    //wxButton* exit_btn = dynamic_cast<wxButton*>(event.GetEventObject());
    if (start_btn)
    {
        start_btn->Destroy();
        exit_btn->Destroy();
        //GetParent()->Layout();
        BoardPanel* boardPanel = new BoardPanel(this, "");
        boardPanel->SetClientSize(400, 500);
        boardPanel->SetBackgroundColour(wxColor(20, 200, 20));
        this->SetBackgroundColour(wxColor(20, 200, 20));
    }
}

void MainFrame::exitOnClick(wxCommandEvent& event)
{
    this->Destroy();
}