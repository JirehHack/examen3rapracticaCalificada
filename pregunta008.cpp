#include <iostream>
#include <string>
using namespace std;

const int MAX_TICKETS = 100;

class Ticket {
private:
    string codigo;
    string cliente;
    int prioridad;
    
public:
    Ticket() {
        codigo = "";
        cliente = "";
        prioridad = 0;
    }
    
    Ticket(string c, string cl, int p) {
        codigo = c;
        cliente = cl;
        prioridad = p;
    }
    
    string getCodigo() const {
        return codigo;
    }
    
    string getCliente() const {
        return cliente;
    }
    
    int getPrioridad() const {
        return prioridad;
    }
    
    void setCodigo(string c) {
        codigo = c;
    }
    
    void setCliente(string cl) {
        cliente = cl;
    }
    
    void setPrioridad(int p) {
        prioridad = p;
    }
    
    void mostrar() const {
        cout << "Codigo: " << codigo << endl;
        cout << "Cliente: " << cliente << endl;
        cout << "Prioridad: ";
        if (prioridad == 1) cout << "Alta";
        else if (prioridad == 2) cout << "Media";
        else if (prioridad == 3) cout << "Baja";
        cout << endl;
        cout << "------------------------" << endl;
    }
};

class SistemaTickets {
private:
    Ticket tickets[MAX_TICKETS];
    int cantidadTickets;
    
public:
    SistemaTickets() {
        cantidadTickets = 0;
    }
    
    void agregarTicket() {
        if (cantidadTickets >= MAX_TICKETS) {
            cout << "Sistema lleno. No se pueden agregar mas tickets." << endl;
            return;
        }
        
        string codigo, cliente;
        int prioridad;
        
        cout << "Ingrese codigo del ticket: ";
        cin.ignore();
        getline(cin, codigo);
        
        for (int i = 0; i < cantidadTickets; i++) {
            if (tickets[i].getCodigo() == codigo) {
                cout << "Ya existe un ticket con ese codigo." << endl;
                return;
            }
        }
        
        cout << "Ingrese nombre del cliente: ";
        getline(cin, cliente);
        
        cout << "Ingrese prioridad (1-Alta, 2-Media, 3-Baja): ";
        cin >> prioridad;
        
        while (prioridad < 1 || prioridad > 3) {
            cout << "Prioridad invalida. Ingrese 1, 2 o 3: ";
            cin >> prioridad;
        }
        
        tickets[cantidadTickets] = Ticket(codigo, cliente, prioridad);
        cantidadTickets++;
        cout << "Ticket agregado exitosamente." << endl;
    }
    
    void mostrarOrdenAtencion() {
        if (cantidadTickets == 0) {
            cout << "No hay tickets en el sistema." << endl;
            return;
        }
        
        Ticket temporal[MAX_TICKETS];
        int tempCantidad = cantidadTickets;
        
        for (int i = 0; i < cantidadTickets; i++) {
            temporal[i] = tickets[i];
        }
        
        for (int i = 0; i < tempCantidad - 1; i++) {
            for (int j = 0; j < tempCantidad - i - 1; j++) {
                if (temporal[j].getPrioridad() > temporal[j + 1].getPrioridad()) {
                    Ticket temp = temporal[j];
                    temporal[j] = temporal[j + 1];
                    temporal[j + 1] = temp;
                }
            }
        }
        
        cout << "ORDEN DE ATENCION" << endl;
        cout << "==================" << endl;
        cout << "Prioridad: 1 (Alta) > 2 (Media) > 3 (Baja)" << endl;
        cout << "==========================================" << endl;
        
        for (int i = 0; i < tempCantidad; i++) {
            cout << "Posicion " << (i + 1) << ":" << endl;
            temporal[i].mostrar();
        }
    }
    
    void mostrarTodos() {
        if (cantidadTickets == 0) {
            cout << "No hay tickets registrados." << endl;
            return;
        }
        
        cout << "LISTA DE TICKETS" << endl;
        cout << "=================" << endl;
        cout << "Total: " << cantidadTickets << " tickets" << endl;
        cout << "=================" << endl;
        
        for (int i = 0; i < cantidadTickets; i++) {
            cout << "Ticket #" << (i + 1) << ":" << endl;
            tickets[i].mostrar();
        }
    }
    
    void buscarPorCodigo() {
        if (cantidadTickets == 0) {
            cout << "No hay tickets registrados." << endl;
            return;
        }
        
        string codigoBuscar;
        cout << "Ingrese codigo del ticket: ";
        cin.ignore();
        getline(cin, codigoBuscar);
        
        bool encontrado = false;
        for (int i = 0; i < cantidadTickets; i++) {
            if (tickets[i].getCodigo() == codigoBuscar) {
                cout << "Ticket encontrado:" << endl;
                tickets[i].mostrar();
                encontrado = true;
                break;
            }
        }
        
        if (!encontrado) {
            cout << "No se encontro ticket con ese codigo." << endl;
        }
    }
    
    void eliminarTicket() {
        if (cantidadTickets == 0) {
            cout << "No hay tickets para eliminar." << endl;
            return;
        }
        
        string codigoEliminar;
        cout << "Ingrese codigo del ticket a eliminar: ";
        cin.ignore();
        getline(cin, codigoEliminar);
        
        bool encontrado = false;
        for (int i = 0; i < cantidadTickets; i++) {
            if (tickets[i].getCodigo() == codigoEliminar) {
                for (int j = i; j < cantidadTickets - 1; j++) {
                    tickets[j] = tickets[j + 1];
                }
                cantidadTickets--;
                cout << "Ticket eliminado exitosamente." << endl;
                encontrado = true;
                break;
            }
        }
        
        if (!encontrado) {
            cout << "No se encontro ticket con ese codigo." << endl;
        }
    }
    
    int getCantidadTickets() const {
        return cantidadTickets;
    }
};

int main() {
    SistemaTickets sistema;
    int opcion;
    
    do {
        cout << "SISTEMA DE ATENCION TECNICA" << endl;
        cout << "============================" << endl;
        cout << "1. Agregar ticket" << endl;
        cout << "2. Mostrar orden de atencion" << endl;
        cout << "3. Mostrar todos los tickets" << endl;
        cout << "4. Buscar ticket por codigo" << endl;
        cout << "5. Eliminar ticket" << endl;
        cout << "6. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                sistema.agregarTicket();
                break;
            case 2:
                sistema.mostrarOrdenAtencion();
                break;
            case 3:
                sistema.mostrarTodos();
                break;
            case 4:
                sistema.buscarPorCodigo();
                break;
            case 5:
                sistema.eliminarTicket();
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