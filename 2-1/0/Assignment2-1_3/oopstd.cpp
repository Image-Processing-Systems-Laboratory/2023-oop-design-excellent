#include<cmath>


namespace oopstd {

	void* memset(void* ptr, int value, size_t num) {
		//unsigned char�� ������ ���� �� ptr�� ����Ű�� �޸� �ּ� ���
		unsigned char* char_ptr = (unsigned char*)ptr;
		//i�� 0���� num-1����
		for (int i = 0; i < num; i++)
			char_ptr[i] = (char)value;	//char_ptr[i]�� value���� ������

		return ptr;		//ptr ��ȯ
	}
	void* memcpy(void* destination, const void* source, size_t num) {
		//char�� ������ ���� �� ptr�� ����Ű�� �޸� �ּ� ���
		char* char_dest = (char*)destination;

		//const char�� ������ ���� �� ptr�� ����Ű�� �޸� �ּ� ���
		const char* char_source = (const char*)source;
		//i�� 0���� num-1����
		for (int i = 0; i < num; i++)
			char_dest[i] = char_source[i];	//char_source[i]�� ����� ���� char_dest[i]�� ������
		return destination;		//destination ��ȯ
	}

	int strcmp(const char* str1, const char* str2) {
		//i�� 0���� str1[i] �Ǵ� str2[i]�� null���ڸ� ������ ������ �ݺ�
		for (int i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
			if (str1[i] != str2[i])			//str1[i]�� str2[i]�� �ٸ���
				return str1[i] > str2[i] ? 1 : -1;	//str1[i]�� �� ũ�� 1 ��ȯ str2[i]�� �� ũ�� 2 ��ȯ

		return 0;		//������ 0 ��ȯ
	}
	int strncmp(const char* str1, const char* str2, size_t num) {
		//i�� 0���� num-1����
		for (int i = 0; i < num; i++)
			if (str1[i] != str2[i])			//str1[i]�� str2[i]�� �ٸ���
				return str1[i] > str2[i] ? 1 : -1;	//str1[i]�� �� ũ�� 1 ��ȯ str2[i]�� �� ũ�� 2 ��ȯ
		return 0;	//������ 0 ��ȯ
	}

	char* strcpy(char* destination, const char* source) {
		int i;		//int�� ���� ����
		//i�� 0���� source[i]�� null���ڸ� �������� ����
		for (i = 0; source[i] != '\0'; i++)
		{
			destination[i] = source[i];	//source[i]�� destination[i]�� ����
		}
		destination[i] = '\0';	//null���� ����

		return destination;		//destination ��ȯ
	}
	char* strncpy(char* destination, const char* source, size_t num) {
		//i�� 0���� num-1����
		for (int i = 0; i < num; i++)
		{
			if (source[i] != '\0')	//source[i] != '\0'�̸�
			{
				destination[i] = source[i];	//source[i]�� destination[i]�� ����
				continue;					//���� �ݺ��� ����
			}
			else					//source[i] == '\0'�̸�
			{
				destination[i] = '\0';	//null���� ����
				break;					//�ݺ��� Ż��
			}
		}
		
		return destination;			//destination ��ȯ
	}

	size_t strlen(const char* str) {
		size_t len = 0;		//���̸� ������ ���� ���� �� 0���� �ʱ�ȭ
		for (int i = 0; str[i] != '\0'; i++)	//i�� 0���� str[i]�� null���ڸ� �������� ����
			len++;		//len�� ���� 1������Ŵ
	
		return len;		//len ��ȯ
	}

	int atoi(const char* str) {
		int int_num = 0;
		int pos = 1;		//�����̸� 0 ����̸� 1�� ����
		//���� ����
		for (int i = 0; str[i] != '\0'; i++)	//i�� 0���� str[i]�� null���ڸ� �������� ����
		{
			//ù��° ���ڰ� �����̸�
			if (str[0] == '-')
			{
				pos = 0;		//pos�� 0���� �ʱ�ȭ
				continue;		//���� �ݺ��� ����
			}
			//str[i]�� ���ڰ� '0'~'9'�̸�
			if (str[i] >= '0' && str[i] <= '9')
				int_num = int_num * 10 + (str[i] - '0');
			else		//str[i]�� �����̸�
				break;	//�ݺ��� Ż��
		}
		//�����̸�
		if (pos == 0)
			int_num *= -1;		//����� ���� -1�� ����

		return int_num;			//int_num ��ȯ
	}
	float atof(const char* str) {
		float float_num = 0;	//str�� ����� �Ǽ��� ����
		int pos = 1;		//�����̸� 0 ����̸� 1�� ����
		int decimal_point = 0;	//�Ҽ��� �� ����
		for (int i = 0; str[i] != '\0'; i++)	//i�� 0���� str[i]�� null���ڸ� �������� ����
		{
			//ù��° ���ڰ� �����̸�
			if (str[0] == '-')
			{
				pos = 0;		//pos�� 0���� �ʱ�ȭ
				continue;		//���� �ݺ��� ����
			}
			//�Ǽ� �κ� ����
			//str[i]�� ���ڰ� '0'~'9'�̸�
			if (str[i] >= '0' && str[i] <= '9')
				float_num = float_num * 10 + (str[i] - 48);
			
			//�Ҽ����� ������
			else if (str[i] == '.')
			{
				//�Ҽ��� �κ� ����
				//j=i+1���� str[j]�� null ���ڸ� ������ ������
				for (int j = i + 1; str[j] != '\0'; j++)
				{
					//str[i]�� ���ڰ� '0'~'9'�̸� str[i]�� �Ҽ��� �κ����� ����
					if (str[j] >= '0' && str[j] <= '9')
						float_num = float_num + (str[j] - '0') * pow(10, -(++decimal_point));
					else	//str[i]�� �����̸�
						break;	//�ݺ��� Ż��
				}
				break;	//�ݺ��� Ż��
			}
			else		//str[i]�� �����̸�
				break;	//�ݺ��� Ż��
		}
		//�����̸�
		if (pos == 0)
			float_num *= -1;	//����� ���� -1�� ����

		return  float_num;		//float_num ��ȯ
	}

}