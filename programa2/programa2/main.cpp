//Rosa Maria Guadalupe Avila Sandoval
//218419793
#include <bits/stdc++.h>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>

using namespace std;

void cambiarColorPantalla() {
    system("color 1F"); // Azul de fondo y fuente blanca
}
//-------------------------------------------------------------------------------------------------
class Proceso {
private:
    int id;
    char operacion;
    int tme;
    bool terminado;
    int t_transcurrido;
    int num1;
    int num2;
    int t_restante;
    int resultado;

public:
    Proceso() {
        id = 0;
        operacion = ' ';
        tme = 0;
        terminado = false;
        t_transcurrido = 0;
        num1 = 0;
        num2 = 0;
        t_restante = 0;
        resultado = 0;
    }

    Proceso(int _id, char _operacion, int _tme, int _num1, int _num2)
        : id(_id), operacion(_operacion), tme(_tme), terminado(false), t_transcurrido(0), num1(_num1), num2(_num2) {
        t_restante = tme;
    }

    int getId() const { return id; }
    char getOperacion() const { return operacion; }
    int getTME() const { return tme; }
    bool estaTerminado() const { return terminado; }
    int getTranscurrido() const { return t_transcurrido; }
    int getNum1() const { return num1; }
    int getNum2() const { return num2; }
    int getRestante() const { return t_restante; }
    int getResultado() const { return resultado; }

    void aumentarTranscurrido() {
        t_transcurrido++;
        t_restante--;

    }

    void marcarTerminado() {
        terminado = true;
    }

    void marcarComoError() {
        terminado = false;
    }

};

class Lote {
private:
    vector<Proceso> procesos;
    int idLote;
    int totalTME;

public:
    Lote(int _idLote) : idLote(_idLote), totalTME(0) {}

    void agregarProceso(const Proceso& proceso) {
        procesos.push_back(proceso);
        totalTME += proceso.getTME();
    }

    void eliminarProceso() {
        procesos.erase(procesos.begin());
    }

    Proceso& obtenerProcesoEnEjecucion() {
        return procesos.front();
    }

    bool estaVacio() const {
        return procesos.empty();
    }

    int obtenerTotalTME() const {
        return totalTME;
    }

    int obtenerIdLote() const {
        return idLote;
    }

    int obtenerCantidadProcesos() const {
        return procesos.size();
    }

    const vector<Proceso>& obtenerProcesos() const {
        return procesos;
    }
};
//--------------------------------------------------------------------------------------

void imprimir(int x, int y, const string& texto) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    cout << texto;
}

void imprimirProcesoEnEjecucion(const Proceso& proceso, int tiempoRealTranscurrido) {
    imprimir(0, 0, "Proceso en Ejecucion:");
    imprimir(0, 1, "ID: " + to_string(proceso.getId()));
    imprimir(0, 2, "Operacion: " + string(1, proceso.getOperacion()));

    // Imprimir TME con formato específico
    string tmeString;
    if (proceso.getTME() < 10) {
        tmeString = "TME: " + to_string(proceso.getTME()) + " ";
    } else {
        tmeString = "TME: " + to_string(proceso.getTME());
    }
    imprimir(0, 3, tmeString);

    // Imprimir Tiempo Transcurrido con formato específico
    string tiempoTranscurridoString;
    if (tiempoRealTranscurrido < 10) {
        tiempoTranscurridoString = "Tiempo Transcurrido: " + to_string(tiempoRealTranscurrido) + " ";
    } else {
        tiempoTranscurridoString = "Tiempo Transcurrido: " + to_string(tiempoRealTranscurrido);
    }
    imprimir(0, 4, tiempoTranscurridoString);

    // Imprimir Tiempo Restante con formato específico
    string tiempoRestanteString;
    if (proceso.getRestante() < 10) {
        tiempoRestanteString = "Tiempo Restante: " + to_string(proceso.getRestante()) + " ";
    } else {
        tiempoRestanteString = "Tiempo Restante: " + to_string(proceso.getRestante());
    }
    imprimir(0, 5, tiempoRestanteString);

    imprimir(0, 6, "Numero 1: " + to_string(proceso.getNum1()));
    imprimir(0, 7, "Numero 2: " + to_string(proceso.getNum2()));
}


