#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int durchschnitt=0, median=0, max=0, min=0, anzahl=0, i=0, wert=0;
    vector <int> werte;

    max = INT_MIN;
    min = INT_MAX;


    cout << "Ihre erste Eingabe: ";
    cin >> wert;

    while(wert>0){
        werte.push_back(wert);
        anzahl++;

        if(wert>max){
            max = wert;
        }
        if(wert<min){
            min = wert;
        }

        durchschnitt += wert;

        cout << "Ihre nachste Eingabe (drucken Sie '0' um die Eingabe zu beenden): ";
        cin >> wert;

    }

    cout << endl << "Es wurden die " << anzahl << " Werte: ";

    for(i=0; i<anzahl-1; i++){
        if(i<anzahl-2){
            cout << werte[i] << ", ";
        }else{
            cout << werte[i];
        }
    }
    cout << " und " << werte[i];

    cout << " eingegeben." << endl;

    durchschnitt /= anzahl;
    cout << "Der Durchschnitt betragt: " << durchschnitt << endl;
    median = (min+max)/2;
    cout << "Der Median betragt: " << median << endl;
    cout << "Das Maximum betragt: " << max << endl;
    cout << "Das Minimum betragt: " << min << endl;
    return 0;
}
