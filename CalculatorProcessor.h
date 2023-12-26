#pragma once
#include "MainWindow.h"
#include <vector>
class CalculatorProcessor
{
public:
	CalculatorProcessor();
	~CalculatorProcessor();
	wxString CalculateText(wxString textBox);
	void Calculate(std::vector<double>& numbers, std::vector<wxString>& functions, std::vector<wxString>& operations);
	int OperationOrdering(wxString op);

	double result = 0;

	std::vector<wxString> que;
	std::vector<wxString> OrderedQue;
	std::vector<double> number;

private:

};

