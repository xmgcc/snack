#ifndef LINKLIST2_H
#define LINKLIST2_H
//
// 链表操作
//

struct Snack {
    // x坐标
    int x;

    // y坐标
    int y;

    // 单链表节点
    struct Snack *next;
};



int linklist_find(struct Snack *head, int x, int y);
void linklist_insert(struct Snack **head, int x, int y);
struct Snack *linklist_insert2(struct Snack *head, int x, int y);
#endif // LINKLIST2_H
