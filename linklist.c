#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

// ��������
struct SnackLinkList *linklist_create(int x, int y, int length)
{
    struct SnackLinkList *head;
    int i;

    // ��ͷ, ��������ʼ��
    head = NULL;

    // length-1��������
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

// ����������ӡ
void linklist_printf(struct SnackLinkList *head, int x, int y)
{
    struct SnackLinkList *p;

    // for (i = 0; i < n; i++)
    for (p = head; p != NULL; p = p->next) {
        printf("%d, %d\n", p->x, p->y);
    }
}

// return 0�ɹ���-1ʧ��
void linklist_delete_tail(struct SnackLinkList *head)
{
    struct SnackLinkList *prev;
    struct SnackLinkList *del;

    prev = head;
    // 1)�ҵ���ɾ���ڵ����һ���ڵ�
    while (prev != NULL && prev->next != NULL) {
        if (prev->next->next == NULL) {
            break;
        }

        prev = prev->next;
    }

    // ֻ��һ��ͷ���
    if (prev->next == NULL) {
        return;
    }

    // 2)ɾ���ڵ�
    // 2.1)��ʱ�����ɾ���ڵ�del
    del = prev->next;

    // 2.2)������ɾ���ڵ�del
    prev->next = del->next;

    // 2.3)free del
    free(del);
}

void linklist_insert(struct SnackLinkList **head, int x, int y)
{
    struct SnackLinkList *node;

    // 1) ������ʼ���ڵ�
    node = (struct SnackLinkList *)malloc(sizeof(struct SnackLinkList));
    if (node == NULL) {
        return;
    }
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) nodeָ��ͷ���
    node->next = *head;

    // 3) headָ��node
    *head = node;
}
