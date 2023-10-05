#ifndef PROCESO_H
#define PROCESO_H
#include <bits/stdc++.h>

using namespace std;

class proceso {
private:
    string nombre;
    int id;
    char operacion;
    unsigned int time;
    int num1;
    int num2;

public:
    void set_nombre(string t_name) {
        nombre = t_name;
    }
    void set_num1(int t_num) {
        num1 = t_num;
    }
    void set_num2(int t_num) {
        num2 = t_num;
    }
    void set_id(int t_id) {
        id = t_id;
    }
    void set_operacion(char t_oper) {
        operacion = t_oper;
    }
    void set_time(int t_time) {
        time = t_time;
    }
    string get_nombre() {
        return nombre;
    }
    int get_id() {
        return id;
    }
    int get_num1() {
        return num1;
    }
    int get_num2() {
        return num2;
    }
    char get_oper() {
        return operacion;
    }
    int get_time() {
        return time;
    }
    proceso() {
        nombre = " ";
        id = 0;
        operacion = '+';
        time = 0;
    }
    proceso(const string& t_nombre, const int& t_id, const int& t_num1, const int& t_num2, const char& t_oper, const int& t_time) {
        nombre = t_nombre;
        id = t_id;
        operacion = t_oper;
        time = t_time;
        num1 = t_num1;
        num2 = t_num2;
    }
    proceso(string& t_nombre, int& t_id, int& t_num1, int& t_num2, char& t_oper, int& t_time) {
        nombre = t_nombre;
        id = t_id;
        operacion = t_oper;
        time = t_time;
        num1 = t_num1;
        num2 = t_num2;
    }
    proceso(string&& t_nombre, int&& t_id, int&& t_num1, int&& t_num2, char&& t_oper, int&& t_time) {
        nombre = t_nombre;
        id = t_id;
        operacion = t_oper;
        time = t_time;
        num1 = t_num1;
        num2 = t_num2;
    }
    friend std::ostream& operator<<(std::ostream& salida, const proceso& p) {
        salida << "Nombre: " << p.nombre << "\n";
        salida << "ID: " << p.id << "\n";
        salida << "Numero 1: " << p.num1 << "\n";
        salida << "Numero 2: " << p.num2 << "\n";
        salida << "Operacion: " << p.operacion << "\n";
        salida << "TME: " << p.time << "\n";
        return salida;
    }
};



#endif //PROCESO_H

