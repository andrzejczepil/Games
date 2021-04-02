
//Xcode 9.4 LLVM Compiler

//szerokosc standardowa 596
//punkt (0,0) to wsp (298,422)
//wysokosc standardowa 844
#include<cstdlib>
#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;

const int MAX_N = 100; // ilosc maksymalna punktow

struct wspolrzedne{ //struktura opisujaca punkt w ukladzie wspolrzednych
    float x;
    float y;
};

void sortowanie_babelkowe(wspolrzedne wspolrzedna[MAX_N], int numer) //funkcja sortujaca po zmiennej x
{
    for(int i=0;i<numer;i++)
        for(int j=1;j<numer-i;j++) //pętla wewnętrzna
            if(wspolrzedna[j-1].x>wspolrzedna[j].x)//zamiana miejscami
                swap(wspolrzedna[j-1], wspolrzedna[j]);
}


int main()
{
    wspolrzedne wspolrzedna[MAX_N]; //tablica wspolrzednych do wczytania z pliku tekstowego
    int numer=0; //wielkość ostateczna linijek tekstu
    char nazwaPliku[80]; //zmiena przechowujaca nazwe pliku wejsciowego
    char nazwaPliku_W[80]; //zmiena przechowujaca nazwe pliku wyjsciowego
    wspolrzedne najwiekszy;
    wspolrzedne najmniejszy;
    
    cout << "Podaj nazwe pliku wejsciowego : "; //instrukcja po ktorej nastepuje zapamietanie nazwy pliku
    cin >> nazwaPliku;
    ifstream ifs(nazwaPliku); //otwarcie pliku
    
    if (!ifs) { //sprawdzenie czy otwarcie nastapilo
        cerr << "Nieudane otwarcie pliku wejsciowego" << nazwaPliku<<endl;
        return 1;
    }
    else{ //po tym wierszu nastepuje operacja na pliku poniewaz otwarcie sie udalo
        while(ifs){ //wczytuj tak dlugo jak plik nie jest pusty
            ifs>>wspolrzedna[numer].x; // pierwsze cyfry sa odpowiadajace zmiennej x'owej
            ifs>>wspolrzedna[numer].y; // po znaku bialy powinny znajdowac sie zmienne odpowiadajacej y'kowej
            numer++; /*powiekszenie wielkosci tablicy nastepujace po nastepnym znaku bialym czyli w przypadku prawidlowego pliku po znaku konca lini*/
        }
    ifs.close(); //zamkniecie pliku wejsciowego
        
        numer--;//pomniejszenie o 1 z uwagi na ostatni znak konca lini w pliku
        
            for(int i=0;i<numer;i++){ //wyswietlenie tablicy struktur przed sortowaniem po x'owej
                cout<<setw(4)<<wspolrzedna[i].x<<"  |  "<<setw(4)<<wspolrzedna[i].y<<endl;
            }
        
        sortowanie_babelkowe(wspolrzedna,numer); //wywowalanie funkcji sortujacej
        
        cout<<endl<<"posortowana"<<endl; //wyswietlenie posortowanej talbicy
            for(int i=0;i<numer;i++){
                cout<<setw(4)<<wspolrzedna[i].x<<"  |  "<<setw(4)<<wspolrzedna[i].y<<endl;
            }
        
        najwiekszy.x = wspolrzedna[0].x;
        najmniejszy.x = wspolrzedna[0].x;
        najwiekszy.y = wspolrzedna[0].y;
        najmniejszy.y = wspolrzedna[0].y;
        
        for( int i=1;i<numer;i++)  //znajdywanie najmniejszej i najwiekszej wartosci
        {
            if(wspolrzedna[i].x > najwiekszy.x )
                najwiekszy.x = wspolrzedna[i].x;
            
            if(wspolrzedna[i].y > najwiekszy.y )
                najwiekszy.y = wspolrzedna[i].y;
            
            if( wspolrzedna[i].x < najmniejszy.x )
                najmniejszy.x = wspolrzedna[i].x;
            
            if( wspolrzedna[i].y < najmniejszy.y )
                najmniejszy.y = wspolrzedna[i].y;
        }
        
        cout<<endl<<"Najwiekszy :  "<<" X "<<setw(5)<<najwiekszy.x<<" | Y "<<setw(5)<<najwiekszy.y<<endl;
        cout<<"Najmniejszy : "<<" X "<<setw(5)<<najmniejszy.x<<" | Y "<<setw(5)<<najmniejszy.y<<endl;
        /*wypisanie znalezionych wartosci*/
        
       while((najmniejszy.x<(-298))||(najmniejszy.y<(-422))||(najwiekszy.x>(298))||(najwiekszy.y>(422))){
           /* skalowanie w celu zmniejszenia do maksymalnej wielkosci mieszczacej sie w ukladzie */
            for(int i=0;i<numer;i++){
                wspolrzedna[i].x=((wspolrzedna[i].x)*(0.9));
                wspolrzedna[i].y=((wspolrzedna[i].y)*(0.9));
            }
            najmniejszy.x=najmniejszy.x*(0.9);
            najmniejszy.y=najmniejszy.y*(0.9);
            najwiekszy.x=najwiekszy.x*(0.9);
            najwiekszy.y=najwiekszy.y*(0.9);
        }
        
        cout<<endl<<"zmniejszona"<<endl; //wyswietlenie zmniejszonej tablicy
        for(int i=0;i<numer;i++){
            cout<<setw(8)<<wspolrzedna[i].x<<"  |  "<<setw(8)<<wspolrzedna[i].y<<endl;
        }
    while(((1.1)*najmniejszy.x>(-298))&&((1.1)*najmniejszy.y>(-422))&&((1.1)*najwiekszy.x<(298))&&((1.1)*najwiekszy.y<(422))){
        /* Powiekszenie wykresu do maksymalnej mozliwej wielkosci mieszczacej sie */
            for(int i=0;i<numer;i++){
                wspolrzedna[i].x=((wspolrzedna[i].x)*(1.1));
                wspolrzedna[i].y=((wspolrzedna[i].y)*(1.1));
            }
            najmniejszy.x=najmniejszy.x*(1.1);
            najmniejszy.y=najmniejszy.y*(1.1);
            najwiekszy.x=najwiekszy.x*(1.1);
            najwiekszy.y=najwiekszy.y*(1.1);
        }
        
        cout<<endl<<"zwiekszona"<<endl; //wyswietlenie zwiekszonej tablicy
        for(int i=0;i<numer;i++){
            cout<<setw(8)<<wspolrzedna[i].x<<"  |  "<<setw(8)<<wspolrzedna[i].y<<endl;
        }
      
    } //koniec elsa i operacji na danych
    
    
    cout << "Podaj nazwe pliku wyjsciowego : "; //instrukcja po ktorej nastepuje zapamietanie nazwy pliku
    cin >> nazwaPliku_W;
    fstream plik( nazwaPliku_W, std::ofstream::out | std::ofstream::trunc);
    if( plik.good() )
    {
        plik<<"%!PS"<<endl;
        plik<<298<<" "<<0<<" moveto"<<endl;
        plik<<298<<" "<<844<<" lineto"<<endl;
        plik<<"stroke"<<endl;
        plik<<0<<" "<<422<<" moveto"<<endl;
        plik<<596<<" "<<422<<" lineto"<<endl;
        plik<<"stroke"<<endl;
        /* powyzsze instrukcje rysuja uklad wspolrzednych na srodku strony*/
        
        plik<<(298+wspolrzedna[0].x)<<" "<<(422+wspolrzedna[0].y)<<" moveto"<<endl;
        /*rozpoczecie rysowania wykresu*/
        
        for(int i=1;i<numer;i++)
        {
            plik<<(298+wspolrzedna[i].x)<<" "<<(422+wspolrzedna[i].y)<<" lineto"<<endl;
        }
        plik<<"stroke"<<endl;
        plik<<"showpage"<<endl;
        plik.close(); //zakonczenie operacji na pliku
    }
    else{
        cerr << "Nieudane zapisanie pliku " << nazwaPliku_W<<endl;
        return 1;
        
    }
    cout<<endl;
 return 0;
}
