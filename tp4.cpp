#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}; 

void cargarTareas(Tarea * TareasPendientes,int cantTareas);
void realizarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas);
void mostrarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas);
Tarea buscarTarea(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas);

int main() {
    char palabra[60];
    int cantTareas;
    Tarea Resultado;
    printf("Cuantas tareas desea cargar?: ");
    scanf("%d",&cantTareas);
    system("cls");

    Tarea * TareasPendientes = (Tarea *) malloc(sizeof(Tarea)*cantTareas);
    Tarea * TareasRealizadas = (Tarea *) malloc(sizeof(Tarea)*cantTareas);

    cargarTareas(TareasPendientes,cantTareas);
    realizarTareas(TareasPendientes,TareasRealizadas,cantTareas);
    mostrarTareas(TareasPendientes,TareasRealizadas,cantTareas);

    printf("|||||||||||||||||BUSCAR TAREAS|||||||||||||||||\n\n");

    Resultado = buscarTarea(TareasPendientes,TareasRealizadas,cantTareas);
    if (Resultado.TareaID == 0){
        printf("No se pudo encontrar la palabra");
    }else
    {
        printf("\nTarea ID: %d \n", Resultado.TareaID);
		printf("Descripcion: \"%s\"\n", Resultado.Descripcion);
		printf("Duracion: %d\n\n", Resultado.Duracion);
    }
    
    getchar();
}

void cargarTareas(Tarea * TareasPendientes,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        char descripcion[60];
        int duracion = 0;

        printf("Tarea #%d\n", i+1);
        TareasPendientes->TareaID = i + 1;

        printf("Descripcion: ");
        fflush(stdin);
        gets(descripcion);
        TareasPendientes->Descripcion = (char*)malloc(sizeof(descripcion)*(strlen(descripcion)));
        strcpy(TareasPendientes->Descripcion,descripcion);

        do
        {
            printf("Duracion: ");
            scanf("%d",&duracion);
        } while (duracion<10 || duracion>100);
        TareasPendientes->Duracion = duracion;
        system("cls");
        TareasPendientes++;
    }   
}

void realizarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas){
    int aux;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("Esta tarea esta realizada?\n\n");
        printf("Tarea ID: %d\n", TareasPendientes->TareaID);
        printf("Descripcion: \"%s\"\n", TareasPendientes->Descripcion);
        printf("Duracion: %d\n\n", TareasPendientes->Duracion);
        do
        {
            printf("1 / 0 (Si / No): ");
            scanf("%d",&aux);
        } while (aux != 0 && aux != 1);
        if (aux == 1)
        {
            *TareasRealizadas = *TareasPendientes;
            TareasPendientes->TareaID = 0;
        }else
        {
            TareasRealizadas->TareaID = 0;
        }
        system("cls");
        TareasPendientes++;
        TareasRealizadas++;
    }
}

void mostrarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas, int cantTareas){
    printf("|||||||||||||||||TAREAS REALIZADAS|||||||||||||||||\n\n");
	for(int i = 0; i < cantTareas; i++){
		if(TareasRealizadas->TareaID != 0){
			printf("Tarea ID: %d \n", TareasRealizadas->TareaID);
			printf("Descripcion: \"%s\"\n", TareasRealizadas->Descripcion);
			printf("Duracion: %d\n\n", TareasRealizadas->Duracion);
		}
		TareasRealizadas++;
	}
    printf("|||||||||||||||||TAREAS PENDIENTES|||||||||||||||||\n\n");
    for (int i = 0; i < cantTareas; i++)
    {
        if (TareasPendientes->TareaID != 0){
            printf("Tarea ID: %d \n", TareasPendientes->TareaID);
		    printf("Descripcion: \"%s\"\n", TareasPendientes->Descripcion);
		    printf("Duracion: %d\n\n", TareasPendientes->Duracion);
        }
        TareasPendientes++;
    }  
}

Tarea buscarTarea(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas){
    char palabra[60];
    printf("Ingresar palabra clave: ");
    fflush(stdin);
    gets(palabra);
    for (int i = 0; i < cantTareas; i++)
    {
        if(TareasRealizadas->TareaID != 0){
			while(*(TareasRealizadas->Descripcion) != '\0'){
				if(strstr(TareasRealizadas->Descripcion, palabra)){
		            return *TareasRealizadas;
		    	}
		    	(TareasRealizadas->Descripcion)++;
			}
		}
		if(TareasPendientes->TareaID != 0){
			while(*(TareasPendientes->Descripcion) != '\0'){
				if(strstr(TareasPendientes->Descripcion, palabra)){
		            return *TareasPendientes;
		    	}
		    	(TareasPendientes->Descripcion)++;
			}
		}
		TareasRealizadas++; 
        TareasPendientes++;
    }
    Tarea Sin;
    Sin.TareaID = 0;
    return Sin;
}