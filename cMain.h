#pragma once

#include "wx/wx.h"
#include "wx/listctrl.h"
#include "sqlite3.h"
#include <vector>
#include <map>
#include <string>
#include <filesystem>
#include "wx/msgdlg.h"
#include "wx/stattext.h"


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
	wxButton* m_btn1 = nullptr;
	wxButton* m_btn2 = nullptr;
	wxButton* m_btn3 = nullptr;
	wxButton* m_btn4 = nullptr;
	wxButton* m_btn5 = nullptr;
	wxPanel* mainPane = nullptr;
	sqlite3* DB;
	unsigned ok = 0;
	std::string numeFisier = "persoane.db";
	std::map<int, std::vector<std::string>> judete = { {1,{"Alba","AB"}},{2,{"Arad","AR"}},{3,{"Arges","AG"}},
		{4,{"Bacau","BC"}},{5,{"Bihor","BH"}},{6,{"Bistrita-Nasaud","BN"}},{7,{"Botosani","BT"}},
		{8,{"Brasov","BV"}},{9,{"Braila","BR"}},{10,{"Buzau","BZ"}},{11,{"Caras-Severin","CS"}},
		{12,{"Cluj","CJ"}},{13,{"Constanta","CT"}},{14,{"Covasna","CV"}},{15,{"Dambovita","DB"}},
		{16,{"Dolj","DJ"}},{17,{"Galati","GL"}},{18,{"Gorj","GJ"}},{19,{"Harghita","HR"}},
		{20,{"Hunedoara","HD"}},{21,{"Ialomita","IL"}},{22,{"Iasi","IS"}},{23,{"Ilfov","IF"}},
		{24,{"Maramures","MM"}},{25,{"Mehedinti","MH"}},{26,{"Mures","MS"}},{27,{"Neamt","NT"}},
		{28,{"Olt","OT"}},{29,{"Prahova","PH"}},{30,{"Satu Mare","SM"}},{31,{"Salaj","SJ"}},
		{32,{"Sibiu","SB"}},{33,{"Suceava","SV"}},{34,{"Teleorman","TR"}},{35,{"Timis","TM"}},
		{36,{"Tulcea","TL"}},{37,{"Vaslui","VS"}},{38,{"Valcea","VL"}},{39,{"Vrancea","VN"}},
		{40,{"Bucuresti","B"}},{41,{"Bucuresti - Sector 1","B"}},{42,{"Bucuresti - Sector 2","B"}},
		{43,{"Bucuresti - Sector 3","B"}},{44,{"Bucuresti - Sector 4","B"}},{45,{"Bucuresti - Sector 5","B"}},
		{46,{"Bucuresti - Sector 6","B"}},{51,{"Calarasi","CL"}},{52,{"Giurgiu","GR"}}, };
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
	wxStaticText* txt6 = nullptr;
	wxTextCtrl* m_txt6 = nullptr;
	wxStaticText* txt7 = nullptr;
	wxTextCtrl* m_txt7 = nullptr;
	wxStaticText* txt8 = nullptr;
	wxTextCtrl* m_txt8 = nullptr;
	wxStaticText* txt9 = nullptr;
	wxTextCtrl* m_txt9 = nullptr;
	wxStaticText* txt10 = nullptr;
	wxTextCtrl* m_txt10 = nullptr;
	wxStaticText* txt11 = nullptr;
	wxTextCtrl* m_txt11 = nullptr;
	wxStaticText* txt12 = nullptr;
	wxTextCtrl* m_txt12 = nullptr;
	wxTextCtrl* m_txt13 = nullptr;
	wxTextCtrl* m_txt14 = nullptr;

	wxDECLARE_EVENT_TABLE();
};

