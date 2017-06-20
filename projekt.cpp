#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <queue>
#include <mutex>
#include <time.h>
char charM[10];
char charN[10];
int m=0;
int n=0;
char temp=' ';
char temp2=' ';
int licznik=0;
int zrodlo1=0;
int zrodlo2=0;	

int** macierz;


	std::mutex mx;
std::queue <int> kolejka1;
std::queue <int> kolejka2;
void producent(){
	while (true){
std::this_thread::sleep_for(std::chrono::milliseconds(400));
 mx.lock();
	kolejka1.push(std::rand()%m);
	kolejka2.push(std::rand()%n);
 mx.unlock();

	}
		
}
void ncurses(){
	
	while(true){
		

		  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		  clear();
    		for (int i=0;i  <n; i++)
			printw("|%d",i%10);
			printw("|\n");

for(int i=0; i < m; i++){

    for(int j=0; j < n; j++){
	
        printw("|%c",macierz[i][j]);
    }
    printw("|\n");

}	
				for(int i=0; i < m; i++){
	 for(int j=n-1; j >0 ; j--){
              macierz[i][j] = macierz[i][j-1];
	 }			
			  macierz[i][0]= ' ';
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

	
	initscr();
	printw("podaj wysokosc macierzy");
	getstr(charM);
	printw("podaj szerokosc macierzy");
	getstr(charN);
	m=atoi(charM);
	n=atoi(charN);
	
	macierz = new int*[m];
for(int i = 0; i < m; ++i)
    macierz[i] = new int[n];

	for(int i=0; i < m; i++){

    for(int j=0; j < n; j++){
	macierz[i][j]=' ';


}
	}

  	auto przetwarzaczThread = std::thread(przetwarzacz); 
 	auto producentThread = std::thread(producent); 
    auto ncursesThread = std::thread(ncurses); 
	przetwarzaczThread.join();
   	ncursesThread.join();
	producentThread.join();
getch();

	endwin();
}
