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

float calcularPromedio(const vector<float>& notas) {
    float suma = 0;
    for (size_t i = 0; i < notas.size(); ++i) {
        suma += notas[i];
    }
    return notas.empty() ? 0 : suma / notas.size();
}

Alumno capturaAlumno(int numero) {
    Alumno a;
    cout << "\n==============================" << endl;
    cout << "  Ingreso de datos - Alumno #" << numero << endl;
    cout << "==============================" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "Ingrese primer nombre: ";
    getline(cin, a.nombre);

    cout << "Ingrese primer apellido: ";
    getline(cin, a.apellido1);

    cout << "Ingrese segundo apellido: ";
    getline(cin, a.apellido2);

    a.ciclo = pedirEnteroPositivo("Ingrese ciclo de estudio: ");
    a.cedula = pedirEnteroPositivo("Ingrese numero de cedula: ");

    for (int i = 0; i < 5; ++i) {
        a.notas.push_back(pedirNota(i + 1));
    }

    a.promedio = calcularPromedio(a.notas);
    return a;
}

void clasificarAlumnos(const vector<Alumno>& alumnos, vector<Alumno>& aprobados, vector<Alumno>& reprobados) {
    for (size_t i = 0; i < alumnos.size(); ++i) {
        if (alumnos[i].promedio >= 60.0) {
            aprobados.push_back(alumnos[i]);
        } else {
            reprobados.push_back(alumnos[i]);
        }
    }
}

int main() {
    int cantidadAlumnos = pedirEnteroPositivo("Cuantos alumnos desea evaluar? ");
    vector<Alumno> alumnos;

    for (int i = 0; i < cantidadAlumnos; ++i) {
        alumnos.push_back(capturaAlumno(i + 1));
    }

    vector<Alumno> aprobados;
    vector<Alumno> reprobados;

    clasificarAlumnos(alumnos, aprobados, reprobados);

    cout << "\n=== Alumnos Aprobados ===\n";
    for (size_t i = 0; i < aprobados.size(); ++i) {
        cout << aprobados[i].nombre << " " << aprobados[i].apellido1 << " " << aprobados[i].apellido2
             << " - Promedio: " << aprobados[i].promedio << "\n";
    }

    cout << "\n=== Alumnos Reprobados ===\n";
    for (size_t i = 0; i < reprobados.size(); ++i) {
        cout << reprobados[i].nombre << " " << reprobados[i].apellido1 << " " << reprobados[i].apellido2
             << " - Promedio: " << reprobados[i].promedio << "\n";
    }

    return 0;
}

