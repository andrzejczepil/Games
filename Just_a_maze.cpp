
//Xcode 9.4 LLVM Compiler

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;
const int MAX_N=8;//wielkosc w pionie labiryntu
const int MAX_M=10;//wielkosc w poziomie labiryntu

struct pozycja{ //tworzenie wzornika zapisu pozycji
    int y;
    int x;
};

struct gracz{ //tworzenie wzornika gracza
    pozycja pole;
    int zwrot;
    int punkty_energi;
};

void wysw(int labirynt[][MAX_M]){ //funkcja wyswietlajaca plansze zamieniajac cyfry na wzory
    cout<<endl;
    for(int i=0;i<MAX_N;i++){
        for(int j=0;j<MAX_M;j++){
            switch(labirynt[i][j]){
                case 0 :
                    cout<<setw(2)<<"*";
                    break;
                case 5 :
                    cout<<setw(2)<<"W";
                    break;
                case 3 :
                    cout<<setw(2)<<"?";
                    break;
                case 1 :
                    cout<<setw(2)<<" ";
                    break;
                case 4 :
                    cout<<setw(2)<<"?";
                    break;
                case 2 :
                    cout<<setw(2)<<"#";
                    break;
                default:
                    cout<<"b"<<i<<"|"<<j;
                    break;
            }
        }
        cout<<endl;
    }
}

