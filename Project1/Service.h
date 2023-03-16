#pragma once
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "Zbor.h"
#include "Bilet.h"
#include "User.h"

class Service
{
private:
	IRepository<Zbor>* repoZbor;
	IRepository<Bilet>* repoBilet;
	IRepository<User>* repoUser;
	int findNoOfSeats(string destinatie, string data, string ora);
	

public:
	Service();
	Service(IRepository<Zbor>*, IRepository<Bilet>*, IRepository<User>*);
	bool login(string, string);
	void logout(string, string);
	void buyTicket(string destinatie, string data, string ora, int nrLocuri);
	int findAvailableSeats(string destinatie, string data, string ora);
	int findSoldSeats(string destinatie, string data, string ora);
	vector<Zbor> getAllFlights();
	vector<Zbor> getAllFlightsToDestination(string destinatie);
	~Service();
};

