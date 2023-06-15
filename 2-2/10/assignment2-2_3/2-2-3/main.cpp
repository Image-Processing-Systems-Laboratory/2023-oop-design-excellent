#include "CSVLoader.hpp"
#include <iostream>

int main(void)
{
	CSVLoader csvl("CSVLoader_Data.txt"); // csv 파일을 열어 파싱함

	csvl.print(); // 파싱 결과를 출력
	// 파일의 행과 열을 출력
	std::cout << csvl.getRows() << ' ' << csvl.getCols() << std::endl;
	return (0);
}