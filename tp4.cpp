#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>

struct Tarea {
    int TareaID; //Numerado en ciclo iterativo
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}; 

void cargarTareas(Tarea ** TareasPendientes,int cantTareas);
int realizarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas);
void mostrarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas,int cantRealizadas);
Tarea buscarTarea(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas, int cantRealizadas);
Tarea buscarTareaID(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas, int cantRealizadas);

int main() {
    int cantTareas;
    int cantRealizadas;
    Tarea Resultado;
    Tarea ResultadoID;
    
    printf("Cuantas tareas desea cargar?: ");
    scanf("%d",&cantTareas);
    system("cls");

    Tarea ** TareasPendientes = (Tarea **) malloc(sizeof(Tarea)*cantTareas);
    Tarea ** TareasRealizadas = (Tarea **) malloc(sizeof(Tarea)*cantTareas);

    cargarTareas(TareasPendientes,cantTareas);
    cantRealizadas = realizarTareas(TareasPendientes,TareasRealizadas,cantTareas);
    mostrarTareas(TareasPendientes,TareasRealizadas,cantTareas,cantRealizadas);

    printf("|||||||||||||||||BUSCAR TAREAS|||||||||||||||||\n\n");
    Resultado = buscarTarea(TareasPendientes,TareasRealizadas,cantTareas,cantRealizadas);
    if (Resultado.TareaID == 0){
        printf("No se pudo encontrar la palabra");
    }else
    {
        printf("\nTarea ID: %d \n", Resultado.TareaID);
		printf("Descripcion: \"%s\"\n", Resultado.Descripcion);
		printf("Duracion: %d\n\n", Resultado.Duracion);
    }

    ResultadoID = buscarTareaID(TareasPendientes,TareasRealizadas,cantTareas,cantRealizadas);
    if (ResultadoID.TareaID == 0)
    {
        printf("No se pudo encontrar el ID");
    }else
    {
        printf("\nTarea ID: %d \n", ResultadoID.TareaID);
		printf("Descripcion: \"%s\"\n", ResultadoID.Descripcion);
		printf("Duracion: %d\n\n", ResultadoID.Duracion);
    }
    
    getchar();
    getchar();
}

void cargarTareas(Tarea ** TareasPendientes,int cantTareas){
    for (int i = 0; i < cantTareas; i++)
    {
        TareasPendientes[i] = (Tarea *) malloc(sizeof(Tarea));;
        char descripcion[60];
        int duracion = 0;

        printf("Tarea #%d\n", i+1);
        TareasPendientes[i]->TareaID = i + 1;

        printf("Descripcion: ");
        fflush(stdin);
        gets(descripcion);
        TareasPendientes[i]->Descripcion = (char*)malloc(sizeof(descripcion)*(strlen(descripcion)));
        strcpy(TareasPendientes[i]->Descripcion,descripcion);

        do
        {
            printf("Duracion: ");
            scanf("%d",&duracion);
        } while (duracion<10 || duracion>100);
        TareasPendientes[i]->Duracion = duracion;
        system("cls");
    }   
}

int realizarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas){
    int aux;
    int v = 0;
    for (int i = 0; i < cantTareas; i++)
    {
        printf("Esta tarea esta realizada?\n\n");
        printf("Tarea ID: %d\n", TareasPendientes[i]->TareaID);
        printf("Descripcion: \"%s\"\n", TareasPendientes[i]->Descripcion);
        printf("Duracion: %d\n\n", TareasPendientes[i]->Duracion);
        do
        {
            printf("1 / 0 (Si / No): ");
            scanf("%d",&aux);
        } while (aux != 0 && aux != 1);
        if (aux == 1)
        {
            TareasRealizadas[v] = TareasPendientes[i];
            TareasPendientes[i] = NULL;
            v++;
        }
        system("cls");
    }
    return v;
}

void mostrarTareas(Tarea ** TareasPendientes,Tarea ** TareasRealizadas, int cantTareas, int cantRealizadas){
    printf("|||||||||||||||||TAREAS REALIZADAS|||||||||||||||||\n\n");
	for(int i = 0; i < cantRealizadas; i++){
		if(TareasRealizadas[i]){
			printf("Tarea ID: %d \n", TareasRealizadas[i]->TareaID);
			printf("Descripcion: \"%s\"\n", TareasRealizadas[i]->Descripcion);
			printf("Duracion: %d\n\n", TareasRealizadas[i]->Duracion);
		}
	}
    printf("|||||||||||||||||TAREAS PENDIENTES|||||||||||||||||\n\n");
    for (int i = 0; i < cantTareas; i++)
    {
        if (TareasPendientes[i]){
            printf("Tarea ID: %d \n", TareasPendientes[i]->TareaID);
		    printf("Descripcion: \"%s\"\n", TareasPendientes[i]->Descripcion);
		    printf("Duracion: %d\n\n", TareasPendientes[i]->Duracion);
        }
    }  
}

Tarea buscarTarea(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas, int cantRealizadas){
    char palabra[60];
    printf("Ingresar palabra clave: ");
    fflush(stdin);
    gets(palabra);
    for (int i = 0; i < cantRealizadas; i++)
    {
        if(TareasRealizadas[i]){
			while(*(TareasRealizadas[i]->Descripcion) != '\0'){
				if(strstr(TareasRealizadas[i]->Descripcion, palabra)){
		            return *TareasRealizadas[i];
		    	}
		    	(TareasRealizadas[i]->Descripcion)++;
			}
		}
    }
    for (int i = 0; i < cantTareas; i++)
    {
		if(TareasPendientes[i]){
			while(*(TareasPendientes[i]->Descripcion) != '\0'){
				if(strstr(TareasPendientes[i]->Descripcion, palabra)){
		            return *TareasPendientes[i];
		    	}
		    	(TareasPendientes[i]->Descripcion)++;
			}
		}
    }
    Tarea Sin;
    Sin.TareaID = 0;
    return Sin;
}

Tarea buscarTareaID(Tarea ** TareasPendientes,Tarea ** TareasRealizadas,int cantTareas, int cantRealizadas){
    int id;
    printf("\nIngresar ID: ");
    scanf("%d", &id);
    for (int i = 0; i < cantTareas; i++)
    {
        if (TareasPendientes[i]->TareaID == id)
        {
            return *TareasPendientes[i];
        }
    }
    for (int i = 0; i < cantRealizadas; i++)
    {
        if (TareasRealizadas[i]->TareaID == id)
        {
            return *TareasRealizadas[i];
        }
    }
    Tarea Sin;
    Sin.TareaID = 0;
    return Sin;
}