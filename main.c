#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "queue.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Rus");
    if (argc == 3 && strcmp(argv[1], "--file") == 0) {
        const char* filename;

        filename = argv[2];

        FILE* file = fopen(filename, "r");
        readFile(file);

    }
    char filename[255];

    printf("Имя файла для сохранения: ");
    scanf("%255s", filename);

    FILE* file = fopen(filename, "w");

    checkToInt(file);

    Queue newQueue;
    initializeQueue(&newQueue);
    createQueue(&newQueue, file);
    writeQueueToFile(file, &newQueue);
    selectionSortQueue(&newQueue);
    printQueue(&newQueue);
    writeQueueToFile(file, &newQueue);
    freeQueue(&newQueue);
    fclose(file);

    return 0;
}
