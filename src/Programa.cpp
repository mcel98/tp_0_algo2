//
// Created by jampuero on 03/04/18.
//
#include "Programa.h"
Programa::Rutina::Rutina(Id nombre, vector<Instruccion> Rutina){
    IdRutina = nombre;
    _Rutina = Rutina;
    }
Programa::Programa(){
    vector<Rutina> programa;
    _Prog = programa;

}

void Programa::agregarInstruccion(Id idRutina, Instruccion instruccion){
    bool existe = false;
    for(int i =0; i< _Prog.size(); i++) {

        if (_Prog[i].IdRutina == idRutina) {
              _Prog[i]._Rutina.push_back(instruccion);
                existe = true;
          }

      }
    if(!existe){
        vector<Instruccion > RVacio;
        RVacio.push_back(instruccion);
        Rutina NuevaRutina = Rutina(idRutina, RVacio);
        _Prog.push_back(NuevaRutina);
    }

}

bool Programa::esRutinaExistente(Id idRutina) const {
    bool res = false;
    for(int i = 0; i<_Prog.size(); i++){
        if(idRutina == _Prog[i].IdRutina){
            res = true;
        }
    }

return res;
}

int Programa::longitud(Id idRutina) const {
    int length = 0;
    if(esRutinaExistente(idRutina)){

        for(int i =0; i <_Prog.size(); i++ ){
            if(_Prog[i].IdRutina == idRutina){
               length = idRutina.size();

            }

        }

    }

return length;
}


Instruccion Programa::instruccion(Id idRutina, int i) const {

    for(int j = 0; j<_Prog.size();j++){
        if(_Prog[j].IdRutina == idRutina){
            if(i < _Prog[j]._Rutina.size()) {
                return _Prog[j]._Rutina[i];
            }
        }

    }


}