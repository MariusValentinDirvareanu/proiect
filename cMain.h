#pragma once

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "sqlite3.h"
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include "wx/msgdlg.h"
#include "wx/stattext.h"
#include "wx/combobox.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
	void creareTabelDB(int& exit, std::string queryCreare);
	void inserareDB(int& exit, std::string& queryInserare);
	void stergereDB(int& exit, std::string& queryDelete);
	void primaPornire();
	void inregistrarePeroana(wxCommandEvent& evt);
	void generareCNP(wxCommandEvent& evt);
	void cautarePersoana(wxCommandEvent& evt);
	void stergerePersoana(wxCommandEvent& evt);
	void modificarePersoana(wxCommandEvent& evt);

public:
	wxButton* buton_inregistrare = nullptr;
	wxButton* buton_cautare = nullptr;
	wxButton* buton_stergere = nullptr;
	wxButton* buton_generare = nullptr;
	wxButton* buton_modificare = nullptr;
	wxPanel* mainPane = nullptr;
	sqlite3* DB;
	unsigned ok = 0;
	std::string numeFisier = "persoane.db";
	int exit = 0;
	char* messaggeError;
	wxStaticText* cnp = nullptr;
	wxTextCtrl* text_cnp = nullptr;
	wxStaticText* nume = nullptr;
	wxTextCtrl* text_nume = nullptr;
	wxStaticText* prenume = nullptr;
	wxTextCtrl* text_prenume = nullptr;
	wxStaticText* serie = nullptr;
	wxTextCtrl* m_txt4 = nullptr;
	wxStaticText* numar = nullptr;
	wxTextCtrl* text_numar = nullptr;
	wxStaticText* cetatenie = nullptr;
	wxTextCtrl* text_cetatenie = nullptr;
	wxStaticText* gen = nullptr;
	wxTextCtrl* m_txt7 = nullptr;
	wxStaticText* locNastere = nullptr;
	wxTextCtrl* text_locNastere = nullptr;
	wxStaticText* domiciliu = nullptr;
	wxTextCtrl* text_domiciliu = nullptr;
	wxStaticText* emisaDe = nullptr;
	wxTextCtrl* text_emisaDe = nullptr;
	wxStaticText* valabilitate = nullptr;
	wxTextCtrl* text_valabilitate = nullptr;
	wxStaticText* dataNasterii = nullptr;
	wxTextCtrl* text_zi_dataNasterii = nullptr;
	wxTextCtrl* text_luna_dataNasterii = nullptr;
	wxTextCtrl* text_an_dataNasterii = nullptr;
	wxStaticText* judetNastere = nullptr;
	wxComboBox* combo_judetNastere = nullptr;
	wxComboBox* combo_gen = nullptr;
	wxComboBox* combo_serie = nullptr;
	wxArrayString jud;
	wxArrayString judeteNastere;
	std::vector<wxString> vec_serie = { "AB","AR","AG","BC","BH","BN","BT","BV","BR","BZ","CS","CJ","CT","CV","DB","DJ","GL","GJ","HR","HD","IL","IS",
		"IF","MM","MH","MS","NT","OT","PH","SM","SJ","SB","SV","TR","TM","TL","VS","VL","VN","B","CL","GR" };
	std::vector<wxString> vec_judete = { "Alba","Arad","Arges","Bacau","Bihor","Bistrita-Nasaud","Botosani","Brasov","Braila","Buzau","Caras-Severin","Cluj",
		"Constanta","Covasna","Dambovita","Dolj","Galati","Gorj","Harghita","Hunedoara","Ialomita","Iasi","Ilfov","Maramures","Mehedinti","Mures","Neamt","Olt",
		"Prahova","Satu Mare","Salaj","Sibiu","Suceava","Teleorman","Timis","Tulcea","Vaslui","Valcea","Vrancea","Bucuresti","Bucuresti - Sector 1",
		"Bucuresti - Sector 2","Bucuresti - Sector 3","Bucuresti - Sector 4","Bucuresti - Sector 5","Bucuresti - Sector 6","Calarasi","Giurgiu" };

	wxDECLARE_EVENT_TABLE();
};

