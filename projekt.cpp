#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
char m[10];
char n[10];
int zrodlo1=0;
int zrodlo2=0;
char macierz[20][20];
void producent(){
	
}
void przetwarzacz(){


}
void ncurses(){
for(int i=0; i < 20; i++){

    for(int j=0; j < 20; j++){
        printw("%c",macierz[i][j]);
    }
    printw("\n");
}}
int main(){
		srand( time( NULL ) );
for(int i=0; i < 20; i++){

    for(int j=0; j < 20; j++){
        macierz[i][j]=' ';    
    }
}
	initscr();
	printw("podaj szerokosc macierzy");
	getstr(m);
	printw("podaj wysokosc macierzy");
	getstr(n);
	zrodlo1=std::rand()%atoi(m);
	zrodlo2=std::rand()%atoi(m);
  auto przetwarzaczThread = std::thread(przetwarzacz); 
  auto producentThread = std::thread(producent); 
		clear();
        
	macierz[10][10]='d';
    refresh();
       ncurses();

	getch();
	endwin();
}