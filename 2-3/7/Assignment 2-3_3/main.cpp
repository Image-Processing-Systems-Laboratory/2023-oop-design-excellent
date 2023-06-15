#include "class.h"

int main()
{
	oopstd::string a, b, c, d;

	/*assign*/
	a.assign("Hi");
	b.assign("Hello world");
	c.assign("10bus");
	d.assign("1.5abc");

	/*c_str*/
	cout << "/* assign & c_str */" << endl; 
	cout<< a.c_str() << endl; // Hi
	cout << endl;

	/*at*/
	cout << "/* at */" << endl;
	cout << a.at(1) << endl; // i
	cout << endl;

	/*push_back*/
	a.push_back('!'); 
	cout << "/* push_back */" << endl;
	cout << a.c_str() << endl; // Hi!
	cout << endl;

	/*replace*/
	string ex = "Hello world";
	ex.replace(0, 5, "Hi");
	cout << "/* replace */" << endl;
	cout << ex << endl; //Hi world
	cout << endl;

	/*find*/
	cout << "/* find */" << endl;
	cout << b.find("world", 0) << endl; //6
	cout << endl;

	/*stoi*/
	cout << "/* stoi */" << endl;
	size_t sz;
	int inum = stoi(c, &sz, 10);
	cout << inum << endl; //10
	cout << sz << endl; //2
	cout << endl;

	/*stof*/
	cout << "/* stof */" << endl;
	float fnum = stof(d, &sz);
	cout << fnum << endl; //1.5
	cout << sz << endl; //3
	cout << endl;

	/*to_string*/
	cout << "/* to_string */" << endl;
	int num = 12345;
	oopstd::string nstr = oopstd::to_string(num);
	cout << nstr.c_str() << endl; //12345

	float num2 = 12.345;
	oopstd::string fstr = oopstd::to_string(num2);
	cout << fstr.c_str() << endl; //12.345
	return 0;
}