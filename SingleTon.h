#pragma once
#include "BookSystem.h"

class SingletonClass {

private:

	/**
	 * ������
	 * �ܺο��� �ν��Ͻ��� ������ �� ������ private ������ �����ϰ� ������
	 * ����: private ������ �����ڰ� �����ϹǷ� �ܺο��� SingletonClass()�� ȣ���� �� ����
	 */


	// �̱��� �ν��Ͻ��� �����Ǿ����� ����
	static bool instanceFlag;

	// �̱��� �ν��Ͻ�
	//static SingletonClass* instance;

public:
	SingletonClass() {};
	static SingletonClass* head;
	// �̱��� �ν��Ͻ��� ��ȯ�� ����Լ�
	//static SingletonClass* getInstance();

	static SingletonClass* gethead();

	// �Ҹ���, instanceFlag�� false�� ����
	virtual ~SingletonClass() {
		instanceFlag = false;
	};

	int nButton = 0;
	SingletonClass* next = nullptr;
	char chInformation[F_SIZE] = { "\0" };
};