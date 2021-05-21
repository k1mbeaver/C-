#pragma once
#include "BookSystem.h"

class SingletonClass {

private:

	/**
	 * ������
	 * �ܺο��� �ν��Ͻ��� ������ �� ������ private ������ �����ϰ� ������
	 * ����: private ������ �����ڰ� �����ϹǷ� �ܺο��� SingletonClass()�� ȣ���� �� ����
	 */
	SingletonClass() {};

	// �̱��� �ν��Ͻ��� �����Ǿ����� ����
	static bool instanceFlag;

	// �̱��� �ν��Ͻ�
	static SingletonClass* instance;
	static SingletonClass* head;

public:
	// �̱��� �ν��Ͻ��� ��ȯ�� ����Լ�
	//static SingletonClass* getInstance();

	static SingletonClass* gethead();
	static SingletonClass* printhead();

	// �Ҹ���, instanceFlag�� false�� ����
	virtual ~SingletonClass() {
		instanceFlag = false;
	};

	int nButton = 0;
	SingletonClass* next = nullptr;
	char chInformation[F_SIZE] = { "\0" };
};