void imprimirProcesosEnEspera(const Lote& lote) {
    imprimir(0, 10, "Procesos en Espera del Lote " + to_string(lote.obtenerIdLote()) + ":");
    int y = 11;
    for (const Proceso& proceso : lote.obtenerProcesos()) {
        // Imprimir Tiempo Transcurrido con formato específico
        string tiempoTranscurridoString;
        if (proceso.getTranscurrido() < 10) {
            tiempoTranscurridoString = "Transcurrido: " + to_string(proceso.getTranscurrido()) + " ";
        } else {
            tiempoTranscurridoString = "Transcurrido: " + to_string(proceso.getTranscurrido());
        }

        imprimir(0, y, "ID: " + to_string(proceso.getId()) + "  TME: " + to_string(proceso.getTME()) +
            "  " + tiempoTranscurridoString);
        y++;
    }
}

void imprimirLotesPendientes(const vector<Lote>& lotes, int loteActual) {
    int lotesPendientes = lotes.size() - loteActual-1;
    if (lotesPendientes < 0) {
        lotesPendientes = 0; // Evitar valores negativos
    }
    imprimir(0, 20, "Lotes Pendientes: " + to_string(lotesPendientes));
}

void imprimirTrabajosTerminados(const vector<Proceso>& terminados) {
    imprimir(40, 0, "Trabajos Terminados:");
    int y = 1;
    for (const Proceso& proceso : terminados) {
        int resultado = 0;
        if (proceso.estaTerminado() && proceso.getOperacion() != 'E') {
            // Realizar la operación y almacenar el resultado en la variable 'resultado'
            char operacion = proceso.getOperacion();
            int num1 = proceso.getNum1();
            int num2 = proceso.getNum2();

            switch (operacion) {
                case '+':
                    resultado = num1 + num2;
                    break;
                case '-':
                    resultado = num1 - num2;
                    break;
                case '*':
                    resultado = num1 * num2;
                    break;
                case '/':
                    if (num2 != 0) {
                        resultado = num1 / num2;
                    } else {
                        resultado = 0; // Evitar división por cero
                    }
                    break;
                case '%':
                    if (num2 != 0) {
                        resultado = num1 % num2;
                    } else {
                        resultado = 0; // Evitar módulo por cero
                    }
                    break;
                default:
                    resultado = 0; // Operación no válida
                    break;
            }

            // Mostrar el resultado
            string resultadoString = to_string(num1) + proceso.getOperacion() +
                to_string(num2) + " = " + to_string(resultado);

            imprimir(40, y, "ID: " + to_string(proceso.getId()) + "  Operacion: " + proceso.getOperacion() +
                "  Resultado: " + resultadoString);
        } else {
            imprimir(40, y, "ID: " + to_string(proceso.getId()) + "  Operacion: " + proceso.getOperacion() +
                "  Resultado: ERROR");
        }
        y++;
    }
}


void actualizarReloj(int segundos) {
    imprimir(0, 25, "Contador General: " + to_string(segundos));
}

