#include "node.h"

int main()
{
    Node* head;
    Node* target;
    int tar;

    head = make_rand_list(); // head는 16개의 랜덤한 값을 가지는 리스트의 헤드
    print_list(head);
    insertion_sort(&head); // 삽입 정렬을 통해 헤드 정보가 바뀔 수 있으므로 &head를 넘김
    print_list(head);
    std::cout << "insert target: ";
    std::cin >> tar; // 찾을 target을 입력
    target = Binary_Search(head, tar); // target이 있는 노드 혹은 가장 가까운 값을 가지는 노드 반환
    std::cout << target->getData() << std::endl; // 노드의 data 출력
    memory_free(head); // 메모리 해제
    return 0;
}