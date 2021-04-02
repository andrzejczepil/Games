
//POP 2016-12-09 projekt 1 Czepil Andrzej EIT 2 165431
//xcode 8.0 kompilator wewnetrzny lldb

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;
char Ad[6];
int TAB_NP[6];
char Bd[6];
string X ="###";
string Y ="OOO";
string V = "   ";
char P[36]; // tablica wartosci stosów dla poczatku gry
string Z[36]; //tablica znaków w stosach na poczatku gry
char W[36];
string M[36];
int pole_P;
int pole_K;
int pion_P;
char poziom_P;
int pion_K;
char poziom_K;
int menu_P;

void Tablica_gracza_A_start (){
    
    for(int i=0;i<6;i++){
        Bd[i]= Ad[i];
    }
    
    int TAB_N[6];
    
    for(int i=0;i<6;i++){
        TAB_N[i]=TAB_NP[i];
    }
    
    for (int i=0;i<12;i++){
        P[i]='1';
        Z[i]=X;
    }
    
    for (int i=12;i<24;i++){
        P[i]=' ';
        Z[i]=V;
    }
    for (int i=24;i<36;i++){
        P[i]='1';
        Z[i]=Y;
    }
    
    
    cout <<endl<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[0]<<"  |  "<<P[1]<<"  |  "<<P[2]<<"  |  "<<P[3]<<"  |  "<<P[4]<<"  |  "<<P[5]<<"  |"<<endl
    <<" "<<TAB_N[0]<<" | "<<Z[0]<<" | "<<Z[1]<<" | "<<Z[2]<<" | "<<Z[3]<<" | "<<Z[4]<<" | "<<Z[5]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[6]<<"  |  "<<P[7]<<"  |  "<<P[8]<<"  |  "<<P[9]<<"  |  "<<P[10]<<"  |  "<<P[11]<<"  |"<<endl
    <<" "<<TAB_N[1]<<" | "<<Z[6]<<" | "<<Z[7]<<" | "<<Z[8]<<" | "<<Z[9]<<" | "<<Z[10]<<" | "<<Z[11]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[12]<<"  |  "<<P[13]<<"  |  "<<P[14]<<"  |  "<<P[15]<<"  |  "<<P[16]<<"  |  "<<P[17]<<"  |"<<endl
    <<" "<<TAB_N[2]<<" | "<<Z[12]<<" | "<<Z[13]<<" | "<<Z[14]<<" | "<<Z[15]<<" | "<<Z[16]<<" | "<<Z[17]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[18]<<"  |  "<<P[19]<<"  |  "<<P[20]<<"  |  "<<P[21]<<"  |  "<<P[22]<<"  |  "<<P[23]<<"  |"<<endl
    <<" "<<TAB_N[3]<<" | "<<Z[18]<<" | "<<Z[19]<<" | "<<Z[20]<<" | "<<Z[21]<<" | "<<Z[22]<<" | "<<Z[23]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[24]<<"  |  "<<P[25]<<"  |  "<<P[26]<<"  |  "<<P[27]<<"  |  "<<P[28]<<"  |  "<<P[29]<<"  |"<<endl
    <<" "<<TAB_N[4]<<" | "<<Z[24]<<" | "<<Z[25]<<" | "<<Z[26]<<" | "<<Z[27]<<" | "<<Z[28]<<" | "<<Z[29]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[30]<<"  |  "<<P[31]<<"  |  "<<P[32]<<"  |  "<<P[33]<<"  |  "<<P[34]<<"  |  "<<P[35]<<"  |"<<endl
    <<" "<<TAB_N[5]<<" | "<<Z[30]<<" | "<<Z[31]<<" | "<<Z[32]<<" | "<<Z[33]<<" | "<<Z[34]<<" | "<<Z[35]<<" |"<<endl;
    
    
    cout<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout << "      "<<Bd[0]<<"     "<<Bd[1]<<"     "<<Bd[2]<<"     "<<Bd[3]<<"     "<<Bd[4]<<"     "<<Bd[5]<<"   "<<endl;
    }

