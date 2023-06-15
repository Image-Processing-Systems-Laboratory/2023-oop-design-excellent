// 01반_02반_2022202078_조영훈 2-2주차 3번.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "CSVLoader.h"

int main()
{
	CSVLoader CSVLoader("CSVLoader_Data.txt");
	cout << "Rows: ";
	cout << CSVLoader.getRows() << endl;
	cout << "Cols: ";
	cout << CSVLoader.getCols()<<endl;
	cout << "Second Data: ";
	cout << CSVLoader.getData()[0][1]<<endl;
	cout << "print all data: " << endl;
	CSVLoader.print();

}
