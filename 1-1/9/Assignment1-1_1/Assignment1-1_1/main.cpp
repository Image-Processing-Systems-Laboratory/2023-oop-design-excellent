#include <iostream>
#define DOLLAR '$'  // 달러 기호 정의 
#define SPACE ' '   // 공백 기호 정의

struct Buffer // 버퍼 공간 포인터와 해당 공간의 너비와 높이 저장
{
	char	*buf;
	int		width;
	int		height;
};

void	buf_output(Buffer &buf) // 버퍼를 표준 출력에 출력
{
	for (int i = 0; i < buf.height; i++)
	{
		std::cout << &(buf.buf[i * buf.width]) << '\n';
	}
}

void	input_char(Buffer &buf, int i, int j, char ch) //버퍼 내부에 인덱스 (i, j)위치에 ch를 대입
{
	buf.buf[i * buf.width + j] = ch;
}

int	pow_int(int num, int power) // num의 power 제곱을 계산
{
	int result;

	result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= num;
	}
	return (result);
}

void	buf_init(Buffer &buf) // 버퍼를 할당하고 모두 공백으로 초기화
{
	int	i;
	int	j;
	
	buf.buf = new char[buf.height * buf.width]; // 버퍼는 논리적으로는 2차원이나 할당은 1차원, 할당 및 접근에서 속도의 이득이 있음
	for (i = 0; i < buf.height; i++) // 버퍼를 모두 공백으로 초기화, 출력 시를 위해 각 행의 끝 지점에 널 문자 삽입
	{
		for (j = 0; j < buf.width - 1; j++)
			input_char(buf, i, j, SPACE);
		input_char(buf, i, j, 0);
	}
}

void	buf_destruct(Buffer &buf)
{
	delete[] buf.buf; // 버퍼의 공간을 해제
}

// Sierpinski triangle 재귀 구현
// 매개변수로 삼각형을 그릴 버퍼와, 삼각형의 윗 꼭짓점, 삼각형의 높이를 지정한다.
void	triangle(Buffer &buf, int i, int j, int size)
{
	if (size == 3) // 삼각형의 높이가 3이면 단위 삼각형으로 취급하여 버퍼에 입력한다. 
	{
		input_char(buf, i, j, DOLLAR);			// 삼각형의 위 꼭짓점
		input_char(buf, i + 1, j - 1, DOLLAR);	// 삼각형의 좌측 변
		input_char(buf, i + 1, j + 1, DOLLAR);	// 삼각형의 우측 변 
		for (int k = 0; k < 5; k++) // 삼각형의 밑면(크기 5인 선분)
			input_char(buf, i + 2, j - 2 + k, DOLLAR);
		return ;
	}
	// 재귀 구현부
	triangle(buf, i, j, size / 2); // 윗 꼭짓점에 위치하는 부분 삼각형
	triangle(buf, i + size / 2, j - size / 2, size / 2); // 밑 좌측에 위치하는 부분 삼각형
	triangle(buf, i + size / 2, j + size / 2, size / 2); // 밑 우측에 위치하는 부분 삼각형
}

int	main(void)
{
	unsigned char	k;		// k 는 unsigned char 형으로 하라고 문제에 명시
	Buffer			buf;	// 삼각형의 데이터를 담을 버퍼

	std::cin >> k; // 사용자로부터 입력을 받음
	if (!std::cin || k < '1' || k > '8') // 예외 처리: 1~8사이가 아닌 경우 모두 에러 처리함
	{
		std::cerr << "Invalid input" << std::endl;
		return (EXIT_FAILURE);
	}
	k -= '0'; // k를 캐릭터형에서 알맞은 정수형으로 변환
	buf.height = 3 * pow_int(2, k - 1); // 삼각형의 높이 (문제에 3N으로 명시된 값)
	buf.width = 6 * pow_int(2, k - 1); // 삼각형의 최대 너비 + 1, +1을 한 이유는 널 문자를 사용하여 문자열 출력을 사용 가능하도록 함
	buf_init(buf); // 버퍼 할당 및 초기화
	triangle(buf, 0, buf.width / 2 - 1, buf.height); // 삼각형을 버퍼에 그리는 함수
	buf_output(buf); // 버퍼 출력
	buf_destruct(buf); // 버퍼 공간 해제
	return (0);
}