#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Node { //Node class
private:
    Node* m_pNext; //다음 노드를 가리키는 포인터
    int m_Data; //노드의 데이터 값
public:
    Node(int data = 0, Node* next = nullptr) { //생성자 
        m_Data = data;
        m_pNext = next;
    }
    ~Node() {} //소멸자

    void SetData(int n) { //노드의 데이터 값 설정
        m_Data = n;
    }
    void SetNext(Node* pNext) { //다음 노드 설정
        m_pNext = pNext;
    }
    int GetData() { //노드의 데이터 값 반환
        return m_Data;
    }
    Node* GetNext() { //다음 노드 반환
        return m_pNext;
    }
};

void print_list(Node* head) { //리스트 출력 함수
    while (head != nullptr) { //head 포인터가 nullptr이 아니면 반복
        cout << head->GetData() << " "; //노드의 데이터 값 출력
        head = head->GetNext(); //다음 노드로
    }
    cout << endl; //개행
}

Node* insertion_sort(Node* head) { //삽입 정렬을 사용하여 연결 리스트를 정렬하는 함수
    if (head == nullptr || head->GetNext() == nullptr) { //노드가 0 또는 1개이면 
        return head; //그대로 반환
    }
    //첫 번째 노드를 기준으로 정렬된 리스트를 만들고
    Node* sorted = head;
    //두 번째 노드부터 마지막 노드까지 반복하면서 정렬된 리스트에 삽입
    head = head->GetNext();
    sorted->SetNext(nullptr);
    while (head != nullptr) { // head가 nullptr이 아닐 때까지 반복
        //현재 노드를 선택한 후 다음 노드로
        Node* currnode = head;
        head = head->GetNext();
        //선택된 노드가 기준 노드보다 크면 리스트의 맨 앞에 삽입
        if (currnode->GetData() > sorted->GetData()) {
            currnode->SetNext(sorted);
            sorted = currnode;
        }
        //선택된 노드가 기준 노드보다 작거나 같으면 정렬된 리스트의 적절한 위치에 삽입
        else {
            Node* search = sorted;
            while (search->GetNext() != nullptr && search->GetNext()->GetData() > currnode->GetData()) {
                search = search->GetNext();
            }
            currnode->SetNext(search->GetNext());
            search->SetNext(currnode);
        }
    }
    return sorted; //정렬된 리스트의 헤드 노드를 반환
}

Node* binary_search(Node* p, int n) { //이진 탐색 알고리즘으로 노드를 검색하는 함수

    Node* currnode = p; //현재 노드를 가리키는 포인터 변수 currnode
    int start = 0, end = 15, mid; //start, end, mid  //시작, 끝, 중간 인덱스

    //이진 탐색 알고리즘
    while (start <= end) { //start가 end보다 작거나 같으면 반복
        mid = (start + end) / 2; //중간 인덱스 계산

        currnode = p; //다시 p로 초기화
        for (int i = 0; i < mid; i++) { //중간 노드를 가리키도록 이동
            currnode = currnode->GetNext();
        }
        if (currnode->GetData() == n) { //타겟 노드가 현재 노드의 데이터와 같으면
            cout << endl << "Target node found! : " << n << endl; //타겟 노드가 발견되었음을 출력
            return currnode; //해당 노드 반환
        }
        else if (currnode->GetData() > n) { //찾는 값이 현재 노드의 데이터보다 작으면
            cout << "Target value is smaller than " << currnode->GetData() << ", check the lower half" << endl; //작은 쪽 절반을 검사 중임을 출력
            start = mid + 1; //start 값을 mid + 1로
        }
        else { //찾는 값이 현재 노드의 데이터보다 크면
            cout << "Target value is larger than " << currnode->GetData() << ", check the upper half" << endl; //큰 쪽 절반을 검사 중임을 출력
            end = mid - 1; //end 값을 mid - 1로
        }
    }

    //찾는 노드가 없는 경우 가장 가까운 노드를 찾은 후 출력
    currnode = p; //다시 p로 초기화
    int diff = abs(currnode->GetData() - n); //처음 노드와 찾는 값과의 차이 계산
    Node* closestnode = currnode; //가장 가까운 노드를 가리키는 closestnode

    while (currnode != nullptr) { //노드를 끝까지 탐색할 때까지 반복
        int currdiff = abs(currnode->GetData() - n); //현재 노드와 찾는 값과의 차이 계산
        if (currdiff < diff) { //현재 노드와 찾는 값과의 차이가 더 작으면
            diff = currdiff; //차이 값을 저징
            closestnode = currnode; //closestnode를 현재 노드로
        }
        currnode = currnode->GetNext(); //다음 노드로 이동
    }
    cout << endl << "Target node not found!" << endl << "The closest node : " << closestnode->GetData() << endl; //closestnode 값 출력
    return closestnode; //closestnode
}


int main() {
    //0에서 200 사이의 16개의 고유한 난수를 생성
    srand(time(NULL)); //난수 발생 시드값을 현재 시간으로 설정해 난수가 생성되도록 설정
    int random[16] = { 0 }; //크기가 16인 배열 생성하고 초기값을 0으로 설정
    random[0] = rand() % 201; //첫번째 배열 원소에 0~200 사이의 난수 생성 후 할당

    //중복되지 않는 16개의 난수 생성
    for (int i = 1; i < 16; i++) { //i는 1부터 15까지 반복
        int dup = rand() % 201; //0~200 사이의 난수 생성 후 dup 변수에 할당
        for (int j = 0; j < i; j++) { //j는 0부터 i-1까지 반복
            if (dup == random[j]) { //만약 새로 생성된 dup이 이미 존재하는 숫자와 중복이면
                dup = rand() % 201; //새로운 dup 생성
                j = -1; //j를 -1로 설정하여 j가 0부터 시작하도록 설정
            }
        }
        random[i] = dup; //중복되지 않는 난수가 생성되면 배열의 i번째 원소에 할당
    }

    //랜덤 숫자 16개로 연결 리스트 생성
    Node* head = new Node(random[0]); //첫 번째 원소를 헤드 노드로 하여 연결 리스트 생성
    for (int i = 1; i < 16; i++) { //i는 1부터 16까지 반복
        head = new Node(random[i], head); //새로운 노드를 헤드 노드로 추가하여 연결 리스트 생성
    }

    cout << "List: ";
    print_list(head); //print_list 함수 호출해 생성된 리스트 출력

    head = insertion_sort(head); //insertion_sort 함수 호출해  리스트 정렬
    cout << "Sorted: ";
    print_list(head); //print_list 함수 호출해 정렬된 리스트 출력

    cout << endl << "Enter the target node: ";
    int targetnode = 0;
    cin >> targetnode; //타겟 값을 입력받음
    cout << endl;
    Node* result = binary_search(head, targetnode); //binary_search 함수 호출해 결과 출력

    return 0; //종료
}