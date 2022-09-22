#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_SIZE 255

typedef struct {
    char nombre[255];
} persona;

int main(int argc, char *argv[]) {
    FILE *mi_lectura = fopen(argv[1], "r");

    if (mi_lectura == NULL) {
        printf("Pon bien el nombre, pinche morro pendejo XDDD\n");
        return 420;
    }

    char buffer[MAX_LINE_SIZE];
    int count = 0;

    printf("Nombres dentro del archivo:\n");
    while (fgets(buffer, MAX_LINE_SIZE, mi_lectura) != NULL) {
        printf("%s", buffer);
        count++;
    }

    rewind(mi_lectura);
    printf("%d", count);

    return 0;
}
