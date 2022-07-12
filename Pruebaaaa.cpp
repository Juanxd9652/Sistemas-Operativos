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
void Generacion3(); //Permite insertar al usuario los datos manualmente.

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
            cout<<"* Bienvenido señor usuario, por favor identifíquese con un nombre: ";
            cin>>nombre;
            nombre2=nombre;
            system("cls");
        }while(validarNombres(nombre));

        while(opc2<1 || opc2>3 || validarNumeros(opc1)){
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
        else if (opc2==2){
            cout<<"Aquí debo poner texto haciendo referencia a la inserción de datos de manera manual.\n";
            Generacion3();
        }
        else{
            return 0;
        }

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
    cout<<"Prioridad, Quantum de manera manual.\n\n1. Generación aleatoria.\n2. Inserción manual.\n3. Salir.\n\nPor favor escoja una opción: ";
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
    int TCPU=0;
    int aux;
    float TiempoPromedioDeEspera=0;
    system("cls");

    // Para guardar el tiempo de espera de cada proceso.

    for (int b=0;b<NProcesos;b++){
        TCPU=Paquete[b][1];
        if (b==0){
            TiempoDeEspera[b]=0;
        }else{
            TiempoDeEspera[b]=TiempoDeEspera[b-1]+TiempoCPU[b-1];
        }
        TiempoCPU[b]=TCPU;
    }

    // Para calcular el tiempo promedio de espera.

    for (int a=0;a<NProcesos;a++){
        TiempoPromedioDeEspera+=TiempoDeEspera[a];
        if(a==NProcesos-1){
            TiempoPromedioDeEspera/=NProcesos;
        }
    }

    Titulo();
    cout<<"  -----------------------------\n";
    cout<<"  |DIAGRAMA DE GANTT PARA FCFS|\n";
    cout<<"  -----------------------------\n\n";
    cout<<"              0 ms."<<endl;
    for(int a=0,b=0;a<NProcesos;a++){
        cout<<"              ^\n              |\n              P"<<a+1<<"\n              |\n              v"<<endl;
        b+=TiempoCPU[a];
        cout<<"              "<<b<<" ms."<<endl;
    }
    cout<<"\n  * El tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
};

