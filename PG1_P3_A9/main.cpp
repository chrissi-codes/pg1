#include <iostream>

using namespace std;

void fun(int *ptr){
    cout << ptr << endl; //bei *ptr wird nur der Wert von a ausgegeben, bei ptr der Speicherort von a sowie der von b und ein "hello world"
}

int main()
{
    int a = 42; //Deklariert und initialisiert
    int *b = nullptr; //Zeigt auf Anfang vom Speicher

    fun(&a); //Referenz wird erstellt -> Speicherstelle wird weitergegeben
    fun(b); //Der Pointer wird einfach weitergegeben -> nullptr -> hat keinen wert welcher ausgegeben werden kann

    cout << "Hello World!" << endl; //Wird durch *ptr nicht ausgegeben

    return 0;
}
