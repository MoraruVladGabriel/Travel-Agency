#pragma once
#include "RepositoryFile.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "RepositoryInMemory.h"
#include "Zbor.h"
#include "Bilet.h"
#include "User.h"

class TestRepo
{private:
	void runCSVTests();
	void runTXTTests();
	void runInMemoryTests();
public:
	TestRepo();
	void runTests();
	~TestRepo();
};

