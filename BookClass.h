#pragma once
#include "main.h"

class Book {
public:
	Book* next = nullptr;

	char chInformation[F_SIZE] = "\0";
	int nButton = 0;

	int menu();
	void error();
	void NoBook();
	void CompleteDelete();
	void CompleteInsert();
	void GetName();
	void GetWriter();
	void GetYear();
	void GetInformation();
	void HowInitialize();
	void InitializeComplete();
};