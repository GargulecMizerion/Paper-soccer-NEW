#include "StartPanel.h"
#include <wx/mediactrl.h>
#include "BoardPanel.h"
#include <wx/statbmp.h>

StartPanel::StartPanel(wxFrame* parent, const wxString& title) : wxPanel(parent, wxID_ANY)
{
    /*nie wiem do kurwy dlaczego to nie dziala

    wxImage image(wxT("C:/Users/Komputer/Desktop/PNGsy/ufo.png"), wxBITMAP_TYPE_PNG);
    wxBitmap bitmap(image);

    if (!image.IsOk())
    {
        wxMessageBox("Nie mo¿na wczytaæ obrazka.", "B³¹d", wxICON_ERROR | wxOK);
        return;
    }  

    wxStaticBitmap* backgroundBitmap = new wxStaticBitmap(this, wxID_ANY, bitmap);
    backgroundBitmap->SetSize(GetClientSize());
    SetSizer(new wxBoxSizer(wxVERTICAL));

    */

    startButton = new wxButton(this, wxID_ANY, "START", wxPoint(100, 100), wxSize(100,100));
    startButton->Bind(wxEVT_BUTTON, &StartPanel::startOnClick, this);
     
    exitButton = new wxButton(this, wxID_ANY, "EXIT", wxPoint(300, 100), wxSize(100,100));
    exitButton->Bind(wxEVT_BUTTON, &StartPanel::exitOnClick, this);
}

void StartPanel::startOnClick(wxCommandEvent& event)
{
    BoardPanel* boardPanel = new BoardPanel(this->GetParent(), "SIEMANKO");
    boardPanel->SetClientSize(400, 500);
    this->Destroy();
}

void StartPanel::exitOnClick(wxCommandEvent& event)
{
    this->GetParent()->Destroy();
}