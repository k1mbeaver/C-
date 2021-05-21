#pragma once
#include "BookSystem.h"

class SingletonClass {

private:

	/**
	 * 생성자
	 * 외부에서 인스턴스를 생성할 수 없도록 private 영역에 정의하고 구현함
	 * 원리: private 영역에 생성자가 존재하므로 외부에서 SingletonClass()를 호출할 수 없음
	 */
	SingletonClass() {};

	// 싱글턴 인스턴스가 생성되었는지 여부
	static bool instanceFlag;

	// 싱글턴 인스턴스
	static SingletonClass* instance;
	static SingletonClass* head;

public:
	// 싱글턴 인스턴스를 반환할 멤버함수
	//static SingletonClass* getInstance();

	static SingletonClass* gethead();
	static SingletonClass* printhead();

	// 소멸자, instanceFlag를 false로 변경
	virtual ~SingletonClass() {
		instanceFlag = false;
	};

	int nButton = 0;
	SingletonClass* next = nullptr;
	char chInformation[F_SIZE] = { "\0" };
};