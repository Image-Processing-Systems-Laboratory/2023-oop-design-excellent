#include <iostream>


using namespace std;

int main() {
    double a, b, c, d, e, f, g, h, i;
    //3X3 ��� �Է�
    cout << "Enter the 3X3 matrix:" << endl;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;

    //��Ľ� �� ���
    double det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    if (det == 0) {     //��Ľ��� 0�϶� ������� ���� �ʴ´�.
        cout << "The inverse matrix does not exit." << endl;
    }
    else {
        //������� ���
        double adjugate[3][3] = { {e * i - f * h, -(b * i - c * h), b * f - c * e},
                                 {-(d * i - f * g), a * i - c * g, -(a * f - c * d)},
                                 {d * h - e * g, -(a * h - b * g), a * e - b * d} };
        //����� ���
        double inverse[3][3];
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                inverse[row][col] = adjugate[row][col] / det;       //�ݺ����� �Ἥ �� ��ҵ��� �Ҵ����ش�.
            }
        }

        //����� ���
        cout << "The inverse matrix is:" << endl;
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                cout << inverse[row][col] << " ";       //�ݺ����� �Ἥ �� ��ҵ��� ������ش�.
            }
            cout << endl;
        }
    }

    return 0;
}