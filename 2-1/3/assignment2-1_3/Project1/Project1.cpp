#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"oopstd.h"

int main(void) {
	char stdmset_arr[30] = "abcdefghijklmnop";				//std::memset 실행용 배열
	char oopmset_arr[30] = "abcdefghijklmnop";				//oopstd::memset 실행용 배열
	std::memset(stdmset_arr, '-' , 10);						//std::memset 실행
	oopstd::memset(oopmset_arr, '-', 10);					//oopstd::memset 실행
	std::cout << "memset(std) : " << stdmset_arr << std::endl;			//결과 출력
	std::cout << "memset(oopstd) : " << oopmset_arr << std::endl;		//결과 출력

	char stdmcpy_dest[30] = "abcdefghijklmnop";				//std::memcpy 실행용 배열1
	char stdmcpy_sour[30] = "hahahahaha";					//std::memcpy 실행용 배열2
	std::memcpy(stdmcpy_dest, stdmcpy_sour, 6);				//std::memcpy 실행
	char oopmcpy_dest[30] = "abcdefghijklmnop";				//oopstd::memcpy 실행용 배열1
	char oopmcpy_sour[30] = "hahahahaha";					//oopstd::memcpy 실행용 배열2
	oopstd::memcpy(oopmcpy_dest, oopmcpy_sour, 6);			//oopstd::memcpy 실행
	std::cout << "memcpy(std) : " << stdmcpy_dest << std::endl;			//결과 출력
	std::cout << "memcpy(oopstd) : " << oopmcpy_dest << std::endl;		//결과 출력

	char stdcmp_arr1[30] = "hello";							//std::strcmp 실행용 배열1
	char stdcmp_arr2[30] = "hello";							//std::strcmp 실행용 배열2
	std::cout << "strcmp(std) : " << std::strcmp(stdcmp_arr1, stdcmp_arr2) << std::endl;		//결과 출력
	char oopcmp_arr1[30] = "hello";							//oopstd::strcmp 실행용 배열1
	char oopcmp_arr2[30] = "hello";							//oopstd::strcmp 실행용 배열2
	std::cout << "strcmp(oopstd) : " << oopstd::strcmp(oopcmp_arr1, oopcmp_arr2) << std::endl;	//결과 출력

	char stdncmp_arr1[30] = "abcdefghijklmnop";				//std::strncmp 실행용 배열1
	char stdncmp_arr2[30] = "hahahahaha";					//std::strncmp 실행용 배열2
	std::cout << "strncmp(std) : " << std::strncmp(stdncmp_arr1, stdncmp_arr2, 6) << std::endl;			//결과 출력
	char oopncmp_arr1[30] = "abcdefghijklmnop";				//oopstd::strncmp 실행용 배열1
	char oopncmp_arr2[30] = "hahahahaha";					//oopstd::strncmp 실행용 배열2
	std::cout << "strncmp(oopstd) : " << oopstd::strncmp(oopncmp_arr1, oopncmp_arr2, 6) << std::endl;	//결과 출력
	char stdncmp_arr3[30] = "abcdefghijklmnop";				//std::strncmp 실행용 배열1
	char stdncmp_arr4[30] = "abcdefghhahahahaha";			//std::strncmp 실행용 배열2
	std::cout << "strncmp(std) : " << std::strncmp(stdncmp_arr3, stdncmp_arr4, 6) << std::endl;		//결과 출력
	char oopncmp_arr3[30] = "abcdefghijklmnop";				//oopstd::strncmp 실행용 배열1
	char oopncmp_arr4[30] = "abcdefghhahahahaha";			//oopstd::strncmp 실행용 배열2
	std::cout << "strncmp(oopstd) : " << std::strncmp(oopncmp_arr3, oopncmp_arr4, 6) << std::endl;	//결과 출력

	char stdscpy_dest[30] = "abcdefghijklmnop";				//std::strcpy 실행용 배열1
	char stdscpy_sour[30] = "hahahahaha";					//std::strcpy 실행용 배열2
	std::strcpy(stdscpy_dest, stdscpy_sour);				//std::strcpy 실행
	std::cout << "strcpy(std) : " << stdscpy_dest << std::endl;				//결과 출력
	char oopscpy_dest[30] = "abcdefghijklmnop";				//oopstd::strcpy 실행용 배열1
	char oopscpy_sour[30] = "hahahahaha";					//oopstd::strcpy 실행용 배열2
	oopstd::strcpy(oopscpy_dest, oopscpy_sour);				//oopstd::strcpy 실행
	std::cout << "strcpy(oopstd) : " << oopscpy_dest << std::endl;			//결과 출력

	char stdsncpy_dest[30] = "abcdefghijklmnop";			//std::strncpy 실행용 배열1
	char stdsncpy_sour[30] = "hahahahaha";					//std::strncpy 실행용 배열2
	std::strncpy(stdsncpy_dest, stdsncpy_sour, 6);			//std::strncpy 실행
	char oopsncpy_dest[30] = "abcdefghijklmnop";			//oopstd::strncpy 실행용 배열1
	char oopsncpy_sour[30] = "hahahahaha";					//oopstd::strncpy 실행용 배열1
	oopstd::strncpy(oopsncpy_dest, oopsncpy_sour, 6);		//oopstd::strncpy 실행
	std::cout << "strncpy(std) : " << stdsncpy_dest << std::endl;		//결과 출력
	std::cout << "strncpy(oopstd) : " << oopsncpy_dest << std::endl;	//결과 출력

	char stdlen_arr[30] = "hahahahahoho";			//std::strlen 실행용 배열
	std::cout << "strlen(std) : " << std::strlen(stdlen_arr) << std::endl;			//결과 출력
	char ooplen_arr[30] = "hahahahahoho";			//oopstd::strlen 실행용 배열
	std::cout << "strlen(oopstd) : " << oopstd::strlen(ooplen_arr) << std::endl;	//결과 출력

	char stdatoi_arr[30] = "1234";					//std::atoi 실행용 배열
	int stdatoi_num = atoi(stdatoi_arr);			//std::atoi 실행
	printf("atoi(std) : %d\n", stdatoi_num);			//결과 출력
	char oopatoi_arr[30] = "1234";					//oopstd::atoi 실행용 배열
	int oopatoi_num = atoi(oopatoi_arr);			//oopstd::atoi 실행
	printf("atoi(oopstd) : %d\n", oopatoi_num);			//결과 출력

	char stdatof_arr[30] = "3.141592";				//std::atof 실행용 배열
	float stdatof_num = atof(stdatof_arr);			//std::atof 실행
	printf("atof(std) : %.6f\n", stdatof_num);		//결과 출력
	char oopatof_arr[30] = "3.141592";				//oopstd::atof 실행용 배열
	float oopatof_num = atof(oopatof_arr);			//oopstd::atof 실행
	printf("atof(oopstd) : %.6f\n", oopatof_num);	//결과 출력

	return 0;
}