#include <bits/stdc++.h>
#ifndef LOTE_H
#define LOTE_H
#include "proceso.h"

using namespace std;

class lote{
private:
    vector <proceso> lote;
    int id_lote;
    vector<int>ids;
public:
    void set_proceso(proceso t_proceso, int ps) {
        //t_proceso.set_id(ps + 1);
        lote.push_back(t_proceso);
        for (int i = 0; i < ids.size(); i++) {
            ids.push_back(lote[i].get_id());
        }

    }
    proceso get_proceso(int ps) {
        return lote[ps];
    }
    int get_id() {
        return id_lote;
    }
    lote_c() {
        id_lote=-1;


    }
    bool conf_id(int t_id, int lotes) {//esta verificando en el mismo lote no en la lista
        /*        for (int i = 0; i < lotes; i++) {
            if (lote.empty()) {
                return false;
            }
            else if (lote[i].get_id() == t_id) {
                return true;
            }

        }
        return false;
        */
        for (int i = 0; i < ids.size(); i++) {
            if (ids[i] == t_id) {
                return true;
            }

        }
        return false;
    }
    bool vacio() {
        return lote.empty();
    }
    int tamanio() {
        int tamanio = lote.size();
        return tamanio;
    }
};
#endif //LOTE_H
