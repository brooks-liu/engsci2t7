typedef struct circqueue{
    int *data;
    int front;
    int back;
    int capacity;
} circqueue;

void create_circqueue(circqueue **p_p_q, int capacity)
{
    *p_p_q = (circqueue *)malloc(sizeof(circqueue));
    (*p_p_q)->data = (int *)malloc(sizeof(int)*capacity);
    (*p_p_q)->begin = 0;
    (*p_p_q)->end = 0;
    (*p_p_q)->capacity = capacity;
}

void enqueue(circqueue *q, int n)
{
    if((q->end+1)%q->capacity == q->begin){
        q->data = (int *)realloc(q->data, sizeof(int)*q->capacity*2);
        if(q->begin > q->end){
            memmove(q->data+q->capacity, q->data, sizeof(int)*q->end);
            q->end += q->capacity;
        }   
    }
    q->data[q->back] = n;
    q->back = (q->back+1)%q->capacity;
}

int dequeue(circqueue *q)
{
    int ind = q->front;
    q->front = (q->front+1)%q->capacity;
    return q->data[ind];
}