#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //float a b c�� �Է� �޴´�.
    float a, b, c;
    cout << "Enter coefficient a: ";
    cin >> a;
    cout << "Enter coefficient b: ";
    cin >> b;
    cout << "Enter coefficient c: ";
    cin >> c;

    if (a == 0) {   //a = 0���� ������������ �ƴѰ��
        cout << "Unexpected factor of a quadratic term" << endl;    //���
        return -1;
    }
    //������������ �Ǻ��� discriminant ���
    float discriminant = static_cast<float>(pow(b, 2)) - 4 * a * c;

    //�Ǻ����� ������ ���
    if (discriminant < 0) {     //�Ǻ����� ������ ���
        cout << "The equation has no real number solutions." << endl;   //���
    }
    else if (discriminant == 0) {   //�Ǻ����� 0�� ���
        cout << "X1, X2: " << (-b / (2 * a)) << " (double root)" << endl;   //���
    }
    else {      //�Ǻ����� ����� ���
        //���� ������ �̿��� ��� ���
        float x1 = 0, x2 = 0;
        //b�� �ٸ� ����� ���� ���������� ū ���, ������ ���̱� ���� ���
        if (b < 0)      //�μ��� ���� ������ ������� ����
            x1 = (-b + sqrt(discriminant)) / (2 * a);
        else            //�μ��� ������ ������ ������� ����
            x1 = (2 * c) / (-b - sqrt(discriminant));
        x2 = c / (a * x1);  //�ٰ� ����� ���� ���

        cout << "X1: " << x1 << ", X2: " << x2 << endl; //���
    }

    return 0;
}