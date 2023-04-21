#pragma once
#include <wx/wx.h>
#include "Board.h"

using namespace std;

class BoardFrame : public wxFrame
{
private:
	int dupinka = 3;
	int cycolinka = 5;
	
public:
	BoardFrame(const wxString& title);
	void drawLine(wxCommandEvent& event, int* source_x, int* source_y, int destiny_x, int destiny_y);
};