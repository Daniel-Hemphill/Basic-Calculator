#pragma once
#include "wx/wx.h"
#include "MainWindow.h"

class UI : public wxApp
{
	private:
		MainWindow* frame1 = nullptr;
	public:
		UI();
		~UI();
		virtual bool OnInit();
};

