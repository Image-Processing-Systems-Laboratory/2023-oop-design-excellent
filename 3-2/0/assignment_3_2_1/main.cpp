#include "node.h"

int main()
{
    Node* head;
    Node* target;
    int tar;

    head = make_rand_list(); // head�� 16���� ������ ���� ������ ����Ʈ�� ���
    print_list(head);
    insertion_sort(&head); // ���� ������ ���� ��� ������ �ٲ� �� �����Ƿ� &head�� �ѱ�
    print_list(head);
    std::cout << "insert target: ";
    std::cin >> tar; // ã�� target�� �Է�
    target = Binary_Search(head, tar); // target�� �ִ� ��� Ȥ�� ���� ����� ���� ������ ��� ��ȯ
    std::cout << target->getData() << std::endl; // ����� data ���
    memory_free(head); // �޸� ����
    return 0;
}