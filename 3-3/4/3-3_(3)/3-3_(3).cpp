#include <iostream>

using namespace std;

class Matrix {
private:
    double elements[3][3];

public:
    Matrix(double value = 0.0);
    void print();
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix operator*(const Matrix& other);
};

// Matrix 생성자, 초기화
Matrix::Matrix(double value) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // 입력 받은 값으로 matrix 초기화
            elements[i][j] = value;
        }
    }
}

// matrix 출력해주는 print 함수
void Matrix::print() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << elements[i][j] << ' ';
        }
        cout << endl;
    }
}

// 두 matrix를 더해주는 operator += 함수
Matrix& Matrix::operator+=(const Matrix& other) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            elements[i][j] += other.elements[i][j];
        }
    }

    return *this;
}

// 두 matrix를 빼주는 operator -= 함수
Matrix& Matrix::operator-=(const Matrix& other) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            elements[i][j] -= other.elements[i][j];
        }
    };

    return *this;
}

// 두 matrix를 곱해주는 operator *= 함수
Matrix Matrix::operator*(const Matrix& other) {
    Matrix result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // 곱해준 행렬을 저장해줄 result matrix
            result.elements[i][j] = 0;
            for (int k = 0; k < 3; ++k)
                result.elements[i][j] +=
                this->elements[i][k] * other.elements[k][j];
        }
    }
    return result;
}

int main() {
    Matrix m1(1.0), m2(2.0);
    // m1 matrix 출력
    cout << "Matrix m1:" << endl;
    m1.print();
    // m2 matrix 출력
    cout << "Matrix m2:" << endl;
    m2.print();
    // m1 + m2 한 matrix 출력
    m1 += m2;
    cout << "Matrix 1 += Matrix 2:" << endl;
    m1.print();
    // m1 - m2 한 matrix 출력
    m1 -= m2;
    cout << "Matrix 1 -= Matrix 2:" << endl;
    m1.print();
    // m1 * m2 한 matrix m3 출력
    Matrix m3 = m1 * m2;
    cout << "Matrix 1 * Matrix 2:" << endl;
    m3.print();

    return 0;
}
