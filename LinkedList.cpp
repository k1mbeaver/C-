#include "main.h"
#include "BookClass.h"
#include "FileClass.h"

int File::makeLinkedList(Book* Head, FILE* Filetxt)
{
	system("cls");
	int npCount = 0; // 
	Head->next = NULL;
	Filetxt = fopen("Book.txt", "r");

	while (fgets(chBuffer, F_SIZE, Filetxt) != NULL)
	{
		Book* newNode = new Book();

		strcpy(newNode->chInformation, chBuffer);

		if (Head->next == NULL)
		{
			Head->next = newNode;
		}
		else
		{
			Tail->next = newNode;
		}
		newNode->next = NULL;
		Tail = newNode;
		npCount++;
	}

	fclose(Filetxt);

	return npCount;
}

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

