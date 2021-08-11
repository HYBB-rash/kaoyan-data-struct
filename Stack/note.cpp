
/*
 *  @File        :   note.cpp
 *  @Time        :   2021/08/05 14:57:00
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   栈 笔记
 */

#define MaxSize  50
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

void InitStack(SqStack &S) { S.top = -1; }

bool StackEmpty(SqStack S) { return S.top == -1; }

bool Push(SqStack &S, ElemType x) {
    if (S.top == MaxSize - 1) return false;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {
    if (S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1) return false;
    x = S.data[S.top];
    return true;
}

typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
} * LiStack;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;

void InitQueue(SqQueue &Q) { Q.rear = Q.front = 0; }

bool isEmpty(SqQueue Q) { return Q.front == Q.rear; }

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front) return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (isEmpty(Q)) return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = new LinkNode();
    Q.front->next = nullptr;
}

bool IsEmpty(LinkQueue Q) { return Q.front == Q.rear; }

void EnQueue(LinkQueue &Q, ElemType x) {
    LinkNode *s = new LinkNode();
    s->data = x, s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &x) {
    if (IsEmpty(Q)) return false;
    LinkNode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if (Q.rear == p) Q.rear = Q.front;
    delete p;
    return true;
}