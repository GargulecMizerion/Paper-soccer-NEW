#include "App.h"
#include <wx/wx.h>
#include "BoardFrame.h"
#include "StartFrame.h"

using namespace std;
wxIMPLEMENT_APP(App);

bool App::OnInit() {
	BoardFrame* boardFrame = new BoardFrame("Paper Soccer");
	StartFrame* startFrame = new StartFrame("Paper Soccer");


	boardFrame->SetClientSize(400, 500);
	startFrame->SetClientSize(400, 500);

	startFrame->Show();
	//boardFrame->Show();

	return true;
}