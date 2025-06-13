#include <iostream>
#include <vector>
#include <limits>
#include <string>

using namespace std;

struct Alumno {
    string nombre, apellido1, apellido2;
    int ciclo, cedula;
    vector<float> notas;
    float promedio;
};

int pedirEnteroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor <= 0) {
            cout << "Entrada invalida. Por favor ingrese un numero entero mayor a cero." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

float pedirNota(int numero) {
    float valor;
    while (true) {
        cout << "Ingrese la nota #" << numero << ": ";
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

Alumno capturaAlumno(int numero) {
    Alumno a;
    cout << "\n==============================" << endl;
    cout << "  Ingreso de datos - Alumno #" << numero << endl;
    cout << "==============================" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // limpiar buffer antes de getline

    cout << "Ingrese primer nombre: ";
    getline(cin, a.nombre);

    cout << "Ingrese primer apellido: ";
    getline(cin, a.apellido1);

    cout << "Ingrese segundo apellido: ";
    getline(cin, a.apellido2);

    a.ciclo = pedirEnteroPositivo("Ingrese ciclo de estudio: ");
    a.cedula = pedirEnteroPositivo("Ingrese numero de cedula: ");

    float sumaNotas = 0;
    for (int i = 0; i < 5; ++i) {
        float nota = pedirNota(i + 1);
        a.notas.push_back(nota);
        sumaNotas += nota;
    }

    a.promedio = sumaNotas / 5.0;

    return a;
}

int main() {
    int cantidadAlumnos = pedirEnteroPositivo("Cuantos alumnos desea evaluar? ");
    vector<Alumno> alumnos;

    for (int i = 0; i < cantidadAlumnos; ++i) {
        Alumno nuevoAlumno = capturaAlumno(i + 1);
        alumnos.push_back(nuevoAlumno);
    }

    cout << "\n=== Datos de los alumnos ===\n";
    for (int i = 0; i < (int)alumnos.size(); ++i) {
        Alumno a = alumnos[i];
        cout << "Alumno #" << (i + 1) << ": " << a.nombre << " " << a.apellido1 << " " << a.apellido2
             << "\nCedula: " << a.cedula
             << "\nCiclo: " << a.ciclo
             << "\nNotas: ";
        for (size_t j = 0; j < a.notas.size(); ++j) {
            cout << a.notas[j] << " ";
        }
        cout << "\nPromedio: " << a.promedio << "\n\n";
    }

    return 0;
}