bool estaListoParaTerminar(const Proceso& proceso) {
    return proceso.getRestante() == 0 && proceso.estaTerminado() && proceso.getOperacion() != 'E';
}
void manejarTeclas(vector<Lote>& lotes, int& loteActual, vector<Proceso>& terminados, bool& pausado, int& segundos) {
    if (_kbhit()) {
        char tecla = _getch();
        if (tecla == 'i' || tecla == 'I') {
            // Interrupción por entrada/salida
                Proceso& procesoEnEjecucion = lotes[loteActual].obtenerProcesoEnEjecucion();
                lotes[loteActual].agregarProceso(procesoEnEjecucion);
                lotes[loteActual].eliminarProceso();
                imprimirProcesoEnEjecucion(lotes[loteActual].obtenerProcesoEnEjecucion(),segundos);


        } else if (tecla == 'e' || tecla == 'E') {
            // Error
            if (!lotes[loteActual].estaVacio()) {
                Proceso& procesoEnEjecucion = lotes[loteActual].obtenerProcesoEnEjecucion();
                if (!procesoEnEjecucion.estaTerminado()) {
                    procesoEnEjecucion.marcarComoError();
                    terminados.push_back(procesoEnEjecucion);
                    lotes[loteActual].eliminarProceso();
                }
            }
        } else if (tecla == 'p' || tecla == 'P') { // Pausar o Continuar

            do {
                if (_kbhit()) {
                    tecla = _getch();
                    if (tecla == 'c' || tecla == 'C') {
                        break;
                }
            }
            segundos++;
            actualizarReloj(segundos);
            Sleep(1000);

        }while(true);

    } else if (tecla == 'c' || tecla == 'C');
}
}

int main() {
    int numTrabajos = 0;
    cout << "Ingrese el numero de trabajos iniciales: ";
    cin >> numTrabajos;
    system("cls");

    vector<Lote> lotes;
    int idProceso = 1;
    vector<Proceso> terminados;

    while (numTrabajos > 0) {
        Lote lote(lotes.size()+1);
        int trabajosEnLote = min(5, numTrabajos);  // Genera hasta 5 trabajos o los que queden
        for (int i = 0; i < trabajosEnLote; i++) {
            int tme = rand() % 13 + 6;  // TME entre 6 y 18
            char operaciones[] = {'+', '-', '*', '/', '%'};
            char operacion = operaciones[rand() % 5];
            int num1 = rand() % 100;
            int num2 = rand() % 100;

            Proceso proceso(idProceso, operacion, tme, num1, num2);
            lote.agregarProceso(proceso);
            idProceso++;
        }
        lotes.push_back(lote);
        numTrabajos -= trabajosEnLote;
    }

    cambiarColorPantalla();
    int loteActual = 0;
    int segundos = 0;
    bool pausado = false;
    bool hayLotesPendientes = !lotes.empty();

    imprimirLotesPendientes(lotes, loteActual);

    while (!lotes.empty()) {
        if (lotes[loteActual].estaVacio()) {
            lotes.erase(lotes.begin() + loteActual);
            loteActual = 0; // Volver al primer lote
            hayLotesPendientes = !lotes.empty(); // Actualizar el estado de lotes pendientes
        }

        Proceso& procesoEnEjecucion = lotes[loteActual].obtenerProcesoEnEjecucion();
        if(procesoEnEjecucion.getRestante()==0){
            procesoEnEjecucion.marcarTerminado();
        }

        // Verifica si el proceso está listo para ser marcado como terminado
        if (estaListoParaTerminar(procesoEnEjecucion)) {
            terminados.push_back(procesoEnEjecucion);
            lotes[loteActual].eliminarProceso();
        }

        imprimirProcesoEnEjecucion(procesoEnEjecucion, segundos);
        imprimirProcesosEnEspera(lotes[loteActual]);

        if (!pausado) {
            Sleep(1000); // Dormir 1 segundo (simula el paso del tiempo)
            segundos++;
        }

        if (!procesoEnEjecucion.estaTerminado() && !pausado) {
            procesoEnEjecucion.aumentarTranscurrido();
        }

        manejarTeclas(lotes, loteActual, terminados, pausado, segundos);

        if (lotes[loteActual].estaVacio()) {
            lotes.erase(lotes.begin() + loteActual);
            loteActual = 0; // Volver al primer lote
            imprimirLotesPendientes(lotes, loteActual);
        }

        actualizarReloj(segundos);
        imprimirTrabajosTerminados(terminados);
    }

    imprimir(0, 30, "Simulacion Terminada. Presione una tecla para salir.");
    _getch();
    return 0;
}
