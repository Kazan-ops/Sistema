#include <iostream>Add commentMore actions
#include <vector>
#include <limits>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    int edad;
    float nota;
};

int pedirEnteroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor <=0){

            cout <<"Entrada invalida. Por favor ingrese un numero entero mayor a cero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

float pedirNota(const string& mensaje) {
    float valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor < 0.0 || valor > 100.0) {
            cout << "Entrada invalida. Ingrese una nota entre 0 y 100." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

void capturaAlumnos(vector<Alumno>& alumnos, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        Alumno a;
        cout << "\nAlumno #" << (i + 1) << endl;

        cout << "Nombre: ";
        getline(cin, a.nombre);

        a.edad = pedirEnteroPositivo("Edad: ");
        a.nota = pedirNota("Nota final: ");

        alumnos.push_back(a);
    }
}

int main (){
    int cantidadAlumnos = pedirEnteroPositivo ("Cuantos alumnos desea evaluar? ");
    vector<Alumno> alumnos;
    
    capturaAlumnos(alumnos, cantidadAlumnos);

    // Mostrar los datos capturados
    cout << "\n=== Datos de los alumnos ===\n";
    for (int i = 0; i < alumnos.size(); ++i) {
        cout << "Alumno #" << (i + 1) << ": "
             << alumnos[i].nombre << ", Edad: "
             << alumnos[i].edad << ", Nota: "
             << alumnos[i].nota << endl;
    }
    
    return 0;

}
