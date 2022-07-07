#include <iostream>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;

///////////////////////////////////////   FUNCIONES DECLARADAS   ///////////////////////////////////////////////////////////

void Titulo(); //Para llamar al título.
void Bienvenida(string nom); //Para llamar el enunciado de la bienvenida.
int validarNombres(char num[]); //Para validar que los nombres no contengan números.
int validarNumeros(char num[]); //Para validar que los números no contengan letras.
void Generacion1(); //Genera los números aleatorios con un rango definido.
void Generacion2(); //Genera los números aleatorios con un rango definido por el sistema.

void FCFS(int A, int B, int NProcesos);
void SJF(char SJF1[][3], int NProcesos);
void Prioridad(char Prioridad1[][3], int NProcesos);
void RoundRobin(char RoundRobin1[][3], int NProcesos, int Quantum);

int main(){
    setlocale(LC_ALL, "Spanish"); //Idioma español.

    for(;;){
        //Variables para todo el programa

            //Variables de inicio.
            char nombre[20];
            string nombre2;

            //Variables para la opción de generación de algoritmos.
            char opc1[2];
            int opc2=0;

        do{
            Titulo();
            cout<<"Bienvenido señor usuario, por favor identifíquese con un nombre: ";
            cin>>nombre;
            nombre2=nombre;
            system("cls");
        }while(validarNombres(nombre));

        while(opc2<1 || opc2>2 || validarNumeros(opc1)){
            Titulo();
            Bienvenida(nombre2);
            cin>>opc1;
            opc2=atoi(opc1);
            system("cls");
        }

        if (opc2==1){
            do{
                Titulo();
                cout<<"\n¿Qué desea escoger señor "<<nombre2<<"?\n\n";
                cout<<"1. Asignar rangos de aleatoriedad.\n";
                cout<<"2. Rangos de aleatoriedad predeterminados.\n\n";
                cout<<"Opción: ";
                cin>>opc1;
                opc2=atoi(opc1);
                system("cls");
            }while(opc2<1 || opc2>2 || validarNumeros(opc1));

            if(opc2==1){
                Generacion1();
            }
            else{
                Generacion2();
            }

        }
        cout<<"Validó que no ingresaran letras y que el rango de opciones sea el correcto.\n";

        system("pause");
        system("cls");
    }
}

///////////////////////////////////////  FUNCIONES INICIALIZADAS //////////////////////////////////////////

void Titulo(){
    cout<<"\n                                                           ----------------------------------------------------\n";
    cout<<"                                                           |    PROGRAMA MULTI-ALGORITMOS DE PLANIFICACIÓN    |\n";
    cout<<"                                                           ----------------------------------------------------\n\n";
}

void Bienvenida(string nom){
    cout<<"Estimado "<<nom<<".\n";
    cout<<"\nMuchas gracias por utilizar nuestro software de Algoritmos, tenga en cuenta que pondremos a su disposición (4) algoritmos de planificación que son FCFS, SJF, Prioridad\n";
    cout<<"y Round Robin. A continuación te daremos a escoger (2) opciones, la primera consiste en generar los datos de manera aleatoria para los (4) algoritmos, definiendo los\n";
    cout<<"rangos de aleatoriedad para el # de procesos, tiempo de CPU, Prioridad, Quantum, y la segunda opción consiste en insertar la cantidad de # de procesos, tiempo de CPU,\n";
    cout<<"Prioridad, Quantum de manera manual.\n\n1. Generación aleatoria.\n2. Inserción manual.\n\nPor favor escoja una opción: ";
}

int validarNombres(char num[]){
    for (int i = 0; i < strlen(num); i++){
        if(isdigit(num[i]) ) {
            return 1;
        }
    }
    return 0;
}

int validarNumeros(char num[]){
    for (int i = 0; i < strlen(num); i++){
        if(!isdigit(num[i]) ) {
            return 1;
        }
    }
    return 0;
}

void FCFS(int A, int B, int NProcesos){
    int TiempoCPU[100];
    int TiempoDeEspera[100];
    TiempoDeEspera[0]=0;
    char NProcesos1[3];
    char TCPU1[6];
    int TCPU=0;
    int aux;
    float TiempoPromedioDeEspera=0;
    system("cls");
            for (int b=0;b<NProcesos;b++){
                for (int a=0;a<1;a++){
                    aux=B-A+1;
                    TCPU=A + rand()%aux;
                    if (b==0){
                        TiempoDeEspera[b]=0;
                    }else{
                        TiempoDeEspera[b]=TiempoDeEspera[b-1]+TiempoCPU[b-1];
                    }

                    TiempoCPU[b]=TCPU;
                }
            }

            for (int a=0;a<NProcesos;a++){
                TiempoPromedioDeEspera+=TiempoDeEspera[a];
                if(a==NProcesos-1){
                    TiempoPromedioDeEspera/=NProcesos;
                }
            }
            cout<<"\nEl tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
            cout<<"---------DIAGRAMA DE GANTT PARA FCFS---------\n\n";
            cout<<"       0 ms."<<endl;
            for(int a=0,b=0;a<NProcesos;a++){
                cout<<"       ^\n       |\n       P"<<a+1<<"\n       |\n       v"<<endl;
                b+=TiempoCPU[a];
                cout<<"       "<<b<<" ms."<<endl;
            }

            system("pause");
            system("cls");

};

void SJF(char SJF1[][3], int NProcesos){
    cout<<"Funciona FCFS";
};

void Prioridad(char Prioridad1[][3], int NProcesos){
    cout<<"Funciona FCFS";
};

void RoundRobin(char RoundRobin1[][3], int NProcesos, int Quantum){
    cout<<"Funciona RoundRobin";
};

void Generacion1(){
    //Variables necesarias
    char RangoA[2];
    int RangoA1;
    char RangoB[2];
    int RangoB1;
    int aux;
    int aux2;
    int NProcesos;
    int Quantum;
    char PaqueteDatos[2][2];

    do{
        Titulo();
        cout<<"\nInserte los rangos para la cantidad de procesos.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 20 procesos.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        RangoA1=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        RangoB1=atoi(RangoB);
        system("cls");
    }while(RangoA1>RangoB1 || RangoA1<=0 || RangoB1>20);

    aux=RangoB1-RangoA1 +1;
    NProcesos=RangoA1 + rand()%aux;
    cout<<NProcesos;

    do{
        Titulo();
        cout<<"\nInserte los rangos para los tiempos de CPU de un proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá asignar hasta un máximo de 20 milisegundos por proceso.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        RangoA1=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        RangoB1=atoi(RangoB);
        system("cls");
    }while(RangoA1>RangoB1 || RangoA1<=0 || RangoB1>20);

    aux=RangoB1-RangoA1 +1;
    aux2=RangoA1 + rand()%aux;
    cout<<aux2;


    do{
        Titulo();
        cout<<"\nInserte los rangos para la prioridad de un proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 10 prioridades.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        RangoA1=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        RangoB1=atoi(RangoB);
        system("cls");
    }while(RangoA1>RangoB1 || RangoA1<=0 || RangoB1>10);

    aux=RangoB1-RangoA1 +1;
    aux2=RangoA1 + rand()%aux;
    //cout<<NProcesos;
    FCFS(RangoA1,RangoB1,NProcesos);
};

void Generacion2(){
    cout<<"Nuevo cambio al código";
    cout<<"Un cambio más";
    cout<<"Hola";
};



