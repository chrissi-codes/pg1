#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool palindrom(string wort){
    string rev = wort;
    reverse(rev.begin(), rev.end());
    if(wort==rev){
        return 1;
    }
    return 0;
}

string sortieren(string wort){ //TODO fix
    int i, n, j;
    char temp;

    for(j=0; j<wort.length(); j++){
        for(i=0; i<wort.length(); i++){
            if(wort[i]<wort[i-1]){
                temp=wort[i];
                wort[i]=wort[i-1];
                wort[i-1]=temp;
            }
        }
    }
    return wort;
}

int main()
{
    string wort;
    cout << "Welches Wort soll getestet werden? ";
    cin >> wort;
    transform(wort.begin(), wort.end(), wort.begin(), ::toupper);
    if(palindrom(wort)){
        cout << "Das Wort " << wort << " ist ein Palindrom :)" << endl;
    }else{
        cout << "Das Wort " << wort << " ist kein Palindrom :(" << endl;
    }

    wort=sortieren(wort);
    cout << "Alphabetisch sortiert: " << wort << endl;

    return 0;
}
