#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <stdlib.h>

using namespace std;

//TODO Struktur

void printFeld(){

}

int main()
{
    int size, anzahlMinen;
    bool suitable = 0;


    //durchlaufen lassen??
    cout << R"(

                            :::   :::   ::::::::::: ::::    ::: :::::::::: ::::::::  :::       ::: :::::::::: :::::::::: :::::::::  :::::::::: :::::::::
     :+:     :+:          :+:+: :+:+:      :+:     :+:+:   :+: :+:       :+:    :+: :+:       :+: :+:        :+:        :+:    :+: :+:        :+:    :+:        :+:     :+:
      +:+ +:+           +:+ +:+:+ +:+     +:+     :+:+:+  +:+ +:+       +:+        +:+       +:+ +:+        +:+        +:+    +:+ +:+        +:+    +:+          +:+ +:+
  +#++:++#++:++        +#+  +:+  +#+     +#+     +#+ +:+ +#+ +#++:++#  +#++:++#++ +#+  +:+  +#+ +#++:++#   +#++:++#   +#++:++#+  +#++:++#   +#++:++#:        +#++:++#++:++
    +#+ +#+           +#+       +#+     +#+     +#+  +#+#+# +#+              +#+ +#+ +#+#+ +#+ +#+        +#+        +#+        +#+        +#+    +#+          +#+ +#+
 #+#     #+#         #+#       #+#     #+#     #+#   #+#+# #+#       #+#    #+#  #+#+# #+#+#  #+#        #+#        #+#        #+#        #+#    #+#        #+#     #+#
                    ###       ### ########### ###    #### ########## ########    ###   ###   ########## ########## ###        ########## ###    ###

    )";



    while(!suitable){
        cout << "Wie lang soll ihr Spielfeld sein? ";
        cin >> size;
        if(size<2||size>99){
            cout << "Ihr Spielfeld sollte eine grosse zwischen 2 und 26 haben. \n";
        }else{
            suitable=1;
            system("cls");
        }
    }
    suitable=0;
    int len=size*size;

    while(!suitable){
        cout << "Wie viele Mienen sollen versteckt werden? ";
        cin >> anzahlMinen;
        if(anzahlMinen<0||anzahlMinen>len){
            cout << "Die Anzahl der Minen sollte zwischen 1 und der Anzahl der Felder("<< len <<") sein. \n";
        }else{
            suitable=1;
            system("cls");
        }
    }

    int guessnr=0, guess=0;
    char guesslt='@';

    int i=0, n=0, x=0, random=0, count=0;
    vector <int> temp;
    bool repeat=1, alive=1, won=0, nulOnFeld=0, doAll=0;


    char feld[len], miFeld[len];
    char anzMi[len];

    int zeile = size;
    char czeile='@'+zeile;

    int col = 1;
    char row = czeile;

    for(i=0; i<len; i++){ //Felder werden erstellt
        feld[i] = '*';
        anzMi[i] = '0';
        miFeld[i] = '_';
    }

    for(i=0; i<anzahlMinen; i++){ //Minen werden versteckt
        srand((unsigned) time(0));
        while(repeat){
            random = rand() % len-1 + 1;
            if(miFeld[random]!='x' && random!=zeile-1){
                repeat = 0;
            }
        }
        repeat = 1;
        miFeld[random]='x';
        anzMi[random]=-9; //Mine selbst (um Automatisches aufdecken zu vermeiden)
        //TODO nicht über Rand hinweg
        anzMi[random-1]+=1, anzMi[random+1]+=1; //waagrecht
        anzMi[random+size]+=1, anzMi[random-size]+=1; //senkrecht
        anzMi[random-(size+1)]+=1, anzMi[random-(size-1)]+=1, anzMi[random+(size-1)]+=1, anzMi[random+(size+1)]+=1; //diagonal
    }
    repeat=1;

    while(alive){
        for(i=0; i<len; i++){ //Es wird überprüft, ob sichere Felder da sind. Falls ja werden diese aufgedeckt.
            if(feld[i]=='0'){
                guess=i;

                guess++;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //rechts
                }
                guess--;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //feld selbst
                }
                guess--;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //links
                }

                guess+=size;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //links unten
                }
                guess++;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //unten
                }
                guess++;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //rechts unten
                }

                guess-=2*size;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //rechts oben
                }guess--;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //oben
                }
                guess--;
                if(anzMi[guess]>0){
                    feld[guess] = anzMi[guess]; //links oben
                }
            }else{
                nulOnFeld=0;
            }
        }
        for(i=0; i<len; i++){
            if(feld[i]=='0'){
                feld[i]='_';
            }
        }

        if(!nulOnFeld){
            system("cls");
            //Ausgabe Feld:
            cout << " ";
            if(size>9){
                cout << " ";
            }
            for(i=0; i<zeile; i++){
                cout << " " << row;
                row--;
            }
            cout << endl;
            row = czeile;
            if(size>9){
                cout << " ";
            }

            cout << col << " ";

            for(i=0; i<len; i++){
                for(i=0; i<len; i++){
                    cout << feld[i] << " ";
                    if(!((i+1)%zeile)){
                        if(col<zeile){
                            col++;
                            cout << endl;
                            for(x=1;x<zeile+1;x*=10){
                                if(col<x){
                                    cout << " ";
                                }
                            }
                            cout << col << " ";

                        }
                    }
                }
            }
            col=1;
            cout << endl;
            while(repeat){ //Eingabe
                cout << endl;

                cout << "Welches Feld mochten Sie aufdecken? (1A-" << zeile << czeile<< ") "; //Eingabe, falls keine sicheren Felder vorhanden
                cin >> guessnr >> guesslt;

                guess=((czeile+1)-guesslt)+guessnr*size-size;

                if(guess>0 && guess<=len){
                    repeat=0;
                    if(feld[guess]=='*'){
                        count++;
                    }
                }else{
                    cout << endl << "Diese Eingabe ist nicht zulassig! \n" << endl;
                }
            }
            repeat=1;
        }

        if(miFeld[guess-1]!='x'){ //Felder werden aufgedeckt & makiert
            feld[guess-1] = anzMi[guess-1];

            for(i=0;i<len;i++){ //TODO gewinnbedingung
                if(count>=(len-anzahlMinen)){
                    won=1;
                }else{
                    won=0;
                }

            }
            if(won){
                cout << "Gewonnen! Congrats :)" << endl; //TODO Wenn alle "nichtminen" offen sind
            }
        }else{
            system("cls");
            cout << "Verloren! Du hast " << count << " Felder aufgedeckt!" << endl;

            for(i=0; i<zeile; i++){ //Mienenfeld wird ausgegeben
                cout << "  ";
                for(i=0; i<zeile; i++){
                    cout << " " << row;
                    row--;
                }
                cout << endl;
                cout << " " << col << " ";
                for(i=0; i<len; i++){
                    for(i=0; i<len; i++){
                        cout << miFeld[i] << " ";
                        if(!((i+1)%zeile)){
                            if(col<zeile){
                                col++;
                                cout << endl;
                                for(x=1;x<zeile+1;x*=size){
                                    if(col<x){
                                        cout << " ";
                                    }
                                }
                                cout << col << " ";
                            }
                        }
                    }
                }
                cout << endl;
                return 0;
            }
        }
    }
}


