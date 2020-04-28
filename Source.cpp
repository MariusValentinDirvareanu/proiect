#include <iostream>
#include <sqlite3.h>
#include <fstream>
#include <filesystem>

using namespace std;

// Printare informatii extrase din baza de date
static int callback(void *data, int argc, char **argv, char **azColName)
{
	cout << (const char *)data << ":\n";

	for (int i = 0; i < argc; ++i)
	{
		cout << azColName[i] << " = " << (argv[i] ? argv[i] : "NULL") << '\n';
	}

	cout << '\n';
	return 0;
}

int creareTabel(int &exit, sqlite3 *DB, string queryCreare)
{
	// Apelare query de creare baza de date
	char *messaggeError;
	exit = sqlite3_exec(DB, queryCreare.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		cerr << "Error Create Table\n";
		sqlite3_free(messaggeError);
		return -1;
	}
	else
		cout << "Table created Successfully\n";

	return 0;
}

int selectareTabel(int exit, sqlite3 *DB)
{
	string data = "CALLBACK FUNCTION";

	// Query SELECT din baza de date
	string querySelectare = "SELECT * FROM PERSON;";
	// Verificare deschidere baza de date
	if (exit)
	{
		cerr << "Error open DB " << sqlite3_errmsg(DB) << '\n';
		return -1;
	}
	else
		cout << "Opened Database Successfully!" << '\n';

	// Apelare Query
	int rc = sqlite3_exec(DB, querySelectare.c_str(), callback, (void *)data.c_str(), NULL);

	// Afisare eraore sau succes
	if (rc != SQLITE_OK)
		cerr << "Error SELECT" << '\n';
	else
	{
		cout << "Operation OK!" << '\n';
	}
	return 0;
}

void inserare(int &exit, sqlite3 *DB, std::string &queryInserare)
{
	char *messaggeError;

	exit = sqlite3_exec(DB, queryInserare.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;
}

void stergere(int &exit, sqlite3 *DB, std::string &queryDelete)
{
	char *messaggeError;
	exit = sqlite3_exec(DB, queryDelete.c_str(), NULL, 0, &messaggeError);
	if (exit != SQLITE_OK)
	{
		std::cerr << "Error DELETE" << std::endl;
		sqlite3_free(messaggeError);
	}
	else
		std::cout << "Record deleted Successfully!" << std::endl;
}

int main()
{
	sqlite3 *DB;
	unsigned ok = 0;
	string numeFisier = "stock.db";
	int exit = 0;
	// Deschidere fisier baza de date pentru scriere si citire
	exit = sqlite3_open(numeFisier.c_str(), &DB);

	// Se verifica daca fisierul are marimea 0
	// Daca marimea este 0 se insereaza tabelul
	if (filesystem::file_size(numeFisier) == 0)
	{
		string magazine = "CREATE TABLE magazine ("
						  "id	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
						  "numemagazin	TEXT NOT NULL UNIQUE,"
						  "judet	TEXT NOT NULL,"
						  "oras	TEXT,"
						  "comuna	TEXT,"
						  "strada	TEXT,"
						  "numar	TEXT,"
						  "bloc	TEXT,"
						  "domeniu	TEXT NOT NULL);"
						  "CREATE TABLE stock ("
						  "id	INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT UNIQUE,"
						  "denumire	TEXT NOT NULL,"
						  "unitati	INTEGER NOT NULL,"
						  "kg	REAL,"
						  "litri	REAL,"
						  "pretunitate	REAL NOT NULL);"
						  "CREATE TABLE COMENZI("
						  "ID	INTEGER	NOT NULL	PRIMARY KEY AUTOINCREMENT UNIQUE,"
						  "IDMAGAZIN	INTEGER	NOT NULL,"
						  "IDPRODUS	INTEGER	NOT NULL,"
						  "UNITATI	INTEGER	NOT NULL,"
						  "FOREIGN KEY('idprodus') REFERENCES 'stock'('id'),"
						  "FOREIGN KEY('idmagazin') REFERENCES 'magazine'('id'));";

		creareTabel(exit, DB, magazine);
	}
	/*

	cout << "Inserati info? (1 sau 0)";
	cin >> ok;

	if (ok == 1) {
		string queryInserare = "INSERT INTO PERSON VALUES(1, 'STEVE', 'GATES', 30, 'PALO ALTO', 1000.0);"
			"INSERT INTO PERSON VALUES(2, 'BILL', 'ALLEN', 20, 'SEATTLE', 300.22);"
			"INSERT INTO PERSON VALUES(3, 'PAUL', 'JOBS', 24, 'SEATTLE', 9900.0);";

		inserare(exit, DB, queryInserare);
	}

		
	// Apelare functie de selectare
	selectareTabel(exit, DB);


	// Stergere din baza de date
	string queryDelete = "DELETE FROM PERSON WHERE ID = 2;";

	stergere(exit, DB, queryDelete);


	// Apelare functie de selectare
	selectareTabel(exit, DB);

	*/

	// Inchidere baza de date
	sqlite3_close(DB);
	return 0;
}
