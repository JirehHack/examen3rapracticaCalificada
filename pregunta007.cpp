#include <iostream>
#include <string>
using namespace std;

const int MAX_CLIENTES = 100;

class Cliente {
private:
    string nombre;
    int numeroTurno;
    string tipoServicio;
    
public:
    Cliente() {
        nombre = "";
        numeroTurno = 0;
        tipoServicio = "";
    }
    
    Cliente(string n, int nt, string ts) {
        nombre = n;
        numeroTurno = nt;
        tipoServicio = ts;
    }
    
    string getNombre() const {
        return nombre;
    }
    
    int getNumeroTurno() const {
        return numeroTurno;
    }
    
    string getTipoServicio() const {
        return tipoServicio;
    }
    
    void setNombre(string n) {
        nombre = n;
    }
    
    void setNumeroTurno(int nt) {
        numeroTurno = nt;
    }
    
    void setTipoServicio(string ts) {
        tipoServicio = ts;
    }
    
    void mostrar() const {
        cout << "Turno: " << numeroTurno << endl;
        cout << "Cliente: " << nombre << endl;
        cout << "Servicio: " << tipoServicio << endl;
        cout << "------------------------" << endl;
    }
};

class Banco {
private:
    Cliente clientes[MAX_CLIENTES];
    int cantidadClientes;
    int contadorTurnos;
    int turnoActual;
    
public:
    Banco() {
        cantidadClientes = 0;
        contadorTurnos = 0;
        turnoActual = 0;
    }
    
    void agregarCliente() {
        if (cantidadClientes >= MAX_CLIENTES) {
            cout << "Banco lleno. No se pueden agregar mas clientes." << endl;
            return;
        }
        
        string nombre, tipoServicio;
        
        cout << "Ingrese nombre del cliente: ";
        cin.ignore();
        getline(cin, nombre);
        
        cout << "Ingrese tipo de servicio (Caja/Credito/Asesoria): ";
        getline(cin, tipoServicio);
        
        contadorTurnos++;
        clientes[cantidadClientes] = Cliente(nombre, contadorTurnos, tipoServicio);
        cantidadClientes++;
        
        cout << "Cliente agregado. Turno asignado: " << contadorTurnos << endl;
    }
    
    void atenderCliente() {
        if (cantidadClientes == 0) {
            cout << "No hay clientes en espera." << endl;
            return;
        }
        
        cout << "Atendiendo al siguiente cliente:" << endl;
        clientes[0].mostrar();
        
        turnoActual = clientes[0].getNumeroTurno();
        
        for (int i = 0; i < cantidadClientes - 1; i++) {
            clientes[i] = clientes[i + 1];
        }
        cantidadClientes--;
    }
    
    void mostrarSiguienteCliente() {
        if (cantidadClientes == 0) {
            cout << "No hay clientes en espera." << endl;
            return;
        }
        
        cout << "Proximo cliente en ser atendido:" << endl;
        clientes[0].mostrar();
    }
    
    void mostrarCantidadClientes() {
        cout << "Clientes en espera: " << cantidadClientes << endl;
        cout << "Ultimo turno asignado: " << contadorTurnos << endl;
        if (turnoActual > 0) {
            cout << "Ultimo turno atendido: " << turnoActual << endl;
        }
    }
    
    void mostrarTodosClientes() {
        if (cantidadClientes == 0) {
            cout << "No hay clientes en espera." << endl;
            return;
        }
        
        cout << "LISTA DE CLIENTES EN ESPERA" << endl;
        cout << "============================" << endl;
        for (int i = 0; i < cantidadClientes; i++) {
            cout << "Posicion " << (i + 1) << ":" << endl;
            clientes[i].mostrar();
        }
    }
    
    int getCantidadClientes() const {
        return cantidadClientes;
    }
};

int main() {
    Banco banco;
    int opcion;
    
    do {
        cout << "SISTEMA BANCARIO" << endl;
        cout << "================" << endl;
        cout << "1. Agregar cliente" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Mostrar siguiente cliente" << endl;
        cout << "4. Mostrar cantidad de clientes" << endl;
        cout << "5. Mostrar todos los clientes" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                banco.agregarCliente();
                break;
            case 2:
                banco.atenderCliente();
                break;
            case 3:
                banco.mostrarSiguienteCliente();
                break;
            case 4:
                banco.mostrarCantidadClientes();
                break;
            case 5:
                banco.mostrarTodosClientes();
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);
    
    return 0;
}