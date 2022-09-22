#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_SIZE 255

typedef struct {
    char nombre[255];
} persona;

void llenar_struct(char *cadena, persona *lista, int j) {
    persona arreglo;
    strcpy(arreglo.nombre, cadena);
    lista[j] = arreglo;
}

void swap(persona *a, persona *b) {
    persona pivote = *a;
    *a = *b;
    *b = pivote;
}

void desaparecer_struct(persona *targetivo, int index, int max) {
    for(int i = index; i < (max -1); i++){
        swap(&targetivo[i], &targetivo[i+1]);
    }
}

int main(int argc, char *argv[]) {

    // Configuración inicial
    FILE *mi_lectura = fopen(argv[1], "r");

    if (mi_lectura == NULL) {
        printf("Pon bien la ruta weon\n");
        return 0xF;
    }

    printf("Ruta del archivo: %s\n",argv[1]);
    printf("~HoN 0.1.0\n");

    char buffer[MAX_LINE_SIZE];
    int count = 0;

    while (fgets(buffer, MAX_LINE_SIZE, mi_lectura) != NULL) {
        count++;
    }

    // Guardar los nombres dentro de una lista
    rewind(mi_lectura);
    persona *lista = malloc(sizeof(persona) * count);

    for (int i = 0; i < count; i++) {
        fgets(buffer, MAX_LINE_SIZE, mi_lectura);
        llenar_struct(buffer, lista, i);
    }

    // Comienza la interaccion con el usuario
    int reserva = count;
    char opcion;
    int random;

    srand(time(NULL));

    while (count > 0) {
        printf("> ");
        opcion = fgetc(stdin);
        fgetc(stdin);

        switch (opcion) {
            case 'p':
                random = rand() % count;
                printf("%s", lista[random].nombre);
                desaparecer_struct(lista, random, count);
                count--;
                break;

            case 'r':
                printf("La lista ha sido reseteada\n");
                count = reserva;
                break;

            case 'x':
                printf("Que le vaya bien joven\n");
                return 0;

            default:
                printf("No meta eso compa\n");
        }
    }

    printf("\nSe terminaron los nombres, ahuecando el ala");
    return 0;
}