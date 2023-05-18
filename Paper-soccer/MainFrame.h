#pragma once
#include "wx/wx.h"

class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title);
    void startOnClick(wxCommandEvent& event, wxButton* exit_btn);
    void exitOnClick(wxCommandEvent& event);
};