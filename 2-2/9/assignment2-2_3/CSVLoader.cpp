#include "CSVLoader.h"
#include <iostream>
#include <cstdio>

CSVLoader::CSVLoader()
{
	//cols�� rows ������ ���� ���� ����
	std::fstream file;
	file.open("CSVLoader_Data.txt");
	if (!file) {             //���� ���� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";
		exit(100);
	}

	char ch;

	//cols ����
	cols = 0;
	while (1) {
		ch = file.get();      //������ ���� �о ����

		if (ch == '\n' || file.eof()) {
			break;                //���� ���ڸ� �����ų� ������ ���� �������� ��� �ݺ� ����
		}

		if (ch == ',') {
			cols++;            //','�� ���� ������ cols�� 1 ����
		}
	}
	cols++;            //���� ���� ������ ���ڿ� �� ���� ','�� �������� �ϳ� �� �����Ƿ� 1 ����
	file.seekg(0);      //������ ���� ������ �̵�
	
	//rows ����
	rows = 0;
	while (1) {
		ch = file.get();     //������ ���� �о ����

		if (file.eof()) {
			break;         //������ ���� �������� ��� �ݺ� ����
		}

		if (ch == '\n') {
			rows++;          //���� ���ڸ� ���� ������ rows�� 1 ���� (���� ���� ���� ������ ���� ���� ���� ����.)
		}
	}

	file.close();             //���� �ݱ�
	
	//�����Ҵ�
	data = new float* [rows];          //float* �ڷ������� ���� ����ŭ �Ҵ� �� data�� �ּ� �� ����
	if (data == NULL) {           //�Ҵ� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";          
		exit(100);
	}
	data[0] = new float[rows * cols];  //float �ڷ������� (�� * ��) ��ŭ �Ҵ� �� data[0]�� �ּ� �� ����
	if (data[0] == NULL) {            //�Ҵ� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";
		delete[] data;
		exit(100);
	}
	for (int i = 1; i < rows; i++)
	{
		data[i] = data[i - 1] + cols;     //�ึ�� ���� �� �������� �ּ� �� ����
	}

	//CSV ������ �м��Ͽ� data�� �����ϱ� ���� ���� ����
	std::fstream CSV;
	CSV.open("CSVLoader_Data.txt");
	if (!CSV) {                  //���� ���� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";
		exit(100);
	}

	char str[MAX_BUFFER_SIZE];  //������ �� ���� ������ char�� �迭

	//data�� ����
	int k = rows;     //k�� rows �� �ӽ� ����
	for (rows = 0; rows < k; rows++) {         //���� ����ŭ �ݺ�
		CSV.getline(str, MAX_BUFFER_SIZE);     //���� �� �پ� �о����

		parse(str);                  //parse �Լ��� str�� �����Ͽ� ȣ��
	}
	

	
	CSV.close();        //���� �ݱ�
}

CSVLoader::CSVLoader(const char* path) {

	cols = 0;
	rows = 1;

	//cols ����
	int comma = 0;
	while (path[comma] != '\0') {  //���ڿ��� ������ �ݺ�
		if (path[comma] == ',') {
			cols++;         //','�� ������ ��� cols�� 1 ����
		}
		comma++;
	}
	cols++;             //���� ���� ���ڿ��� ','�� �������� �ϳ� �� �����Ƿ� 1 ����

	//���� �Ҵ�
	data = new float* [rows];  //float* �ڷ������� ���� ����ŭ �Ҵ� �� data�� �ּ� �� ����
	if (data == NULL) {        //�Ҵ� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";
		exit(100);
	}
	data[0] = new float[rows * cols];   //float �ڷ������� (�� * ��) ��ŭ �Ҵ� �� data[0]�� �ּ� �� ����
	if (data[0] == NULL) {   //�Ҵ� ������ ��� ���� �޽��� ��� �� ����
		std::cerr << "ERROR";
		delete[] data;
		exit(100);
	}

	rows = 0;
	parse(path);      //CSV �м�
	rows++;
}

CSVLoader::~CSVLoader()
{
	if (data == 0)  //data�� �Ҵ�� �޸𸮰� ���� ��� ����
	{
		exit(100);
	}

	if (data[0])
	{
		delete[] data[0];  //data[0]�� NULL�� �ƴ� ��� �޸� ����
	}

	delete[] data;  //data�� �޸� ����
}

//data �� ��ȯ�ϴ� �Լ�
float** CSVLoader::getData() const {
	return data;         //data �� ��ȯ
}

//rows �� ��ȯ�ϴ� �Լ�
int CSVLoader::getRows() const {
	return rows;             //rows �� ��ȯ
}

//cols �� ��ȯ�ϴ� �Լ�
int CSVLoader::getCols() const {
	return cols;            //cols �� ��ȯ
}

