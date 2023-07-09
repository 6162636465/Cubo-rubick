//javierAlvarezReyes
//Pablo cesar Yucra
#ifndef GLFW_INCLUDE_NONE
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#endif
#ifndef GLAD_GL_IMPLEMENTATION
#define GLAD_GL_IMPLEMENTATION
#include <glad/gl.h>
#endif
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "shader_m.h"
#include "Cubo.h"
#include "Camara.h"
#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window,Cubo* cubo);
// Compilar y enlazar los shaders
const char* vertexShaderSource = R"(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 view;
    uniform mat4 projection;
    out vec3 ourColor; // Variable ourColor agregada
    void main()
    {
        gl_Position = projection * view * vec4(aPos, 1.0);
        ourColor = aPos; // Ejemplo de asignación de ourColor basado en la posición del vértice
    }
)";

const char* fragmentShaderSource = R"(
    #version 330 core
    uniform vec3 triangleColor; // Nueva variable para el color 
    in vec3 ourColor; // Variable ourColor
    out vec4 FragColor;
    void main()
    {
        FragColor = vec4(triangleColor, 1.0);
    }
)";



const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

//Almacenamiento que se seteara con la estructura cubo
std::map<int, std::pair<float*, unsigned int*>> VerticesDeLosCubos;
//condicional Rotacion
bool CuboRotacion = false;
bool CuboLados=false;

int Rotacion=0;
int Opcion=0;
bool RotacionPiso=false;
bool RotacionPlano=false;
bool RotacionLados=false;


bool AnimacionTerminada=true;

bool AnimacionInicial=false;
bool AnimacionInicialTerminada=false;
float condicional=0.0f;

int Kapretado1vez=false;


int RotacionCount=0;
int TraslacionCount=0;
bool RotacionReversaActivar=false;

bool RotarBoll=false;
bool abajoRE=false;
bool ReversaAnimacion=false;
bool AnimacionReversaTerminada=false;

//_______________________________________
bool activadoUnavezZoLAMENTE=false;
bool activadoUnavez2=false;
//____________________________________________________________camada
int PlanoA[3][3];
int PlanoB[3][3];
int PlanoC[3][3];
int PisoA[3][3];
int PisoB[3][3];
int PisoC[3][3];
int LadoA[3][3];
int LadoB[3][3];
int LadoC[3][3];
//____________________________________________________________camada_Piramide
vector<int> piramide1= {0,1,2,3,4,5,9,10,11,18,19,20};
vector<int> piramide2= {14, 13,12, 23,22,21,8,6};
vector<int> piramide3= {7,16,17,15,25};
vector<int> piramide4= {26,24};

//________________________________________________________Cola de animacion__________
vector<int>ColaAnimacion;
vector<int>ListaMovimientos;
//________________________________________________________________________________________________________________________
//colores
// Rojo
float triangleColor[] = { 1.0f, 0.0f, 0.0f };

// Verde
float triangleColor2[] = { 0.0f, 1.0f, 0.0f };

// Azul
float triangleColor3[] = { 0.0f, 0.0f, 1.0f };

// Amarillo
float triangleColor4[] = { 1.0f, 1.0f, 0.0f };

// Blanco
float triangleColor5[] = { 1.0f, 1.0f, 1.0f };

// Morado
float triangleColor6[] = { 1.0f, 0.0f, 1.0f };

// Negro
float blackColor[] = { 0.0f, 0.0f, 0.0f };

//_________________________________________________________________________________________________________________________________
//_________________________________________________________________________________________________________________________________
//cara1
unsigned int indices1[] 
{
        0, 1, 2, 2, 3, 0
};
//cara2
unsigned int indices2[] 
{
        4, 5, 7, 7, 6, 4
};
//cara3
unsigned int indices3[] 
{
        0, 1, 5, 5, 4, 0
};
//cara4
unsigned int indices4[] 
{
        2, 3, 7, 7, 6, 3
};
//cara5
unsigned int indices5[] 
{
        0, 4, 6, 6, 3, 0
};
//cara6
unsigned int indices6[] 
{
        1, 2, 7, 7, 5, 1
};

//Lineas
unsigned int indices7[] 
{
        0, 1, 2, 3, 0, 4, 1, 5, 2, 6, 3, 7, 4, 5, 6, 7
};
//______________________________________________________________________________
void imprimirPila(std::stack<int> pila) {
    while (!pila.empty()) {
        std::cout << pila.top() << " ";
        pila.pop();
    }
    std::cout << std::endl;
}

std::vector<int> pegarDePilaAVector(std::stack<int>& pila) {
    std::vector<int> vectorResultado;

    while (!pila.empty()) {
        vectorResultado.insert(vectorResultado.begin(), pila.top());
        pila.pop();
    }

    return vectorResultado;
}

