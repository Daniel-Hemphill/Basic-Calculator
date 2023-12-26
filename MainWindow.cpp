#include "MainWindow.h"

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_BUTTON(10000, MainWindow::OnNumberClick)
EVT_BUTTON(10001, MainWindow::OnNumberClick)
EVT_BUTTON(10002, MainWindow::OnNumberClick)
EVT_BUTTON(10003, MainWindow::OnNumberClick)
EVT_BUTTON(10004, MainWindow::OnNumberClick)
EVT_BUTTON(10005, MainWindow::OnNumberClick)
EVT_BUTTON(10006, MainWindow::OnNumberClick)
EVT_BUTTON(10007, MainWindow::OnNumberClick)
EVT_BUTTON(10008, MainWindow::OnNumberClick)
EVT_BUTTON(10009, MainWindow::OnNumberClick)
EVT_BUTTON(10010, MainWindow::OnEquals)
EVT_BUTTON(10011, MainWindow::OnAdd)
EVT_BUTTON(10012, MainWindow::OnMinus)
EVT_BUTTON(10013, MainWindow::OnMultiply)
EVT_BUTTON(10014, MainWindow::OnDivide)
EVT_BUTTON(10015, MainWindow::OnMod)
EVT_BUTTON(10016, MainWindow::OnSin)
EVT_BUTTON(10017, MainWindow::OnCos)
EVT_BUTTON(10018, MainWindow::OnTan)
EVT_BUTTON(10019, MainWindow::OnClear)
EVT_BUTTON(10020, MainWindow::OnBack)
EVT_BUTTON(10021, MainWindow::OnDec)
EVT_BUTTON(10022, MainWindow::OnNegative)
wxEND_EVENT_TABLE()

MainWindow::MainWindow() : wxFrame(nullptr, wxID_ANY, "Calculator", wxPoint(0, 0), wxSize(300, 250))
{
	// Text box
	text = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 10), wxSize(200, 30));
	// Numbers

	num1 = ButtonFactory::ButtonCreation(this, 10001, "1", wxPoint(10, 50), wxSize(30, 30));
	num2 = ButtonFactory::ButtonCreation(this, 10002, "2", wxPoint(50, 50), wxSize(30, 30));
	num3 = ButtonFactory::ButtonCreation(this, 10003, "3", wxPoint(90, 50), wxSize(30, 30));
	num4 = ButtonFactory::ButtonCreation(this, 10004, "4", wxPoint(10, 90), wxSize(30, 30));
	num5 = ButtonFactory::ButtonCreation(this, 10005, "5", wxPoint(50, 90), wxSize(30, 30));
	num6 = ButtonFactory::ButtonCreation(this, 10006, "6", wxPoint(90, 90), wxSize(30, 30));
	num7 = ButtonFactory::ButtonCreation(this, 10007, "7", wxPoint(10, 130), wxSize(30, 30));
	num8 = ButtonFactory::ButtonCreation(this, 10008, "8", wxPoint(50, 130), wxSize(30, 30));
	num9 = ButtonFactory::ButtonCreation(this, 10009, "9", wxPoint(90, 130), wxSize(30, 30));
	num0 = ButtonFactory::ButtonCreation(this, 10000, "0", wxPoint(10, 170), wxSize(30, 30));
	
	// Operations
	equals = ButtonFactory::ButtonCreation(this, 10010, "=", wxPoint(210, 170), wxSize(30, 30));
	plus = ButtonFactory::ButtonCreation(this, 10011, "+", wxPoint(130, 170), wxSize(30, 30));
	minus = ButtonFactory::ButtonCreation(this, 10012, "-", wxPoint(130, 130), wxSize(30, 30));
	multiply = ButtonFactory::ButtonCreation(this, 10013, "*", wxPoint(130, 90), wxSize(30, 30));
	divide = ButtonFactory::ButtonCreation(this, 10014, "/", wxPoint(130, 50), wxSize(30, 30));
	mod = ButtonFactory::ButtonCreation(this, 10015, "%", wxPoint(170, 50), wxSize(30, 30));
	sin = ButtonFactory::ButtonCreation(this, 10016, "sin", wxPoint(170, 90), wxSize(30, 30));
	cos = ButtonFactory::ButtonCreation(this, 10017, "cos", wxPoint(170, 130), wxSize(30, 30));
	tan = ButtonFactory::ButtonCreation(this, 10018, "tan", wxPoint(170, 170), wxSize(30, 30));
	clear = ButtonFactory::ButtonCreation(this, 10019, "CL", wxPoint(210, 90), wxSize(30, 30));
	backspace = ButtonFactory::ButtonCreation(this, 10020, "<-", wxPoint(210, 50), wxSize(30, 30));
	decimal = ButtonFactory::ButtonCreation(this, 10021, ".", wxPoint(50, 170), wxSize(30, 30));
	negative = ButtonFactory::ButtonCreation(this, 10022, "-", wxPoint(90, 170), wxSize(30, 30));

}
MainWindow::~MainWindow()
{

}
void MainWindow::OnNumberClick(wxCommandEvent& evt)
{
	switch (evt.GetId())
	{
		case 10000:
			text->SetValue(text->GetValue() + "0");
			break;
		case 10001:
			text->SetValue(text->GetValue() + "1");
			break;
		case 10002:
			text->SetValue(text->GetValue() + "2");
			break;
		case 10003:
			text->SetValue(text->GetValue() + "3");
			break;
		case 10004:
			text->SetValue(text->GetValue() + "4");
			break;
		case 10005:
			text->SetValue(text->GetValue() + "5");
			break;
		case 10006:
			text->SetValue(text->GetValue() + "6");
			break;
		case 10007:
			text->SetValue(text->GetValue() + "7");
			break;
		case 10008:
			text->SetValue(text->GetValue() + "8");
			break;
		case 10009:
			text->SetValue(text->GetValue() + "9");
			break;
	}
}
void MainWindow::OnAdd(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " + ");
	total = text->GetValue();
}
void MainWindow::OnMinus(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " - ");
	total = text->GetValue();
}
void MainWindow::OnNegative(wxCommandEvent& evt)
{
	total = text->GetValue();
	total.ToDouble(&result);
	result = result * -1;
	text->SetValue(wxString::FromDouble(result));
}
void MainWindow::OnMultiply(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " * ");
	total = text->GetValue();
}
void MainWindow::OnDivide(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " / ");
	total = text->GetValue();
}
void MainWindow::OnMod(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " % ");
	total = text->GetValue();
}
void MainWindow::OnCos(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " cos ");
	total = text->GetValue();
}
void MainWindow::OnSin(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " sin ");
	total = text->GetValue();
}
void MainWindow::OnTan(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + " tan ");
	total = text->GetValue();
}
void MainWindow::OnClear(wxCommandEvent& evt)
{
	text->Clear();
	result = 0;
}
void MainWindow::OnBack(wxCommandEvent& evt)
{
	text->OnDelete(evt);
}
void MainWindow::OnDec(wxCommandEvent& evt)
{
	text->SetValue(text->GetValue() + ".");
	total = text->GetValue();
}

void MainWindow::OnEquals(wxCommandEvent& evt)
{
	CalculatorProcessor* calc = new CalculatorProcessor();

	text->SetValue(calc->CalculateText(text->GetValue()));
}