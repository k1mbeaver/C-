#pragma once
#include "SingleTon.h"
#include "LinkedList.h"
#include "FileClass.h"

class File {

public:
	char chFName[SIZE] = "\0";
	char chFWriter[SIZE] = "\0";
	int nFYear = 0;
	char chBuffer[F_SIZE] = "\0";

	Link chInformation[F_SIZE];
	FILE* Filetxt = NULL;
	Link* Head = new Link();
	Link* newNode = NULL;
	Link* Tail = NULL;

	int makeLinkedList(Link* Head, FILE* Filetxt);
	void returnNode();
	void linkedlistTofile(FILE* Filetxt);
	void printallindex();
	void insertbook();
	void deletebook();
	void searchbook();
	void initializeindex();
	SingletonClass* Help;
};
