#include <iostream>


using namespace std;

int main() {
    double a, b, c, d, e, f, g, h, i;
    //3X3 행렬 입력
    cout << "Enter the 3X3 matrix:" << endl;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    //행렬식 값 계산
    double det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    if (det == 0) {     //행렬식이 0일때 역행렬을 갖지 않는다.
        cout << "The inverse matrix does not exit." << endl;
    }
    else {
        //수반행렬 계산
        double adjugate[3][3] = { {e * i - f * h, -(b * i - c * h), b * f - c * e},
                                 {-(d * i - f * g), a * i - c * g, -(a * f - c * d)},
                                 {d * h - e * g, -(a * h - b * g), a * e - b * d} };
        //역행렬 계산
        double inverse[3][3];
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                inverse[row][col] = adjugate[row][col] / det;       //반복문을 써서 각 요소들을 할당해준다.
            }
        }

        //역행렬 출력
        cout << "The inverse matrix is:" << endl;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cout << inverse[row][col] << " ";       //반복문을 써서 각 요소들을 출력해준다.
            }
            cout << endl;
        }
    }

    return 0;
}