all: movingtexts

movingtexts: main.c
	gcc -o movingtext main.c

clean:
	$(RM) movingtexts