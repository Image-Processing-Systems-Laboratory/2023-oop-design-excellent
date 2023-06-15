#include <iostream>
#define DOLLAR '$'  // �޷� ��ȣ ���� 
#define SPACE ' '   // ���� ��ȣ ����

struct Buffer // ���� ���� �����Ϳ� �ش� ������ �ʺ�� ���� ����
{
	char	*buf;
	int		width;
	int		height;
};

void	buf_output(Buffer &buf) // ���۸� ǥ�� ��¿� ���
{
	for (int i = 0; i < buf.height; i++)
	{
		std::cout << &(buf.buf[i * buf.width]) << '\n';
	}
}

void	input_char(Buffer &buf, int i, int j, char ch) //���� ���ο� �ε��� (i, j)��ġ�� ch�� ����
{
	buf.buf[i * buf.width + j] = ch;
}

int	pow_int(int num, int power) // num�� power ������ ���
{
	int result;

	result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= num;
	}
	return (result);
}

void	buf_init(Buffer &buf) // ���۸� �Ҵ��ϰ� ��� �������� �ʱ�ȭ
{
	int	i;
	int	j;
	
	buf.buf = new char[buf.height * buf.width]; // ���۴� �������δ� 2�����̳� �Ҵ��� 1����, �Ҵ� �� ���ٿ��� �ӵ��� �̵��� ����
	for (i = 0; i < buf.height; i++) // ���۸� ��� �������� �ʱ�ȭ, ��� �ø� ���� �� ���� �� ������ �� ���� ����
	{
		for (j = 0; j < buf.width - 1; j++)
			input_char(buf, i, j, SPACE);
		input_char(buf, i, j, 0);
	}
}

void	buf_destruct(Buffer &buf)
{
	delete[] buf.buf; // ������ ������ ����
}

// Sierpinski triangle ��� ����
// �Ű������� �ﰢ���� �׸� ���ۿ�, �ﰢ���� �� ������, �ﰢ���� ���̸� �����Ѵ�.
void	triangle(Buffer &buf, int i, int j, int size)
{
	if (size == 3) // �ﰢ���� ���̰� 3�̸� ���� �ﰢ������ ����Ͽ� ���ۿ� �Է��Ѵ�. 
	{
		input_char(buf, i, j, DOLLAR);			// �ﰢ���� �� ������
		input_char(buf, i + 1, j - 1, DOLLAR);	// �ﰢ���� ���� ��
		input_char(buf, i + 1, j + 1, DOLLAR);	// �ﰢ���� ���� �� 
		for (int k = 0; k < 5; k++) // �ﰢ���� �ظ�(ũ�� 5�� ����)
			input_char(buf, i + 2, j - 2 + k, DOLLAR);
		return ;
	}
	// ��� ������
	triangle(buf, i, j, size / 2); // �� �������� ��ġ�ϴ� �κ� �ﰢ��
	triangle(buf, i + size / 2, j - size / 2, size / 2); // �� ������ ��ġ�ϴ� �κ� �ﰢ��
	triangle(buf, i + size / 2, j + size / 2, size / 2); // �� ������ ��ġ�ϴ� �κ� �ﰢ��
}

int	main(void)
{
	unsigned char	k;		// k �� unsigned char ������ �϶�� ������ ���
	Buffer			buf;	// �ﰢ���� �����͸� ���� ����

	std::cin >> k; // ����ڷκ��� �Է��� ����
	if (!std::cin || k < '1' || k > '8') // ���� ó��: 1~8���̰� �ƴ� ��� ��� ���� ó����
	{
		std::cerr << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	k -= '0'; // k�� ĳ���������� �˸��� ���������� ��ȯ
	buf.height = 3 * pow_int(2, k - 1); // �ﰢ���� ���� (������ 3N���� ��õ� ��)
	buf.width = 6 * pow_int(2, k - 1); // �ﰢ���� �ִ� �ʺ� + 1, +1�� �� ������ �� ���ڸ� ����Ͽ� ���ڿ� ����� ��� �����ϵ��� ��
	buf_init(buf); // ���� �Ҵ� �� �ʱ�ȭ
	triangle(buf, 0, buf.width / 2 - 1, buf.height); // �ﰢ���� ���ۿ� �׸��� �Լ�
	buf_output(buf); // ���� ���
	buf_destruct(buf); // ���� ���� ����
	return (0);
}