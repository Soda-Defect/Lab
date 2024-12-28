#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initializeQueue(Queue* q) {
    q->front = q->rear = NULL;
}

void readFile(FILE* file)
{
        if (!file)
        {
            printf("Ошибка файл пуст или отсутствует");
        }
        int n, number;
        fscanf(file, "%d", &n);
        for(int i = 0; i < n; ++i)
        {
            fscanf(file, "%d", &number);
            printf("%d ", number);
        }

        printf("\n");

        for(int i = 0; i < n; ++i)
        {
            fscanf(file, "%d", &number);
            printf("%d ", number);
        }
        printf("\n");

        fclose(file);
}

void checkToInt(FILE* file)
{
    int n;
    printf("количество чисел: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fclose(file);
        printf("Ошибка: число должно быть больше нуля\n");
    }
}

void createQueue(Queue* newQueue, FILE* file)
{
    int n, num;
    fprintf(file, "%d\n", n);
    for (int i = 0; i < n; i++)
    {
        if (scanf("%d", &num) != 1)
        {
            freeQueue(newQueue);
            fclose(file);
            printf("Ошибка: можно вводить только целые числа");
        }
        push(newQueue, num);
    }

}

void freeQueue(Queue* q) {
    Node* current = q->front;
    Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    q->front = q->rear = NULL;
}

void push(Queue* q, int value) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (!temp) {
        freeQueue(q);
        exit(-1);
    }
    temp->data = value;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    q->rear->next = temp;
    q->rear = temp;
}

void printQueue(Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void selectionSortQueue(Queue* q) {
    if (q->front == NULL) return;

    Node* i = q->front;
    while (i != NULL) {
        Node* min = i;
        Node* j = i->next;
        while (j != NULL) {
            if (j->data < min->data) {
                min = j;
            }
            j = j->next;
        }
        if (min != i) {
            int temp = i->data;
            i->data = min->data;
            min->data = temp;
        }
        i = i->next;
    }
}

void writeQueueToFile(FILE* file, Queue* q) {
    Node* current = q->front;
    while (current != NULL) {
        fprintf(file, "%d ", current->data);
        current = current->next;
    }
}
