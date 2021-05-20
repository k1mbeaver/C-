#pragma once
#include "main.h"
#include "BookClass.h"
#include "FileClass.h"

class File {

public:
	char chFName[SIZE] = "\0";
	char chFWriter[SIZE] = "\0";
	int nFYear = 0;
	char chBuffer[F_SIZE] = "\0";

	Book chInformation[F_SIZE];
	FILE* Filetxt = NULL;
	Book* Head = new Book();
	Book* newNode = NULL;
	Book* Tail = NULL;

	int makeLinkedList(Book* Head, FILE* Filetxt);
	void returnNode();
	void linkedlistTofile(FILE* Filetxt);
	void printallindex();
	void insertbook();
	void deletebook();
	void searchbook();
	void initializeindex();
	Book Help;
};
