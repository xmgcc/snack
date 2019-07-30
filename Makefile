snack:
	gcc linklist2.c snack.c -lncurses
test:
	gcc linklist2.c linklist2_unittest.c -o linklist2_unittest
