#include <iostream>
#include "iStack.h"
using namespace std;
int main()
{
	iStack is;
	for (int n = 0; n < 100; n++)
		is + rand() % 10; 
	is.print();
	cout << is.search(5) << endl;
	cout << is.search(20) << endl;
	
	iStack* pis = new iStack;
	for (int n = 0; n < 100; n++)
		*pis + rand() % 10; 
	pis->print();
	cout << pis->search(5) << endl;
	cout << pis->search(20) << endl;
	delete pis;
	return 0;
}