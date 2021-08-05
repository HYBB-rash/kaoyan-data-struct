
/*
 *  @File        :   note.cpp
 *  @Time        :   2021/08/05 14:57:00
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   栈 笔记
 */

#define MaxSize 50
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

typedef struct Linknode {
    ElemType data;
    struct Linknode *next;
} * LiStack;

typedef struct {
    ElemType data[MaxSize];
    int front, rear;
} SqQueue;
