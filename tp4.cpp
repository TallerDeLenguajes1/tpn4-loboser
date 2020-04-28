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
void realizarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas);

int main() {
    int cantTareas;
    printf("Cuantas tareas desea cargar?: ");
    scanf("%d",&cantTareas);
    system("cls");

    Tarea * TareasPendientes = (Tarea *) malloc(sizeof(Tarea)*cantTareas);
    Tarea * TareasRealizadas = (Tarea *) malloc(sizeof(Tarea)*cantTareas);

    cargarTareas(TareasPendientes,cantTareas);
    realizarTareas(TareasPendientes,TareasRealizadas,cantTareas);
}

void cargarTareas(Tarea * TareasPendientes,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        char descripcion[60];
        int duracion;
        (TareasPendientes + i)->TareaID = i + 1;

        printf("Tarea Nº%d", i+1);
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
        system("cls");
    }   
}

void realizarTareas(Tarea * TareasPendientes,Tarea * TareasRealizadas,int cantTareas){
    int aux;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("Esta tarea esta realizada?\n\n");
        printf("Tarea Nº%d", (TareasPendientes + i)->TareaID);
        puts((TareasPendientes + i)->Descripcion);
        printf("Duracion: %d\n\n", (TareasPendientes + i)->Duracion);
        do
        {
            printf("1 / 0 (Si / No)");
            scanf("%d",&aux);
        } while (aux != 0 && aux != 1);
        if (aux == 1)
        {
            *(TareasRealizadas + i) = *(TareasPendientes + i);
        }
        system("cls");
    }
}