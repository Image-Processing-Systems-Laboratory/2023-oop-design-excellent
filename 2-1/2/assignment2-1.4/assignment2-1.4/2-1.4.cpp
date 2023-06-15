#include <iostream> //iostream ����
#include <fstream> //fstream ����

using namespace std; //namespace std ����

class decorde //decorde class ����
{
private:
	char get[1000] = { 0 }; //���� ������ �ؽ�Ʈ�� �ޱ� ���� ������ �迭
	char put[1000] = { 0 }; //���Ͽ� �� �ؽ�Ʈ�� ���� ������ �迭
	const char charac = 'a'; //a�� �����̱� ������ charac ������ a�� �����ؼ� ���
	ifstream readfile;
	ofstream writefile; //�Է� ���� ��Ʈ��, ��� ���� ��Ʈ�� ����
	int countzero = 0; //0�� ����� ���� ���� ���� ����
	int j = 0; //�ݺ������� put �迭�� �ε����� ����Ű�� ���� ���� ����

public:
	void fileopen(const char* readtext, const char* writetext) //fileopen �Լ�
	{
		readfile.open(readtext); //���� �ؽ�Ʈ ���� ����
		if (!readfile) //���� �������� ������
			cout << "No file detected"; //�ȳ��� ���
		writefile.open(writetext); //���⸦ ���� �ؽ�Ʈ ���� ����
	} //fileopen �Լ� ����

	void read(void) //read �Լ�
	{
		while (!readfile.eof()) //���� �ؽ�Ʈ������ ���� ������
			readfile.getline(get, 1000); //get �迭�� �����ϱ�
		for (int i = 0; get[i] != '\0'; i++) //�� ������ �� get�迭�� ��ҵ��� ���ǿ� �°� ��ȯ�ؼ� put�迭�� �־��ֱ� ���� �ݺ��� ����
		{
			if ((get[i] == '1')) //���� 1�� ������
			{
				put[j] = static_cast<char>(charac + countzero); //1 �տ� �ִ� 0�� ������ŭ�� charac(������ a)�� ���� �� char������ ����ȯ �� put�迭�� ����
				countzero = 0; //countzero�� �ʱ�ȭ
				j++; //put�� �ε����� ����Ű�� j ����
			}
			else //1�� ������ ���� ���, �� 0�� ������ ��� 
			{
				if (countzero == 24) //zó���� ���ؼ� ���� ���ǹ�, countzero�� 24���� �����ϸ� z��� ��!
				{
					put[j] = static_cast<char>(charac + countzero + 1); //charac�� 25�� ���� �� char������ ����ȯ �Ͽ� put�迭�� ���� (z ó��)
					countzero = 0; //countzero�� �ʱ�ȭ
					j++; //put�� �ε����� ����Ű�� j ����
				}
				else //�� ���� ���, �� �Ϲ������� 0�� ������ ��Ȳ
				{
					countzero++; //countzero�� ������Ų��.
				}
			}
		}
	} //read�Լ� ����

	void write(void) //write�Լ�
	{
		if (writefile.is_open()) //���������� ������ ������
		{
			writefile << put; //put�迭�� �Էµ� ���ڵ��� writefile�� ���ش�.
		}
		else //���������� ������ ������
		{
			cout << "No File to write"; //�ȳ��� ���
		}
	} //write�Լ� ����

	void fileclose(void) //fileclose�Լ�
	{
		readfile.close();
		writefile.close(); //���������� ������ �ݴ´�.
	} //fileclose�Լ� ����

};

int main()
{
	char input1[] = "binary.txt"; //0000000100001000000000001000000000001000000000000001 �� ���ִ� �ؽ�Ʈ ����
	char output1[] = "hello.txt"; //hello�� ����� �ؽ�Ʈ ����

	char input2[] = "allnumber.txt";
	//0000000000000000000000000010101101001000100001000001000000100000001000000001000000000100000000001000000000000000000000000000000 �� ���ִ� �ؽ�Ʈ ����
	char output2[] = "alphabet.txt"; //zbbbabcdefghijkz �� ����� �ؽ�Ʈ ����

	decorde object1; //decorde Ŭ������ ���� object1 ��ü ����
	object1.fileopen(input1, output1); //object1 ��ü�� ���� fileopen �Լ� ����
	object1.read(); //read �Լ� ����
	object1.write(); //write �Լ� ����
	object1.fileclose(); //fileclose �Լ� ����

	decorde object2; //decorde Ŭ������ ���� object2 ��ü ����
	object2.fileopen(input2, output2); //object2 ��ü�� ���� fileopen �Լ� ����
	object2.read(); //read �Լ� ����
	object2.write(); //write �Լ� ����
	object2.fileclose(); //fileclose �Լ� ����

	return 0; //0�� ��ȯ
} //main�Լ� ����