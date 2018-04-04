//
// Created by jampuero on 04/04/18.
//
#include "gtest/gtest.h"
#include "../src/Calculadora.h"
#include "../src/Programa.h"
#include "../src/Instruccion.h"

TEST(Test_Calculadora, Ejecucion_ProgramaConUnaRutina_Operaciones_Aritmeticas){

    //creo un programa
    Programa p;
                        /** instrucciones en rutina a **/
    p.agregarInstruccion("a", Instruccion(PUSH, 10));
    p.agregarInstruccion("a", Instruccion(ADD));
    p.agregarInstruccion("a", Instruccion(MUL));
    p.agregarInstruccion("a", Instruccion(PUSH, 2));
    p.agregarInstruccion("a", Instruccion(MUL));
    p.agregarInstruccion("a", Instruccion(READ,"x"));
    p.agregarInstruccion("a", Instruccion(ADD));
    p.agregarInstruccion("a", Instruccion(WRITE,"x"));



    //creo calculadora con programa p
    Calculadora c = Calculadora(p);
                        /** asigno variables y la guardo en la memoria **/

    c.asignarVariable("x",1);
    c.ejecutar("a");
EXPECT_EQ(c.valorVariable("x"),21);


}



TEST(Test_Calculadora, Ejecucion_ProgramaConUnaRutinaX_Operaciones_Aritmeticas){
    Programa q;

    q.agregarInstruccion("X", Instruccion(READ, "n"));
    q.agregarInstruccion("X", Instruccion(PUSH, 1));
    q.agregarInstruccion("X", Instruccion(SUB));
    //q.agregarInstruccion("X", Instruccion(WRITE, "n"));
    q.agregarInstruccion("X", Instruccion(READ, "n"));
    q.agregarInstruccion("X", Instruccion(WRITE, "n"));
    q.agregarInstruccion("X", Instruccion(JUMPZ, "END"));
    q.agregarInstruccion("X", Instruccion(JUMP, "Y"));

    Calculadora c = Calculadora(q);

    c.asignarVariable("n", 2);
    c.ejecutar("X");
    EXPECT_EQ(c.valorVariable("x"),2);


}