#include "main.h"
#include "BookClass.h"

void Book::GetName()
{
	cout << endl << "책의 이름(영문 100자 이내, 한글 30자 이내, 공백포함, 처음에 공백이 있으면 실행실패) : ";
}

void Book::GetWriter()
{
	cout << endl << "책의 작가(영문 100자 이내, 한글 30자 이내, 공백포함, 처음에 공백이 있으면 실행실패) : ";
}

void Book::GetYear()
{
	cout << endl << "출판 년도(0~9999까지의 숫자를 입력하여 주세요) : ";
}

void Book::GetInformation()
{
	cout << endl << "\t\t\t책의 정보(영문 100자 이내, 한글 30자 이내, 공백포함, 처음에 공백이 있으면 실행실패) : ";
}

void Book::HowInitialize()
{
	cout << "\t\t\t\t\t== 전체 도서 목록을 초기화 하시겠습니까?? ==" << endl << endl << "\t\t\t\t\t== 희망 하시는 경우 'y'를 입력 후 엔터를 눌러주세요 ==" << endl << endl;
}

