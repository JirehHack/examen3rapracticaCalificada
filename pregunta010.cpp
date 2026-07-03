#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX_CONTACTOS = 100;

class Contacto {
    private:
        string nombre;
        string telefono;
        string correo;
    public:
        Contacto() {
            nombre = "";
            telefono = "";
            correo = "";
        }

        Contacto(string n, string t, string c) {
            nombre = n;
            telefono = t;
            correo = c;
        }

        string getnombre() {
            return nombre;
        }

        string gettelefono() {
            return telefono;
        }

        string getcorreo() {
            return correo;
        }

        void setnombre(string n) {
            nombre = n;
        }

        void settelefono(string t) {
            telefono = t;
        }

        void setcorreo(string c) {
            correo = c;
        }
        
        void mostrarMenú() {
            cout << "-----------------------------" << endl;
            cout << "Nombre: " << endl;
            cout << "Teléfono: " << endl;
            cout << "Correo: " << endl;
            cout << "-----------------------------" << endl;
        }
};

class Agenda {
    private:
        Contacto contactos[MAX_CONTACTOS];
        int cantidadContactos;
    public:
        Agenda() {
            cantidadContactos = 0;
        }

        //metodo para agregar contacto//
        void agregarContactos() {
            if (cantidadContactos >= MAX_CONTACTOS) {
                cout << "No se puede agregar más contactos. La agenda está llena." << endl;

                return;
            }

            string nombre, telefono, correo;

            cout << "Ingrese el nombre del contacto: ";
            cin.ignore();
            getline(cin, nombre);

            cout << "ingrese el telefono del contacto: ";
            getline(cin, telefono);

            cout << "Ingrese el correo del contacto: ";
            getline(cin, correo);

            contactos[cantidadContactos] = Contacto(nombre, telefono, correo);
            cantidadContactos++;

            cout << "El contacto ha sido guardado con éxito." << endl;
        }
        
        void buscarContacto() {
            if (cantidadContactos == 0) {
                cout << "No hay ningun contacto en la agenda." << endl;

                return;
            }

            string nombreBuscar;

            cout << "Ingrese el nombre del contacto que quiera buscar: ";
            cin.ignore();
            getline(cin, nombreBuscar);

            bool encontrado = false;
            for (int i = 0; i < cantidadContactos; i++) {
                string nombreContacto = contactos[i].getnombre();
                string nombreBusqueda = nombreBuscar;

                for (char &c : nombreContacto) c = tolower(c);
                for (char &c : nombreBusqueda) c = tolower(c);

                if (nombreContacto == nombreBusqueda) {
                    cout << "Contacto encontrado: " << endl;
                    contactos[i].mostrarMenú();
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "No se encontró el contacto con el nombre específico." << endl;
            }
        }

        void eliminarContacto() {
            if (cantidadContactos == 0) {
                cout << "No hay ningún contacto en la agenda." << endl;

                return;
            }

            string nombreEliminar;

            cout <<"Ingrese el nombre del contacto que quiere eliminar: ";
            cin.ignore();
            getline(cin, nombreEliminar);

            bool encontrado = false;
            
            for (int i = 0; i < cantidadContactos; i++) {
                string nombreContactos = contactos[i].getnombre();
                string nombreBusqueda = nombreEliminar;

                for (char &c : nombreContactos) c = tolower(c);
                for (char &c : nombreBusqueda) c = tolower(c);

                if (nombreContactos == nombreBusqueda) {
                    for (int j = i; j < cantidadContactos - 1; j++) {
                        contactos[j] = contactos[j + 1];
                    }

                    cantidadContactos--;

                    cout << "El contacto ha sido eliminado éxitosamente. " << endl;
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado) {
                cout << "No se encontró el contacto con el nombre específico." << endl;
            }
        }
        
        void mostrarTodos() {
            if (cantidadContactos == 0) {
                cout << "No hay ningún contacto en la agenda." << endl;

                return;
            }

            cout << "Lista de contactos: " << endl;
            cout << "==============================" << endl;
            for (int i = 0; i < cantidadContactos; i++) {
                cout << "Contactos#" << i + 1 << endl;
                contactos[i].mostrarMenú();
            }

            cout << "Cantidad de contactos: " << cantidadContactos << endl;
        }

        int getcantidadContactos() {
            return cantidadContactos;
        }
};

int main() {
    Agenda agenda;
    int opción;
    
    do {
        cout << "==============================" << endl;
        cout << "1. Agregar contacto" << endl;
        cout << "2. Buscar contactos por nombre" << endl;
        cout << "3. Eliminar contacto" << endl;
        cout << "4. Mostrar todos los contactos" << endl;
        cout << "5. Salir" << endl;
        cout << "Selecione una opción: ";
        cin >> opción;
        
        switch (opción) {
            case 1:
                agenda.agregarContactos();
                break;
            case 2:
                agenda.buscarContacto();
                break;
            case 3:
                agenda.eliminarContacto();
                break;
            case 4:
                agenda.mostrarTodos();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Por favor, seleccione una opción válida." << endl;
        }
    } while (opción != 5);

    return 0;
}
