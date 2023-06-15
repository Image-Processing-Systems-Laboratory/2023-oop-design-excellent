#include "Matrix.h"
#include<iostream>


Matrix::Matrix() : data(nullptr), rows(0), cols(0) {}
Matrix::Matrix(const Matrix& mat): Matrix(mat.rows, mat.cols) {     // 요소 복사
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

float** create_2d(Matrix& a, int rows, int cols) {		// 동적 할당 및 0으로 초기화
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

void delete_2d(Matrix& a) {		// 메모리 해제
    for (size_t i = 0; i < a.rows; i++) {
        delete[] a.data[i];
    }
    delete a.data;
    return;
}

float* Matrix::operator[](size_t num) {     // 인덱스 접근
    return data[num];
}

void Matrix::print() {                      // 원소 출력
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < cols; j++)
            std::cout << data[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}



float Matrix::getElement(int row, int col)  // 메서드 접근
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


void Matrix::setData(const int rows, const int cols, float** data)      // 행렬 크기 조정 및 초기화
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


void Matrix::setRows(const int rows)        // 행 조절 및 초기화
{
    if(data != nullptr)
        delete_2d(*this);
    create_2d(*this, rows, cols);
    return;
}


void Matrix::setCols(const int cols)        // 열 조절 및 초기화
{
    if (data != nullptr)
        delete_2d(*this);
    create_2d(*this, rows, cols);
    return;
}


float Matrix::determinant()
{
    if (rows != cols) {     // 예외 처리
        std::cout << "정방행렬이 아닙니다. ↓" << std::endl;
        this->print();
        return 0.0f;
    }
    Matrix temp(*this);     // 소거를 진행할 임시 행렬
    // 가우스 소거법 적용   (행렬식은 변하지 않는다)
    float det = 1.0;
    for (int i = 0; i < rows - 1; i++) {
        if (temp.data[i][i] == 0) {  // 대각선 원소가 0이면 행 교환을 통해 0이 아닌 대각선 원소 찾기
            for (int j = i + 1; j < rows; j++) {
                if (temp.data[j][i] != 0) {
                    // 행 교환
                    for (int k = i; k < cols; k++) {
                        float asd = temp.data[i][k];
                        temp.data[i][k] = temp.data[j][k];
                        temp.data[j][k] = asd;
                    }

                    det *= -1;  // 행 교환으로 부호가 바뀜
                    break;
                }
            }
            if (temp.data[i][i] == 0) {  // 대각선 원소가 여전히 0이면 계산 중단
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

    for (int i = 0; i < rows; i++) {        // 삼각 행렬의 행렬식은 대각성분의 곱
        det *= temp.data[i][i];
    }

    return det;
}

// 행렬 연산
Matrix& add(Matrix& r, Matrix& a, Matrix& b) {
    if (a.getRows() != b.getRows()) {       // 예외 처리
        std::cout << "행렬의 크기가 다릅니다." << std::endl;
        return r;
    }
    if (a.getCols() != b.getCols()) {
        std::cout << "행렬의 크기가 다릅니다." << std::endl;
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
    if (a.getRows() != b.getRows()) {       // 예외 처리
        std::cout << "행렬의 크기가 다릅니다." << std::endl;
        return r;
    }
    if (a.getCols() != b.getCols()) {
        std::cout << "행렬의 크기가 다릅니다." << std::endl;
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
    if (a.getCols() != b.getRows()) {       // 예외 처리
        std::cout << "행렬의 곱이 성립하지 않습니다." << std::endl;
        return r;
    }

    r.setData(a.getRows(), b.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < b.getCols(); j++) {
            float sum = 0;
            for (size_t k = 0; k < a.getCols(); k++) {
                sum += a[i][k] * b[k][j];       // 가로 * 세로
            }
            r[i][j] = sum;
        }
    }
    return r;
}

// 스칼라 연산
Matrix& elementAdd(Matrix& r, Matrix& a, float v) {
    r.setData(a.getRows(), a.getCols(), nullptr);
    for (size_t i = 0; i < a.getRows(); i++) {
        for (size_t j = 0; j < a.getCols(); j++)
            r[i][j] = a[i][j] + v;      // 이부분만 바뀐다 +
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
    r.setData(m.getCols(), m.getRows(), nullptr);       // 행과 열의 크기를 서로 바꿈
    for (size_t i = 0; i < m.getRows(); i++) {
        for (size_t j = 0; j < m.getCols(); j++)
            r[j][i] = m[i][j];      //  행과 열 인덱스를 서로 바꿔 재할당
    }
    return r;
}
// cofactor matrix를 구하는 함수
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

// 여인수 계산에 쓰일 행렬식 보조 함수
float det(Matrix& m) {      // 인자를 최소화한 함수
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
        Matrix minor = cofactor(m, 0, j);       // 재귀
        float sign = j % 2 == 0 ? 1.0f : -1.0f; // 부호 결정
        result += sign * m[0][j] * det(minor);
    }

    return result;
}

// adjoint 함수
Matrix& adjoint(Matrix& r, Matrix& m){
    r.setData(m.getRows(), m.getCols(), nullptr);
    for (size_t i = 0; i < m.getRows(); ++i) {
        for (size_t j = 0; j < m.getCols(); ++j) {
            Matrix minor = cofactor(m, i, j);
            float sign = (i + j) % 2 == 0 ? 1.0f : -1.0f;
            r[j][i] = sign * det(minor);            // 여인수 행렬의 전치, 연산의 최적화를 위해 transfose를 사용하지 않음
        }
    }
    return r;
}

Matrix& inverse(Matrix& r, Matrix& m) {
    float d = det(m);
    if (d == 0) {
        std::cout << "역행렬이 존재하지 않습니다." << std::endl;
        return r;
    }
    Matrix temp;
    adjoint(temp, m);       // 수반 행렬
    elementDiv(r, temp, d);    // 행렬식값으로 나누기
    return r;
}