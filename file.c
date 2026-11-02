all: APC.out

APC.out: main.c add.c sub.c mul.c div.c
	gcc main.c add.c sub.c mul.c div.c -o APC.out

clean:
	rm -f APC.out