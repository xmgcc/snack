#ifndef __LINKLIST_H__
#define __LINKLIST_H__

// c++编译器会定义__cplusplus这个宏
#ifdef __cplusplus
// 告诉c++编译器，这段代码是c代码
extern "C" {
#endif

struct SnackLinkList {
	int id;
    int x;
    int y;
	struct SnackLinkList *next;
};

// 创建链表
// data，数据数组
// data_length，数组长度
struct SnackLinkList *linklist_create(int x[], int y[], int data_length);

// 遍历链表，打印
void linklist_printf(struct SnackLinkList *head, int x, int y);

// return 0成功，-1失败
int linklist_delete(struct SnackLinkList *head, int id);

#ifdef __cplusplus
}
#endif
#endif // __LINKLIST_H__
