#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
  
typedef int value;
  
// 链表节点的结构体
typedef struct node {
    value val; // 值
    node *next; // 下一个节点指针
};
  
// 判断两个值a和b是否相等，若相等，返回true，否则返回false
bool is_equal(value a, value b);
  
// 在链表头为head的链表第x个节点之后插入值为v的节点
// 保证链表非空，1<=x<=链表长度，且不会在链表头插入节点
void insert(node *head, int x, value v) {
    node *p = head;
    for (int i = 0; i < x - 1; ++i)
        p = p->next;
    node *q = new node;
    q->val = v;
    q->next = p->next;
    p->next = q;
}
  
// 从链表头开始查找链表中第一个值等于v的节点，返回节点的位置（从链表头开始数第几个节点）
// 链表为1，以此类推，若不存值等于v的节点则返回-1
// 注：判断是否相等时，必须调用is_equal函数
int search(node *head, value v) {
    int i = 1;
    for (node *p = head; p; p = p->next, ++i)
        if (is_equal(p->val, v))
            return i;
    return -1;
}
  
bool is_equal(value a, value b) {
    return a % 100 == b % 100;
}
  
int main() {
    int n, op, x, v;
    while (true) {
        cin >> op;
        if (op == 0)
            break;
        else if (op == 1)
            cin >> x >> v;
        else
            cin >> v;
        cin >> n;
        node *a = new node[n];
        for (int i = 0; i < n; i ++) {
            a[i].next = a + i + 1;
            cin >> a[i].val;
        }
        a[n - 1].next = NULL;
        if (op == 1) {
            insert(a, x, v);
            node *b = a;
            while (b != NULL) {
                cout << b -> val << endl;
                b = b -> next;
            }
        } else
            cout << search(a, v) << endl;
        delete []a;
    }
}
