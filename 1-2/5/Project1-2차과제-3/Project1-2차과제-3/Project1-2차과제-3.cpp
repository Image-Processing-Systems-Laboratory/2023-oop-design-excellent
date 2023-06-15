#define _CRT_SECURE_NO_WARNINGS
#include <iostream> // 헤더파일 선언
#include <fstream>
#include <string.h>

using namespace std; // 표준 라이브러리 사용
/* cin같은 함수들의 앞에 정의된 클래스가 없으면
C++ 표준 라이브러리 함수로 받아들이겠다는 뜻*/

bool compare(char* pattern, char* filename) {
    // 와일드카드 패턴과 파일 이름을 비교하여 일치하는지 확인하는 bool형 함수이다. 일치하면 1을 일치하지 않으면 0을 반환한다. 재귀함수를 이용하여 '?'와'*'을 찾을때 까지 함수를 반복
    if (*pattern == NULL && *filename == NULL) {
        // 패턴과 파일 이름 모두 끝에 도달했을 경우
        return 1;
    }
    if (*pattern == '*' && *(pattern + 1) != NULL && *filename == NULL) { // 예외처리 : *pattern이 '*'이지만 파일 이름이 끝나버렸을 경우 0을 반환한다. 
        // 패턴이 '*'로 시작하고, 파일 이름이 끝나버렸을 경우
        return 0;
    }
    if (*pattern == '?' || *pattern == *filename) { // 지금까지 *pattern과 *filename의 요소가 일치했고, 패턴이 ? 이면 그 다음 요소들을 비교하여 끝까지 일치하면 1을 반환한다. 
        // 패턴 문자와 파일 이름 문자가 일치하는 경우와 패턴 문자가 '?'인 경우
        return compare(pattern + 1, filename + 1);
    }
    if (*pattern == '*') {
        // 지금까지 패턴과 파일의 요소가 일치했고, 패턴 문자가 '*'인 경우 재귀를 이용하여 *pattern과 *filename이 모두 NULL값에 도달할 때까지 재귀를 이용한 후 1을 반환
        // 하지만 *pattern이 아직 끝나지 않았지만 파일 이름이 끝나버렸을 경우에는 0을 반환한다(예외처리)
        return compare(pattern + 1, filename) || compare(pattern, filename + 1);
    }
    return 0; // 그 외의 경우 모두 0을 반환
}

int main() { // main 함수 선언
    char filename[100]; // char형 변수 filname 선언 filename을 입력받기위해 사용
    cout << "Input file name : ";
    cin >> filename;
    int count = 0; // int형 변수 count선언 패턴의 개수를 입력받기 위해 사용
    cin >> count;
    char input[100][100]; // char형 2차원배열 input 패턴을 입력받기 위해 사용
    for (int i = 0; i < count; i++) {
        cin >> input[i];
    }

    ifstream file1(filename); // filename과 일치하는 파일 열기
    if (!file1) { // filename과 일치하는 파일이 없는경우
        cout << "파일을 열 수 없습니다.";
        return 0;
    }
    char buffer[100]; // 파일에서 한줄씩 data를 받을 buffer, 데이터를 조건에 맞으면 result에 저장하기 위해 선언
    char result[1000][101]; // 결과값을 저장할 배열
    int idx = 0; // 결과값 배열의 인덱스
    while (!file1.eof()) { // 파일의 끝이 아닐때까지 반복
        file1.getline(buffer, 100);
        // 파일 내의 모든 줄에 대해서
        for (int i = 0; i < count; i++) {
            // 입력된 모든 패턴에 대해서
            if (compare(input[i], buffer)) {
                // 일치하는 경우 배열에 저장, compare함수를 호출하여 1이 return 되면 result에 buffer을 저장한다.
                strcpy(result[idx], buffer);
                idx++;
                break;
            }
        }
    }
    file1.close(); // 파일 닫기

    // 입력된 패턴 순서대로 결과를 출력 다시한번 compare함수를 호출하여 먼저 입력된 패턴부터 출력함
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < idx; j++) {
            if (compare(input[i], result[j])) {
                cout << result[j] << endl;
            }
        }
    }

    return 0; // 0의 반환
}