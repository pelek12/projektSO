#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
char m[10];
char n[10];
int zrodlo1=0;
int zrodlo2=0;
void producent(){
	
}
void przetwarzacz(){
	zrodlo1=std::rand()%atoi(m);
	zrodlo2=std::rand()%atoi(m);

}
void ncurses(){
	
}
int main(){
		srand( time( NULL ) );

	initscr();
		printw("podaj szerokosc macierzy");
	getstr(m);
	printw("podaj wysokosc macierzy");
	getstr(n);
  auto przetwarzaczThread = std::thread(przetwarzacz); 
  auto producentThread = std::thread(producent); 
  auto ncursesThread = std::thread(ncurses); 

	clear();
	mvprintw(zrodlo1,zrodlo2,"%d %d",zrodlo1,zrodlo2);
	getch();
	endwin();
}