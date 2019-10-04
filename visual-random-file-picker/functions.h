//melkadze
#pragma once

#include <stdlib.h>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <string>
#undef max //max causes a command conflict, so we are undefining it here

int customRand() {
	srand(time(NULL));
	int a = rand();
	srand(time(NULL));
	int b = rand();
	return (a*(RAND_MAX+1)+b);
}

void fileCheck() {
	if (std::ifstream("$randomselector.txt")) { return; }
	system("dir *.jpg,*.png,*.gif,*.jpeg /b /s > $randomselector.txt");
	/* change this line to modify the files this program will open
	NOTE: you must change this line in MyForm.h as well!     */
}

std::fstream& gotoLine(std::fstream& file, long long int num) { 
	file.unsetf(std::ios_base::skipws);
	file.seekg(std::ios::beg);
	for (long long int i = 0; i < num - 1; ++i)
	{
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return file;
}

void randomLine(long long int howmany) {
	std::ifstream randLine("$randomselector.txt");
	std::string line;
	randLine.unsetf(std::ios_base::skipws);
	long long int number_of_lines = -1;
	if (randLine.is_open()) {
		while (!randLine.eof()) {
			getline(randLine, line);
			number_of_lines++;
		}
		randLine.close();
	}
	long long int howmanydone = 0;
	long long int linetoopen;
	while (howmanydone < howmany) {
		linetoopen = rand() % number_of_lines + 1;
		std::fstream file("$randomselector.txt", std::ios::in);
		file.unsetf(std::ios_base::skipws);
		gotoLine(file, linetoopen);
		std::string whichline;
		getline(file, whichline);
		file.close();
		system(("call \"" + whichline + "\"").c_str());
		//runs a system command in order to open the required file
		howmanydone++;
	}
}