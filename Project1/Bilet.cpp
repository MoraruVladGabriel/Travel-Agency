#include "Bilet.h"
#include "Utils.h"



Bilet::Bilet()
{
	locuri = 0;
}

Bilet::Bilet(Zbor & zbor, int n)
{
	z = zbor;
	locuri = n;
}

Bilet::Bilet(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	z.destinatie = tokens[0];
	z.data = tokens[1];
	z.ora = tokens[2];
	z.nrLocuri = stoi(tokens[3]);
	locuri = stoi(tokens[4]);
}

Bilet::Bilet(const Bilet &b)
{
	z = b.z;
	locuri = b.locuri;
}

Zbor Bilet::getZbor()
{
	return z;
}

void Bilet::setZbor(Zbor & zb)
{
	z = zb;
}

void Bilet::setLocuri(int n)
{
	locuri = n;
}

int Bilet::getLocuri()
{
	return locuri;
}

bool Bilet::operator==(const Bilet &b)
{
	return z.operator==(b.z) and (locuri == b.locuri);
}

string Bilet::toString()
{
	return z.toString()+" "+std::to_string(locuri);
}

string Bilet::toStringDelimiter(char delim) 
{
	return z.toStringDelimiter(delim) + delim + std::to_string(locuri);
} 

Bilet::~Bilet()
{
}
