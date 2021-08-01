
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
    for (DoubleNode *p = this->head; p != this->tail;
         p = p->next, cnt++) {
        if (cnt == idx - 1) {
            node->next = p->next, node->prev = p;
            p->next->prev = node, p->next = node;
            return;
        }
    }
    cout << "插入失败" << endl;
}

void DoubleLinkedList::PrintList() {
    cout << this->Length() << ": { " ;
    for (DoubleNode *p = this->head->next; p != this->tail; p = p->next) {
        cout << p->data << ", ";
    }
    cout << " }\n";
}

int DoubleLinkedList::LocalElem(DoubleNode *node) { return 0; }

DoubleNode *DoubleLinkedList::GetElem(int idx) { return nullptr; }

DoubleNode *DoubleLinkedList::ListDelete(int idx) { return nullptr; }


int main() {
    DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();
    doubleLinkedList->ListInsert(1, new DoubleNode(2));
    doubleLinkedList->PrintList();

    doubleLinkedList->ListInsert(2, new DoubleNode(3));
    doubleLinkedList->PrintList();

    return 0;
}