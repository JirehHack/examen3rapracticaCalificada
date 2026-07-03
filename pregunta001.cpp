#include <iostream>
using namespace std;

const int MAX_PILA = 100;

class Pila {
private:
    int elementos[MAX_PILA];
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
    
    void push(int valor) {
        if (estaLlena()) {
            cout << "Error: Pila llena." << endl;
            return;
        }
        tope++;
        elementos[tope] = valor;
    }
    
    int pop() {
        if (estaVacia()) {
            return -1;
        }
        int valor = elementos[tope];
        tope--;
        return valor;
    }
    
    int getCantidadElementos() {
        return tope + 1;
    }
    
    int getUltimoElemento() {
        if (estaVacia()) {
            return -1;
        }
        return elementos[tope];
    }
};

int main() {
    Pila pila;
    int numero;
    
    cout << "Ingrese numeros (-1 para terminar):" << endl;
    
    while (true) {
        cout << "Numero: ";
        cin >> numero;
        
        if (numero == -1) {
            break;
        }
        
        pila.push(numero);
    }
    
    cout << "\nRESULTADOS:" << endl;
    cout << "================================" << endl;
    cout << "Cantidad de elementos en la pila: " << pila.getCantidadElementos() << endl;
    
    if (pila.getCantidadElementos() > 0) {
        cout << "Ultimo elemento ingresado: " << pila.getUltimoElemento() << endl;
    } else {
        cout << "No se ingresaron elementos." << endl;
    }
    
    return 0;
}