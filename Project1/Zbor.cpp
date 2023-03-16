#include "Zbor.h"
#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;



Zbor::Zbor()
{
}



Zbor::Zbor(string dest, string data, string ora, int nr)
{
	destinatie = dest;
	this->data = data;
	this->ora = ora;
	nrLocuri = nr;
}


Zbor::Zbor(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	destinatie = tokens[0];
	data = tokens[1];
	ora = tokens[2];
	nrLocuri = stoi(tokens[3]);
}

Zbor::Zbor(const Zbor &z)
{
	destinatie = z.destinatie;
	data = z.data;
	ora = z.ora;
	nrLocuri = z.nrLocuri;
}

string Zbor::getDestinatia()
{
	return destinatie;
}

string Zbor::getData()
{
	return data;
}

string Zbor::getOra()
{
	return ora;
}

int Zbor::getNrLocuri()
{
	return nrLocuri;
}

void Zbor::setDestinatie(string d)
{
	destinatie = d;
}

void Zbor::setData(string d)
{
	data = d;
}

void Zbor::setOra(string o)
{
	ora = o;
}

void Zbor::setNrLocuri(int n)
{
	nrLocuri = n;
}

bool Zbor::operator==(const Zbor &z)
{
	return (destinatie == z.destinatie) and (data == z.data) and (ora == z.ora) and (nrLocuri == z.nrLocuri);
}

string Zbor::toString()
{
	
	return destinatie+" "+data+ " "+ora+" "+ to_string(nrLocuri);;
}

string Zbor::toStringDelimiter(char delim)
{
	return destinatie + delim + data + delim + ora + delim + to_string(nrLocuri);
}


Zbor::~Zbor()
{
}
