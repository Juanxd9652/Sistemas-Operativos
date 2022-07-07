#include <iostream>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

using namespace std;
using std::stoi;

int validar(char []);

int validar(char num[]){
    for (int i = 0; i < strlen(num); i++){
        if(!isdigit(num[i]) ) {
            return 1;
        }
        else{
            return 0;
        }
    }
}

int main(){
    setlocale(LC_ALL, "Spanish"); //Idioma español.
    int TiempoCPU[100];
    int TiempoDeEspera[100];
    TiempoDeEspera[0]=0;
    char NProcesos1[3];
    int NProcesos;
    char TCPU1[6];
    int TCPU=0;
    char Prioridad1[6];
    int Prio=0;
    float TiempoPromedioDeEspera=0;
    char Opcion1[2];
    int Opcion;
    for (;;){
        cout<<"----------------------------------------------------------------------------------\n";
        cout<<"|                        PROGRAMA DE EJECUCIÓN DE PROCESOS                       |\n";
        cout<<"|                                MEDIANTE ALGORITMOS                             |\n";
        cout<<"----------------------------------------------------------------------------------\n\n";
        cout<<"\nHola señor usuario, a través de este aplicativo podrá ejecutar procesos según el tipo de algoritmo a utilizar, ";
        cout<<"por favor escoja una opción: \n"<<endl;

        for (int b=0;b<1;){
            cout<<"1. Algoritmo FCFS (First Come, First Served): Ejecuta los procesos por orden de llegada sin interrupciones ";
            cout<<"y recibe como parámetros el T CPU.\n\n";
            cout<<"2. Algoritmo SJF (Shortest Job First): Ejecuta los procesos empezando por el más corto sin interrupciones y ";
            cout<<"recibe como parámetros el T CPU.\n\n";
            cout<<"3. Algoritmo de Prioridad: Ejecuta los procesos según la prioridad que se le haya asignado sin interrupciones y ";
            cout<<"recibe como parámetros la prioridad y el T CPU del proceso.\n\n";
            cout<<"4. Salir\n"<<endl;
            cout<<"Opción a escoger: ";
            cin>>Opcion1;

            if(validar(Opcion1)){
                system("cls");
                cout<<"----------------------------------------------------------------------------------\n";
                cout<<"|                        PROGRAMA DE EJECUCIÓN DE PROCESOS                       |\n";
                cout<<"|                                MEDIANTE ALGORITMOS                             |\n";
                cout<<"----------------------------------------------------------------------------------\n\n";
                cout<<"\nHola señor usuario, a través de este aplicativo podrá ejecutar procesos según el tipo de algoritmo a utilizar, ";
                cout<<"por favor escoja una opción: \n"<<endl;
                cout<<"ERROR: Solo se permiten números.\n"<<endl;
            }
            else{
                Opcion=atoi(Opcion1); //Para convertir el char en int.
                if (Opcion!=1 && Opcion!=2 && Opcion!=3 && Opcion!=4){
                    system("cls");
                    cout<<"----------------------------------------------------------------------------------\n";
                    cout<<"|                        PROGRAMA DE EJECUCIÓN DE PROCESOS                       |\n";
                    cout<<"|                                MEDIANTE ALGORITMOS                             |\n";
                    cout<<"----------------------------------------------------------------------------------\n\n";
                    cout<<"\nHola señor usuario, a través de este aplicativo podrá ejecutar procesos según el tipo de algoritmo a utilizar, ";
                    cout<<"por favor escoja una opción: \n"<<endl;
                    cout<<"ERROR: Número no valido como opción.\n"<<endl;
                }else{
                b++;
                }
            }

        }
        switch (Opcion) {
        case 1:{
            system("cls");
            for (int a=0;a<1;){
            cout<<"\nIndique la cantidad de procesos a ingresar (Máximo 100 procesos) para FCFS: ";
                cin>>NProcesos1;
                if(validar(NProcesos1)){
                    system("cls");
                    cout<<"ERROR: Solo se permiten números."<<endl;
                }
                else{
                    NProcesos=atoi(NProcesos1); //Para convertir el char en int.
                    if (NProcesos<1 || NProcesos>100){
                        system("cls");
                        cout<<"ERROR: Número fuera del rango."<<endl;
                    }else{
                    a++;
                    }
                }
            }
            cout<<endl;
            for (int b=0;b<NProcesos;b++){
                for (int a=0;a<1;){
                    cout<<"Indique el tiempo de CPU del proceso P"<<b+1<<": ";
                    cin>>TCPU1;
                    if(validar(TCPU1)){
                        //system("cls");
                        cout<<"\nERROR: Solo se permiten números."<<endl;
                    }
                    else{
                        TCPU=atoi(TCPU1); //Para convertir el char en int.
                        if (TCPU<=0){
                            //system("cls");
                            cout<<"\nERROR: Tiempo de CPU no válido."<<endl;
                        }else{
                        a++;
                        }
                    }
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
            cout<<"---------DIAGRAMA DE GANTT---------\n\n";
            cout<<"       0 ms."<<endl;
            for(int a=0,b=0;a<NProcesos;a++){
                cout<<"       ^\n       |\n       P"<<a+1<<"\n       |\n       v"<<endl;
                b+=TiempoCPU[a];
                cout<<"       "<<b<<" ms."<<endl;
            }

            system("pause");
            system("cls");

        }break;
        case 2:{
            int SJF[2][100]; //Matriz para guardar el orden de llegada y el TCPU.
            int aux[2][2]; //Matriz auxiliar para ordenar los TCPU de menor a mayor.
            system("cls");
            for (int a=0;a<1;){
            cout<<"\nIndique la cantidad de procesos a ingresar (Máximo 100 procesos) para SJF: ";
                cin>>NProcesos1;
                if(validar(NProcesos1)){
                    system("cls");
                    cout<<"Error: Solo se permiten números.\n"<<endl;
                }
                else{
                    NProcesos=atoi(NProcesos1); //Para convertir el char en int.
                    if (NProcesos<1 || NProcesos>100){
                        system("cls");
                        cout<<"Error: Número fuera del rango.\n"<<endl;
                    }else{
                    a++;
                    }
                }
            }
            cout<<endl;
            for (int b=0;b<NProcesos;b++){
                for (int a=0;a<1;){
                    cout<<"Indique el tiempo de CPU del proceso P"<<b+1<<": ";
                    cin>>TCPU1;
                    if(validar(TCPU1)){
                        //system("cls");
                        cout<<"\nError: Solo se permiten números.\n"<<endl;
                    }
                    else{
                        TCPU=atoi(TCPU1); //Para convertir el char en int.
                        if (TCPU<=0){
                            //system("cls");
                            cout<<"\nError: Tiempo de CPU no válido.\n"<<endl;
                        }else{
                        a++;
                        }
                    }

                    SJF[0][b]=TCPU;
                    SJF[1][b]=b+1;

                }
            }
            //Método de ordenamiento
            int cambio=0;
            for (int a=0;a<1;){
                for (int b=0;b<NProcesos-1;b++){
                    if (SJF[0][b]>SJF[0][b+1]){
                        aux[0][0]=SJF[1][b];
                        aux[0][1]=SJF[0][b];
                        aux[1][0]=SJF[1][b+1];
                        aux[1][1]=SJF[0][b+1];

                        SJF[1][b]=aux[1][0];
                        SJF[1][b+1]=aux[0][0];
                        SJF[0][b]=aux[1][1];
                        SJF[0][b+1]=aux[0][1];

                        cambio=1;
                    }
                }
                if (cambio==0){
                    a=1;
                }
                cambio=0;
            }


            for (int a=0;a<NProcesos;a++){
                if (a==0){
                    TiempoDeEspera[a]=0;
                }else{
                    TiempoDeEspera[a]=TiempoDeEspera[a-1]+SJF[0][a-1];
                }
            }
            for (int a=0;a<NProcesos;a++){
                cout<<TiempoDeEspera[a]<<endl;
            }
            for (int a=0;a<NProcesos;a++){
                TiempoPromedioDeEspera+=TiempoDeEspera[a];
                if(a==NProcesos-1){
                    TiempoPromedioDeEspera/=NProcesos;
                }
            }


            cout<<"\nEl tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
            cout<<"---------DIAGRAMA DE GANTT---------\n\n";
            cout<<"       0 ms."<<endl;
            for(int a=0,b=0;a<NProcesos;a++){
                cout<<"       ^\n       |\n       P"<<SJF[1][a]<<"\n       |\n       v"<<endl;
                b+=SJF[0][a];
                cout<<"       "<<b<<" ms."<<endl;
            }

            system("pause");
            system("cls");

        }break;
        case 3:{
            int Prioridad[3][100]; //Matriz para guardar el orden de llegada, la prioridad y el TCPU.
            int aux2[3][2]; //Matriz auxiliar para ordenar los procesos según la prioridad.
            system("cls");
            for (int a=0;a<1;){
            cout<<"\nIndique la cantidad de procesos a ingresar (Máximo 100 procesos) para Prioridad: ";
                cin>>NProcesos1;
                if(validar(NProcesos1)){
                    system("cls");
                    cout<<"Error: Solo se permiten números.\n"<<endl;
                }
                else{
                    NProcesos=atoi(NProcesos1); //Para convertir el char en int.
                    if (NProcesos<1 || NProcesos>100){
                        system("cls");
                        cout<<"Error: Número fuera del rango.\n"<<endl;
                    }else{
                    a++;
                    }
                }
            }

            cout<<endl;
            for (int b=0;b<NProcesos;b++){
                for (int a=0;a<1;){
                    cout<<"\nIndique la prioridad del proceso P"<<b+1<<": ";
                    cin>>Prioridad1;
                    if(validar(Prioridad1)){
                        //system("cls");
                        cout<<"\nError: Solo se permiten números.\n"<<endl;
                    }
                    else{
                        Prio=atoi(Prioridad1); //Para convertir el char en int.
                        if (Prio<=0){
                            //system("cls");
                            cout<<"\nError: Prioridad no válida.\n"<<endl;
                        }else{
                        a++;
                        }
                    }

                    Prioridad[0][b]=Prio;
                    //cout<<Prioridad[0][b];
                    Prioridad[1][b]=b+1;

                }
            }

            for (int b=0;b<NProcesos;b++){
                for (int a=0;a<1;){
                    cout<<"\nIndique el tiempo de CPU del proceso P"<<b+1<<": ";
                    cin>>TCPU1;
                    if(validar(TCPU1)){
                        //system("cls");
                        cout<<"\nError: Solo se permiten números.\n"<<endl;
                    }
                    else{
                        TCPU=atoi(TCPU1); //Para convertir el char en int.
                        if (TCPU<=0){
                            //system("cls");
                            cout<<"\nError: Tiempo de CPU no válido.\n"<<endl;
                        }else{
                        a++;
                        }
                    }

                    Prioridad[2][b]=TCPU;
                }
            }

            //Método de ordenamiento
            int cambio=0;
            for (int a=0;a<1;){
                for (int b=0;b<NProcesos-1;b++){
                    if (Prioridad[0][b]>Prioridad[0][b+1]){
                        aux2[0][0]=Prioridad[0][b]; //Guarda prioridad
                        aux2[0][1]=Prioridad[0][b+1];
                        aux2[1][0]=Prioridad[1][b]; //Guarda orden
                        aux2[1][1]=Prioridad[1][b+1];
                        aux2[2][0]=Prioridad[2][b]; //Guarda TCPU
                        aux2[2][1]=Prioridad[2][b+1];

                        Prioridad[0][b]=aux2[0][1];
                        Prioridad[0][b+1]=aux2[0][0];
                        Prioridad[1][b]=aux2[1][1];
                        Prioridad[1][b+1]=aux2[1][0];
                        Prioridad[2][b]=aux2[2][1];
                        Prioridad[2][b+1]=aux2[2][0];

                        cambio=1;
                    }
                }
                if (cambio==0){
                    a=1;
                }
                cambio=0;
            }

            for (int a=0;a<NProcesos;a++){
                if (a==0){
                    TiempoDeEspera[a]=0;
                }else{
                    TiempoDeEspera[a]=TiempoDeEspera[a-1]+Prioridad[2][a-1];
                }
            }

            for (int a=0;a<NProcesos;a++){
                TiempoPromedioDeEspera+=TiempoDeEspera[a];
                if(a==NProcesos-1){
                    TiempoPromedioDeEspera/=NProcesos;
                }
            }


            cout<<"\nEl tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
            cout<<"---------DIAGRAMA DE GANTT---------\n\n";
            cout<<"       0 ms."<<endl;
            for(int a=0,b=0;a<NProcesos;a++){
                cout<<"       ^\n       |\n       P"<<Prioridad[1][a]<<"\n       |\n       v"<<endl;
                b+=Prioridad[2][a];
                cout<<"       "<<b<<" ms."<<endl;
            }

            system("pause");
            system("cls");


        }break;
        case 4:{
            return 0;
        }break;
    }
    }


}



