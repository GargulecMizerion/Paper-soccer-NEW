#include "EndPanel.h"
EndPanel::EndPanel(wxWindow* parent, const wxString& title) : wxPanel(parent, wxID_ANY)
{
    exitButton = new wxButton(this, wxID_ANY, "EXIT", wxPoint(100, 100), wxSize(100, 100));
    exitButton->Bind(wxEVT_BUTTON, &EndPanel::exitOnClick, this);
}

void EndPanel::exitOnClick(wxCommandEvent& event)
{
    this->GetParent()->Destroy();
}
