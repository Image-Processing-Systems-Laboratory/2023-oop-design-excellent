#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* next;
};

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A' + 'a';
    return ch;
}

bool my_compare(const string& a, const string& b) // 대소문자 구별 없이 비교
{
    for (size_t i = 0; i < a.length() && i < b.length(); i++) // a,b의 길이 만큼 비교
    {
        char lower_a = toLower(a[i]); // a를 소문자로
        char lower_b = toLower(b[i]); // b도 소문자로
        if (lower_a < lower_b) // a가 더 작으면 
            return true; // true
        else if (lower_a > lower_b) // a가 더 크면       
            return false; // false
    }
}

Node* sortList(Node* head)
{
    if (head == nullptr) // head가 빈값이면 비어있는 리스트이므로
        return nullptr; // nullptr 반환

    Node* sort = nullptr; // 정렬할 노드의 초기화
    while (head != nullptr) // 리스트의 끝이 오기 전까지 
    {
        Node* Cur = head; // 현재 값을 head로
        head = head->next; // 다음 노드로 변경 

        if (sort == nullptr || my_compare(Cur->data, sort->data)) // 정렬된 리스트가 비어있거나 현재 노드가 정렬된 리스트의 노드보다 작을경우
        {
            Cur->next = sort; // 현재 값을 정렬된 노드 처음 값에
            sort = Cur; // 정렬된 노드에 현재 값을 저장
        }
        else // 비어 있지 않거나 들어가려는 문자열이 더 큰 경우
        {
            Node* temp = sort;// 정렬된 값을 저장하고
            while (temp->next != nullptr && my_compare(temp->next->data, Cur->data)) // 정렬된 리스트가 끝이 아닐때까지            
                temp = temp->next; // 그 다음 값으로 넣음         
            Cur->next = temp->next; // 다음 temp의 값이 현재 다음 값으로 설정
            temp->next = Cur; // temp를 현재 다음값으로 설정
        }
    }
    return sort;
}

Node* Merge_List(Node* p1, Node* p2, Node* p3) // 머지 리스트
{
    p1 = sortList(p1); // 두 개의 정렬된 리스트
    p2 = sortList(p2);

    while (p1 != nullptr && p2 != nullptr) // 두 리스트가 끝나기 전까지
    {
        Node* newNode; // 새로운 노드 생성
        if (my_compare(p1->data, p2->data)) // 리스트의 문자 비교
        {
            newNode = new Node{ p1->data, nullptr }; // true면 실행이니 p1의 데이터 이동
            p1 = p1->next; // 그 다음 번지로
        }
        else
        {
            newNode = new Node{ p2->data, nullptr }; // false 일때는 p2가 더크므로
            p2 = p2->next; // 다음 껄로 이동
        }
        if (p3 == nullptr)
            p3 = newNode;
        else // 널문자가 아니면
        {
            Node* temp = p3; // 새로운 노드를 추가할 위치
            while (temp->next != nullptr) // 널문자가 오기전까지
                temp = temp->next; // 다음 노드로 이동
            temp->next = newNode; // 새로운 노드로 결과 추가
        }
    }

    Node* remaining; // 남아있는 노드 추가
    if (p1 != nullptr) // 널문자가 아니면
        remaining = p1;   // p1 반환
    else  // 널문자면
        remaining = p2; // p2 반환
    
    while (remaining != nullptr)
    {
        Node* newNode = new Node{ remaining->data, nullptr }; // 새 노드 생성
        Node* temp = p3; // 새로운 노드를 추가할 위치
        while (temp->next != nullptr) // 리스트의 끝에 도달할 때까지 반복
            temp = temp->next; // 다음 노드로 이동
        temp->next = newNode; // 노드를 결과 추가
        remaining = remaining->next; // 남은 리스트에서 다음 노드로 이동
    }
    return p3; // 합치고 정렬된 리스트 반환
}

Node* strchangeNode(const string& input) // 입력한 스트링을 노드로
{
    Node* head = nullptr; // 처음과 끝 초기화
    Node* tail = nullptr;
    string word; // 문자열에서 현재 처리 중인 단어를 저장할 변수

    for (char ch : input)
    {
        if (ch != ' ') // 공백이 오지않으면
            word += ch; // 단어 계속 받아옴
        else // 공백이면
        {
            if (word.length() > 0) // 그 단어의 길이가 0보다 크면
            {
                Node* newNode = new Node{ word, nullptr }; // 새 노드 생성후 저장   
                if (head == nullptr) // 널문자면
                    head = newNode; // 새로운 노드를 처음으로 설정
                else // 널문자가 아니면
                    tail->next = newNode; // 맨 마지막을 가르키는 노드의 가르키도록
                tail = newNode; // 맨마지막은 노드 값
                word = ""; // 단어 초기화
            }
        }
    }
    if (word.length() > 0) // 맨 마지막단어
    {
        Node* newNode = new Node{ word, nullptr }; // 새 노드 생성하고 단어를 저장
        if (head == nullptr) // 연결 리스트가 비어있는 경우
            head = newNode; // 새로운 노드를 리스트의 처음으로 설정
        else // 연결 리스트가 비어있지 않은 경우
            tail->next = newNode; // 현재 마지막 노드의 다음 노드로 새 노드를 연결
        tail = newNode; // 새로운 노드를 마지막 노드로 설정
    }
    return head; // 맨 처음가르키는 head 반환
}

int main()
{
    string input1, input2; // 입력할 두 문자열
    cout << "Input>>" << endl;
    cout << "Input list 1:";
    getline(cin, input1);
    cout << "Input list 2:";
    getline(cin, input2);

    Node* p1 = strchangeNode(input1); // 노드 형태로 바꾼후
    Node* p2 = strchangeNode(input2);
    Node* result = nullptr; // 결과 노드를 초기화
    result = Merge_List(p1, p2, result);

    cout << "Output>>" << endl;
    cout << "Result: ";
    Node* current = result; // 결과 출력
    while (current != nullptr)
    {
        cout << current->data;
        if (current->next != nullptr)
            cout << " ";     
        current = current->next;
    }

    return 0;
}