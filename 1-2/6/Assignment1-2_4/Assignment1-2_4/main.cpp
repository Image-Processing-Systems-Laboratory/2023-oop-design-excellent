#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

#define ORIGINAL_SIZE 512 // 512 x 512 파일을 다루므로

typedef uint8_t BYTE; // 바이너리 파일 1바이트씩 다루기 위함

struct Point // x와 y 좌표를 저장
{
	int x;
	int y;
};

void	error_exit(const char *err_str) // 에러 발생시 에러 사유 출력 후 종료
{
	std::cerr << "Error!" << std::endl;
	std::cerr << err_str << std::endl;
	exit(EXIT_FAILURE);
}

Point coo_read(void) // 좌표 입력
{
	Point ret_p;

	std::cin >> ret_p.x; // x좌표 입력
	while(',' == std::cin.get()); // ,(반점) 처리
	std::cin >> ret_p.y; // y좌표 입력
	if (!std::cin) // 입력 에러 발생 시
		error_exit("coordinate read error");
	return (ret_p); // 좌표 반환
}

BYTE** buf_init(void) // 버퍼 초기화
{
	BYTE** ret_m = NULL;

	try
	{
		// 2차원 배열을 for문을 사용하여 초기화
		ret_m = new BYTE * [ORIGINAL_SIZE];
		for (int i = 0; i < ORIGINAL_SIZE; i++)
		{
			ret_m[i] = new BYTE[ORIGINAL_SIZE];
		}
	}
	catch (std::exception& e) // new는 실패 시 예외 발생하므로 catch로 처리함
	{
		//만약 이미 할당된 메모리가 존재해도
		//exit로 프로세스가 끝나며 할당된 메모리는 모두 free됨
		error_exit("memory allocate error");
	}
	return (ret_m);
}

void swap(int& a, int& b) // a와 b의 값을 변경
{
	int t;

	t = a;
	a = b;
	b = t;
}

void read_picture(char* filename, BYTE** buf) // 사진 read
{
	std::ifstream ifs; // 입력 스트림

	ifs.open(filename, std::ios::binary | std::ios::in); // 바이너리 읽기로 파일을 엶
	if (!ifs.is_open()) // 파일 열기 실패시
		error_exit("file open error");
	for (int i = 0; i < ORIGINAL_SIZE; i++) // 한 줄씩 읽으며 반복
	{
		ifs.read((char*)buf[i], ORIGINAL_SIZE); // 한 줄만큼 파일을 read
	}
	ifs.close(); // 파일 닫음
}

void crop_output(char* filename, BYTE** buf, Point& p1, Point& p2) // 자른 파일 만들기
{
	char outfile_name[100];
	char temp[5];

	// 파일 이름 제작
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_cropped_");
	sprintf(temp, "%d", p2.x - p1.x); // 가로 길이를 문자열로 변환
	strcat(outfile_name, temp);
	strcat(outfile_name, "x");
	sprintf(temp, "%d", p2.y - p1.y); // 세로 길이를 문자열로 변환
	strcat(outfile_name, temp);
	strcat(outfile_name, ".raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // 출력 파일 열기
	if (!ofs.is_open()) // 파일 열기 에러
		error_exit("file open error");
	for (int i = p1.y; i < p2.y; i++) // 지정된 범위 안에서 순회하며 출력
	{
		ofs.write((char *) & buf[i][p1.x], p2.x - p1.x);
	}
	ofs.close(); // 파일 닫기
}

void horizon_output(char* filename, BYTE** buf) // 좌우 회전 출력
{
	char outfile_name[100];
	 // 파일 이름 제작
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_horizontalflip.raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // 출력 파일 열기
	if (!ofs.is_open()) // 파일 열기 에러
		error_exit("file open error");
	for (int i = 0; i < ORIGINAL_SIZE; i++) // 파일을 위부터 한줄씩 출력
	{
		for (int j = ORIGINAL_SIZE - 1; j >= 0; j--) // 한 줄을 역순으로 출력
			ofs.write((char*)&buf[i][j], 1);	
	}
	ofs.close(); // 파일 닫기
}

void vertical_output(char* filename, BYTE** buf) // 상하 회전 출력
{
	char outfile_name[100];
	// 파일 이름 제작
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_verticalflip.raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // 출력 파일 열기
	if (!ofs.is_open()) // 파일 열기 에러
		error_exit("file open error");
	for (int i = ORIGINAL_SIZE - 1; i >= 0; i--) // 파일을 맨 아랫줄부터 출력
	{
		ofs.write((char*)&buf[i][0], ORIGINAL_SIZE); // 한 줄씩 출력
	}
	ofs.close(); // 출력파일 닫기
}

int main(void)
{
	BYTE** buf; // 그림을 저장할 버퍼
	char filename[100]; // 입력파일 이름
	char original_name[100]; // 입력파일 이름에서 확장자 제거
	Point p1, p2; // 그림을 잘라낼 두 좌표

	std::cout << "Input file name : "; // 파일 이름 입력
	std::cin >> filename;
	if (!std::cin) // 입력 에러 처리
		error_exit("standard input error");
	std::cout << "1st coordinate : "; // 첫 번째 좌표 입력
	p1 = coo_read();
	std::cout << "2nd coordinate : "; // 두 번째 좌표 입력
	p2 = coo_read();
	// p1이 좌상단에 갈 수 있도록 좌표를 조정
	if (p1.x > p2.x)
		swap(p1.x, p2.x);
	if (p1.y > p2.y)
		swap(p1.y, p2.y);
	// 입력 파일 이름에서 확장자 제거
	strcpy(original_name, filename);
	original_name[strlen(original_name) - 4] = 0;
	buf = buf_init(); // 버퍼 할당
	read_picture(filename, buf); //파일 읽기
	crop_output(original_name, buf, p1, p2); // 자른 사진 출력
	horizon_output(original_name, buf); // 좌우반전 사진 출력
	vertical_output(original_name, buf); // 상하반전 사진 출력
	std::cout << "Output images are stored!" << std::endl;
	// 버퍼 할당 해제
	for (int i = 0; i < ORIGINAL_SIZE; i++)
		delete[] buf[i];
	delete[] buf;
	return (0);
}