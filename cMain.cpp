#include "cMain.h"


wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(1001, inregistrarePeroana)
	EVT_BUTTON(1002, cautarePersoana)
	EVT_BUTTON(1003, stergerePersoana)
	EVT_BUTTON(1004, generareCNP)
	EVT_BUTTON(1005, modificarePersoana)
	EVT_BUTTON(1006, curatare)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Test", wxPoint(10, 10),wxSize(800, 600))
{

	wxSize s = wxSize(67, 20);
    
    mainPane = new wxPanel(this);
    
	cnp = new wxStaticText(mainPane, wxID_ANY, "CNP", wxPoint(30, 30), s);
	text_cnp = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 30), wxSize(300, 20));

	nume = new wxStaticText(mainPane, wxID_ANY, "Nume", wxPoint(30, 60), s);
	text_nume = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 60), wxSize(300, 20));

	prenume = new wxStaticText(mainPane, wxID_ANY, "Prenume", wxPoint(30, 90), s);
	text_prenume = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 90), wxSize(300, 20));


	jud.assign(vec_serie.begin(), vec_serie.end());
	judeteNastere.assign(vec_judete.begin(), vec_judete.end());

	serie = new wxStaticText(mainPane, wxID_ANY, "Serie", wxPoint(500, 30), s);
	combo_serie = new wxComboBox(mainPane, 2001, "", wxPoint(600, 30), s, jud);


	numar = new wxStaticText(mainPane, wxID_ANY, "Numar", wxPoint(500, 60), s);
	text_numar = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 60), wxSize(100, 20));

	cetatenie = new wxStaticText(mainPane, wxID_ANY, "Cetatenie", wxPoint(30, 120), s);
	text_cetatenie = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 120), wxSize(300, 20));

	gen = new wxStaticText(mainPane, wxID_ANY, "Sex", wxPoint(530, 120), s);
	alegeri.Add("M");
	alegeri.Add("F");
	combo_gen = new wxComboBox(mainPane, wxID_ANY, "M", wxPoint(600, 120), s, alegeri);

	judetNastere = new wxStaticText(mainPane, wxID_ANY, "Judet Nastere", wxPoint(500, 150), wxSize(80, 20));
	combo_judetNastere = new wxComboBox(mainPane, wxID_ANY, "", wxPoint(600, 150), wxSize(150, 20), judeteNastere);

	locNastere = new wxStaticText(mainPane, wxID_ANY, "Loc Nastere", wxPoint(30, 150), s);
	text_locNastere = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 150), wxSize(300, 20));

	domiciliu = new wxStaticText(mainPane, wxID_ANY, "Domiciliu", wxPoint(30, 180), s);
	text_domiciliu = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 180), wxSize(300, 20));

	emisaDe = new wxStaticText(mainPane, wxID_ANY, "Emisa de", wxPoint(30, 210), s);
	text_emisaDe = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(100, 210), wxSize(300, 20));

	valabilitate = new wxStaticText(mainPane, wxID_ANY, "Valabilitate", wxPoint(500, 210), s);
	text_valabilitate = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(450, 240), wxSize(200, 20));

	dataNasterii = new wxStaticText(mainPane, wxID_ANY, "Data nasterii", wxPoint(500, 90), s);
	text_zi_dataNasterii = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(600, 90), wxSize(40, 20));
	text_luna_dataNasterii = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(650, 90), wxSize(40, 20));
	text_an_dataNasterii = new wxTextCtrl(mainPane, wxID_ANY, "", wxPoint(700, 90), wxSize(40, 20));


	buton_inregistrare = new wxButton(mainPane, 1001, "Inregistrare persoana", wxPoint(100, 300), wxSize(150, 50));
	buton_cautare = new wxButton(mainPane, 1002, "Cautare CNP", wxPoint(300, 300), wxSize(150, 50));
	buton_stergere = new wxButton(mainPane, 1003, "Stergere persoana", wxPoint(500, 300), wxSize(150, 50));
	buton_generare = new wxButton(mainPane, 1004, "Generare CNP", wxPoint(100, 400), wxSize(150, 50));
	buton_modificare = new wxButton(mainPane, 1005, "Modificare date persoana", wxPoint(300, 400), wxSize(150, 50));
	buton_modificare = new wxButton(mainPane, 1006, "Curatare", wxPoint(500, 400), wxSize(150, 50));


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
		std::string persoane = "CREATE TABLE buletin ("
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
			"Valabilitate	TEXT NOT NULL,"
			"Zi	INTEGER NOT NULL,"
			"Luna	INTEGER NOT NULL,"
			"An	INTEGER NOT NULL,"
			"JudNastere	TEXT NOT NULL);";

		creareTabelDB(exit, persoane);
	}

	sqlite3_close(DB);
	// End baza de date
}



