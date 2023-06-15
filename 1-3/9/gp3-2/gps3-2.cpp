#define CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void cir(int up, int down); // 식별자 위해 미리 선언
void print(int* m, int i, int j); // 식별자 위해 미리 선언

void cir(int up, int down) // 순환소수 확인 함수
{
    int m[256]; // 몫 배열
    int n[256]; // 나머지 배열
    bool count = 0; // 체크용 변수(이중반복문을 빠져나오기 위한 변수)
    int i = 0; // 반복문을 위한 변수
    int j = 0; // 반복문을 위한 변수
    for (i = 0; i < 256; i++)
    {
        m[i] = up / down; // m 배열에 몫을 저장
        n[i] = up % down; // n 배열에 나머지를 저장
        for (j = 0; j < i; j++) // j는 처음부터 바깥 반복문 인덱스인 i 전까지 돈다
        {
            if (n[i] == n[j]) // 만약에 이전에 저장된 나머지값중에 같은 값이 나오면 찾은부분부터 i 전까지가 하나의 순환구조가 되는것이다
            {
                count++;
                break; // 빠져나오고
            }
        }
        if (count==1)
            break; // 빠져나온다
        up %= down; // 이제 up은 나머지 연산후 나머지로 들어간다
        up *= 10; // 나머지는 무조건 몫보다 작기 때문에 10을 곱해준다. 이는 나눗셈 연산을 실제로 손으로 써서 해보면 나누는 값이 더 클때 뒤에 0을 붙여주는 과정과 같은 과정이다
    }
    if (n[i] == 0) // 만약에 나누어 떨어질 경우
    {
        cout << m[0];
        cout << ".";
        for (int k = 1; k < j+1; k++)
            cout << m[k];
        // 괄호 전까지만 출력(만약에 똑같이 할 경우 0이 순환된다고 인지하여 (0)으로 출력한다)
    }
    else
        print(m, i, j); // 인자로 출력을 위한 몫배열과 인덱스 두개를 가지고 순환소수 출력 함수로 넘어간다
}

void print(int* m, int i, int j) // 순환소수 출력 함수
{
    cout << m[0];
    cout << ".";
    for (int k = 1; k < j + 1; k++) // 일단 반복이 시작되는 구간 전까지
        cout << m[k]; // 몫을 출력
    cout << "(";
    for (int k = j + 1; k < i + 1; k++)
        cout << m[k];
    cout << ")" << endl;
}

int main()
{
    int down = 0; // 분모
    int up = 0; // 분자
    int Vs = 0;
    int R1 = 0;
    int R2 = 0;
    int RL = 0;
    cout << "Vs: ";
    cin >> Vs;
    cout << "R1: ";
    cin >> R1;
    cout << "R2: ";
    cin >> R2;
    cout << "R(Load): ";
    cin >> RL;
    double Vout = 0;
    if (RL == 0) // RL이 0이냐 아니냐에 따라 회로 구조가 달라진다. 0일 경우 일반적인 직렬회로. R2쪽이 Vout이다
    {
        up = Vs * R2; // 분자는 단순히 전압에 저항을 곱한것이다
        down = R1 + R2; // 분모 역시 두 개의 저항의 합이다
        cout << "Vout: " << up << "/" << down << " = "; // 출력은 약분하지 않고 분자/분모 형태로 출력
        if (up % down == 0) // 분자/분모가 정수형태로 나눗셈 연산이 가능하면
            cout << up / down << endl; // 그냥 몫 바로 출력
        else // 나누어 떨어지지 않는다면
            cir(up, down); // 순환소수 함수
    }
    else
    {
        double temp = (R2 * RL) / (R2 + RL); // R2||RL을 임시로 하나의 변수로 치환해준 것이다.
        // up과 down 계산시에 둘의 공통분모인 R2+RL을 지워주고 계산한다(40/20꼴을 출력하기 위해서).
        up = Vs * R2 * RL; // 분모에 있던 R2+RL을 지우고 나서의 분자 
        down = R1 * (R2 + RL) + R2 * RL; // 역시 분모에 있던 R2+RL을 지우고 나서의 분모. R1은 R2+RL로 나누어져있지 않았기 때문에 곱해줘야 한다
        cout << "Vout: " << up << "/" << down << " = ";
        if (up % down == 0)
            cout << up / down << endl;
        else
            cir(up, down);
        Vout = up / down; // Vout은 double 형으로 선언했기 때문에 소수형태로 저장된다(나머지가 없어지지 않음)
        double cal = (Vout * Vout / RL) / (Vs * Vs / (R1 + temp)); // cal은 Load power ratio의 값이 저장돼있는 변수
        cal *= 100; // 둘째짜리까지 출력해야 하므로 round를 이용하되, 100을 곱해서 round를 취해준뒤 다시 100으로 나눠주는식으로 한다
        cal = round(cal); // round를 이용한 반올림
        // 다시 100으로 나눠주지 않는 이유는, %형태로 출력하기 위해 어차피 100을 다시 곱해줘야 하기 때문이다.
        cout.precision(2); // 예를 들어 10.00 같은 경우는 뒤 00은 생략돼서 출력되므로, 이를 방지하기 위해(유효 숫자 출력을 위해) cout.precision과
        cout << fixed; // fixed를 사용한다
        cout << "Load power ratio: " << cal << "%" << endl;
    }
    return 0;
}