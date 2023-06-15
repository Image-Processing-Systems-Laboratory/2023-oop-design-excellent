#include <iostream>
using namespace std;
class Matrix
{
private:
    double matrix[3][3];

public:
    Matrix() // 빈 생성자
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] = 0.0; // 0으로 초기화
    }

    Matrix(double arr[3][3]) // 입력받은 행렬
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] = arr[i][j]; // 입력받은 행렬로 초기화
    }

    ~Matrix()
    {

    }

    void print() const // 행렬 출력
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << matrix[i][j] << " ";          
            cout << endl;
        }
    }

    Matrix& operator+=(const Matrix& Other) // += 연산자 오버로딩
    {
        for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
                matrix[i][j] += Other.matrix[i][j]; // 더하기 연산자                
        return *this;
    }

    Matrix& operator-=(const Matrix& Other) // -= 연산자 오버로딩 
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] -= Other.matrix[i][j]; // 빼기 연산자                   
        return *this;
    }

    Matrix operator*(const Matrix& Other) const // * 연산자 오버로딩
    {
        Matrix result;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    result.matrix[i][j] += matrix[i][k] * Other.matrix[k][j]; ;             
        return result;
    }
};

int main() 
{
    int i, j;
    double matrix1[3][3]; // 두 행렬 선언
    double matrix2[3][3];
    cout << "Matrix 1 information : " << endl; // 두 행렬 입력
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> matrix1[i][j];
    cout << "Matrix 2 information : " << endl;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            cin >> matrix2[i][j];

    Matrix Matrix1(matrix1);
    Matrix Matrix2(matrix2);

    cout << "Matrix 1" << endl;
    Matrix1.print(); // 입력 받은 행렬 출력
    cout << "Matrix 2" << endl;
    Matrix2.print(); // 입력 받은 행렬 출력

    cout << "Sum of Matrix " << endl;
    Matrix1 += Matrix2; // 두 행렬 합
    Matrix1.print(); // 결과 출력

    cout << "Sub of Matrix" << endl;
    Matrix1 -= Matrix2; // 두 행렬 차
    Matrix1.print(); // 결과 출력

    cout << "Product of Matrix" << endl;
    Matrix Result = Matrix1 * Matrix2; // 두 행렬 곱
    Result.print(); // 결과 출력

    return 0;
}
