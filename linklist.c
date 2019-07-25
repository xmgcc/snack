#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// 创建链表
struct SnackLinkList *linklist_create(int x, int y, int length)
{
    struct SnackLinkList *head;
    int i;

    // 蛇头, 创建并初始化
    head = NULL;

    // length-1创建蛇身
    for (i = 0; i < length; i++) {
        linklist_insert(&head, x, y + i);
    }

    return head;
}

int linklist_find(struct SnackLinkList *head, int x, int y)
{
    struct SnackLinkList *p;

    // for (i = 0; i < n; i++)
    for (p = head; p != NULL; p = p->next) {
        if (p->x == x && p->y == y) {
            return 0;
        }
    }

    return -1;
}

// 遍历链表，打印
void linklist_printf(struct SnackLinkList *head, int x, int y)
{
    struct SnackLinkList *p;

    // for (i = 0; i < n; i++)
    for (p = head; p != NULL; p = p->next) {
        printf("%d, %d\n", p->x, p->y);
    }
}

// return 0成功，-1失败
void linklist_delete_tail(struct SnackLinkList *head)
{
    struct SnackLinkList *prev;
    struct SnackLinkList *del;

    prev = head;
    // 1)找到待删除节点的上一个节点
    while (prev != NULL && prev->next != NULL) {
        if (prev->next->next == NULL) {
            break;
        }

        prev = prev->next;
    }

    // 只有一个头结点
    if (prev->next == NULL) {
        return;
    }

    // 2)删除节点
    // 2.1)临时保存待删除节点del
    del = prev->next;

    // 2.2)从链表删除节点del
    prev->next = del->next;

    // 2.3)free del
    free(del);
}

void linklist_insert(struct SnackLinkList **head, int x, int y)
{
    struct SnackLinkList *node;

    // 1) 创建初始化节点
    node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
    if (node == NULL) {
        return;
    }
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) node指向头结点
    node->next = *head;

    // 3) head指向node
    *head = node;
}