void Tablica_gracza_B_start (){
    for(int i=0;i<6;i++){
        Bd[i]= Ad[i];
    }
    int TAB_N[6];
    
    for(int i=0;i<6;i++){
        TAB_N[i]=TAB_NP[i];
    }
    for (int i=0;i<12;i++){
        P[i]='1';
        Z[i]=Y;
    }
    
    for (int i=12;i<24;i++){
        P[i]=' ';
        Z[i]=V;
    }
    for (int i=24;i<36;i++){
        P[i]='1';
        Z[i]=X;
    }
    
      cout <<endl<< "      "<<Bd[5]<<"     "<<Bd[4]<<"     "<<Bd[3]<<"     "<<Bd[2]<<"     "<<Bd[1]<<"     "<<Bd[0]<<"   "<<endl;
    
    cout <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[35]<<"  |  "<<P[34]<<"  |  "<<P[33]<<"  |  "<<P[32]<<"  |  "<<P[31]<<"  |  "<<P[30]<<"  |"<<endl
    <<"  "<<" | "<<Z[35]<<" | "<<Z[34]<<" | "<<Z[33]<<" | "<<Z[32]<<" | "<<Z[31]<<" | "<<Z[30]<<" | "<<TAB_N[5]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[29]<<"  |  "<<P[28]<<"  |  "<<P[27]<<"  |  "<<P[26]<<"  |  "<<P[25]<<"  |  "<<P[24]<<"  |"<<endl
    <<"  "<<" | "<<Z[29]<<" | "<<Z[28]<<" | "<<Z[27]<<" | "<<Z[26]<<" | "<<Z[25]<<" | "<<Z[24]<<" | "<<TAB_N[4]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[23]<<"  |  "<<P[22]<<"  |  "<<P[21]<<"  |  "<<P[20]<<"  |  "<<P[19]<<"  |  "<<P[18]<<"  |"<<endl
    <<"  "<<" | "<<Z[23]<<" | "<<Z[22]<<" | "<<Z[21]<<" | "<<Z[20]<<" | "<<Z[19]<<" | "<<Z[18]<<" | "<<TAB_N[3]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[17]<<"  |  "<<P[16]<<"  |  "<<P[15]<<"  |  "<<P[14]<<"  |  "<<P[13]<<"  |  "<<P[12]<<"  |"<<endl
    <<"  "<<" | "<<Z[17]<<" | "<<Z[16]<<" | "<<Z[15]<<" | "<<Z[14]<<" | "<<Z[13]<<" | "<<Z[12]<<" | "<<TAB_N[2]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[11]<<"  |  "<<P[10]<<"  |  "<<P[9]<<"  |  "<<P[8]<<"  |  "<<P[7]<<"  |  "<<P[6]<<"  |"<<endl
    <<"  "<<" | "<<Z[11]<<" | "<<Z[10]<<" | "<<Z[9]<<" | "<<Z[8]<<" | "<<Z[7]<<" | "<<Z[6]<<" | "<<TAB_N[1]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<P[5]<<"  |  "<<P[4]<<"  |  "<<P[3]<<"  |  "<<P[2]<<"  |  "<<P[1]<<"  |  "<<P[0]<<"  |"<<endl
    <<"  "<<" | "<<Z[5]<<" | "<<Z[4]<<" | "<<Z[3]<<" | "<<Z[2]<<" | "<<Z[1]<<" | "<<Z[0]<<" | "<<TAB_N[0]<<endl;
    
    
    cout<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
     cout <<endl<< "      "<<Bd[5]<<"     "<<Bd[4]<<"     "<<Bd[3]<<"     "<<Bd[2]<<"     "<<Bd[1]<<"     "<<Bd[0]<<"   "<<endl;

    
    }

void Tablica_gracza_A(){
    for(int i=0;i<6;i++){
        Bd[i]= Ad[i];
    }
      int TAB_N[6];
    
    for(int i=0;i<6;i++){
        TAB_N[i]=TAB_NP[i];
    }
    cout <<endl<< "      "<<Bd[0]<<"     "<<Bd[1]<<"     "<<Bd[2]<<"     "<<Bd[3]<<"     "<<Bd[4]<<"     "<<Bd[5]<<"   "<<endl;
    cout <<endl<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[0]<<"  |  "<<W[1]<<"  |  "<<W[2]<<"  |  "<<W[3]<<"  |  "<<W[4]<<"  |  "<<W[5]<<"  |"<<endl
    <<" "<<TAB_N[0]<<" | "<<M[0]<<" | "<<M[1]<<" | "<<M[2]<<" | "<<M[3]<<" | "<<M[4]<<" | "<<M[5]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[6]<<"  |  "<<W[7]<<"  |  "<<W[8]<<"  |  "<<W[9]<<"  |  "<<W[10]<<"  |  "<<W[11]<<"  |"<<endl
    <<" "<<TAB_N[1]<<" | "<<M[6]<<" | "<<M[7]<<" | "<<M[8]<<" | "<<M[9]<<" | "<<M[10]<<" | "<<M[11]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[12]<<"  |  "<<W[13]<<"  |  "<<W[14]<<"  |  "<<W[15]<<"  |  "<<W[16]<<"  |  "<<W[17]<<"  |"<<endl
    <<" "<<TAB_N[2]<<" | "<<M[12]<<" | "<<M[13]<<" | "<<M[14]<<" | "<<M[15]<<" | "<<M[16]<<" | "<<M[17]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[18]<<"  |  "<<W[19]<<"  |  "<<W[20]<<"  |  "<<W[21]<<"  |  "<<W[22]<<"  |  "<<W[23]<<"  |"<<endl
    <<" "<<TAB_N[3]<<" | "<<M[18]<<" | "<<M[19]<<" | "<<M[20]<<" | "<<M[21]<<" | "<<M[22]<<" | "<<M[23]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[24]<<"  |  "<<W[25]<<"  |  "<<W[26]<<"  |  "<<W[27]<<"  |  "<<W[28]<<"  |  "<<W[29]<<"  |"<<endl
    <<" "<<TAB_N[4]<<" | "<<M[24]<<" | "<<M[25]<<" | "<<M[26]<<" | "<<M[27]<<" | "<<M[28]<<" | "<<M[29]<<" |"<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[30]<<"  |  "<<W[31]<<"  |  "<<W[32]<<"  |  "<<W[33]<<"  |  "<<W[34]<<"  |  "<<W[35]<<"  |"<<endl
    <<" "<<TAB_N[5]<<" | "<<M[30]<<" | "<<M[31]<<" | "<<M[32]<<" | "<<M[33]<<" | "<<M[34]<<" | "<<M[35]<<" |"<<endl;
    
    
    cout<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    
    
    cout << "      "<<Bd[0]<<"     "<<Bd[1]<<"     "<<Bd[2]<<"     "<<Bd[3]<<"     "<<Bd[4]<<"     "<<Bd[5]<<"   "<<endl;
}

