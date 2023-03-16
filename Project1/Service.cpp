#include "Service.h"
#include "User.h"



int Service::findNoOfSeats(string destinatie, string data, string ora)
{
	
	int total = 0;
	vector<Zbor> zboruri = repoZbor->getAll();
	for (Zbor z : zboruri) {
		if (z.getDestinatia() == destinatie and z.getData() == data and z.getOra() == ora)
			return z.getNrLocuri();
	}
	return 0;
}

Service::Service()
{
}

Service::Service(IRepository<Zbor>* repoZbor, IRepository<Bilet>* repoBilet, IRepository<User>* repoUseri)
{
	this->repoZbor = repoZbor;
	this->repoBilet = repoBilet;
	this->repoUser = repoUseri;
	User u1("Ana", "123");
	User u2("Ion", "1234");
	repoUser->add(u1);
	repoUser->add(u2);
}

bool Service::login(string u, string p)
{
	User usr(u, p);
	
	return repoUser->find(usr)!=-1;
}

void Service::logout(string name, string pass)
{
	User u(name, pass);
	repoUser->remove(u);
}

void Service::buyTicket(string destinatie, string data, string ora, int nrLocuri)
{
	Zbor z(destinatie, data, ora, findNoOfSeats(destinatie, data, ora));
	Bilet b(z, nrLocuri);
	repoBilet->add(b);
	((RepositoryFile<Bilet>*)repoBilet)->saveToFile();
}

int Service::findAvailableSeats(string destinatie, string data, string ora)
{
	int nrLocuri = findNoOfSeats(destinatie, data, ora);
	Zbor z(destinatie, data, ora, nrLocuri);
	return z.getNrLocuri() - findSoldSeats(destinatie, data, ora);
}




int Service::findSoldSeats(string dest, string data, string ora)
{
	int nrLocuri = findNoOfSeats(dest, data, ora);
	Zbor z(dest, data, ora, nrLocuri);
	int total = 0;
	vector<Bilet> bilete = repoBilet->getAll();
	for (Bilet b : bilete) {
		if (b.getZbor() == z)
			total += b.getLocuri();
	}
	return total;
}

vector<Zbor> Service::getAllFlights()
{
	return repoZbor->getAll();
}

vector<Zbor> Service::getAllFlightsToDestination(string destinatie)
{
	vector<Zbor> rez;
	vector<Zbor> zboruri = repoZbor->getAll();
	for (Zbor z : zboruri) {
		if (z.getDestinatia() == destinatie)
			rez.push_back(z);
	}
	return rez;
}


Service::~Service()
{
}
