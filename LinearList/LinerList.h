
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

// template <typename T> void test_DySeqList(LinerList<T> *seqList, T argv[]);

#endif // DATA_STRUCT_LINERLIST_H
