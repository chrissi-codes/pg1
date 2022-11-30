#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool standartWerte(){
    char eingabe = '0';
    cout << endl << "Sollen die Standartwerte verwendet werden? (y/n) ";
    cin >> eingabe;

    if(eingabe=='n'){
        return 0;
    }else{
        return 1;
    }
}

int getEnde(){
    int eingabe = '0';
    cout << "Bis zu welchem Wert wollen Sie gehen? ";
    cin >> eingabe;
    return eingabe;
}


bool schnappszahl(int test){
    int temp=test%10, end=0;
    if(test<11){
        return 0;
    }
    while(test!=0){
        if(test%10==temp){
            end=test%10;
        }
        else{
            return 0;
        }
        test/=10;
    }
    if(temp==end){
        return 1;
    }
    return 0;
}


bool gerade(int test){
    if(test%2){
        return 0;
    }
    return 1;
}

bool primzahl(int test){
    int i;
    if(test < 2){
        return 0;
    }
    for(i = 2; i <= test/i; i++){
        if(test%i == 0){
            return 0;
        }
    }
    return 1;
}

bool palindrom(int test){
    string zahl, rev;
    zahl = to_string(test);
    rev = zahl;
    reverse(rev.begin(), rev.end());
    if(zahl==rev){
        return 1;
    }
    return 0;
}


void a(){
    int start = 0, ende;
    if(standartWerte()){
        ende = 100;
    }else{
        ende = getEnde();
    }

    while(start<ende){
        if(schnappszahl(start)&&!gerade(start)){
            if(start > 11){
                cout << ", ";
            }
            cout << start;
        }
        start++;
    }
    cout << endl << endl;
}

void b(){
    int start, ende, ref;
    if(standartWerte()){
        start = 27;
        ende = 61;
    }else{
        start = 0;
        ende = getEnde();
    }
    ref = start;

    while(start<ende){
        if(gerade(start)){
            if(start > ref+1){
                cout << ", ";
            }
            cout << start;
        }
        start++;
    }
    cout << endl << endl;
}

void c(){
    int start = 0, ende;
    if(standartWerte()){
        ende = 100;
    }else{
        ende = getEnde();
    }

    while(start<ende){
        if(palindrom(start)){
            if(start > 0){
                cout << ", ";
            }
            cout << start;
        }
        start++;
    }
    cout << endl << endl;
}

void d(){
    int start = 0, ende;
    if(standartWerte()){
        ende = 100;
    }else{
        ende = getEnde();
    }

    while(start<ende){
        if(primzahl(start)){
            if(start > 2){
                cout << ", ";
            }
            cout << start;
        }
        start++;
    }
    cout << endl << endl;
}


int main()
{
    string reply = "Mochten Sie noch eine weitere Aufgabe sehen? (y/n)";
    char eingabe = '0';
    bool repeat = 1;

    while(repeat){
        cout << "Welche Aufgabe mochten sie sehen? (a/b/c/d)" << endl << endl << "a) Ungerade Schnappszahlen" << endl << "b) Gerade Zahlen" << endl << "c) Palindrome" << endl << "d) Primzahlen" << endl << endl;
        cin >> eingabe;

        switch(eingabe){
        case 'a':
            a();

            cout << reply << endl;
            cin >> eingabe;
            if(eingabe!='y'){
                repeat = 0;
            }
            break;
        case 'b':
            b();

            cout << reply << endl;
            cin >> eingabe;
            if(eingabe!='y'){
                repeat = 0;
            }
            break;
        case 'c':
            c();

            cout << reply << endl;
            cin >> eingabe;
            if(eingabe!='y'){
                repeat = 0;
            }
            break;
        case 'd':
            d();

            cout << reply << endl;
            cin >> eingabe;
            if(eingabe!='y'){
                repeat = 0;
            }
            break;

        default:
            cout << "Ihre Eingabe war leider nicht korrekt, versuchen sie es erneut!" << endl << endl;
            break;
        }
    }
    return 0;
}
