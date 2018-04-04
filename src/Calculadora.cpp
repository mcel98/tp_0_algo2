//
// Created by jampuero on 03/04/18.
//
#include "Calculadora.h"
Calculadora::Var::Var(Id idVar, int valor) {
    IdVar = idVar;
    Valor = valor;
}

Calculadora::Calculadora(Programa programa){
    _programa = programa;

}


void Calculadora::asignarVariable(Id idVariable, int valor) {
    Var variable = Var(idVariable,valor);
    _Mem.push_back(variable);
}

void Calculadora::ejecutar(Id idRutina)  {
    if(_programa.esRutinaExistente(idRutina)){
        for(int i = 0; i < _programa.longitud(idRutina); i++){
            Instruccion inst = _programa.instruccion(idRutina,i);
                if(inst.operacion() == ADD){
                    FADD();

                } else if(inst.operacion() == SUB){
                    FSUB();

                }else if (inst.operacion() == MUL){
                    FMUL();

                }else if(inst.operacion() == PUSH){
                    FPUSH(inst.valor());

                }else if (inst.operacion() == WRITE){
                    FWRITE(inst.nombre());

                }else if (inst.operacion() == READ){
                    FREAD(inst.nombre());

                }else if(inst.operacion() == JUMP){
                    FJUMP(inst.nombre());

                } else{
                    FJUMPZ(inst.nombre());

                }




        }

    }



}


int Calculadora::valorVariable(Id idVariable) const{
    int valorVar = 0;
    int i=0;
    while(i < _Mem.size()){
        if(_Mem[i].IdVar == idVariable){
            valorVar = _Mem[i].Valor;
        }
        i++;
    }
    return valorVar;
}

void Calculadora::FPUSH(int valor) {
    pila.push_back(valor);

}

void Calculadora::FADD() {
    int suma = 0;
    if(pila.size() > 1) {
        for (int i = 0; i >= 1; i++) {
            suma += pila[pila.size()-1];
            pila.pop_back();
        }
        pila.push_back(suma);
    }else if(pila.size() == 0){
        suma = 0;
        pila.push_back(suma);

    }

}

void Calculadora::FSUB() {
    int resta;
    if(pila.size() > 1) {
        resta = pila[pila.size()-2] - pila[pila.size()-1];
        for(int i=0; i<2; i++) {

            pila.pop_back();

        }
        pila.push_back(resta);
    }else if(pila.size() == 0){
        resta = 0;
        pila.push_back(resta);

    }


}

void Calculadora::FMUL() {
    int mul = 1;
    if(pila.size() > 1) {
        for (int i = 0; i >= 1; i++) {
            mul *= pila[pila.size()-1];
            pila.pop_back();
        }
        pila.push_back(mul);
    }else if(pila.size() == 0){
        mul = 0;
        pila.push_back(mul);

    }

}

void Calculadora::FWRITE(Id idVar) {
    for(int i =0; i< _Mem.size();i++){
        if(idVar == _Mem[i].IdVar){
            asignarVariable(idVar, pila[pila.size()-1]);
            pila.pop_back();
        }


    }



}


void Calculadora::FREAD(Id idVar){

    pila.push_back(valorVariable(idVar));

}

void Calculadora::FJUMP(Id idRutina) {
ejecutar(idRutina);
}

void Calculadora::FJUMPZ(Id idRutina) {
    if(pila.size() == 0 || pila[pila.size()-1] == 0 ){

        ejecutar(idRutina);
    }


}