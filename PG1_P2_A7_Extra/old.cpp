#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int guess=0;
    int i=0, len=50, random=0, lvl=7, count=0, allcount=0;
    bool alive=1, contin=1, repeat=1, won=0, nulOnFeld=0;
    char feld[len], miFeld[len];
    char anzMi[len];

    for(i=0; i<len; i++){ //Felder werden erstellt
        feld[i] = '*';
        anzMi[i] = '0';
        miFeld[i] = 'x';
        if(!((i+1)%10)){
        }
    }
    cout << "Minen werden generiert... " << endl << endl;

    for(i=0; i<lvl; i++){ //Minen werden versteckt
        while(contin){
            srand((unsigned) time(0));
            random = rand() % 49 + 1;
            if(miFeld[random]!='o'){
                contin = 0;
            }
        }
        contin = 1;
        miFeld[random]='o';
        anzMi[random]+=1, anzMi[random-1]+=1, anzMi[random+1]+=1, anzMi[random+10]+=1, anzMi[random-10]+=1;
    }

    while(alive&&!won){
        for(i=0; i<len; i++){ //Es wird überprüft, ob sichere Felder da sind
            if(!nulOnFeld){
                if(feld[i]=='0'){
                    nulOnFeld=1;
                }else{
                    nulOnFeld=0;
                }
            }

        }

            if(!nulOnFeld){
                while(repeat){ //Feld wird ausgegeben
                    for(i=0; i<len; i++){
                        for(i=0; i<len; i++){
                            cout << feld[i];
                            if(!((i+1)%10)){
                                cout << endl;
                            }
                        }
                    }

                    cout << "Geben Sie eine Zahl zwischen 1 und 50: "; //Eingabe, falls keine sicheren Felder vorhanden
                    cin >> guess;
                    cout << endl;
                    if(guess>0 && guess<=50){
                        repeat=0;
                        if(feld[guess]=='*'){
                            count++, allcount++;
                        }
                    }else{
                        cout << "Diese Eingabe ist nicht zulassig! ";
                    }
                }
            }else{
                i=0;
                while(repeat){ //Herausfinden von sicheren Feldern
                    guess=i+1;
                    if(feld[guess-1]=='0'){
                        repeat=0;
                    }else{
                        i++;
                    }
                }
                allcount++;
                nulOnFeld=0;
            }

            if(miFeld[guess-1]!='o'){ //Felder werden aufgedeckt & makiert
                feld[guess-1] = '_';

                if(feld[guess-2]=='*'){
                   feld[guess-2] = anzMi[guess-2];
                }
                if(feld[guess]=='*'){
                   feld[guess] = anzMi[guess];
                }
                if(feld[guess-11]=='*'){
                   feld[guess-11] = anzMi[guess-11];
                }
                if(feld[guess+9]=='*'){
                   feld[guess+9] = anzMi[guess+9];
                }

                repeat=1;
            }else{
                alive = false; //Tod bei Mine
            }
            if(count>=(len-lvl)){
                won=1;
            }
    }
    if(won){
        cout << "Gewonnen! Congrats :)" << endl;
    }else{
        cout << "Verloren! Du hast " << count << " Felder aufgedeckt!" << endl;
        cout << "Insgesamt wurden " << allcount << " Felder aufgedeckt!" << endl;
        for(i=0; i<len; i++){
            cout << miFeld[i];
            if(!((i+1)%10)){
                cout << endl;
            }
        }
    }
    return 0;
}
