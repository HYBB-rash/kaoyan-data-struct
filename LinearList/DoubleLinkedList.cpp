
/*
 *  @File        :   DoubleLinkedList.cpp
 *  @Time        :   2021/08/01 23:18:49
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   双链表的实现
 */

#include <LinearList/LinerList.h>

using namespace std;

class DoubleLinkedList : public LinerList<DoubleNode *> {
  private:
    DoubleNode *head, *tail;

  public:
    DoubleLinkedList();
    ~DoubleLinkedList() = default;

    int Length() override;
    int LocalElem(DoubleNode *node) override;
    DoubleNode *GetElem(int idx) override;
    void ListInsert(int idx, DoubleNode *node) override;
    DoubleNode *ListDelete(int idx) override;
    void PrintList() override;

  public:
};

DoubleLinkedList::DoubleLinkedList() {
    this->head = new DoubleNode(0), this->tail = new DoubleNode(0);
    this->head->next = this->tail, this->tail->prev = this->head;
}

int DoubleLinkedList::Length() {
    int cnt = 0;
    for (DoubleNode *p = this->head; p->next != this->tail; p = p->next) {
        cnt++;
    }
    return cnt;
}

void DoubleLinkedList::ListInsert(int idx, DoubleNode *node) {
    int cnt = 0;
    for (DoubleNode *p = this->head; p != this->tail; p = p->next, cnt++) {
        if (cnt == idx - 1) {
            node->next = p->next, node->prev = p;
            p->next->prev = node, p->next = node;
            return;
        }
    }
    cout << "插入失败" << endl;
}

void DoubleLinkedList::PrintList() {
    cout << "len: " << this->Length() << ": { ";
    for (DoubleNode *p = this->head->next; p != this->tail; p = p->next) {
        cout << p->data << ", ";
    }
    cout << " }\n";
}

int DoubleLinkedList::LocalElem(DoubleNode *node) {
    int cnt = 0;
    for (auto *p = this->head; p != this->tail; p = p->next, cnt++) {
        if (p->data == node->data) return cnt;
    }
    return Error;
}

DoubleNode *DoubleLinkedList::GetElem(int idx) {
    int cnt = 0;
    for (auto *p = this->head; p != nullptr; p = p->next, cnt++) {
        if (cnt == idx) return p;
    }
    return nullptr;
}

DoubleNode *DoubleLinkedList::ListDelete(int idx) {
    auto *tar = this->GetElem(idx);
    if (tar == this->tail || tar == nullptr) return nullptr;
    tar->prev->next = tar->next;
    tar->next->prev = tar->prev;
    tar->next = tar->prev = nullptr;
    return tar;
}

int main() {
    DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();

    testList(doubleLinkedList);

    return 0;
}