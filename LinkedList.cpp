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

