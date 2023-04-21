#include "BoardFrame.h"
#include "Field.h"
#include "Board.h"
#include <wx/button.h>
#include <algorithm>

using namespace std;

BoardFrame::BoardFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{
	CreateStatusBar();
	Board* board = new Board(7, 11, this);

	  // tak dziala

	board->setCurrentField(board->getFields()[5][3]);

	wxLogStatus(wxString::Format("%p ", board->getCurrentField().getPG()));

	/*
	board->getCurrentField().getLG()->getFieldBtn()->Enable();
	board->getCurrentField().getG()->getFieldBtn()->Enable();
	board->getCurrentField().getPG()->getFieldBtn()->Enable();
	board->getCurrentField().getL()->getFieldBtn()->Enable();
	board->getCurrentField().getP()->getFieldBtn()->Enable();
	board->getCurrentField().getLD()->getFieldBtn()->Enable();
	board->getCurrentField().getD()->getFieldBtn()->Enable();
	board->getCurrentField().getPD()->getFieldBtn()->Enable();


	*/


	wxColour* panelColor = new wxColour(255,255,255,0);
	for (int i = 0; i < board->getY(); i++) {
		for (int j = 0; j < board->getX(); j++) {
			
			
			// PRZENIESIONE DO BOARD
			//wxButton* fieldButton = new wxButton(this, wxID_ANY, " ", wxPoint(20 + 30 * i, 20 + 30 * j), wxSize(10, 10));
			
			
			
			auto boundDrawLine = std::bind(&BoardFrame::drawLine, this, std::placeholders::_1, &(this->dupinka), &(this->cycolinka), j, i);
			
			
			
			//board->getFields()[j][i].setFieldBtn(fieldButton);
			//board->getFields()[j][i].getFieldBtn()->Disable();
			//board->getFields()[j][i].getFieldBtn()->Bind(wxEVT_BUTTON, boundDrawLine);

			//wxLogStatus(wxString::Format("%p ", board->getFields()[3][5].getD()));  // tak dziala
			//wxLogStatus(wxString::Format("%p ", board->getCurrentField()->getD()));  // tak nie dziala

			//fieldButton->Disable();
			//fieldButton->Bind(wxEVT_BUTTON, boundDrawLine);


			

			//wxLogStatus(wxString::Format("Punkt źródłowy: x = %d,   y = %d: ", this->dupinka, this->cycolinka));
			
			

			/*
			TODO
			1.	FUNKCJA która zwraca true/false czy można wejść na to pole? 
				Zrobić tak aby nie dało się cofać. ( poprawne poruszanie się po planszy )
				- sprawdzać wskaźniki, jeśli NULL to nie można się cofnąć/wejść na to pole.

			2. Z palca bindować funkcje drawLine dla wszystkich sąsiadów currentFielda (O ILE DA SIE NA NIE PRZEJSC). Korzystamy z punktu nr 1.

			3.  Przekazać pole przez parametr do drawLine
			*/
		}
	}

	//board->getFields()[3][5].getD()->getFieldBtn()->Enable();

}

/*
void BoardFrame::enableButton() {
	
}
*/


void BoardFrame::drawLine(wxCommandEvent& event, int* source_x, int* source_y, int destiny_x, int destiny_y) 
{
		wxClientDC dc(this);
		// ustawienie koloru linii na czerwony o grubości 1 piksela
		dc.SetPen(wxPen(wxColor(255, 0, 0), 3, wxPENSTYLE_SOLID));
		wxPoint source((*source_x) * 30 + 20 + 5, (*source_y) * 30 + 20 + 5);
		wxPoint destiny(destiny_x * 30 + 20 + 5, destiny_y * 30 + 20 + 5);
		wxLogStatus(wxString::Format("Punkt źródłowy: x = %d,   y = %d: ", *source_x, *source_y));
		dc.DrawLine(source, destiny);

		//*source_x = destiny_x;
		//*source_y = destiny_y;

		//board->setCurrentField(board->getFields()[destiny_y][destiny_x]);

} 


