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
};

int main() {
    Cola cola;
    string nombre;
    int opcion;
    
    do {
        cout << "\nSISTEMA DE ATENCION " << endl;
        cout << "========================" << endl;
        cout << "1. Registrar persona" << endl;
        cout << "2. Atender persona" << endl;
        cout << "3. Mostrar siguiente en atender" << endl;
        cout << "4. Mostrar todos los registrados" << endl;
        cout << "5. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                if (cola.getCantidadElementos() >= 10) {
                    cout << "Ya se registraron 10 personas. No se pueden agregar mas." << endl;
                } else {
                    cout << "Ingrese nombre de la persona: ";
                    cin >> nombre;
                    cola.encolar(nombre);
                    cout << "Persona registrada: " << nombre << endl;
                    cout << "Personas en espera: " << cola.getCantidadElementos() << endl;
                }
                break;
                
            case 2:
                if (cola.estaVacia()) {
                    cout << "No hay personas para atender." << endl;
                } else {
                    string atendido = cola.desencolar();
                    cout << "Atendiendo a: " << atendido << endl;
                    cout << "Personas en espera: " << cola.getCantidadElementos() << endl;
                }
                break;
                
            case 3:
                if (cola.estaVacia()) {
                    cout << "No hay personas en espera." << endl;
                } else {
                    cout << "Siguiente en atender: " << cola.obtenerFrente() << endl;
                }
                break;
                
            case 4:
                if (cola.estaVacia()) {
                    cout << "No hay personas registradas." << endl;
                } else {
                    cout << "\nPERSONAS REGISTRADAS" << endl;
                    cout << "====================" << endl;
                    Cola temporal = cola;
                    int posicion = 1;
                    while (!temporal.estaVacia()) {
                        cout << posicion << ". " << temporal.desencolar() << endl;
                        posicion++;
                    }
                    cout << "Total: " << cola.getCantidadElementos() << " personas" << endl;
                }
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