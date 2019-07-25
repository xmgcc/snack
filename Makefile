all:
	gcc linklist.c snack.c -lncurses -o snack
clean:
	rm snack
