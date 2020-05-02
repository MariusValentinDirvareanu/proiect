#pragma once

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "sqlite3.h"
#include <vector>
#include <string>
#include <filesystem>
#include "wx/msgdlg.h"
#include "wx/stattext.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
	//void creareTabel(std::vector<std::string> den);
	void creareTabelDB(int& exit, std::string queryCreare);
	void inserareDB(int& exit, std::string& queryInserare);
	void stergereDB(int& exit, std::string& queryDelete);
	void primaPornire();
	void OnButtonClicked(wxCommandEvent& evt);

public:
	wxButton* m_btn1 = nullptr;
	wxListCtrl* m_item_list = nullptr;
	wxBoxSizer* sizer = nullptr;
	wxPanel* mainPane = nullptr;
	//wxListItem coloane[100];
	//std::vector<std::string> denumiri;
	sqlite3* DB;
	unsigned ok = 0;
	std::string numeFisier = "persoane.db";
	int exit = 0;
	char* messaggeError;
	wxStaticText* txt1 = nullptr;
	wxTextCtrl* m_txt1 = nullptr;
	wxStaticText* txt2 = nullptr;
	wxTextCtrl* m_txt2 = nullptr;
	wxStaticText* txt3 = nullptr;
	wxTextCtrl* m_txt3 = nullptr;
	wxStaticText* txt4 = nullptr;
	wxTextCtrl* m_txt4 = nullptr;
	wxStaticText* txt5 = nullptr;
	wxTextCtrl* m_txt5 = nullptr;

	wxDECLARE_EVENT_TABLE();
};

