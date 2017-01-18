


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

/* make dequeue costly */
void enqueue(Queue *q, int data)
{
    Node* node = newNode(data);
    push(q->s1, node);
}

Node* dequeue(Queue *q)
{
    if (isEmpty(q->s1) && isEmpty(q->s2))
        return NULL;
    
    if (isEmpty(q->s2)) {
        Node *tmp;
        while (!isEmpty(q->s1)) {
            tmp = pop(q->s1);
            push(q->s2, tmp);
        }
    }
    return pop(q->s2);
}












