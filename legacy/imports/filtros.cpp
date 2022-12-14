#include "filtros.h"

/* De momento este filtro solo sirve para la funcion de vector unitario pero planeamos reutilizarla.
    Separa las dimensiones y aplica i,j y z a los std::cout */
void filtro_dim_gen(int &dimension, vec result_vec){
    if (dimension == 1) {
        std::cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ")" << std::endl;
    } else if (dimension == 2) {
        std::cout << "El resultado es: " << "(" << result_vec.eje_x << "," << result_vec.eje_y << ","
                  << result_vec.eje_z << ")" << std::endl;
    } else {
        std::cout << "Ha ocurrido un error con las dimensiones" << std::endl;
    }
}
// Filtro para separar 2D y 3D en el std::cout generico (x,y,z)
void filtro_dim_componente(int &dimension, vec result_vec){
    if (dimension == 1) {
        std::cout << "El resultado es: " << "(" << result_vec.eje_x << " i " << "+ " << result_vec.eje_y << " j " << ")" << std::endl;
    } else if (dimension == 2) {
        std::cout << "El resultado es: " << "(" << result_vec.eje_x << " i "<< "+ " << result_vec.eje_y << " j " << "+ "
                  << result_vec.eje_z << " k " << ")" << std::endl;
    } else {
        std::cout << "Ha ocurrido un error con las dimensiones" << std::endl;
    }
}
// Filtros de los input para poder distinguir entre vector 2D, 3D y escalar
void filtro_input(int &operacion, int &dimension, vec &vector1, vec &vector2, float &escalar) {
    vector1=INVALID;
    vector2=INVALID;
    escalar=INVALID_ESC;
    if (operacion != 3 && operacion != 7 && operacion != 9 && operacion != 8) {
        if (dimension == 1) {
            while(vector1.eje_x==INVALID.eje_x||vector1.eje_y==INVALID.eje_y){
                std::cout << "Ingrese el vector 1 en formato x y" << std::endl;
                std::cin >> vector1.eje_x >> vector1.eje_y;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                vector1.eje_z = 0;
            }
            while(vector2.eje_x==INVALID.eje_x||vector2.eje_y==INVALID.eje_y) {
                std::cout << "Ingrese el vector 2 en formato x y" << std::endl;
                std::cin >> vector2.eje_x >> vector2.eje_y;
                vector2.eje_z = 0;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }

        } else if (dimension == 2) {
            if (operacion != 4){
                while(vector1.eje_x==INVALID.eje_x||vector1.eje_y==INVALID.eje_y||vector1.eje_z==INVALID.eje_z) {
                    std::cout << "Ingrese el vector 1 en formato x y z" << std::endl;
                    std::cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
                while(vector2.eje_x==INVALID.eje_x||vector2.eje_y==INVALID.eje_y||vector2.eje_z==INVALID.eje_z) {
                    std::cout << "Ingrese el vector 2 en formato x y z" << std::endl;
                    std::cin >> vector2.eje_x >> vector2.eje_y >> vector2.eje_z;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                }
            }
        }

    } else if (operacion == 3 || operacion == 7 || operacion == 8) {
        if (dimension == 1) {
            while(vector1.eje_x==INVALID.eje_x||vector1.eje_y==INVALID.eje_y) {
                std::cout << "Ingrese el vector en formato x y" << std::endl;
                std::cin >> vector1.eje_x >> vector1.eje_y;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                vector1.eje_z = 0;
            }
        } else if (dimension == 2) {
            while (vector1.eje_x == INVALID.eje_x || vector1.eje_y == INVALID.eje_y || vector1.eje_z == INVALID.eje_z) {
                std::cout << "Ingrese el vector en formato x y z" << std::endl;
                std::cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
    } else if (operacion == 9) {
        if (dimension == 1) {
            while (vector1.eje_x == INVALID.eje_x || vector1.eje_y == INVALID.eje_y) {
                std::cout << "Ingrese el vector en formato x y" << std::endl;
                std::cin >> vector1.eje_x >> vector1.eje_y;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                vector1.eje_z = 0;
            }
            while (escalar == INVALID_ESC){
                std::cout << "Ingrese el escalar" << std::endl;
                std::cin >> escalar;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
        }
        } else if (dimension == 2) {
            while (vector1.eje_x == INVALID.eje_x || vector1.eje_y == INVALID.eje_y || vector1.eje_z == INVALID.eje_z) {
                std::cout << "Ingrese el vector en formato x y z" << std::endl;
                std::cin >> vector1.eje_x >> vector1.eje_y >> vector1.eje_z;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
            while(escalar==INVALID_ESC) {
                std::cout << "Ingrese el escalar" << std::endl;
                std::cin >> escalar;
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        }
    }
}