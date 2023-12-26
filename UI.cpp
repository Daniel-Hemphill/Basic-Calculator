#include "UI.h"

wxIMPLEMENT_APP(UI);

UI::UI()
{
}

UI::~UI()
{
}

bool UI::OnInit() 
{
	frame1 = new MainWindow();
	frame1->Show();
	return true;
}