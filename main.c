#include <strings.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include <ncurses.h>

#define PI 3.141592653589732364
#define RADIUS 40
#define MAP_MAX_X 80
#define MAP_MAX_Y 22

char map[MAP_MAX_X][MAP_MAX_Y];

int read_into_file(){
    FILE* ptr;
    char ch;
 
    ptr = fopen("src.txt", "r");
 
    if (NULL == ptr) {
        printf("file can't be opened \n");
    }
 
    int x = 0;
    int y = 0;
    do {
        ch = fgetc(ptr);
        printf("%c",ch);

        map[x][y] = (ch != '\n')?ch:' ';
        if(ch == '\n'){
            x = -1;
            y++;
        }
        x++;
    } while (ch != EOF);
    printf("\n");
    fclose(ptr);
    return 0;
}

void out__(){
    for(int y = 0; y < (int)MAP_MAX_Y; y++) {
       for(int x = 0; x < (int)MAP_MAX_X; x++) {
          printf("%c",map[x][y]);
       }
       printf("\n");
    }
}

int main(){
    for(int y = 0; y < (int)MAP_MAX_Y; y++) {
       for(int x = 0; x < (int)MAP_MAX_X; x++) {
          map[x][y] = ' ';
       }
    }
    read_into_file();
    //out__();
	double row,col;
	initscr();
	getmaxyx(stdscr,row,col);
    for(int i = 0; i < 360; i++){
        double angle = i*PI/180;
        double xshape = RADIUS * sin(angle);
        double yshape = RADIUS * cos(angle);
        yshape = yshape/2; //weil rund
        double yCoord = row/2 + yshape;
        double xCoord = col/2 + xshape;
        //mvprintw(yCoord,xCoord,"?");
        double xam = angle/(360*PI/180);
        int Xamount = (int)(xam*MAP_MAX_X);

        double yHeight = yshape - (RADIUS * cos(90*PI/180));//height -10..10 (-10 --> above 0 && 10 --> below 0)
        //for(double i = 0; (yHeight>0)? i < yHeight: i > yHeight; (yHeight>0)?i++:i--){
        //    char temp = map[(int)xam*MAP_MAX_X][(int)(((double)i/(double)yHeight)*MAP_MAX_Y)];
        //    mvprintw((int)(i+(row/2)),xCoord,&temp);
        //}
        for(int i = (int)MAP_MAX_Y/2; i > 0; i--){
        for(int i = 0; i < (int)MAP_MAX_Y/2; i++){
            double iam = i/((double)MAP_MAX_Y/(double)2);
            char temp = (yHeight > (double)0)?
                map[Xamount][(MAP_MAX_Y/2)+(int)(iam*(MAP_MAX_Y/2))]
                :
                map[Xamount][(int)(iam*(MAP_MAX_Y/2))*2];
            mvprintw((yHeight)*iam+(row/2),xCoord,&temp);
        }
    }
	refresh();
	getch();
	endwin();
	return 0;
}