void invertirPila(std::stack<int>& pila) {
    std::stack<int> pilaAuxiliar;

    while (!pila.empty()) {
        pilaAuxiliar.push(pila.top());
        pila.pop();
    }

    pila = pilaAuxiliar;
}
void AnimacionAutomatica(int Valor, Cubo* cubo)
    {
        // aser un switch para los casos
        if(AnimacionTerminada==true)
        {
            switch (Valor)
            {
                //Pisos
                //girar piso1
                case 1:
                    Opcion=1;
                    cubo->GirarPiso(1);
                    RotacionPiso=true;
                    RotacionPlano=false;
                    AnimacionTerminada=false;
                    break;
                //girar piso2
                case 2:
                    Opcion=2;
                    RotacionPiso=true;
                    RotacionPlano=false;
                    cubo->GirarPiso(2);
                    AnimacionTerminada=false;
                    break;
                //girar piso3
                case 3:
                    Opcion=3;
                    RotacionPiso=true;
                    RotacionPlano=false;
                    cubo->GirarPiso(3);
                    AnimacionTerminada=false;
                    break;
                //girar piso1 inverso
                case 4:
                    Opcion=4;
                    RotacionPiso=true;
                    RotacionPlano=false;
                    cubo->GirarPiso(4);
                    AnimacionTerminada=false;
                    break;
                //girar piso2 inverso
                case 5:
                    Opcion=5;
                    RotacionPiso=true;
                    RotacionPlano=false;
                    cubo->GirarPiso(5);
                    AnimacionTerminada=false;
                    break;
                //girar piso3 inverso
                case 6:
                    Opcion=6;
                    RotacionPiso=true;
                    RotacionPlano=false;
                    cubo->GirarPiso(6);
                    AnimacionTerminada=false;
                    break;
                //Planos
                //girar plano1
                case 7:
                    Opcion=1;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(1);
                    AnimacionTerminada=false;
                    break;
                //girar plano2
                case 8:
                    Opcion=2;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(2);
                    AnimacionTerminada=false;
                    break;
                //girar plano3
                case 9:
                    Opcion=3;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(3);
                    AnimacionTerminada=false;
                    break;
                //girar plano1 inverso
                case 10:
                    Opcion=4;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(4);
                    AnimacionTerminada=false;
                    break;
                //girar plano2 inverso
                case 11:
                    Opcion=5;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(5);
                    AnimacionTerminada=false;
                    break;
                //girar plano3 inverso
                case 12:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarPlano(6);
                    AnimacionTerminada=false;
                    break;
                case 13:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(1);
                    AnimacionTerminada=false;
                    break;
                case 14:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(2);
                    AnimacionTerminada=false;
                    break;
                case 15:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(3);
                    AnimacionTerminada=false;
                    break;
                case 16:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(4);
                    AnimacionTerminada=false;
                    break;
                case 17:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(5);
                    AnimacionTerminada=false;
                    break;
                case 18:
                    Opcion=6;
                    RotacionPiso=false;
                    RotacionPlano=true;
                    cubo->GirarLado(6);
                    AnimacionTerminada=false;
                    break;
                default:
                    break;  
            }
        }
    }
//______________________________________________________________________________

void actualizarVertices(const std::map<int, std::pair<float*, unsigned int*>>& Cubos, unsigned int VAOs[200], unsigned int VBOs[200], unsigned int EBOs[200])
{
    //156
    int index = 0;
    for (const auto& elemento : Cubos)
    {
        const auto& datos = elemento.second;
        const float* vertices = datos.first;

        // cara 1
        glBindVertexArray(VAOs[index*7]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices1), indices1, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 2
        glBindVertexArray(VAOs[index*7+1]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+1]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+1]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices2), indices2, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 3
        glBindVertexArray(VAOs[index*7+2]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+2]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+2]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices3), indices3, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 4
        glBindVertexArray(VAOs[index*7+3]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+3]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+3]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices4), indices4, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 5
        glBindVertexArray(VAOs[index*7+4]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+4]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+4]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices5), indices5, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // cara 6
        glBindVertexArray(VAOs[index*7+5]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+5]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+5]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices6), indices6, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // Lineas
        glBindVertexArray(VAOs[index*7+6]);
        glBindBuffer(GL_ARRAY_BUFFER, VBOs[index*7+6]);
        glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBOs[index*7+6]);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices7), indices7, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        index=index+1;
    }
}

