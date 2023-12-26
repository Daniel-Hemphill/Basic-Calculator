#include "ButtonFactory.h"

ButtonFactory::ButtonFactory()
{

}

ButtonFactory::~ButtonFactory()
{

}

wxButton* ButtonFactory::ButtonCreation(wxWindow* parent, int id, wxString displayText, wxPoint pos, wxSize size)
{
	return new wxButton(parent, id, displayText, pos, size);
}