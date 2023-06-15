#include "Matrix.h"
#include<iostream>


Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}
Matrix::Matrix(const Matrix& mat): Matrix(mat.rows, mat.cols) {     // ��� ����
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++) {
            data[i][j] = mat.data[i][j];
        }
    }

}
Matrix::Matrix(int rows, int cols): data(nullptr), rows(rows), cols(cols) {
    create_2d(*this, rows, cols);
}
Matrix::~Matrix() {
    delete_2d(*this);
}

float** create_2d(Matrix& a, int rows, int cols) {		// ���� �Ҵ� �� 0���� �ʱ�ȭ
    a.data = new float* [rows];
    for (size_t i = 0; i < rows; i++) {
        a.data[i] = new float[cols];
    }
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            a.data[i][j] = 0;
    }
    a.rows = rows;
    a.cols = cols;
    return a.data;
}

void delete_2d(Matrix& a) {		// �޸� ����
    for (size_t i = 0; i < a.rows; i++) {
        delete[] a.data[i];
    }
    delete a.data;
    return;
}

float* Matrix::operator[](size_t num) {     // �ε��� ����
    return data[num];
}

void Matrix::print() {                      // ���� ���
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}



float Matrix::getElement(int row, int col)  // �޼��� ����
{
    return data[row][col];
}


float** Matrix::getData()
{
    return data;
}


void Matrix::setElement(const int row, const int col, float value)
{
    data[row][col] = value;
}


void Matrix::setData(const int rows, const int cols, float** data)      // ��� ũ�� ���� �� �ʱ�ȭ
{
    if (this->data != nullptr) {
        delete_2d(*this);
    }
    create_2d(*this, rows, cols);
}


int Matrix::getRows()
{
    return rows;
}


int Matrix::getCols()
{
    return cols;
}


void Matrix::setRows(const int rows)        // �� ���� �� �ʱ�ȭ
{
    if(data != nullptr)
        delete_2d(*this);
    create_2d(*this, rows, cols);
    return;
}


void Matrix::setCols(const int cols)        // �� ���� �� �ʱ�ȭ
{
    if (data != nullptr)
        delete_2d(*this);
    create_2d(*this, rows, cols);
    return;
}


float Matrix::determinant()
{
    if (rows != cols) {     // ���� ó��
        std::cout << "��������� �ƴմϴ�. ��" << std::endl;
        this->print();
        return 0.0f;
    }
    Matrix temp(*this);     // �ҰŸ� ������ �ӽ� ���
    // ���콺 �ҰŹ� ����   (��Ľ��� ������ �ʴ´�)
    float det = 1.0;
    for (int i = 0; i < rows - 1; i++) {
        if (temp.data[i][i] == 0) {  // �밢�� ���Ұ� 0�̸� �� ��ȯ�� ���� 0�� �ƴ� �밢�� ���� ã��
            for (int j = i + 1; j < rows; j++) {
                if (temp.data[j][i] != 0) {
                    // �� ��ȯ
                    for (int k = i; k < cols; k++) {
                        float asd = temp.data[i][k];
                        temp.data[i][k] = temp.data[j][k];
                        temp.data[j][k] = asd;
                    }

                    det *= -1;  // �� ��ȯ���� ��ȣ�� �ٲ�
                    break;
                }
            }
            if (temp.data[i][i] == 0) {  // �밢�� ���Ұ� ������ 0�̸� ��� �ߴ�
                return 0.0f;
            }
        }

        for (int j = i + 1; j < rows; j++) {
            float coef = temp.data[j][i] / temp.data[i][i];
            for (int k = i + 1; k < rows; k++) {
                temp.data[j][k] -= coef * temp.data[i][k];
            }
        }
    }

    for (int i = 0; i < rows; i++) {        // �ﰢ ����� ��Ľ��� �밢������ ��
        det *= temp.data[i][i];
    }

    return det;
}

