#include "TestRepo.h"
#include <assert.h>



void TestRepo::runCSVTests()
{	
	/*Zboruri*/
	//RepositoryFile<Zbor>* repo = new RepositoryFileCSV<Zbor>("Zboruri.csv");
	//((RepositoryFileCSV<Zbor>*)repo)->loadFromFile();
	//assert(repo->size() == 2);
	//
	//Zbor z("Cluj-Napoca", "14.04.2020", "12:25", 195);
	//repo->add(z);
	//((RepositoryFileCSV<Zbor>*)repo)->saveToFile();

	//assert(repo->find(z) == 2);

	//Zbor z1("Cluj-Napoca", "14.04.2020", "12:25", 295);
	//repo->update(z, z1);
	//assert(repo->find(z1) == 2);
	//assert(repo->find(z) ==-1);
	//assert(repo->size()==3);
	
	/*Bilete*/
	const char* fileNameBilete = "Bilete.csv";
	Zbor z("Cluj-Napoca", "14.04.2020", "12:25", 195);
	RepositoryFile<Bilet>* repoBilet = new RepositoryFileCSV<Bilet>(fileNameBilete);
	((RepositoryFileCSV<Bilet>*)repoBilet)->loadFromFile();
	assert(repoBilet->size() == 2);

	Bilet b(z, 5);
	repoBilet->add(b);
	assert(repoBilet->size() == 3);

	repoBilet->remove(b);
	assert(repoBilet->size() == 2);
	
	assert(repoBilet->find(b) == -1);
}

void TestRepo::runTXTTests()
{
	//RepositoryFile<Zbor>* repo = new RepositoryFileTXT<Zbor>("Zboruri.txt");
	//((RepositoryFileTXT<Zbor>*)repo)->loadFromFile();
	//assert(repo->size() == 2);

	//Zbor z("Cluj-Napoca", "14.04.2020", "12:25", 195);
	//repo->add(z);
	//((RepositoryFileCSV<Zbor>*)repo)->saveToFile();

	//assert(repo->find(z) == 2);

	//Zbor z1("Cluj-Napoca", "14.04.2020", "12:25", 295);
	//repo->update(z, z1);
	//assert(repo->find(z1) == 2);
	//assert(repo->find(z) == -1);
	//assert(repo->size() == 3);

	/*Bilete*/
	const char* fileNameBilete = "Bilete.txt";
	Zbor z("Cluj-Napoca", "14.04.2020", "12:25", 195);
	RepositoryFile<Bilet>* repoBilet = new RepositoryFileTXT<Bilet>(fileNameBilete);
	((RepositoryFileTXT<Bilet>*)repoBilet)->loadFromFile();
	assert(repoBilet->size() == 2);

	Bilet b(z, 5);
	repoBilet->add(b);
	assert(repoBilet->size() == 3);

	repoBilet->remove(b);
	assert(repoBilet->size() == 2);

	assert(repoBilet->find(b) == -1);
}

void TestRepo::runInMemoryTests()
{
	IRepository<User>* repoUseri = new RepositoryInMemory<User>();
	User u("Ana", "123");
	
	repoUseri->add(u);
	assert(repoUseri->size() == 1);

	assert(repoUseri->find(u) == 0);

}

TestRepo::TestRepo()
{
}



void TestRepo::runTests()
{
	runCSVTests();
	runTXTTests();
	runInMemoryTests();
	
}


TestRepo::~TestRepo()
{
}
