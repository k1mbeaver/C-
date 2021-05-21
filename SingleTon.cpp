#include "SingleTon.h"
#include "FileClass.h"

/*
 * ��Ŭ������ ���� �ڵ� ������ �����ڿ� �Ҹ����� ���ø�
 * - ������: ������Ͽ��� private �����ڷ� ���� �� ������
 * - �Ҹ���: ������Ͽ��� public �Ҹ��ڷ� ���� �� ������
 * ��, �ҽ��ڵ忡���� �������� ����(�ؼ��� �ȵ�)
SingletonClass::SingletonClass() {
}

SingletonClass::~SingletonClass() {
}
*/

/*
 *  ������� ������ static ������� �ٽ����� �����Ѵ�.
 * �̴� static ����� �Ϲ� ����Լ�ó�� ������ �� �ֵ��� �Ѵ�(?)
 */
bool SingletonClass::instanceFlag = false;

// SingletonClass* SingletonClass::instance = NULL;
SingletonClass* SingletonClass::head = NULL;
// �̱��� �ν��Ͻ��� ��ȯ�� ����Լ�

/*
SingletonClass* SingletonClass::getInstance() {
	if (!instance) {
		instance = new SingletonClass();
		instanceFlag = true;
	}
	return instance;
}
*/

SingletonClass* SingletonClass::gethead() {
	if (!head) {
		head = new SingletonClass();
		FILE* Filetxt = NULL;
		char chBuffer[F_SIZE] = { "\0" };
		head->next = NULL;
		SingletonClass* Tail = NULL;
		Filetxt = fopen("Book.txt", "r");

		while (fgets(chBuffer, F_SIZE, Filetxt) != NULL)
		{
			SingletonClass* newNode = new SingletonClass();

			strcpy(newNode->chInformation, chBuffer);

			if (head->next == NULL)
			{
				head->next = newNode;
			}
			else
			{
				Tail->next = newNode;
			}
			newNode->next = NULL;
			Tail = newNode;
		}

		fclose(Filetxt);
		instanceFlag = true;
	}
	return head;
}