#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
    Tarea * Siguiente;
}; 

void cargarTareas(Tarea ** TareasPendientes,int cantTareas);
void realizarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas);
void mostrarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas);
int buscarTarea(Tarea ** TareasPendientes,Tarea ** TareasRealizadas);
int buscarTareaID(Tarea ** TareasPendientes,Tarea ** TareasRealizadas);

int main() {
    Tarea * TareasPendientes = NULL;
    Tarea * TareasRealizadas = NULL;
    int cantTareas;
    
    printf("Cuantas tareas desea cargar?: ");
    scanf("%d",&cantTareas);
    system("cls");

    cargarTareas(&TareasPendientes,cantTareas);
    realizarTareas(&TareasPendientes,&TareasRealizadas,cantTareas);
    mostrarTareas(&TareasPendientes,&TareasRealizadas);
    buscarTarea(&TareasPendientes,&TareasRealizadas);
    buscarTareaID(&TareasPendientes,&TareasRealizadas);

    getchar();
    getchar();
    return 0;
}

void cargarTareas(Tarea ** TareasPendientes,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        Tarea * Pendientes = (Tarea *) malloc(sizeof(Tarea));
        char descripcion[60];
        int duracion = 0;

        printf("Tarea #%d\n", i+1);
        Pendientes->TareaID = i + 1;

        printf("Descripcion: ");
        fflush(stdin);
        gets(descripcion);
        Pendientes->Descripcion = (char*)malloc(sizeof(descripcion)*(strlen(descripcion)));
        strcpy(Pendientes->Descripcion,descripcion);

        do
        {
            printf("Duracion: ");
            scanf("%d",&duracion);
        } while (duracion<10 || duracion>100);
        Pendientes->Duracion = duracion;
        Pendientes->Siguiente = NULL;

        Tarea * Aux = *TareasPendientes;

        if (i==0)
        {
            *TareasPendientes = Pendientes;
        }else
        {
            while (Aux->Siguiente)
            {
                Aux = Aux->Siguiente;
            }
            Aux->Siguiente = Pendientes;
        }
        
        system("cls");
    }   
}

void realizarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas){
    int bandera;
    int bandera2 = 0;
    int v = 0;
    Tarea * Aux = *TareasPendientes;
    Tarea * AuxAnt = NULL;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("Esta tarea esta realizada?\n\n");
        printf("Tarea ID: %d\n", Aux->TareaID);
        printf("Descripcion: \"%s\"\n", Aux->Descripcion);
        printf("Duracion: %d\n\n", Aux->Duracion);
        do
        {
            printf("1 / 0 (Si / No): ");
            scanf("%d",&bandera);
        } while (bandera != 0 && bandera != 1);
        if (bandera == 1)
        {
            Tarea * Realizadas = (Tarea *) malloc(sizeof(Tarea));
            *Realizadas = *Aux;
            Realizadas->Siguiente = NULL;
            if (AuxAnt != NULL)
            {
                AuxAnt->Siguiente = Aux->Siguiente;
            }else
            {
                *TareasPendientes = Aux->Siguiente;
            }

            Tarea * Aux2 = *TareasRealizadas;

            if (bandera2 == 0)
            {
                *TareasRealizadas = Realizadas;
                bandera2 = 1;
            }else
            {
                while (Aux2->Siguiente)
                {
                    Aux2 = Aux2->Siguiente;
                }
                Aux2->Siguiente = Realizadas;
            }
            Aux = Aux->Siguiente;
        }else
        {
            AuxAnt = Aux;
            Aux = Aux->Siguiente;
        }
        system("cls");
    }
}

void mostrarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas){
    Tarea * Aux = *TareasPendientes;
    Tarea * Aux2 = *TareasRealizadas;

    printf("|||||||||||||||||TAREAS REALIZADAS|||||||||||||||||\n\n");
	while(Aux2){
		printf("Tarea ID: %d \n", Aux2->TareaID);
		printf("Descripcion: \"%s\"\n", Aux2->Descripcion);
	    printf("Duracion: %d\n\n", Aux2->Duracion);
        Aux2 = Aux2->Siguiente;
	}
    printf("|||||||||||||||||TAREAS PENDIENTES|||||||||||||||||\n\n");
    while (Aux)
    {
        printf("Tarea ID: %d \n", Aux->TareaID);
		printf("Descripcion: \"%s\"\n", Aux->Descripcion);
		printf("Duracion: %d\n\n", Aux->Duracion);
        Aux = Aux->Siguiente;
    }  
}

int buscarTarea(Tarea ** TareasPendientes,Tarea ** TareasRealizadas){
    Tarea * Aux = *TareasPendientes;
    Tarea * Aux2 = *TareasRealizadas;

    printf("|||||||||||||||||BUSCAR TAREAS|||||||||||||||||\n\n");

    char palabra[60];
    printf("Ingresar palabra clave: ");
    fflush(stdin);
    gets(palabra);
    while (Aux2)
    {
		while(*(Aux2->Descripcion) != '\0'){
			if(strstr(Aux2->Descripcion, palabra)){
                printf("\nTarea ID: %d \n", Aux2->TareaID);
		        printf("Descripcion: \"%s\"\n", Aux2->Descripcion);
	            printf("Duracion: %d\n\n", Aux2->Duracion);
                return 1;
		    }
		    (Aux2->Descripcion)++;
		}
        Aux2 = Aux2->Siguiente;
    }
    while (Aux)
    {
		while(*(Aux->Descripcion) != '\0'){
			if(strstr(Aux->Descripcion, palabra)){
                printf("\nTarea ID: %d \n", Aux->TareaID);
                printf("Descripcion: \"%s\"\n", Aux->Descripcion);
                printf("Duracion: %d\n\n", Aux->Duracion);
                return 1;
		    }
		    (Aux->Descripcion)++;
		}
        Aux = Aux->Siguiente;
    }
    printf("\nNo se pudo encontrar la palabra.");
    return 0;
}

int buscarTareaID(Tarea ** TareasPendientes,Tarea ** TareasRealizadas){
    Tarea * Aux = *TareasPendientes;
    Tarea * Aux2 = *TareasRealizadas;

    int id;
    printf("Ingresar ID: ");
    scanf("%d", &id);
    while (Aux2)
    {
        if (Aux2->TareaID == id)
        {
            printf("\nTarea ID: %d \n", Aux2->TareaID);
		    printf("Descripcion: \"%s\"\n", Aux2->Descripcion);
	        printf("Duracion: %d\n\n", Aux2->Duracion);
            return 1;
        }
        Aux2 = Aux2->Siguiente;
    }
    while (Aux)
    {
        if (Aux->TareaID == id)
        {
            printf("\nTarea ID: %d \n", Aux->TareaID);
            printf("Descripcion: \"%s\"\n", Aux->Descripcion);
            printf("Duracion: %d\n\n", Aux->Duracion);
            return 1;
        }
        Aux = Aux->Siguiente;
    }
    printf("No se pudo encontrar el ID.");
    return 0;
}