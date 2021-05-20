#include "main.h"
#include "BookClass.h"

void Book::error()
{
	cout << endl << "\t\t\t\t\t== 다시 시도하여주세요 ==" << endl;
	system("pause");
}

void Book::NoBook()
{
	cout << endl << "\t\t\t\t\t == 도서가 없습니다. 메인 화면으로 돌아갑니다. == " << endl;
	system("pause");
}

void Book::CompleteDelete()
{
	cout << endl << "\t\t\t\t\t== 도서 삭제가 완료되었습니다!! ==" << endl;
	system("pause");
}

void Book::CompleteInsert()
{
	cout << endl << "\t\t\t\t\t== 도서 추가가 완료되었습니다!! ==" << endl;
	system("pause");
}

void Book::InitializeComplete()
{
	cout << "\t\t\t\t\t== 초기화가 완료 되었습니다!! ==" << endl;
	system("pause");
}