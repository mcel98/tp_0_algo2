//
// Created by jampuero on 03/04/18.
//

#ifndef SOLUCION_CALCULADORA_H
#define SOLUCION_CALCULADORA_H

#include "Programa.h"
class Calculadora{

public:
    Calculadora(Programa programa);
    int valorVariable(Id idVariable) const;
    void asignarVariable(Id idVariable, int valor);
    void ejecutar(Id idRutina);




private:
    struct Var{
        Id IdVar;
        int Valor;
        Var(Id idVar,int valor):IdVar(idVar), Valor(valor){};
    };




    vector <Var> _Mem;
    vector<int> pila;
    Programa _programa;

    void FPUSH(int valor);
    void FADD();
    void FSUB();
    void FMUL();
    void FWRITE(Id idVar);
    void FREAD(Id idVar);



};

#endif //SOLUCION_CALCULADORA_H
