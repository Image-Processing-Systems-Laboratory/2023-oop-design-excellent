#include <iostream>
using namespace std;

class Matrix  // matrix 클래스를 정의
{
private: // private 멤버 변수 선언
    double elements[3][3]; // 3x3 행렬을 저장할 배열

public: // public 멤버 함수 선언
    Matrix(double val = 0.0) // 생성자
    {
        // 3x3 행렬의 각 원소를 초기값 0.0으로 초기화
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = val;
            }
        }
    }

    Matrix(double arr[3][3]) // 생성자
    {
        // 3x3 행렬의 각 원소를 배열 arr의 값으로 초기화
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = arr[i][j];
            }
        }
    }

    void print() // 행렬의 원소를 출력하는 함수
    {
        // 행렬의 각 원소를 출력
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+=(const Matrix& m) // 행렬의 덧셈 연산자
    {
        // 행렬의 각 원소를 더함
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] += m.elements[i][j];
            }
        }
        return *this; // 덧셈 결과를 반환
    }

    Matrix operator-=(const Matrix& m) // 행렬의 뺄셈 연산자
    {
        // 행렬의 각 원소를 뺌
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = elements[i][j] - m.elements[i][j];
            }
        }
        return *this; // 뺄셈 결과를 반환
    }

    Matrix operator*(const Matrix& m) // 행렬의 곱셈 연산자
    {
        Matrix result; // 곱셈 결과를 저장할 행렬
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                double sum = 0.0; // 행렬의 원소를 곱한 값을 더할 변수
                for (int k = 0; k < 3; k++)
                {
                    sum += elements[i][k] * m.elements[k][j]; // 행렬의 원소를 곱한 값을 더함
                }
                result.elements[i][j] = sum; // 곱셈 결과를 저장
            }
        }
        return result; // 곱셈 결과를 반환
    }
};

int main()
{
    double arr1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // 3x3 행렬에 값 저장
    double arr2[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} }; // 3x3 행렬에 값 저장

    Matrix m1(arr1); // 3x3 행렬을 생성하고 arr1의 값으로 초기화
    Matrix m2(arr2); // 3x3 행렬을 생성하고 arr2의 값으로 초기화

    cout << "m1:" << endl; // m1 출력
    m1.print(); // m1의 원소 출력
    cout << endl; // 줄 바꿈

    cout << "m2:" << endl; // m2 출력
    m2.print(); // m2의 원소 출력
    cout << endl; // 줄 바꿈

    cout << "m1 += m2:" << endl; // m1 += m2 출력
    m1 += m2; // m1 += m2 연산
    m1.print(); // m1의 원소 출력
    cout << endl; // 줄 바꿈

    cout << "m1 -= m2:" << endl; // m1 -= m2 출력
    m1 -= m2; // m1 -= m2 연산
    m1.print(); // m1의 원소 출력
    cout << endl; // 줄 바꿈

    cout << "m1 * m2:" << endl; // m1 * m2 출력
    m1 = m1 * m2; // m1 * m2 연산
    m1.print(); // m1의 원소 출력
    cout << endl; // 줄 바꿈

    return 0; // 프로그램 종료
}
