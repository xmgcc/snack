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



// 查找节点
int linklist_find(struct Snack *head, int x, int y);

// 头插法插入节点
void linklist_insert(struct Snack **head, int x, int y);

// 头插法插入节点
struct Snack *linklist_insert2(struct Snack *head, int x, int y);

// 删除最后一个节点
void linklist_delete(struct Snack *head);

// 打印所有节点
void linklist_print(struct Snack *head);
#endif // LINKLIST2_H
