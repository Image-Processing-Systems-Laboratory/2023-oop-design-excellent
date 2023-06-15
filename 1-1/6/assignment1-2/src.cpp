#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //float a b c를 입력 받는다.
    float a, b, c;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;

    if (a == 0) {   //a = 0으로 이차방정식이 아닌경우
        cout << "Unexpected factor of a quadratic term" << endl;    //출력
        return -1;
    }
    //이차방정식의 판별식 discriminant 계산
    float discriminant = static_cast<float>(pow(b, 2)) - 4 * a * c;

    //판별식이 음수인 경우
    if (discriminant < 0) {     //판별식이 음수인 경우
        cout << "The equation has no real number solutions." << endl;   //출력
    }
    else if (discriminant == 0) {   //판별식이 0인 경우
        cout << "X1, X2: " << (-b / (2 * a)) << " (double root)" << endl;   //출력
    }
    else {      //판별식이 양수인 경우
        //근의 공식을 이용해 결과 출력
        float x1 = 0, x2 = 0;
        //b가 다른 계수에 비해 독보적으로 큰 경우, 오차를 줄이기 위해 사용
        if (b < 0)      //두수의 합을 나누는 방식으로 변형
            x1 = (-b + sqrt(discriminant)) / (2 * a);
        else            //두수의 합으로 나누는 방식으로 변형
            x1 = (2 * c) / (-b - sqrt(discriminant));
        x2 = c / (a * x1);  //근과 계수의 관계 사용

        cout << "X1: " << x1 << ", X2: " << x2 << endl; //출력
    }

    return 0;
}