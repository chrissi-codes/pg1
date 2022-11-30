#include <iostream>
#include <regex>
#include <algorithm>
#include <string>

using namespace std;

string Dec_To_Bin(int decZahl){ //wandelt die Zahl von der Dezimalschreibweise zu der Binärschreibweise um
    string binZahl, tempStr;
    bool temp;
    int i;
    while(decZahl != 0){
        temp = decZahl % 2;
        if(temp){
            binZahl += '1';
        }else{
            binZahl += '0';
        }
        decZahl /= 2;
    }
    tempStr = binZahl;
    for(i=0; i<=binZahl.length();i++){ //spiegelt die Zahl
        binZahl[i] = tempStr[binZahl.length()-i];
    }
    return binZahl;
}


int MakeZahl(int t, int fh, int h, int fz, int z, int fe, int e){ //berechnet die zahl
    return (1000*t)+(500*fh)+(100*h)+(50*fz)+(10*z)+(5*fe)+(1*e);
}

int main()
{
    string eingabe = "0";
    string bzahl="0";
    int tau=0, funfhun=0, hun=0, funfzeh=0, zeh=0, funfein=0, ein = 0;
    int dzahl=0, anzahlZiffern=0;
    int i=0;
    bool check = 0;

    while(!check){
        cout << "Geben sie eine Romische Zahl an: ";
        cin >> eingabe;
        transform(eingabe.begin(), eingabe.end(), eingabe.begin(), ::toupper); //ermöglicht auch kleine Buchstaben

        if(regex_match (eingabe, regex("^M{0,9}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$"))){ //überprüft, ob Zahl legitim ist
            check=1;
        }else{
            check=0;
            cout << "Ihre Zahl ist leider keine korrekte romische Zahl." << endl;
        }
    }

    anzahlZiffern = eingabe.length();
    char eingabeArr[anzahlZiffern];

    for(i=0; i<=anzahlZiffern; i++){ //Umwandlung String -> Array
        eingabeArr[i] = eingabe[i];
        eingabeArr[i+1] = '\0';
    }
    i=0;

    while(eingabeArr[i]!='\0'){ //Auswertung der Buchstaben
        while(eingabeArr[i]=='M'){ //1000er
            tau++, i++;
        }
        if(eingabeArr[i]=='D'){ //500er
            funfhun++, i++;
        }
        if(eingabeArr[i]=='C'){ //400er, 900er, 100er
            switch(eingabeArr[i+1]){
            case 'D': //400er
                funfhun++, hun--, i+=2;
                break;
            case 'M': //900er
                tau++, hun--, i+=2;
                break;
            default: //100er
                hun++, i++;
                break;
            }
        }
        if(eingabeArr[i]=='L'){ //50er
            funfzeh++, i++;
        }
        if(eingabeArr[i]=='X'){ //10er
            switch(eingabeArr[i+1]){
            case 'L': //40er
                funfzeh++, zeh--, i+=2;
                break;
            case 'C': //90er
                hun++, zeh--, i+=2;
                break;
            default: //10er
                zeh++, i++;
                break;
            }
        }
        if(eingabeArr[i]=='V'){ //5er
            funfein++, i++;
        }
        if(eingabeArr[i]=='I'){ //4er, 9er, 1er
            switch(eingabeArr[i+1]){
            case 'V': //4er
                funfein++, ein--, i+=2;
                break;
            case 'X': //9er
                zeh++, ein--, i+=2;
                break;
            default: //1er
                ein++, i++;
                break;
            }
        }
    }

    cout << "Ihre Zahl besteht aus: " << endl; //Ausgabe Bestandteile
    if(tau){
        cout << "Tausendern: " << tau << endl;
    }
    if(funfhun){
        cout << "Funfhundertern: " << funfhun << endl;
    }
    if(hun){
        cout << "Hundertern: " << hun << endl;
    }
    if(funfzeh){
        cout << "Funfziger: " << funfzeh << endl;
    }
    if(zeh){
        cout << "Zehner: " << zeh << endl;
    }
    if(funfein){
        cout << "Funfern: " << funfein << endl;
    }
    if(ein){
        cout << "Einer: " << ein << endl;
    }

    dzahl = MakeZahl(tau, funfhun, hun, funfzeh, zeh, funfein, ein);
    bzahl = Dec_To_Bin(dzahl);

    cout << "Die Zahl " << eingabe; //Ausgabe Zahl
    cout << " wird in der Dezimaldarstellung als " << dzahl;
    cout << " und in der Binardarstellung als " << bzahl;
    cout << " dargestellt." << endl;
}
