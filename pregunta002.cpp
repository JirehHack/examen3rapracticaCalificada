#include <iostream>
#include <string>
using namespace std;

const int MAX_PILA = 100;

class Pila {
private:
    char elementos[MAX_PILA];
    int tope;
    
public:
    Pila() {
        tope = -1;
    }
    
    bool estaVacia() {
        return tope == -1;
    }
    
    bool estaLlena() {
        return tope == MAX_PILA - 1;
    }
    
    void push(char valor) {
        if (estaLlena()) {
            cout << "Error: Pila llena." << endl;
            return;
        }
        tope++;
        elementos[tope] = valor;
    }
    
    char pop() {
        if (estaVacia()) {
            return '\0';
        }
        char valor = elementos[tope];
        tope--;
        return valor;
    }
    
    int getCantidadElementos() {
        return tope + 1;
    }
};

int main() {
    Pila pila;
    string palabra;
    
    cout << "Ingrese una palabra: ";
    cin >> palabra;
    
    for (int i = 0; i < (int)palabra.length(); i++) {
        pila.push(palabra[i]);
    }
    
    cout << "Palabra original: " << palabra << endl;
    cout << "Palabra invertida: ";
    
    while (!pila.estaVacia()) {
        cout << pila.pop();
    }
    cout << endl;
    
    return 0;
}