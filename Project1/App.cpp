/*O agentie de turism colaboreaza cu o companie de zbor pentru a transporta clienții la diferite destinații
turistice. Agenția foloseste un sistem soft pentru a cumpăra bilete pentru turiști. Angajații de la agenția` de
turism folosesc o aplicație desktop cu următoarele funcționalități:
1. Login. După autentificarea cu success, angajatul poate sa vada informațiile
despre zboruri (destinația, data și ora plecării și numărul de locuri disponbile).
2. Căutare. După autentificarea cu succes, angajatul poate căuta un zbor introducând informatiile despre zbor. 
Aplicația va afișa  toate zborurile pentru acea destinație, ora plecării și numărul de locuri disponibile.
3. Cumpărare. Angajatul poate cumpara bilete pentru clienți pentru o anumită destinație, la o anumită dată,
respectiv oră de plecare.*
4. Logout.

ATENTIE pentru logare sunt stocati doar urmatorii useri: "Ana", "123" si "Ion", "1234";
*/
#include "IRepository.h"
#include "Zbor.h"
#include "Bilet.h"
#include "RepositoryFileCSV.h"
#include "TestRepo.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main() {
/*	const char* fileName = "Zboruri.csv"; 
	RepositoryFile<Zbor>* repo = new RepositoryFileCSV<Zbor>(fileName);
	((RepositoryFileCSV<Zbor>*)repo)->loadFromFile();
	Zbor z("Cluj-Napoca", "14.04.2020", "12:25", 195);
	repo->add(z);
	((RepositoryFileCSV<Zbor>*)repo)->saveToFile();
	
	cout<<repo->size();

	const char* fileNameBilete = "Bilete.csv";
	RepositoryFile<Bilet>* repoBilet = new RepositoryFileCSV<Bilet>(fileNameBilete);
	((RepositoryFileCSV<Bilet>*)repoBilet)->loadFromFile();
	Bilet b(z, 5);
	repoBilet->add(b);
	cout << repoBilet->size();*/
	
	/*TestRepo tr;
	tr.runTests();
	*/

	
	IRepository<Zbor>* repoZbor = new RepositoryFileCSV<Zbor>("Zboruri.csv");
	((RepositoryFile<Zbor>*)repoZbor)->loadFromFile();
	IRepository<Bilet>* repoBilet = new RepositoryFileCSV<Bilet>("Bilete.csv");
	((RepositoryFile<Bilet>*)repoBilet)->loadFromFile();
	IRepository<User>* repoUser = new RepositoryInMemory<User>();


	Service s(repoZbor, repoBilet, repoUser);
	UI ui(s);
	ui.showMenu();

	/*if (s.login("Ana", "123")) {

		Zbor z("Barcelona", "12/12/2020", "13:45", 35);
		int rez = s.findSoldSeats("Barcelona", "12/12/2020", "13:45");
		cout << rez << endl;
		s.buyTicket("Barcelona", "12/12/2020", "13:45", 5);
		rez = s.findSoldSeats("Barcelona", "12/12/2020", "13:45");
		cout << rez << endl;
		rez=s.findAvailableSeats("Barcelona", "12/12/2020", "13:45");
		cout << rez << endl;
		((RepositoryFileCSV<Bilet>*)repoBilet)->saveToFile();

	}*/
	return 0;
}