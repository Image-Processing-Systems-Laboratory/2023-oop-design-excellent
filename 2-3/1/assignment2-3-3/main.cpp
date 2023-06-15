#include "str.h"
#include<iostream>
#include<string>

using namespace std;
int main() {
	string str1("Hello");
	string str2("Hi");

	oopstd::string strstr1("Hello");
	oopstd::string strstr2("Hi");

	/* "Hello"�� ���*/
	cout << "string        : str1, str2" << endl;
	cout << "oopstd::string: strstr1, strstr2" << endl << endl;
	cout << "==========c_str==========" << endl;
	cout << "str1   .c_str():   " << str1.c_str() << endl;
	cout << "strstr1.c_str():   " << strstr1.c_str() << endl << endl;
	
	/* "Hello"�� "Hello World"�� �ٲ� -> "Hello World"���*/
	cout << "==========assign==========" << endl;
	str1.assign("Hello World");		 strstr1.assign("Hello World");
	cout << "str1   .assign(\"Hello World\"):   " << str1 << endl;
	cout << "strstr1.assign(\"Hello World\"):   " << strstr1.c_str() << endl <<  endl;
	
	/* "Hello World"�� �ε�����ȣ2�� 'l'�� ���*/
	cout << "==========at==========" << endl;
	cout << "str1   .at(2):   " << str1.at(2) << endl;
	cout << "strstr1.at(2):   " << strstr1.at(2) << endl << endl;
	
	/* ���ڿ��� �ʱ�ȭ �������Ƿ� �ƹ��͵� ��µ��� ����*/
	cout << "==========clear==========" << endl;
	str1.clear();	strstr1.clear();
	cout << "str1   .clear():   " << str1 << endl;
	cout << "strstr1.clear():   " << strstr1.c_str() << endl << endl;
	
	/* "Hello World"�� �ʱ�ȭ��Ű�� '!' ����*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	cout << "==========push_back==========" << endl;
	str1.push_back('!'); strstr1.push_back('!');
	cout << "str1   .pus_back('!'):   " << str1 << endl;
	cout << "strstr1.pus_back('!'):   " << strstr1.c_str() << endl << endl;
	
	/* ���ڿ� �ƽ�Ű�ڵ� �� ��*/
	cout << "==========compare==========" << endl;
	str2.assign("Hello World!");	strstr2.assign("Hello World!");
	cout << "str1   .compare(str2)    #str2 =     Hello World!:   " << str1.compare(str2) << endl;
	cout << "strstr1.compare(strstr2) #str2str2 = Hello World!:   " << strstr1.compare(&strstr2) << endl << endl;
	
	str2.assign("Hello Hi!");	strstr2.assign("Hello Hi!");
	cout << "str1   .compare(str2)    #str2 =     Hello Hi!:   " << str1.compare(str2) << endl;
	cout << "strstr1.compare(strstr2) #str2str2 = Hello Hi!:   " << strstr1.compare(&strstr2) << endl << endl;

	str2.assign("Hello Zoo!");	strstr2.assign("Hello Zoo!");
	cout << "str1   .compare(str2)     #str2   =   Hello Zoo!:   " << str1.compare(str2) << endl;
	cout << "strstr1.compare(&strstr2) #str2str2 = Hello Zoo!:   " << strstr1.compare(&strstr2) << endl << endl;
	

	cout << "==========replace==========" << endl;
	/* string �ʱ�ȭ*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	str2.assign("Hi");	strstr2.assign("Hi");
	/* ���� �� ��ü*/
	str1.replace(5, 2, str2);	strstr1.replace(5, 2, &strstr2);
	cout << "str1   .replace(5, 2, str2)     #str2  =   Hi:   " << str1 << endl;
	cout << "strstr1.replace(5, 2, &strstr2) #strstr2 = Hi:   " << strstr1.c_str() << endl << endl;
	
	/* string �ʱ�ȭ*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	/* ���� �ʰ� ��ü*/
	str1.replace(5, 15, str2);	strstr1.replace(5, 15, &strstr2);
	cout << "str1   .replace(5, 15, str2)     #str2  =   Hi:   " << str1 << endl;
	cout << "strstr1.replace(5, 15, &strstr2) #strstr2 = Hi:   " << strstr1.c_str() << endl << endl;

	/* �������� ������ �ʰ��ϸ� ������ ��.*/
	
	cout << "==========substr==========" << endl;
	/* string �ʱ�ȭ*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	/* ���� �� ����*/
	string c = str1.substr(4, 3);	oopstd::string d = strstr1.substr(4, 3);
	cout << "str1   .substr(4, 3)   " << c << endl;
	cout << "strstr1.substr(4, 3)   " << d.c_str() << endl << endl;
	
	/* string �ʱ�ȭ*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	/* ���� �ʰ� ����*/
	string e = str1.substr(4, 11);	oopstd::string f = strstr1.substr(4, 11);
	cout << "str1   .substr(4, 11)   " << e << endl;
	cout << "strstr1.substr(4, 11)   " << f.c_str() << endl << endl;

	/* �������� ������ �ʰ��ϸ� ������ ��*/
	
	cout << "==========find==========" << endl;
	/* string �ʱ�ȭ*/
	str1.assign("Hello World");		strstr1.assign("Hello World");
	str2.assign("o");	strstr2.assign("o");

	/* pos�� ����Ʈ �� 0�� ��*/
	cout << "str1   .find(str2)    #str2  =   \"o\":   " << str1.find(str2) << endl;
	cout << "strstr1.find(strstr2) #strstr2 = \"o\":   " << strstr1.find(strstr2) << endl << endl;

	/* pos�� 5�� ����*/
	cout << "str1   .find(str2, 5)    #str2  =   \"o\":   " << str1.find(str2, 5) << endl;
	cout << "strstr1.find(strstr2, 5) #strstr2 = \"o\":   " << strstr1.find(strstr2, 5) << endl << endl;

	/* ���ڿ��� ���� ���� ã�� (string::npos ����)*/
	str2.assign("Zo");	strstr2.assign("Zo");
	cout << "str1   .find(str2)    #str2  =   \"Zo\":   " << str1.find(str2) << endl;
	cout << "strstr1.find(strstr2) #strstr2 = \"Zo\":   " << strstr1.find(strstr2) << endl << endl;


	cout << "==========stoi==========" << endl;
		/* string ����� �ʱ�ȭ*/
	str1.assign("\n\t+10bus");		strstr1.assign("\n\t+10bus");
	size_t sz;
	int num = stoi(str1, &sz);
	cout << "stoi(str1, &sz)    #str1  =   \"\\n\\t+10bus\" ->   " << "num: " << num << "   sz: " << sz << endl;
	num = oopstd::stoi(strstr1, &sz);
	cout << "stoi(strstr1, &sz) #strstr1 = \"\\n\\t+10bus\" ->   " << "num: " << num << "   sz: " << sz << endl << endl;

	/* string ������ �ʱ�ȭ*/
	str1.assign("\n\t -33bus");		strstr1.assign("\n\t -33bus");
	num = stoi(str1, &sz);
	cout << "stoi(str1, &sz)    #str1  =   \"\\n\\t -33bus\" ->   " << "num: " << num << "   sz: " << sz << endl;
	num = oopstd::stoi(strstr1, &sz);
	cout << "stoi(strstr1, &sz) #strstr1 = \"\\n\\t -33bus\" ->   " << "num: " << num << "   sz: " << sz << endl << endl;
	
	
	cout << "==========stof==========" << endl;
	/* string ����� �ʱ�ȭ*/
	str1.assign("\n\t+10.1284abc");		strstr1.assign("\n\t+10.1284abc");
	float num1 = stof(str1, &sz);
	cout << "stoi(str1, &sz)    #str1  =   \"\\n\\t+10.1284abc\" ->   " << "num: " << num << "   sz: " << sz << endl;
	num1 = oopstd::stof(strstr1, &sz);
	cout << "stoi(strstr1, &sz) #strstr1 = \"\\n\\t+10.1284abc\" ->   " << "num: " << num << "   sz: " << sz << endl << endl;

	/* string ������ �ʱ�ȭ*/
	str1.assign("\n\t -23.4433abc");		strstr1.assign("\n\t -23.4433abc");
	num1 = stof(str1, &sz);
	cout << "stof(str1, &sz)    #str1  =   \"\\n\\t -23.4433abc\" ->   " << "num: " << num1 << "   sz: " << sz << endl;
	num1 = oopstd::stof(strstr1, &sz);
	cout << "stof(strstr1, &sz) #strstr1 = \"\\n\\t -23.4433abc\" ->   " << "num: " << num1 << "   sz: " << sz << endl << endl;


	cout << "==========to_string==========" << endl;
	/* ���� -> string*/
	cout << "to_string(1423)         : " << to_string(1423) << endl;
	cout << "oopstd::to_string(1423) : " << oopstd::to_string(1423).c_str() << endl << endl;
	/* �Ǽ� -> string*/
	cout << "to_string(51.123123123)         : " << to_string((float)51.123123123) << endl;
	cout << "oopstd::to_string(51.123123123) : " << oopstd::to_string((float)51.123123123).c_str() << endl;
	

	return 0;
}