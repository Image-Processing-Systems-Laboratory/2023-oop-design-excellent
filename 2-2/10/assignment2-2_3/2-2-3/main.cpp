#include "CSVLoader.hpp"
#include <iostream>

int main(void)
{
	CSVLoader csvl("CSVLoader_Data.txt"); // csv ������ ���� �Ľ���

	csvl.print(); // �Ľ� ����� ���
	// ������ ��� ���� ���
	std::cout << csvl.getRows() << ' ' << csvl.getCols() << std::endl;
	return (0);
}