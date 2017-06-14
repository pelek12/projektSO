#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>
#include <time.h>
char m[10];
char n[10];
char temp=' ';
char temp2=' ';
int licznik=0;
int zrodlo1=0;
int zrodlo2=0;	
char macierz[10][10];
	std::mutex mx;
std::queue <int> kolejka1;
std::queue <int> kolejka2;
void producent(){
	while (true){
std::this_thread::sleep_for(std::chrono::milliseconds(500));
 mx.lock();
	kolejka1.push(std::rand()%10);
	kolejka2.push(std::rand()%10);
 mx.unlock();

	}
		
}
void ncurses(){
	while(true){
		  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		  clear();
				for(int i=0; i < 10; i++){
	 for(int j=9; j >0 ; j--){
              macierz[i][j] = macierz[i][j-1];
	 }			macierz[i][0]= ' ';
				}

    

for(int i=0; i < 10; i++){

    for(int j=0; j < 10; j++){
		if (macierz[i][j]==' ')
		printw(" %c",' ');
			else
        printw(" %c",macierz[i][j]);
    }
    printw("\n");

}
			refresh();
	}}				  
void przetwarzacz(){
	while (true){
	  std::this_thread::sleep_for(std::chrono::milliseconds(500)); // sleep(4);
 		 mx.lock();
	     macierz[kolejka1.front()][kolejka2.front()]='+';
 
		kolejka1.pop();
		kolejka2.pop();
		 mx.unlock();
	
	}	


	}


int main(){
		srand( time( NULL ) );
for(int i=0; i < 10; i++){

    for(int j=0; j < 10; j++){
      macierz[i][j]=' ';
	}

}
	
	initscr();
//	printw("podaj szerokosc macierzy");
	//getstr(m);
	//printw("podaj wysokosc macierzy");
	//getstr(n);
	//zrodlo1=std::rand()%atoi(m);
	//zrodlo2=std::rand()%atoi(m);
  	auto przetwarzaczThread = std::thread(przetwarzacz); 
 	auto producentThread = std::thread(producent); 
    auto ncursesThread = std::thread(ncurses); 
        przetwarzaczThread.join();
      	ncursesThread.join();
		producentThread.join();
getch();

	endwin();
}
