#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    int guessnr=0, guess=0;
    char guesslt='@';

    int col =1;
    char row='A';
    int i=0, len=100, random=0, lvl=25, count=0, allcount=0;
    bool contin=1, repeat=1, won=0;
    char feld[len], miFeld[len];
    char anzMi[len];

    int zeile=int(sqrt(len));
    char czeile=guesslt+zeile;

    for(i=0; i<len; i++){ //Felder werden erstellt
        feld[i] = '*';
        anzMi[i] = '0';
        miFeld[i] = '_';
        if(!((i+1)%zeile)){
        }
    }
    cout << "Minen werden generiert... " << endl;

    for(i=0; i<lvl; i++){ //Minen werden versteckt
        while(contin){
            srand((unsigned) time(0));
            random = rand() % len-1 + 1;
            if(miFeld[random]!='x'){
                cout << "|";
                contin = 0;
            }
        }
        contin = 1;
        miFeld[random]='x';
        anzMi[random]+=1, anzMi[random-1]+=1, anzMi[random+1]+=1, anzMi[random+10]+=1, anzMi[random-10]+=1;
    }
    cout << endl << endl;

    while(!won){
        for(i=0; i<len; i++){ //Es wird überprüft, ob sichere Felder da sind
            for(i=0; i<len;i++){
                    if(feld[i]=='-'){ //Felder um sicheres Feld herum werden aufgedeckt
                        feld[i+1] = anzMi[i+1];
                        feld[i-1] = anzMi[i-1];
                        feld[i+10] = anzMi[i+10];
                        feld[i-10] = anzMi[i-10];
                    }
                }
                allcount++;
            }


            for(i=0; i<len;i++){
                if(feld[i]=='0'){
                    feld[i]='-';
                }
            }
            while(repeat){ //Feld wird ausgegeben
                cout << " ";
                for(i=0; i<zeile; i++){
                    cout << " " << row;
                    row++;
                }
                cout << endl;
                row='A';
                cout << col << " ";
                for(i=0; i<len; i++){
                    for(i=0; i<len; i++){
                        cout << feld[i] << " ";
                        if(!((i+1)%zeile)){
                            if(col<zeile){
                                col++;
                                cout << endl << col << " ";
                            }
                        }
                    }
                }
                col=1;
                cout << endl;

                cout << "Geben Sie eine Zahl zwischen 1 und " << zeile << ": "; //Eingabe, falls keine sicheren Felder vorhanden
                cin >> guessnr;
                cout << endl;

                cout << "Geben Sie einen Buchstaben zwischen A und " << czeile << ": "; //Eingabe, falls keine sicheren Felder vorhanden
                cin >> guesslt;
                cout << endl;

                guess=((czeile+1)-guesslt)+guessnr*10-10;

                if(guess>0 && guess<=len){
                    repeat=0;
                    if(feld[guess]=='*'){
                        count++, allcount++;
                    }
                }else{
                    cout << "Diese Eingabe ist nicht zulassig! " << endl;
                }
            }
        }

        if(miFeld[guess-1]!='x'){ //Felder werden aufgedeckt & makiert
            feld[guess-1] = anzMi[guess-1];
            }
            if(count>=(len-lvl)){
                won=1;
            }

    if(won){
        cout << "Gewonnen! Congrats :)" << endl;
    }else{
        cout << "Verloren! Du hast " << count << " Felder aufgedeckt!" << endl;
        cout << "Insgesamt wurden " << allcount << " Felder aufgedeckt!" << endl;

        for(i=0; i<zeile; i++){ //Mienenfeld wird ausgegeben
            cout << " ";
            for(i=0; i<zeile; i++){
                cout << " " << row;
                row++;
            }
            cout << endl;
            row='A';
            cout << col << " ";
            for(i=0; i<len; i++){
                for(i=0; i<len; i++){
                    cout << miFeld[i] << " ";
                    if(!((i+1)%zeile)){
                        if(col<zeile){
                            col++;
                            cout << endl << col << " ";
                        }
                    }
                }
            }
            col=1;
            cout << endl;
        }
    }
    return 0;
}
