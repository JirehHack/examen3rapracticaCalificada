#include <iostream>
#include <string>
using namespace std;

const int MAX_COLA = 100;

class Cola {
private:
    string elementos[MAX_COLA];
    int frente;
    int final;
    
public:
    Cola() {
        frente = 0;
        final = -1;
    }
    
    bool estaVacia() {
        return frente > final;
    }
    
    bool estaLlena() {
        return final == MAX_COLA - 1;
    }
    
    void encolar(string valor) {
        if (estaLlena()) {
            cout << "Error: Cola llena." << endl;
            return;
        }
        final++;
        elementos[final] = valor;
    }
    
    string desencolar() {
        if (estaVacia()) {
            return "";
        }
        string valor = elementos[frente];
        frente++;
        return valor;
    }
    
    string obtenerFrente() {
        if (estaVacia()) {
            return "";
        }
        return elementos[frente];
    }
    
    int getCantidadElementos() {
        if (estaVacia()) {
            return 0;
        }
        return final - frente + 1;
    }
    
    void mostrarTodos() {
        if (estaVacia()) {
            cout << "No hay clientes en espera." << endl;
            return;
        }
        cout << "Clientes en espera:" << endl;
        for (int i = frente; i <= final; i++) {
            cout << (i - frente + 1) << ". " << elementos[i] << endl;
        }
    }
};

int main() {
    Cola cola;
    int opcion;
    string nombre;
    
    do {
        cout << "\nSISTEMA DE ATENCION AL CLIENTE" << endl;
        cout << "==============================" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar cliente atendido" << endl;
        cout << "4. Mostrar clientes pendientes" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                cout << "Ingrese nombre del cliente: ";
                cin >> nombre;
                cola.encolar(nombre);
                cout << "Cliente registrado: " << nombre << endl;
                cout << "Clientes en espera: " << cola.getCantidadElementos() << endl;
                break;
                
            case 2:
                if (cola.estaVacia()) {
                    cout << "No hay clientes para atender." << endl;
                } else {
                    string atendido = cola.desencolar();
                    cout << "Cliente atendido: " << atendido << endl;
                    cout << "Clientes en espera: " << cola.getCantidadElementos() << endl;
                }
                break;
                
            case 3:
                if (cola.estaVacia()) {
                    cout << "No hay clientes atendidos recientemente." << endl;
                } else {
                    cout << "Proximo cliente a atender: " << cola.obtenerFrente() << endl;
                }
                break;
                
            case 4:
                cola.mostrarTodos();
                break;
                
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
                
            default:
                cout << "Opcion invalida." << endl;
        }
        
    } while (opcion != 5);
    
    return 0;
}