#ifndef VECALCULATOR_GRAFICADOR_H
#define VECALCULATOR_GRAFICADOR_H
#include <QApplication>
#include "../qt/mainwindow.h"
#include "vectores.h"

// Estas funciones se encargan de iniciar la ventana de Qt y pasar los valores necesarios para crear el plot


void graficar2d(vec final, vec inicial, int argc, char **argv);

//void graficar3d(int x, int y, int x_orig, int y_orig, int argc, char **argv)



#endif //VECALCULATOR_GRAFICADOR_H
