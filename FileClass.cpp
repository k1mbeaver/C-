#include "FileClass.h"

//LinkedList
/*
void File::returnNode()
{
	newNode = Head->next; //맨 처음노드부터 시작
	while (newNode != NULL)//노드가 NULL이아니면
	{
		Head->next = newNode->next;//head가 현재노드의 주소가 가리키는 값을 가지고
		delete newNode; // 회수
		newNode = Head->next; // 그리고 다시 돌려받기 = 계속 주소를 따라서 이동
	}
}

void File::linkedlistTofile(FILE* Filetxt)
{
	newNode = Head->next;

	Filetxt = fopen("Book.txt", "w");

	while (newNode != NULL)
	{
		fprintf(Filetxt, "%s", newNode->chInformation);
		newNode = newNode->next;
	}

	fclose(Filetxt);
}
*/
//filemenu
void File::printallindex()
{
	system("cls");
	int naCount = 0;
	SingletonClass* testhead = SingletonClass::gethead();
	SingletonClass* newNode = NULL;
	SingletonClass* Tail = NULL;
	//출력하기
	int GetnCount = 1;

	if (testhead->next == NULL)
	{
		Help.NoBook();
	}
	else
	{
		newNode = testhead->next;
		Help.Information();
		while (newNode != NULL)
		{
			cout << "<" << GetnCount << ">" << " " << newNode->chInformation << endl << endl;
			newNode = newNode->next;
			GetnCount++;
		}
		system("pause");
	}
}

void File::insertbook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;
	//연결리스트 만들기
	SingletonClass* testhead = SingletonClass::gethead();
	//정보 입력
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//오류
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//오류
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}

	//오류
	else { Help.error(); return; }

	//추가하기
	SingletonClass* newNode = new SingletonClass();
	SingletonClass* curNode = NULL;
	curNode = testhead->next;
	strcpy(newNode->chInformation, chInformationBuffer);

	if (testhead->next == NULL)
	{
		testhead->next = newNode;
	}
	else
	{
		while (curNode != NULL)
		{
			if (curNode->next == NULL)
			{
				curNode->next = newNode;
				break;
			}
			curNode = curNode->next;
		}
	}
	newNode->next = NULL;

	Help.CompleteInsert();
}

void File::deletebook()
{
	char chInformationBuffer[F_SIZE] = "\0";
	int nReturnIndex = 0;

	//연결리스트 만들기
	SingletonClass* testhead = SingletonClass::gethead();

	//정보 입력
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//오류
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//오류
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}
	//오류
	else { Help.error(); return; }

	//도서가 없는 경우
	int nGetCount = 0;
	SingletonClass* curNode = NULL;
	curNode = testhead->next;

	while (curNode != NULL) // 연결리스트의 끝까지 갈때 까지 진행
	{
		if (strstr(chInformationBuffer, curNode->chInformation) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(chInformationBuffer, curNode->chInformation) == NULL)
		{
			curNode = curNode->next;
			continue;//계속 0으로 진행
		}
		curNode = curNode->next;
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	// 특정 노드 삭제하기
	SingletonClass* delNode = new SingletonClass();
	delNode = testhead->next;
	SingletonClass* befNode = testhead;
	SingletonClass* nextNode;
	nextNode = delNode->next;

	int nIndex = 0; // 처음을 표현
	
	while (delNode != NULL) // 노드가 NULL 일 때 까지
	{
		if (strstr(delNode->chInformation, chInformationBuffer) != NULL) // 노드안에 있는 chInformation 안에 아까 입력한 chBuffer가 있을 때
		{
			if (delNode->next == NULL) // 다음 노드가 없을 때
			{
				if (nIndex == 0) // 노드가 하나만 있을 때
				{
					delete delNode;

					testhead->next = NULL;
					Help.CompleteDelete();
					return;
				}

				else // 노드가 맨 끝에 있을 때
				{
					befNode->next = NULL;
					delete delNode;

					Help.CompleteDelete();
					return;
				}
			}
			else // 다음 노드가 있을 때
			{
				if (nIndex == 0) // 처음 일 때
				{
					testhead->next = nextNode;
					delete delNode;

					Help.CompleteDelete();
					return;
				}

				else // 처음이 아닐 때
				{
					befNode->next = nextNode;
					delete delNode;

					Help.CompleteDelete();
					return;
				}
			}
		}

		befNode = delNode;
		delNode = delNode->next;
		nextNode = delNode->next;
		nIndex++;
	}
}

void File::searchbook()
{
	system("cls");
	char chBookInformation[SIZE] = "\0";
	char chPrintInformation[F_SIZE] = "\0"; 
	char chBuffer[F_SIZE] = "\0";
	int nPrintCount = 1;

	Help.GetInformation();
	getchar();
	cin.getline(chBookInformation, SIZE, '\n');

	//오류
	if (chBookInformation[0] == ' ') { Help.error(); return; }


	//연결리스트 만들기
	SingletonClass* testhead = SingletonClass::gethead();

	//도서가 없는 경우
	int nGetCount = 0;
	SingletonClass* curNode = NULL;
	curNode = testhead->next;

	while (curNode != NULL) // 연결리스트의 끝까지 갈때 까지 진행
	{
		if (strstr(curNode->chInformation, chBookInformation) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(curNode->chInformation, chBookInformation) == NULL)
		{
			curNode = curNode->next;
			continue;//계속 0으로 진행
		}
		curNode = curNode->next;
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	//특정 도서 출력
	curNode = testhead->next;
	Help.Information();
	while (curNode != NULL)
	{
		if (strstr(curNode->chInformation, chBookInformation) != NULL)
		{
			cout << "<" << nPrintCount << "> " << curNode->chInformation << endl;
			nPrintCount++;
		}
		curNode = curNode->next;
	}
	system("pause");
}

void File::savefile()
{
	SingletonClass* testhead = SingletonClass::gethead();
	SingletonClass* curNode = NULL;
	curNode = testhead->next;
	FILE* Filetxt = NULL;
	Filetxt = fopen("Book.txt", "w");

	while (curNode != NULL)
	{
		fprintf(Filetxt, "%s", curNode->chInformation);
		curNode = curNode->next;
	}

	Help.saveComplete();
}