#include <ncurses.h>
#include <cstdlib>
#include <ctime>
char m[10];
char n[10];
int main(){
	srand( time( NULL ) );
	initscr();
	printw("podaj szerokosc macierzy");
	getstr(m);
	printw("podaj wysokosc macierzy");
	getstr(n);
	mvprintw(std::rand()%atoi(m),std::rand()%atoi(n),"+");
	getch();
	endwin();
}