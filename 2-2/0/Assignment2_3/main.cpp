#include"CSVLoader.h"



int main(void)
{
	CSVLoader l("CSVLoader_Data.txt"); // 해당 파일명을 매개변수로 하는 
	l.print(); // 객체의 print 메서드 호출
	return 0;
}