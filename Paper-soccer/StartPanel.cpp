#include "StartPanel.h"
#include <wx/mediactrl.h>

StartPanel::StartPanel(wxFrame* parent, const wxString& title) : wxPanel(parent, wxID_ANY)
{

    wxMediaCtrl* m_mediaCtrl = new wxMediaCtrl(this, wxID_ANY, "C:/Users/Komputer/Downloads/INTRO.avi",
        wxDefaultPosition, wxDefaultSize);

    // Wczytanie pliku wideo
    //m_mediaCtrl->Load("C:/Users/Komputer/Downloads/UEFA.mp4");

    // Ustawienie rozmiaru i pozycji wxMediaCtrl
    m_mediaCtrl->SetSize(wxSize(400, 500));
    m_mediaCtrl->SetPosition(wxPoint(0, 0));
}
