#pragma once
#include "SingleTon.h"

class File {

public:
	char chFName[SIZE] = "\0";
	char chFWriter[SIZE] = "\0";
	int nFYear = 0;
	char chBuffer[F_SIZE] = "\0";

	char chInformation[F_SIZE];
	FILE* Filetxt = NULL;

	//int makeLinkedList(SingletonClass* Head, FILE* Filetxt);
	void returnNode();
	void linkedlistTofile(FILE* Filetxt);
	void printallindex();
	void insertbook();
	void deletebook();
	void searchbook();
	void savefile();
	void readfile();
	BookSystem Help;
};
