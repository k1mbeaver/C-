#include "SingleTon.h"
#include "FileClass.h"

/*
 * 이클립스에 의해 자동 생성된 생성자와 소멸자의 템플릿
 * - 생성자: 헤더파일에서 private 생성자로 선언 및 구현함
 * - 소멸자: 헤더파일에서 public 소멸자로 선언 및 구현함
 * 즉, 소스코드에서는 구현하지 않음(해서는 안됨)
SingletonClass::SingletonClass() {
}

SingletonClass::~SingletonClass() {
}
*/

/*
 *  헤더에서 선언한 static 멤버들을 다시한전 선언한다.
 * 이는 static 멤버를 일반 멤버함수처럼 참조할 수 있도록 한다(?)
 */
bool SingletonClass::instanceFlag = false;

// SingletonClass* SingletonClass::instance = NULL;
SingletonClass* SingletonClass::head = NULL;
// 싱글턴 인스턴스를 반환할 멤버함수

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