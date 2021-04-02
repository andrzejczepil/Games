#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
const int L = 8;
const int K = 11;
const int M = 5;

struct wsp{
	int x;
	int y;
};
//45
void wyswietlanie(int plansza[][K],int plansza_miejsc_niebezpiecznych[][K]){ //funkcja wyswietlajaca    cout<<endl;
    for(int i=0;i<L;i++){
        cout<<"---------------------------------------------"<<endl;
        cout<<"|";
        for(int j=0;j<K;j++){
            switch(plansza[i][j]){
                case 5 : //pole na ktorym jest gracz
                    if(plansza_miejsc_niebezpiecznych[i][j]==0){ // pole na ktorym jest gracz jesli w poblizu nie ma min
                        cout<<setw(2)<<" # ";
                    }
                    else if(plansza_miejsc_niebezpiecznych[i][j]==1){//pole na ktorym jest gracz jesli w poblizu mina
                        cout<<setw(2)<<"!#!";
                    }
                    break;
                case 0 : // pole bez miny
                    if(plansza_miejsc_niebezpiecznych[i][j]==0){//pole na ktorym gracz byl i brak min w poblizu
                        cout<<setw(2)<<" . ";
                    }
                    else if(plansza_miejsc_niebezpiecznych[i][j]==1){ // pole na ktorym gracz byl i byla mina
                        cout<<setw(2)<<" ! ";
                    }
                    else {
                        cout<<setw(2)<<"   ";
                    }
                    break;
                case 1 : //pole gdzie jest mina
                    cout<<setw(2)<<"   ";
                    break;
                default:
                    cout<<"blad";
                    break;
            }
            cout<<"|";
        }
        cout<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
}

int poruszanie (wsp gracz, wsp mina[M]){
    if (((gracz.x-1==mina[0].x) && (gracz.y==mina[0].y)) || ((gracz.x+1==mina[0].x) && (gracz.y==mina[0].y)) || ((gracz.x==mina[0].x) && (gracz.y-1==mina[0].y)) || ((gracz.x==mina[0].x) && (gracz.y+1==mina[0].y)) || ((gracz.x-1==mina[1].x) && (gracz.y==mina[1].y)) || ((gracz.x+1==mina[1].x) && (gracz.y==mina[1].y)) || ((gracz.x==mina[1].x) && (gracz.y-1==mina[1].y)) || ((gracz.x==mina[1].x) && (gracz.y+1==mina[1].y)) || ((gracz.x-1==mina[2].x) && (gracz.y==mina[2].y)) || ((gracz.x+1==mina[2].x) && (gracz.y==mina[2].y)) || ((gracz.x==mina[2].x) && (gracz.y-1==mina[2].y)) || ((gracz.x==mina[2].x) && (gracz.y+1==mina[2].y)) || ((gracz.x-1==mina[3].x) && (gracz.y==mina[3].y)) || ((gracz.x+1==mina[3].x) && (gracz.y==mina[3].y)) || ((gracz.x==mina[3].x) && (gracz.y-1==mina[3].y)) || ((gracz.x==mina[3].x) && (gracz.y+1==mina[3].y)) || ((gracz.x-1==mina[4].x) && (gracz.y==mina[4].y)) || ((gracz.x+1==mina[4].x) && (gracz.y==mina[4].y)) || ((gracz.x==mina[4].x) && (gracz.y-1==mina[4].y)) || ((gracz.x==mina[4].x) && (gracz.y+1==mina[4].y))){
    return 1;
	}
	else{
    return 0;
	}
    
}

int main (){
	
	wsp gracz;
	wsp start;
	wsp koniec;
	wsp mina[M];
	start ={7,0};
	koniec={0,10};
	char ruch_gracza;
    int rand_x;
    int rand_y;
    int plansza[L][K];
    int plansza_miejsc_niebezpiecznych[L][K];
    srand( static_cast<unsigned int>(time(NULL)));
    for(int i=0;i<M;i++){
        mina[i].x=0;
        mina[i].y=0;
    }

    for(int i=0;i<M;i++){
    rand_x=(rand()%(L-1))+1;
	rand_y=(rand()%(K-1))+1;
        
        while(((rand_x==mina[0].x) && (rand_y==mina[0].y))||((rand_x==mina[1].x) && (rand_y==mina[1].y))||((rand_x==mina[2].x) && (rand_y==mina[2].y))||((rand_x==mina[3].x) && (rand_y==mina[3].y))|| ((rand_x==mina[4].x) && (rand_y==mina[4].y))){
		 rand_x=(rand()%(L-1)) + 1;
		 rand_y=(rand()%(K-1)) + 1;
	}
	mina[i].x=rand_x;
	mina[i].y=rand_y;
        
}
    for (int i=0; i<L; i++)
        for(int j=0; j<K; j++){
            plansza[i][j]=0;
            plansza_miejsc_niebezpiecznych[i][j]=3;
        }
    
    for (int i=0; i<5; i++){
        plansza[mina[i].x][mina[i].y]=1;
    }
    cout<<"^^^^^^ GRA ZWIADOWCA ^^^^^^"<<endl;
    cout<<endl;
    cout<<"Zasady gry:"<<endl;
    cout<<"1. Gracz ma za zadanie przeprowadzic zwiadowce z lewego dolnego rogu planszy do prawego gornego rogu."<<endl;
    cout<<"2. Na planszy umieszczone sa miny."<<endl;
    cout<<"3. Gra konczy sie po wejsciu zwiadowcy na mine (przegrana) lub po dotarciu"<<endl<<"na mete (wygrana)."<<endl;
    cout<<endl;
    gracz=start;
    plansza[gracz.x][gracz.y]=5;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=0;
        wyswietlanie(plansza,plansza_miejsc_niebezpiecznych);
        
    while((((gracz.x!=mina[0].x)&&(gracz.y!=mina[0].y))||((gracz.x!=mina[1].x)&&(gracz.y!=mina[1].y))||((gracz.x!=mina[2].x)&&(gracz.y!=mina[2].y))||((gracz.x!=mina[3].x)&&(gracz.y!=mina[3].y))||((gracz.x!=mina[4].x)&&(gracz.y!=mina[4].y))) || ((gracz.x!=koniec.x)&&(gracz.y!=koniec.y))){ //wszystko co w srodku powtarza sie tak dlugo jak gracz nie wejdzie na mine lub nie doszedl do pola koncowego

        cout<<endl<<"Twoj ruch (g-gora, d-dol, l-lewo, p-prawo): ";
        cin>>ruch_gracza;
        
        switch(ruch_gracza){
            case 'g':
            	if (gracz.x-1<0){
				cout<<"BLAD, SCIANA!!"<<endl;
		    	}
			    else{
    plansza[gracz.x][gracz.y]=0;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina); 
	          gracz.x = gracz.x - 1;
	plansza[gracz.x][gracz.y]=5;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);
}
                break;
                
            case 'd':
            	if (gracz.x>6){
            	cout<<"BLAD, SCIANA!!"<<endl;
			    }
			    else{
    plansza[gracz.x][gracz.y]=0;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);        	
                gracz.x = gracz.x + 1;
    plansza[gracz.x][gracz.y]=5;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);
}
                break;
                
            case 'l':
            	if (gracz.y-1<0){
            	cout<<"BLAD, SCIANA!!"<<endl;
                }
                else{
    plansza[gracz.x][gracz.y]=0;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);        	
            gracz.y = gracz.y - 1;
	plansza[gracz.x][gracz.y]=5;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);
}
                break;

            case 'p': 
            if (gracz.y>9){
            	cout<<"BLAD, SCIANA!!"<<endl;
			}
			else{
    plansza[gracz.x][gracz.y]=0;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);
            gracz.y = gracz.y + 1;
    plansza[gracz.x][gracz.y]=5;
    plansza_miejsc_niebezpiecznych[gracz.x][gracz.y]=poruszanie (gracz, mina);
}
                break;
            default:
                cout<<"Blad"<<endl;
                break;
        }
        wyswietlanie(plansza,plansza_miejsc_niebezpiecznych);
	//koniec gry
    if((gracz.x==koniec.x)&&(gracz.y==koniec.y)){
    	
        cout<<endl<<"-----BRAWO WYGRALES!-----"<<endl;
        exit(0);
    }
    else if (((gracz.x==mina[0].x)&&(gracz.y==mina[0].y))||((gracz.x==mina[1].x)&&(gracz.y==mina[1].y))|| ((gracz.x==mina[2].x)&&(gracz.y==mina[2].y)) || ((gracz.x==mina[3].x)&&(gracz.y==mina[3].y)) || ((gracz.x==mina[4].x)&&(gracz.y==mina[4].y))){
        
		cout<<endl<<"-----PRZEGRANA, wszedles na mine!-----"<<endl;
        for(int i=0;i<L;i++){
            cout<<"---------------------------------------------"<<endl;
            cout<<"|";
            for(int j=0;j<K;j++){
                switch(plansza[i][j]){
                    case 5 : {//pole na ktorym jest gracz
                        cout<<setw(2)<<" & ";
                    }
                        break;
                    case 0 : // pole bez miny
                        if(plansza_miejsc_niebezpiecznych[i][j]==0){//pole na ktorym gracz byl i brak min w poblizu
                            cout<<setw(2)<<" . ";
                        }
                        else if(plansza_miejsc_niebezpiecznych[i][j]==1){ // pole na ktorym gracz byl i byla mina
                            cout<<setw(2)<<" ! ";
                        }
                        else {
                            cout<<setw(2)<<"   ";
                        }
                        break;
                    case 1 : //pole gdzie jest mina
                        cout<<setw(2)<<" * ";
                        break;
                    default:
                        cout<<"blad";
                        break;
                }
                cout<<"|";
            }
            cout<<endl;
        }
        cout<<"---------------------------------------------"<<endl;
        
        exit(0);
    }
}
        
    

return 0;
}





