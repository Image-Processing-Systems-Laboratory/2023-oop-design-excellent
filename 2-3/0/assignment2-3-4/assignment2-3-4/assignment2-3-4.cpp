#include <iostream>
#include "oopstd.h" 

using namespace oopstd;
using namespace std;

Matrix inputMatrix(int rows, int cols) {
    Matrix mat(rows, cols);
    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            float value;
            cin >> value;
            mat.setElement(i, j, value);
        }
    }
    return mat;
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // 행렬 A의 크기 입력
    cout << "Enter the number of rows and columns for matrix A: ";
    cin >> rowsA >> colsA;

    // 행렬 B의 크기 입력
    cout << "Enter the number of rows and columns for matrix B: ";
    cin >> rowsB >> colsB;

    // 행렬 A 입력
    Matrix A = inputMatrix(rowsA, colsA);

    // 행렬 B 입력
    Matrix B = inputMatrix(rowsB, colsB);

    // 두 행렬의 합 계산 및 출력
    if (rowsA == rowsB && colsA == colsB) {
        Matrix C(rowsA, colsA);
        C.add(C, A, B);
        cout << "Matrix A + B:" << endl;
        C.print();
    }
    else {
        cout << "Matrix A and B cannot be added (different dimensions)." << endl;
    }

    // 두 행렬의 차 계산 및 출력
    if (rowsA == rowsB && colsA == colsB) {
        Matrix D(rowsA, colsA);
        D.sub(D, A, B);
        cout << "Matrix A - B:" << endl;
        D.print();
    }
    else {
        cout << "Matrix A and B cannot be subtracted (different dimensions)." << endl;
    }

    // 두 행렬의 곱 계산 및 출력
    if (colsA == rowsB) {
        Matrix E(rowsA, colsB);
        E.mul(E, A, B);
        cout << "Matrix A * B:" << endl;
        E.print();
    }
    else {
        cout << "Matrix A and B cannot be multiplied (incompatible dimensions)." << endl;
    }
    //element 연산
    int rows, cols;
    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    Matrix matrix(rows, cols);
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            float value;
            cin >> value;
            matrix.setElement(i, j, value);
        }
    }

    float element;
    cout << "Enter the value to perform element-wise operations: ";
    cin >> element;

    Matrix result(rows, cols);

    matrix.elementAdd(result, matrix, element); 
    cout << "Element-wise addition of " << element << " to the matrix:" << endl;
    result.print();

    matrix.elementSub(result, matrix, element);
    cout << "Element-wise subtraction of " << element << " from the matrix:" << endl;
    result.print();

    matrix.elementMul(result, matrix, element);
    cout << "Element-wise multiplication of the matrix by " << element << ":" << endl;
    result.print();

    matrix.elementDiv(result, matrix, element);
    cout << "Element-wise division of the matrix by " << element << ":" << endl;
    result.print();

    //transpose, adjoint, inverse 연산

    int roWs, coLs;

    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> roWs >> coLs;

    // 행렬 입력
    Matrix mat = inputMatrix(roWs, coLs);

    // Transpose
    Matrix matTranspose(roWs, coLs);
    mat.transpose(matTranspose, mat);
    cout << "Transpose of the matrix:" << endl;
    matTranspose.print();

    // Adjoint
    if (roWs == coLs) {
        Matrix matAdjoint(roWs, coLs);
        mat.adjoint(matAdjoint, mat);
        cout << "Adjoint of the matrix:" << endl;
        matAdjoint.print();
    }
    else {
        cout << "Adjoint is not applicable for non-square matrices." << endl;
    }

    // Inverse
    if (roWs == coLs) {
        Matrix matInverse(roWs, coLs);
        mat.inverse(matInverse, mat);
        float det = mat.determinant();
        if (det != 0) {
            cout << "Inverse of the matrix:" << endl;
            matInverse.print();
        }
        else {
            cout << "The matrix is not invertible." << endl;
        }
    }
    else {
        cout << "Inverse is not applicable for non-square matrices." << endl;
    }
    return 0;
}
