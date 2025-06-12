#include <iostream>
#include <vector>
#include <limits> //Si preguntas esto lo que hace es limpiar el buffer

using namespace std;

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

struct Alumno {
    string nombre, apellido1, apellido2;
    int ciclo, cedula;
    vector <float> notas;
    float promedio;
};
// Estos espara capturar los datos y el de arriba usted sabe para que es

Alumno capturaAlumno(int numero){
    Alumno a;
    cout << "\n==============================" << endl;
    cout << "  Ingreso de datos - Alumno #" << numero << endl;
    cout << "==============================" << endl;

    cout << "Ingrese primer nombre";
    cin.ignore();
    getline(cin, a.nombre);

    cout << "Ingrese primer apellido: ";
    getline(cin, a.apellido1);

    cout << "Ingrese segundo apellido: ";
    getline(cin, a.apellido2);

    a.ciclo=pedirEnteroPositivo("Ingrese ciclo de estudio: ");
    a.cedula=pedirEnteroPositivo("Ingrese numero de cedula");

    return a;
}

int main (){
    int cantidadAlumnos = pedirEnteroPositivo ("Cuantos alumnos desea evaluar? ");

    //Aqui vamos a crear un bucle para capturar los datos de cada alumno
    // Darian usted puede ir implementando la estructura Alumno y el Vector dinamico de los Alumnos
    // A su vezpuedes definir la funcion capturaAlumnos() para que nos ordenemos mejor

    vector<Alumno> alumnos;

    for(int i=0; i< cantidadAlumnos; i++){
        Alumno nuevoAlumno =capturaAlumno(i + 1);
        alumnos.push_back(nuevoAlumno);

        //Te encvargo capturar las 5 notas del alumno y calcular el promedio de estas
        //Use Validacionees para cada nota: entre 0.0 y 100.0
        //Tambien guarda las notas en nuevoAlumno.notas y calcule el promedio en nuevoAlumno.promedio
        // Crea una funcion calcularPromedio(), [Nos ayudara,HAAAAAAAAAHAHAHAH]
    }
    cout << "\nCaptura de datos personales finalizada" << endl;

    return 0;
}