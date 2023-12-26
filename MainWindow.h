#pragma once
#include "wx/wx.h"
#include "wx/filedlg.h"
#include <wx/tokenzr.h>
#include "ButtonFactory.h"
#include "CalculatorProcessor.h"

class MainWindow : public wxFrame
{
public:
	MainWindow();
	~MainWindow(); 
	void OnNumberClick(wxCommandEvent& evt);
	void OnAdd(wxCommandEvent& evt);
	void OnMinus(wxCommandEvent& evt);
	void OnNegative(wxCommandEvent& evt);
	void OnEquals(wxCommandEvent& evt);
	void OnMultiply(wxCommandEvent& evt);
	void OnDivide(wxCommandEvent& evt);
	void OnMod(wxCommandEvent& evt);
	void OnCos(wxCommandEvent& evt);
	void OnSin(wxCommandEvent& evt);
	void OnTan(wxCommandEvent& evt);
	void OnClear(wxCommandEvent& evt);
	void OnBack(wxCommandEvent& evt);
	void OnDec(wxCommandEvent& evt);

	wxString total = "";
	double result = 0;

	// All objects 
	wxTextCtrl* text = nullptr;
	wxButton* num0 = nullptr;
	wxButton* num1 = nullptr;
	wxButton* num2 = nullptr;
	wxButton* num3 = nullptr;
	wxButton* num4 = nullptr;
	wxButton* num5 = nullptr;
	wxButton* num6 = nullptr;
	wxButton* num7 = nullptr;
	wxButton* num8 = nullptr;
	wxButton* num9 = nullptr;
	wxButton* equals = nullptr;
	wxButton* plus = nullptr;
	wxButton* minus = nullptr;
	wxButton* multiply = nullptr;
	wxButton* divide = nullptr;
	wxButton* mod = nullptr;
	wxButton* sin = nullptr;
	wxButton* cos = nullptr;
	wxButton* tan = nullptr;
	wxButton* clear = nullptr;
	wxButton* backspace = nullptr;
	wxButton* decimal = nullptr;
	wxButton* negative = nullptr;

	wxDECLARE_EVENT_TABLE();
};

