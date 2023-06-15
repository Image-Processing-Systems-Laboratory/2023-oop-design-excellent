#include <iostream>
using namespace std;

class Matrix  // matrix Ŭ������ ����
{
private: // private ��� ���� ����
    double elements[3][3]; // 3x3 ����� ������ �迭

public: // public ��� �Լ� ����
    Matrix(double val = 0.0) // ������
    {
        // 3x3 ����� �� ���Ҹ� �ʱⰪ 0.0���� �ʱ�ȭ
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = val;
            }
        }
    }

    Matrix(double arr[3][3]) // ������
    {
        // 3x3 ����� �� ���Ҹ� �迭 arr�� ������ �ʱ�ȭ
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = arr[i][j];
            }
        }
    }

    void print() // ����� ���Ҹ� ����ϴ� �Լ�
    {
        // ����� �� ���Ҹ� ���
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << elements[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+=(const Matrix& m) // ����� ���� ������
    {
        // ����� �� ���Ҹ� ����
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] += m.elements[i][j];
            }
        }
        return *this; // ���� ����� ��ȯ
    }

    Matrix operator-=(const Matrix& m) // ����� ���� ������
    {
        // ����� �� ���Ҹ� ��
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                elements[i][j] = elements[i][j] - m.elements[i][j];
            }
        }
        return *this; // ���� ����� ��ȯ
    }

    Matrix operator*(const Matrix& m) // ����� ���� ������
    {
        Matrix result; // ���� ����� ������ ���
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                double sum = 0.0; // ����� ���Ҹ� ���� ���� ���� ����
                for (int k = 0; k < 3; k++)
                {
                    sum += elements[i][k] * m.elements[k][j]; // ����� ���Ҹ� ���� ���� ����
                }
                result.elements[i][j] = sum; // ���� ����� ����
            }
        }
        return result; // ���� ����� ��ȯ
    }
};

int main()
{
    double arr1[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} }; // 3x3 ��Ŀ� �� ����
    double arr2[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} }; // 3x3 ��Ŀ� �� ����

    Matrix m1(arr1); // 3x3 ����� �����ϰ� arr1�� ������ �ʱ�ȭ
    Matrix m2(arr2); // 3x3 ����� �����ϰ� arr2�� ������ �ʱ�ȭ

    cout << "m1:" << endl; // m1 ���
    m1.print(); // m1�� ���� ���
    cout << endl; // �� �ٲ�

    cout << "m2:" << endl; // m2 ���
    m2.print(); // m2�� ���� ���
    cout << endl; // �� �ٲ�

    cout << "m1 += m2:" << endl; // m1 += m2 ���
    m1 += m2; // m1 += m2 ����
    m1.print(); // m1�� ���� ���
    cout << endl; // �� �ٲ�

    cout << "m1 -= m2:" << endl; // m1 -= m2 ���
    m1 -= m2; // m1 -= m2 ����
    m1.print(); // m1�� ���� ���
    cout << endl; // �� �ٲ�

    cout << "m1 * m2:" << endl; // m1 * m2 ���
    m1 = m1 * m2; // m1 * m2 ����
    m1.print(); // m1�� ���� ���
    cout << endl; // �� �ٲ�

    return 0; // ���α׷� ����
}
