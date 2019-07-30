#include "linklist2.h"
#include <stdio.h>
#include <stdlib.h>
// 链表遍历
// 空实现
// 污染,不可重入
// x坐标
// y坐标
// 0表示找到节点，-1表示没找到对应的节点
int linklist_find(struct Snack *head, int x, int y)
{
    struct Snack *p;

    p = head;
    while(p != NULL)
    {
        // 找到节点
        if (p->x ==x && p->y == y)
        {
            return 0;
        }

        p = p->next;
    }

    return -1;
}

// 头插法
// x 新节点的x坐标
// y 新节点的y坐标
// head 头节点
//struct Snack **head;
//
//  变量 : 类型
// head  : struct Snack **  二级指针
// *head : struct Snack *   一级指针
// **head: struct Snack     变量
//
void linklist_insert(struct Snack **head, int x, int y)
{
    struct Snack *node = (struct Snack *)malloc(sizeof(struct Snack));
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) 链表连接
    node->next = *head;

    // 3) 头节点指针指向新节点
    *head = node;
}

// 插入新节点后，返回新的头节点
struct Snack *linklist_insert2(struct Snack *head, int x, int y)
{
    struct Snack *node = (struct Snack *)malloc(sizeof(struct Snack));
    node->x = x;
    node->y = y;
    node->next = NULL;

    // 2) 链表连接
    node->next = head;

    // 3) 返回新的头节点
    return node;
}

void linklist_delete(struct Snack *head)
{
    struct Snack *p;
    struct Snack *tmp;

    p = head;
    while(NULL != p && NULL != p->next) {
        if (NULL == p->next->next) {
            // 保存待删除节点
            tmp = p->next;
            // 从链表删除节点
            p->next = NULL;
            // 释放节点
            free(tmp);
            break;
        }
        p = p->next;
    }
}

void linklist_print(struct Snack *head)
{
    struct Snack *p;
    p = head;
    while (NULL != p) {
        printf("%d,%d\n", p->x, p->y);
        p = p->next;
    }
}

