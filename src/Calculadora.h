//
// Created by jampuero on 03/04/18.
//

#ifndef SOLUCION_CALCULADORA_H
#define SOLUCION_CALCULADORA_H

#include "Programa.h"
class Calculadora{

public:
    Calculadora(Programa programa);


private:
    struct Var{
        Id IdVar;
        int Valor;
        Var(Id idVar,int valor);

    };
    struct Memoria{
        void asignarVariable(Id idVariable, int valor);
        Memoria();
        vector <Var> _Mem;

    };
    vector<int> pila;
    Programa _programa;





};

#endif //SOLUCION_CALCULADORA_H
