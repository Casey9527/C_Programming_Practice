


typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* newNode(int data);

typedef struct Stack {
    int capacity;
    int size;
    Node *top;
} Stack;

Stack* newStack(int cap);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, Node* node);
Node* peek(Stack *s);
Node* pop(Stack *s);

typedef struct Queue {
    int capacity;
    int size;
    Stack *s1, *s2;
} Queue;

Queue* newQueue(int cap);

/* make enqueue costly */


void enqueue(Queue *q, int data)
{
    Node *node = newNode(data);
    Node *tmp;
    // move all in stack1 to stack2
    while (!isEmpty(q->s1)) {
        tmp = pop(q->s1);
        push(q->s2, tmp);
    }
    // push node to stack1
    push(q->s1, node);
    // move all in stack2 back to stack1
    while (!isEmpty(q->s2)) {
        tmp = pop(q->s2);
        push(q->s1, tmp);
    }
}

Node* dequeue(Queue *q)
{
    if (isEmptyq->s1)
        return NULL;
    return pop(q->s1);
}