void SJF(int Paquete[][3], int NProcesos){

    int TiempoDeEspera[100];
    TiempoDeEspera[0]=0;
    float TiempoPromedioDeEspera=0;

    int SJF[2][20]; //Matriz para guardar el orden de llegada y el TCPU.
    int aux[2][2]; //Matriz auxiliar para ordenar los TCPU de menor a mayor.

    // Aquí se insertan los tiempos de CPU

    for (int b=0;b<NProcesos;b++){
        SJF[0][b]=Paquete[b][1]; //T CPU
        SJF[1][b]=Paquete[b][0]; //Identificador
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

    // Se registra el tiempo de espera de cada proceso

    for (int a=0;a<NProcesos;a++){
        if (a==0){
            TiempoDeEspera[a]=0;
        }else{
            TiempoDeEspera[a]=TiempoDeEspera[a-1]+SJF[0][a-1];
        }
    }

    // Se calcula el tiempo de espera promedio

    for (int a=0;a<NProcesos;a++){
        TiempoPromedioDeEspera+=TiempoDeEspera[a];
        if(a==NProcesos-1){
            TiempoPromedioDeEspera/=NProcesos;
        }
    }

    cout<<"  ----------------------------\n";
    cout<<"  |DIAGRAMA DE GANTT PARA SJF|\n";
    cout<<"  ----------------------------\n\n";
    cout<<"              0 ms."<<endl;
    for(int a=0,b=0;a<NProcesos;a++){
        cout<<"              ^\n              |\n              P"<<SJF[1][a]<<"\n              |\n              v"<<endl;
        b+=SJF[0][a];
        cout<<"              "<<b<<" ms."<<endl;
    }
    cout<<"\n  * El tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;
};

void Prioridad(int Paquete[][3], int NProcesos){

    int TiempoDeEspera[100];
    TiempoDeEspera[0]=0;
    int TCPU=0;
    float TiempoPromedioDeEspera=0;

    int Prioridad[3][100]; //Matriz para guardar el orden de llegada, la prioridad y el TCPU.
    int aux2[3][2]; //Matriz auxiliar para ordenar los procesos según la prioridad.

    // Aquí se insertan los datos del Paquete.

    for (int b=0;b<NProcesos;b++){
        Prioridad[1][b]=Paquete[b][0]; // Identificador
        Prioridad[2][b]=Paquete[b][1]; // TCPU.
        Prioridad[0][b]=Paquete[b][2]; // Prioridad
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

    cout<<"  ----------------------------------\n";
    cout<<"  |DIAGRAMA DE GANTT PARA PRIORIDAD|\n";
    cout<<"  ----------------------------------\n\n";
    cout<<"              0 ms."<<endl;
    for(int a=0,b=0;a<NProcesos;a++){
        cout<<"              ^\n              |\n              P"<<Prioridad[1][a]<<"\n              |\n              v"<<endl;
        b+=Prioridad[2][a];
        cout<<"              "<<b<<" ms."<<endl;
    }
    cout<<"\nEl tiempo promedio de espera es de: "<<TiempoPromedioDeEspera<<" ms.\n"<<endl;

};

void RoundRobin(int Paquete[][3], int NProcesos, int Quantum){
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
        int auxQ;
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
    cout<<"\nEl número de procesos que fue generado de manera aleatoria es ("<<NProcesos<<").\n\n";
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
        Q_A=atoi(RangoA);
        cout<<"\nRango superior: ";
        cin>>RangoB;
        Q_B=atoi(RangoB);
    }while(Q_A>Q_B || Q_A<=0 || Q_B>20 || validarNumeros(RangoA) || validarNumeros(RangoB));

    auxQ = Q_B - Q_A + 1;
    Quantum=Q_A + rand()%auxQ;
    cout<<"\nEl Quantum que fue generado de manera aleatoria es ("<<Quantum<<").\n\n";
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

void Generacion3(){

    //Variables necesarias

    char Ingreso[2];
    int PaqueteDatos[20][3];

        //Variables para # Procesos

        int NProcesos;

        //Variables para T CPU

        int T_A;

        //Variables para Prioridad

        int Pr_A;
        int auxPr;

        //Variables para Quantum

        int Quantum;

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte la cantidad de procesos a trabajar.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 20 procesos.\n\n";
        cout<<"Procesos: ";
        cin>>Ingreso;
        NProcesos=atoi(Ingreso);
    }while(NProcesos>20 || NProcesos<=0 || validarNumeros(Ingreso));

    cout<<"\nEl número de procesos ingresado es ("<<NProcesos<<").\n\n";
    system("pause");

    // Primero, el identificador

        for (int a=1;a<=NProcesos;a++){
            PaqueteDatos[a-1][0]=a;
            cout<<PaqueteDatos[a-1][0]<<endl;
        }

    for (int a=1;a<=NProcesos;a++){
        do{
        system("cls");
        Titulo();
        cout<<"\nInserte los tiempos de CPU de cada proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá asignar hasta un máximo de 20 milisegundos por proceso.\n\n";
        cout<<"Tiempo de CPU del proceso ("<<a<<"): ";
        cin>>Ingreso;
        T_A=atoi(Ingreso);
        }while(T_A>20 || T_A<=0 || validarNumeros(Ingreso));
        PaqueteDatos[a-1][1]=T_A;
    }

    cout<<endl;
    system("pause");

    for (int a=1;a<=NProcesos;a++){
        do{
        system("cls");
        Titulo();
        cout<<"\nInserte las prioridades de cada proceso.\nPRECAUCIÓN: No sobrecargue el programa, podrá generar hasta un máximo de 10 prioridades.\n\n";
        cout<<"Prioridad del proceso ("<<a<<"): ";
        cin>>Ingreso;
        Pr_A=atoi(Ingreso);
        }while(Pr_A>10 || Pr_A<=0 || validarNumeros(Ingreso));
        PaqueteDatos[a-1][2]=Pr_A;
    }

    cout<<endl;
    system("pause");

    do{
        system("cls");
        Titulo();
        cout<<"\nInserte el Quantum.\nPRECAUCIÓN: No sobrecargue el programa, podrá asignar un Quantum máximo de 10 ms .\n\n";
        cout<<"Quantum: ";
        cin>>Ingreso;
        Quantum=atoi(Ingreso);
    }while(Quantum>10 || Quantum<=0 || validarNumeros(Ingreso));

    cout<<"\nEl Quantum ingresado es ("<<Quantum<<").\n\n";

    system("pause");

    FCFS(PaqueteDatos,NProcesos);
    SJF(PaqueteDatos,NProcesos);
    Prioridad(PaqueteDatos,NProcesos);
    RoundRobin(PaqueteDatos,NProcesos,Quantum);
};

void Generacion2(){
    /*
    int TiempoCPU[100];
    int TiempoDeEspera[100];
    TiempoDeEspera[0]=0;
    char NProcesos1[3];
    int NProcesos;
    char TCPU1[6];
    int TCPU=0;
    char Prioridad1[6];
    int Prio=0;

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

    // Aquí se insertan las prioridades de cada proceso.

    cout<<endl;
    for (int b=0;b<NProcesos;b++){
        for (int a=0;a<1;){
            cout<<"\nIndique la prioridad del proceso P"<<b+1<<": ";
            cin>>Prioridad1;
            if(validar(Prioridad1)){
                cout<<"\nError: Solo se permiten números.\n"<<endl;
            }
            else{
                Prio=atoi(Prioridad1); //Para convertir el char en int.
                if (Prio<=0){
                    cout<<"\nError: Prioridad no válida.\n"<<endl;
                }else{
                a++;
                }
            }
            Prioridad[0][b]=Prio;
            Prioridad[1][b]=b+1;
        }
    }

    // Aquí se insertan los tiempos de CPU

    for (int b=0;b<NProcesos;b++){
        for (int a=0;a<1;){
            cout<<"\nIndique el tiempo de CPU del proceso P"<<b+1<<": ";
            cin>>TCPU1;
            if(validar(TCPU1)){
                cout<<"\nError: Solo se permiten números.\n"<<endl;
            }
            else{
                TCPU=atoi(TCPU1); //Para convertir el char en int.
                if (TCPU<=0){
                    cout<<"\nError: Tiempo de CPU no válido.\n"<<endl;
                }else{
                    a++;
                }
            }
            Prioridad[2][b]=TCPU;
        }
    }
    */
};



