
#include "LinearList/LinerList.h"
#include <cstdio>
bool ListInsert(SeqList &L, int i, ElemType e) {
    if (i < 1 || i > L.length + 1) return false;
    if (L.length >= MaxSize) return false;
    for (int j = L.length; j >= i; j--) L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqlList &L, int i, ElemType &e) {
    if (i < 1 || i > L.length) return false;
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++) L.data[j - 1] = L.data[j];
    L.length--;
    return true;
}

int LocateElem(SqList L, ElemType e) {
    int i;
    for (i = 0; i < L.length; i++)
        if (L.data[i] == e) return i + 1;
    return -1;
}

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L) {
    LNode *s;
    int X;
    L = new LinkList();
    L->next = nullptr;
    while (scanf("%d", &X) != EOF) {
        s = new LNode();
        s->data = X, s->next = L->next;
        L->next = s;
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    int x;
    L = new LinkList();
    LNode *s, *r = L;
    while (scanf("%d", &x) != EOF) {
        s = new LNode();
        s->data = x, r->next = s;
        r = s;
    }
    r->next = nullptr;
    return L;
}

LNode *GetElem(LinkList L, int i) {
    int j = 1;
    LNode *p = L->next;
    if (i == 0) return L;
    if (i < 1) return nullptr;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocalElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != nullptr && p->data != e) p = p->next;
    return p;
}

void ListInsert_After(LinkList L, int i, ElemType e) {
    LNode *s = new LNode(), *p = GetElem(L, i - 1);
    if (p == nullptr || p->next == nullptr) return;

    s->data = e;
    s->next = p->next;
    p->next = s;
}

void ListInsert_After(LinkList L, int i, ElemType e) {
    LNode *s = new LNode(), *p = GetElem(L, i);
    s->data = e;
    s->next = p->next;
    p->next = s;
    swap(p->data, s->data);
}

void DeleteElem(LinkList L, int i) {
    LNode *p = GetElem(L, i - 1);
    if (p == nullptr || p->next == nullptr) return;
    LNode *q = p->next;
    p->next = q->next;
    delete q;
}

typedef struct DNode {
    ElemType data;
    struct DNode *prev, next;
} DNode, *DLinkList;

void ListInsert(DLinkList L, int i, ElemType e) {
    DNode *s = new DNode();
    s->data = e;

    DNode *p = GetElem(L, i);
    if (p != nullptr && p->next != nullptr)
        return ;
    s->next = p->next;
    s->prev = p;
    p->next->prev = s;
    p->next = s;
}

void ListDelete(DLinkList L, int i) {
    DNode *p = GetElem(L, i);
    if (p == nullptr || p->next == nullptr)
        return;
    p->next->prev = p->prev;
    p->prev->next = p->next;
    delete p;
}

typedef struct {
    ElemType data;
    int next;
} SLinkList[MaxSize];