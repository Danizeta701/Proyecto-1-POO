// Progamacion 1 POO.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<stdlib.h>
using namespace std;

class Shape {
public:
    bool filled;
    int axisX, axisY;
    virtual void draw() = 0;

    void setAxisX(int position) {
        if (position < 0) axisX = 0;//No se aceptan numeros negativos
        else axisX = position;
    }

    void setAxisY(int position) {
        if (position < 0) axisY = 0;//No se aceptan numeros negativos
        else axisY = position;
    }
};


class Square : public Shape {
public:
    int size;

    Square(char filled, int size, int axisX, int axisY) {//Constructor
        if (filled == 'y' || filled == 'Y') Square::filled = true;
        else Square::filled = false;
        if (size < 2) Square::size = 2;//El cuadrado debe medir minimo 2
        else Square::size = size;
        Square::setAxisX(axisX);
        Square::setAxisY(axisY);
    }

    void draw() {//Funcion para dibujar el cuadrado
        for (int counter = 0; counter < size + axisY; counter++) {//Barrido de fila en fila
            for (int auxCounter = 0; auxCounter < size + axisX; auxCounter++) {//Barrido de columna en columna
                if (auxCounter < axisX || counter < axisY) cout << "   ";//Se mueve a las coordendas designadas
                else {
                    if (!filled) {//Si se solicito que no estuviera rellenado
                        if (counter == axisY || counter == size + axisY - 1 || auxCounter == axisX || auxCounter == size + axisX - 1) cout << " * ";//Contorno
                        else cout << "   ";//Se llena con espacios vacios
                    }
                    else cout << " * ";
                }
            }
            cout << endl;//Salto de linea
        }
    }
};



void drawShape(Shape*);//Funcion para dibujar el cuadrado

int main() {
    while (true) {
        int shape;//Variable para guardar respuesta del usuario conforme a que figura desea dibujar
        while (true) {
            //Instrucciones para el usuario
            cout << "Favor de escribir que figura desea dibujar\n";
            cout << "[1] Cuadrado\n";
            cout << "[4] Salir\nFigura deseada: ";
            cin >> shape;

            if (shape < 1 || shape > 4) {
                system("cls");//Limpiar pantalla
                cout << "Favor de escribir una opcion valida\n\n";
            }
            else break;//Romper ciclo
        }
        if (shape == 4) break;//Romper ciclo principal

        int size, secondSize, axisX, axisY;//Propiedades de la figura
        char filled;//Saber si la figura debe estar rellenada o no
        //Instrucciones para el usuario
        cout << "Favor de escribir el tamano de la figura (Mininimo 2): ";
        cin >> size;
        cout << "Favor de escribir la coordenada en X donde desea que empiece (Positivos): ";
        cin >> axisX;
        cout << "Favor de escribir la coordenada en Y donde desea que empiece (Positivos): ";
        cin >> axisY;
        do {
            cout << "\nDesea que la figura este rellenada? [y/n]: ";
            cin >> filled;
        } while (filled != 'y' && filled != 'Y' && filled != 'n' && filled != 'N');
        system("cls");//Limpiar pantalla

        switch (shape) {
        case 1: {
            Square square(filled, size, axisX, axisY);//Creamos el cuadrado
            drawShape(&square);//Lo mandamos a dibujar
            break;
        }

        }
        system("cls");//Limpiar pantalla
    }
}

void drawShape(Shape* shape) {//Utilizamos un puntero al objeto secundario que se nos proporcione
    shape->draw();
    while (true) {
        system("cls");//Limpiar pantalla
        shape->draw();
    }
}