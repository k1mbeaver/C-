#include "FileClass.h"

//LinkedList
/*
void File::returnNode()
{
	newNode = Head->next; //�� ó�������� ����
	while (newNode != NULL)//��尡 NULL�̾ƴϸ�
	{
		Head->next = newNode->next;//head�� �������� �ּҰ� ����Ű�� ���� ������
		delete newNode; // ȸ��
		newNode = Head->next; // �׸��� �ٽ� �����ޱ� = ��� �ּҸ� ���� �̵�
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
	//����ϱ�
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
	//���Ḯ��Ʈ �����
	SingletonClass* testhead = SingletonClass::gethead();
	//���� �Է�
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//����
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//����
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}

	//����
	else { Help.error(); return; }

	//�߰��ϱ�
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

	//���Ḯ��Ʈ �����
	SingletonClass* testhead = SingletonClass::gethead();

	//���� �Է�
	Help.GetName();
	getchar();
	cin.getline(chFName, SIZE, '\n');

	//����
	if (chFName[0] == ' ') { Help.error(); return; }

	Help.GetWriter();
	cin.getline(chFWriter, SIZE, '\n');

	//����
	if (chFWriter[0] == ' ') { Help.error(); return; }

	Help.GetYear();
	cin >> nFYear;
	if (nFYear >= 0 && nFYear <= 9999)
	{
		sprintf(chInformationBuffer, "%s / %s / %d\n", chFName, chFWriter, nFYear);
	}
	//����
	else { Help.error(); return; }

	//������ ���� ���
	int nGetCount = 0;
	SingletonClass* curNode = NULL;
	curNode = testhead->next;

	while (curNode != NULL) // ���Ḯ��Ʈ�� ������ ���� ���� ����
	{
		if (strstr(chInformationBuffer, curNode->chInformation) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(chInformationBuffer, curNode->chInformation) == NULL)
		{
			curNode = curNode->next;
			continue;//��� 0���� ����
		}
		curNode = curNode->next;
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	// Ư�� ��� �����ϱ�
	SingletonClass* delNode = new SingletonClass();
	delNode = testhead->next;
	SingletonClass* befNode = testhead;
	SingletonClass* nextNode;
	nextNode = delNode->next;

	int nIndex = 0; // ó���� ǥ��
	
	while (delNode != NULL) // ��尡 NULL �� �� ����
	{
		if (strstr(delNode->chInformation, chInformationBuffer) != NULL) // ���ȿ� �ִ� chInformation �ȿ� �Ʊ� �Է��� chBuffer�� ���� ��
		{
			if (delNode->next == NULL) // ���� ��尡 ���� ��
			{
				if (nIndex == 0) // ��尡 �ϳ��� ���� ��
				{
					delete delNode;

					testhead->next = NULL;
					Help.CompleteDelete();
					return;
				}

				else // ��尡 �� ���� ���� ��
				{
					befNode->next = NULL;
					delete delNode;

					Help.CompleteDelete();
					return;
				}
			}
			else // ���� ��尡 ���� ��
			{
				if (nIndex == 0) // ó�� �� ��
				{
					testhead->next = nextNode;
					delete delNode;

					Help.CompleteDelete();
					return;
				}

				else // ó���� �ƴ� ��
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

	//����
	if (chBookInformation[0] == ' ') { Help.error(); return; }


	//���Ḯ��Ʈ �����
	SingletonClass* testhead = SingletonClass::gethead();

	//������ ���� ���
	int nGetCount = 0;
	SingletonClass* curNode = NULL;
	curNode = testhead->next;

	while (curNode != NULL) // ���Ḯ��Ʈ�� ������ ���� ���� ����
	{
		if (strstr(curNode->chInformation, chBookInformation) != NULL)
		{
			nGetCount++;
		}

		else if (strstr(curNode->chInformation, chBookInformation) == NULL)
		{
			curNode = curNode->next;
			continue;//��� 0���� ����
		}
		curNode = curNode->next;
	}

	if (nGetCount == 0)
	{
		Help.NoBook();
		return;
	}

	//Ư�� ���� ���
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