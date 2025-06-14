#include <iostream>
#include <vector>
#include <limits> //Si preguntas esto lo que hace es limpiar el buffer
#include <string>
#include <iomanip>

using namespace std;

// Struct Alumno original esta incopleto se elimino tambien (edad y notas)
// Esta ahora s la struct final de Alumnos
struct Alumno {
    string nombre, apellido1, apellido2;
    int ciclo, cedula;
    vector<float> notas;
    float promedio;
};
// Estos espara capturar los datos y el de arriba usted sabe para que es

//Funcion original de capturaAlumnos tambien esta incopleta, eliminado
//Funcion final de captura
int pedirEnteroPositivo(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        cin >> valor;

        if (cin.fail() || valor <= 0) {
            cout << "Entrada invalida. Por favor ingrese un numero entero mayor a cero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

//Esta función ahora usa el número para mostrar cuál nota se está pidiendo
float pedirNota(int numero) {
    float valor;
    while (true) {
        cout << "Ingrese la nota #" << numero << ": ";
        cin >> valor;

        if (cin.fail() || valor < 0.0 || valor > 100.0) {
            cout << "Su entrada es invalida, digite una nota que sea entre 0 y 100" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return valor;
        }
    }
}

//Funcion final de captura
Alumno capturaAlumno(int numero) {
    Alumno a;
    cout << "\n==============================" << endl;
    cout << "  Ingreso de datos - Alumno #" << numero << endl;
    cout << "==============================" << endl;

    cin.ignore(); // Limpiar antes de getline
    cout << "Ingrese primer nombre: ";
    getline(cin, a.nombre);

    cout << "Ingrese primer apellido: ";
    getline(cin, a.apellido1);

    cout << "Ingrese segundo apellido: ";
    getline(cin, a.apellido2);

    a.ciclo = pedirEnteroPositivo("Ingrese ciclo de estudio: ");
    a.cedula = pedirEnteroPositivo("Ingrese numero de cedula: ");

    float sumaNotas = 0;
    for (int i = 0; i < 5; ++i) { // ← Corregido el error de coma
        float nota = pedirNota(i + 1);
        a.notas.push_back(nota); // ← Añadimos la nota al vector
        sumaNotas += nota;
    }
    a.promedio = sumaNotas / 5.0;

    return a;
}

// Funcion para mostrar listas de alumnos aprobados y reprobados
void mostrarAlumnos(const vector<Alumno>& lista, const string& titulo) {
    cout << "\n========== " << titulo << " ==========\n";
    cout << left << setw(30) << "Nombre completo"
         << setw(8) << "Ciclo"
         << setw(15) << "Cedula"
         << setw(10) << "Promedio" << endl;
    cout << "--------------------------------------------------------------\n";

    for (const Alumno& a : lista) {
        string nombreCompleto = a.nombre + " " + a.apellido1 + " " + a.apellido2;
        cout << "> " << left << setw(30) << nombreCompleto
             << "(" << a.ciclo << ")" << setw(5) << ""
             << setw(15) << a.cedula
             << fixed << setprecision(2) << setw(10) << a.promedio << endl;
    }

    cout << "Costa Rica, Guanacaste, 2025\n";
}

int main() {
    int cantidadAlumnos = pedirEnteroPositivo("Cuantos alumnos desea evaluar? ");
    vector<Alumno> alumnos;

    //Aqui vamos a crear un bucle para capturar los datos de cada alumno
    // Darian usted puede ir implementando la estructura Alumno y el Vector dinamico de los Alumnos
    // A su vezpuedes definir la funcion capturaAlumnos() para que nos ordenemos mejor

    for (int i = 0; i < cantidadAlumnos; i++) {
        Alumno nuevoAlumno = capturaAlumno(i + 1);
        alumnos.push_back(nuevoAlumno);

        //Te encvargo capturar las 5 notas del alumno y calcular el promedio de estas
        //Use Validacionees para cada nota: entre 0.0 y 100.0
        //Tambien guarda las notas en nuevoAlumno.notas y calcule el promedio en nuevoAlumno.promedio
        // Crea una funcion calcularPromedio(), [Nos ayudara,HAAAAAAAAAHAHAHAH]
    }
    cout << "\nCaptura de datos personales finalizada" << endl;

    // Mostrar resumen individual
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

    //Clasificacion Darian
    vector<Alumno> aprobados;
    vector<Alumno> reprobados;

    for (const Alumno& a: alumnos){
        if (a.promedio >= 70.0){
            aprobados.push_back(a);
        } else {
            reprobados.push_back(a);
        }
    }

    mostrarAlumnos(aprobados, "APROBADOS");
    mostrarAlumnos(reprobados, "REPROBADOS");

    return 0;
}
