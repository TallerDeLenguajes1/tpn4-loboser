#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <time.h>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}; 

void cargarTareas(Tarea * TareasPendientes,int cantTareas);

int main() {
    int cantTareas;
    printf("Cuantas tareas desea cargar?: ");
    scanf("%d",&cantTareas);
    system("cls");

    Tarea * TareasPendientes = (Tarea *) malloc(sizeof(Tarea)*cantTareas);
    Tarea * TareasRealizadas = (Tarea *) malloc(sizeof(Tarea)*cantTareas);

    cargarTareas(TareasPendientes,cantTareas);

}

void cargarTareas(Tarea * TareasPendientes,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        char descripcion[60];
        int duracion;
        (TareasPendientes + i)->TareaID = i + 1;

        printf("Tarea Nº%d", i);
        printf("Descripcion: ");
        fflush(stdin);
        gets(descripcion);
        (TareasPendientes + i)->Descripcion = (char *) malloc(sizeof(char)*strlen(descripcion));

        do
        {
            printf("Duracion: ");
            scanf("%d",&duracion);
        } while (duracion<10 || duracion>100);
        (TareasPendientes + i)->Duracion = duracion;
    }   
}

