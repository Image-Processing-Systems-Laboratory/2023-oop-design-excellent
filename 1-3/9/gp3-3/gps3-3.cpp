#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
using namespace std;

char* convert(char* input, int from, int to)
{
    int decimal = 0; // 일단 10진수로 먼저 바꾸고 시작한다. 10진수가 우리가 가장 흔히 쓰는 진법이므로 계산시에 가장 편하기 때문이다.
    int len = strlen(input);

    if (from == 10) // input값이 이미 10진수면
        decimal = atoi(input); // 바로 input 숫자로 바꿔서 decimal에 넣어주기. 문자열을 숫자로 바꿔줄때 atoi를 사용해준다(strtol을 사용해도 된다).

    else // 10진수가 아니면(10진수로 바꿔줘야 한다)
        for (int i = len - 1; i >= 0; i--) // 반복문이 뒤에서부터 시작해서 앞으로 오는 구조
        {
            char c = input[i]; // c에는 i번째 자리가 들어간다(배열이므로 정확히는 i+1번째 자리지만 좀 더 빠른 이해를 위해 자리수를 인덱스라고 생각했다)
            int num1;
            if (isdigit(c) == 0) // isdigit을 통해 c가 숫자인지 문자인지 확인하기
                num1 = c - 'A' + 10; // 문자면 아스키코드표를 참고해 다음과 같이 숫자로 바꿔주기. 예를 들어 A면 10, B면 11, C면 12 이런식으로
            else // 숫자면
                num1 = c - '0'; // 그대로 실제 숫자로 바꿔주기 -'0' 대신에 -48을 해줘도 된다(아스키 코드)
            decimal += num1 * pow(from, len - i - 1); // 오른쪽부터 시작해서 진수의 0제곱(1), 진수의 1제곱, 이런식으로 쭉 간다
            // 예를 들어 2진수 0011이면 2의 0제곱 * 1 + 2의 1제곱 * 1 + 2의 3제곱 * 1 이런식으로 가는것을 의미한다. 여기서 1, 0이 num1이고 2가 spe, input.length()가 자리수(n제곱에서 n)를 말한다. 
        }
    // 이제 decimal에는 input을 10진수로 바꾼 값이 들어가있다.

    int temp = decimal; // temp에 input을 10진수로 바꾼 값 넣기
    int count = 0; // to 진수에서의 자리수
    while (temp != 0)
    {
        temp /= to; // temp를 to로 나누고
        count++; // 나눌때마다 count를 1씩 더한다. 따라서 count에는 총 몇번 나뉘는지가 들어간다.
    }
    char* output = new char[count + 1]; // output 동적할당해주기. 길이는 총 나뉜횟수+1이 된다. 1은 끝에 null을 넣기 위함이다.
    if (to == 10) // 만약에 바꿔줄 진수가 10진수면
        sprintf(output, "%d", decimal); // sprintf를 이용해 문자열로 바꿔준뒤에 바로 반환하기
    else
    {
        int i = 0;
        while (decimal > 0)
        {
            int num2 = decimal % to; // decimal을 to로 나눈 나머지를 넣어준다
            if (num2 < 10) // 나머지가 10보다 작으면
                output[i++] = num2 + '0'; // 그 숫자는 10진수 아래이므로 다음과 같이 +'0'만 해서 문자형태로만 바꿔준다(0~9로 표현할 수 있기 때문에)
            else // 나머지가 10 이상이라면
                output[i++] = num2 - 10 + 'A'; // 그 숫자는 16진수라는 뜻이므로 다음과 같이 16진수 형태로 바꿔준다(10을 넘어가면 알파벳으로 표현하기 때문에)
            decimal /= to; // 나머지 한번 넣고 한번 나눠주기

            // 왜 이렇게 나누냐면, 2진수, 8진수, 10진수는 0~9의 숫자로 모든걸 해결할 수 있지만, 16진수의 경우 알파벳도 추가돼있다.
            // 그래서 이렇게 두가지 경우로 쪼개서 만약에 나머지가 9를 넘어가는 값이 나오면 알파벳으로 해결해줘야 하므로 다음과 같이 한것이다.
        }
        output[i] = '\0'; // 끝을 표시해준다. i가 반복문에서 후위연산 되기 때문에, 최종적으로 반복문을 빠져나올때 i에 1이 더해진다. 그래서 굳이 output[i+1]로 해줄 필요가 없다.

        for (int j = 0; j < i / 2; j++) // 최종적으로 나머지를 쭉 넣어준 배열을 거꾸로 읽어야 그게 바뀐 수(output)가 된다.
        {
            // tempp를 이용한 스왑이다. j 범위가 j<i/2이므로, output의 절반을 기준으로 처음부터 하나씩 바꿔나가는 것이다. 
            char tempp = output[j];
            output[j] = output[i - j - 1];
            output[i - j - 1] = tempp;
        }
    }
    return output; // 최종적으로 변환된 진수의 값을 가지고 있는 output을 반환
}

int main()
{
    char input[100]; // input 값(바꾸고자 하는 수)
    int from, to;
    cin >> input >> from >> to;
    char* output = convert(input, from, to); // ouput에 넣어주기
    cout << output << endl;
    delete[] output; // output에 할당된 메모리 delete
    return 0;
}
