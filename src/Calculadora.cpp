//
// Created by jampuero on 03/04/18.
//
#include "Calculadora.h"
Calculadora::Var::Var(Id idVar, int valor) {
    IdVar = idVar;
    Valor = valor;
}

Calculadora::Calculadora(Programa programa): _programa(programa){
    
}


void Calculadora::asignarVariable(Id idVariable, int valor) {
    Var variable = Var(idVariable,valor);
    int existe = 0;
    for(int i =0; i <_Mem.size(); i++) {
        if(_Mem[i].IdVar == idVariable) {
            _Mem[i].Valor = valor;
            existe = 1;
        }
    }
    if(existe == 0){

        _Mem.push_back(variable);
    }
}

void Calculadora::ejecutar(Id idRutina)  {
    if(_programa.esRutinaExistente(idRutina)){
        int i=0;
        int rutinaL =_programa.longitud(idRutina);
        while( i < rutinaL){
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
                    if(_programa.esRutinaExistente(inst.nombre())) {
                        ejecutar(inst.nombre());
                    }else {
                        i= rutinaL;
                    }
                } else{
                    if(_programa.esRutinaExistente(inst.nombre())) {
                        if(pila[pila.size()-1] == 0) {
                            ejecutar(inst.nombre());
                        }
                    }else {
                        i= rutinaL;
                    }

                }


            i++;

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
    if(pila.size() == 0){

        pila.push_back(suma);

    } else if(pila.size() > 1) {
        for (int i = 0; i <2; i++) {
            suma += pila[pila.size()-1];
            pila.pop_back();
        }
        pila.push_back(suma);
    }

}

void Calculadora::FSUB() {
    int resta;
    if(pila.size() == 0){
        resta = 0;
        pila.push_back(resta);

    }else if(pila.size() > 1) {
        resta = pila[pila.size()-2] - pila[pila.size()-1];
        for(int i=0; i<2; i++) {

            pila.pop_back();

        }
        pila.push_back(resta);
    }


}

void Calculadora::FMUL() {
    int mul = 1;
    if(pila.size() == 0){
        mul = 0;
        pila.push_back(mul);

    }
    else if(pila.size() > 1) {
        for (int i = 0; i < 2; i++) {
            mul = mul * pila[pila.size()-1];
            pila.pop_back();
        }
        pila.push_back(mul);
    }

}

void Calculadora::FWRITE(Id idVar) {
    if(_Mem.size() == 0){
        if(pila.size() == 0 ) {

            asignarVariable(idVar,0);

        }else{

            asignarVariable(idVar, pila[pila.size() - 1]);
        }
    }else{
      for(int i =0; i< _Mem.size();i++) {
          if (idVar == _Mem[i].IdVar) {
                if (pila.size() == 0) {
                    asignarVariable(idVar, 0);
                } else {

                    asignarVariable(idVar, pila[pila.size() - 1]);
                    pila.pop_back();

                }
            }
        }

    }



}


void Calculadora::FREAD(Id idVar){

    pila.push_back(valorVariable(idVar));

}

