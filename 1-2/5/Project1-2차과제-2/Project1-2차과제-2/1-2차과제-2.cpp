#include <iostream> // ������� ����
#include <cmath> // ������� ���� => pow�Լ����� ����ϱ� ���� ���
#include <cstdlib> // ������� ���� => rand�Լ����� ����ϱ� ���� ���
#include <ctime> // ������� ����
using namespace std; // ǥ�� ���̺귯�� ���

/* cin���� �Լ����� �տ� ���ǵ� Ŭ������ ������
C++ ǥ�� ���̺귯�� �Լ��� �޾Ƶ��̰ڴٴ� ��*/


void Receiver(const char* received_frame, long long P) {// ��ȯ���� ���� const char*���� long long ���� �Ű������� �޴� Receiver �Լ� 
    cout << "Received frame: "; // Received frame: ���
    for (int i = 0; i < 16; i++) { // for���� �̿��Ͽ� Received frame�� ��Ҹ� ����ϴ� ����
        cout << received_frame[i];
    }
    cout << endl; // �ٹٲ�

    long long num1 = 0; // int�� ���� num1 ���� �̴� 2������ 10������ ǥ���ϱ� ���� ���
    int arr[16] = { 0, }; // int�� 1�����迭 arr���� received_frame�� ��Ҵ�� ������ ���������� �����ϱ� ���� ����
    for (int i = 0; i < 16; i++) { // �̰��� ������ received_frame�� 1�����迭 arr�� ���������� �����ϴ� �����̴�
        if (received_frame[i] == '1') {
            arr[i] = 1;
        }
        else {
            arr[i] = 0;
        }
    }

    for (int i = 0; i < 16; i++) { // �迭 arr�� ����Ǿ��ִ� ��ҵ��� 10������ ��ȯ�ϴ� ���� 
        num1 += (arr[i] * pow(2, 15 - i));
    }
    int R = 0; // int �� ���� R ������ �����ϱ� ���� ����
    int i = 0; // int�� ���� i�� ���� XOR������ �� ����Ʈ�� ��� ������ ������
    int j = 0; // int�� ���� j�� ���ݱ��� �� ����Ʈ�� ������ �����ֱ� ���� ���
    char frame[16];// char�� 1�����迭 frame ���� �̴� Reconstructed data�� ����ϱ� ���� ��� 
    R = ((num1 >> 11) ^ P); // num1�� ���������� 11�� ����Ʈ�Ͽ� P�� XOR �������� R�� ����

    while (1) { // �ݺ��� ����
        int imag1 = 0; // int�� ���� imag1�� �ٷ� �Ʒ��� ���ǹ����� R�� ���� �������� �ʱ� ���� ���
        imag1 = R;
        i = 0; // i 0���� �ʱ�ȭ
        if (R != 0) {
            while (1) { // �ݺ��� ���� => R���� �Ǿ��� 1�� �ڿ��� ���° �ڸ��� �ִ��� ������
                imag1 /= 2;
                i++;
                if (imag1 == 0) {
                    break; // �ݺ��� Ż��
                }
            }
            i = 5 - i; // ���� ���� i�� ����Ʈ ��� ������ ������
        }
        else { // ���� ���� XOR �����ؾ��� ������ �����ִµ� R�� 0�̶�� ����Ʈ 5�� 
            i = 5;
        }

        if (i > 11 - j) { // ����Ʈ�ؾߵǴ� Ƚ���� �����ִ� ����� �� ���� ���� �� ����ó�� 
            R = R << (11 - j); // R�� 11-j��ŭ ����Ʈ�ϰ�
            for (int k = 1; k <= 11 - j; k++) { // �����ִ� ��Ҹ� 10������ ��ȯ�� ����
                R += (arr[4 + j + k] * pow(2, i - k));
            }
            for (int m = 0; m < 15; m++) { // num1�� �ɰ��� 1���� �迭 frame�� ��Ҹ� ���������� �־��ִ� ����
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15 - m] = '1';
                }
                else {
                    frame[15 - m] = '0';
                }
            }
            cout << "Reconstructed data: ";
            for (int n = 0; n < 12; n++) {
                cout << frame[n];
            }
            cout << endl;
            // Reconstructed data ���
            if (R == 0) {
                cout << "No detected error";
            }
            else {
                cout << "Receiver has detected error";
            }
            // error �߻� ���� ���
            break; // �ݺ��� Ż��!
        }

        R = (R << i); // R�� i��ŭ �������� ����Ʈ
        for (int k = 1; k <= i; k++) {
            R += (arr[4 + j + k] * pow(2, i - k)); // ����Ʈ�� Ƚ����ŭ ������ ��Ҹ� ä����
        }
        j += i; // �� ����Ʈ�� Ƚ�� ���� ����
        R = R ^ P; // XOR����
        if (4 + j >= 15) { // ���� �� ������ ��Ұ� �������� ������� XOR������ �������Ѵ�
            for (int i = 0; i < 15; i++) {// num1�� �ɰ��� 1���� �迭 frame�� ��Ҹ� ���������� �־��ִ� ����
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15 - i] = '1';
                }
                else {
                    frame[15 - i] = '0';
                }
            }
            cout << "Reconstructed data: ";
            for (int n = 0; n < 12; n++) {
                cout << frame[n];
            }
            cout << endl;
            // Reconstructed data ���
            if (R == 0) {
                cout << "No detected error";
            }
            else {
                cout << "Receiver has detected error";
            }
            // error �߻� ���� ���
            break;// �ݺ��� Ż��!
        }
    }
}
void Transmission_Channel(const char* coded_frame, long long P) {// ��ȯ���� ���� const char*���� long long ���� �Ű������� �޴� Transmission_Channel �Լ�
    cout << "Coded frame: ";
    char frame[16];
    for (int i = 0; i < 16; i++) {  // for���� �̿��Ͽ�, Coded_frame ��� ����
        cout << coded_frame[i];
        frame[i] = coded_frame[i];
    }
    cout << endl;

    srand((unsigned)time(NULL)); // seed���� ������ �ð����� �־���

    for (int i = 0; i < 16; i++) { // rand �Լ��� �̿��Ͽ� 0~99�� ������ ���� a�� �����ϰ� a�� 0~4�� ���ڸ� 1�̸� 0����, 0�̸� 1�� �ٲ���. ���� �� ����� ���� ����� Ȯ���� 5%�̴�.
        int a = rand() % 99;
        if (a >= 0 && a <= 4) {
            if (frame[i] == '1') {
                frame[i] = '0';
            }
            else {
                frame[i] = '1';
            }
        }
    }
    Receiver(frame, P); // Receiver�Լ� ȣ�� frame�� P�� �Ѱ���
}
void Sender(long long D, long long P) {// ��ȯ���� ���� long long���� long long ���� �Ű������� �޴� Sender �Լ�
    int arr[16] = { 0, }; // int�� 1�����迭 arr���� �̴� ���� Data�� ��Ҵ�� ������ �����ϱ� ���� ����
    long long num1 = 0; // int�� ���� num1 ���� �̴� 2������ 10������ ǥ���ϱ� ���� ���
    char frame[16]; // char�� 1�����迭 frame ���� �̴� Transmission_Channel�Լ����� �Ű������� ���� ���� �Ѱ��� �� char������ �Ѱ��ֱ� ���� ��� 

    for (int i = 0; i < 12; i++) { // D�� �� ��Ҵ�� �迭�� �����ϱ� ���� �ݺ��� 
        long long  num = D; // long long�� ���� num ����
        num = D / pow(10, 11 - i);

        if (num >= 10) { // num�� 10���� ũ�� ��ҿ� 1�� 0�� �ƴ� �ٸ� ���ڰ� ����ȴ� ���� 10���� ������ �� �������� �־��ش�.
            num %= 10;
            arr[i] = num;
        }
        else {
            arr[i] = num;
        }
    }
    for (int i = 0; i < 12; i++) { // �迭 arr�� ����Ǿ��ִ� ��ҵ��� 10������ ��ȯ�ϴ� ���� 
        num1 += (arr[i] * pow(2, 11 - i));
    }
    // num1 = D�� 10������ ǥ���� ��
    long long T = num1 << 4; //12bit frame���� 16bit frame(T)���� �ٲ���, long long�� ���� T
    long long R = 0; // long long �� ���� R �̴� ������ ���� �����ϱ� ���� ����
    int i = 0; // int�� ���� i�� ���� XOR������ �� ����Ʈ�� ��� ������ ������
    int j = 0; // int�� ���� j�� ���ݱ��� �� ����Ʈ�� ������ �����ֱ� ���� ���

    R = (T >> 11) ^ P; // T�� ���������� 11�� ����Ʈ�Ͽ� P�� XOR �������� R�� ����

    while (1) { // �ݺ��� ����
        int imag1 = 0; // int�� ���� imag1�� �ٷ� �Ʒ��� ���ǹ����� R�� ���� �������� �ʱ� ���� ���
        imag1 = R;
        i = 0; // i 0���� �ʱ�ȭ
        if (R != 0) {
            while (1) { // �ݺ��� ���� => R���� �Ǿ��� 1�� �ڿ��� ���° �ڸ��� �ִ��� ������
                imag1 /= 2;
                i++;
                if (imag1 == 0) {
                    break; // �ݺ��� Ż��
                }
            }
            i = 5 - i; // ���� ���� i�� ����Ʈ ��� ������ ������
        }
        else { // ���� ���� XOR �����ؾ��� ������ �����ִµ� R�� 0�̶�� ����Ʈ 5�� 
            i = 5;
        }
        long long FCS = 0;
        if (i > 11 - j) { // ����Ʈ�ؾߵǴ� Ƚ���� �����ִ� ����� �� ���� ���� �� ����ó�� 
            R = R << (11 - j); // R�� 11-j��ŭ ����Ʈ�ϰ�
            for (int k = 1; k <= 11 - j; k++) { // �����ִ� ��Ҹ� 10������ ��ȯ�� ����
                R += (arr[4 + j + k] * pow(2, i - k));
            }
            FCS = R;
            num1 = ((num1 << 4) + FCS); // num1�� �������� 4�� ����Ʈ�ϰ� R�� �����ִ� ���� �̶� �̴� Coded frame�� 2������ 10������ ��ȯ�� ����̴�.
            for (int m = 0; m < 15; m++) { // num1�� �ɰ��� 1���� �迭 frame�� ��Ҹ� ���������� �־��ִ� ����
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num == 1) {
                    frame[15-m] = '1';
                }
                else {
                    frame[15-m] = '0';
                }
            }
            Transmission_Channel(frame,P); // Transmission_Channel �Լ� ȣ���ϰ� frame�� P�� �Ѱ��ش�
            break; // �ݺ��� Ż��!
        }

        R = (R << i); // R�� i��ŭ �������� ����Ʈ
        for (int k = 1; k <= i; k++) {
            R += (arr[4 + j + k] * pow(2, i - k)); // ����Ʈ�� Ƚ����ŭ ������ ��Ҹ� ä����
        }
        j += i; // �� ����Ʈ�� Ƚ�� ���� ����
        R = R ^ P; // XOR����
        if (4 + j >= 15) { // ���� �� ������ ��Ұ� �������� ������� XOR������ �������Ѵ�
            FCS = R;
            num1 = ((num1 << 4) + FCS);// num1�� �������� 4�� ����Ʈ�ϰ� R�� �����ִ� ���� �̶� �̴� Coded frame�� 2������ 10������ ��ȯ�� ����̴�
            for (int i = 0; i < 15; i++) {// num1�� �ɰ��� 1���� �迭 frame�� ��Ҹ� ���������� �־��ִ� ����
                int num;
                num = num1 % 2;
                num1 /= 2;
                if (num1 == 1) {
                    frame[0] = '1';
                }
                if (num==1) {
                    frame[15-i] = '1';
                }
                else {
                    frame[15-i] = '0';
                }
            }
            Transmission_Channel(frame,P);// Transmission_Channel �Լ� ȣ���ϰ� frame�� P�� �Ѱ��ش�
            break;// �ݺ��� Ż��!
        }
    }

}


int main() { // main �Լ� ����
    long long input1; // long long �� input 1 ���� �̴� Data�� �ޱ� ���� ����
    long long input2 = 0b11011; // input 2 ���� �̴� P�� �ǹ��Ѵ�.

    cout << "Data: ";
    cin >> input1; // Data �Է�
    Sender(input1, input2);  // Sender �Լ� ȣ��, input1�� input2�� �ѱ�.

    return 0; // 0�� ��ȯ
}