void Tablica_gracza_B (){
    for(int i=0;i<6;i++){
        Bd[i]= Ad[i];
    }
    int TAB_N[6];
    
    for(int i=0;i<6;i++){
        TAB_N[i]=TAB_NP[i];
    }
    
   cout <<endl<< "      "<<Bd[5]<<"     "<<Bd[4]<<"     "<<Bd[3]<<"     "<<Bd[2]<<"     "<<Bd[1]<<"     "<<Bd[0]<<"   "<<endl;
    
    cout <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[35]<<"  |  "<<W[34]<<"  |  "<<W[33]<<"  |  "<<W[32]<<"  |  "<<W[31]<<"  |  "<<W[30]<<"  |"<<endl
    <<"  "<<" | "<<M[35]<<" | "<<M[34]<<" | "<<M[33]<<" | "<<M[32]<<" | "<<M[31]<<" | "<<M[30]<<" | "<<TAB_N[5]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[29]<<"  |  "<<W[28]<<"  |  "<<W[27]<<"  |  "<<W[26]<<"  |  "<<W[25]<<"  |  "<<W[24]<<"  |"<<endl
    <<"  "<<" | "<<M[29]<<" | "<<M[28]<<" | "<<M[27]<<" | "<<M[26]<<" | "<<M[25]<<" | "<<M[24]<<" | "<<TAB_N[4]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[23]<<"  |  "<<W[22]<<"  |  "<<W[21]<<"  |  "<<W[20]<<"  |  "<<W[19]<<"  |  "<<W[18]<<"  |"<<endl
    <<"  "<<" | "<<M[23]<<" | "<<M[22]<<" | "<<M[21]<<" | "<<M[20]<<" | "<<M[19]<<" | "<<M[18]<<" | "<<TAB_N[3]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[17]<<"  |  "<<W[16]<<"  |  "<<W[15]<<"  |  "<<W[14]<<"  |  "<<W[13]<<"  |  "<<W[12]<<"  |"<<endl
    <<"  "<<" | "<<M[17]<<" | "<<M[16]<<" | "<<M[15]<<" | "<<M[14]<<" | "<<M[13]<<" | "<<M[12]<<" | "<<TAB_N[2]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[11]<<"  |  "<<W[10]<<"  |  "<<W[9]<<"  |  "<<W[8]<<"  |  "<<W[7]<<"  |  "<<W[6]<<"  |"<<endl
    <<"  "<<" | "<<M[11]<<" | "<<M[10]<<" | "<<M[9]<<" | "<<M[8]<<" | "<<M[7]<<" | "<<M[6]<<" | "<<TAB_N[1]<<endl
    <<"   +-----+-----+-----+-----+-----+-----+"<<endl;
    
    cout <<"   |  "<<W[5]<<"  |  "<<W[4]<<"  |  "<<W[3]<<"  |  "<<W[2]<<"  |  "<<W[1]<<"  |  "<<W[0]<<"  |"<<endl
    <<"  "<<" | "<<M[5]<<" | "<<M[4]<<" | "<<M[3]<<" | "<<M[2]<<" | "<<M[1]<<" | "<<M[0]<<" | "<<TAB_N[0]<<endl;
    
    
    cout<<"   +-----+-----+-----+-----+-----+-----+"<<endl;
 cout <<endl<< "      "<<Bd[5]<<"     "<<Bd[4]<<"     "<<Bd[3]<<"     "<<Bd[2]<<"     "<<Bd[1]<<"     "<<Bd[0]<<"   "<<endl;
}
void menu(){
    cout <<endl<<"Co w tej turze zamierzasz ?"<<endl<<"Aby zwiekszyc wysokosc swojego dowolnie wybranego stosu wcisnij 1"<<endl<<"Aby przesunac stos na sasiednie pole wcisnij 2 "<<endl<<"Aby zbic stos przeciwnika wcisnij 3"<<endl;
    cin >>menu_P;
    
}
void wybor_do_podniesienia(){
    cout <<endl<< "Wybierz stos do podniesienia"<<endl<<" Podaj pozycje wybranego stosu" <<endl<<" w poziomie ( wielkie litery od A do F) = ";
    cin >> poziom_P;
    cout <<endl<<" oraz w pionie ( cyfry od 1 do 6) = ";
    cin >> pion_P;
    switch(poziom_P){
        case 'A':
            switch(pion_P){
                case 1:
                    pole_P = 0;
                    break;
                case 2:
                    pole_P = 6;
                    break;
                case 3:
                    pole_P = 12;
                    break;
                case 4:
                    pole_P = 18;
                    break;
                case 5:
                    pole_P = 24;
                    break;
                case 6:
                    pole_P = 30;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'B':
            switch(pion_P){
                case 1:
                    pole_P = 1;
                    break;
                case 2:
                    pole_P = 7;
                    break;
                case 3:
                    pole_P = 13;
                    break;
                case 4:
                    pole_P = 19;
                    break;
                case 5:
                    pole_P = 25;
                    break;
                case 6:
                    pole_P = 31;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'C':
            switch(pion_P){
                case 1:
                    pole_P = 2;
                    break;
                case 2:
                    pole_P =8;
                    break;
                case 3:
                    pole_P =14;
                    break;
                case 4:
                    pole_P =20;
                    break;
                case 5:
                    pole_P =26;
                    break;
                case 6:
                    pole_P =32;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'D':
            switch(pion_P){
                case 1:
                    pole_P =3;
                    break;
                case 2:
                    pole_P =9;
                    break;
                case 3:
                    pole_P =15;
                    break;
                case 4:
                    pole_P =21;
                    break;
                case 5:
                    pole_P =27;
                    break;
                case 6:
                    pole_P =33;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'E':
            switch(pion_P){
                case 1:
                    pole_P =4;
                    break;
                case 2:
                    pole_P =10;
                    break;
                case 3:
                    pole_P =16;
                    break;
                case 4:
                    pole_P =22;
                    break;
                case 5:
                    pole_P =28;
                    break;
                case 6:
                    pole_P =34;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'F':
            switch(pion_P){
                case 1:
                    pole_P =5;
                    break;
                case 2:
                    pole_P =11;
                    break;
                case 3:
                    pole_P =17;
                    break;
                case 4:
                    pole_P =23;
                    break;
                case 5:
                    pole_P =29;
                    break;
                case 6:
                    pole_P =35;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        default:
            cout <<endl<<"blad";
            break;
    }
    
}
void wybor_pola(){
    cout <<endl<< "Wykonaj ruch"<<endl<<" Podaj pozycje wybranego stosu" <<endl<<" w poziomie ( wielkie litery od A do F) = ";
    cin >> poziom_P;
    cout <<endl<<" oraz w pionie ( cyfry od 1 do 6) = ";
    cin >> pion_P;
    switch(poziom_P){
        case 'A':
            switch(pion_P){
                case 1:
                    pole_P = 0;
                    break;
                case 2:
                    pole_P = 6;
                    break;
                case 3:
                    pole_P = 12;
                    break;
                case 4:
                    pole_P = 18;
                    break;
                case 5:
                    pole_P = 24;
                    break;
                case 6:
                    pole_P = 30;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'B':
            switch(pion_P){
                case 1:
                    pole_P = 1;
                    break;
                case 2:
                    pole_P = 7;
                    break;
                case 3:
                    pole_P = 13;
                    break;
                case 4:
                    pole_P = 19;
                    break;
                case 5:
                    pole_P = 25;
                    break;
                case 6:
                    pole_P = 31;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'C':
            switch(pion_P){
                case 1:
                    pole_P = 2;
                    break;
                case 2:
                    pole_P =8;
                    break;
                case 3:
                    pole_P =14;
                    break;
                case 4:
                    pole_P =20;
                    break;
                case 5:
                    pole_P =26;
                    break;
                case 6:
                    pole_P =32;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'D':
            switch(pion_P){
                case 1:
                    pole_P =3;
                    break;
                case 2:
                    pole_P =9;
                    break;
                case 3:
                    pole_P =15;
                    break;
                case 4:
                    pole_P =21;
                    break;
                case 5:
                    pole_P =27;
                    break;
                case 6:
                    pole_P =33;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'E':
            switch(pion_P){
                case 1:
                    pole_P =4;
                    break;
                case 2:
                    pole_P =10;
                    break;
                case 3:
                    pole_P =16;
                    break;
                case 4:
                    pole_P =22;
                    break;
                case 5:
                    pole_P =28;
                    break;
                case 6:
                    pole_P =34;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'F':
            switch(pion_P){
                case 1:
                    pole_P =5;
                    break;
                case 2:
                    pole_P =11;
                    break;
                case 3:
                    pole_P =17;
                    break;
                case 4:
                    pole_P =23;
                    break;
                case 5:
                    pole_P =29;
                    break;
                case 6:
                    pole_P =35;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        default:
            cout <<endl<<"blad";
            break;
    }
    
    
    cout <<endl<<" Podaj pozycje wybranego pola " <<endl<<" w poziomie ( wielkie litery od A do F) = ";
    cin >> poziom_K;
    cout <<endl<<" oraz w pionie ( cyfry od 1 do 6) = ";
    cin >> pion_K;
    
    switch(poziom_K){
        case 'A':
            switch(pion_K){
                case 1:
                    pole_K = 0;
                    break;
                case 2:
                    pole_K = 6;
                    break;
                case 3:
                    pole_K = 12;
                    break;
                case 4:
                    pole_K = 18;
                    break;
                case 5:
                    pole_K = 24;
                    break;
                case 6:
                    pole_K = 30;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'B':
            switch(pion_K){
                case 1:
                    pole_K = 1;
                    break;
                case 2:
                    pole_K = 7;
                    break;
                case 3:
                    pole_K = 13;
                    break;
                case 4:
                    pole_K = 19;
                    break;
                case 5:
                    pole_K = 25;
                    break;
                case 6:
                    pole_K = 31;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'C':
            switch(pion_K){
                case 1:
                    pole_K = 2;
                    break;
                case 2:
                    pole_K =8;
                    break;
                case 3:
                    pole_K =14;
                    break;
                case 4:
                    pole_K =20;
                    break;
                case 5:
                    pole_K =26;
                    break;
                case 6:
                    pole_K =32;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'D':
            switch(pion_K){
                case 1:
                    pole_K =3;
                    break;
                case 2:
                    pole_K =9;
                    break;
                case 3:
                    pole_K =15;
                    break;
                case 4:
                    pole_K =21;
                    break;
                case 5:
                    pole_K =27;
                    break;
                case 6:
                    pole_K =33;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'E':
            switch(pion_K){
                case 1:
                    pole_K =4;
                    break;
                case 2:
                    pole_K =10;
                    break;
                case 3:
                    pole_K =16;
                    break;
                case 4:
                    pole_K =22;
                    break;
                case 5:
                    pole_K =28;
                    break;
                case 6:
                    pole_K =34;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'F':
            switch(pion_K){
                case 1:
                    pole_K =5;
                    break;
                case 2:
                    pole_K =11;
                    break;
                case 3:
                    pole_K =17;
                    break;
                case 4:
                    pole_K =23;
                    break;
                case 5:
                    pole_K =29;
                    break;
                case 6:
                    pole_K =35;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        default:
            cout <<endl<<"blad";
            break;
    }
    
}

void wybor_pola_bicia(){
    cout <<endl<< "Wykonaj ruch"<<endl<<" Podaj pozycje wybranego stosu bijacego" <<endl<<" w poziomie ( wielkie litery od A do F) = ";
    cin >> poziom_P;
    cout <<endl<<" oraz w pionie ( cyfry od 1 do 6) = ";
    cin >> pion_P;
    switch(poziom_P){
        case 'A':
            switch(pion_P){
                case 1:
                    pole_P = 0;
                    break;
                case 2:
                    pole_P = 6;
                    break;
                case 3:
                    pole_P = 12;
                    break;
                case 4:
                    pole_P = 18;
                    break;
                case 5:
                    pole_P = 24;
                    break;
                case 6:
                    pole_P = 30;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'B':
            switch(pion_P){
                case 1:
                    pole_P = 1;
                    break;
                case 2:
                    pole_P = 7;
                    break;
                case 3:
                    pole_P = 13;
                    break;
                case 4:
                    pole_P = 19;
                    break;
                case 5:
                    pole_P = 25;
                    break;
                case 6:
                    pole_P = 31;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'C':
            switch(pion_P){
                case 1:
                    pole_P = 2;
                    break;
                case 2:
                    pole_P =8;
                    break;
                case 3:
                    pole_P =14;
                    break;
                case 4:
                    pole_P =20;
                    break;
                case 5:
                    pole_P =26;
                    break;
                case 6:
                    pole_P =32;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'D':
            switch(pion_P){
                case 1:
                    pole_P =3;
                    break;
                case 2:
                    pole_P =9;
                    break;
                case 3:
                    pole_P =15;
                    break;
                case 4:
                    pole_P =21;
                    break;
                case 5:
                    pole_P =27;
                    break;
                case 6:
                    pole_P =33;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'E':
            switch(pion_P){
                case 1:
                    pole_P =4;
                    break;
                case 2:
                    pole_P =10;
                    break;
                case 3:
                    pole_P =16;
                    break;
                case 4:
                    pole_P =22;
                    break;
                case 5:
                    pole_P =28;
                    break;
                case 6:
                    pole_P =34;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'F':
            switch(pion_P){
                case 1:
                    pole_P =5;
                    break;
                case 2:
                    pole_P =11;
                    break;
                case 3:
                    pole_P =17;
                    break;
                case 4:
                    pole_P =23;
                    break;
                case 5:
                    pole_P =29;
                    break;
                case 6:
                    pole_P =35;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        default:
            cout <<endl<<"blad";
            break;
    }
   
    
    cout <<endl<<" Podaj pozycje wybranego stosu przeciwnika " <<endl<<" w poziomie ( wielkie litery od A do F) = ";
    cin >> poziom_K;
    cout <<endl<<" oraz w pionie ( cyfry od 1 do 6) = ";
    cin >> pion_K;
    
    switch(poziom_K){
        case 'A':
            switch(pion_K){
                case 1:
                    pole_K = 0;
                    break;
                case 2:
                    pole_K = 6;
                    break;
                case 3:
                    pole_K = 12;
                    break;
                case 4:
                    pole_K = 18;
                    break;
                case 5:
                    pole_K = 24;
                    break;
                case 6:
                    pole_K = 30;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'B':
            switch(pion_K){
                case 1:
                    pole_K = 1;
                    break;
                case 2:
                    pole_K = 7;
                    break;
                case 3:
                    pole_K = 13;
                    break;
                case 4:
                    pole_K = 19;
                    break;
                case 5:
                    pole_K = 25;
                    break;
                case 6:
                    pole_K = 31;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'C':
            switch(pion_K){
                case 1:
                    pole_K = 2;
                    break;
                case 2:
                    pole_K =8;
                    break;
                case 3:
                    pole_K =14;
                    break;
                case 4:
                    pole_K =20;
                    break;
                case 5:
                    pole_K =26;
                    break;
                case 6:
                    pole_K =32;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'D':
            switch(pion_K){
                case 1:
                    pole_K =3;
                    break;
                case 2:
                    pole_K =9;
                    break;
                case 3:
                    pole_K =15;
                    break;
                case 4:
                    pole_K =21;
                    break;
                case 5:
                    pole_K =27;
                    break;
                case 6:
                    pole_K =33;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'E':
            switch(pion_K){
                case 1:
                    pole_K =4;
                    break;
                case 2:
                    pole_K =10;
                    break;
                case 3:
                    pole_K =16;
                    break;
                case 4:
                    pole_K =22;
                    break;
                case 5:
                    pole_K =28;
                    break;
                case 6:
                    pole_K =34;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        case 'F':
            switch(pion_K){
                case 1:
                    pole_K =5;
                    break;
                case 2:
                    pole_K =11;
                    break;
                case 3:
                    pole_K =17;
                    break;
                case 4:
                    pole_K =23;
                    break;
                case 5:
                    pole_K =29;
                    break;
                case 6:
                    pole_K =35;
                    break;
                default:
                    cout <<endl<<"blad";
                    break;
            }
            break;
        default:
            cout <<endl<<"blad";
            break;
    }

}

void ruch_wykonanie_X(){
    if (M[pole_P] == X){
        if (M[pole_K] ==V){
            W[pole_K]=W[pole_P];
            M[pole_K]=M[pole_P];
            W[pole_P]=' ';
            M[pole_P]=V;
        }
        else {
            cout <<"blad"<<endl;
        }
    }
    else {
        cout <<"blad"<<endl;
    }

}

void ruch_wykonanie_Y(){
    if (M[pole_P] == Y){
        if (M[pole_K] ==V){
            W[pole_K]=W[pole_P];
            M[pole_K]=M[pole_P];
            W[pole_P]=' ';
            M[pole_P]=V;
        }
        else {
            cout <<"blad"<<endl;
        }
    }
    else {
        cout <<"blad"<<endl;
    }
    
}


void bicie_X(){
    if (M[pole_P] == X){
        if (M[pole_K] ==Y){
            if((W[pole_P]=(W[pole_K]+1))){
            W[pole_K]=W[pole_P];
            M[pole_K]=M[pole_P];
            W[pole_P]=' ';
            M[pole_P]=V;
        }
            else{
                cout <<"blad"<<endl;
                
               }
            }
        else {
            cout <<"blad"<<endl;
        }
    }
    else {
        cout <<"blad"<<endl;
    }
}

void bicie_Y(){
    if (M[pole_P] == Y){
        if (M[pole_K] ==X){
            if((W[pole_P]=(W[pole_K]+1))){
                W[pole_K]=W[pole_P];
                M[pole_K]=M[pole_P];
                W[pole_P]=' ';
                M[pole_P]=V;
            }
            else{
                cout <<"blad"<<endl;
                
            }
        }
        else {
            cout <<"blad"<<endl;
        }
    }
    else {
        cout <<"blad"<<endl;
    }
    
}

int main(){
    int n;
    for(int i=0;i<6;i++){
        TAB_NP[i]=i+1;
    }
    Ad[0]='A';
    Ad[1]='B';
    Ad[2]='C';
    Ad[3]='D';
    Ad[4]='E';
    Ad[5]='F';
    cout << "Gracz wykonujacy ruch znajduje sie na szczycie planszy"<<endl;
    cout << "Gracz 1 to figura # , gracz 2 to figura O"<<endl;
    cout << " Czy rozpoczyna gracz 1 czy 2 ?"<<endl;
    cin >>n;
    cout<<endl;
    switch (n){
        case 1:
   cout <<"Rozpoczyna gracz 1";
    Tablica_gracza_A_start();
            menu();
            switch (menu_P){
                case 1:
                    wybor_do_podniesienia();
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    
                    if (M[pole_P] == X){
                        W[pole_P]=W[pole_P]+1;
                    }
                    else {
                        cout <<"blad"<<endl;
                    }
                    Tablica_gracza_A();
                    break;
                    
                    
                case 2:
                    wybor_pola();
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    if ((abs((pole_K-pole_P)))==1){
                        ruch_wykonanie_X();
                    }
                    else if ((abs((pole_K-pole_P)))==6){
                        ruch_wykonanie_X();
                    
                    }
                    else if ((abs((pole_K-pole_P)))==7){
                        ruch_wykonanie_X();
                        
                    }
                    else{
                        cout <<"blad"<<endl;
                    }
                    Tablica_gracza_A();
                    break;
                    
                case 3:
                    
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    
                    wybor_pola_bicia();
                    
                    if ((abs((pole_K-pole_P)))==1){
                        bicie_X();
                    }
                    else if ((abs((pole_K-pole_P)))==6){
                        
                        bicie_X();
                    }
                    else if ((abs((pole_K-pole_P)))==7){
                        
                        bicie_X();
                    }
                    else{
                        cout <<"blad"<<endl;
                    }
                    
                    Tablica_gracza_A();
                    break;
                    
                    
                default:
                    cout<<"blad"<<endl;
                    break;
    
            }
            do
            {
                
                cout <<" gracz 2 "<<endl;
                Tablica_gracza_B();
                menu();
                switch (menu_P){
                    case 1:
                        wybor_do_podniesienia();
                   
                        if (M[pole_P] == Y){
                            W[pole_P]=W[pole_P]+1;
                        }
                        else {
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_B();
                        break;
                        
                        
                    case 2:
                        wybor_pola();
                    
                        if ((abs((pole_K-pole_P)))==1){
                            ruch_wykonanie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            ruch_wykonanie_Y();
                            
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            ruch_wykonanie_Y();
                            
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_B();
                        break;
                        
                    case 3:
                        
                        
                        wybor_pola_bicia();
                        if ((abs((pole_K-pole_P)))==1){
                            bicie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            
                            bicie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            
                            bicie_Y();
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        
                        Tablica_gracza_B();
                        break;
                        
                        
                    default:
                        cout<<"blad"<<endl;
                        break;
                        
                }
                
                
                cout<<"gracz 1"<<endl;
                Tablica_gracza_A();
                menu();
                switch (menu_P){
                    case 1:
                        wybor_do_podniesienia();
                       
                        if (M[pole_P] == X){
                            W[pole_P]=W[pole_P]+1;
                        }
                        else {
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_A();
                        break;
                        
                        
                    case 2:
                        wybor_pola();

                        if ((abs((pole_K-pole_P)))==1){
                            ruch_wykonanie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            ruch_wykonanie_X();
                            
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            ruch_wykonanie_X();
                            
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_A();
                        break;
                        
                    case 3:
                        
                        wybor_pola_bicia();
                        
                        if ((abs((pole_K-pole_P)))==1){
                            bicie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            
                            bicie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            
                            bicie_X();
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        
                        Tablica_gracza_A();
                        break;
                        
                        
                        
                    default:
                        cout<<"blad"<<endl;
                        break;
                        
                }
                
                
                
            } while( (M[30]!=X && W[30]!=1) || (M[31]!=X && W[31]!=1) || (M[32]!=X && W[32]!=1) || (M[33]!=X && W[33]!=1) || (M[34]!=X && W[34]!=1) || (M[35]!=X && W[35]!=1) || (M[0]!=Y && W[0]!=1) || (M[1]!=Y && W[1]!=1) || (M[2]!=Y && W[2]!=1) || (M[3]!=Y && W[3]!=1) || (M[4]!=Y && W[4]!=1) || (M[5]!=Y && W[5]!=1)  );
            cout <<"Wygrana"<<endl;
            break;
            
        
        

        case 2:
            cout <<"Rozpoczyna gracz 2";
            Tablica_gracza_B_start();
            menu();
            switch (menu_P){
                case 1:
                    wybor_do_podniesienia();
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    cout <<W[pole_P]<<endl;
                    if (M[pole_P] == Y){
                        W[pole_P]=W[pole_P]+1;
                    }
                    else {
                        cout <<"blad"<<endl;
                    }
                    Tablica_gracza_B();
                    break;
                    
                    
                case 2:
                    wybor_pola();
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    if ((abs((pole_K-pole_P)))==1){
                        ruch_wykonanie_Y();
                    }
                    else if ((abs((pole_K-pole_P)))==6){
                        ruch_wykonanie_Y();
                        
                    }
                    else if ((abs((pole_K-pole_P)))==7){
                        ruch_wykonanie_Y();
                        
                    }
                    else{
                        cout <<"blad"<<endl;
                    }
                    Tablica_gracza_B();
                    break;
                    
                case 3:
                    
                    for (int i=0;i<36;i++){
                        W[i]=P[i];
                        M[i]=Z[i];
                    }
                    
                    wybor_pola_bicia();
                    if ((abs((pole_K-pole_P)))==1){
                        bicie_Y();
                    }
                    else if ((abs((pole_K-pole_P)))==6){
                        
                        bicie_Y();
                    }
                    else if ((abs((pole_K-pole_P)))==7){
                        
                        bicie_Y();
                    }
                    else{
                        cout <<"blad"<<endl;
                    }
                    
                    Tablica_gracza_B();
                    break;
                    
                    
                default:
                    cout<<"blad"<<endl;
                    break;
                    
            }
            do
            {
                cout<<"gracz 1"<<endl;
                Tablica_gracza_A();
                menu();
                switch (menu_P){
                    case 1:
                        wybor_do_podniesienia();
                       
                        if (M[pole_P] == X){
                            W[pole_P]=W[pole_P]+1;
                        }
                        else {
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_A();
                        break;
                        
                        
                    case 2:
                        wybor_pola();
                        
                        if ((abs((pole_K-pole_P)))==1){
                            ruch_wykonanie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            ruch_wykonanie_X();
                            
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            ruch_wykonanie_X();
                            
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_A();
                        break;
                        
                    case 3:
                        
                        wybor_pola_bicia();
                        
                        if ((abs((pole_K-pole_P)))==1){
                            bicie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            
                            bicie_X();
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            
                            bicie_X();
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        
                        Tablica_gracza_A();
                        break;
                        
                        
                        
                    default:
                        cout<<"blad"<<endl;
                        break;
                        
                }
                

                cout <<" gracz 2"<<endl;
                Tablica_gracza_B();
                menu();
                switch (menu_P){
                    case 1:
                        wybor_do_podniesienia();
                        
                        if (M[pole_P] == Y){
                            W[pole_P]=W[pole_P]+1;
                        }
                        else {
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_B();
                        break;
                        
                        
                    case 2:
                        wybor_pola();
                    
                        if ((abs((pole_K-pole_P)))==1){
                            ruch_wykonanie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            ruch_wykonanie_Y();
                            
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            ruch_wykonanie_Y();
                            
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        Tablica_gracza_B();
                        break;
                        
                    case 3:
                        
                    
                        
                        wybor_pola_bicia();
                        if ((abs((pole_K-pole_P)))==1){
                            bicie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==6){
                            
                            bicie_Y();
                        }
                        else if ((abs((pole_K-pole_P)))==7){
                            
                            bicie_Y();
                        }
                        else{
                            cout <<"blad"<<endl;
                        }
                        
                        Tablica_gracza_B();
                        break;
                        
                        
                    default:
                        cout<<"blad"<<endl;
                        break;
                        
                }
                
                
                
                
            } while( (M[30]!=X && W[30]!=1) || (M[31]!=X && W[31]!=1) || (M[32]!=X && W[32]!=1) || (M[33]!=X && W[33]!=1) || (M[34]!=X && W[34]!=1) || (M[35]!=X && W[35]!=1) || (M[0]!=Y && W[0]!=1) || (M[1]!=Y && W[1]!=1) || (M[2]!=Y && W[2]!=1) || (M[3]!=Y && W[3]!=1) || (M[4]!=Y && W[4]!=1) || (M[5]!=Y && W[5]!=1)  );
            cout <<"Wygrana"<<endl;
            break;
    
        default:
        cout << "blad";
            break;
    }
    
    
    return 0;
}