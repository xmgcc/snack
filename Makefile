all:
	gcc linklist.c snack.c -lncurses -o snack -g
clean:
	rm snack
