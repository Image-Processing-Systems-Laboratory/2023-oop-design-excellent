#define _CRT_SECURE_NO_WARNINGS
#include "CSVLoader.h"

using namespace std;

int main() {
	CSVLoader a("CSVLoader_Data.txt");

	cout << "Rows : "<<a.getRows() << endl;
	cout << "Cols : " << a.getCols() << endl;
	cout << "Data(row 10, col 2) : ";
	cout << a.getData()[9][1] << endl;
	cout << "All Data : " << endl;
	a.print();
}