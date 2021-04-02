#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
using namespace std;
void sprawdzanie_ilosci_lini(int* ilosc_lini,char (*instrukcje_plotera_surowe_linie)[20]){
    
    ifstream plik("pliczek.txt");
    
    while (plik.getline( (*instrukcje_plotera_surowe_linie), 20 ))
        ++*ilosc_lini;
    }


void wczytywanie_pliku (char (*instrukcje_plotera_surowe)[30][20],int* ilosc_lini)
{
    fstream plik("pliczek.txt");
       if(!plik) {
        cout << "Plik nie zostal otwarty";
    }
    
    for(int i=0;i<(*ilosc_lini);i++){
        plik.getline( (*instrukcje_plotera_surowe)[i], 20 );
        
    }
}

void sprawdzanie_czy_dane_dobre(int*ilosc_lini,char (*instrukcje_plotera_surowe)[30][20],char (*instrukcje_plotera_dobre)[30][20],int*blad,int (*znak_kierunku)[20],int (*stan_plotera)[20]){
    for(int i=0;i<*ilosc_lini;i++)
    {
        if (
            (
             ((*instrukcje_plotera_surowe)[i][0]=='Y')||((*instrukcje_plotera_surowe)[i][0]=='X')
             )
            &&
            ((*instrukcje_plotera_surowe)[i][1]==' ')
            &&
            (
             ((*instrukcje_plotera_surowe)[i][2]>47) && ((*instrukcje_plotera_surowe)[i][2]<58)
             )
            
            )
        {
            if(
                (
                ((*instrukcje_plotera_surowe)[i][3]>47) && ((*instrukcje_plotera_surowe)[i][3]<58)
                 && ((*instrukcje_plotera_surowe)[i][2]<'3')
                )
            )
            {
                if ((*instrukcje_plotera_surowe)[i][4]){
                    *blad=1;
                    cout<<"blad w lini : "<<i+1<<" ,poza zakresem"<<endl;
                    break;
                }
                else {
                    if((*instrukcje_plotera_surowe)[i][0]=='Y'){
                    (*stan_plotera)[i]=0;
                     (*znak_kierunku)[i]=7;
                    for(int j=0;j<4;j++){
                        (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else if ((*instrukcje_plotera_surowe)[i][0]=='X'){
                        (*stan_plotera)[i]=0;
                        (*znak_kierunku)[i]=3;
                        for(int j=0;j<4;j++){
                        (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else {
                        *blad=1;
                        cout<<"blad w lini : "<<i+1<<endl;
                        break;
                    }
                }
            }
            else if(
                    (*instrukcje_plotera_surowe)[i][3]=='\0'
                    )
            {
                if((*instrukcje_plotera_surowe)[i][0]=='Y'){
                (*stan_plotera)[i]=0;
                (*znak_kierunku)[i]=5;
                for(int j=0;j<5;j++){
                    (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                }
                else if ((*instrukcje_plotera_surowe)[i][0]=='X'){
                    (*stan_plotera)[i]=0;
                    (*znak_kierunku)[i]=1;
                    for(int j=0;j<5;j++){
                    (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                }
                else {
                    *blad=1;
                    cout<<"blad w lini : "<<i+1<<endl;
                    break;
                }
            }
            else {
                *blad=1;
                cout<<"blad w lini : "<<i+1<<endl;
                break;}
        }
        else if (
                  (
                   ((*instrukcje_plotera_surowe)[i][0]=='Y')||((*instrukcje_plotera_surowe)[i][0]=='X')
                  )
                 &&
                    ((*instrukcje_plotera_surowe)[i][1]==' ')
                 &&
                    ((*instrukcje_plotera_surowe)[i][2]=='-')
                 &&
                  (
                    ((*instrukcje_plotera_surowe)[i][3]>47) &&((*instrukcje_plotera_surowe)[i][3]<58)
                  )
                )
        {
            if(
               ((*instrukcje_plotera_surowe)[i][4]>47) && ((*instrukcje_plotera_surowe)[i][4]<58)
               && ((*instrukcje_plotera_surowe)[i][3]<'3')
               )
            {
                if ((*instrukcje_plotera_surowe)[i][5]){
                    *blad=1;
                    cout<<"blad w lini : "<<i+1<<" ,poza zakresem"<<endl;
                    break;}
                else{
                    if((*instrukcje_plotera_surowe)[i][0]=='Y'){
                    (*stan_plotera)[i]=0;
                    (*znak_kierunku)[i]=8;
                    for(int j=0;j<5;j++){
                        (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else if ((*instrukcje_plotera_surowe)[i][0]=='X'){
                        (*stan_plotera)[i]=0;
                        (*znak_kierunku)[i]=4;
                        for(int j=0;j<5;j++){
                            (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else{
                        *blad=1;
                        cout<<"blad w lini : "<<i+1<<endl;
                        break;
                    }
                }
            }
                else if(
                        (*instrukcje_plotera_surowe)[i][4]=='\0'
                        )
                {
                    if((*instrukcje_plotera_surowe)[i][0]=='Y'){
                    (*znak_kierunku)[i]=6;
                    (*stan_plotera)[i]=0;
                    for(int j=0;j<5;j++){
                        (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else if ((*instrukcje_plotera_surowe)[i][0]=='X'){
                        (*znak_kierunku)[i]=2;
                        (*stan_plotera)[i]=0;
                        for(int j=0;j<5;j++){
                            (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
                    }
                    else {
                        *blad=1;
                        cout<<"blad w lini : "<<i+1<<endl;
                        break;
                    }
                }
            
            else {
                *blad=1;
                cout<<"blad w lini : "<<i+1<<endl;
                break;}
        }
        else if(
           ( (*instrukcje_plotera_surowe)[i][0] == 'U') && ( (*instrukcje_plotera_surowe)[i][1] == 'P')&& ( (*instrukcje_plotera_surowe)[i][2] == '\0')
            )
        {
            if ((*instrukcje_plotera_surowe)[i][3]){
                *blad=1;
                cout<<"blad w lini : "<<i+1<<" ,poza zakresem"<<endl;
                break;}
            else{
                (*znak_kierunku)[i]=0;
                (*stan_plotera)[i]=1;
            for(int j=0;j<4;j++){
                (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
            }
        }
        else if(
                ( (*instrukcje_plotera_surowe)[i][0] == 'D') && ( (*instrukcje_plotera_surowe)[i][1] == 'O') && ( (*instrukcje_plotera_surowe)[i][2] == 'W') && ( (*instrukcje_plotera_surowe)[i][3] == 'N') && ( (*instrukcje_plotera_surowe)[i][4] == '\0')
                )
        {
            if ((*instrukcje_plotera_surowe)[i][5]){
                *blad=1;
                cout<<"blad w lini : "<<i+1<<" ,poza zakresem"<<endl;
                break;}
            else{
                (*znak_kierunku)[i]=0;
                (*stan_plotera)[i]=2;
                for(int j=0;j<4;j++){
                    (*instrukcje_plotera_dobre)[i][j]=(*instrukcje_plotera_surowe)[i][j];}
            }
        }
        else{
            *blad=1;
            cout<<"blad w lini : "<<i+1<<endl;
            break;}
    }

}
void wyswietlanie_sciezki(char (*instrukcje_plotera_dobre)[30][20],int* ilosc_lini,int (*znak_kierunku)[20],int (*stan_plotera)[20],char (*sciezka)[70][70],int*blad,int* pamiec_X,int* pamiec_Y){
    if (((*stan_plotera)[0]= 2)){
        for(int i=1;i<(*ilosc_lini);i++){
            do {
                if(((*znak_kierunku)[i])==1){
                    if ((*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z<(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));z++){
                        (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));
                        }
                  break;
                }
                else if(((*znak_kierunku)[i])==2){
                    if ((*pamiec_X-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z>((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));z--){
                        (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));
                        ;
                    }
                    break;

                }
                else if(((*znak_kierunku)[i])==3){
                    if ((*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);(*pamiec_X+(((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48)))>z;z++){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==4){
                    if ((*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z>(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));z--){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==5){
                    if ((*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z<(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));z++){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==6){
                    if ((*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z>(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));z--){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==7){
                    if ((*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);(*pamiec_Y+(((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48)))>z;z++){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;

                }
                else if(((*znak_kierunku)[i])==8){
                    if ((*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z>(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));z--){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                }
                else {
                    cout <<" blad inny w lini : "<<i+1<<endl;
                }
                
            }
            while (((*stan_plotera)[i]!= 1)&&(i<(*ilosc_lini)));
            do {
                if(((*znak_kierunku)[i])==1){
                    if ((*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_X=(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==2){
                    if ((*pamiec_X-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        
                        *pamiec_X=((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==3){
                    if ((*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        
                        *pamiec_X=(*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==4){
                    if ((*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        
                        *pamiec_X=(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==5){
                    if ((*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==6){
                    if ((*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==7){
                    if ((*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==8){
                    if ((*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                }
                else {
                    cout <<" blad inny w lini : "<<i+1<<endl;
                }
                
            }
            while (((*stan_plotera)[i]!= 2)&&(i<(*ilosc_lini)));

        }
    }
    else if(((*stan_plotera)[0]= 1)){
        cout <<"gora"<<endl;
        for(int i=1;i<(*ilosc_lini);i++){
            do {
                if(((*znak_kierunku)[i])==1){
                    if ((*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_X=(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==2){
                    if ((*pamiec_X-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                      
                        *pamiec_X=((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==3){
                    if ((*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        
                        *pamiec_X=(*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==4){
                    if ((*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        
                        *pamiec_X=(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==5){
                    if ((*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                    *pamiec_Y=(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==6){
                    if ((*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==7){
                    if ((*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==8){
                    if ((*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        *pamiec_Y=(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                }
                else {
                    cout <<" blad inny w lini : "<<i+1<<endl;
                }
 
            }
            while (((*stan_plotera)[i]!= 2)&&(i<(*ilosc_lini)));
            do {
                if(((*znak_kierunku)[i])==1){
                    if ((*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z<(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));z++){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==2){
                    if ((*pamiec_X-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z>((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));z--){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=((*pamiec_X)-(((*instrukcje_plotera_dobre)[i][3])-48));
                        ;
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==3){
                    if ((*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);(*pamiec_X+(((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48)))>z;z++){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==4){
                    if ((*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_X);z>(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));z--){
                            (*sciezka)[*pamiec_Y][z]='*';
                        }
                        *pamiec_X=(*pamiec_X-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==5){
                    if ((*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z<(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));z++){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y+(((*instrukcje_plotera_dobre)[i][2])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==6){
                    if ((*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z>(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));z--){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y-(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                }
                else if(((*znak_kierunku)[i])==7){
                    if ((*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48))>70){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);(*pamiec_Y+(((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48)))>z;z++){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y+((((*instrukcje_plotera_dobre)[i][2])-48)*10)+(((*instrukcje_plotera_dobre)[i][3])-48));
                    }
                    break;
                    
                }
                else if(((*znak_kierunku)[i])==8){
                    if ((*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)))<0){
                        cout <<"poza zakresem"<<endl;
                    }
                    else{
                        for(int z=(*pamiec_Y);z>(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));z--){
                            (*sciezka)[z][*pamiec_X]='*';
                        }
                        *pamiec_Y=(*pamiec_Y-(((((*instrukcje_plotera_dobre)[i][3])-48)*10)+(((*instrukcje_plotera_dobre)[i][4])-48)));
                    }
                    break;
                }
                else {
                    cout <<" blad inny w lini : "<<i+1<<endl;
                }

            }
            while (((*stan_plotera)[i]!= 1)&&(i<(*ilosc_lini)));
        }

        
    }
    else if (((*stan_plotera)[0]= 0)){
        *blad=1;
        cout <<" blad. Plik tekstowy nie zawiera instrukcji poczatkowej plotera "<<endl;
    }
    else {
        *blad=1;
        cout<<"blad w lini : 1"<<endl;
    }

        
}
void rysowanie_sciezki(){
    
}

int main(){
    int ilosc_lini = 0;
    int blad = 0;
    int znak_kierunku[20]; //1 dodatnie w poziomie, 5 dodatnie w pionie  , 2 ujemne w poziomie , 6 ujemne w pionie, 3 dodatnie wieksze niz 9 w poziomie, 7 dodatnie wieksze niz 9 w pionie,4 ujemne wieksze niz 9 w poziomie, 8 dodatnie wieksze niz 9 w pionie
    int stan_plotera[20]; //0 nic, 1 up , 2 down
    char instrukcje_plotera_surowe_linie [20];
    char instrukcje_plotera_surowe[30][20];
    char instrukcje_plotera_dobre[30][20];
    char sciezka[70][70];
    
    for(int i=0;i<ilosc_lini;i++)
    {
        znak_kierunku[i]=0;
        stan_plotera[i]=0;
        
    }
    int pamiec_X=0;
    int pamiec_Y=0;
    for(int y=0;y<70;y++)
    {
        for(int x=0;x<70;x++)
        {
            sciezka[y][x]=' ';
        }
    }
    sprawdzanie_ilosci_lini(&ilosc_lini,&instrukcje_plotera_surowe_linie);
    wczytywanie_pliku(&instrukcje_plotera_surowe,&ilosc_lini);
    sprawdzanie_czy_dane_dobre(&ilosc_lini,&instrukcje_plotera_surowe,&instrukcje_plotera_dobre,&blad,&znak_kierunku,&stan_plotera);
    wyswietlanie_sciezki(&instrukcje_plotera_dobre,&ilosc_lini,&znak_kierunku,&stan_plotera,&sciezka,&blad,&pamiec_X,&pamiec_Y);
    if((blad!=1)){
    for(int i=0;i<ilosc_lini;i++)
        {
            cout<<instrukcje_plotera_dobre[i]<<" | "<<znak_kierunku[i]<<" | "<<stan_plotera[i]<<endl;
        }
        
        for(int y=0;y<70;y++)
        {
            for(int x=0;x<70;x++)
            {
                cout<<sciezka[y][x];
            }
            cout<<endl;
            }
        }
    return 0;
    }
