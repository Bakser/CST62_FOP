
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef int value;

// ����ڵ�Ľṹ��
typedef struct node {
    value val; // ֵ
    node *next; // ��һ���ڵ�ָ��
};

// �ж�����ֵa��b�Ƿ���ȣ�����ȣ�����true�����򷵻�false
bool is_equal(value a, value b);

// ������ͷΪhead�������x���ڵ�֮�����ֵΪv�Ľڵ�
// ��֤����ǿգ�1<=x<=�����ȣ��Ҳ���������ͷ����ڵ�
void insert(node *head, int x, value v) {
	for (int i = 0; i + 1 < x; ++ i) {
		head = head->next;
	}
	node *n = new node;
	n->val = v;
	n->next = head->next;
	head->next = n;
}

// ������ͷ��ʼ���������е�һ��ֵ����v�Ľڵ㣬���ؽڵ��λ�ã�������ͷ��ʼ���ڼ����ڵ㣩
// ����Ϊ1���Դ����ƣ�������ֵ����v�Ľڵ��򷵻�-1
// ע���ж��Ƿ����ʱ���������is_equal����
int search(node *head, value v) {
	int s(1);
	for (; head && !is_equal(head->val, v); head = head->next, ++ s);
	return head ? s : -1;
}

bool is_equal(value a, value b) {
    return a == b;
}

int main() {
    node *head = new node;
    head -> next = NULL;
    head -> val = 0;
    insert(head, 1, 1);
    insert(head, 2, 2);
    if (search(head, 0) == 1 &&
        search(head, 1) == 2 &&
        search(head, 2) == 3 &&
        search(head, 3) == -1)
        cout << "Accept\n";
    else
        cout << "Wrong answer\n";
    system("pause");
}
