#include <iostream>
#include <cmath>

using namespace std;

void calculate(int num1, int num2); // 분수를 계산하는 함수

int main()
{
    double Vs, R1, R2, RL; // 값을 입력 받기 위한 변수들 선언
    cout << "Vs : ";
    cin >> Vs;
    cout << "R1 : ";
    cin >> R1;
    cout << "R2 : ";
    cin >> R2;
    cout << "R(Load) : ";
    cin >> RL;

    double R2RL = R2 * RL / (R2 + RL); // R2||RL의 계산과정을 나타낸 것
    double I, Vout, Pload, Ps, load_power_ratio; // 계산한 값들을 저장하기 위한 변수들 선언

    if (RL == 0) // RL이 0일 경우 아래와 같은 계산과정이 일어남
    {
        I = Vs / (R1 + R2);
        Vout = I * R2;
        cout << "Vout : " << Vs * R2 << "/" << R1 + R2 << " = ";
        calculate(Vs * R2, R1 + R2); // 함수 호출
        cout << endl;

    }
    else // 그 외의 경우 아래와 같은 계산과정이 일어남
    {
        I = Vs / (R1 + R2RL);
        Vout = I * R2RL;
        cout << "Vout : " << Vs * R2 * RL << "/" << (R1 * (R2 + RL)) + (R2 * RL) << " = ";
        calculate(Vs * R2 * RL, (R1 * (R2 + RL)) + (R2 * RL)); // 함수 호출
        cout << endl;

        // power 값 계산과정
        Pload = Vout * Vout / RL;
        Ps = Vs * I;
        load_power_ratio = Pload / Ps;

        cout.precision(2); // 소수점 둘째자리까지 출력
        cout << "Load power ratio : " << fixed << load_power_ratio * 100.0 << "%" << endl; // 소수점 둘째자리까지 출력
    }
    return 0;
}

void calculate(int num1, int num2) // 분수를 계산하는 함수
{
    int cpynum1 = num1, cpynum2 = num2, cnt = 0, start, end; // 변수들 선언
    int num[10000] = { 0 }; // 배열 선언

    while (1) // 무한루프
    {
        cpynum1 = (cpynum1 % cpynum2 * 10); // 분자를 분모로 나눈 나머지를 10을 곱함
        if (num[cpynum1] != 0)  // 만약 num[cpynum1]이 0이 아니라면
        {
            start = num[cpynum1]; // start에 값을 저장
            end = cnt; //end는 cnt와 같게 함
            break; // 루프 탈출
        }
        num[cpynum1] = ++cnt; // num[cpynum1]에 cnt값을 저장하고 cnt값을 1 증가시킴
    }

    cpynum1 = num1; // cpynum1에 num1값을 저장
    cpynum2 = num2; // cpynum2에 num2값을 저장
    cout << cpynum1 / cpynum2; // 분자를 분모로 나눈 몫을 출력
    if (cpynum1 % cpynum2 != 0) // 나머지가 0이 아니라면
    {
        cout << "."; // .을 출력
    }

    int temp = cpynum1 % cpynum2 * 10; // 나머지를 10 곱한 값을 저장
    for (int i = 0; i < start - 1; i++)
    {
        cout << temp / cpynum2; // temp를 cpynum2로 나눈 몫을 출력
        temp = (temp % cpynum2 * 10); // temp를 cpynum2로 나눈 나머지를 10 곱한 값을 저장
    }

    if (temp > 0) // temp가 0보다 크면
    {
        cout << "("; // (를 출력
        for (int j = start - 1; j < end; j++)
        {
            cout << temp / cpynum2; // temp를 cpynum2로 나눈 몫을 출력
            temp = temp % cpynum2 * 10; // temp를 cpynum2로 나눈 나머지를 10 곱한 값을 저장
        }
        cout << ")\n"; // )를 출력
    }
}