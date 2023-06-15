#include <cmath>
#include <iostream>

using namespace std;

namespace ooplinalg {
    class Matrix {
    private:
        float** data;
        int rows;
        int cols;

    public:
        Matrix() {
            this->data = NULL;
            this->rows = 0;
            this->cols = 0;
        }
        //Matrix(const Matrix& mat);
        Matrix(int rows, int cols) {
            // 행과 열을 모두 0으로 초기화
            this->rows = rows;
            this->cols = cols;
            // data를 해당 크기만큼 동적할당
            this->data = new float* [rows];
            for (int i = 0; i < rows; i++)
                this->data[i] = new float[cols];

            // 동적할당한 배열 0으로 초기화
            for (int i = 0; i < rows; i++)
                for (int j = 0; j < cols; j++)
                    this->data[i][j] = 0;
        }
        ~Matrix() {
            for (int i = 0; i < this->getRows(); i++)
                delete[] this->data[i];
            delete[] this->data;
        }

        float getElement(int row, int col) const { return this->data[row][col]; }
        float** getData() const { return this->data; }
        void setElement(const int row, const int col, float value) { this->data[row][col] = value; }
        void setData(const int rows, const int cols, float** data);
        int getRows() const { return this->rows; }
        int getCols() const { return this->cols; }
        void setRows(const int rows) { this->rows = rows; }
        void setCols(const int cols) { this->cols = cols; }

        void print_all();

        float determinant();
    };
    // 데이터 저장 멤버함수
    void Matrix::setData(const int rows, const int cols, float** data) {
        // 전달받은 행과 열 크기를 저장
        this->setRows(rows);
        this->setCols(cols);
        // 저장된 행열 크기로 실수형 2차원 배열 동적할당
        this->data = new float* [rows];
        for (int i = 0; i < rows; i++)
            this->data[i] = new float[cols];

        // 동적할당한 배열에 전달받은 값 저장
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->data[i][j] = data[i][j];
    }
    // 출력 멤버함수
    void Matrix::print_all() {
        for (int i = 0; i < this->getRows(); i++) {
            for (int j = 0; j < this->getCols(); j++) {
                cout.width(5);
                cout << this->getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
    // determinant 연산 멤버함수
    float Matrix::determinant() {
        if (this->rows == 1) { // 행렬의 크기가 1인 경우
            return data[0][0];
        }

        float det = 0;
        for (int j = 0; j < cols; j++) {
            Matrix submatrix(this->rows - 1, this->cols - 1); // 부분 행렬 생성
            for (int i = 1; i < this->rows; i++) {
                for (int k = 0; k < cols; k++) {
                    if (k < j) {
                        submatrix.setElement(i - 1, k, data[i][k]);
                    }
                    else if (k > j) {
                        submatrix.setElement(i - 1, k - 1, data[i][k]);
                    }
                }
            }
            float sign = (j % 2 == 0) ? 1 : -1; // 부호 계산
            det += sign * data[0][j] * submatrix.determinant(); // 재귀 호출
        }

        return det;
    }

    // matrix 덧셈 연산 함수
    Matrix& add(Matrix& r, Matrix& a, Matrix& b) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));

        return r;
    }
    // matrix 뺄셈 연산 함수
    Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));

        return r;
    }
    // matrix 곱셈 연산 함수
    Matrix& mul(Matrix& r, Matrix& a, Matrix& b) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < b.getCols(); j++) {
                float sum = 0;
                for (int k = 0; k < a.getCols(); k++)
                    sum += a.getElement(i, k) * b.getElement(k, j);
                r.setElement(i, j, sum);
            }

        return r;
    }

    // scalar 덧셈 연산 함수
    Matrix& elementAdd(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) + v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar 뺄셈 연산 함수
    Matrix& elementSub(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) - v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar 곱셈 연산 함수
    Matrix& elementMul(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) * v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar 나눗셈 연산 함수
    Matrix& elementDiv(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) / v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }

    // matrix 전치행렬 변환 함수
    Matrix& transpose(Matrix& r, Matrix& m) {
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                r.setElement(j, i, m.getElement(i, j));
            }
        }

        return r;
    }
    // 수반행렬 변환 함수
    Matrix& adjoint(Matrix& r, Matrix& m) {
        int n = m.getRows();
        // 값을 저장할 저장 행렬 생성
        Matrix temp(n, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Matrix submatrix(n - 1, n - 1); // 부분 행렬 생성
                int temp_row = 0, temp_col = 0;
                for (int k = 0; k < n; k++) { 
                    for (int l = 0; l < n; l++) {
                        if (i == k || j == l) // 같은 위치에 존재하면 추가 안하고 넘기기
                            continue;
                        else if (temp_col < n - 1) {
                            submatrix.setElement(temp_row, temp_col++, m.getElement(k, l));
                        }
                        else {
                            temp_col = 0;
                            submatrix.setElement(++temp_row, temp_col++, m.getElement(k, l));
                        }
                    }
                }
                float sign = ((i + j) % 2 == 0) ? 1 : -1; // 부호 계산
                temp.setElement(i, j, sign * submatrix.determinant());
            }
        }

        r = transpose(r, temp); // 전치행렬 구하기
        return r;

    }
    // 역행렬 연산 함수
    Matrix& inverse(Matrix& r, Matrix& m) {
        int n = m.getCols();
        float det = m.determinant();
        r = adjoint(r, m);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                r.setElement(i, j, r.getElement(i, j) / det);
            }
        }
        
        return r;
    }
}


