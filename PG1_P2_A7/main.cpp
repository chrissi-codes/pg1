#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    int guess=0;
    int i=0, len=50, random=0, lvl=3, count=0;
    bool alive=1, contin=1, repeat=1;
    char feld[len], miFeld[len];

    for(i=0; i<len; i++){ //Felder werden erstellt
        feld[i] = '*';
        miFeld[i] = 'x';
        if(!((i+1)%10)){
        }
    }
    cout << "Minen werden generiert... " << endl << endl;

    for(i=0; i<lvl; i++){ //Minen werden versteckt
        srand((unsigned) time(0));
        while(contin){
            random = rand() % 49 + 1;
            if(miFeld[random]!='o'){
                contin = 0;
            }
        }
        contin = 1;
        miFeld[random]='o';
    }

    while(alive){
        for(i=0; i<len; i++){
            cout << feld[i];
            if(!((i+1)%10)){
                cout << endl;
            }
        }

        while(repeat){
            cout << "Geben Sie eine Zahl zwischen 1 und 50: ";
            cin >> guess;
            cout << endl;
            if(guess>0 && guess<=50){
                repeat=0;
                count++;
            }else{
                cout << "Diese Eingabe ist nicht zulassig! ";
            }
        }
        system("cls");
        if(miFeld[guess-1]!='o'){
            feld[guess-1] = '_';
            cin.clear();
            repeat=1;
        }else{
            alive = false;
        }

    }
    system("cls");
    cout << "Verloren! Du hast " << count << " Felder aufgedeckt!" << endl;
    for(i=0; i<len; i++){
        cout << miFeld[i];
        if(!((i+1)%10)){
            cout << endl;

        }
    }
    return 0;
}
