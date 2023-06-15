#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>

#define ORIGINAL_SIZE 512 // 512 x 512 ������ �ٷ�Ƿ�

typedef uint8_t BYTE; // ���̳ʸ� ���� 1����Ʈ�� �ٷ�� ����

struct Point // x�� y ��ǥ�� ����
{
	int x;
	int y;
};

void	error_exit(const char *err_str) // ���� �߻��� ���� ���� ��� �� ����
{
	std::cerr << "Error!" << std::endl;
	std::cerr << err_str << std::endl;
	exit(EXIT_FAILURE);
}

Point coo_read(void) // ��ǥ �Է�
{
	Point ret_p;

	std::cin >> ret_p.x; // x��ǥ �Է�
	while(',' == std::cin.get()); // ,(����) ó��
	std::cin >> ret_p.y; // y��ǥ �Է�
	if (!std::cin) // �Է� ���� �߻� ��
		error_exit("coordinate read error");
	return (ret_p); // ��ǥ ��ȯ
}

BYTE** buf_init(void) // ���� �ʱ�ȭ
{
	BYTE** ret_m = NULL;

	try
	{
		// 2���� �迭�� for���� ����Ͽ� �ʱ�ȭ
		ret_m = new BYTE * [ORIGINAL_SIZE];
		for (int i = 0; i < ORIGINAL_SIZE; i++)
		{
			ret_m[i] = new BYTE[ORIGINAL_SIZE];
		}
	}
	catch (std::exception& e) // new�� ���� �� ���� �߻��ϹǷ� catch�� ó����
	{
		//���� �̹� �Ҵ�� �޸𸮰� �����ص�
		//exit�� ���μ����� ������ �Ҵ�� �޸𸮴� ��� free��
		error_exit("memory allocate error");
	}
	return (ret_m);
}

void swap(int& a, int& b) // a�� b�� ���� ����
{
	int t;

	t = a;
	a = b;
	b = t;
}

void read_picture(char* filename, BYTE** buf) // ���� read
{
	std::ifstream ifs; // �Է� ��Ʈ��

	ifs.open(filename, std::ios::binary | std::ios::in); // ���̳ʸ� �б�� ������ ��
	if (!ifs.is_open()) // ���� ���� ���н�
		error_exit("file open error");
	for (int i = 0; i < ORIGINAL_SIZE; i++) // �� �پ� ������ �ݺ�
	{
		ifs.read((char*)buf[i], ORIGINAL_SIZE); // �� �ٸ�ŭ ������ read
	}
	ifs.close(); // ���� ����
}

void crop_output(char* filename, BYTE** buf, Point& p1, Point& p2) // �ڸ� ���� �����
{
	char outfile_name[100];
	char temp[5];

	// ���� �̸� ����
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_cropped_");
	sprintf(temp, "%d", p2.x - p1.x); // ���� ���̸� ���ڿ��� ��ȯ
	strcat(outfile_name, temp);
	strcat(outfile_name, "x");
	sprintf(temp, "%d", p2.y - p1.y); // ���� ���̸� ���ڿ��� ��ȯ
	strcat(outfile_name, temp);
	strcat(outfile_name, ".raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // ��� ���� ����
	if (!ofs.is_open()) // ���� ���� ����
		error_exit("file open error");
	for (int i = p1.y; i < p2.y; i++) // ������ ���� �ȿ��� ��ȸ�ϸ� ���
	{
		ofs.write((char *) & buf[i][p1.x], p2.x - p1.x);
	}
	ofs.close(); // ���� �ݱ�
}

void horizon_output(char* filename, BYTE** buf) // �¿� ȸ�� ���
{
	char outfile_name[100];
	 // ���� �̸� ����
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_horizontalflip.raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // ��� ���� ����
	if (!ofs.is_open()) // ���� ���� ����
		error_exit("file open error");
	for (int i = 0; i < ORIGINAL_SIZE; i++) // ������ ������ ���پ� ���
	{
		for (int j = ORIGINAL_SIZE - 1; j >= 0; j--) // �� ���� �������� ���
			ofs.write((char*)&buf[i][j], 1);	
	}
	ofs.close(); // ���� �ݱ�
}

void vertical_output(char* filename, BYTE** buf) // ���� ȸ�� ���
{
	char outfile_name[100];
	// ���� �̸� ����
	strcpy(outfile_name, filename);
	strcat(outfile_name, "_verticalflip.raw");

	std::ofstream ofs;

	ofs.open(outfile_name, std::ios::out | std::ios::binary); // ��� ���� ����
	if (!ofs.is_open()) // ���� ���� ����
		error_exit("file open error");
	for (int i = ORIGINAL_SIZE - 1; i >= 0; i--) // ������ �� �Ʒ��ٺ��� ���
	{
		ofs.write((char*)&buf[i][0], ORIGINAL_SIZE); // �� �پ� ���
	}
	ofs.close(); // ������� �ݱ�
}

int main(void)
{
	BYTE** buf; // �׸��� ������ ����
	char filename[100]; // �Է����� �̸�
	char original_name[100]; // �Է����� �̸����� Ȯ���� ����
	Point p1, p2; // �׸��� �߶� �� ��ǥ

	std::cout << "Input file name : "; // ���� �̸� �Է�
	std::cin >> filename;
	if (!std::cin) // �Է� ���� ó��
		error_exit("standard input error");
	std::cout << "1st coordinate : "; // ù ��° ��ǥ �Է�
	p1 = coo_read();
	std::cout << "2nd coordinate : "; // �� ��° ��ǥ �Է�
	p2 = coo_read();
	// p1�� �»�ܿ� �� �� �ֵ��� ��ǥ�� ����
	if (p1.x > p2.x)
		swap(p1.x, p2.x);
	if (p1.y > p2.y)
		swap(p1.y, p2.y);
	// �Է� ���� �̸����� Ȯ���� ����
	strcpy(original_name, filename);
	original_name[strlen(original_name) - 4] = 0;
	buf = buf_init(); // ���� �Ҵ�
	read_picture(filename, buf); //���� �б�
	crop_output(original_name, buf, p1, p2); // �ڸ� ���� ���
	horizon_output(original_name, buf); // �¿���� ���� ���
	vertical_output(original_name, buf); // ���Ϲ��� ���� ���
	std::cout << "Output images are stored!" << std::endl;
	// ���� �Ҵ� ����
	for (int i = 0; i < ORIGINAL_SIZE; i++)
		delete[] buf[i];
	delete[] buf;
	return (0);
}