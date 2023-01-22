check:
	gcc -O2 main.c -o main -lncurses -lpanel -lm
run:
	gcc -O2 main.c -o main -lncurses -lpanel -lm 
	./main
build:
	gcc -O2 main.c -o main -lncurses -lpanel -lm
