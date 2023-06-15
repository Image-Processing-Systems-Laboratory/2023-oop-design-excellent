#include "node.h"

Node::Node()
{
    data = 0;
    next = 0; // 멤버 변수 초기화
}

void Node::setNext(Node* ptr)
{
    next = ptr;
}

void Node::setData(int data)
{
    this->data = data; // 멤버 변수에 값 할당
}

Node* Node::getNext()
{
    return next;
}

int Node::getData()
{
    return data; // 멤버 변수 반환
}

int check_dup(Node* head, int num)
{
	Node* tmp;

	for (tmp = head; tmp; tmp = tmp->getNext()) // head노드부터 리스트를 순회
	{
		if (tmp->getData() == num) // num data가 기존에 있으면
			return 1; // 1 반환
	}
	return 0;
}

Node* make_rand_list()
{
	Node* head;
	Node* last;
	Node* tmp;
	int num;

	srand((unsigned int)time(NULL)); // 랜덤 시드를 time()으로 초기화
	head = new Node; // head node 생성
	num = (int)rand() % 201; // num은 0부터 200의 랜덤한 값
	head->setData(num); // head 노드에 data 추가
	last = head;
	for (int i = 0; i < 15; i++)
	{
		num = (int)rand() % 201;
		if (check_dup(head, num)) // 기존 리스트에 있는 값이 나오면
		{
			i--; // 개수 추가 X
			continue; // 반복문의 조건 부분으로 이동
		}
		tmp = new Node;
		tmp->setData(num); // 노드 생성
		last->setNext(tmp); // last의 뒷 부분에 노드 삽입
		last = tmp; // last 갱신
	}
	return head;
}

void push(Node* prev, Node* now)
{
	now->setNext(prev->getNext()); // now의 다음은 prev의 다음
	prev->setNext(now); // prev의 다음은 now
}

Node* pop(Node* prev)
{
	Node* ret;

	ret = prev->getNext(); // prev노드의 다음 노드가 pop할 대상
	prev->setNext(ret->getNext()); // prev의 다다음 노드가 prev의 다음 노드(연결 끊기)
	ret->setNext(0); // ret의 다음을 0으로 만들어 ret 노드와 리스트의 연결 완전 끊기
	return ret;
}

void insertion_sort(Node** head)
{
	Node* now_prev, *now, *prev;
	int num;

	if (!(*head)) // 리스트가 비어있으면
		return; // 종료
	now_prev = *head; // 삽입 정렬 시에 비교하는 노드
	while (now_prev->getNext())
	{
		num = now_prev->getNext()->getData(); // 노드를 먼저 pop하는 대신 값만 추출
		if (num > (*head)->getData()) // 비교 중인 노드가 가장 앞에 와야 한다면
		{
			now = pop(now_prev); // now_prev의 다음 노드를 기존 위치에서 pop
			now->setNext(*head); // now를 맨 앞에 삽입
			*head = now; // head 갱신
			continue; // 조건으로 이동
		}
		for (prev = *head; prev != now_prev; prev = prev->getNext())
		{
			if (num > prev->getNext()->getData()) // 노드의 적절한 위치를 찾으면
			{
				now = pop(now_prev); // 노드를 pop
				push(prev, now); // prev 다음에 now를 push
				break; // 더 이상 탐색 x
			}
		}
		if (prev == now_prev) // 마지막까지 비교했다면(노드의 위치가 적절했다면)
			now_prev = now_prev->getNext(); // now_prev만 한 칸 옮김
	}
}

void print_list(Node* head)
{
	for (Node* tmp = head; tmp; tmp = tmp->getNext())
		std::cout << tmp->getData() << " "; // head부터 data를 하나씩 출력
	std::cout << std::endl;
}

Node* getNode(int idx, Node* head)
{
	for (int i = 0; head && i < idx; head = head->getNext(), i++);
	return head; // head에서부터 idx번째 있는 노드를 반환
}

Node* recur_binary(int f, int r, Node* p, int n)
{
	int mid, mid_data;
	Node* f_node = 0;
	Node* r_node = 0;
	Node* m_node = 0;

	if (f >= 0 && f < 16)
		f_node = getNode(f, p);
	if (r >= 0 && r < 16)
		r_node = getNode(r, p); // f와 r이 적절한 값을 가진다면, 각 위치의 노드를 할당
	if (f > r) // 탐색에 실패한다면(두 인덱스가 역전)
	{
		std::cout << "Search failed..." << std::endl; // 에러문 출력
		if (f_node && r_node) // f_node, r_node 둘다 존재하면
		{
			if (abs(f_node->getData() - n) < abs(r_node->getData() - n))
				return f_node; // 둘 중 n과의 차이의 절대값이 작은 값을 가지는 노드를 반환
			else
				return r_node;
		}
		else if (f_node)
			return f_node;
		else if (r_node)
			return r_node; // 둘 중 하나만 존재한다면 그 노드를 반환
		else
			return 0; // 둘 다 존재하지 않는다면 널 반환
	}
	mid = (f + r) / 2; // front와 rear의 중간 값이 mid
	if (mid >= 0 && mid < 16)
		m_node = getNode(mid, p); // 해당 인덱스의 노드
	mid_data = m_node->getData();
	if (mid_data == n) // 검색 성공
		return m_node;
	else if (mid_data < n) // 중간 값보다 데이터가 크다면
		return (recur_binary(f, mid - 1, p, n)); // rear 인덱스를 갱신
	else
		return (recur_binary(mid + 1, r, p, n)); // front 인덱스를 갱신

}

Node* Binary_Search(Node* p, int n)
{
	return recur_binary(0, 15, p, n); // 총 16개의 데이터를 가진 리스트이므로 0부터 15까지 탐색
}

void memory_free(Node* head)
{
	Node* tmp;

	while (head) // head 노드부터
	{
		tmp = head;
		head = head->getNext();
		delete tmp; // 하나씩 메모리 해제
	}
}