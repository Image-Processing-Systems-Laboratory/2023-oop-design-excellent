#include <iostream>

using namespace std;

class Matrix {
private:
    double data[3][3];

public:
    // 초기화가 없는 생성자
    Matrix() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = 0.0;
            }
        }
    }

    // 초기화가 있는 생성자
    Matrix(double arr[3][3]) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                data[i][j] = arr[i][j];
            }
        }
    }

    // Print 함수
    void print() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    // Overload += operator 
    Matrix& operator+=(const Matrix& other) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                this->data[i][j] += other.data[i][j];
            }
        }
        return *this;
    }

    // Overload -= operator
    Matrix& operator-=(const Matrix& other) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                this->data[i][j] -= other.data[i][j];
            }
        }
        return *this;
    }

    // Overload * operator 
    Matrix operator*(const Matrix& other) {
        Matrix result;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < 3; ++k) {
                    result.data[i][j] += this->data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }
    Matrix copy() {
        Matrix copy;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                copy.data[i][j] = this->data[i][j];
            }
        }
        return copy;
    }
};
int main() {
    double arr1[3][3];
    double arr2[3][3];

    cout << "Enter the elements of the first 3x3 matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter the elements of the second 3x3 matrix:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> arr2[i][j];
        }
    }

    Matrix m1(arr1), m2(arr2);

    Matrix m1_for_add = m1.copy();
    m1_for_add += m2; 
    cout << "Result of addition:\n";
    m1_for_add.print();

    Matrix m1_for_subtract = m1.copy();
    m1_for_subtract -= m2;
    cout << "Result of subtraction:\n";
    m1_for_subtract.print();

    Matrix m3 = m1 * m2; 
    cout << "Result of multiplication:\n";
    m3.print();

    return 0;
}