void cMain::inregistrarePeroana(wxCommandEvent& evt) {
	if (text_cnp->GetValue() == wxT("") || text_nume->GetValue() == wxT("") || text_prenume->GetValue() == wxT("")
		|| text_numar->GetValue() == wxT("") || text_cetatenie->GetValue() == wxT("") || text_locNastere->GetValue() == wxT("")
		|| text_domiciliu->GetValue() == wxT("") || text_emisaDe->GetValue() == wxT("") || text_valabilitate->GetValue() == wxT("") || text_zi_dataNasterii->GetValue() == wxT("")
		|| text_luna_dataNasterii->GetValue() == wxT("") || text_an_dataNasterii->GetValue() == wxT("")) {

		wxMessageBox(wxT("Nu ai introdus toate datele necesare!"), wxT("Eroare"), wxICON_ERROR);
	}
	else {
		exit = sqlite3_open(numeFisier.c_str(), &DB);
		std::string ins;


		ins = "INSERT INTO buletin(CNP,Serie,Numar,Nume,Prenume,Cetatenie,Sex,LocNastere,Domiciliu,EmisaDe,Valabilitate,Zi,Luna,An,JudNastere) VALUES(";
		ins.append(text_cnp->GetValue() + ",'");
		ins.append(combo_serie->GetValue() + "',");
		ins.append(text_numar->GetValue() + ",'");
		ins.append(text_nume->GetValue() + "','");
		ins.append(text_prenume->GetValue() + "','");
		ins.append(text_cetatenie->GetValue() + "','");
		ins.append(combo_gen->GetValue() + "','");
		ins.append(text_locNastere->GetValue() + "','");
		ins.append(text_domiciliu->GetValue() + "','");
		ins.append(text_emisaDe->GetValue() + "','");
		ins.append(text_valabilitate->GetValue() + "',");
		ins.append(text_zi_dataNasterii->GetValue() + ",");
		ins.append(text_luna_dataNasterii->GetValue() + ",");
		ins.append(text_an_dataNasterii->GetValue() + ",'");
		ins.append(combo_judetNastere->GetValue() + "');");

		inserareDB(exit, ins);


		sqlite3_close(DB);
	}
	evt.Skip();
}

void cMain::generareCNP(wxCommandEvent& evt)
{
	int s, aa, ll, zz, jj, nnn, c;
	std::string cnp;
	if (text_cetatenie->GetValue() == wxT("") || text_zi_dataNasterii->GetValue() == wxT("") || text_luna_dataNasterii->GetValue() == wxT("") 
		|| text_an_dataNasterii->GetValue() == wxT("") || combo_judetNastere->GetValue() == wxT("")) {
		wxMessageBox(wxT("Nu ai introdus toate datele necesare!"), wxT("Eroare"), wxICON_ERROR);
	}
	else {
		if (text_cetatenie->GetValue() == wxT("Romana")) {
			if (combo_gen->GetValue() == wxT("M")) {
				s = 1;
			}
			else {
				s = 2;
			}
		}
		else {
			if (combo_gen->GetValue() == wxT("M")) {
				s = 7;
			}
			else {
				s = 8;
			}
		}
		aa = (std::stoi((std::string)text_an_dataNasterii->GetValue())) % 100;
		ll = std::stoi((std::string)text_luna_dataNasterii->GetValue());
		zz = std::stoi((std::string)text_zi_dataNasterii->GetValue());
		it = std::find(vec_judete.begin(), vec_judete.end(), combo_judetNastere->GetValue());
		jj = std::distance(vec_judete.begin(), it) + 1;
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
		text_cnp->ChangeValue(cnp);
	}
	evt.Skip();
}