int main() {

    int max_row, max_col; // 행렬의 최대 크기 저장 변수

    int command;

    cout << "Enter command (1.matrix operation, 2.scalar operation, else.exit): ";
    cin >> command;

    // matrix operation
    if (command == 1) {
        // 기준 행렬의 사이즈를 입력 받기
        cout << "Enter max row and max col: ";
        cin >> max_row >> max_col;
        // 입력받은 행렬의 크기를 토대로 임시 행렬 동적할당
        float** temp_mat = new float* [max_row];
        for (int i = 0; i < max_row; i++)
            temp_mat[i] = new float[max_col];
        // 임시 행렬에 값 저장
        cout << "Enter matrix input" << endl;
        for (int i = 0; i < max_row; i++)
            for (int j = 0; j < max_col; j++)
                cin >> temp_mat[i][j];

        // 행렬 객체 두개 생성
        ooplinalg::Matrix a;
        a.setData(max_row, max_col, temp_mat);    

        // 임시 행렬 동적할당 해제
        for (int i = 0; i < max_row; i++)
            delete[] temp_mat[i];
        delete[] temp_mat;

        cout << endl;

        while (1) {
            int temp_command;
            cout << "Enter command (1.Addition, 2.Subtraction, 3.Multiplication, 4.Transpose, 5.Determinant, 6.Adjoint, 7.Inverse, else.exit): ";
            cin >> temp_command;

            // 덧셈 연산
            if (temp_command == 1) {
                // 기준 행렬의 크기를 토대로 임시 행렬 동적할당
                float** temp_mat = new float* [max_row];
                for (int i = 0; i < max_row; i++)
                    temp_mat[i] = new float[max_col];
                // 임시 행렬에 값 저장
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_row; i++)
                    for (int j = 0; j < max_col; j++)
                        cin >> temp_mat[i][j];
                // 입력받은 임시 행렬 값 연산 행렬에 저장
                ooplinalg::Matrix b;
                b.setData(max_row, max_col, temp_mat);
                ooplinalg::Matrix r(max_row, max_col);

                // 덧셈 연산 후
                ooplinalg::add(r, a, b);
                r.print_all(); // 출력
                cout << endl;

                // 임시 행렬 동적할당 해제
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;

            }
            // 뺄셈 연산
            else if (temp_command == 2) {
                // 기준 행렬의 크기를 토대로 임시 행렬 동적할당
                float** temp_mat = new float* [max_row];
                for (int i = 0; i < max_row; i++)
                    temp_mat[i] = new float[max_col];
                // 임시 행렬에 값 저장
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_row; i++)
                    for (int j = 0; j < max_col; j++)
                        cin >> temp_mat[i][j];
                // 입력받은 임시 행렬 값 연산 행렬에 저장
                ooplinalg::Matrix b;
                b.setData(max_row, max_col, temp_mat);
                ooplinalg::Matrix r(max_row, max_col);

                // 뺄셈 연산
                ooplinalg::sub(r, a, b);
                r.print_all(); // 출력
                cout << endl;

                // 임시 행렬 동적할당 해제
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;
            }
            // 곱셈 연산
            else if (temp_command == 3) {
                // 기준 행렬의 크기를 토대로 행과 열이 바뀐 행렬 동적할당
                float** temp_mat = new float* [max_col];
                for (int i = 0; i < max_col; i++)
                    temp_mat[i] = new float[max_row];
                // 임시 행렬에 값 저장
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_col; i++)
                    for (int j = 0; j < max_row; j++)
                        cin >> temp_mat[i][j];
                // 입력받은 임시 행렬 값 연산 행렬에 저장
                ooplinalg::Matrix b;
                b.setData(max_col, max_row, temp_mat);
                ooplinalg::Matrix r(max_row, max_row);

                // 곱셈 연산
                ooplinalg::mul(r, a, b);
                r.print_all(); // 출력
                cout << endl;

                // 임시 행렬 동적할당 해제
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;
            }
            // 전치행렬 출력
            else if (temp_command == 4) {
                ooplinalg::Matrix r(max_row, max_col);
                ooplinalg::transpose(r, a);
                r.print_all(); // 출력
                cout << endl;
            }
            // determinant 연산
            else if (temp_command == 5) {
                if (max_row != max_col) {
                    cout << "It is not square matrix. So cannot calculate determinant" << endl;
                    continue;
                }
                cout << a.determinant() << endl;
            }
            // 수반행렬(adjoint) 연산
            else if (temp_command == 6) {                
                if (max_row != max_col) {
                    cout << "It is not square matrix. So cannot calculate adjoint matrix" << endl;
                    continue;
                }
                ooplinalg::Matrix r(max_row, max_col);
                ooplinalg::adjoint(r, a);
                r.print_all();
                cout << endl;
            }
            // 역행렬 연산
            else if (temp_command == 7) {                
                if (a.determinant() == 0) {
                    cout << "det = 0. Therefore no inverse matrix" << endl;
                }
                else {
                    ooplinalg::Matrix r(max_row, max_col);
                    ooplinalg::inverse(r, a);
                    r.print_all(); // 출력
                    cout << endl;
                }                
            }
            else
                break;
        }
    }
    // scalar operation
    else if (command == 2) {
        // 행렬의 사이즈를 입력 받기
        cout << "Enter max row and max col: ";
        cin >> max_row >> max_col;
        // 입력받은 행렬의 크기를 토대로 임시 행렬 동적할당
        float** temp_mat = new float* [max_row];
        for (int i = 0; i < max_row; i++)
            temp_mat[i] = new float[max_col];
        // 임시 행렬에 값 저장
        cout << "Enter matrix input" << endl;
        for (int i = 0; i < max_row; i++)
            for (int j = 0; j < max_col; j++)
                cin >> temp_mat[i][j];

        // 행렬 객체 두개 생성
        ooplinalg::Matrix a;
        a.setData(max_row, max_col, temp_mat);
        ooplinalg::Matrix r(max_row, max_col);
            
        // 임시 행렬 동적할당 해제
        for (int i = 0; i < max_row; i++)
            delete[] temp_mat[i];
        delete[] temp_mat;

        cout << endl;
            
        while (1) {
            int temp_command;
            // 스칼라 연산을 위한 값 선언 및 입력
            float temp_num;
            cout << "Enter number: ";
            cin >> temp_num;

            cout << "Enter command (1.Addition, 2.Subtraction, 3.Multiplication, 4.Division, else.exit): ";
            cin >> temp_command;

            if (temp_command == 1) {
                // 덧삼 연산 후 a에 저장
                ooplinalg::elementAdd(r, a, temp_num);
                r.print_all(); // 출력
                cout << endl;
            }
            else if (temp_command == 2) {
                // 뺄셈 연산 후 a에 저장
                ooplinalg::elementSub(r, a, temp_num);
                r.print_all(); // 출력
                cout << endl;
            }
            else if (temp_command == 3) {
                // 곱셈 연산 후 a에 저장
                ooplinalg::elementMul(r, a, temp_num);
                r.print_all(); // 출력
                cout << endl;
            }
            else if (temp_command == 4) {
                // 나눗셈 연산 후 a에 저장
                ooplinalg::elementDiv(r, a, temp_num);
                r.print_all(); // 출력
                cout << endl;
            }
            else 
                break; 
        }
    }
    // 예외처리
    else
        cout << "Unvalid command";

    return 0;
}