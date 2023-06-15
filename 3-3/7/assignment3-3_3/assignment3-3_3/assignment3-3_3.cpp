#include <iostream>
using namespace std;
class Matrix
{
private:
    double matrix[3][3];

public:
    Matrix() // �� ������
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] = 0.0; // 0���� �ʱ�ȭ
    }

    Matrix(double arr[3][3]) // �Է¹��� ���
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] = arr[i][j]; // �Է¹��� ��ķ� �ʱ�ȭ
    }

    ~Matrix()
    {

    }

    void print() const // ��� ���
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                cout << matrix[i][j] << " ";          
            cout << endl;
        }
    }

    Matrix& operator+=(const Matrix& Other) // += ������ �����ε�
    {
        for (int i = 0; i < 3; i++)
           for (int j = 0; j < 3; j++)
                matrix[i][j] += Other.matrix[i][j]; // ���ϱ� ������                
        return *this;
    }

    Matrix& operator-=(const Matrix& Other) // -= ������ �����ε� 
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                matrix[i][j] -= Other.matrix[i][j]; // ���� ������                   
        return *this;
    }

    Matrix operator*(const Matrix& Other) const // * ������ �����ε�
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
    double matrix1[3][3]; // �� ��� ����
    double matrix2[3][3];
    cout << "Matrix 1 information : " << endl; // �� ��� �Է�
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
    Matrix1.print(); // �Է� ���� ��� ���
    cout << "Matrix 2" << endl;
    Matrix2.print(); // �Է� ���� ��� ���

    cout << "Sum of Matrix " << endl;
    Matrix1 += Matrix2; // �� ��� ��
    Matrix1.print(); // ��� ���

    cout << "Sub of Matrix" << endl;
    Matrix1 -= Matrix2; // �� ��� ��
    Matrix1.print(); // ��� ���

    cout << "Product of Matrix" << endl;
    Matrix Result = Matrix1 * Matrix2; // �� ��� ��
    Result.print(); // ��� ���

    return 0;
}
