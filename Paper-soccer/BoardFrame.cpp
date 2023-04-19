#include "BoardFrame.h"
#include "Field.h"
#include "Board.h"
#include <wx/button.h>
#include <algorithm>

using namespace std;

BoardFrame::BoardFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateStatusBar();
	


	//wxLogStatus(wxString::Format("%d", *y_pointer));


	wxColour* panelColor = new wxColour(255,255,255,0);
	for (int i = 0; i < this->x; i++) {
		for (int j = 0; j < this->y; j++) {
			wxButton* fieldButton = new wxButton(this, wxID_ANY, " ", wxPoint(20 + 30 * i, 20 + 30 * j), wxSize(10,10));
			auto boundDrawLine = std::bind(&BoardFrame::drawLine, this, std::placeholders::_1, &(this->current_x), &(this->current_y), 20 + 30 * i, 20 + 30 * j);
			fieldButton->Bind(wxEVT_BUTTON, boundDrawLine);
		}
	}
}

void BoardFrame::drawLine(wxCommandEvent& event, int *x1, int *y1, int x2, int y2) {
	wxClientDC dc(this);
	// ustawienie koloru linii na czerwony o grubości 1 piksela
	dc.SetPen(wxPen(wxColor(255, 0, 0), 3, wxPENSTYLE_SOLID));
	wxPoint pt1(*x1, *y1);
	wxPoint pt2(x2, y2);
	wxLogStatus(wxString::Format("%d, %d", *y1, *x1));
	dc.DrawLine(pt1, pt2);

	*x1 = x2;
	*y1 = y2;

	
	

	
}