#include "main.h"
#include "BookClass.h"

void Book::GetName()
{
	cout << endl << "å�� �̸�(���� 100�� �̳�, �ѱ� 30�� �̳�, ��������, ó���� ������ ������ �������) : ";
}

void Book::GetWriter()
{
	cout << endl << "å�� �۰�(���� 100�� �̳�, �ѱ� 30�� �̳�, ��������, ó���� ������ ������ �������) : ";
}

void Book::GetYear()
{
	cout << endl << "���� �⵵(0~9999������ ���ڸ� �Է��Ͽ� �ּ���) : ";
}

void Book::GetInformation()
{
	cout << endl << "\t\t\tå�� ����(���� 100�� �̳�, �ѱ� 30�� �̳�, ��������, ó���� ������ ������ �������) : ";
}

void Book::HowInitialize()
{
	cout << "\t\t\t\t\t== ��ü ���� ����� �ʱ�ȭ �Ͻðڽ��ϱ�?? ==" << endl << endl << "\t\t\t\t\t== ��� �Ͻô� ��� 'y'�� �Է� �� ���͸� �����ּ��� ==" << endl << endl;
}

