#include <iostream> 
#include <cmath> 
#define PI 3.141592 // PI 값을 상수로 정의

using namespace std;

int main()
{
    double theta; // 사용자로부터 입력받을 각도 값
    double matrix3x1[3] = { 0 }; // 3x1 행렬을 표현하기 위한 배열

    cout << "Degrees: ";
    cin >> theta;

    cout << "Coordinate: ";
    cin >> matrix3x1[0] >> matrix3x1[1] >> matrix3x1[2];

    double radian = theta * PI / 180.0; // 입력받은 각도 값을 라디안으로 변환
    double cosine = cos(radian); // 라디안 값을 삼각함수 계산을 통해 cosine 값으로 변환
    double sine = sin(radian); // 라디안 값을 삼각함수 계산을 통해 sine 값으로 변환
    double matrix3x3[3][3] = // 3x3 행렬
    {
     {-cosine , sine , 0},
     {sine , cosine , 0},
     {0, 0, 0}
    };

    // 오차를 잡기 위해 행렬의 원소값들을 10000을 곱한 후 반올림하여 다시 10000으로 나눈다
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix3x3[i][j] *= 10000;
            matrix3x3[i][j] = round(matrix3x3[i][j]);
            matrix3x3[i][j] /= 10000;
        }
    }

    double result[3] = { 0, 0, 0 }; // 결과값을 저장할 3x1 행렬을 표현하기 위한 배열

    for (int i = 0; i < 3; i++)
    {
        double temp = 0;
        for (int j = 0; j < 3; j++)
        {
            temp += matrix3x3[i][j] * matrix3x1[j];
        }
        result[i] = temp;
    }

    // 결과값 출력
    cout << "Result: " << result[0] << " " << result[1] << " " << result[2] << endl;

    return 0; // 프로그램 종료
}