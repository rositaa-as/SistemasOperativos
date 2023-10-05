#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>
#include "proceso.h"
#include "lote.h"

lote ingresar_datos(vector<lote_c> lista_lote, int cant_oper, int cant_lotes, int contador) {
    cout << "Vamos a llenar tus operaciones" << endl;
    lote nuevo_lote;
    string nombreProceso;
    char t_op;
    int id_pro, tiempoMaximo, numero1, numero2;

    for (int i = 0; i < cant_oper; i++) {
        cout << "LOTE: " << contador << endl;
        cout << "OPERACION: " << i + 1 << endl;

        do {
            cout << "Ingresa un ID no antes ingresado" << endl;
            cin >> t_id;

            if (t_lote.conf_id(t_id, i + 1)) {
                cout << "ID ya ingresado para esta operación. Por favor, ingresa un ID diferente." << endl;
            } else {
                aux++;
            }
        } while (aux < cant_lotes);

        t_oper.set_id(t_id);

        cout << "Ingresa el nombre: " << endl;
        cin >> t_name;
        t_oper.set_nombre(t_name);

        cout << "Ingresa el tiempo: " << endl;
        cin >> t_time;
        t_oper.set_time(t_time);

        do {
            cout << "Ingresa la operación válida (+, -, *, /): " << endl;
            cin >> t_op;
            cout << "Ingresa el número 1: " << endl;
            cin >> t_num1;
            cout << "Ingresa el número 2: " << endl;
            cin >> t_num2;
        } while ((t_op == '/' && t_num2 == 0) || (t_op != '+' && t_op != '-' && t_op != '*' && t_op != '/'));

        t_oper.set_num1(t_num1);
        t_oper.set_num2(t_num2);
        t_oper.set_operacion(t_op);
        t_lote.set_proceso(t_oper, i);

        system("cls");
    }

    return t_lote;
}


double get_resultado(vector<lote_c>lista_lote,int i,int j) {
    double t_resultado=0;
    switch (lista_lote[i].get_proceso(j).get_oper()) {
    case '+':
        t_resultado = lista_lote[i].get_proceso(j).get_num1() + lista_lote[i].get_proceso(j).get_num2();
        break;
    case '-':
        t_resultado = lista_lote[i].get_proceso(j).get_num1() - lista_lote[i].get_proceso(j).get_num2();
        break;
    case '*':
        t_resultado = lista_lote[i].get_proceso(j).get_num1() * lista_lote[i].get_proceso(j).get_num2();
        break;
    case '/':
        t_resultado = lista_lote[i].get_proceso(j).get_num1() / lista_lote[i].get_proceso(j).get_num2();
        break;
    case '%':
        t_resultado = lista_lote[i].get_proceso(j).get_num1() % lista_lote[i].get_proceso(j).get_num2();
        break;

    }
    return t_resultado;
}
void imprimir_lote(vector<lote_c> lista_lote, int total_oper, int cant_lotes) {
    system("cls");
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    COORD coordenadasActuales = csbi.dwCursorPosition;
    SMALL_RECT windowSize = { 0, 0, 100, 100 };
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);
    COORD cursorPos = { 0,0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);

    int segundos = 0;
    short aux = 0;
        for (int i = 0; i < lista_lote.size(); i++) {

            for (int j = 0; j < lista_lote[i].tamanio() ; j++) {//-----------------------------------------------------------
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordenadasActuales);
                cout << "Segundos: " << segundos << endl;
                cout <<endl<< lista_lote[i].get_proceso(j) << endl;
                coordenadasActuales = csbi.dwCursorPosition;

                cursorPos = { 0,0 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                for (int k = 0; k <= lista_lote[i].get_proceso(j).get_tme(); k++) {
                    cout << "Segundos: " << segundos << endl;

                    cursorPos = { 0,0 };
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                    this_thread::sleep_for(chrono::seconds(1));
                    segundos++;

                }
                cursorPos = { 60,aux};
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                if (aux == 0) {
                    cout << "Terminados" << endl; cursorPos = { 60,aux };
                    aux++;
                }

                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout << "Lote: " << i+1<<" Operacion: "<<j+1 << endl;
                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout << "Nombre: " << lista_lote[i].get_proceso(j).get_nombre() << endl;
                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout << "ID: " << lista_lote[i].get_proceso(j).get_id() << endl;
                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout << "TME: " << lista_lote[i].get_proceso(j).get_tme() << endl;
                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout<<"Resultado"<< get_resultado(lista_lote, i, j);
                aux++;
                cursorPos = { 60,aux };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
                cout <<"--------------------------------------";
                aux++;

            }


        }



    cout << "termino" << endl;
    system("pause");
}
using namespace std;
int main() {

    int cant_opera,cant_lotes,aux;
    cout << "Ingresa la cantidad de operaciones deseadas: " << endl;
    cin >> cant_opera;
    if (cant_opera % 5 != 0) {
        cant_lotes = (cant_opera / 5)+1;
    }
    else {
        cant_lotes = cant_opera / 5;
    }
    aux = 5;
    lote_c t_lote;
    vector<lote_c> arreglo;
    system("cls");
    for (int i = 1; i <= cant_lotes; i++) {
        if (cant_opera<(5*i)) {
            aux=cant_opera%5;
        }
        t_lote = ingresar_datos(arreglo, aux,cant_lotes,i);
        arreglo.push_back(t_lote);
    }
    imprimir_lote(arreglo, cant_opera, cant_lotes);

    return 0;
}
/*
    SMALL_RECT windowSize = { 0, 0, 100, 100 };
    SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

    COORD cursorPos = { 0,0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
    int segundos = 0;
    int cont = 11;
    while (segundos != 1) {
        cout << "Segundos: " << segundos << endl;
        COORD cursorPos = { 0,0 };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPos);
        segundos++;
        this_thread::sleep_for(chrono::seconds(1));

    }
*/
