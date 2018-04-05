//
// Created by jampuero on 04/04/18.
//
#include "gtest/gtest.h"
#include "../src/Calculadora.h"
#include "../src/Programa.h"
#include "../src/Instruccion.h"


//////TEST PARA ADD////
TEST(test_calculadora, pila_vacia){
    Programa a;

    a.agregarInstruccion("A", Instruccion(ADD));
    a.agregarInstruccion("A", Instruccion(WRITE, "x"));

    Calculadora c = Calculadora(a);
    c.ejecutar("A");
    EXPECT_EQ(c.valorVariable("x"),0);
}


TEST(test_calculadora, pila_con_un_elemento){

    Programa b;
    b.agregarInstruccion("B", Instruccion(READ, "n"));
    b.agregarInstruccion("B", Instruccion(ADD));
    b.agregarInstruccion("B", Instruccion(WRITE, "n"));

    Calculadora k = Calculadora(b);

    k.asignarVariable("n",1);
    k.ejecutar("B");
    EXPECT_EQ(k.valorVariable("n"),1);

}

////TEST PARA PUSH////
TEST(test_calculadora, push){
    Programa l;

    l.agregarInstruccion("L", Instruccion(PUSH, 42));
    l.agregarInstruccion("L", Instruccion(WRITE, "y"));

    Calculadora c1 = Calculadora(l);

    c1.ejecutar("L");
    EXPECT_EQ(c1.valorVariable("y"),42);
}

/////TEST PARA SUB/////
TEST(test_calculadora, pila_vacia_sub){
    Programa m;

    m.agregarInstruccion("M", Instruccion(SUB));
    m.agregarInstruccion("M", Instruccion(WRITE, "z"));

    Calculadora c2 = Calculadora(m);
    c2.ejecutar("M");
    EXPECT_EQ(c2.valorVariable("z"),0);
}

/////TEST PARA MUL//////
TEST(test_calculadora, pila_vacia_mul){
    Programa q;

    q.agregarInstruccion("Q", Instruccion(MUL));
    q.agregarInstruccion("Q", Instruccion(WRITE, "x1"));

    Calculadora c3 = Calculadora(q);
    c3.ejecutar("Q");
    EXPECT_EQ(c3.valorVariable("x1"),0);
}

//////TEST PARA WRITE //////
TEST(test_calculadora, write){
    Programa w;

    w.agregarInstruccion("W", Instruccion(PUSH, 21));
    w.agregarInstruccion("W", Instruccion(WRITE, "x2"));

    Calculadora c4 = Calculadora(w);
    c4.ejecutar("W");
    EXPECT_EQ(c4.valorVariable("x2"), 21);
}

TEST(test_calculadora, write_vacio){
    Programa w1;

    w1.agregarInstruccion("W1", Instruccion(WRITE, "x3"));

    Calculadora c5 = Calculadora(w1);
    c5.ejecutar("W");
    EXPECT_EQ(c5.valorVariable("x3"), 0);
}


//////TEST PARA READ////////

TEST(test_calculadora, read_vacio){
    Programa r;

    r.agregarInstruccion("R", Instruccion(READ, "x4"));

    Calculadora c5 = Calculadora(r);
    c5.ejecutar("R");
    EXPECT_EQ(c5.valorVariable("x4"), 0);
}






TEST(test_calculadora, ejecucion_programaConUnaRutina_operaciones_aritmeticas){

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

//////TEST PARA EJECUTAR//////

TEST(test_calculadora, ejecutar_programaConUnaRutinaX_operaciones_aritmeticas){
    Programa q;

    q.agregarInstruccion("X", Instruccion(READ, "n"));
    q.agregarInstruccion("X", Instruccion(PUSH, 1));
    q.agregarInstruccion("X", Instruccion(SUB));

    q.agregarInstruccion("X", Instruccion(READ, "n"));
    q.agregarInstruccion("X", Instruccion(WRITE, "n"));
    q.agregarInstruccion("X", Instruccion(JUMPZ, "END"));
    q.agregarInstruccion("X", Instruccion(JUMP, "Y"));

    Calculadora c = Calculadora(q);

    c.asignarVariable("n", 2);
    c.ejecutar("X");
    EXPECT_EQ(c.valorVariable("n"),2);

}

///////TEST PARA JUMP JUMPZ/////

TEST(test_calculadora, ejecucion_dosProgramasConRutina_pruebo_jump_jumpz){
    Programa r;

    r.agregarInstruccion("Y", Instruccion(WRITE, "n"));  //agrego a la memoria el n=0
    r.agregarInstruccion("Y", Instruccion(PUSH, 4));    //pusheo 4
    r.agregarInstruccion("Y", Instruccion(PUSH, 2));     //pusheo 2, --> <4,2>
    r.agregarInstruccion("Y", Instruccion(MUL));
    r.agregarInstruccion("Y", Instruccion(PUSH, 8));     //<8,8>
    r.agregarInstruccion("Y", Instruccion(SUB));         // <0>
    r.agregarInstruccion("Y", Instruccion(JUMPZ, "Z"));  // se activa el JUMPZ pq el tope es 0. Leo rutina"Z"



    r.agregarInstruccion("Z", Instruccion(WRITE, "m")); //agrego m=0
    r.agregarInstruccion("Z", Instruccion(PUSH, 9)); //<0,9>
    r.agregarInstruccion("Z", Instruccion(ADD)); //<9>
    r.agregarInstruccion("Z", Instruccion(WRITE, "n")); //n =9
    r.agregarInstruccion("Z", Instruccion(JUMP, "A"));  //vuelvo a ejecutar "Y", solo la primer linea

    Calculadora c = Calculadora(r);


    c.ejecutar("Y");
    EXPECT_EQ(c.valorVariable("n"),9);

}

/////TEST ASIGNAR VARIABLE///////
TEST (test_calculadora, asignar_variable){
    Programa e;

    Calculadora d = Calculadora(e);

    d.asignarVariable("n",35);
    EXPECT_EQ(d.valorVariable("n"),35);
}

/////TEST VALOR VARIABLE//////
TEST(test_calculadora, valor_variable_porDefecto){
    Programa f;

    Calculadora e = Calculadora(f);

    EXPECT_EQ(e.valorVariable("n"), 0);
}

