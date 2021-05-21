#include "SingleTon.h"
#include "FileClass.h"
#include "BookSystem.h"

using namespace std;

int main() {
	cout << "SingleTonTest" << endl; // prints SingleTonTest

	BookSystem* test = new BookSystem();

	test->Process();

	cout << endl; system("pause"); return 0;
}