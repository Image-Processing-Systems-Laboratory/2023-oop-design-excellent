#define _CRT_SECURE_NO_WARNINGS // for strcpy
#include <iostream>
#include "oopstd.h"
#include <string.h>

using namespace std;
using namespace oopstd;

struct {
	char name[40];
	int age;
}person, person_copy, person_copy2;

int main(void) {
	//memset check
	char str1[] = "OoP assignment 2-1-3 (oopstd.h)";
	char str2[] = "OoP assignment 2-1-3 (string.h)";
	my_memset(str1, '-', 4);
	memset(str2, '-', 4);
	cout << "memset check" << endl;
	cout << str1 << endl << str2;

	//memcpy check
	cout << endl << endl << "memcpy check" << endl;
	char myname[] = "Park Hyun-woong";

	my_memcpy(person.name, myname, strlen(myname) + 1);
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 21;

	my_memcpy(&person_copy, &person, sizeof(person));
	memcpy(&person_copy2, &person, sizeof(person));

	cout << "person_copy : " << person_copy.name << "," << person_copy.age << "(oopstd.h)" << endl;
	cout << "person_copy : " << person_copy2.name << "," << person_copy2.age << "(string.h)" << endl;

	//strcmp check
	cout << endl << endl << "strcmp check" << endl;
	char key[] = "apple";
	char buffer1[80], buffer2[80];
	do {
		cout << "Guess my favorite fruit? ";
		cin >> buffer1;
	} while (my_strcmp(key, buffer1) != 0);
	cout << "correct answer (oopstd.h)" << endl << endl;
	do {
		cout << "Guess my favorite fruit? ";
		cin >> buffer2;
	} while (strcmp(key, buffer2) != 0);
	cout << "correct answer (string.h)" << endl;

	//strncmp check
	cout << endl << endl << "strncmp check" << endl;

	char str[][5] = { "R2D2", "C3PO", "R2A6" };
	int n;
	cout << "Looking for R2 astromech droids... (oopstd.h)" << endl;
	for (n = 0; n < 3; n++)
		if (my_strncmp(str[n], "R2xx", 2) == 0)
			cout << "found " << str[n] << endl;
	cout << "Looking for R2 astromech droids... (string.h)" << endl;
	for (n = 0; n < 3; n++)
		if (strncmp(str[n], "R2xx", 2) == 0)
			cout << "found " << str[n] << endl;

	//strcpy check
	cout << endl << endl << "strcpy check" << endl;
	char str3[] = "OoP assignment 2-1-3";
	char str4[40], str5[40], str6[40], str7[40];
	my_strcpy(str4, str3);
	my_strcpy(str5, "copy successful");
	strcpy(str6, str3);
	strcpy(str7, "copy successful");
	cout << "(oopstd.h) \nstr3 : " << str3 << endl << "str4 : " << str4 << endl << "str5 : " << str5 << endl;
	cout << "(string.h) \nstr3 : " << str3 << endl << "str6 : " << str6 << endl << "str7 : " << str7 << endl;

	//strncpy check
	cout << endl << endl << "strncpy check" << endl;
	char str8[] = "OoP assignment 2-1-3";
	char str9[40], str10[40], str11[40], str12[40];
	my_strncpy(str9, str8, sizeof(str9));
	strncpy(str10, str8, 3);
	str10[3] = '\0';
	cout << "(oopstd.h)" << endl << str8 << endl << str9 << endl << str10 << endl;
	my_strncpy(str11, str8, sizeof(str9));
	strncpy(str12, str8, 3);
	str12[3] = '\0';
	cout << "(string.h)" << endl << str8 << endl << str11 << endl << str12 << endl;

	//strlen check
	cout << endl << endl << "strlen check" << endl;
	char szinput[256];
	cout << "enter a sentence :";
	cin >> szinput;
	cout << "size (oopstd.h) : " << my_strlen(szinput) << endl;
	cout << "size (string.h) : " << strlen(szinput) << endl;

	//atoi check
	cout << endl << endl << "atoi check" << endl;
	int i1, i2;
	char buffer[256];
	cout << "Enter a number :";
	cin >> buffer;
	i1 = my_atoi(buffer);
	i2 = atoi(buffer);
	cout << "the value entered is " << i1 << "it's double is " << 2 * i1 << "(oopstd.h)" << endl;
	cout << "the value entered is " << i2 << "it's double is " << 2 * i2 << "(string.h)" << endl;
	
	//atof check
	cout << endl << endl << "atof check" << endl;
	double n1, n2;
	char buffer0[256];
	cout << "Enter a number :";
	cin >> buffer0;
	n1 = my_atof(buffer0);
	n2 = atof(buffer0);
	cout << "the value entered is " << n1 << "(oopstd.h)" << endl;
	cout << "the value entered is " << n2 << "(string.h)" << endl;

	return 0;
}