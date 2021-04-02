
#include<iostream>
#include<fstream>
#include<cstring>
#include<ctime>
#include<cstdlib>

using namespace std;

const int MAX_A=100; //max ilosc dat
const int MAX_P=4; //max ilosc pytan na zadanie
const int MAX_Z=2; //max ilosc zadan na ture (uzytkownika)

struct wydarzenia{
    /*  struktura do zapamietania danych z pliku    */
    char data[80];
    int rok;
    int miesiac;
    int dzien;
    string nazwa;
};

struct gracze{
    /*  struktura do zapamietania informacji o graczu   */
    int punkty;
    char nazwij[80];
};

int sprawdzanie(int random,int ilosc,int TAB_A[MAX_A]){
    /*  Funkcja sprawdzajaca czy wczesniej nie wylosowano   */
    int a=0;
    for(int i=0;i<ilosc;i++){
        if(random==TAB_A[i]){
            return 1;
        }
        else{
            a=0;
        }
    }
    return a;
}

/*  Sortowanie dat za pomoca funkcji do tablicy B zapamietujacej poprawna kolejnosc */
/*  Gdy data nie ma miesiecy ani dni ( miesiac i dzien == 0 to uznawane za wczesniejsze wydarzenie niz inne w danym roku ktore okreslone jest rowniez na dzien lub miesiac  */
void sort(wydarzenia wydarzenie_quiz[MAX_Z][MAX_P], int TAB_B[MAX_Z][MAX_P])
{
    for(int g=0;g<MAX_Z;g++){
        for(int i=0;i<MAX_P;i++){
            for(int j=1;j<MAX_P-i;j++){
                if(wydarzenie_quiz[g][TAB_B[g][j-1]].rok>wydarzenie_quiz[g][TAB_B[g][j]].rok){
                    swap(TAB_B[g][j-1], TAB_B[g][j]);
                }
                else if(wydarzenie_quiz[g][TAB_B[g][j-1]].rok==wydarzenie_quiz[g][TAB_B[g][j]].rok){
                    if(wydarzenie_quiz[g][TAB_B[g][j-1]].miesiac>wydarzenie_quiz[g][TAB_B[g][j]].miesiac){
                        swap(TAB_B[g][j-1], TAB_B[g][j]);
                    }
                    else if(wydarzenie_quiz[g][TAB_B[g][j-1]].dzien>wydarzenie_quiz[g][TAB_B[g][j]].dzien){
                        swap(TAB_B[g][j-1], TAB_B[g][j]);
                    }
                }
            }
        }
    }
            
}