//CSV ���� �м�
void CSVLoader::parse(const char* path) {
	float exponent;        //�ڸ���
	float num;             //�Ǽ��� ��ȯ�� ��
	int exponent_num;      //����ǥ���
	bool minus;            //�������� �Ǵ�
	bool minus_exponent;   //���� ǥ������� �������� �Ǵ�

	int start = 0;             //���ڰ� �����ϴ� ��ġ

	int start_decimal;     //�Ҽ� �κ��� �����ϴ� ��ġ
	int len;

	//���� ����ŭ �ݺ�
	for (int index = 0; index < cols; index++) {
		exponent = 1;
		num = 0;
		exponent_num = 0;
		minus = false;
		minus_exponent = false;

		//��ȣ�� �ִ��� �Ǻ��ϱ�
		if (path[start] == '+' || path[start] == '-') {
			if (path[start] == '-') { //'-'�� ���� ��� ������ ����
				minus = true;
			}
			start++;     
		}  // -> �ݺ��� ���� �� start�� ���ڰ� �����ϴ� ��ġ �ǹ�

		//�Ҽ��� ���� �κ� ���ϱ�(�Ҽ��� ���� ������ �ݺ�)
		start_decimal = start;
		while (path[start_decimal] >= '0' && path[start_decimal] <= '9') {
			start_decimal++;
		}       // -> �ݺ��� ���� �� start_decimal�� ���� ���� �ٸ� �� '.', ',', '\0'�� ��ġ �ǹ�

		//���� �κ� ���
		for (int i = start_decimal - 1; i >= start; i--) {   //������ ���� �κ��� �ں��� ����
			num = num + ((path[i] - '0') * exponent);   //�� �ڸ��� ����Ǿ� �ִ� ���ڿ� �ڸ����� ���� ���� num�� ���Ѵ�.
			exponent *= 10;
		}

		//�Ҽ��� ���
		if (path[start_decimal] == '.') {  
			start_decimal++;   //�Ҽ��� ���� �κ� �ǹ�
			exponent = 0.1;


			//�Ҽ� �κ� ���
			while (path[start_decimal] != ',' && path[start_decimal] != '\0') {   //������ ���� ������ ������ �ݺ�
				if (path[start_decimal] == 'e' || path[start_decimal] == 'E') {  //���� ǥ����� ���
					start_decimal++;

					//��ȣ�� �ִ��� �Ǻ��ϱ�
					if (path[start_decimal] == '+' || path[start_decimal] == '-') {
						if (path[start_decimal] == '-') {
							minus_exponent = true;
						}
						start_decimal++;
					}

					//������ ���� ���ϱ�
					len = start_decimal;
					while (path[len] >= '0' && path[len] <= '9') {
						len++;
					}

					//e �Ǵ� E ���� ���� ���ϱ�
					exponent = 1;
					for (int i = len - 1; i >= start_decimal; i--) {  //������ �ں��� ����
						exponent_num = exponent_num + ((path[i] - '0') * exponent); //���ڿ��� �� �ڸ��� ����Ǿ� �ִ� ���ڿ� �ڸ����� ���� ���� exponent_num�� ���Ѵ�.
						exponent *= 10;
					}

					//num�� ���ϱ�
					if (minus_exponent) {
						for (int i = 0; i < exponent_num; i++) {
							num *= 0.1;
						}
					}
					else {
						for (int i = 0; i < exponent_num; i++) {
							num *= 10;
						}
					}

					start_decimal = len;  //start_decimal�� ������ ���� �κп� ����Ǿ� �ִ� ����(',', '\0')�� ��ġ �ǹ�
					break;
				}
				
				num = num + ((path[start_decimal] - '0') * exponent);  //���ڿ��� �� �ڸ��� ����Ǿ� �ִ� ���ڿ� �ڸ����� ���� ���� num�� ���Ѵ�.
				exponent *= 0.1;
				start_decimal++;
			}
		}

		
		if (minus) {
			num *= -1;    //���� �տ� '-'��ȣ�� ������ ��� -1 ���Ͽ� ������ ��ȯ
		}

		data[rows][index] = num;     //data[rows][index]�� num �� ����

		start = start_decimal + 1;   //start�� ���� ������ ���� ��ġ�� ����
	}
}

//data ��� �Լ�
void CSVLoader::print(void) {
	for (int i = 0; i < rows; i++) {          //���� ����ŭ �ݺ�
		for (int j = 0; j < cols; j++) {      //���� ����ŭ �ݺ�
			std::cout << data[i][j] << "    ";    //�������� �����Ͽ� data �� ������� ���
		}
		std::cout << std::endl;         //�� �ٲٱ�
	}
}