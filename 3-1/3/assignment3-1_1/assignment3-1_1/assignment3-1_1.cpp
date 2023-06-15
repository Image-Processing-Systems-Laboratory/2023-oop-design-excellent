#include<string>			//string strl 선언
#include<iostream>			//헤더파일 선언

using namespace std;

class Node {			//클래스 노드 선언
private:
	string data;		//문자열을 저장할 멤버
	Node* next;			//다음 노드를 가리킬 포인터 멤버
public:
	Node() {			//생성자
		data = "";		//노드 내 멤버를 초기화
		next = nullptr;
	}
	~Node() {			//소멸자
		while (next != nullptr) {		//모든 노드가 동적할당 되도록 한다.
			Node* temp = next;
			next = next->next;
			delete temp;
		}
	}
	void setData(string str) {		//data를 저장하는 함수
		data = str;
	}
	void setNext(Node* NextNode) {	//입력받은 노드로 현재 노드가 가리키게 해주는 함수
		next = NextNode;
	}
	string getData() {				//현재 노드에 저장된 문자열을 반환하는 함수
		return data;
	}
	Node* getNext() {				//현재 노드가 가리키고 있는 노드를 반환하는 함수
		return next;
	}
};

void Merge_List(Node* p1, Node* p2, Node* p3);		//Merge_List함수로 입력받는 p1, p2노드를 sort시켜 정렬하고, p3에 merge sort를 사용해 정렬한다.
void Sorted_List(Node* p);							//입력받은 문자열을 Sorted list로 변환 시켜주는 함수
void Sort_Push(Node* p, string str);				//Sort를 시킬 때, 삽입 정렬을 사용하면서 해당 위치를 찾아 노드를 연결해주는 함수
int my_comp(string str1, string str2);				//문자열을 대소문자 구분 없이 비교해주는 함수
void print_list(Node* p);							//현재 리스트에 있는 데이터를 처음부터 끝노드까지 출력해주는 함수
Node* list_pop(Node* p);							//list의 맨 앞 노드를 pop해주는 함수, Merge_List함수에서 사용

int main(void) {
	string str1, str2;								//문자열 선언
	cout << "Input list 1: ";
	getline(cin, str1);								//str1 입력
	Node* p1 = new Node;							//p1 노드의 Data 멤버에 str1을 저장
	p1->setData(str1);

	cout << "Input list 2: ";
	getline(cin, str2);								//str2 입력
	Node* p2 = new Node;							//p2 노드의 Data 멤버에 str2을 저장
	p2->setData(str2);

	Node* p3 = new Node;							//p3 노드 선언
	Merge_List(p1, p2, p3);							//Merge_List()함수 실행
	cout << "Result: ";
	print_list(p3);									//Merge_List()함수 실행 결과 출력

	return 0;
}

void Merge_List(Node* p1, Node* p2, Node* p3) {		//Merge_List함수로 입력받는 p1, p2노드를 sort시켜 정렬하고, p3에 merge sort를 사용해 정렬한다.
	Node* tail = new Node;							//tail 포인터 선언
	Sorted_List(p1);								//p1을 오름차순으로 정렬한 리스트로 변환
	Sorted_List(p2);								//p2를 오름차순으로 정렬한 리스트로 변환

	tail = p3;										//tail = p3으로 둠
	while (p1->getNext() != nullptr && p2->getNext() != nullptr) {		//p1, p2 모두 nullptr을 가리키지 않을동안 반복문 반복
		if (my_comp(p1->getNext()->getData(), p2->getNext()->getData()) == -1) {		//p1, p2가 각각 가리키는 노드의 데이터를 분석해 p1에 저장된 문자열이 더 작다면
			tail->setNext(list_pop(p1));								//tail에 p1에서 추출한 노드를 연결
		}
		else {										//아니라면
			tail->setNext(list_pop(p2));								//tail에 p2에서 추출한 노드를 연결
		}
		tail = tail->getNext();						//tail을 다음 노드로 이동시키기
	}

	if (p1->getNext() != nullptr) {					//p1, p2를 비교하고 p2가 nullptr을 가리켜 p1이 남은경우
		tail->setNext(p1->getNext());				//p1의 나머지 노드를 tail 뒤에 붙임
	}
	if (p2->getNext() != nullptr) {					//p1, p2를 비교하고 p1이 nullptr을 가리켜 p2가 남은경우
		tail->setNext(p2->getNext());				//p2의 나머지 노드를 tail 뒤에 붙임
	}
}

