#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const int MAX_ESTUDIANTES = 100;

class Estudiante {
private:
    string codigo;
    string nombre;
    int edad;
    string carrera;
    
public:
    // Constructor por defecto
    Estudiante() {
        codigo = "";
        nombre = "";
        edad = 0;
        carrera = "";
    }
    
    // Constructor con parámetros
    Estudiante(string c, string n, int e, string car) {
        codigo = c;
        nombre = n;
        edad = e;
        carrera = car;
    }
    
    // Getters
    string getCodigo() const {
        return codigo;
    }
    
    string getNombre() const {
        return nombre;
    }
    
    int getEdad() const {
        return edad;
    }
    
    string getCarrera() const {
        return carrera;
    }
    
    // Setters
    void setCodigo(string c) {
        codigo = c;
    }
    
    void setNombre(string n) {
        nombre = n;
    }
    
    void setEdad(int e) {
        edad = e;
    }
    
    void setCarrera(string car) {
        carrera = car;
    }
    
    // Método para mostrar los datos del estudiante
    void mostrar() const {
        cout << "----------------------------------------" << endl;
        cout << "Código: " << codigo << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << " años" << endl;
        cout << "Carrera: " << carrera << endl;
        cout << "----------------------------------------" << endl;
    }
};

class ListaEstudiantes {
private:
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int cantidadEstudiantes;
    
public:
    // Constructor
    ListaEstudiantes() {
        cantidadEstudiantes = 0;
    }
    
    // Método para registrar un estudiante
    void registrarEstudiante() {
        if (cantidadEstudiantes >= MAX_ESTUDIANTES) {
            cout << "¡Error! La lista de estudiantes está llena." << endl;
            return;
        }
        
        string codigo, nombre, carrera;
        int edad;
        
        cout << "\n--- REGISTRO DE ESTUDIANTE ---" << endl;
        cout << "Ingrese el código: ";
        cin.ignore();
        getline(cin, codigo);
        
        // Verificar si el código ya existe
        for (int i = 0; i < cantidadEstudiantes; i++) {
            if (estudiantes[i].getCodigo() == codigo) {
                cout << "¡Error! Ya existe un estudiante con ese código." << endl;
                return;
            }
        }
        
        cout << "Ingrese el nombre: ";
        getline(cin, nombre);
        
        cout << "Ingrese la edad: ";
        cin >> edad;
        cin.ignore(); // Limpiar el buffer
        
        cout << "Ingrese la carrera: ";
        getline(cin, carrera);
        
        estudiantes[cantidadEstudiantes] = Estudiante(codigo, nombre, edad, carrera);
        cantidadEstudiantes++;
        
        cout << "Estudiante registrado exitosamente." << endl;
    }
    
    // Método para mostrar todos los estudiantes
    void mostrarTodos() const {
        if (cantidadEstudiantes == 0) {
            cout << "\nNo hay estudiantes registrados." << endl;
            return;
        }
        
        cout << "\nLISTA DE ESTUDIANTES" << endl;
        cout << "========================================" << endl;
        cout << "Total de estudiantes: " << cantidadEstudiantes << endl;
        cout << "========================================" << endl;
        
        for (int i = 0; i < cantidadEstudiantes; i++) {
            cout << "\nEstudiante #" << (i + 1) << ":" << endl;
            estudiantes[i].mostrar();
        }
    }
    
    // Método para buscar un estudiante por código
    void buscarPorCodigo() const {
        if (cantidadEstudiantes == 0) {
            cout << "\nNo hay estudiantes registrados." << endl;
            return;
        }
        
        string codigoBuscar;
        cout << "\nBUSCAR ESTUDIANTE POR CÓDIGO" << endl;
        cout << "Ingrese el código del estudiante: ";
        cin.ignore();
        getline(cin, codigoBuscar);
        
        bool encontrado = false;
        
        for (int i = 0; i < cantidadEstudiantes; i++) {
            if (estudiantes[i].getCodigo() == codigoBuscar) {
                cout << "\nEstudiante encontrado:" << endl;
                estudiantes[i].mostrar();
                encontrado = true;
                break;
            }
        }
        
        if (!encontrado) {
            cout << "\nNo se encontró ningún estudiante con el código: " << codigoBuscar << endl;
        }
    }
    
    // Getter para la cantidad de estudiantes
    int getCantidadEstudiantes() const {
        return cantidadEstudiantes;
    }
    
    // Método para verificar si la lista está vacía
    bool estaVacia() const {
        return cantidadEstudiantes == 0;
    }
    
    // Método para verificar si la lista está llena
    bool estaLlena() const {
        return cantidadEstudiantes >= MAX_ESTUDIANTES;
    }
};

int main() {
    ListaEstudiantes lista;
    int opcion;
    
    cout << "SISTEMA DE GESTIÓN DE ESTUDIANTES" << endl;
    cout << "========================================" << endl;
    
    do {
        cout << "\n--- MENÚ PRINCIPAL ---" << endl;
        cout << "1. Registrar estudiante" << endl;
        cout << "2. Mostrar todos los estudiantes" << endl;
        cout << "3. Buscar estudiante por código" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                lista.registrarEstudiante();
                break;
                
            case 2:
                lista.mostrarTodos();
                break;
                
            case 3:
                lista.buscarPorCodigo();
                break;
                
            case 4:
                cout << "\nSaliendo del programa..." << endl;
                break;
                
            default:
                cout << "\nOpción inválida. Por favor, seleccione una opción válida." << endl;
        }
        
    } while (opcion != 4);
    
    return 0;
}