int main(){
    pozycja wyjsc_p={4,9}; //pole startowe gracza
    int wyjsc_z=3;//zwrot startowy gracza
    int zasob_energi=500;
    pozycja kierunek[4]; //tablica mozliwych zwrotow w ukladzie wspolrzednych tablicy
    kierunek[0]={1,0};//ruch w dol
    kierunek[1]={0,1};//ruch w prawo
    kierunek[2]={-1,0}; //ruch w gore
    kierunek[3]={0,-1};//ruch w lewo
    int labirynt[MAX_N][MAX_M]; //tworzenie labiryntu
    char ruch; //zmienna odpowiadajaca wpisywanemu przez uzytkownika ruchowi w danej turze
    int licznik=1; //zmienna odpowiadajaca za ilosc pol odkrytych
    int licznik_2=0; // zmienna odpowiadajaca za ilosc pol na ktorych gracz stanal
    int rand_y; //generowane liczby randomowe
    int rand_x;
    int rand_z;
    srand( static_cast<unsigned int>(time(NULL)));
    gracz gracz_1; //tworzenie danych gracza 1
        gracz_1.pole=wyjsc_p; //przypisanie pola wyjsciowego
        gracz_1.zwrot=wyjsc_z;//przypisanie zwrotu wyjsciowego
        gracz_1.punkty_energi=zasob_energi; //przypisywanie zasobu energi na start
    
    for(int i=0;i<MAX_M;i++){ //sciana bok gorny i dolny labiryntu
        labirynt[0][i]=4;
        labirynt[(MAX_N-1)][i]=4;
    }
    for(int i=1;i<(wyjsc_p.y);i++){//sciany labiryntu bok lewy i prawy do wysokosci przejscia
        labirynt[i][0]=4;
        labirynt[i][MAX_M-1]=4;
    }
    for(int i=(wyjsc_p.y);i<(MAX_N-1);i++){ //sciany labiryntu bok lewy i prawy do wysokosci przejscia
        labirynt[i][0]=4;
        labirynt[i][MAX_M-1]=4;
    }
    labirynt[wyjsc_p.y][MAX_M-(wyjsc_p.x)-1]=4;//sciany na wysokosci wejscia
    
    labirynt[wyjsc_p.y][wyjsc_p.x]=5; // przypisanie pozycji wejscia
    
    for(int i=1;i<(MAX_N-1);i++){ //nadpisanie wnetrza jako same przejscia
        for(int j=1;j<(MAX_M-1);j++){
            labirynt[i][j]=3;
        }
    }
    labirynt[1][1]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[1][2]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[2][1]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[3][1]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[3][2]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[2][5]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][1]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][2]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[6][1]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[6][2]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[1][7]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[1][8]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[2][8]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[3][8]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][8]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[6][8]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[4][4]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[4][5]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][4]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][5]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[5][6]=4; //przypisanie scian wewnatrz labiryntu
    labirynt[gracz_1.pole.y][gracz_1.pole.x]=0;
    labirynt[4][8]=1; //przypisanie scian wewnatrz labiryntu
    
    
    cout<<endl;
 //start gry
    cout<<endl<<"Przed Toba Labirynt. Postaraj sie przejsc go odkrywajac jak najwiecej  pol i wrocic do punktu W."<<endl<<"Startujesz z energia rowna: "<<gracz_1.punkty_energi<<".pkt"<<endl<<"Ruchy : "<<endl<<"N - naprzod (15 pkt. energi)"<<endl<<"P - prawo (10 pkt. energi)"<<endl<<"L - lewo (10 pkt. energi)"<<endl<<"T - teleportacja (30 pkt. energi)"<<endl<<"* oznacza polozenie postaci"<<endl<<"Aby rozpoczac gre wcisnij N"<<endl;
    cin>>ruch;
   
    if(ruch=='N'){ //pierwszy ruch ktory musi byc wejsciem do labiryntu, inaczej gracz przegrywa
        gracz_1.punkty_energi=gracz_1.punkty_energi-15;
        licznik_2++;
        labirynt[gracz_1.pole.y][gracz_1.pole.x]=5;
        gracz_1.pole.y = gracz_1.pole.y + kierunek[gracz_1.zwrot].y;
        gracz_1.pole.x = gracz_1.pole.x + kierunek[gracz_1.zwrot].x;
        labirynt[gracz_1.pole.y][gracz_1.pole.x]=0;
        
        if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
            labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
            licznik++;
        }
        else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
            labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
            
        }
        wysw(labirynt);
    }
    else{
        cout<<"Blad rozpoczecia gry ,  Wpisz N raz jeszcze: "<<endl;
        cin>>ruch;
        if(ruch!='N'){
            cout<<"Blad rozpoczecia gry i koniec gry"<<endl;
        gracz_1.punkty_energi=0;
        }
        else{
            gracz_1.punkty_energi=gracz_1.punkty_energi-15;
            licznik_2++;
            labirynt[gracz_1.pole.y][gracz_1.pole.x]=5;
            gracz_1.pole.y = gracz_1.pole.y + kierunek[gracz_1.zwrot].y;
            gracz_1.pole.x = gracz_1.pole.x + kierunek[gracz_1.zwrot].x;
            labirynt[gracz_1.pole.y][gracz_1.pole.x]=0;
            
            if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
                
                labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
                licznik++;
            }
            else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
                
                labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
                
            }
          wysw(labirynt);
        }
    }
    while(gracz_1.punkty_energi>0 && (labirynt[gracz_1.pole.y][gracz_1.pole.x]!=5)){ //rozpoczecie rozgrywki w labiryncie
        
        //polecenie wypisujace co przed graczem
        if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==1 ){
            
            cout<<endl<<" Przed toba korytarz"<<endl;
        }
        //polecenie wypisujace co przed graczem
        else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==2 ){
            
            cout<<endl<<" Przed toba sciana"<<endl;
        }
        cout<<endl<<" Twoja Energia to:"<<gracz_1.punkty_energi<<" pkt."<<endl<<" Podaj ruch (L/P/N/T): ";
        cin>>ruch;
        
        switch(ruch){ //menu gry
            case 'N': //ruch do przodu
                if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==2 ){ //przed graczem stoi sciana
                    
                    gracz_1.punkty_energi=gracz_1.punkty_energi-15;
                    cout<<"nie da sie wejsc w sciane"<<endl;
                    //powtorzenie ruchu
                }
                else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==5 ){//przed graczem stoi wyjscie
                    
                        gracz_1.punkty_energi=gracz_1.punkty_energi-15;
                        labirynt[gracz_1.pole.y][gracz_1.pole.x]=1;
                        gracz_1.pole.y = ((gracz_1.pole.y) + (kierunek[gracz_1.zwrot].y));
                        gracz_1.pole.x = gracz_1.pole.x + kierunek[gracz_1.zwrot].x;
                        licznik_2++;
                        //wyjscie z suma punktow
                    }
                else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==1 ){//przed graczem stoi przejscie
                    
                    gracz_1.punkty_energi=gracz_1.punkty_energi-15;
                    licznik_2++;
                    labirynt[gracz_1.pole.y][gracz_1.pole.x]=1;
                    gracz_1.pole.y = gracz_1.pole.y + kierunek[gracz_1.zwrot].y;
                    gracz_1.pole.x = gracz_1.pole.x + kierunek[gracz_1.zwrot].x;
                    labirynt[gracz_1.pole.y][gracz_1.pole.x]=0;
                    
                    if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
                        
                        labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
                        licznik++;
                    }
                    else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
                        
                        labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
                        
                    }
                    //przesuniecie gracza oraz zmiana widoku planszy
                }
                break;
                
                case 'P': //obrot w prawo
                gracz_1.punkty_energi=gracz_1.punkty_energi-10;
                if (gracz_1.zwrot==0){
                    
                    gracz_1.zwrot=3;
                }
                else{
                    gracz_1.zwrot--;
                }
                if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
                    
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
                    licznik++;
                }
                else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
                    
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
                    
                }
                //obrot gracza w prawo
                break;
                
                case 'L': //obrot w lewo
                gracz_1.punkty_energi=gracz_1.punkty_energi-10;
                if (gracz_1.zwrot==3){
                    
                    gracz_1.zwrot=0;
                }
                else{
                    gracz_1.zwrot++;
                }
                if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
                    
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
                    licznik++;
                }
                else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
                    
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
                    
                }
                //obrot gracza w lewo
                break;
                
                case 'T':                                       //Teleportacja
                
                gracz_1.punkty_energi=gracz_1.punkty_energi-30;
                rand_z =(rand()%(4));
                rand_y =(rand()%(6)+1);
                rand_x =(rand()%(8)+1); //losowanie pozycji ktora nie jest sciana
                while((labirynt[rand_y][rand_x]==4 )||(labirynt[rand_y][rand_x]==2)){
                    rand_y =(rand()%(6)+1);
                    rand_x =(rand()%(8)+1);
                }
                
                labirynt[gracz_1.pole.y][gracz_1.pole.x]=1;             //wykonanie ruchu na pozycje
                gracz_1.zwrot=rand_z;                                   //wykonanie ruchu na pozycje
                gracz_1.pole.y = rand_y;  //wykonanie ruchu na pozycje
                gracz_1.pole.x = rand_x;    //wykonanie ruchu na pozycje
                
                if((labirynt[gracz_1.pole.y][gracz_1.pole.x])==3 ){
                    
                    licznik++;
                }
                
                labirynt[gracz_1.pole.y][gracz_1.pole.x]=0;
                licznik_2++;
                
                if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==3 ){
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=1;
                    licznik++;
                }
                else if((labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x])==4 ){
                    labirynt[gracz_1.pole.y+kierunek[gracz_1.zwrot].y][gracz_1.pole.x+kierunek[gracz_1.zwrot].x]=2;
                    
                }
                break;
                
                default: //blad komendy
                    cout<<"Blad Komendy!"<<endl;
                break;
        }
        wysw(labirynt); // wyswietlanie planszy
    }
    if(gracz_1.punkty_energi<=0){
    cout<<endl<<"Koniec gry ! Skonczyla Ci sie Energia i przegrales !"<<endl;
    }
    else{
        cout<<endl<<"Koniec gry"<<endl<<"Odwiedziles "<<licznik_2<<" pol"<<endl<<"Odkryles "<<licznik<<" pol"<<endl;
    }
return 0;
}