void Sorted_List(Node* p) {							//입력받은 문자열을 Sorted list로 변환 시켜주는 함수
    string str = p->getData() + " ";				//문자열을 받아와 str에 저장하고 마지막에 띄어쓰기를 붙여줌
    int i = 0;
    string temp;									//임지로 저장할 문자열 변수
    do {
        temp.push_back(str[i]);						//str의 한글자씩 temp에 넣기
        if (str[i] == ' ') {						//str[i]가 띄어쓰기라면
			str[i] = '\0';							//null을 넣고
            Sort_Push(p, temp);						//Sort_Push함수를 실행해 삽입정렬으로 위치를 찾아 맞는 위치에 노드 연결
            temp.clear();							//temp를 다시 비우기
        }
        i++;										//인덱스 증가
    } while (str[i] != '\0');						//문자열 마지막이 올때까지
}

void Sort_Push(Node* p, string str) {				//Sort를 시킬 때, 삽입 정렬을 사용하면서 해당 위치를 찾아 노드를 연결해주는 함수
	Node* temp = new Node;							//새 노드를 동적할당
	Node* current;									//현재 노드를 저장할 포인터
	temp->setData(str);								//temp에 입력받은 문자열을 넣기
	if (p->getNext() == nullptr) {					//p의 다음 노드가 null이라면 즉, 처음 노드라면
		p->setNext(temp);							//temp를 연결해주기
	}
	else {											//첫 노드가 아니라면
		current = p;								//현재 노드를 조정
		while (current->getNext() != nullptr) {		//다음 노드가 nullptr이 아닐때까지
			if (my_comp(current->getNext()->getData(), str) == -1) {	//현재 기준 다음 노드의 데이터에 저장된 문자열이 입력된 문자열보다 작다면
				current = current->getNext();			//현재 노드를 지나치지
			}
			else {									//아니라면
				Node* Next_temp = current->getNext();		//Next_temp 포인터 선언해 현재 노드의 다음 노드를 가리키게 하기
				current->setNext(temp);						//현재 노드의 다음노드로 temp를 연결해주기
				temp->setNext(Next_temp);					//temp의 다음 노드로 원래 있던 다음 노드를 연결해 삽입해주기
				return;										//삽입 완료 되었으므로 반환
			}
		}
		current->setNext(temp);								//현재 노드가 가리키는 것이 temp가 되게 한다.
	}
}
int my_comp(string str1, string str2) {				//문자열을 대소문자 구분 없이 비교해주는 함수
	for (int i = 0; i < str1.length(); i++) {		//str1의 사이즈만큼 반복문을 사용하기
		if (str1[i] >= 'a' && str1[i] <= 'z') {		//만약 해당 글자가 소문자라면
			str1[i] -= 'a' - 'A';					//대문자로 변환
		}
	}
	for (int i = 0; i < str2.length(); i++) {		//str2의 사이즈만큼 반복문을 사용하기
		if (str2[i] >= 'a' && str2[i] <= 'z') {		//만약 해당 글자가 소문자라면
			str2[i] -= 'a' - 'A';					//대문자로 변환
		}
	}
	return strcmp(str1.c_str(), str2.c_str());		//strcmp함수를 사용해 변환한 문자열끼리의 비교 결과를 반환
}
void print_list(Node* p) {							//현재 리스트에 있는 데이터를 처음부터 끝노드까지 출력해주는 함수
	Node* current = p->getNext();					 //첫 번째 노드는 데이터가 아니므로 생략
	while (current != nullptr) {					//현재 가리키는 노드가 nullptr이 아닐때까지
		cout << current->getData();					//데이터 출력
		current = current->getNext();				//현재 가리키는 노드를 다음노드로 이동
	}
	cout << endl;									//모두 출력 후 개행
}
Node* list_pop(Node* p) {							//list의 맨 앞 노드를 pop해주는 함수, Merge_List함수에서 사용
	if (p == nullptr || p->getNext() == nullptr) {		//p가 nullptr이거나 p의 다음 노드가 nullptr이면
		return nullptr;								//nullptr을 반환
	}
	Node* temp = p->getNext();						//temp에 첫 노드를 저장
	p->setNext(temp->getNext());					//p가 첫노드를 건너뛰어 가리키도록 설정
	temp->setNext(nullptr);							//temp가 가리키는 노드를 제거
	return temp;									//temp 반환
}