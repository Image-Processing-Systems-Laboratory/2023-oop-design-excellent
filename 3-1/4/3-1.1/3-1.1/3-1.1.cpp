#include <iostream>
#include <string>

using namespace std;

class Node { //Node class
private:
    Node* m_pNext; //다음 노드를 가리키는 포인터
    string m_Data; //노드의 데이터

public:
    Node() { //생성자 //포인터와 데이터 초기화
        m_pNext = nullptr;
        m_Data = "";
    }
    ~Node() {} //소멸자

    void SetData(string data) { //데이터 설정
        m_Data = data;
    }
    void SetNext(Node* pNext) { //다음 노드 설정
        m_pNext = pNext;
    }
    string GetData() { //m_Data 반환
        return m_Data;
    }
    Node* GetNext() { //m_pNext 반환
        return m_pNext;
    }
};

void InsertNode(Node*& head, string data); //노드 추가 함수
void InsertWords(Node*& list, const string& input); //문자열에서 단어 추출 후 링크드 리스트에 추가하는 함수
string ConvertToLower(string str); //소문자 변환 함수
Node* Merge_List(Node* p1, Node* p2, Node* p3); //리스트 병합 함수
void Print_List(Node* head); //링크드 리스트 노드 데이터 출력 함수

int main() {
    Node* list1 = nullptr; //nullptr로 초기화
    Node* list2 = nullptr; //nullptr로 초기화
    Node* list3 = new Node(); //동적할당 후 초기화
    list3->SetData(""); //공백 문자열로 초기화

    string input1, input2; //사용자로부터 입력받을 문자열 변수

    cout << "Input list 1: ";
    getline(cin, input1); //input1 입력받기
    cout << "Input list 2: ";
    getline(cin, input2); //input2 입력받기

    InsertWords(list1, input1); //InsertWords 함수 호출해 list1에 값 저장
    InsertWords(list2, input2); //InsertWords 함수 호출해 list2에 값 저장

    list3 = Merge_List(list1, list2, list3); //Merge_List 함수 호출해 list3에 값 저장
    cout << "Result: ";
    Print_List(list3);  //Print_List 함수 호출해 결과 값 출력

    return 0; //종료
}


void InsertNode(Node*& head, string data) {
    Node* newNode = new Node;  //새 노드 생성
    newNode->SetData(data); //데이터 설정
    newNode->SetNext(nullptr);  //다음 노드를 nullptr로 설정

    if (head == nullptr) {  //head가 nullptr이면
        head = newNode; //새 노드를 리스트의 첫 번째 노드로
        return;
    }

    Node* curNode = head; //현재 노드를 헤드 노드로 초기화
    Node* prevNode = nullptr;  //이전 노드를 nullptr로 초기화

    while (curNode != nullptr && ConvertToLower(curNode->GetData()) < ConvertToLower(data)) { //리스트가 비어있지 않으면서 현재 노드의 데이터가 새 데이터보다 작으면
        prevNode = curNode; //이전 노드를 현재 노드로 설정
        curNode = curNode->GetNext(); //현재 노드를 다음 노드로 이동
    }
    if (prevNode == nullptr) { //이전 노드가 nullptr이면 
        newNode->SetNext(head); //새 노드를 첫 번째 노드로
        head = newNode;
    }
    else { //이전 노드가 nullptr이 아니면 
        prevNode->SetNext(newNode); //새 노드를 이전 노드와 현재 노드 사이에 삽입
        newNode->SetNext(curNode);
    }
}

void InsertWords(Node*& list, const string& input) {
    int i = 0, j = 0; //단어의 시작과 끝 인덱스 변수 선언 및 초기화
    while (j < input.length()) { //문자열의  끝까지 반복
        if (input[j] == ' ') { //공백 문자일 때
            InsertNode(list, input.substr(i, j - i)); //InsertNode 함수 호출해 시작부터 끝까지의 문자열을 추출하여 링크드 리스트에 추가
            i = j + 1; //시작 인덱스를 다음 단어의 시작 위치로 이동
        }
        j++; //다음 문자로 이동
    }
    InsertNode(list, input.substr(i)); //InsertNode 함수 호출해 마지막 단어를 추출하여 링크드 리스트에 추가
}

string ConvertToLower(string str) {
    string result = ""; //result 초기화
    for (int i = 0; i < str.length(); i++) { //문자열의 끝까지 반복
        result += tolower(str[i]); //소문자로 변환해 result에 추가
    }
    return result; //result 반환
}

Node* Merge_List(Node* p1, Node* p2, Node* p3) { 
    if (p2 == nullptr) {  //p2가 nullptr이면
        return p1; //p1 반환
    }
    if (p1 == nullptr) { //p1이 nullptr이면
        return p2; //p2 반환
    }
    while (p1 != nullptr && p2 != nullptr) { //p1과 p2 둘 다 nullptr이 아니면 반복
        if (ConvertToLower(p1->GetData()) < ConvertToLower(p2->GetData())) { //p1 값이 p2 값보다 작으면
            InsertNode(p3, p1->GetData()); //p1 값을 p3에 추가
            p1 = p1->GetNext(); //p1 다음 노드로 이동
        }
        else { //그 외의 경우일 때
            InsertNode(p3, p2->GetData()); //p2 값을 p3에 추가
            p2 = p2->GetNext(); //p2 다음 노드로 이동
        }
    }
    while (p1 != nullptr) { //p1이 nullptr이 아니면
        InsertNode(p3, p1->GetData()); //p1 값을 p3에 추가
        p1 = p1->GetNext(); //p1 다음 노드로 이동
    }
    while (p2 != nullptr) {  //p2가 nullptr이 아니면
        InsertNode(p3, p2->GetData()); //p2 값을 p3에 추가
        p2 = p2->GetNext(); //p2 다음 노드로 이동
    }
    return p3->GetNext(); //p3 다음 노드 반환
}

void Print_List(Node* head) {
    Node* curNode = head; //현재 노드를 가리키는 포인터를 헤드 노드로 초기화
    while (curNode != nullptr) { //현재 노드가 nullptr이 아닐 때까지 반복
        cout << curNode->GetData(); //현재 노드 데이터 출력
        if (curNode->GetNext() != nullptr) { //다음 노드가 nullptr이 아니면
            cout << " "; //공백 문자 출력
        }
        curNode = curNode->GetNext(); //curNode 다음 노드로 이동
    }
    cout << endl; //개행
}