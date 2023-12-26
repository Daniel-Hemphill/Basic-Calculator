#pragma once
#include "wx/wx.h"

class ButtonFactory
{
public:
	ButtonFactory();
	~ButtonFactory();
	static wxButton* ButtonCreation(wxWindow* parent, int id, wxString displayText, wxPoint pos, wxSize size);

private: 


};

