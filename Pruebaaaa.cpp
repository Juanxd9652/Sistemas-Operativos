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

void FCFS(int Paquete[][3], int NProcesos);
void SJF(int Paquete[][3], int NProcesos);
void Prioridad(int Paquete[][3], int NProcesos);
void RoundRobin(int Paquete[][3], int NProcesos, int Quantum);

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

void FCFS(int Paquete[][3], int NProcesos){
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
                    TCPU=Paquete[b][0];
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
            Titulo();
            cout<<"---------DIAGRAMA DE GANTT PARA FCFS---------\n\n";
            cout<<"       0 ms."<<endl;
            for(int a=0,b=0;a<NProcesos;a++){
                cout<<"       ^\n       |\n       P"<<a+1<<"\n       |\n       v"<<endl;
                b+=TiempoCPU[a];
                cout<<"       "<<b<<" ms."<<endl;
            }
            cout<<"\nEl tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
            system("pause");
            system("cls");

};

void SJF(int SJF1[][3], int NProcesos){
    cout<<"Funciona FCFS";
};

void Prioridad(int Prioridad1[][3], int NProcesos){
    cout<<"Funciona FCFS";
};

void RoundRobin(int RoundRobin1[][3], int NProcesos, int Quantum){
    cout<<"Funciona RoundRobin";
};

void Generacion1(){

    //Variables necesarias

    char RangoA[2];
    char RangoB[2];
    int PaqueteDatos[20][3];

        //Variables para # Procesos

        int P_A;
        int P_B;
        int auxP;
        int NProcesos;

        //Variables para T CPU

        int T_A;
        int T_B;
        int auxT;

        //Variables para Prioridad

        int Pr_A;
        int Pr_B;
        int auxPr;

        //Variables para Quantum

        int Q_A;
        int Q_B;
        int Quantum;

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte los rangos para la cantidad de procesos.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 20 procesos.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        P_A=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        P_B=atoi(RangoB);
    }while(P_A>P_B || P_A<=0 || P_B>20 || validarNumeros(RangoA) || validarNumeros(RangoB));

    auxP = P_B - P_A + 1;
    NProcesos=P_A + rand()%auxP;
    cout<<"\nEl número aleatorio de procesos generado es: "<<NProcesos<<"\n\n";
    system("pause");

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte los rangos para los tiempos de CPU de un proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá asignar hasta un máximo de 20 milisegundos por proceso.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        T_A=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        T_B=atoi(RangoB);
    }while(T_A>T_B || T_A<=0 || T_B>20 || validarNumeros(RangoA) || validarNumeros(RangoB));

    cout<<"\nEl rango de generación aleatoria de tiempos de CPU es "<<T_A<<" ms - "<<T_B<<" ms.\n\n";
    system("pause");

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte los rangos para la prioridad de un proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 10 prioridades.\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        Pr_A=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        Pr_B=atoi(RangoB);
    }while(Pr_A>Pr_B || Pr_A<=0 || Pr_B>10 || validarNumeros(RangoA) || validarNumeros(RangoB));

    cout<<"\nEl rango de generación aleatoria de prioridades es "<<Pr_A<<" - "<<Pr_B<<".\n\n";
    system("pause");

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte los rangos de generación para el Quantum.\nPRECAUCIÓN: No sobrecargue el programa, podrá asignar un Quantum máximo de .\n\n";
        cout<<"Rango inferior: ";
        cin>>RangoA;
        P_A=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        P_B=atoi(RangoB);
    }while(P_A>P_B || P_A<=0 || P_B>20 || validarNumeros(RangoA) || validarNumeros(RangoB));

    auxP = P_B - P_A + 1;
    NProcesos=P_A + rand()%auxP;
    cout<<"\nEl número aleatorio de procesos generado es: "<<NProcesos<<"\n\n";
    system("pause");

    // Vamos a llenar la matriz a trabajar

        // Primero, el identificador

        for (int a=1;a<=NProcesos;a++){
            PaqueteDatos[a-1][0]=a;
            cout<<PaqueteDatos[a-1][0]<<endl;
        }
        cout<<endl;
        // Segundo, generamos los T CPU

        auxT = T_B - T_A + 1;
        for (int a=1;a<=NProcesos;a++){
            PaqueteDatos[a-1][1]=T_A + rand()%auxT;
            cout<<PaqueteDatos[a-1][1]<<endl;
        }
        cout<<endl;
        // Tercerp, generamos las Prioridades

        auxPr = Pr_B - Pr_A + 1;
        for (int a=1;a<=NProcesos;a++){
            PaqueteDatos[a-1][2]=Pr_A + rand()%auxPr;
            cout<<PaqueteDatos[a-1][2]<<endl;
        }
    system("pause");
    FCFS(PaqueteDatos,NProcesos);
    SJF(PaqueteDatos,NProcesos);
    Prioridad(PaqueteDatos,NProcesos);
    RoundRobin(PaqueteDatos,NProcesos,Quantum);
};

void Generacion2(){
    cout<<"Nuevo cambio al código";
    cout<<"Un cambio más";
    cout<<"Hola";
};