int main(){
    char koniec('\n'); //ogranicznik wczytywania
    int ilosc=0; //ilosc linijek w pliku z
    wydarzenia wydarzenie[MAX_A]; //tablica struktur zapamietujaca wszystkie daty
    wydarzenia wydarzenie_quiz[MAX_Z][MAX_P]; // ulozona w losowej kolejnosci tablica stuktur
    char daty[80]; //zmienna przechowujaca nazwe pliku z datami
    char Wyniki[80];
    int random=-1; // zmienna do generowania liczb pseudolosowych
    int pomocnicza=0; //zmienna pomocnicza do uzywania jako indeks tablicy w petlach ect.
    int TAB_A[MAX_A]; //tablica zawierajaca indeksy tablicy struktur w zamienionej losowo kolejnosci
    int TAB_B[MAX_Z][MAX_P]; //tablica zapamietujaca kolejnoscc wlasciwa odpowiedzi
    int ilosc_graczy=0; //zmienna przechowujaca ilosc graczy
    gracze gracz[ilosc_graczy]; //struktura zawierajaca punkty i nazwe gracza
    int a,b,c,d; //zmienna przechowujac odpowiedzi
    srand( static_cast<unsigned int>(time(NULL)));
    
    /*  Pobieranie danych z pliku   */
    cout << "Podaj nazwe pliku z datami : "; //instrukcja po ktorej nastepuje zapamietanie nazwy
    cin >> daty;
    ifstream plik(daty); //otwarcie pliku
    if (!plik) { //sprawdzenie czy otwarcie nastapilo
        cerr << "Nieudane otwarcie pliku wejsciowego" << daty <<endl;
        return 1;
    }
    else{
        while(plik){
            plik>>wydarzenie[ilosc].data;
            getline(plik,wydarzenie[ilosc].nazwa,koniec);
            ilosc++;
            }
        ilosc--;
        }
        plik.close();
    
    for(int i=0;i<ilosc;i++){
        /*  Zmienne pomocnicze  */
        int rok_tysiace = 0;
        int rok_setki = 0;
        int rok_dziesiatki = 0;
        int rok_jednosci = 0;
        int miesiac_dziesiatki = 0;
        int miesiac_jednosci = 0;
        int dzien_dziesiatki = 0;
        int dzien_jednosci = 0;
        
        /*  rozkladanie zapamietanej daty na dni miesiace i lata  */
        
        if (isdigit(wydarzenie[i].data[0])){
            rok_tysiace=wydarzenie[i].data[0]-'0';
            rok_setki=wydarzenie[i].data[1]-'0';
            rok_dziesiatki=wydarzenie[i].data[2]-'0';
            rok_jednosci=wydarzenie[i].data[3]-'0';
        }
        else{
            cout<<" Blad, brak roku lub zle podany "<<endl;
            return 1;
        }
        if (isdigit(wydarzenie[i].data[5])){
            miesiac_dziesiatki=wydarzenie[i].data[5]-'0';
            miesiac_jednosci=wydarzenie[i].data[6]-'0';
        }
        if (isdigit(wydarzenie[i].data[8])){
            dzien_dziesiatki=wydarzenie[i].data[8]-'0';
            dzien_jednosci=wydarzenie[i].data[9]-'0';
        }
        wydarzenie[i].rok=(1000*rok_tysiace)+(100*rok_setki)+(10*rok_dziesiatki)+rok_jednosci;
        wydarzenie[i].miesiac=(10*miesiac_dziesiatki)+miesiac_jednosci;
        wydarzenie[i].dzien=(10*dzien_dziesiatki)+dzien_jednosci;
    }
    
    /*  Sprawdzanie poprawnosci Danych  */
    
    for(int i=0;i<ilosc;i++)
    {
        if(wydarzenie[i].miesiac==0&&wydarzenie[i].dzien==0){
            
        }
        
        else if ((wydarzenie[i].miesiac<0)||(wydarzenie[i].miesiac>12)){
            cout<<endl<<"Blad w miesiacu daty : "<<wydarzenie[i].data<<endl;
            return 1;
        }
        else {
            switch(wydarzenie[i].miesiac){
                    
                case 1:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 2:
                    if(((wydarzenie[i].rok % 4 == 0) && (wydarzenie[i].rok % 100 != 0)) || (wydarzenie[i].rok % 400 == 0)){
                        /*lata przestepne*/
                        if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>29) ){
                            cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                            return 1;
                        }
                    }
                    else{
                        if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>28) ){
                            cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                            return 1;
                        }
                    }
                    
                    break;
                    
                case 3:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    break;
                    
                case 4:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>30) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 5:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    break;
                    
                case 6:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>30) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 7:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 8:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 9:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>30) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 10:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 11:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>30) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
                    
                case 12:
                    if((wydarzenie[i].dzien<1)||(wydarzenie[i].dzien>31) ){
                        cout<<"Blad w dniu daty : "<<wydarzenie[i].data<<endl;
                        return 1;
                    }
                    
                    break;
            }
        }
    }
    
    /*  Rozpoczecie Tworzenia gry   */
    cout<<endl<<"Podaj ilosc graczy : ";
    cin>>ilosc_graczy;
    

    /*  Petla powtarzana dla kazdego kolejnego gracza   */
    for(int k=0;k<ilosc_graczy;k++){

        
        for(int i=0;i<ilosc;i++){ //"Oczyszczanie" tablicy zapamietujacej nowa kolejnosc
            TAB_A[i]=-1;
        }
        
        /*  LOSOWANIE KOLEJNOSCI    */
        
        for(int i=0;i<ilosc;i++){
            random = (rand() % ilosc);
            while(sprawdzanie(random,ilosc,TAB_A)){
                random = (rand() % ilosc);
            }
            TAB_A[i]=random; //tablica wypelniona indeksami odpowiadajacymi nowej kolejnosci
        }
        
        
        /*  przypisanie nowej pseudolosowej kolejnosci  */
        pomocnicza=0;
        for(int i=0;i<MAX_Z;i++){
            for(int j=0;j<MAX_P;j++){
                if((pomocnicza+1)>ilosc){
                    cout<<endl<<"Za malo pytan w pliku"<<endl; //wykluczenie syt. gdzie za malo pytan
                    return 1;
                }
                else{
                    TAB_B[i][j]=j; //obecna kolejnosc w tablicy
                    wydarzenie_quiz[i][j].nazwa=wydarzenie[TAB_A[pomocnicza]].nazwa;
                    wydarzenie_quiz[i][j].rok=wydarzenie[TAB_A[pomocnicza]].rok;
                    wydarzenie_quiz[i][j].miesiac=wydarzenie[TAB_A[pomocnicza]].miesiac;
                    wydarzenie_quiz[i][j].dzien=wydarzenie[TAB_A[pomocnicza]].dzien;
                    for(int g=0;g<80;g++){
                        wydarzenie_quiz[i][j].data[g]=wydarzenie[TAB_A[pomocnicza]].data[g];
                    }
                    pomocnicza++;
                }
            }
        }
        /*  ustalenie kolejnosci prawidlowej wylosowanych dat   */
        
        /*  rozpoczecie gry dla graczy  */
        
        cout<<endl<<"Podaj nazwe gracza "<<k+1<<" : ";
        cin>>gracz[k].nazwij;
        cout<<endl;
        gracz[k].punkty=0;
        
        sort(wydarzenie_quiz,TAB_B);
        
        a=0;
        b=0;
        c=0;
        d=0;
        
        /*  Wyswietlenie pytan oraz pobranie odpowiedzi */
        for(int i=0;i<MAX_Z;i++){
            cout<<endl<<"ZADANIE NR "<<i+1<<" :"<<endl;
            
            for(int j=0;j<MAX_P;j++){
                cout<<"NR."<<j+1<<" "<<wydarzenie_quiz[i][j].nazwa<<endl;
            }
            cout<<endl<<"Podaj poprawna kolejnosc powyzszych dat wpisujac kolejnosc chronologicznie za pomoca liczb od 1 do 4 oddzielajac poprzez 'enter'"<<endl;
            cin>>a>>b>>c>>d;
            if(((a-1)==TAB_B[i][0])&&((b-1)==TAB_B[i][1])&&((c-1)==TAB_B[i][2])&&((d-1)==TAB_B[i][3])){
                cout<<endl<<"Dobrze !"<<endl;
                
                for(int j=0;j<MAX_P;j++){
                    cout<<"NR."<<TAB_B[i][j]+1<<" "<<wydarzenie_quiz[i][TAB_B[i][j]].nazwa<<" Rok - "<<wydarzenie_quiz[i][TAB_B[i][j]].data<<endl;
                }
                
                gracz[k].punkty++;
            }
            else{
                cout<<endl<<"ZLE ! Poprawna kolejność to : "<<endl;
                
                for(int j=0;j<MAX_P;j++){
                    cout<<"NR."<<TAB_B[i][j]+1<<" "<<wydarzenie_quiz[i][TAB_B[i][j]].nazwa<<" Rok - "<<wydarzenie_quiz[i][TAB_B[i][j]].data<<endl;
                }
            }
        }
        
    }
    
    /*  Zapisywanie wynikow do pliku    */
    
    cout << "Podaj nazwe pliku na wyniki: "; //instrukcja po ktorej nastepuje zapamietanie nazwy pliku
    cin >> Wyniki;
    fstream wyniczek( Wyniki, ios::app);
    if( wyniczek.good() ){
        wyniczek<<endl<<"Wynik z lekcji : "<<daty<<endl;
        for(int i=0;i<ilosc_graczy;i++){
            wyniczek<<" Login : "<<gracz[i].nazwij<<" | Punkty Zdobyte : "<<gracz[i].punkty<<endl;
        }
        
        wyniczek.close(); //zakonczenie operacji na pliku
    }
    else{
        cerr << "Nieudane zapisanie pliku " <<Wyniki<<endl;
        return 1;
        
    }
    
    cout<<endl;
return 0;
}
