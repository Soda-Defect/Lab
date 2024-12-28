
typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initializeQueue(Queue* q);
void readFile(FILE* file);
void checkToInt(FILE* file);
void createQueue(Queue* newQueue, FILE* file);
void freeQueue(Queue* q);
void push(Queue* q, int value);
void printQueue(Queue* q);
void selectionSortQueue(Queue* q);
void writeQueueToFile(FILE* file, Queue* q);
