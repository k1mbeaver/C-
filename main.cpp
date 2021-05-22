#include "SingleTon.h"
#include "FileClass.h"
#include "BookSystem.h"
using namespace std;

int main() {
	BookSystem* Book = new BookSystem;

	Book->Process();

	delete Book;

	cout << endl;
	return 0;
}