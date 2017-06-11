#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
char m[10];
char n[10];
char temp=' ';
char temp2=' ';
int licznik=0;
int zrodlo1=0;
int zrodlo2=0;
char macierz[3][3];
void producent(){
	
}
void ncurses(){
for(int i=0; i < 3; i++){

    for(int j=0; j < 3; j++){
		if (macierz[i][j]==' ')
		printw("%c",' ');
			else
        printw("%d",macierz[i][j]);
    }
    printw("\n");
}}
void przetwarzacz(){
	  std::this_thread::sleep_for(std::chrono::seconds(4)); // sleep(4);

 for(int i=0; i < 3; i++){
	 temp2=temp;
	 temp=macierz[i][2];
	 for(int j=0; j <1 ; j++){
	 	macierz[i][j+2]=macierz [i][j+1];
        macierz[i][j+1]=macierz[i][j];
		macierz[i][j]= temp2;
    }	
        

    
}
        macierz[0][0]=' ';

}

int main(){
		srand( time( NULL ) );
for(int i=0; i < 3; i++){

    for(int j=0; j < 3; j++){
      macierz[i][j]=licznik;
	licznik++;
    }
}
	initscr();
	printw("podaj szerokosc macierzy");
	getstr(m);
	printw("podaj wysokosc macierzy");
	getstr(n);
	zrodlo1=std::rand()%atoi(m);
	zrodlo2=std::rand()%atoi(m);
 // auto przetwarzaczThread = std::thread(przetwarzacz); 
//  auto producentThread = std::thread(producent); 
		clear();
        
      // auto ncursesThread= std::thread(ncurses);
    ncurses();
	refresh();
    
    getch();
    		clear();
while (true){
        przetwarzacz();
		refresh();
	ncurses();
	}
	refresh();

    	getch();

	endwin();
}