void agregarElementoListaMov( int elemento) {
    ListaMovimientos.push_back(elemento);
}
void PintarCarasCubo(const std::map<int, std::pair<float*, unsigned int*>>& Cubos, unsigned int VAOs[200], unsigned int shaderProgram)
{
    int index = 0;
    for (const auto& elemento : Cubos)
    {
        const auto& datos = elemento.second;
        const float* vertices = datos.first;

        // Cara roja
        glBindVertexArray(VAOs[index*7]);
        unsigned int triangleColorLoc = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc, triangleColor[0], triangleColor[1], triangleColor[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara verde
        glBindVertexArray(VAOs[index*7+1]);
        unsigned int triangleColorLoc2 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc2, triangleColor2[0], triangleColor2[1], triangleColor2[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara azul
        glBindVertexArray(VAOs[index*7+2]);
        unsigned int triangleColorLoc3 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc3, triangleColor3[0], triangleColor3[1], triangleColor3[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        
        // Cara amarilla
        glBindVertexArray(VAOs[index*7+3]);
        unsigned int triangleColorLoc4 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc4, triangleColor4[0], triangleColor4[1], triangleColor4[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        // Cara blanca
        glBindVertexArray(VAOs[index*7+4]);
        unsigned int triangleColorLoc5 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc5, triangleColor5[0], triangleColor5[1], triangleColor5[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);

        // Cara morada
        glBindVertexArray(VAOs[index*7+5]);
        unsigned int triangleColorLoc6 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc6, triangleColor6[0], triangleColor6[1], triangleColor6[2]);
        glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
        /*
        // Líneas
        glBindVertexArray(VAOs[index*7+6]);
        unsigned int triangleColorLoc7 = glGetUniformLocation(shaderProgram, "triangleColor");
        glUniform3f(triangleColorLoc7, blackColor[0], blackColor[1], blackColor[2]);
        glLineWidth(9.0f);
        glDrawElements(GL_LINES, 24, GL_UNSIGNED_INT, 0);
        */
        // Restaurar el programa de shaders
        glUseProgram(shaderProgram);
        index=index+1;
    }
}
vector<int> invertirVector(std::vector<int> last)
{
    std::vector<int> invertido;

    for (auto it = last.rbegin(); it != last.rend(); ++it) {
        invertido.push_back(*it);
    }

    return invertido;
}
void imprimirVectorNativo(const std::vector<int>& miVector) {
    for (const auto& elemento : miVector) {
        std::cout << elemento << " ";
    }
    std::cout << std::endl;
}
std::stack<int> pegarEnPila(const std::vector<int>& vector) {
    std::stack<int> pila;

    for (int elemento : vector) {
        pila.push(elemento);
    }

    return pila;
}
CamaraLast camera;

int main()
{
    // Inicializar GLFW y configurar la ventana
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Camera Example", nullptr, nullptr);
    if (window == nullptr)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Cargar GLAD
    if (!gladLoadGL(glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    unsigned int vertexShader, fragmentShader, shaderProgram;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    shaderProgram = glCreateProgram();

    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);

    glCompileShader(vertexShader);
    glCompileShader(fragmentShader);

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);



    unsigned int VBOs[200], VAOs[200], EBOs[200];
    glGenVertexArrays(200, VAOs); // we can also generate multiple VAOs or buffers at the same time
    glGenBuffers(200, VBOs);
    glGenBuffers(200, EBOs);
    


// crear y vincular los VBOs para el primer triangulo

    Cubo cubo;
    cubo.insertarElementos(27);
    //cubo.imprimirCubos();
    cout << "_________________________________________________________________________________________________" << endl;
    cubo.ordenarCubos();
    //cubo.imprimirCubos();
    VerticesDeLosCubos= cubo.retornarCubos();
    //cubo.sumarCondicion(25);
    actualizarVertices(VerticesDeLosCubos, VAOs, VBOs, EBOs);
    

    // Variable para controlar la velocidad del movimiento de la cámara
    float cameraSpeed = 0.05f;
    bool unaPrueba=true;
    int EscalarPrueba=0;

    

    // Habilitar el test de profundidad
    glEnable(GL_DEPTH_TEST);
    cout << "*********************************************************************************************************************" << endl;
    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        //SETEAR MATRICES
        cubo.setPiso1(PisoA);
        cubo.setPiso2(PisoB);
        cubo.setPiso3(PisoC);
        cubo.setPlano1(PlanoA);
        cubo.setPlano2(PlanoB);
        cubo.setPlano3(PlanoC);
        cubo.setLadoA(LadoA);
        cubo.setLadoB(LadoB);
        cubo.setLadoC(LadoC);
        //______________________________________
        processInput(window,&cubo);
        VerticesDeLosCubos= cubo.retornarCubos();
        actualizarVertices(VerticesDeLosCubos, VAOs, VBOs, EBOs);
        if (!ColaAnimacion.empty()) 
        {
            if(AnimacionTerminada==true)
            {
                int temp = ColaAnimacion.front(); // Obtener el primer número y almacenarlo en una variable temporal
                ColaAnimacion.erase(ColaAnimacion.begin());
                AnimacionAutomatica(temp,&cubo);
                cout<<"entro"<<temp<<endl;
            }
        }
        if(Opcion>0)
        {
            if(Opcion==1 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(1,true,PisoA,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==1 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(1,false,PlanoA,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==1 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(1,false,LadoA,CuboLados);
                //cout<<Rotacion<<endl;
                Rotacion=Rotacion+1;
            }
            else if(Opcion==2 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(2,true,PisoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==2 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(2,false,PlanoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==2 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(2,false,LadoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==3 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(3,true,PisoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==3 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(3,false,PlanoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==3 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(3,false,LadoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==4 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(4,true,PisoA,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==4 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(4,false,PlanoA,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==4 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(4,false,LadoA,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==5 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(5,true,PisoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==5 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(5,false,PlanoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==5 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(5,false,LadoB,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==6 && RotacionPiso==true && RotacionPlano==false &&Rotacion<=90)
            {
                cubo.realizarAnimacion(6,true,PisoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==6 && RotacionPiso==false && RotacionPlano==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(6,false,PlanoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if(Opcion==6 && RotacionLados==true &&Rotacion<=90)
            {
                cubo.realizarAnimacion(6,false,LadoC,CuboLados);
                Rotacion=Rotacion+1;
            }
            else if (Rotacion>=90)
            {
                Opcion==0;
                Rotacion=0;
                RotacionPiso = false;
                RotacionPlano = false;
                RotacionLados = false;
                AnimacionTerminada=true;
                cout<<"*********************"<<endl;
                //cubo.ImprimirTodasLasMatrices();
                cout<<"*********PosicionSet************"<<endl;
                //cubo.SetearPosiciones();
                cout<<"*********************"<<endl;
            }

        }
        //___________________________________EN_ESTA_PARTE_SE _REALIZARA_LA_ANIMACION_INICIAL______________________
        if(AnimacionInicial==true && AnimacionInicialTerminada==false)
        {
            if(condicional<0.21f)
            {
                //ID/MOV/DIS
                //Capa1
                cubo.moverUnCubito(3,"Y",-0.01f);
                cubo.moverUnCubito(4,"Y",-0.01f);
                cubo.moverUnCubito(5,"Y",-0.01f);

                cubo.moverUnCubito(4,"Z",-0.01f);

                cubo.moverUnCubito(0,"Z",0.01f);
                cubo.moverUnCubito(1,"Z",0.01f);
                cubo.moverUnCubito(2,"Z",0.01f);

                cubo.moverUnCubito(1,"Z",0.01f);

                cubo.moverUnCubito(0,"X",-0.01f);
                cubo.moverUnCubito(2,"X",0.01f);

                cubo.moverUnCubito(9,"Z",0.01f);
                cubo.moverUnCubito(10,"Z",0.01f);
                cubo.moverUnCubito(11,"Z",0.01f);

                cubo.moverUnCubito(9,"X",-0.01f);
                cubo.moverUnCubito(11,"X",0.01f);

                cubo.moverUnCubito(18,"Z",0.01f);
                cubo.moverUnCubito(19,"Z",0.01f);
                cubo.moverUnCubito(20,"Z",0.01f);
                //__________capa2________________
                cubo.moverUnCubito(6,"Y",-0.01f);
                cubo.moverUnCubito(8,"Y",-0.01f);
                cubo.moverUnCubito(6,"Z",0.01f);
                cubo.moverUnCubito(8,"Z",0.01f);
                cubo.moverUnCubito(13,"Z",-0.01f);

                cubo.moverUnCubito(14,"X",0.01f);
                cubo.moverUnCubito(12,"X",-0.01f);

                cubo.moverUnCubito(14,"Z",0.01f);
                cubo.moverUnCubito(12,"Z",0.01f);

                cubo.moverUnCubito(23,"Z",0.01f);
                cubo.moverUnCubito(21,"Z",0.01f);

                cubo.moverUnCubito(22,"Z",0.01f);
                //__________capa3________________
                cubo.moverUnCubito(7,"Z",0.01f);
                cubo.moverUnCubito(16,"Z",0.01f);
                cubo.moverUnCubito(17,"Z",0.01f);
                cubo.moverUnCubito(15,"Z",0.01f);
                cubo.moverUnCubito(25,"Z",0.01f);
                //__________capa4________________
                cubo.moverUnCubito(26,"X",-0.01f);
                cubo.moverUnCubito(24,"X",0.01f);

                cubo.moverUnCubito(26,"Y",0.01f);
                cubo.moverUnCubito(24,"Y",0.01f);
                cubo.moverUnCubito(24,"Y",0.01f);
    
            }
            else if(condicional<0.42f)
            {
                //__________capa1________________
                cubo.moverUnCubito(1,"Z",0.01f);
                cubo.moverUnCubito(10,"Z",0.01f);

                cubo.moverUnCubito(1,"X",-0.01f);
                cubo.moverUnCubito(10,"X",0.01f);

                cubo.moverUnCubito(9,"X",-0.01f);
                cubo.moverUnCubito(11,"X",0.01f);

                cubo.moverUnCubito(18,"X",-0.01f);
                cubo.moverUnCubito(19,"Z",0.01f);
                cubo.moverUnCubito(20,"X",0.01f);
                //__________capa2________________
                cubo.moverUnCubito(22,"Z",0.01f);
                //__________capa3________________

                
            }
            else if(condicional<0.63f)
            {
                //__________capa1________________
                cubo.moverUnCubito(1,"Z",0.01f);
                cubo.moverUnCubito(10,"Z",0.01f);
                cubo.moverUnCubito(19,"Z",0.01f);
                //__________capa2________________

            }
            
            else if(condicional>0.63f)
            {
                AnimacionInicialTerminada=true;
                activadoUnavezZoLAMENTE=true;
            }
            //cout<<"ga:"<<condicional<<endl;
            condicional=condicional+0.01f;
        }
        //terminado la animacion mover al centro
        else if(AnimacionInicialTerminada==true && activadoUnavezZoLAMENTE== true)
        {
            activadoUnavezZoLAMENTE=false;
            cout<<"condicional:"<<condicional<<endl;
            cout<<"Mover una vez terminado"<<endl;
            cubo.VectorllamadaTraslacion(piramide1,"Z",-0.21f);
            cubo.VectorllamadaTraslacion(piramide2,"Z",-0.21f);
            cubo.VectorllamadaTraslacion(piramide3,"Z",-0.21f);
            cubo.VectorllamadaTraslacion(piramide4,"Z",-0.21f);
            activadoUnavez2=true;
        }

        if(activadoUnavez2==true )
        {
            if(RotacionCount <=1800 && RotarBoll==false)
            {
                cubo.VectorllamadaRotacion(piramide1,"Y",-0.2f);
                //cubo.VectorllamadaEscala(piramide1,-0.08);
                cubo.VectorllamadaRotacion(piramide2,"Y",0.2f);
                //void VectorllamadaTrasladarRotacion(const std::vector<int>& vector,float X,float Y,float Z,string opcion,float ANguloGiro) 
                cubo.VectorllamadaRotacion(piramide3,"Y",-0.2f);
                //cubo.VectorllamadaEscala(piramide3,0.00001);                           
                cubo.VectorllamadaRotacion(piramide4,"Y",0.2f);
                RotacionCount=RotacionCount+1;
            }
            else if(RotarBoll==true && TraslacionCount<=20)
            {
                if (abajoRE==false)
                {
                    TraslacionCount=TraslacionCount+1;
                    cubo.VectorllamadaTraslacion(piramide1,"Y", 0.08f);
                    cubo.VectorllamadaTraslacion(piramide2,"Y", 0.04f);
                    cubo.VectorllamadaTraslacion(piramide3,"Y",-0.005f);
                    cubo.VectorllamadaTraslacion(piramide4,"Y",-0.04f);
                    if(TraslacionCount==10)
                    {
                        RotacionCount=0;
                        RotarBoll=false;
                        TraslacionCount=0;
                        abajoRE=true;
                    }

                }
                else if(abajoRE==true)
                {
                    TraslacionCount=TraslacionCount+1;
                    cubo.VectorllamadaTraslacion(piramide1,"Y", -0.08f);
                    cubo.VectorllamadaTraslacion(piramide2,"Y", -0.04f);
                    cubo.VectorllamadaTraslacion(piramide3,"Y",0.005f);
                    cubo.VectorllamadaTraslacion(piramide4,"Y",0.04f);
                    if(TraslacionCount==10)
                    {
                        RotacionCount=0;
                        RotarBoll=false;
                        TraslacionCount=0;
                        abajoRE=false;
                    }
                }
            }
            else
            {
                RotarBoll=true;
                cout<<"asd"<<endl;
                TraslacionCount=TraslacionCount+1;
            }
            /*
            cubo.VectorllamadaTrasladarRotacion(piramide1,0.01f,0.0f,0.0f,"Y",-0.2f);
            cubo.VectorllamadaTrasladarRotacion(piramide2,0.01f,0.0f,0.0f,"Y",0.2f);
            cubo.VectorllamadaTrasladarRotacion(piramide3,0.01f,0.0f,0.0f,"Y",-0.2f);                          
            cubo.VectorllamadaTrasladarRotacion(piramide4,0.01f,0.0f,0.0f,"Y",0.2f);
            */
        }
        if(ReversaAnimacion==true)
        {
            //cout<<"entre Reversa Rotacion:"<<RotacionCount<<endl;
            if(RotacionCount>0)
            {
                //cout<<"entre anim:"<<endl;
                cubo.VectorllamadaRotacion(piramide1,"Y", 0.2f);
                cubo.VectorllamadaRotacion(piramide2,"Y",-0.2f); 
                cubo.VectorllamadaRotacion(piramide3,"Y", 0.2f);                         
                cubo.VectorllamadaRotacion(piramide4,"Y",-0.2f);
                RotacionCount=RotacionCount-1;
                if(RotacionCount==0 && abajoRE==false)
                {
                    cubo.SetearPosicionePiramide(PlanoA,PlanoB,PlanoC);
                    AnimacionReversaTerminada=true;
                    condicional=0;
                }
            }
            else if(abajoRE==true)
            {
                cubo.VectorllamadaTraslacion(piramide1,"Y", -0.08f);
                cubo.VectorllamadaTraslacion(piramide2,"Y", -0.04f);
                cubo.VectorllamadaTraslacion(piramide3,"Y",0.005f);
                cubo.VectorllamadaTraslacion(piramide4,"Y",0.04f);
                TraslacionCount=TraslacionCount+1;
                if(TraslacionCount==10)
                {
                    RotacionCount=0;
                    RotarBoll=false;
                    TraslacionCount=0;
                    abajoRE=false;
                    cubo.SetearPosicionePiramide(PlanoA,PlanoB,PlanoC);
                    AnimacionReversaTerminada=true;
                    condicional=0;
                }
            }
            else if(AnimacionReversaTerminada==true)
            {
                if (condicional < 0.21f) {
                    // Invertir el movimiento en el orden inverso
                    cubo.moverUnCubito(24, "Y", 0.01f);
                    cubo.moverUnCubito(24, "Y", 0.01f);
                    cubo.moverUnCubito(24, "Y", 0.01f);

                    cubo.moverUnCubito(0, "Z", -0.01f);
                    cubo.moverUnCubito(1, "Z", -0.01f);
                    cubo.moverUnCubito(2, "Z", -0.01f);

                    cubo.moverUnCubito(1, "Z", -0.01f);

                    cubo.moverUnCubito(0, "X", 0.01f);
                    cubo.moverUnCubito(2, "X", -0.01f);

                    cubo.moverUnCubito(9, "Z", -0.01f);
                    cubo.moverUnCubito(10, "Z", -0.01f);
                    cubo.moverUnCubito(11, "Z", -0.01f);

                    cubo.moverUnCubito(9, "X", 0.01f);
                    cubo.moverUnCubito(11, "X", -0.01f);

                    cubo.moverUnCubito(18, "Z", -0.01f);
                    cubo.moverUnCubito(19, "Z", -0.01f);
                    cubo.moverUnCubito(20, "Z", -0.01f);

                    cubo.moverUnCubito(6, "Y", 0.01f);
                    cubo.moverUnCubito(8, "Y", 0.01f);
                    cubo.moverUnCubito(6, "Z", -0.01f);
                    cubo.moverUnCubito(8, "Z", -0.01f);
                    cubo.moverUnCubito(13, "Z", 0.01f);

                    cubo.moverUnCubito(14, "X", -0.01f);
                    cubo.moverUnCubito(12, "X", 0.01f);

                    cubo.moverUnCubito(14, "Z", -0.01f);
                    cubo.moverUnCubito(12, "Z", -0.01f);

                    cubo.moverUnCubito(23, "Z", -0.01f);
                    cubo.moverUnCubito(21, "Z", -0.01f);

                    cubo.moverUnCubito(22, "Z", -0.01f);

                    cubo.moverUnCubito(7, "Z", -0.01f);
                    cubo.moverUnCubito(16, "Z", -0.01f);
                    cubo.moverUnCubito(17, "Z", -0.01f);
                    cubo.moverUnCubito(15, "Z", -0.01f);
                    cubo.moverUnCubito(25, "Z", -0.01f);

                    cubo.moverUnCubito(24, "X", 0.01f);
                    cubo.moverUnCubito(26, "X", -0.01f);

                    cubo.moverUnCubito(24, "Y", -0.01f);
                    cubo.moverUnCubito(26, "Y", -0.01f);
                    cubo.moverUnCubito(24, "Y", -0.01f);
                }

                else if (condicional < 0.42f) {
                    // Invertir el movimiento en el orden inverso
                    cubo.moverUnCubito(10, "X", -0.01f);
                    cubo.moverUnCubito(9, "X", 0.01f);

                    cubo.moverUnCubito(10, "Z", -0.01f);
                    cubo.moverUnCubito(1, "X", 0.01f);
                    cubo.moverUnCubito(10, "Z", -0.01f);
                    cubo.moverUnCubito(1, "Z", -0.01f);

                    cubo.moverUnCubito(11, "X", -0.01f);
                    cubo.moverUnCubito(9, "X", 0.01f);

                    cubo.moverUnCubito(20, "X", -0.01f);
                    cubo.moverUnCubito(19, "Z", -0.01f);
                    cubo.moverUnCubito(18, "X", 0.01f);

                    cubo.moverUnCubito(22, "Z", -0.01f);
                }

                else if (condicional < 0.63f) {
                    // Invertir el movimiento en el orden inverso
                    cubo.moverUnCubito(19, "Z", -0.01f);
                    cubo.moverUnCubito(10, "Z", -0.01f);
                    cubo.moverUnCubito(1, "Z", -0.01f);
                }
                else if(condicional < 0.64f)
                {

                    cubo.VectorllamadaTraslacion(piramide1,"Z",0.21f);
                    cubo.VectorllamadaTraslacion(piramide2,"Z",0.21f);
                    cubo.VectorllamadaTraslacion(piramide3,"Z",0.21f);
                    cubo.VectorllamadaTraslacion(piramide4,"Z",0.21f);
                    AnimacionReversaTerminada=false;
                    cubo.SetearPosiciones(PlanoA,PlanoB,PlanoC);
                }

                condicional=condicional+0.01f;
                cout<<"cont:"<<condicional<<endl;
            }

        }


        //_________________________________________________________________________________________________________

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


        camera.first(window);

        // Crear la matriz de vista
        
        glm::mat4 view = glm::lookAt(camera.cameraPos, camera.cameraPos + camera.cameraFront, camera.cameraUp);
        

        // Configurar las matrices de proyección y vista en los shaders
        
        glm::mat4 projection = glm::perspective(glm::radians(camera.fov), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
        
        if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
        {
            const float radius = 1.5f;
            float camX = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            view = glm::lookAt(glm::vec3(camX, 0.0, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        }

        if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        {
            const float radius = 1.5f;
            float camY = sin(glfwGetTime()) * radius;
            float camZ = cos(glfwGetTime()) * radius;
            view = glm::lookAt(glm::vec3(0.0, camY, camZ), glm::vec3(0.0, 0.0, 0.0), glm::vec3(0.0, 1.0, 0.0));
        }

        // Configurar las matrices de proyección y vista en los shaders
        glUseProgram(shaderProgram);

        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));


        // Dibujar el cubo

        PintarCarasCubo(VerticesDeLosCubos, VAOs, shaderProgram);

        // Intercambiar los buffers de color
        glfwSwapBuffers(window);

        // Verificar si se han activado eventos y llamar a las funciones de callback correspondientes
        glfwPollEvents();

    }


    // Terminar GLFW
    glfwTerminate();
    return 0;
}

// Función para manejar el cambio de tamaño de la ventana
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

// Función para manejar la entrada de teclado y llamada por puntero a la clase cubo
void processInput(GLFWwindow* window, Cubo* cubo)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
    camera.inputIfs(window);
    
    static bool qPresionado = false; // Variable de estado para la tecla Q
    static bool ePresionado = false; // Variable de estado para la tecla E
    static bool rPresionado = false;

    static bool tecla1Presionada = false; // Variable de estado para la tecla 1
    static bool tecla2Presionada = false; // Variable de estado para la tecla 2
    static bool tecla3Presionada = false; // Variable de estado para la tecla 3
    static bool tecla4Presionada = false; // Variable de estado para la tecla 4
    static bool tecla5Presionada = false; // Variable de estado para la tecla 5
    static bool tecla6Presionada = false; // Variable de estado para la tecla 6
    static bool tecla8Presionada = false; // Variable de estado para la tecla 8
    static bool tecla9Presionada = false; // Variable de estado para la tecla 9
    static bool teclaKPresionada = false; // Variable de estado para la tecla 9
    static bool tecla10Presionada = false; // Variable de estado para la tecla 9
    static bool teclaRPresionada = false;
    static bool tecla7Presionada = false;
    // ...

    // Condicional si apreta q
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && !qPresionado)
    {
        CuboRotacion = true;
        CuboLados = false;
        qPresionado = true;
    }

    // Condicional si apreta e
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && !ePresionado)
    {
        CuboRotacion = false;
        CuboLados = false;
        ePresionado = true;
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS && !rPresionado)
    {
        /*
        rPresionado = true;
        CuboRotacion = false;
        CuboLados = true;
        */
    }
    // Condicional si apreto 1
    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS && !tecla1Presionada)
    {
        tecla1Presionada = true;

        // Condicional si CuboRotacion es true llamar a GirarPiso y si es false llamar a GirarPlano
        if (CuboRotacion == true)
        {
            cout << "se apreto  1 Q" << endl;
            cubo->GirarPiso(1);
            Opcion=1;
            RotacionPiso=true;
            RotacionPlano=false;
            RotacionLados=false;
            agregarElementoListaMov(7);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  1 R" << endl;
            cubo->GirarLado(1);
            Opcion=1;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(13);

        }
        else
        {
            cout << "se apreto  1 E" << endl;
            Opcion=1;
            RotacionPiso=false;
            RotacionPlano=true;
            RotacionLados=false;
            cubo->GirarPlano(1);
            agregarElementoListaMov(1);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 2
    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS && !tecla2Presionada)
    {
        tecla2Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  2 Q" << endl;
            Opcion=2;
            RotacionPiso=true;
            RotacionPlano=false;
            RotacionLados=false;
            cubo->GirarPiso(2);
            agregarElementoListaMov(8);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  2 R" << endl;
            cubo->GirarLado(2);
            Opcion=2;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(14);

        }
        else
        {
            cout << "se apreto  2 E" << endl;
            Opcion=2;
            RotacionPiso=false;
            RotacionPlano=true;
            RotacionLados=false;
            cubo->GirarPlano(2);
            agregarElementoListaMov(2);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 3
    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS && !tecla3Presionada)
    {
        tecla3Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  3 Q" << endl;
            Opcion=3;
            RotacionPiso=true;
            RotacionPlano=false;
            RotacionLados=false;
            cubo->GirarPiso(3);
            agregarElementoListaMov(9);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  3 R" << endl;
            cubo->GirarLado(3);
            Opcion=3;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(15);

        }
        else
        {
            cout << "se apreto  3 E" << endl;
            Opcion=3;
            RotacionPiso=false;
            RotacionLados=false;
            RotacionPlano=true;
            cubo->GirarPlano(3);
            agregarElementoListaMov(3);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 4
    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS && !tecla4Presionada)
    {
        tecla4Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  4 Q" << endl;
            Opcion=4;
            RotacionPiso=true;
            RotacionLados=false;
            RotacionPlano=false;
            cubo->GirarPiso(4);
            agregarElementoListaMov(10);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  4 R" << endl;
            cubo->GirarLado(4);
            Opcion=4;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(16);

        }
        else
        {
            cout << "se apreto  4 E" << endl;
            Opcion=4;
            RotacionPiso=false;
            RotacionLados=false;
            RotacionPlano=true;
            cubo->GirarPlano(4);
            agregarElementoListaMov(4);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 5
    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_PRESS && !tecla5Presionada)
    {
        tecla5Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  5 Q" << endl;
            Opcion=5;
            RotacionPiso=true;
            RotacionLados=false;
            RotacionPlano=false;
            cubo->GirarPiso(5);
            agregarElementoListaMov(11);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  5 R" << endl;
            cubo->GirarLado(5);
            Opcion=5;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(17);

        }
        else
        {
            cout << "se apreto  5 E" << endl;
            Opcion=5;
            RotacionPiso=false;
            RotacionLados=false;
            RotacionPlano=true;
            cubo->GirarPlano(5);
            agregarElementoListaMov(5);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    // Condicional si apreto 6
    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_PRESS && !tecla6Presionada)
    {
        tecla6Presionada = true;

        if (CuboRotacion == true)
        {
            cout << "se apreto  6 Q" << endl;
            Opcion=6;
            RotacionPiso=true;
            RotacionLados=false;
            RotacionPlano=false;
            cubo->GirarPiso(6);
            agregarElementoListaMov(12);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
        else if(CuboLados == true)
        {
            cout << "se apreto  6 R" << endl;
            cubo->GirarLado(6);
            Opcion=6;
            RotacionPiso=false;
            RotacionPlano=false;
            RotacionLados=true;
            agregarElementoListaMov(18);

        }
        else
        {
            cout << "se apreto  6 E" << endl;
            Opcion=6;
            RotacionPiso=false;
            RotacionLados=false;
            RotacionPlano=true;
            cubo->GirarPlano(6);
            agregarElementoListaMov(6);
            //cubo->ImprimirTodasLasMatrices();
            //cubo->imprimirCubos();
        }
    }

    //condicion si apreto 7
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_PRESS && !tecla7Presionada)
    {
        /*
        std::string solve, scr;
        int am;
        Cube Cube1;
        //Default (Manually) Mode
		scr = "U2 L2 B2 D L2 R2 D B2 D F2 U B' R F2 U F' D' U' B' R' D2";
		std::cout << "Scramble: " << scr << '\n';
		Cube1.SetScramble(scr);
		Cube1.PrintCube();
		solve = SolveCube(Cube1, "Default");
		am = Cube1.SetScramble(solve);
		std::cout << "Moves: " << am << '\n';
		std::cout << "Solution: " << solve << '\n';
		Cube1.PrintCube();
		Cube1.PrintBoolIsSolved();*/
    }

    //condicional si apreto 9
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_PRESS && !tecla9Presionada)
    {
        tecla9Presionada= true;
        cubo->ImprimirTodasLasMatrices();
        cout<<"_____________________________________________________________"<<endl;
        cubo->imprimirCubos();
        cout<<"_____________________________________________________________"<<endl;
        imprimirVectorNativo(ListaMovimientos);
    }
    //condicional si apreta 8
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_PRESS && !tecla8Presionada)
    {
        tecla8Presionada= true;
        cubo->RandomCubo();
        ColaAnimacion=cubo->obtenerColaDeAnimacion();
        ListaMovimientos=ColaAnimacion;
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS && !teclaKPresionada)
    {
        teclaKPresionada= true;
        if(Kapretado1vez==false)
        {
            cout<<"Iniciar Animacion"<<endl;
            AnimacionInicial=true;
            Kapretado1vez=true;
            ReversaAnimacion=false;
        }
        else if(Kapretado1vez==true)
        {
            cout<<"reversa Animacion"<<endl;
            ReversaAnimacion=true;
            AnimacionInicial=false;
            AnimacionInicialTerminada=false;
            RotarBoll=false;
            activadoUnavez2=false;

        }
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS && !tecla10Presionada)
    {
        tecla10Presionada= true;
        stack<int> stackSolve = pegarEnPila(ListaMovimientos);
        stack<int> stackSolveLast;
        while(!stackSolve.empty())
        {
            if(stackSolve.top()==1 ||stackSolve.top()==2 ||stackSolve.top()==3 ||stackSolve.top()==7 ||stackSolve.top()==8 ||stackSolve.top()==9)
            {
                stackSolve.top()= stackSolve.top()+3;
                stackSolveLast.push(stackSolve.top());
            }
            else if(stackSolve.top()==4 ||stackSolve.top()==5 ||stackSolve.top()==6 ||stackSolve.top()==10 ||stackSolve.top()==11 ||stackSolve.top()==12)
            {
                stackSolve.top()= stackSolve.top()-3;
                stackSolveLast.push(stackSolve.top());
            }
            stackSolve.pop();
        }
        cout<<"_____________________________________________________________"<<endl;
        imprimirPila(stackSolveLast);
        cout<<"_____________________________________________________________"<<endl;
        imprimirVectorNativo(ColaAnimacion);

        invertirPila(stackSolveLast);
        vector<int> ColaAnimacion2=pegarDePilaAVector(stackSolveLast);
        ColaAnimacion=invertirVector(ColaAnimacion2);

        cout<<"_____________________________________________________________"<<endl;
        imprimirVectorNativo(ColaAnimacion);
    }

    // ...

    // Reiniciar el estado de las variables cuando se suelta la tecla correspondiente

    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_RELEASE)
    {
        qPresionado = false;
    }

    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_RELEASE)
    {
        ePresionado = false;
    }

    if (glfwGetKey(window, GLFW_KEY_1) == GLFW_RELEASE)
    {
        tecla1Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_2) == GLFW_RELEASE)
    {
        tecla2Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_3) == GLFW_RELEASE)
    {
        tecla3Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_4) == GLFW_RELEASE)
    {
        tecla4Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_5) == GLFW_RELEASE)
    {
        tecla5Presionada = false;
    }

    if (glfwGetKey(window, GLFW_KEY_6) == GLFW_RELEASE)
    {
        tecla6Presionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_8) == GLFW_RELEASE)
    {
        tecla8Presionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_9) == GLFW_RELEASE)
    {
        tecla9Presionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_K) == GLFW_RELEASE)
    {
        teclaKPresionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_RELEASE)
    {
        tecla10Presionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_7) == GLFW_RELEASE)
    {
        tecla7Presionada = false;
    }
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_RELEASE)
    {
        teclaRPresionada = false;
    }
}