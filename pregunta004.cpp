#include <iostream>
#include <string>
using namespace std;

const int MAX_PILA = 100;

class Pila {
private:
    string elementos[MAX_PILA];
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
    
    void push(string valor) {
        if (estaLlena()) {
            cout << "Error: Pila llena." << endl;
            return;
        }
        tope++;
        elementos[tope] = valor;
    }
    
    string pop() {
        if (estaVacia()) {
            return "";
        }
        string valor = elementos[tope];
        tope--;
        return valor;
    }
    
    string obtenerTope() {
        if (estaVacia()) {
            return "";
        }
        return elementos[tope];
    }
    
    int getCantidadElementos() {
        return tope + 1;
    }
};

int main() {
    Pila historial;
    int opcion;
    string pagina;
    string paginaActual = "";
    Pila pilaAuxiliar;
    
    do {
        cout << "\nHISTORIAL DE NAVEGACION" << endl;
        cout << "========================" << endl;
        cout << "1. Visitar pagina" << endl;
        cout << "2. Retroceder" << endl;
        cout << "3. Mostrar pagina actual" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese la URL de la pagina: ";
                cin >> pagina;
                
                if (!paginaActual.empty()) {
                    historial.push(paginaActual);
                }
                paginaActual = pagina;
                cout << "Visitando: " << paginaActual << endl;
                break;
                
            case 2:
                if (historial.estaVacia()) {
                    cout << "No hay paginas para retroceder." << endl;
                } else {
                    paginaActual = historial.pop();
                    cout << "Retrocediendo a: " << paginaActual << endl;
                }
                break;
                
            case 3:
                if (paginaActual.empty()) {
                    cout << "No hay pagina actual." << endl;
                } else {
                    cout << "Pagina actual: " << paginaActual << endl;
                }
                break;
                
            case 4:
                cout << "Saliendo del navegador..." << endl;
                break;
                
            default:
                cout << "Opcion invalida." << endl;
        }
        
    } while (opcion != 4);
    
    return 0;
}