void cMain::cautarePersoana(wxCommandEvent& evt)
{
	if (text_cnp->GetValue() == wxT("")) {
		wxMessageBox(wxT("Pentru a cauta o persoana, va rog, introduceti CNP"), wxT("Eroare"), wxICON_ERROR);
	}
	else {
		std::string query = "SELECT CNP, Serie, Numar, Nume, Prenume, Cetatenie, Sex, LocNastere, Domiciliu, EmisaDe, Valabilitate, Zi, Luna, An, JudNastere FROM buletin where CNP=";
		query.append(text_cnp->GetValue() + ";");

		exit = sqlite3_open(numeFisier.c_str(), &DB);

		sqlite3_stmt* stmt;
		const char* sql = query.c_str();
		int rc = sqlite3_prepare_v2(DB, sql, -1, &stmt, NULL);
		if (rc != SQLITE_OK) {
			wxMessageBox(sqlite3_errmsg(DB), wxT("Eroare"), wxICON_ERROR);
		}
		
		while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
			combo_serie->ChangeValue(sqlite3_column_text(stmt, 1));
			text_numar->ChangeValue(std::to_string(sqlite3_column_int(stmt, 2)));
			text_nume->ChangeValue(sqlite3_column_text(stmt, 3));
			text_prenume->ChangeValue(sqlite3_column_text(stmt, 4));
			text_cetatenie->ChangeValue(sqlite3_column_text(stmt, 5));
			combo_gen->ChangeValue(sqlite3_column_text(stmt, 6));
			text_locNastere->ChangeValue(sqlite3_column_text(stmt, 7));
			text_domiciliu->ChangeValue(sqlite3_column_text(stmt, 8));
			text_emisaDe->ChangeValue(sqlite3_column_text(stmt, 9));
			text_valabilitate->ChangeValue(sqlite3_column_text(stmt, 10));
			text_zi_dataNasterii->ChangeValue(std::to_string(sqlite3_column_int(stmt, 11)));
			text_luna_dataNasterii->ChangeValue(std::to_string(sqlite3_column_int(stmt, 12)));
			text_an_dataNasterii->ChangeValue(std::to_string(sqlite3_column_int(stmt, 13)));
			combo_judetNastere->ChangeValue(sqlite3_column_text(stmt, 14));
		}

		

		if (rc != SQLITE_DONE) {
			wxMessageBox(sqlite3_errmsg(DB), wxT("Eroare"), wxICON_ERROR);
		}
		sqlite3_finalize(stmt);

		sqlite3_close(DB);

	}
	evt.Skip();
}

void cMain::stergerePersoana(wxCommandEvent& evt)
{

	std::string query = "DELETE FROM buletin where CNP=";
	query.append(text_cnp->GetValue() + ";");

	exit = sqlite3_open(numeFisier.c_str(), &DB);

	stergereDB(exit, query);
	sqlite3_close(DB);

	curatare(evt);

	evt.Skip();
}

void cMain::modificarePersoana(wxCommandEvent& evt)
{
	std::string queryUpdate = "UPDATE buletin SET ";
	queryUpdate.append("Serie='" + combo_serie->GetValue() + "',");
	queryUpdate.append("Numar=" + text_numar->GetValue() + ",");
	queryUpdate.append("Nume='" + text_nume->GetValue() + "',");
	queryUpdate.append("Prenume='" + text_prenume->GetValue() + "',");
	queryUpdate.append("Domiciliu='" + text_domiciliu->GetValue() + "',");
	queryUpdate.append("EmisaDe='" + text_emisaDe->GetValue() + "',");
	queryUpdate.append("Valabilitate='" + text_valabilitate->GetValue() + "' ");
	queryUpdate.append("WHERE CNP=" + text_cnp->GetValue() + ";");
	exit = sqlite3_open(numeFisier.c_str(), &DB);
	exit = sqlite3_exec(DB, queryUpdate.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		wxMessageBox(wxT("Eroare modificare in baza de date"), wxT("Eroare"), wxICON_ERROR);
		sqlite3_free(messaggeError);
	}
	else {
		wxMessageBox(wxT("Modificarea s-a facut cu succes!"), wxT("Succes!"), wxICON_INFORMATION);
		cautarePersoana(evt);
	}
	sqlite3_close(DB);
	evt.Skip();
}

void cMain::curatare(wxCommandEvent& evt)
{
	text_cnp->ChangeValue("");
	text_an_dataNasterii->ChangeValue("");
	text_cetatenie->ChangeValue("");
	text_domiciliu->ChangeValue("");
	text_emisaDe->ChangeValue("");
	text_locNastere->ChangeValue("");
	text_luna_dataNasterii->ChangeValue("");
	text_numar->ChangeValue("");
	text_nume->ChangeValue("");
	text_prenume->ChangeValue("");
	text_valabilitate->ChangeValue("");
	text_zi_dataNasterii->ChangeValue("");
	combo_gen->ChangeValue("");
	combo_judetNastere->ChangeValue("");
	combo_serie->ChangeValue("");
	evt.Skip();
}


cMain::~cMain()
{
}

