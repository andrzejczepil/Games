#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<locale>
//Users/andi/Documents/ksiazka.txt
//Users/andi/Documents/wiadomosc.txt
//Users/andi/Documents/plik.txt
//Users/andi/Documents/plik_2.txt
const int MAX_N=100;
using namespace std;

struct slowo{
    int x;
    int y;
};
int sprawdzanie (int &m,int &k,int numer_ksiazka, int numer_2_ksiazka[numer_ksiazka], string sprawdzany, string ksiazka_podzielona[MAX_N][MAX_N]){
    for(int i=0;i<numer_ksiazka;i++){
        for(int j=0;j<numer_2_ksiazka[i];j++){
            if(sprawdzany==ksiazka_podzielona[i][j]){
                cout<<"Slowo : \""<<sprawdzany<<"\" | Znaleziono w  wierszu : "<<i+1<<" slowo nr : "<<j+1<<endl;
                m=i;
                k=j;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int numer_ksiazka=0;
    int numer_2_ksiazka[MAX_N];
    string ksiazka[MAX_N];
    string ksiazka_podzielona[MAX_N][MAX_N];
    char nazwaPliku[80];
    int numer_zdanie=0;
    int numer_2_zdanie[MAX_N];
    string zdanie[MAX_N];
    string zdanie_podzielone[MAX_N][MAX_N];
    string slowa_nieznalezione[MAX_N][MAX_N];
    char nazwaPliku_2[80];
    string sprawdzany;
    int m=-1;
    int k=-1;
    int M[MAX_N][MAX_N];
    int K[MAX_N][MAX_N];
    char nazwaPliku_W[80];
    char nazwaPliku_W_2[80];
    
    cout << "Podaj nazwe pliku z ksiazka szyfrujaca : ";
    cin >> nazwaPliku;
    cout<<endl;
    fstream plik(nazwaPliku);
    
    if (!plik) {
        cerr << "Nieudane otwarcie pliku z ksiazka szyfrujaca" << nazwaPliku<<endl;
        return 1;
    }
    else{
        while(plik){
            getline(plik,ksiazka[numer_ksiazka]);
            numer_ksiazka++;
        }
        numer_ksiazka--;
        plik.close();
    }
    for (int i=0; i<MAX_N; i++){
        numer_2_ksiazka[i]=0;
        numer_2_zdanie[i]=0;
        for (int j=0;j<MAX_N; j++){
            M[i][j]=-1;
            K[i][j]=-1;
        }
    }
    for(int i=0;i<numer_ksiazka;i++){
        istringstream podzial(ksiazka[i]);
        while (podzial){
            podzial>>ksiazka_podzielona[i][numer_2_ksiazka[i]];
            numer_2_ksiazka[i]++;
        }
        numer_2_ksiazka[i]--;
    }
    for(int i=0;i<numer_ksiazka;i++){
        for (int j=0;j<(numer_2_ksiazka[i]);j++) {
            cout <<"wiersz = "<<i+1<<" , slowo nr = "<<j+1<<" slowo : "<<ksiazka_podzielona[i][j] << endl;
        }
        cout<<endl;
    }
    cout<<endl<< "Podaj nazwe pliku z zaszyfrowana wiadomoscia : ";
    cin >> nazwaPliku_2;
    cout<<endl;
    fstream plik_2(nazwaPliku_2);
    
    if (!plik_2) {
        cerr << "Nieudane otwarcie pliku z wiadomoscia" << nazwaPliku_2<<endl;
        return 1;
    }
    else{
        while(plik_2){
            getline(plik_2,zdanie[numer_zdanie]);
            numer_zdanie++;
        }
        numer_zdanie--;
        plik_2.close();
    }
    for(int i=0;i<numer_zdanie;i++){
        istringstream podzial_2(zdanie[i]);
        while (podzial_2){
            podzial_2>>zdanie_podzielone[i][numer_2_zdanie[i]];
            numer_2_zdanie[i]++;
        }
        numer_2_zdanie[i]--;
    }
    for(int i=0;i<numer_zdanie;i++){
        for (int j=0;j<(numer_2_zdanie[i]);j++) {
            cout <<"wiersz nr = "<<i+1<<" , slowo nr = "<<j+1<<" to slowo : "<<zdanie_podzielone[i][j] << endl;
        }
        cout<<endl;
    }
    
    cout<<endl<<endl;
    
    for (int i=0; i<numer_zdanie; i++){
        for (int j=0;j<numer_2_zdanie[i]; j++){
            sprawdzany=zdanie_podzielone[i][j];
            if(sprawdzanie(m,k,numer_ksiazka,numer_2_ksiazka,sprawdzany,ksiazka_podzielona)==1){
                M[i][j]=m+1;
                K[i][j]=k+1;
            }
            else{
                cout<<"Nie znaleziono slowa : "<<sprawdzany<<endl;
                slowa_nieznalezione[i][j]=sprawdzany;
            }
        }
    }
    
    cout<<endl<<endl<< "Podaj nazwe pliku do zapisania zaszyfrowanej wiadomosci ladnie : ";
    cin >> nazwaPliku_W;
    fstream plik_3( nazwaPliku_W, std::ofstream::out | std::ofstream::trunc );
    if( plik_3.good() )
    {
        plik_3<<"Rozpoczecie Szyfrowanej wiadomosci , \" |  \" odpowiada spacji  "<<endl<<"|A,B| gdzie A - nr wiersza, B - nr slowa w tym wierszu, w ksiazce szyfrujacej.";
        for(int i=0; i<numer_zdanie; i++){
            plik_3<<endl<<"|";
            for(int j=0;j<numer_2_zdanie[i]; j++){
                if((M[i][j]==-1)||(K[i][j]==-1)){
                    plik_3<<slowa_nieznalezione[i][j]<<"|";
                }
                else{
                    plik_3<<M[i][j]<<","<<K[i][j]<<"|";
                }
            }
        }
        plik_3<<endl<<"| Koniec wiadomosci |";
        plik_3.close();
    }
    else{
        cerr << "Nieudane zapisanie pliku " << nazwaPliku_W<<endl;
        return 1;
    }
    
    cout << "Podaj nazwe pliku do zapisania wiadomosci dla programu deszyfrujacego : ";
    cin >> nazwaPliku_W_2;
    fstream plik_4( nazwaPliku_W_2, std::ofstream::out | std::ofstream::trunc );
    if( plik_4.good() )
    {
        for(int i=0; i<numer_zdanie; i++){
            for(int j=0;j<numer_2_zdanie[i]; j++){
                if((M[i][j]==-1)||(K[i][j]==-1)){
                    plik_4<<slowa_nieznalezione[i][j]<<" ";
                }
                else{
                    plik_4<<M[i][j]<<" "<<K[i][j]<<" ";
                }
            }
            plik_4<<endl;
        }
        plik_4.close();
    }
    else{
        cerr << "Nieudane zapisanie pliku " << nazwaPliku_W_2<<endl;
        return 1;
    }
    
    
    /*    zad 2   */

    char nazwaPliku_5[80];
    int numer_zaszyfr=0;
    int numer_2_zaszyfr[MAX_N];
    string zaszyfr[MAX_N];
    string zaszyfr_podzielona[MAX_N][MAX_N];
    slowo slowko[MAX_N][MAX_N];
    
    cout << "Podaj nazwe pliku z zaszyfrowana wiadomoscia : ";
    cin >> nazwaPliku_5;
    cout<<endl;
    fstream plik_5(nazwaPliku_5);
    
    if (!plik_5) {
        cerr << "Nieudane otwarcie pliku z zaszyfrowana wiadomoscia" << nazwaPliku<<endl;
        return 1;
    }
    else{
        while(plik_5){
            getline(plik_5,zaszyfr[numer_zaszyfr]);
            numer_zaszyfr++;
        }
        numer_zaszyfr--;
        plik_5.close();
    }
    for (int i=0; i<MAX_N; i++){
        numer_2_zaszyfr[i]=0;
    }
    for(int i=0;i<numer_zaszyfr;i++){
        istringstream podzial_5(zaszyfr[i]);
        while (podzial_5){
            podzial_5>>zaszyfr_podzielona[i][numer_2_zaszyfr[i]];
            numer_2_zaszyfr[i]++;
        }
        numer_2_zaszyfr[i]--;
    }
    
    int liczby[MAX_N][MAX_N];
    
    string pomocniczy;
    
    for(int i=0;i<numer_zaszyfr;i++){
        for(int j=0;j<numer_2_zaszyfr[i];j++){
            pomocniczy=zaszyfr_podzielona[i][j];
            locale loc;
            if (isdigit(pomocniczy[0],loc))
            {
                stringstream(pomocniczy) >> liczby[i][j];
            }
            else{
                liczby[i][j]=-1;
            }
        }
    }
    for(int i=0;i<numer_zaszyfr;i++){
        for(int j=0;j<numer_2_zaszyfr[i];j++){
            if(liczby[i][j]==-1){
                j++;
            }
            else{
                if(liczby[i][j-2]==-1){
                    slowko[i][j].x=(liczby[i][j-1]);
                    slowko[i][j].y=(liczby[i][j]);
                }
                else{
                    slowko[i][j].x=(liczby[i][j]);
                    slowko[i][j].y=(liczby[i][j+1]);
                    j++;
                }
            }
        }
    }
    for(int i=0;i<numer_zaszyfr;i++){
        cout<<endl<<"| ";
        for(int j=0;j<numer_2_zaszyfr[i];j++){
            if(liczby[i][j]!=-1){
                if((slowko[i][j].x!=0)||(slowko[i][j].y!=0)){
                    cout<<ksiazka_podzielona[slowko[i][j].x-1][slowko[i][j].y-1]<<" | ";
                }
            }
            else{
                cout<<zaszyfr_podzielona[i][j]<<" | ";
            }
        }
        cout<<endl;
    }
    
    return 0;
}
