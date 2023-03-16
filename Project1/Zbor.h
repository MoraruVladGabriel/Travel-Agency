#pragma once

#include <string>
using namespace std;

class Zbor
{private:
	string destinatie;
	string data;
	string ora;
	int nrLocuri;
public:
	Zbor();
	Zbor(string, string, string, int);
	Zbor(string, char);
	Zbor(const Zbor&);
	string getDestinatia();
	string getData();
	string getOra();
	int getNrLocuri();
	void setDestinatie(string);
	void setData(string);
	void setOra(string);
	void setNrLocuri(int);
	bool operator==(const Zbor&);
	string toString();
	string toStringDelimiter(char);
	~Zbor();
	friend class Bilet;
};

