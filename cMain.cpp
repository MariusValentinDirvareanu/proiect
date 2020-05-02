#include "cMain.h"
#include <string>


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(1001, OnButtonClicked)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Test", wxPoint(10, 10),wxSize(800, 600))
{
    
    mainPane = new wxPanel(this);
    
	txt1 = new wxStaticText(mainPane, wxID_ANY, "CNP", wxPoint(170, 5), wxSize(60, 40));
	m_txt1 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(170, 50), wxSize(100, 20));

	txt2 = new wxStaticText(mainPane, wxID_ANY, "Nume", wxPoint(270, 5), wxSize(60, 40));
	m_txt2 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(270, 50), wxSize(100, 20));

	txt3 = new wxStaticText(mainPane, wxID_ANY, "Prenume", wxPoint(370, 5), wxSize(60, 40));
	m_txt3 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(370, 50), wxSize(100, 20));

	txt4 = new wxStaticText(mainPane, wxID_ANY, "Serie", wxPoint(470, 5), wxSize(60, 40));
	m_txt4 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(470, 50), wxSize(100, 20));

	txt5 = new wxStaticText(mainPane, wxID_ANY, "Numar", wxPoint(570, 5), wxSize(100, 40));
	m_txt5 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt6 = new wxStaticText(mainPane, wxID_ANY, "Cetatenie", wxPoint(570, 5), wxSize(100, 40));
	m_txt6 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt7 = new wxStaticText(mainPane, wxID_ANY, "Sex", wxPoint(570, 5), wxSize(100, 40));
	m_txt7 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt8 = new wxStaticText(mainPane, wxID_ANY, "LocNastere", wxPoint(570, 5), wxSize(100, 40));
	m_txt8 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt9 = new wxStaticText(mainPane, wxID_ANY, "Domiciliu", wxPoint(570, 5), wxSize(100, 40));
	m_txt9 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt10 = new wxStaticText(mainPane, wxID_ANY, "EmisaDe", wxPoint(570, 5), wxSize(100, 40));
	m_txt10 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));

	txt11 = new wxStaticText(mainPane, wxID_ANY, "Valabilitate", wxPoint(570, 5), wxSize(100, 40));
	m_txt11 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(570, 50), wxSize(100, 20));


	m_btn1 = new wxButton(mainPane, 1001, "Click me!", wxPoint(10, 10), wxSize(150, 50));


	primaPornire();


}



void cMain::creareTabelDB(int& exit, std::string queryCreare)
{
	// Apelare query de creare baza de date
	exit = sqlite3_exec(DB, queryCreare.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		wxMessageBox(wxT("Eroare creare baza de date"), wxT("Eroare"), wxICON_ERROR);
		sqlite3_free(messaggeError);
	}
	else {
		wxMessageBox(wxT("Baza de date creata!"), wxT("Succes!"), wxICON_INFORMATION);
	}
}


void cMain::inserareDB(int& exit, std::string& queryInserare)
{
	exit = sqlite3_exec(DB, queryInserare.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		wxMessageBox(wxT("Eroare inregistrare in baza de date"), wxT("Eroare"), wxICON_ERROR);
		sqlite3_free(messaggeError);
	}
	else {
		std::cout << "Records created Successfully!" << std::endl;
		wxMessageBox(wxT("Inregistrarea s-a facut cu succes!"), wxT("Succes!"), wxICON_INFORMATION);
	}
}

void cMain::stergereDB(int& exit, std::string& queryDelete)
{
	exit = sqlite3_exec(DB, queryDelete.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		wxMessageBox(wxT("Eroare stergere din baza de date"), wxT("Eroare"), wxICON_ERROR);
		sqlite3_free(messaggeError);
	}
	else {
		wxMessageBox(wxT("Sters"), wxT("Succes!"), wxICON_INFORMATION);
	}
}


void cMain::primaPornire() {
	// Baza de date
	exit = sqlite3_open(numeFisier.c_str(), &DB);

	if (std::filesystem::file_size(numeFisier) == 0)
	{
		std::string magazine = "CREATE TABLE buletin ("
			"ID	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
			"CNP	INTEGER NOT NULL UNIQUE,"
			"Serie	TEXT NOT NULL,"
			"Numar	INTEGER NOT NULL,"
			"Nume	TEXT NOT NULL,"
			"Prenume	TEXT NOT NULL,"
			"Cetatenie	TEXT NOT NULL,"
			"Sex	TEXT NOT NULL,"
			"LocNastere	TEXT NOT NULL,"
			"Domiciliu	TEXT NOT NULL,"
			"EmisaDe	TEXT NOT NULL,"
			"Valabilitate	TEXT NOT NULL);";

		creareTabelDB(exit, magazine);
	}

	sqlite3_close(DB);
	// End baza de date
}



void cMain::OnButtonClicked(wxCommandEvent& evt) {
	exit = sqlite3_open(numeFisier.c_str(), &DB);
	std::string ins;
	if (m_txt1->GetValue() == wxT("") || m_txt2->GetValue() == wxT("") || m_txt5->GetValue() == wxT("")) {
		wxMessageBox(wxT("Nu ai introdus destule valori"), wxT("Eroare"), wxICON_ERROR);
	}
	if (m_txt3->GetValue() != wxT("")) {
		wxMessageBox(wxT("Nu poti avea si kg si litri"), wxT("Eroare"), wxICON_ERROR);
	}
	else {
		if (m_txt3->GetValue() != wxT("")) {
			ins = "INSERT INTO stock(denumire,unitati,kg,pretunitate) VALUES('";
			ins.append(m_txt1->GetValue() + "',");
			ins.append(m_txt2->GetValue() + ",");
			ins.append(m_txt3->GetValue() + ",");
			ins.append(m_txt5->GetValue() + ");");
			if (m_txt1->GetValue() != wxT("") && m_txt2->GetValue() != wxT("") && m_txt5->GetValue() != wxT("")) {
				inserareDB(exit, ins);
			}
			else {
				wxMessageBox(wxT("Valoare invalida"), wxT("Eroare"), wxICON_ERROR);
			}
		}
		else {
			if (m_txt4->GetValue() != wxT("")) {
				ins = "INSERT INTO stock(denumire,unitati,litri,pretunitate) VALUES('";
				ins.append(m_txt1->GetValue() + "',");
				ins.append(m_txt2->GetValue() + ",");
				ins.append(m_txt4->GetValue() + ",");
				ins.append(m_txt5->GetValue() + ");");
				if (m_txt1->GetValue() != wxT("") && m_txt2->GetValue() != wxT("") && m_txt5->GetValue() != wxT("")) {
					inserareDB(exit, ins);
				}
				else {
					wxMessageBox(wxT("Valoare invalida"), wxT("Eroare"), wxICON_ERROR);
				}
			}
		}
	}
	sqlite3_close(DB);
	evt.Skip();
}

cMain::~cMain()
{
}

