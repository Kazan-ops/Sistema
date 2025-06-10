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

int main (){
    int cantidadAlumnos = pedirEnteroPositivo ("Cuantos alumnos desea evaluar? ");

    //Aqui vamos a crear un bucle para capturar los datos de cada alumno
    // Darian usted puede ir implementando la estructura Alumno y el Vector dinamico de los Alumnos
    // A su vezpuedes definir la funcion capturaAlumnos() para que nos ordenemos mejor

    cout << "Cantidad de alumnos a evaluar: " << cantidadAlumnos << endl;

    return 0;
}