check:
	gcc main.c -lncurses -lpanel -lm 
	rm ./a.out
run:
	gcc -O2 main.c -o main -lncurses -lpanel -lm 
	./main
build:
	gcc -O2 main.c -o main -lncurses -lpanel -lm
