#ifndef __LINKLIST_H__
#define __LINKLIST_H__

// c++编译器会定义__cplusplus这个宏
#ifdef __cplusplus
// 告诉c++编译器，这段代码是c代码
extern "C" {
#endif

struct SnackLinkList {
    int x;
    int y;
	struct SnackLinkList *next;
};

// 创建链表
// 在x,y位置创建长度为length的蛇
struct SnackLinkList *linklist_create(int x, int y, int length);

// 遍历链表，打印
void linklist_printf(struct SnackLinkList *head, int x, int y);

// 查找蛇是否在坐标x,y
// 找到返回0，找不到返回-1
int linklist_find(struct SnackLinkList *head, int x, int y);

// 头插法
void linklist_insert(struct SnackLinkList **head, int x, int y);

// return 0成功，-1失败
int linklist_delete_tail(struct SnackLinkList *head);

#ifdef __cplusplus
}
#endif
#endif // __LINKLIST_H__
