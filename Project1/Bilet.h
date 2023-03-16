#pragma once
#include "Zbor.h"


class Bilet
{private:
	Zbor z;
	int locuri;
public:
	Bilet();
	Bilet(Zbor&, int);
	Bilet(string, char);
	Bilet(const Bilet&);
	Zbor getZbor();
	void setZbor(Zbor&);
	void setLocuri(int);
	int getLocuri();
	bool operator==(const Bilet&);
	string toString();
	string toStringDelimiter(char delim);
	~Bilet();
};

