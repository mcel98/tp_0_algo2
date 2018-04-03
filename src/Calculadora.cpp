//
// Created by jampuero on 03/04/18.
//
#include "Calculadora.h"
Calculadora::Var::Var(Id idVar, int valor) {
    IdVar = idVar;
    Valor = valor;
}
Calculadora::Memoria::Memoria() {
    vector<Var> Mem;
    _Mem = Mem;

}
Calculadora::Calculadora(Programa programa){
    _programa = programa;

}


void Calculadora::Memoria::asignarVariable(Id idVariable, int valor) {
    Var variable = Var(idVariable,valor);
    _Mem.push_back(variable);
}

