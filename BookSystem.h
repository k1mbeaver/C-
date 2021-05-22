#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#define SIZE 100
#define F_SIZE 210
using namespace std;


class BookSystem {
public:
	int nButton = 0;

	int menu();
	void Process();
	void error();
	void NoBook();
	void CompleteDelete();
	void CompleteInsert();
	void GetName();
	void GetWriter();
	void GetYear();
	void GetInformation();
	void HowInitialize();
	void saveComplete();
	void Information();
};
