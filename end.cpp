#include "main.h"
#include "BookClass.h"

void Book::error()
{
	cout << endl << "\t\t\t\t\t== �ٽ� �õ��Ͽ��ּ��� ==" << endl;
	system("pause");
}

void Book::NoBook()
{
	cout << endl << "\t\t\t\t\t == ������ �����ϴ�. ���� ȭ������ ���ư��ϴ�. == " << endl;
	system("pause");
}

void Book::CompleteDelete()
{
	cout << endl << "\t\t\t\t\t== ���� ������ �Ϸ�Ǿ����ϴ�!! ==" << endl;
	system("pause");
}

void Book::CompleteInsert()
{
	cout << endl << "\t\t\t\t\t== ���� �߰��� �Ϸ�Ǿ����ϴ�!! ==" << endl;
	system("pause");
}

void Book::InitializeComplete()
{
	cout << "\t\t\t\t\t== �ʱ�ȭ�� �Ϸ� �Ǿ����ϴ�!! ==" << endl;
	system("pause");
}