// ��� ����
Matrix& add(Matrix& r, Matrix& a, Matrix& b) {
    if (a.getRows() != b.getRows()) {       // ���� ó��
        std::cout << "����� ũ�Ⱑ �ٸ��ϴ�." << std::endl;
        return r;
    }
    if (a.getCols() != b.getCols()) {
        std::cout << "����� ũ�Ⱑ �ٸ��ϴ�." << std::endl;
        return r;
    }
    
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] + b[i][j];        // +
    }
        return r;
}
Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {
    if (a.getRows() != b.getRows()) {       // ���� ó��
        std::cout << "����� ũ�Ⱑ �ٸ��ϴ�." << std::endl;
        return r;
    }
    if (a.getCols() != b.getCols()) {
        std::cout << "����� ũ�Ⱑ �ٸ��ϴ�." << std::endl;
        return r;
    }

    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] - b[i][j];        // -
    }
    return r;
}
Matrix& mul(Matrix& r, Matrix& a, Matrix& b) {
    if (a.getCols() != b.getRows()) {       // ���� ó��
        std::cout << "����� ���� �������� �ʽ��ϴ�." << std::endl;
        return r;
    }

    r.setData(a.getRows(), b.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < b.getCols(); j++) {
            float sum = 0;
            for (size_t k = 0; k < a.getCols(); k++) {
                sum += a[i][k] * b[k][j];       // ���� * ����
            }
            r[i][j] = sum;
        }
    }
    return r;
}

// ��Į�� ����
Matrix& elementAdd(Matrix& r, Matrix& a, float v) {
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] + v;      // �̺κи� �ٲ�� +
    }
    return r;
}
Matrix& elementSub(Matrix& r, Matrix& a, float v) {
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] - v;      // -
    }
    return r;
}
Matrix& elementMul(Matrix& r, Matrix& a, float v) {
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] * v;      // *
    }
    return r;
}
Matrix& elementDiv(Matrix& r, Matrix& a, float v) {
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] / v;      // /
    }
    return r;
}

Matrix& transpose(Matrix& r, Matrix& m) {
    r.setData(m.getCols(), m.getRows(), nullptr);       // ��� ���� ũ�⸦ ���� �ٲ�
    for (size_t i = 0; i < m.getRows(); i++) {
        for (size_t j = 0; j < m.getCols(); j++)
            r[j][i] = m[i][j];      //  ��� �� �ε����� ���� �ٲ� ���Ҵ�
    }
    return r;
}
// cofactor matrix�� ���ϴ� �Լ�
Matrix cofactor(Matrix& m, size_t row, size_t col) {
    Matrix result;
    result.setData(m.getRows() - 1, m.getCols() - 1, nullptr);
    for (size_t i = 0, ii = 0; i < m.getRows(); ++i) {
        if (i == row) continue;
        for (size_t j = 0, jj = 0; j < m.getCols(); ++j) {
            if (j == col) continue;
            result[ii][jj] = m[i][j];
            ++jj;
        }
        ++ii;
    }
    return result;
}

// ���μ� ��꿡 ���� ��Ľ� ���� �Լ�
float det(Matrix& m) {      // ���ڸ� �ּ�ȭ�� �Լ�
    if (m.getRows() != m.getCols()) {
        return 0.0f;
    }

    const size_t size = m.getRows();
    if (size == 1) {        // special case 1
        return m[0][0];
    }
    else if (size == 2) {
        return m[0][0] * m[1][1] - m[0][1] * m[1][0];       // special case 2
    }

    float result = 0.0f;
    for (size_t j = 0; j < size; ++j) {
        Matrix minor = cofactor(m, 0, j);       // ���
        float sign = j % 2 == 0 ? 1.0f : -1.0f; // ��ȣ ����
        result += sign * m[0][j] * det(minor);
    }

    return result;
}

// adjoint �Լ�
Matrix& adjoint(Matrix& r, Matrix& m){
    r.setData(m.getRows(), m.getCols(), nullptr);
    for (size_t i = 0; i < m.getRows(); ++i) {
        for (size_t j = 0; j < m.getCols(); ++j) {
            Matrix minor = cofactor(m, i, j);
            float sign = (i + j) % 2 == 0 ? 1.0f : -1.0f;
            r[j][i] = sign * det(minor);            // ���μ� ����� ��ġ, ������ ����ȭ�� ���� transfose�� ������� ����
        }
    }
    return r;
}

Matrix& inverse(Matrix& r, Matrix& m) {
    float d = det(m);
    if (d == 0) {
        std::cout << "������� �������� �ʽ��ϴ�." << std::endl;
        return r;
    }
    Matrix temp;
    adjoint(temp, m);       // ���� ���
    elementDiv(r, temp, d);    // ��Ľİ����� ������
    return r;
}