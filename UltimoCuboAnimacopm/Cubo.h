//javierAlvarezReyes
//Pablo cesar Yucra
#include <string>
#include <vector>
#include "matricesEscalaRotacionTraslacion.h"
#include <map>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;



class Cubo
{
    public:

        std::map<int, std::pair<float*, unsigned int*>> Cubos;
        std::vector<std::vector<float>> igualarResultado;
        //crear un vector llamado cola de animacion
        vector<int>ColaDeAnimacion;

        //prueba Condicion
            int condicion = 0;
        //funcion que reciba un int y sume a condicion
            void sumarCondicion(int condicionsuma)
            {
                condicion = condicion + condicionsuma;
                cout << "condicion: " << condicion << endl;
            }
    //______________traslacionPlano___________
        //plano1
        int Plano3[3][3] = {
                {8,7,6},
                {5,4,3},
                {2,1,0}
        };
        //plano1
        int Plano2[3][3] = {
            {17,16,15},
            {14,13,12},
            {11,10,9}
        };
        //plano1
        int Plano1[3][3] = {
            {26,25,24},
            {23,22,21},
            {20,19,18}
        };

        //______________traslacionPISO___________
        //piso1
        int Piso1[3][3] = {
            {2,1,0},
            {11,10,9},
            {20,19,18}
        };
        //piso2
        int Piso2[3][3] = {
            {5,4,3},
            {14,13,12},
            {23,22,21}
        };
        //piso3
        int Piso3[3][3] = {
            {8,7,6},
            {17,16,15},
            {26,25,24}
        };
        //____________TransportarLados__________
        int Lado1[3][3] = {
            {8,17,26},
            {5,14,23},
            {2,11,20}
        };
        //piso2
        int Lado2[3][3] = {
            {7,16,25},
            {4,13,22},
            {1,10,19}
        };
        //piso3
        int Lado3[3][3] = {
            {6,15,24},
            {3,12,21},
            {0,9,18}
        };
        //aser 6 funciones que me devuelvan las matrices de los planos y pisos
        //_____________________________________________________________
        std::vector<int> obtenerColaDeAnimacion() 
        {
            return ColaDeAnimacion;
        }
        void agregarElemento( int elemento) 
        {
            ColaDeAnimacion.push_back(elemento);
        }
        void imprimirVector(const std::vector<int>& miVector) {
            for (const auto& elemento : miVector) {
                std::cout << elemento << " ";
            }
            std::cout << std::endl;
        }
        void setPlano1(int plano[3][3]) {
            // Copiar los valores del plano pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    plano[i][j]  = Plano1[i][j];
                }
            }
        }

        // Método para establecer los valores del plano 2
        void setPlano2(int plano[3][3]) {
            // Copiar los valores del plano pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                     plano[i][j] = Plano2[i][j];
                }
            }
        }

        // Método para establecer los valores del plano 3
        void setPlano3(int plano[3][3]) {
            // Copiar los valores del plano pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    plano[i][j] = Plano3[i][j];
                }
            }
        }

        // Método para establecer los valores del piso 1
        void setPiso1(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Piso1[i][j];
                }
            }
        }

        // Método para establecer los valores del piso 2
        void setPiso2(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Piso2[i][j];
                }
            }
        }

        // Método para establecer los valores del piso 3
        void setPiso3(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Piso3[i][j];
                }
            }
        } 

        void setLadoA(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Lado1[i][j];
                }
            }
        } 

        void setLadoB(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Lado2[i][j];
                }
            }
        } 

        void setLadoC(int piso[3][3]) {
            // Copiar los valores del piso pasado como parámetro a la matriz correspondiente en la clase Cubo
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    piso[i][j] = Lado3[i][j];
                }
            }
        } 


        //_____________________________________________________________
        //____________________________________certices Temp
        float* TempVertices= new float[24] {-0.107f,-0.313f,-0.311f,-0.107f,-0.113f,-0.311f,-0.307f,-0.113f,-0.311f,-0.307f,-0.313f,-0.311f,-0.107f,-0.313f,-0.11f,-0.107f,-0.113f,-0.11f,-0.307f,-0.313f,-0.11f,-0.307f,-0.113f,-0.11f};
        float* TempVertices2= new float[24] {0.103f,-0.313f,-0.311f,0.103f,-0.113f,-0.311f,-0.097f,-0.113f,-0.311f,-0.097f,-0.313f,-0.311f,0.103f,-0.313f,-0.11f,0.103f,-0.113f,-0.11f,-0.097f,-0.313f,-0.11f,-0.097f,-0.113f,-0.11f};
        float* TempVertices3= new float[24] {0.313f,-0.313f,-0.311f,0.313f,-0.113f,-0.311f,0.113f,-0.113f,-0.311f,0.113f,-0.313f,-0.311f,0.313f,-0.313f,-0.11f,0.313f,-0.113f,-0.11f,0.113f,-0.313f,-0.11f,0.113f,-0.113f,-0.11f};
        float* TempVertices4= new float[24] {-0.107f,-0.103f,-0.311f,-0.107f,0.097f,-0.311f,-0.307f,0.097f,-0.311f,-0.307f,-0.103f,-0.311f,-0.107f,-0.103f,-0.11f,-0.107f,0.097f,-0.11f,-0.307f,-0.103f,-0.11f,-0.307f,0.097f,-0.11f};
        float* TempVertices5= new float[24] {0.103f,-0.103f,-0.311f,0.103f,0.097f,-0.311f,-0.097f,0.097f,-0.311f,-0.097f,-0.103f,-0.311f,0.103f,-0.103f,-0.11f,0.103f,0.097f,-0.11f,-0.097f,-0.103f,-0.11f,-0.097f,0.097f,-0.11f};
        float* TempVertices6= new float[24] {0.313f,-0.103f,-0.311f,0.313f,0.097f,-0.311f,0.113f,0.097f,-0.311f,0.113f,-0.103f,-0.311f,0.313f,-0.103f,-0.11f,0.313f,0.097f,-0.11f,0.113f,-0.103f,-0.11f,0.113f,0.097f,-0.11f};
        float* TempVertices7= new float[24] {-0.107f,0.107f,-0.311f,-0.107f,0.307f,-0.311f,-0.307f,0.307f,-0.311f,-0.307f,0.107f,-0.311f,-0.107f,0.107f,-0.11f,-0.107f,0.307f,-0.11f,-0.307f,0.107f,-0.11f,-0.307f,0.307f,-0.11f};
        float* TempVertices8= new float[24] {0.103f,0.107f,-0.311f,0.103f,0.307f,-0.311f,-0.097f,0.307f,-0.311f,-0.097f,0.107f,-0.311f,0.103f,0.107f,-0.11f,0.103f,0.307f,-0.11f,-0.097f,0.107f,-0.11f,-0.097f,0.307f,-0.11f};
        float* TempVertices9= new float[24] {0.313f,0.107f,-0.311f,0.313f,0.307f,-0.311f,0.113f,0.307f,-0.311f,0.113f,0.107f,-0.311f,0.313f,0.107f,-0.11f,0.313f,0.307f,-0.11f,0.113f,0.107f,-0.11f,0.113f,0.307f,-0.11f};
        float* TempVertices10= new float[24] {-0.107f,-0.313f,-0.101f,-0.107f,-0.113f,-0.101f,-0.307f,-0.113f,-0.101f,-0.307f,-0.313f,-0.101f,-0.107f,-0.313f,0.1f,-0.107f,-0.113f,0.1f,-0.307f,-0.313f,0.1f,-0.307f,-0.113f,0.1f};
        float* TempVertices11= new float[24] {0.103f,-0.313f,-0.101f,0.103f,-0.113f,-0.101f,-0.097f,-0.113f,-0.101f,-0.097f,-0.313f,-0.101f,0.103f,-0.313f,0.1f,0.103f,-0.113f,0.1f,-0.097f,-0.313f,0.1f,-0.097f,-0.113f,0.1f};
        float* TempVertices12= new float[24] {0.313f,-0.313f,-0.101f,0.313f,-0.113f,-0.101f,0.113f,-0.113f,-0.101f,0.113f,-0.313f,-0.101f,0.313f,-0.313f,0.1f,0.313f,-0.113f,0.1f,0.113f,-0.313f,0.1f,0.113f,-0.113f,0.1f};
        float* TempVertices13= new float[24] {-0.107f,-0.103f,-0.101f,-0.107f,0.097f,-0.101f,-0.307f,0.097f,-0.101f,-0.307f,-0.103f,-0.101f,-0.107f,-0.103f,0.1f,-0.107f,0.097f,0.1f,-0.307f,-0.103f,0.1f,-0.307f,0.097f,0.1f};
        float* TempVertices14= new float[24] {0.103f,-0.103f,-0.101f,0.103f,0.097f,-0.101f,-0.097f,0.097f,-0.101f,-0.097f,-0.103f,-0.101f,0.103f,-0.103f,0.1f,0.103f,0.097f,0.1f,-0.097f,-0.103f,0.1f,-0.097f,0.097f,0.1f};
        float* TempVertices15= new float[24] {0.313f,-0.103f,-0.101f,0.313f,0.097f,-0.101f,0.113f,0.097f,-0.101f,0.113f,-0.103f,-0.101f,0.313f,-0.103f,0.1f,0.313f,0.097f,0.1f,0.113f,-0.103f,0.1f,0.113f,0.097f,0.1f};
        float* TempVertices16= new float[24] {-0.107f,0.107f,-0.101f,-0.107f,0.307f,-0.101f,-0.307f,0.307f,-0.101f,-0.307f,0.107f,-0.101f,-0.107f,0.107f,0.1f,-0.107f,0.307f,0.1f,-0.307f,0.107f,0.1f,-0.307f,0.307f,0.1f};
        float* TempVertices17= new float[24] {0.103f,0.107f,-0.101f,0.103f,0.307f,-0.101f,-0.097f,0.307f,-0.101f,-0.097f,0.107f,-0.101f,0.103f,0.107f,0.1f,0.103f,0.307f,0.1f,-0.097f,0.107f,0.1f,-0.097f,0.307f,0.1f};
        float* TempVertices18= new float[24] {0.313f,0.107f,-0.101f,0.313f,0.307f,-0.101f,0.113f,0.307f,-0.101f,0.113f,0.107f,-0.101f,0.313f,0.107f,0.1f,0.313f,0.307f,0.1f,0.113f,0.107f,0.1f,0.113f,0.307f,0.1f};
        float* TempVertices19= new float[24] {-0.107f,-0.313f,0.109f,-0.107f,-0.113f,0.109f,-0.307f,-0.113f,0.109f,-0.307f,-0.313f,0.109f,-0.107f,-0.313f,0.31f,-0.107f,-0.113f,0.31f,-0.307f,-0.313f,0.31f,-0.307f,-0.113f,0.31f};
        float* TempVertices20= new float[24] {0.103f,-0.313f,0.109f,0.103f,-0.113f,0.109f,-0.097f,-0.113f,0.109f,-0.097f,-0.313f,0.109f,0.103f,-0.313f,0.31f,0.103f,-0.113f,0.31f,-0.097f,-0.313f,0.31f,-0.097f,-0.113f,0.31f};
        float* TempVertices21= new float[24] {0.313f,-0.313f,0.109f,0.313f,-0.113f,0.109f,0.113f,-0.113f,0.109f,0.113f,-0.313f,0.109f,0.313f,-0.313f,0.31f,0.313f,-0.113f,0.31f,0.113f,-0.313f,0.31f,0.113f,-0.113f,0.31f};
        float* TempVertices22= new float[24] {-0.107f,-0.103f,0.109f,-0.107f,0.097f,0.109f,-0.307f,0.097f,0.109f,-0.307f,-0.103f,0.109f,-0.107f,-0.103f,0.31f,-0.107f,0.097f,0.31f,-0.307f,-0.103f,0.31f,-0.307f,0.097f,0.31f};
        float* TempVertices23= new float[24] {0.103f,-0.103f,0.109f,0.103f,0.097f,0.109f,-0.097f,0.097f,0.109f,-0.097f,-0.103f,0.109f,0.103f,-0.103f,0.31f,0.103f,0.097f,0.31f,-0.097f,-0.103f,0.31f,-0.097f,0.097f,0.31f};
        float* TempVertices24= new float[24] {0.313f,-0.103f,0.109f,0.313f,0.097f,0.109f,0.113f,0.097f,0.109f,0.113f,-0.103f,0.109f,0.313f,-0.103f,0.31f,0.313f,0.097f,0.31f,0.113f,-0.103f,0.31f,0.113f,0.097f,0.31f};
        float* TempVertices25= new float[24] {-0.107f,0.107f,0.109f,-0.107f,0.307f,0.109f,-0.307f,0.307f,0.109f,-0.307f,0.107f,0.109f,-0.107f,0.107f,0.31f,-0.107f,0.307f,0.31f,-0.307f,0.107f,0.31f,-0.307f,0.307f,0.31f};
        float* TempVertices26= new float[24] {0.103f,0.107f,0.109f,0.103f,0.307f,0.109f,-0.097f,0.307f,0.109f,-0.097f,0.107f,0.109f,0.103f,0.107f,0.31f,0.103f,0.307f,0.31f,-0.097f,0.107f,0.31f,-0.097f,0.307f,0.31f};
        float* TempVertices27= new float[24] {0.313f,0.107f,0.109f,0.313f,0.307f,0.109f,0.113f,0.307f,0.109f,0.113f,0.107f,0.109f,0.313f,0.107f,0.31f,0.313f,0.307f,0.31f,0.113f,0.107f,0.31f,0.113f,0.307f,0.31f};
        //______________________________________________________________________________________________________________________________
        float* TempAnimacion= new float[24] {-0.317f, -0.313f, -0.101f, -0.317f, -0.113f, -0.101f, -0.517f, -0.113f, -0.101f, -0.517f, -0.313f, -0.101f, -0.317f, -0.313f, 0.1f, -0.317f, -0.113f, 0.1f, -0.517f, -0.313f, 0.1f, -0.517f, -0.113f, 0.1f};
        float* TempAnimacion1= new float[24] {-0.117f, -0.313f, 0.539f, -0.117f, -0.113f, 0.539f, -0.317f, -0.113f, 0.539f, -0.317f, -0.313f, 0.539f, -0.117f, -0.313f, 0.74f, -0.117f, -0.113f, 0.74f, -0.317f, -0.313f, 0.74f, -0.317f, -0.113f, 0.74f};
        float* TempAnimacion2 = new float[24]{0.523f, -0.313f, -0.101f, 0.523f, -0.113f, -0.101f, 0.323f, -0.113f, -0.101f, 0.323f, -0.313f, -0.101f, 0.523f, -0.313f, 0.1f, 0.523f, -0.113f, 0.1f, 0.323f, -0.313f, 0.1f, 0.323f, -0.113f, 0.1f};
        float* TempAnimacion3 = new float[24]{-0.107f, -0.313f, -0.311f, -0.107f, -0.113f, -0.311f, -0.307f, -0.113f, -0.311f, -0.307f, -0.313f, -0.311f, -0.107f, -0.313f, -0.11f, -0.107f, -0.113f, -0.11f, -0.307f, -0.313f, -0.11f, -0.307f, -0.113f, -0.11f};
        float* TempAnimacion4 = new float[24]{0.103f, -0.313f, -0.521f, 0.103f, -0.113f, -0.521f, -0.097f, -0.113f, -0.521f, -0.097f, -0.313f, -0.521f, 0.103f, -0.313f, -0.32f, 0.103f, -0.113f, -0.32f, -0.097f, -0.313f, -0.32f, -0.097f, -0.113f, -0.32f};
        float* TempAnimacion5 = new float[24]{0.313f, -0.313f, -0.311f, 0.313f, -0.113f, -0.311f, 0.113f, -0.113f, -0.311f, 0.113f, -0.313f, -0.311f, 0.313f, -0.313f, -0.11f, 0.313f, -0.113f, -0.11f, 0.113f, -0.313f, -0.11f, 0.113f, -0.113f, -0.11f};
        float* TempAnimacion6 = new float[24]{-0.107f, -0.103f, -0.101f, -0.107f, 0.097f, -0.101f, -0.307f, 0.097f, -0.101f, -0.307f, -0.103f, -0.101f, -0.107f, -0.103f, 0.1f, -0.107f, 0.097f, 0.1f, -0.307f, -0.103f, 0.1f, -0.307f, 0.097f, 0.1f};
        float* TempAnimacion7 = new float[24]{0.103f, 0.107f, -0.101f, 0.103f, 0.307f, -0.101f, -0.097f, 0.307f, -0.101f, -0.097f, 0.107f, -0.101f, 0.103f, 0.107f, 0.1f, 0.103f, 0.307f, 0.1f, -0.097f, 0.107f, 0.1f, -0.097f, 0.307f, 0.1f};
        float* TempAnimacion8 = new float[24]{0.313f, -0.103f, -0.101f, 0.313f, 0.097f, -0.101f, 0.113f, 0.097f, -0.101f, 0.113f, -0.103f, -0.101f, 0.313f, -0.103f, 0.1f, 0.313f, 0.097f, 0.1f, 0.113f, -0.103f, 0.1f, 0.113f, 0.097f, 0.1f};
        float* TempAnimacion9 = new float[24]{-0.537f, -0.313f, 0.109f, -0.537f, -0.113f, 0.109f, -0.737f, -0.113f, 0.109f, -0.737f, -0.313f, 0.109f, -0.537f, -0.313f, 0.31f, -0.537f, -0.113f, 0.31f, -0.737f, -0.313f, 0.31f, -0.737f, -0.113f, 0.31f};
        float* TempAnimacion10 = new float[24]{0.323f, -0.313f, 0.539f, 0.323f, -0.113f, 0.539f, 0.123f, -0.113f, 0.539f, 0.123f, -0.313f, 0.539f, 0.323f, -0.313f, 0.74f, 0.323f, -0.113f, 0.74f, 0.123f, -0.313f, 0.74f, 0.123f, -0.113f, 0.74f};
        float* TempAnimacion11 = new float[24]{0.743f, -0.313f, 0.109f, 0.743f, -0.113f, 0.109f, 0.543f, -0.113f, 0.109f, 0.543f, -0.313f, 0.109f, 0.743f, -0.313f, 0.31f, 0.743f, -0.113f, 0.31f, 0.543f, -0.313f, 0.31f, 0.543f, -0.113f, 0.31f};
        float* TempAnimacion12 = new float[24]{-0.317f, -0.103f, 0.109f, -0.317f, 0.097f, 0.109f, -0.517f, 0.097f, 0.109f, -0.517f, -0.103f, 0.109f, -0.317f, -0.103f, 0.31f, -0.317f, 0.097f, 0.31f, -0.517f, -0.103f, 0.31f, -0.517f, 0.097f, 0.31f};
        float* TempAnimacion13 = new float[24]{0.103f, -0.103f, -0.311f, 0.103f, 0.097f, -0.311f, -0.097f, 0.097f, -0.311f, -0.097f, -0.103f, -0.311f, 0.103f, -0.103f, -0.11f, 0.103f, 0.097f, -0.11f, -0.097f, -0.103f, -0.11f, -0.097f, 0.097f, -0.11f};
        float* TempAnimacion14 = new float[24]{0.523f, -0.103f, 0.109f, 0.523f, 0.097f, 0.109f, 0.323f, 0.097f, 0.109f, 0.323f, -0.103f, 0.109f, 0.523f, -0.103f, 0.31f, 0.523f, 0.097f, 0.31f, 0.323f, -0.103f, 0.31f, 0.323f, 0.097f, 0.31f};
        float* TempAnimacion15 = new float[24]{-0.107f, 0.107f, 0.109f, -0.107f, 0.307f, 0.109f, -0.307f, 0.307f, 0.109f, -0.307f, 0.107f, 0.109f, -0.107f, 0.107f, 0.31f, -0.107f, 0.307f, 0.31f, -0.307f, 0.107f, 0.31f, -0.307f, 0.307f, 0.31f};
        float* TempAnimacion16 = new float[24]{0.103f, 0.107f, 0.109f, 0.103f, 0.307f, 0.109f, -0.097f, 0.307f, 0.109f, -0.097f, 0.107f, 0.109f, 0.103f, 0.107f, 0.31f, 0.103f, 0.307f, 0.31f, -0.097f, 0.107f, 0.31f, -0.097f, 0.307f, 0.31f};
        float* TempAnimacion17 = new float[24]{0.313f, 0.107f, 0.109f, 0.313f, 0.307f, 0.109f, 0.113f, 0.307f, 0.109f, 0.113f, 0.107f, 0.109f, 0.313f, 0.107f, 0.31f, 0.313f, 0.307f, 0.31f, 0.113f, 0.107f, 0.31f, 0.113f, 0.307f, 0.31f};
        float* TempAnimacion18 = new float[24]{-0.327f, -0.313f, 0.319f, -0.327f, -0.113f, 0.319f, -0.527f, -0.113f, 0.319f, -0.527f, -0.313f, 0.319f, -0.327f, -0.313f, 0.52f, -0.327f, -0.113f, 0.52f, -0.527f, -0.313f, 0.52f, -0.527f, -0.113f, 0.52f};
        float* TempAnimacion19 = new float[24]{0.103f, -0.313f, 0.749f, 0.103f, -0.113f, 0.749f, -0.097f, -0.113f, 0.749f, -0.097f, -0.313f, 0.749f, 0.103f, -0.313f, 0.949999f, 0.103f, -0.113f, 0.949999f, -0.097f, -0.313f, 0.949999f, -0.097f, -0.113f, 0.949999f};
        float* TempAnimacion20 = new float[24]{0.533f, -0.313f, 0.319f, 0.533f, -0.113f, 0.319f, 0.333f, -0.113f, 0.319f, 0.333f, -0.313f, 0.319f, 0.533f, -0.313f, 0.52f, 0.533f, -0.113f, 0.52f, 0.333f, -0.313f, 0.52f, 0.333f, -0.113f, 0.52f};
        float* TempAnimacion21 = new float[24]{-0.107f, -0.103f, 0.319f, -0.107f, 0.097f, 0.319f, -0.307f, 0.097f, 0.319f, -0.307f, -0.103f, 0.319f, -0.107f, -0.103f, 0.52f, -0.107f, 0.097f, 0.52f, -0.307f, -0.103f, 0.52f, -0.307f, 0.097f, 0.52f};
        float* TempAnimacion22 = new float[24]{0.103f, -0.103f, 0.539f, 0.103f, 0.097f, 0.539f, -0.097f, 0.097f, 0.539f, -0.097f, -0.103f, 0.539f, 0.103f, -0.103f, 0.74f, 0.103f, 0.097f, 0.74f, -0.097f, -0.103f, 0.74f, -0.097f, 0.097f, 0.74f};
        float* TempAnimacion23 = new float[24]{0.313f, -0.103f, 0.319f, 0.313f, 0.097f, 0.319f, 0.113f, 0.097f, 0.319f, 0.113f, -0.103f, 0.319f, 0.313f, -0.103f, 0.52f, 0.313f, 0.097f, 0.52f, 0.113f, -0.103f, 0.52f, 0.113f, 0.097f, 0.52f};
        float* TempAnimacion24 = new float[24]{0.103f, 0.527f, 0.109f, 0.103f, 0.727f, 0.109f, -0.097f, 0.727f, 0.109f, -0.097f, 0.527f, 0.109f, 0.103f, 0.527f, 0.31f, 0.103f, 0.727f, 0.31f, -0.097f, 0.527f, 0.31f, -0.097f, 0.727f, 0.31f};
        float* TempAnimacion25 = new float[24]{0.103f, 0.107f, 0.319f, 0.103f, 0.307f, 0.319f, -0.097f, 0.307f, 0.319f, -0.097f, 0.107f, 0.319f, 0.103f, 0.107f, 0.52f, 0.103f, 0.307f, 0.52f, -0.097f, 0.107f, 0.52f, -0.097f, 0.307f, 0.52f};
        float* TempAnimacion26 = new float[24]{0.103f, 0.317f, 0.109f, 0.103f, 0.517f, 0.109f, -0.097f, 0.517f, 0.109f, -0.097f, 0.317f, 0.109f, 0.103f, 0.317f, 0.31f, 0.103f, 0.517f, 0.31f, -0.097f, 0.317f, 0.31f, -0.097f, 0.517f, 0.31f};

        //_______________Tenpmatrices____________________
        //aser matrices temp de pisos y planos
        int PisoTemp[3][3];
        int PisoTemp2[3][3];
        int PisoTemp3[3][3];
        int PlanoTemp1[3][3];
        int PlanoTemp2[3][3];
        int PlanoTemp3[3][3];
        //_______________________________________________________________
        void imprimirMatriz(const int matriz[3][3]) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    std::cout << matriz[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        void funcionTransform(int matrizA[3][3], int matrizB[3][3], int valorA, int valorB) 
        {
            // Reemplazar la fila de matrizA con la fila de matrizB
            for (int i = 0; i < 3; i++) {
                matrizA[valorA][i] = matrizB[valorB][i];
            }
        }
        void funcionTransformGiro(int matrizA[3][3], int matrizB[3][3], int valorA,int valorB) 
        {
            for (int i = 0; i < 3; ++i) {
                matrizA[i][valorA] = matrizB[i][valorB];
            }
        }
        void funcionTransformGiroB(int matrizA[3][3], int matrizB[3][3], int valorA,int valorB) 
        {
            for (int i = 0; i < 3; ++i) {
                matrizA[i][valorA] = matrizB[valorB][i];
            }
        }
        void rotarMatriz(int matriz[3][3])
        {
            int matrizRotada[3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrizRotada[j][2 - i] = matriz[i][j];
                }
            }

            // Copiar la matriz rotada a la matriz original
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matriz[i][j] = matrizRotada[i][j];
                }
            }
        }
        void rotarMatrizInversa(int matriz[3][3]) {
            int matrizRotada[3][3];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matrizRotada[2 - j][i] = matriz[i][j]; // Girar en la dirección opuesta
                }
            }
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    matriz[i][j] = matrizRotada[i][j];
                }
            }
        }
        float* obtenerVertices(int ID) {
            auto it = Cubos.find(ID);
            if (it != Cubos.end()) {
                return it->second.first;
            }
            else {
                return nullptr;
            }
        }
        void modificarVertices(int ID, float* nuevosVertices) {
            auto it = Cubos.find(ID);
            if (it != Cubos.end()) {
                it->second.first = nuevosVertices;
            }
        }
        //___________________________
        void ActualizarVertices(int key, float* vertices) 
        {
            auto it = Cubos.find(key);
            if (it != Cubos.end()) 
            {
                it->second.first = vertices;
                std::cout<<key << "," <<it->second.first <<std::endl;
            } else 
            {
                std::cout << "No se encontró la clave en el mapa." << std::endl;
            }
        }

        void modificarTraslacion3D(float* vertices2, int numVertices, float trasladarX, float trasladarY, float trasladarZ)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];

                mh.trasladar3D(trasladarX, trasladarY, trasladarZ, x, y, z);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }
        void modificarRotacionTraslacion(float* vertices2, int numVertices, float trasladarX, float trasladarY, float trasladarZ,string opcionRotacion,float angulo)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.trasladarRotar3D(trasladarX, trasladarY, trasladarZ, x, y, z,angulo,opcionRotacion);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }
        void ModificarRotacion3D(float* vertices2, int numVertices,  string opcionRotacion, float angulo)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.Rotacion3D(angulo, x, y, z, opcionRotacion);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }

        void ModificarEscala3D(float* vertices2, int numVertices,float Distanciaa)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.Escala3D(Distanciaa,Distanciaa,Distanciaa, x, y, z);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];
                //cout<<"X:"<<x<<"Y:"<<y<<"Z:"<<x<<endl;

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }

        void ModificarEscalaRotacion3D(float* vertices2, int numVertices,float Distanciaa, string opcionRotacion, float angulo)
        {
            for (int i = 0; i < numVertices; i++)
            {
                MatrixHandler mh;
                float x, y, z;
                x = vertices2[i * 3];
                y = vertices2[i * 3 + 1];
                z = vertices2[i * 3 + 2];
                mh.RotarYEscala3D(Distanciaa,Distanciaa,Distanciaa, x, y, z,opcionRotacion,angulo);
                igualarResultado = mh.crearEstructura3D();
                mh.resetearMatrices3D();

                vertices2[i * 3] = igualarResultado[0][0];
                vertices2[i * 3 + 1] = igualarResultado[1][0];
                vertices2[i * 3 + 2] = igualarResultado[2][0];

                if ((i * 3 + 2) >= numVertices - 1)
                {
                    break;
                }
            }
        }

        //_____________________________________________________________________________________________________________________
        void interpolacionCircularLado(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "X", -1.0f);
        }
        void interpolacionCircularLadoB(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "X", 1.0f);
        }
        //_____________________________________________________________________________________________________________________
        void interpolacionCircular(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Z", -1.0f);
        }
        
        void interpolacionCircularPlanos(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Y", -1.0f);
        }
        void interpolacionCircularB(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Z", 1.0f);
        }
        void interpolacionCircularPlanoB(float* vertices, int numVertices, float puntoMedioX, float puntoMedioY, float angulo) 
        {
            ModificarRotacion3D(vertices, numVertices, "Y", 1.0f);
        }
        //_____________________________________________________________________________________________________________________
        void ImprimirTodasLasMatrices()
        {
            cout<<"Plano1"<<endl;
            imprimirMatriz(Plano1);
            cout<<"Plano2"<<endl;
            imprimirMatriz(Plano2);
            cout<<"Plano3"<<endl;
            imprimirMatriz(Plano3);
            cout<<"Piso1"<<endl;
            imprimirMatriz(Piso1);
            cout<<"Piso2"<<endl;
            imprimirMatriz(Piso2);
            cout<<"Piso3"<<endl;
            imprimirMatriz(Piso3);
            cout<<"LADO1"<<endl;
            imprimirMatriz(Lado1);
            cout<<"LADO2"<<endl;
            imprimirMatriz(Lado2);
            cout<<"LADO3"<<endl;
            imprimirMatriz(Lado3);
            cout<<"__________________________"<<endl;
        }
        //_____________________________________________________________________________________________________________________
        
        void interpolacionCircularPlano(int PlanoModifico[3][3],bool condion) 
        {
            if (condion==false)
            {
                //cout<<"entro a la condicion verdadera"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircular(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);

                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircular(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);
                
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircular(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);
                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircular(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);
                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircular(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);
                //int cubo5 = PlanoModifico[1][1];
                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircular(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);
                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircular(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);
                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircular(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);
                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircular(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);

            }
            else if(condion==true)
            {
                //cout<<"entro a la condicion falsa"<<endl;   
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;

                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularB(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularB(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);

                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularB(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularB(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularB(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularB(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularB(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularB(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularB(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);

            }
        }

        void interpolacionCircularPiso(int PlanoModifico[3][3],bool condicion) 
        {
            if(condicion==false)
            {
                //cout<<"entro a la condicion verdadera"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularPlanos(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularPlanos(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);
                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularPlanos(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);
                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularPlanos(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);
                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularPlanos(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);
                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularPlanos(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);
                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularPlanos(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);
                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularPlanos(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);
                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularPlanos(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);

            }
            else if(condicion==true)
            {
                //cout<<"entro a la condicion falsa"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularPlanoB(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);
                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularPlanoB(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);
                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularPlanoB(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularPlanoB(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularPlanoB(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularPlanoB(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularPlanoB(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularPlanoB(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularPlanoB(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);
                /*
                cout<<"se esta moviendo estos cubos :"<<endl;
                cout<<cubo1<<","<<cubo2<<","<<cubo3<<endl;
                cout<<cubo4<<","<<cubo5<<","<<cubo6<<endl;
                cout<<cubo7<<","<<cubo8<<","<<cubo9<<endl;
                */
                //liberar memoria de 
            }
        }

        void CamadaCircularLado(int PlanoModifico[3][3],bool condicion) 
        {
            if(condicion==false)
            {
                //cout<<"entro a la condicion verdadera"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularLado(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);

                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularLado(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);

                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularLado(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularLado(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularLado(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularLado(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularLado(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularLado(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularLado(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);

            }
            else if(condicion==true)
            {
                //cout<<"entro a la condicion falsa"<<endl;
                // Valor del punto medio en x , y
                float puntoMedioX = 0.22f;
                float puntoMedioY = 0.31f;
                //igualar los 8 vertices de int matrizA[3][3]
                int cubo1 = PlanoModifico[0][0];
                float* verticesUsoPlano1 = obtenerVertices(cubo1);
                interpolacionCircularLadoB(verticesUsoPlano1, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo1, verticesUsoPlano1);

                int cubo2 = PlanoModifico[0][1];
                float* verticesUsoPlano2 = obtenerVertices(cubo2);
                interpolacionCircularLadoB(verticesUsoPlano2, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo2, verticesUsoPlano2);

                int cubo3 = PlanoModifico[0][2];
                float* verticesUsoPlano3 = obtenerVertices(cubo3);
                interpolacionCircularLadoB(verticesUsoPlano3, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo3, verticesUsoPlano3);

                int cubo4 = PlanoModifico[1][0];
                float* verticesUsoPlano4 = obtenerVertices(cubo4);
                interpolacionCircularLadoB(verticesUsoPlano4, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo4, verticesUsoPlano4);

                int cubo5 = PlanoModifico[1][1];
                float* verticesUsoPlano5 = obtenerVertices(cubo5);
                interpolacionCircularLadoB(verticesUsoPlano5, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo5, verticesUsoPlano5);

                int cubo6 = PlanoModifico[1][2];
                float* verticesUsoPlano6 = obtenerVertices(cubo6);
                interpolacionCircularLadoB(verticesUsoPlano6, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo6, verticesUsoPlano6);

                int cubo7 = PlanoModifico[2][0];
                float* verticesUsoPlano7 = obtenerVertices(cubo7);
                interpolacionCircularLadoB(verticesUsoPlano7, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo7, verticesUsoPlano7);

                int cubo8 = PlanoModifico[2][1];
                float* verticesUsoPlano8 = obtenerVertices(cubo8);
                interpolacionCircularLadoB(verticesUsoPlano8, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo8, verticesUsoPlano8);

                int cubo9 = PlanoModifico[2][2];
                float* verticesUsoPlano9 = obtenerVertices(cubo9);
                interpolacionCircularLadoB(verticesUsoPlano9, 24, puntoMedioX, puntoMedioY, 90.0f);
                modificarVertices(cubo9, verticesUsoPlano9);
            }
        }


        void moverUnCubito(int IdCubito,string opcion,float movimientoAtrasladar)
        {
            float* VerticesTemp = obtenerVertices(IdCubito);
            if (opcion == "X") {
                modificarTraslacion3D(VerticesTemp, 24,  movimientoAtrasladar, 0.0f, 0.0f);
            }
            else if (opcion == "Y") {
                modificarTraslacion3D(VerticesTemp, 24,  0.0f, movimientoAtrasladar, 0.0f);
            }
            else if (opcion == "Z") {
                modificarTraslacion3D(VerticesTemp, 24,  0.0f, 0.0f, movimientoAtrasladar);
            }
            modificarVertices(IdCubito, VerticesTemp);
        }

        

        //aser funcion llamada Precalculo
        bool verificarElementosRepetidos(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]) 
        {
            bool elementosRepetidos[27] = {false}; // Array para marcar los elementos encontrados

            // Verificar elementos en la matriz1
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz1[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            // Verificar elementos en la matriz2
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz2[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            // Verificar elementos en la matriz3
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int elemento = matriz3[i][j];
                    if (elementosRepetidos[elemento]) {
                        return false; // Se encontró un elemento repetido
                    } else {
                        elementosRepetidos[elemento] = true;
                    }
                }
            }

            return true; // No se encontraron elementos repetidos
        }
        bool PrecalcularPiso(int caso)
        { 
            //iguala las matrices temp 
            memcpy(PisoTemp, Piso1, sizeof(PisoTemp));
            memcpy(PisoTemp2, Piso2, sizeof(PisoTemp2));
            memcpy(PisoTemp3, Piso3, sizeof(PisoTemp3));
            memcpy(PlanoTemp1, Plano1, sizeof(PlanoTemp1));
            memcpy(PlanoTemp2, Plano2, sizeof(PlanoTemp2));
            memcpy(PlanoTemp3, Plano3, sizeof(PlanoTemp3));
            //aser un switch para los casos
            switch (caso)
            {
            case 1:
                rotarMatriz(PisoTemp);
                funcionTransform(PlanoTemp1, PisoTemp, 2, 2);
                funcionTransform(PlanoTemp2, PisoTemp, 2, 1);
                funcionTransform(PlanoTemp3, PisoTemp, 2, 0);
                break;
            case 2:
                rotarMatriz(PisoTemp2);
                funcionTransform(PlanoTemp1, PisoTemp2, 1, 2);
                funcionTransform(PlanoTemp2, PisoTemp2, 1, 1);
                funcionTransform(PlanoTemp3, PisoTemp2, 1, 0);
                break;
            case 3:
                rotarMatriz(PisoTemp3);
                funcionTransform(PlanoTemp1, PisoTemp3, 0, 2);
                funcionTransform(PlanoTemp2, PisoTemp3, 0, 1);
                funcionTransform(PlanoTemp3, PisoTemp3, 0, 0);
                break;
            case 4:
                rotarMatrizInversa(PisoTemp);
                funcionTransform(PlanoTemp1, PisoTemp, 2, 2);
                funcionTransform(PlanoTemp2, PisoTemp, 2, 1);
                funcionTransform(PlanoTemp3, PisoTemp, 2, 0);
                break;
            case 5:
                rotarMatrizInversa(PisoTemp2);
                funcionTransform(PlanoTemp1, PisoTemp2, 1, 2);
                funcionTransform(PlanoTemp2, PisoTemp2, 1, 1);
                funcionTransform(PlanoTemp3, PisoTemp2, 1, 0);
                break;
            case 6:
                rotarMatrizInversa(PisoTemp3);
                funcionTransform(PlanoTemp1, PisoTemp3, 0, 2);
                funcionTransform(PlanoTemp2, PisoTemp3, 0, 1);
                funcionTransform(PlanoTemp3, PisoTemp3, 0, 0);
                break;
            default:
                break;
            }

            bool pisos= verificarElementosRepetidos(PisoTemp,PisoTemp2,PisoTemp3);
            bool planos= verificarElementosRepetidos(PlanoTemp1,PlanoTemp2,PlanoTemp3);
            if(pisos==true && planos==true)
            {
                cout<<"no hay elementos repetidos"<<endl;
                return true;
            }
            else
            {
                cout<<"hay elementos repetidos"<<endl;
                return false;
            }

        }
        bool PrecalcularPlanos(int caso)
        { 
            //iguala las matrices temp 
            memcpy(PisoTemp, Piso1, sizeof(PisoTemp));
            memcpy(PisoTemp2, Piso2, sizeof(PisoTemp2));
            memcpy(PisoTemp3, Piso3, sizeof(PisoTemp3));
            memcpy(PlanoTemp1, Plano1, sizeof(PlanoTemp1));
            memcpy(PlanoTemp2, Plano2, sizeof(PlanoTemp2));
            memcpy(PlanoTemp3, Plano3, sizeof(PlanoTemp3));
            //aser un switch para los casos
            switch (caso)
            {
            case 1:
                rotarMatriz(PlanoTemp1);
                funcionTransform(PisoTemp, PlanoTemp1, 2, 2);
                funcionTransform(PisoTemp2, PlanoTemp1, 2, 1);
                funcionTransform(PisoTemp3, PlanoTemp1, 2, 0);
                break;
            case 2:
                rotarMatriz(PlanoTemp2);
                funcionTransform(PisoTemp, PlanoTemp2, 1, 2);
                funcionTransform(PisoTemp2, PlanoTemp2, 1, 1);
                funcionTransform(PisoTemp3, PlanoTemp2, 1, 0);
                break;
            case 3:
                rotarMatriz(PlanoTemp3);
                funcionTransform(PisoTemp, PlanoTemp3, 0, 2);
                funcionTransform(PisoTemp2, PlanoTemp3, 0, 1);
                funcionTransform(PisoTemp3, PlanoTemp3, 0, 0);
                break;
            case 4:
                rotarMatrizInversa(PlanoTemp1);
                funcionTransform(PisoTemp, PlanoTemp1, 2, 2);
                funcionTransform(PisoTemp2, PlanoTemp1, 2, 1);
                funcionTransform(PisoTemp3, PlanoTemp1, 2, 0);
                break;
            case 5:
                rotarMatrizInversa(PlanoTemp2);
                funcionTransform(PisoTemp, PlanoTemp2, 1, 2);
                funcionTransform(PisoTemp2, PlanoTemp2, 1, 1);
                funcionTransform(PisoTemp3, PlanoTemp2, 1, 0);
                break;
            case 6:
                rotarMatrizInversa(PlanoTemp3);
                funcionTransform(PisoTemp, PlanoTemp3, 0, 2);
                funcionTransform(PisoTemp2, PlanoTemp3, 0, 1);
                funcionTransform(PisoTemp3, PlanoTemp3, 0, 0);
                break;
            default:
                break;
            }

            bool pisos= verificarElementosRepetidos(PisoTemp,PisoTemp2,PisoTemp3);
            bool planos= verificarElementosRepetidos(PlanoTemp1,PlanoTemp2,PlanoTemp3);
            if(pisos==true && planos==true)
            {
                cout<<"no hay elementos repetidos"<<endl;
                return true;
            }
            else
            {
                cout<<"hay elementos repetidos"<<endl;
                return false;
            }

        }
        //__________________________________
        void SetearPosiciones(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]) 
        {
            imprimirMatriz(Plano1);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano2);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano3);
            cout<<"__________________________"<<endl;
            //Plano1
            int cubo1 = matriz1[2][2];
            ActualizarVertices(cubo1,TempVertices);
            int cubo2 = matriz1[2][1];
            ActualizarVertices(cubo2,TempVertices2);
            int cubo3 = matriz1[2][0];
            ActualizarVertices(cubo3,TempVertices3);
            int cubo4 = matriz1[1][2];
            ActualizarVertices(cubo4,TempVertices4);
            int cubo5 = matriz1[1][1];
            ActualizarVertices(cubo5,TempVertices5);
            int cubo6 = matriz1[1][0];
            ActualizarVertices(cubo6,TempVertices6);
            int cubo7 = matriz1[0][2];
            ActualizarVertices(cubo7,TempVertices7);
            int cubo8 = matriz1[0][1];
            ActualizarVertices(cubo8,TempVertices8);
            int cubo9 = matriz1[0][0];
            ActualizarVertices(cubo9,TempVertices9);
            //Plano2
            int cubo10 = matriz2[2][2];
            ActualizarVertices(cubo10,TempVertices10);
            int cubo11 = matriz2[2][1];
            ActualizarVertices(cubo11,TempVertices11);
            int cubo12 = matriz2[2][0];
            ActualizarVertices(cubo12,TempVertices12);
            int cubo13 = matriz2[1][2];
            ActualizarVertices(cubo13,TempVertices13);
            int cubo14 = matriz2[1][1];
            ActualizarVertices(cubo14,TempVertices14);
            int cubo15 = matriz2[1][0];
            ActualizarVertices(cubo15,TempVertices15);
            int cubo16 = matriz2[0][2];
            ActualizarVertices(cubo16,TempVertices16);
            int cubo17 = matriz2[0][1];
            ActualizarVertices(cubo17,TempVertices17);
            int cubo18 = matriz2[0][0];
            ActualizarVertices(cubo18,TempVertices18);
            //Plano3
            int cubo19 = matriz3[2][2];
            ActualizarVertices(cubo19,TempVertices19);
            int cubo20 = matriz3[2][1];
            ActualizarVertices(cubo20,TempVertices20);
            int cubo21 = matriz3[2][0];
            ActualizarVertices(cubo21,TempVertices21);
            int cubo22 = matriz3[1][2];
            ActualizarVertices(cubo22,TempVertices22);
            int cubo23 = matriz3[1][1];
            ActualizarVertices(cubo23,TempVertices23);
            int cubo24 = matriz3[1][0];
            ActualizarVertices(cubo24,TempVertices24);
            int cubo25 = matriz3[0][2];
            ActualizarVertices(cubo25,TempVertices25);
            int cubo26 = matriz3[0][1];
            ActualizarVertices(cubo26,TempVertices26);
            int cubo27 = matriz3[0][0];
            ActualizarVertices(cubo27,TempVertices27);
            cout<<cubo1<<","<<cubo2<<","<<cubo3<<","<<cubo4<<","<<cubo5<<","<<cubo6<<","<<cubo7<<","<<cubo8<<","<<cubo9<<endl;
            cout<<cubo10<<","<<cubo11<<","<<cubo12<<","<<cubo13<<","<<cubo14<<","<<cubo15<<","<<cubo16<<","<<cubo17<<","<<cubo18<<endl;
            cout<<cubo19<<","<<cubo20<<","<<cubo21<<","<<cubo22<<","<<cubo23<<","<<cubo24<<","<<cubo25<<","<<cubo26<<","<<cubo27<<endl;
            cout<<"se setearon las posiciones"<<endl;
            //ImprimirTodasLasMatrices();
            cout<<"__________________________"<<endl;
        }

        void SetearPosicionePiramide(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]) 
        {
            imprimirMatriz(Plano1);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano2);
            cout<<"__________________________"<<endl;
            imprimirMatriz(Plano3);
            cout<<"__________________________"<<endl;
            //Plano1
            int cubo1 = matriz1[2][2];
            ActualizarVertices(cubo1,TempAnimacion);
            int cubo2 = matriz1[2][1];
            ActualizarVertices(cubo2,TempAnimacion1);
            int cubo3 = matriz1[2][0];
            ActualizarVertices(cubo3,TempAnimacion2);
            int cubo4 = matriz1[1][2];
            ActualizarVertices(cubo4,TempAnimacion3);
            int cubo5 = matriz1[1][1];
            ActualizarVertices(cubo5,TempAnimacion4);
            int cubo6 = matriz1[1][0];
            ActualizarVertices(cubo6,TempAnimacion5);
            int cubo7 = matriz1[0][2];
            ActualizarVertices(cubo7,TempAnimacion6);
            int cubo8 = matriz1[0][1];
            ActualizarVertices(cubo8,TempAnimacion7);
            int cubo9 = matriz1[0][0];
            ActualizarVertices(cubo9,TempAnimacion8);
            //Plano2
            int cubo10 = matriz2[2][2];
            ActualizarVertices(cubo10,TempAnimacion9);
            int cubo11 = matriz2[2][1];
            ActualizarVertices(cubo11,TempAnimacion10);
            int cubo12 = matriz2[2][0];
            ActualizarVertices(cubo12,TempAnimacion11);
            int cubo13 = matriz2[1][2];
            ActualizarVertices(cubo13,TempAnimacion12);
            int cubo14 = matriz2[1][1];
            ActualizarVertices(cubo14,TempAnimacion13);
            int cubo15 = matriz2[1][0];
            ActualizarVertices(cubo15,TempAnimacion14);
            int cubo16 = matriz2[0][2];
            ActualizarVertices(cubo16,TempAnimacion15);
            int cubo17 = matriz2[0][1];
            ActualizarVertices(cubo17,TempAnimacion16);
            int cubo18 = matriz2[0][0];
            ActualizarVertices(cubo18,TempAnimacion17);
            //Plano3
            int cubo19 = matriz3[2][2];
            ActualizarVertices(cubo19,TempAnimacion18);
            int cubo20 = matriz3[2][1];
            ActualizarVertices(cubo20,TempAnimacion19);
            int cubo21 = matriz3[2][0];
            ActualizarVertices(cubo21,TempAnimacion20);
            int cubo22 = matriz3[1][2];
            ActualizarVertices(cubo22,TempAnimacion21);
            int cubo23 = matriz3[1][1];
            ActualizarVertices(cubo23,TempAnimacion22);
            int cubo24 = matriz3[1][0];
            ActualizarVertices(cubo24,TempAnimacion23);
            int cubo25 = matriz3[0][2];
            ActualizarVertices(cubo25,TempAnimacion24);
            int cubo26 = matriz3[0][1];
            ActualizarVertices(cubo26,TempAnimacion25);
            int cubo27 = matriz3[0][0];
            ActualizarVertices(cubo27,TempAnimacion26);

            cout<<"__________________________"<<endl;
        }

        //__________________________________
        void realizarAnimacion(int accion,bool condicion,int ModificadoMatriz[3][3],bool condicionLado) 
        {
            if ( condicionLado==false )
            {
                switch (accion) 
                {
                    case 1: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano(ModificadoMatriz,true);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, true);
                        }
                        break;
                    }
                    case 2: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano(ModificadoMatriz,true);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, true);
                        }
                        break;
                    }
                    case 3: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano( ModificadoMatriz,true);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, true);
                        }
                        break;
                    }
                    case 4: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano(ModificadoMatriz,false);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, false);
                        }
                        break;
                    }
                    case 5: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano(ModificadoMatriz,false);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, false);
                        }
                        break;
                    }
                    case 6: 
                    {
                        if (condicion==false)
                        {
                            interpolacionCircularPlano(ModificadoMatriz,false);
                        }
                        else
                        {
                            interpolacionCircularPiso(ModificadoMatriz, false);
                        }
                        break;
                    }

                    default:
                        // Acción no válida
                        break;
                }
            }
            else 
            {
                switch (accion) 
                {
                    case 1: 
                    {
                        CamadaCircularLado(ModificadoMatriz, false);
                        break;
                    }
                    case 2: 
                    {
                        CamadaCircularLado(ModificadoMatriz, false);
                        break;
                    }
                    case 3: 
                    {
                        CamadaCircularLado(ModificadoMatriz, false);
                        break;
                    }
                    case 4: 
                    {
                        CamadaCircularLado(ModificadoMatriz, true);
                        break;
                    }
                    case 5: 
                    {
                        CamadaCircularLado(ModificadoMatriz, true);
                        break;
                    }
                    case 6: 
                    {
                        CamadaCircularLado(ModificadoMatriz, true);
                        break;
                    }
                    default:
                        break;
                }

            }
        }
        void GirarPiso(int condicion) 
        {
            switch (condicion) {

                case 1:
                    if(PrecalcularPiso(1)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Piso1);
                        
                        funcionTransform(Plano1, Piso1, 2, 2);
                        funcionTransform(Plano2, Piso1, 2, 1);
                        funcionTransform(Plano3, Piso1, 2, 0);

                        
                        break;
                    }
                case 2:
                    if(PrecalcularPiso(2)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        
                        rotarMatriz(Piso2);
                        funcionTransform(Plano1, Piso2, 1, 2);
                        funcionTransform(Plano2, Piso2, 1, 1);
                        funcionTransform(Plano3, Piso2, 1, 0);
                        break;
                    }
                case 3:
                    if(PrecalcularPiso(3)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Piso3);
                        funcionTransform(Plano1, Piso3, 0, 2);
                        funcionTransform(Plano2, Piso3, 0, 1);
                        funcionTransform(Plano3, Piso3, 0, 0);
                        break;
                    }
                case 4:
                    if(PrecalcularPiso(4)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Piso1);
                        funcionTransform(Plano1, Piso1, 2, 2);
                        funcionTransform(Plano2, Piso1, 2, 1);
                        funcionTransform(Plano3, Piso1, 2, 0);
                        break;
                    }
                case 5:
                    if(PrecalcularPiso(5)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Piso2);
                        funcionTransform(Plano1, Piso2, 1, 2);
                        funcionTransform(Plano2, Piso2, 1, 1);
                        funcionTransform(Plano3, Piso2, 1, 0);
                        break;
                    }
                case 6:
                    if(PrecalcularPiso(6)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        rotarMatrizInversa(Piso3);
                        cout<<"se puede girar"<<endl;
                        funcionTransform(Plano1, Piso3, 0, 2);
                        funcionTransform(Plano2, Piso3, 0, 1);
                        funcionTransform(Plano3, Piso3, 0, 0);
                        break;
                    }
                default:
                    break;
            }
                
        }
        void GirarPlano(int condicion) 
        {
            switch (condicion) 
            {

                case 1:

                    cout<<"GirarPiso 1"<<endl;
                    if(PrecalcularPlanos(1)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano1);
                        funcionTransform(Piso1, Plano1, 2, 2);
                        funcionTransform(Piso2, Plano1, 2, 1);
                        funcionTransform(Piso3, Plano1, 2, 0);

                        funcionTransformGiro(Lado1, Plano1, 2, 0);
                        funcionTransformGiro(Lado2, Plano1, 2, 1);
                        funcionTransformGiro(Lado3, Plano1, 2, 2);
                        break;
                    }

                    break;
                case 2:
                    cout<<"GirarPiso 2"<<endl;
                    if(PrecalcularPlanos(2)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano2);
                        funcionTransform(Piso1, Plano2, 1, 2);
                        funcionTransform(Piso2, Plano2, 1, 1);
                        funcionTransform(Piso3, Plano2, 1, 0);

                        funcionTransformGiro(Lado1, Plano2, 1, 0);
                        funcionTransformGiro(Lado2, Plano2, 1, 1);
                        funcionTransformGiro(Lado3, Plano2, 1, 2);
                        break;
                    }
                case 3:
                    cout<<"GirarPiso 3"<<endl;
                    if(PrecalcularPlanos(3)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatriz(Plano3);
                        funcionTransform(Piso1, Plano3, 0, 2);
                        funcionTransform(Piso2, Plano3, 0, 1);
                        funcionTransform(Piso3, Plano3, 0, 0);

                        funcionTransformGiro(Lado1, Plano2, 0, 0);
                        funcionTransformGiro(Lado2, Plano2, 0, 1);
                        funcionTransformGiro(Lado3, Plano2, 0, 2);
                        break;
                    }
                case 4:
                    cout<<"GirarPiso 4"<<endl;
                    if(PrecalcularPlanos(4)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano1);
                        funcionTransform(Piso1, Plano1, 2, 2);
                        funcionTransform(Piso2, Plano1, 2, 1);
                        funcionTransform(Piso3, Plano1, 2, 0);

                        funcionTransformGiro(Lado1, Plano1, 2, 0);
                        funcionTransformGiro(Lado2, Plano1, 2, 1);
                        funcionTransformGiro(Lado3, Plano1, 2, 2);
                        break;
                    }
                case 5:
                    cout<<"GirarPiso 5"<<endl;
                    if(PrecalcularPlanos(5)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano2);
                        funcionTransform(Piso1, Plano2, 1, 2);
                        funcionTransform(Piso2, Plano2, 1, 1);
                        funcionTransform(Piso3, Plano2, 1, 0);

                        funcionTransformGiro(Lado1, Plano2, 1, 0);
                        funcionTransformGiro(Lado2, Plano2, 1, 1);
                        funcionTransformGiro(Lado3, Plano2, 1, 2);
                        break;
                    }
                case 6:
                    cout<<"GirarPiso 6"<<endl;
                    if(PrecalcularPlanos(6)==false)
                    {
                        cout<<"no se puede girar"<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"se puede girar"<<endl;
                        rotarMatrizInversa(Plano3);
                        funcionTransform(Piso1, Plano3, 0, 2);
                        funcionTransform(Piso2, Plano3, 0, 1);
                        funcionTransform(Piso3, Plano3, 0, 0);

                        funcionTransformGiro(Lado1, Plano3, 0, 2);
                        funcionTransformGiro(Lado2, Plano3, 0, 1);
                        funcionTransformGiro(Lado3, Plano3, 0, 0);
                        break;
                    }
                default:
                    break;
            }
        }

        void GirarLado(int condicion) 
        {
            switch (condicion) 
            {

                case 1:

                    rotarMatriz(Lado1);
                    funcionTransformGiroB(Piso1, Lado1, 0, 0);
                    funcionTransformGiroB(Piso2, Lado1, 0, 1);
                    funcionTransformGiroB(Piso3, Lado1, 0, 2);
                    funcionTransformGiro(Plano1, Lado1, 0, 0);
                    funcionTransformGiro(Plano2, Lado1, 0, 1);
                    funcionTransformGiro(Plano3, Lado1, 0, 2);
                    break;
                case 2:
                    
                    rotarMatriz(Lado2);
                    funcionTransformGiroB(Piso1, Lado2, 1, 0);
                    funcionTransformGiroB(Piso2, Lado2, 1, 1);
                    funcionTransformGiroB(Piso3, Lado2, 1, 2);
                    funcionTransformGiro(Plano1, Lado2, 1, 0);
                    funcionTransformGiro(Plano2, Lado2, 1, 1);
                    funcionTransformGiro(Plano3, Lado2, 1, 2);
                    break;
                    
                case 3:
                    rotarMatriz(Lado3);
                    funcionTransformGiroB(Piso1, Lado2, 2, 0);
                    funcionTransformGiroB(Piso2, Lado2, 2, 1);
                    funcionTransformGiroB(Piso3, Lado2, 2, 2);
                    funcionTransformGiro(Plano1, Lado2, 2, 0);
                    funcionTransformGiro(Plano2, Lado2, 2, 1);
                    funcionTransformGiro(Plano3, Lado2, 2, 2);
                    break;
                case 4:
                    rotarMatrizInversa(Lado1);
                    funcionTransformGiroB(Piso1, Lado1, 0, 0);
                    funcionTransformGiroB(Piso2, Lado1, 0, 1);
                    funcionTransformGiroB(Piso3, Lado1, 0, 2);
                    funcionTransformGiro(Plano1, Lado1, 0, 0);
                    funcionTransformGiro(Plano2, Lado1, 0, 1);
                    funcionTransformGiro(Plano3, Lado1, 0, 2);
                    break;
                case 5:
                    rotarMatrizInversa(Lado2);
                    funcionTransformGiroB(Piso1, Lado2, 1, 0);
                    funcionTransformGiroB(Piso2, Lado2, 1, 1);
                    funcionTransformGiroB(Piso3, Lado2, 1, 2);
                    funcionTransformGiro(Plano1, Lado2, 1, 0);
                    funcionTransformGiro(Plano2, Lado2, 1, 1);
                    funcionTransformGiro(Plano3, Lado2, 1, 2);
                    break;
                case 6:
                    rotarMatrizInversa(Lado3);
                    funcionTransformGiroB(Piso1, Lado3, 2, 0);
                    funcionTransformGiroB(Piso2, Lado3, 2, 1);
                    funcionTransformGiroB(Piso3, Lado3, 2, 2);
                    funcionTransformGiro(Plano1, Lado3, 2, 0);
                    funcionTransformGiro(Plano2, Lado3, 2, 1);
                    funcionTransformGiro(Plano3, Lado3, 2, 2);
                    break;
                default:
                    break;
            }
        }

        void llenarDatos(int posicion)
        {
            float* vertices = new float[24] {
                //primer cuadrado
                -0.107f,-0.313f,-0.311f,//0
                -0.107f,-0.113f,-0.311f,//1
                -0.307f,-0.113f,-0.311f,//3
                -0.307f,-0.313f,-0.311f,//2
                
                -0.107f,-0.313f,-0.11f,//4
                -0.107f,-0.113f,-0.11f,//5
                -0.307f,-0.313f,-0.11f,//6
                -0.307f,-0.113f,-0.11f//7
            };
            unsigned int* indices = new unsigned int[12] {
                0, 1, 2, 2, 3, 1, 4, 5, 6, 6, 7, 5
            };

            Cubos[posicion] = std::make_pair(vertices, indices);
        }
        void imprimirCubos()
        {
            for (const auto& elemento : Cubos)
            {
                int clave = elemento.first;
                const auto& datos = elemento.second;
                const float* vertices = datos.first;
                const unsigned int* indices = datos.second;

                std::cout << "Cubo " << clave << ":" << std::endl;
                std::cout << "Vertices: ";
                for (int i = 0; i < 24; ++i)
                {
                    std::cout << vertices[i] << "f, ";
                }
                std::cout << std::endl;
                /*
                std::cout << "Indices: ";
                for (int i = 0; i < 12; ++i)
                {
                    std::cout << indices[i] << " ";
                }
                std::cout << std::endl << std::endl;*/
            }
        }
        void imprimirEstructura(std::map<int, std::pair<float*, unsigned int*>> Cubos)
        {
            cout << "Imprimiendo estructura" << endl;
            for (const auto& elemento : Cubos)
            {
                int clave = elemento.first;
                const auto& datos = elemento.second;
                const float* vertices = datos.first;
                const unsigned int* indices = datos.second;

                std::cout << "Cubo " << clave << ":" << std::endl;
                std::cout << "Vertices: ";
                for (int i = 0; i < 24; ++i)
                {
                    std::cout << vertices[i] << " ";
                }
                std::cout << std::endl;
                /*
                std::cout << "Indices: ";
                for (int i = 0; i < 12; ++i)
                {
                    std::cout << indices[i] << " ";
                }
                std::cout << std::endl << std::endl;*/
            }
        }
        void insertarElementos(int posicion)
        {
            for (int i = 0; i < posicion; ++i)
            {
                llenarDatos(i);
            }
        }
        std::map<int, std::pair<float*, unsigned int*>>& retornarCubos()
        {
            return Cubos;
        }
        void ordenarCubos()
        {
            //_________________________________________
            float MovimientoX = 0.21f;
            float MovimientoY = 0.0f;   
            float MovimientoYB = 0.21f;
            float MovimientoYC = 0.42f;
            //_________________________________________
            float Mov = 0.0f;
            float Mov2 = 0.0f;
            for (const auto& elemento : Cubos)
            {  
                int clave = elemento.first;
                const auto& datos = elemento.second;
                float* vertices = datos.first;
                const unsigned int* indices = datos.second;
                cout << "Cubo " << clave << ":" << endl;
                if (clave < 3)
                {
                    cout << "Movimiento en X :" <<Mov<< endl;
                    modificarTraslacion3D(vertices, 24, Mov, 0.0f, 0.0f);
                    Mov = Mov + MovimientoX;
                }
                else if (clave >= 3 && clave < 6)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == 0.0f)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 6 && clave < 9)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.0f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave>=9 && clave < 12)
                {
                    cout << "Movimiento en X" << Mov << endl;
                    if (Mov2 == MovimientoYC)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoY;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 12 && clave < 15)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == MovimientoY)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 15 && clave < 18)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.21f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if(clave >= 18 && clave < 21)
                {
                    cout << "Movimiento en X" << Mov << endl;
                    if (Mov2 == MovimientoYC)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoY;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 21 && clave < 24)
                {
                    cout << "Movimiento en Y" << Mov << endl;
                    if (Mov2 == MovimientoY)
                    {
                        Mov = 0.0f;
                        Mov2 =MovimientoYB;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                }
                else if (clave >= 24 && clave < 27)
                {
                    cout << "Movimiento en Z" << Mov << endl;
                    if (Mov2 == MovimientoYB)
                    {
                        Mov = 0.0f;
                        Mov2 = MovimientoYC;
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                    else
                    {
                        modificarTraslacion3D(vertices, 24, Mov, Mov2, 0.42f);
                        Mov = Mov + MovimientoX;
                    }
                }
            }
        }
        /*
        void AnimacionAutomatica(int Valor)
        {
            // aser un switch para los casos
            switch (Valor)
            {
                //Pisos
                //girar piso1
                case 1:
                    GirarPiso(1);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(1,true,Piso1);
                    }
                    break;
                //girar piso2
                case 2:
                    GirarPiso(2);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(2,true,Piso2);
                    }
                    break;
                //girar piso3
                case 3:
                    GirarPiso(3);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(3,true,Piso3);
                    }
                    break;
                //girar piso1 inverso
                case 4:
                    GirarPiso(4);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(4,true,Piso1);
                    }
                    break;
                //girar piso2 inverso
                case 5:
                    GirarPiso(5);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(5,true,Piso2);
                    }
                    break;
                //girar piso3 inverso
                case 6:
                    GirarPiso(6);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(6,true,Piso3);
                    }
                    break;
                //Planos
                //girar plano1
                case 7:
                    GirarPlano(1);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(1,false,Plano1);
                    }
                    break;
                //girar plano2
                case 8:
                    GirarPlano(2);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(2,false,Plano2);
                    }
                    break;
                //girar plano3
                case 9:
                    GirarPlano(3);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(3,false,Plano3);
                    }
                    break;
                //girar plano1 inverso
                case 10:
                    GirarPlano(4);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(4,false,Plano1);
                    }
                    break;
                //girar plano2 inverso
                case 11:
                    GirarPlano(5);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(5,false,Plano2);
                    }
                    break;
                //girar plano3 inverso
                case 12:
                    GirarPlano(6);
                    for(int mover=0;mover<90;mover++)
                    {
                        realizarAnimacion(6,false,Plano3);
                    }
                    break;
                default:
                    break;  
            }
        }*/

        void RandomCubo()
        {
            srand(static_cast<unsigned int>(time(nullptr)));
            for(int movimientos=0;movimientos<5;movimientos++)
            {
                int numeroAleatorio = (rand() % 12) + 1;
                agregarElemento(numeroAleatorio);
            }
        }
        void VectorllamadaTraslacion(const std::vector<int>& vector,string opcion,float movimientoAtrasladar) 
        {
            for (int i = 0; i < vector.size(); i++) 
            {
                int temp = vector[i];
                float* VerticesTemp = obtenerVertices(temp);
                if (opcion == "X") {
                modificarTraslacion3D(VerticesTemp, 24,  movimientoAtrasladar, 0.0f, 0.0f);
                }
                else if (opcion == "Y") {
                    modificarTraslacion3D(VerticesTemp, 24,  0.0f, movimientoAtrasladar, 0.0f);
                }
                else if (opcion == "Z") {
                    modificarTraslacion3D(VerticesTemp, 24,  0.0f, 0.0f, movimientoAtrasladar);
                }
                modificarVertices(temp, VerticesTemp);
            }
        }
        void VectorllamadaRotacion(const std::vector<int>& vector,string opcion,float movimientoAtrasladar) 
        {
            for (int i = 0; i < vector.size(); i++) 
            {
                int temp = vector[i];
                float* VerticesTemp = obtenerVertices(temp);
                ModificarRotacion3D(VerticesTemp, 24,opcion, movimientoAtrasladar);
            }
        }
        void VectorllamadaEscala(const std::vector<int>& vector,float movimientoAtrasladar) 
        {
            for (int i = 0; i < vector.size(); i++) 
            {
                int temp = vector[i];
                float* VerticesTemp = obtenerVertices(temp);
                ModificarEscala3D(VerticesTemp, 24,movimientoAtrasladar);
            }
        }
        void VectorllamadaEscalaRotacion(const std::vector<int>& vector,float movimientoAtrasladar,string opcion,float ANguloGiro) 
        {
            for (int i = 0; i < vector.size(); i++) 
            {
                int temp = vector[i];
                float* VerticesTemp = obtenerVertices(temp);
                ModificarEscalaRotacion3D(VerticesTemp, 24,movimientoAtrasladar,opcion,ANguloGiro);
            }
        }
        void VectorllamadaTrasladarRotacion(const std::vector<int>& vector,float X,float Y,float Z,string opcion,float ANguloGiro) 
        {
            for (int i = 0; i < vector.size(); i++) 
            {
                int temp = vector[i];
                float* VerticesTemp = obtenerVertices(temp);
                modificarRotacionTraslacion(VerticesTemp, 24,X,Y,Z,opcion,ANguloGiro);
            }
        }
        //void modificarRotacionTraslacion(float* vertices2, int numVertices, float trasladarX, float trasladarY, float trasladarZ,string opcionRotacion,float angulo)

};
