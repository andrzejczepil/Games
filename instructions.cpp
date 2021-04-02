
#include <iostream> //załączenie biblioteki odpowiadającej za komendy "cout", "cin" ect.
#include <cstdio> //biblioteka odpowiedzialna za komendy takie jak "printf"
#include <string>

using namespace std;  //to odpowiada za nie uzywanie "std::"  na poczatku komendy

int main () { //rozpoczęcie argumentu
    
    printf( "Czy %d jest wieksze od %s", 3 + 4, "siedem" "?" "\n" ); //zapis dla cstdio ; % to znak specjalny ;(d) informuje o wystapieniu liczby całkowitej ; (s) informuje o wystąpieniu łańcucha znaków "\n" odpowiada za nową linię
    
    cout << "Czy " << 3 + 4 << " jest wieksze od " << "siedem" << "?" << endl; // zapis dla iostream
    
    cout << endl;
    cout << endl;
    
    //////////////////////////////////////////////////////////////////////////////////////////////////
    
    //badanie ile w rzeczywistości zajmuje dany typ danych
    
     cout << "sizeof(bool) = " << sizeof( bool ) <<  endl;
     cout << "sizeof(char) = " << sizeof( char ) <<  endl;
     cout << "sizeof(unsigned char) = " << sizeof( unsigned char ) <<  endl;
     cout << "sizeof(wchar_t) = " << sizeof( wchar_t ) <<  endl;
     cout << "sizeof(short) = " << sizeof( short ) <<  endl;
     cout << "sizeof(unsigned short) = " << sizeof( unsigned short ) << endl;
     cout << "sizeof(int) = " << sizeof( int ) <<  endl;
     cout << "sizeof(unsigned int) = " << sizeof( unsigned int ) <<  endl;
     cout << "sizeof(long) = " << sizeof( long ) <<  endl;
     cout << "sizeof(unsigned long) = " << sizeof( unsigned long ) <<  endl;
     cout << "sizeof(long long) = " << sizeof( long long ) <<  endl;
     cout << "sizeof(float) = " << sizeof( float ) <<  endl;
     cout << "sizeof(double) = " << sizeof( double ) <<  endl;
     cout << "sizeof(long double) = " << sizeof( long double ) <<  endl;
    
    cout << endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////
    
    //typy zmiennych
    
    //  nazwa           wielkość        zakres
    
    //             ( liczby całkowite )
    
    // short                2       przedział [-32768, 32767]
   
    // int                  4       przedział [-2147483648, 2147483647]
    
    // long                 4       przedział [-2147483648, 2147483647]
    
    // long long            8       przedział [-9223372036854775808, 9223372036854775807]
    
    // unsigned short       2       przedział [0, 65535]
    
    // unsigned int         4       przedział [0, 4294967295]
    
    // unsigned long        4       przedział [0, 4294967295]
    
    // unsigned long long	8       przedział [0, 18446744073709551615]
    
    //             ( liczby z przecinkiem )

    // float                4       pojedyncza precyzja - dokładność 6 - 7 cyfr po przecinku
    
    // double               8       podwójna precyzja - dokładność 15 - 16 cyfr po przecinku
    
    // long double          12      liczby z ogromną dokładnością - 19 - 20 cyfr po przecinku
    
    //                  ( znaki )
    
    // char                 1       -128 ÷ 127 ( każdy znak ma odpowiadającą mu wielkość liczbową )
    
    // unsigned char        1       0 ÷ 255    ( na przykład litera "d" ma wartość 100, "!" = 33 )
    
    //                ( tak / nie )
    
    // bool                 1       true (1)  /  false (0)
    
    //////////////////////////////////////////////////////////////////////////////////////////////////

    //                  ( metody String'ów )
    
    // empty()	Zwraca wartość true jeżeli napis jest pusty.
    
    // size(),length()	Zwraca ilość znaków w napisie.
    
    // at()	Zwraca znak o podanym położeniu, tak jak operator [],
    
    // clear()	Usuwa wszystkie znaki z napisu.
    
    // erase(...)	Usuwa wybrane znaki.
    
    // find(...)	Znajduje podciąg w ciągu, są też bardziej rozbudowane funkcje tego typu.
    
    // swap(...)	Zamienia miejscami dwa stringi, a staje się b, a b staje się a.
    
    // substr(...)	Zwraca podciąg na podstawie indeksu początkowego i długości podciągu.
    
    // append(...)	Dodaje zadany napis na końcu istniejącego ciągu.
    
    // c_str()	Zwraca napis w stylu języka C (stały wskaźnik typu const char*).
    
        string str = "jakiekolwiek badziewie"; // tworzenie stringu
    
            cout << str; // wyświetlanie go
    
                str.clear(); // czyszczenie go
    
    cout << endl;
    cout << endl;
    

    //////////////////////////////////////////////////////////////////////////////////////////////////
    
    //tworzenie zmiennej
    
    int to_jest_zmienna = 1;
    
    unsigned int tylkoDodatnie = 4;
    
    float zmiennoprzecinkowa = 0.5; //kropka zamiast przecinka
    
    char jeden_znak = '?'; //nie cudzysłów
    
    unsigned char rowniez_znak = 'c';
    
    //wyświetlanie
    
    cout << "  to_jest_zmienna = " << to_jest_zmienna << endl;
    cout << "  tylkoDodatnie = " << tylkoDodatnie << endl;
    cout << "  zmiennoprzecinkowa = " << zmiennoprzecinkowa << endl;
    cout << "  jeden_znak = " << jeden_znak << endl;
    cout << "  rowniez_znak = " << rowniez_znak << endl;
    
    cout << endl;
    cout << endl;
    

    //////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    return 0;
}
