
/*
 *  @File        :   LinerList.cpp
 *  @Time        :   2021/08/01 15:17:01
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   线性表数据结构声明
 */

#ifndef DATA_STRUCT_LINERLIST_H
#define DATA_STRUCT_LINERLIST_H

#include <iostream>

using namespace std;

#define MaxSize 6
#define Error   -1

template <class T> class LinerList {
  public:
    LinerList() = default;
    virtual ~LinerList() = default;

    virtual int Length() = 0;
    virtual int LocalElem(T e) = 0;
    virtual T GetElem(int idx) = 0;
    virtual void ListInsert(int idx, T e) = 0;
    virtual T ListDelete(int idx) = 0;
    virtual void PrintList() = 0;
    // virtual void DestroyList();
};

template <class T> class LinkedList : public LinerList<T *> {
  public:
    virtual void InsertByHead(int argv[]) = 0;
    virtual void InsertByTail(int argv[]) = 0;
    virtual void DeleteItem(T *node) = 0;
};

class Node {
  public:
    int data;
    Node *next;

    ~Node() = default;

    Node() : data(0), next(nullptr) {}
    explicit Node(int val) : data(val), next(nullptr) {}

    bool operator==(Node &a) const { return this->data == a.data; }

    friend ostream &operator<<(ostream &out, Node *n) {
        out << "{ " << n->data << " } " << endl;
        return out;
    }
};

class DoubleNode {
  public:
    int data;
    DoubleNode *prev, *next;

    DoubleNode() : data(0), next(nullptr), prev(nullptr) {}
    explicit DoubleNode(int val) : data(val), next(nullptr), prev(nullptr) {}
    ~DoubleNode() = default;

    friend ostream &operator<<(ostream &out, DoubleNode *n) {
        out << "{ " << n->data << " }" << endl;
        return out;
    }
};

template <typename T> void testList(LinerList<T *> *list) {
    list->ListInsert(1, new T(99));
    list->PrintList();

    list->ListInsert(1, new T(100));
    list->PrintList();

    list->ListInsert(3, new T(98));
    list->PrintList();

    for (int i = 0; i < MaxSize; i++) {
        list->ListInsert(i + 1, new T(i + 6));
        list->PrintList();
    }

    cout << "Find 6's idx:" << list->LocalElem(new T(6)) << endl;
    cout << "Find 999's idx:" << list->LocalElem(new T(999)) << endl;

    for (int i = 0; i < MaxSize; i++) {
        auto delVal = list->ListDelete(i + 1);
        delVal == nullptr ? cout << "error \n"
                          : cout << "Del val: " << delVal << "\n\n";
    }
    list->PrintList();

    list->ListInsert(3, new T(9));
    list->PrintList();

    list->ListInsert(5, new T(6));
    list->PrintList();
}

template <typename T> void testLinkedList(LinkedList<T> *linkedList) {
    linkedList->InsertByHead(new int[]{2, 3, 9999});
    linkedList->PrintList();
    linkedList->DeleteItem(linkedList->GetElem(1));
    linkedList->DeleteItem(linkedList->GetElem(1));
    cout << "Delete item" << endl;
    linkedList->PrintList();

    linkedList->InsertByTail(new int[]{5, 6, 7, 8, 9999});
    linkedList->PrintList();
    linkedList->DeleteItem(linkedList->GetElem(1));
    linkedList->DeleteItem(linkedList->GetElem(1));
    linkedList->DeleteItem(linkedList->GetElem(2));
    cout << "Delete item" << endl;
    linkedList->PrintList();
}

#endif // DATA_STRUCT_LINERLIST_H
