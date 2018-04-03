#include "Instruccion.h"

Instruccion::Instruccion(Operacion  Op,int valor){
    _Op = Op;
    _Valor = valor;

}

Instruccion::Instruccion(Operacion  Op){
    _Op = Op;

}

Instruccion::Instruccion(Operacion  Op,Id nombre){
    _Op = Op;
    _Id = nombre;

}

Operacion  Instruccion::operacion() const {
    return _Op;

}

int Instruccion::valor() const {
    return _Valor;

}

Id Instruccion::nombre() const {
    return _Id;

}//
// Created by jampuero on 03/04/18.
//

