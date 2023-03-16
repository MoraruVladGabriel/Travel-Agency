#pragma once
#include <string>
#include "Service.h"
using namespace std;

class UI
{private:
	Service s;
	User u;
	int login();
	void logout();
    void findFlights();
	void buyTickets();
	void soldTickets();
	void availablePlaces();
	void allFlights();
public:
	UI();
	UI(Service&);
	void showMenu();
	~UI();
};

