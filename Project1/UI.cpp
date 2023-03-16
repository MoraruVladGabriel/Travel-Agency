#include "UI.h"
#include <iostream>
using namespace std;



int UI::login()
{
	string user, pass;
	cout << "Dati user: ";
	cin >> user;
	cout << endl << "Parola:";
	cin >> pass;
	u.setUserName(user);
	u.setPassword(pass);
	return s.login(user, pass);
}

void UI::logout()
{
	s.logout(u.getUserName(),u.getPassword());
}

void UI::findFlights()
{
	cout << "Dati destinatia:";
	string destination;
	cin >> destination;
	vector<Zbor>all= s.getAllFlightsToDestination(destination);
	for (Zbor z : all)
		cout << z.toString() << endl;
}

void UI::buyTickets()
{
	string destinatie, data, ora;
	int nr;
	cout << "Dati destinatia:";
	cin >> destinatie;
	cout << "Dati data:";
	cin >> data;
	cout << "Dati ora:";
	cin >> ora;
	cout << "Dati nr locuri:";
	cin >> nr;
	s.buyTicket(destinatie, data, ora, nr);
	cout << "Bilete cumparate cu succes!" << endl;
}

void UI::soldTickets()
{
	string dest, data, ora;
	cout << "Dati destinatia:";
	cin >> dest;
	cout << "Dati data:";
	cin >> data;
	cout << "Dati ora:";
	cin >> ora;
	cout << "Nr de locuri vandute este " << s.findSoldSeats(dest, data, ora) << endl;
}

void UI::availablePlaces()
{
	string dest, data, ora;
	cout << "Dati destinatia:";
	cin >> dest;
	cout << "Dati data:";
	cin >> data;
	cout << "Dati ora:";
	cin >> ora;
	cout << "Numarul de locuri disponibile este " << s.findAvailableSeats(dest, data, ora) << endl;
}

void UI::allFlights()
{
	vector<Zbor> all = s.getAllFlights();
	for (Zbor z : all)
		cout << z.toString() << endl;
}

UI::UI()
{
}


UI::UI(Service & ss)
{
	s = ss;
}

void UI::showMenu()
{
	bool gata=false;
	int rez=login();
	if(rez){
		while (!gata) {
			cout << "1. Cauta zboruri la o destinatie " << endl;
			cout << "2. Verifica numarul de bilete vandute la un zbor " << endl;
			cout << "3. Verifica numarul de locuri disponibile la un zbor" << endl;
			cout << "4. Cumpara bilet" << endl;
			cout << "5. Toate zborurile " << endl;
			cout << "0. Logout" << endl;
			int opt;
			cout << "Dati optiunea: " << endl;
			cin >> opt;
			switch (opt) {
			case 1: {findFlights(); break; }
			case 2: {soldTickets(); break; }
			case 3: {availablePlaces(); break; }
			case 4: {buyTickets(); break; }
			case 5: {allFlights(); break; }
			case 0: {logout(); gata = true; }
			}

		}
	}
	else cout << "Autentificare esuata!" << endl;
}

UI::~UI()
{
}
