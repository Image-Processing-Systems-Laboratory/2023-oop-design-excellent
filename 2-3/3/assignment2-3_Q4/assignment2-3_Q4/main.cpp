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
            // ��� ���� ��� 0���� �ʱ�ȭ
            this->rows = rows;
            this->cols = cols;
            // data�� �ش� ũ�⸸ŭ �����Ҵ�
            this->data = new float* [rows];
            for (int i = 0; i < rows; i++)
                this->data[i] = new float[cols];

            // �����Ҵ��� �迭 0���� �ʱ�ȭ
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
    // ������ ���� ����Լ�
    void Matrix::setData(const int rows, const int cols, float** data) {
        // ���޹��� ��� �� ũ�⸦ ����
        this->setRows(rows);
        this->setCols(cols);
        // ����� �࿭ ũ��� �Ǽ��� 2���� �迭 �����Ҵ�
        this->data = new float* [rows];
        for (int i = 0; i < rows; i++)
            this->data[i] = new float[cols];

        // �����Ҵ��� �迭�� ���޹��� �� ����
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                this->data[i][j] = data[i][j];
    }
    // ��� ����Լ�
    void Matrix::print_all() {
        for (int i = 0; i < this->getRows(); i++) {
            for (int j = 0; j < this->getCols(); j++) {
                cout.width(5);
                cout << this->getElement(i, j) << " ";
            }
            cout << endl;
        }
    }
    // determinant ���� ����Լ�
    float Matrix::determinant() {
        if (this->rows == 1) { // ����� ũ�Ⱑ 1�� ���
            return data[0][0];
        }

        float det = 0;
        for (int j = 0; j < cols; j++) {
            Matrix submatrix(this->rows - 1, this->cols - 1); // �κ� ��� ����
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
            float sign = (j % 2 == 0) ? 1 : -1; // ��ȣ ���
            det += sign * data[0][j] * submatrix.determinant(); // ��� ȣ��
        }

        return det;
    }

    // matrix ���� ���� �Լ�
    Matrix& add(Matrix& r, Matrix& a, Matrix& b) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) + b.getElement(i, j));

        return r;
    }
    // matrix ���� ���� �Լ�
    Matrix& sub(Matrix& r, Matrix& a, Matrix& b) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++)
                r.setElement(i, j, a.getElement(i, j) - b.getElement(i, j));

        return r;
    }
    // matrix ���� ���� �Լ�
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

    // scalar ���� ���� �Լ�
    Matrix& elementAdd(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) + v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar ���� ���� �Լ�
    Matrix& elementSub(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) - v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar ���� ���� �Լ�
    Matrix& elementMul(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) * v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }
    // scalar ������ ���� �Լ�
    Matrix& elementDiv(Matrix& r, Matrix& a, float v) {
        for (int i = 0; i < a.getRows(); i++)
            for (int j = 0; j < a.getCols(); j++) {
                r.setElement(i, j, a.getElement(i, j) / v);
                a.setElement(i, j, r.getElement(i, j));
            }

        return r;
    }

    // matrix ��ġ��� ��ȯ �Լ�
    Matrix& transpose(Matrix& r, Matrix& m) {
        for (int i = 0; i < m.getRows(); i++) {
            for (int j = 0; j < m.getCols(); j++) {
                r.setElement(j, i, m.getElement(i, j));
            }
        }

        return r;
    }
    // ������� ��ȯ �Լ�
    Matrix& adjoint(Matrix& r, Matrix& m) {
        int n = m.getRows();
        // ���� ������ ���� ��� ����
        Matrix temp(n, n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Matrix submatrix(n - 1, n - 1); // �κ� ��� ����
                int temp_row = 0, temp_col = 0;
                for (int k = 0; k < n; k++) { 
                    for (int l = 0; l < n; l++) {
                        if (i == k || j == l) // ���� ��ġ�� �����ϸ� �߰� ���ϰ� �ѱ��
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
                float sign = ((i + j) % 2 == 0) ? 1 : -1; // ��ȣ ���
                temp.setElement(i, j, sign * submatrix.determinant());
            }
        }

        r = transpose(r, temp); // ��ġ��� ���ϱ�
        return r;

    }
    // ����� ���� �Լ�
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

    int max_row, max_col; // ����� �ִ� ũ�� ���� ����

    int command;

    cout << "Enter command (1.matrix operation, 2.scalar operation, else.exit): ";
    cin >> command;

    // matrix operation
    if (command == 1) {
        // ���� ����� ����� �Է� �ޱ�
        cout << "Enter max row and max col: ";
        cin >> max_row >> max_col;
        // �Է¹��� ����� ũ�⸦ ���� �ӽ� ��� �����Ҵ�
        float** temp_mat = new float* [max_row];
        for (int i = 0; i < max_row; i++)
            temp_mat[i] = new float[max_col];
        // �ӽ� ��Ŀ� �� ����
        cout << "Enter matrix input" << endl;
        for (int i = 0; i < max_row; i++)
            for (int j = 0; j < max_col; j++)
                cin >> temp_mat[i][j];

        // ��� ��ü �ΰ� ����
        ooplinalg::Matrix a;
        a.setData(max_row, max_col, temp_mat);    

        // �ӽ� ��� �����Ҵ� ����
        for (int i = 0; i < max_row; i++)
            delete[] temp_mat[i];
        delete[] temp_mat;

        cout << endl;

        while (1) {
            int temp_command;
            cout << "Enter command (1.Addition, 2.Subtraction, 3.Multiplication, 4.Transpose, 5.Determinant, 6.Adjoint, 7.Inverse, else.exit): ";
            cin >> temp_command;

            // ���� ����
            if (temp_command == 1) {
                // ���� ����� ũ�⸦ ���� �ӽ� ��� �����Ҵ�
                float** temp_mat = new float* [max_row];
                for (int i = 0; i < max_row; i++)
                    temp_mat[i] = new float[max_col];
                // �ӽ� ��Ŀ� �� ����
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_row; i++)
                    for (int j = 0; j < max_col; j++)
                        cin >> temp_mat[i][j];
                // �Է¹��� �ӽ� ��� �� ���� ��Ŀ� ����
                ooplinalg::Matrix b;
                b.setData(max_row, max_col, temp_mat);
                ooplinalg::Matrix r(max_row, max_col);

                // ���� ���� ��
                ooplinalg::add(r, a, b);
                r.print_all(); // ���
                cout << endl;

                // �ӽ� ��� �����Ҵ� ����
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;

            }
            // ���� ����
            else if (temp_command == 2) {
                // ���� ����� ũ�⸦ ���� �ӽ� ��� �����Ҵ�
                float** temp_mat = new float* [max_row];
                for (int i = 0; i < max_row; i++)
                    temp_mat[i] = new float[max_col];
                // �ӽ� ��Ŀ� �� ����
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_row; i++)
                    for (int j = 0; j < max_col; j++)
                        cin >> temp_mat[i][j];
                // �Է¹��� �ӽ� ��� �� ���� ��Ŀ� ����
                ooplinalg::Matrix b;
                b.setData(max_row, max_col, temp_mat);
                ooplinalg::Matrix r(max_row, max_col);

                // ���� ����
                ooplinalg::sub(r, a, b);
                r.print_all(); // ���
                cout << endl;

                // �ӽ� ��� �����Ҵ� ����
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;
            }
            // ���� ����
            else if (temp_command == 3) {
                // ���� ����� ũ�⸦ ���� ��� ���� �ٲ� ��� �����Ҵ�
                float** temp_mat = new float* [max_col];
                for (int i = 0; i < max_col; i++)
                    temp_mat[i] = new float[max_row];
                // �ӽ� ��Ŀ� �� ����
                cout << "Enter matrix input" << endl;
                for (int i = 0; i < max_col; i++)
                    for (int j = 0; j < max_row; j++)
                        cin >> temp_mat[i][j];
                // �Է¹��� �ӽ� ��� �� ���� ��Ŀ� ����
                ooplinalg::Matrix b;
                b.setData(max_col, max_row, temp_mat);
                ooplinalg::Matrix r(max_row, max_row);

                // ���� ����
                ooplinalg::mul(r, a, b);
                r.print_all(); // ���
                cout << endl;

                // �ӽ� ��� �����Ҵ� ����
                for (int i = 0; i < max_row; i++)
                    delete[] temp_mat[i];
                delete[] temp_mat;
            }
            // ��ġ��� ���
            else if (temp_command == 4) {
                ooplinalg::Matrix r(max_row, max_col);
                ooplinalg::transpose(r, a);
                r.print_all(); // ���
                cout << endl;
            }
            // determinant ����
            else if (temp_command == 5) {
                if (max_row != max_col) {
                    cout << "It is not square matrix. So cannot calculate determinant" << endl;
                    continue;
                }
                cout << a.determinant() << endl;
            }
            // �������(adjoint) ����
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
            // ����� ����
            else if (temp_command == 7) {                
                if (a.determinant() == 0) {
                    cout << "det = 0. Therefore no inverse matrix" << endl;
                }
                else {
                    ooplinalg::Matrix r(max_row, max_col);
                    ooplinalg::inverse(r, a);
                    r.print_all(); // ���
                    cout << endl;
                }                
            }
            else
                break;
        }
    }
    // scalar operation
    else if (command == 2) {
        // ����� ����� �Է� �ޱ�
        cout << "Enter max row and max col: ";
        cin >> max_row >> max_col;
        // �Է¹��� ����� ũ�⸦ ���� �ӽ� ��� �����Ҵ�
        float** temp_mat = new float* [max_row];
        for (int i = 0; i < max_row; i++)
            temp_mat[i] = new float[max_col];
        // �ӽ� ��Ŀ� �� ����
        cout << "Enter matrix input" << endl;
        for (int i = 0; i < max_row; i++)
            for (int j = 0; j < max_col; j++)
                cin >> temp_mat[i][j];

        // ��� ��ü �ΰ� ����
        ooplinalg::Matrix a;
        a.setData(max_row, max_col, temp_mat);
        ooplinalg::Matrix r(max_row, max_col);
            
        // �ӽ� ��� �����Ҵ� ����
        for (int i = 0; i < max_row; i++)
            delete[] temp_mat[i];
        delete[] temp_mat;

        cout << endl;
            
        while (1) {
            int temp_command;
            // ��Į�� ������ ���� �� ���� �� �Է�
            float temp_num;
            cout << "Enter number: ";
            cin >> temp_num;

            cout << "Enter command (1.Addition, 2.Subtraction, 3.Multiplication, 4.Division, else.exit): ";
            cin >> temp_command;

            if (temp_command == 1) {
                // ���� ���� �� a�� ����
                ooplinalg::elementAdd(r, a, temp_num);
                r.print_all(); // ���
                cout << endl;
            }
            else if (temp_command == 2) {
                // ���� ���� �� a�� ����
                ooplinalg::elementSub(r, a, temp_num);
                r.print_all(); // ���
                cout << endl;
            }
            else if (temp_command == 3) {
                // ���� ���� �� a�� ����
                ooplinalg::elementMul(r, a, temp_num);
                r.print_all(); // ���
                cout << endl;
            }
            else if (temp_command == 4) {
                // ������ ���� �� a�� ����
                ooplinalg::elementDiv(r, a, temp_num);
                r.print_all(); // ���
                cout << endl;
            }
            else 
                break; 
        }
    }
    // ����ó��
    else
        cout << "Unvalid command";

    return 0;
}