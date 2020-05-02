#include "cMain.h"
#include <string>


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(1001, inregistrarePeroana)
	EVT_BUTTON(1004, generareCNP)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Test", wxPoint(10, 10),wxSize(800, 600))
{

	wxSize s = wxSize(67, 20);
    
    mainPane = new wxPanel(this);
    
	txt1 = new wxStaticText(mainPane, wxID_ANY, "CNP", wxPoint(30, 30), s);
	m_txt1 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 30), wxSize(300, 20));

	txt2 = new wxStaticText(mainPane, wxID_ANY, "Nume", wxPoint(30, 60), s);
	m_txt2 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 60), wxSize(300, 20));

	txt3 = new wxStaticText(mainPane, wxID_ANY, "Prenume", wxPoint(30, 90), s);
	m_txt3 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 90), wxSize(300, 20));

	txt4 = new wxStaticText(mainPane, wxID_ANY, "Serie", wxPoint(500, 30), s);
	m_txt4 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 30), wxSize(100, 20));

	txt5 = new wxStaticText(mainPane, wxID_ANY, "Numar", wxPoint(500, 60), s);
	m_txt5 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 60), wxSize(100, 20));

	txt6 = new wxStaticText(mainPane, wxID_ANY, "Cetatenie", wxPoint(30, 120), s);
	m_txt6 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 120), wxSize(300, 20));

	txt7 = new wxStaticText(mainPane, wxID_ANY, "Sex", wxPoint(530, 120), s);
	m_txt7 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 120), wxSize(100, 20));

	txt8 = new wxStaticText(mainPane, wxID_ANY, "Loc Nastere", wxPoint(30, 150), s);
	m_txt8 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 150), wxSize(300, 20));

	txt9 = new wxStaticText(mainPane, wxID_ANY, "Domiciliu", wxPoint(30, 180), s);
	m_txt9 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 180), wxSize(300, 20));

	txt10 = new wxStaticText(mainPane, wxID_ANY, "Emisa de", wxPoint(30, 210), s);
	m_txt10 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 210), wxSize(300, 20));

	txt11 = new wxStaticText(mainPane, wxID_ANY, "Valabilitate", wxPoint(500, 210), s);
	m_txt11 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(450, 240), wxSize(200, 20));

	txt12 = new wxStaticText(mainPane, wxID_ANY, "Data nasterii", wxPoint(500, 90), s);
	m_txt12 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 90), wxSize(40, 20));
	m_txt13 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(650, 90), wxSize(40, 20));
	m_txt14 = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(700, 90), wxSize(40, 20));


	m_btn1 = new wxButton(mainPane, 1001, "Inregistrare persoana", wxPoint(100, 300), wxSize(150, 50));
	m_btn2 = new wxButton(mainPane, 1002, "Cautare CNP", wxPoint(300, 300), wxSize(150, 50));
	m_btn3 = new wxButton(mainPane, 1003, "Stergere persoana", wxPoint(500, 300), wxSize(150, 50));
	m_btn4 = new wxButton(mainPane, 1004, "Generare CNP", wxPoint(100, 400), wxSize(150, 50));
	m_btn5 = new wxButton(mainPane, 1005, "Modificare date persoana", wxPoint(300, 400), wxSize(150, 50));


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



void cMain::inregistrarePeroana(wxCommandEvent& evt) {
	if (m_txt1->GetValue() == wxT("") || m_txt2->GetValue() == wxT("") || m_txt3->GetValue() == wxT("") || m_txt4->GetValue() == wxT("")
		|| m_txt5->GetValue() == wxT("") || m_txt6->GetValue() == wxT("") || m_txt7->GetValue() == wxT("") || m_txt8->GetValue() == wxT("")
		|| m_txt9->GetValue() == wxT("") || m_txt10->GetValue() == wxT("") || m_txt11->GetValue() == wxT("")) {

		wxMessageBox(wxT("Nu ai introdus toate datele necesare!"), wxT("Eroare"), wxICON_ERROR);
	}
	else {
		exit = sqlite3_open(numeFisier.c_str(), &DB);
		std::string ins;


		ins = "INSERT INTO buletin(CNP,Serie,Numar,Nume,Prenume,Cetatenie,Sex,LocNastere,Domiciliu,EmisaDe,Valabilitate) VALUES(";
		ins.append(m_txt1->GetValue() + ",'");
		ins.append(m_txt4->GetValue() + "',");
		ins.append(m_txt5->GetValue() + ",'");
		ins.append(m_txt2->GetValue() + "','");
		ins.append(m_txt3->GetValue() + "','");
		ins.append(m_txt6->GetValue() + "','");
		ins.append(m_txt7->GetValue() + "','");
		ins.append(m_txt8->GetValue() + "','");
		ins.append(m_txt9->GetValue() + "','");
		ins.append(m_txt10->GetValue() + "','");
		ins.append(m_txt11->GetValue() + "');");

		inserareDB(exit, ins);


		sqlite3_close(DB);
	}
	evt.Skip();
}

void cMain::generareCNP(wxCommandEvent& evt)
{
	int s, aa, ll, zz, jj, nnn, c;
	std::string cnp;
	if (m_txt6->GetValue() == wxT("Romana")) {
		if(m_txt7->GetValue() == wxT("M")){
			s = 1;
		}
		else {
			s = 2;
		}
	}
	else {
		if (m_txt7->GetValue() == wxT("M")) {
			s = 7;
		}
		else {
			s = 8;
		}
	}
	aa = (std::stoi((std::string)m_txt14->GetValue())) % 100;
	ll = std::stoi((std::string)m_txt13->GetValue());
	zz = std::stoi((std::string)m_txt12->GetValue());
	jj = 46;
	nnn = rand() % 999 + 1;
	c = (s / 2 + aa / 10 / 7 + aa % 10 / 9 + ll / 10 / 1 + ll % 10 / 4 + zz / 10 / 6 + zz % 10 / 3 + jj / 10 / 5 + jj % 10 / 8 + nnn / 100 / 5 + nnn / 10 % 10 / 7 + nnn % 10 / 9) % 11;
	cnp.append(std::to_string(s));
	if (aa < 10) {
		cnp.append("0" + std::to_string(aa));
	}
	else
	{
		cnp.append(std::to_string(aa));
	}
	
	if (ll < 10) {
		cnp.append("0" + std::to_string(ll));
	}
	else
	{
		cnp.append(std::to_string(ll));
	}
	if (zz < 10) {
		cnp.append("0" + std::to_string(zz));
	}
	else {
		cnp.append(std::to_string(zz));
	}
	
	cnp.append(std::to_string(jj));
	if (nnn < 10) {
		cnp.append("00" + std::to_string(nnn));
	}
	else {
		if (nnn < 100) {
			cnp.append("0" + std::to_string(nnn));
		}
		else
		{
			cnp.append(std::to_string(nnn));
		}
	}
	cnp.append(std::to_string(c));
	m_txt1->AppendText(cnp);
}

cMain::~cMain()
{
}

