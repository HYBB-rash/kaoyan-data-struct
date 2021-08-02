
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

class DoubleLinkedList : public LinkedList<DoubleNode> {
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
    void InsertByHead(int argv[]) override;
    void InsertByTail(int argv[]) override;
    void DeleteItem(DoubleNode *node) override;
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

void DoubleLinkedList::InsertByHead(int *argv) {
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        DoubleNode *node = new DoubleNode(argv[i]);
        node->next = this->head->next, node->prev = this->head;
        this->head->next->prev = node, this->head->next = node;
    }
}

void DoubleLinkedList::InsertByTail(int *argv) {
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        DoubleNode *node = new DoubleNode(argv[i]);
        node->next = this->tail, node->prev = this->tail->prev;
        this->tail->prev->next = node, this->tail->prev = node;
    }
}

void DoubleLinkedList::DeleteItem(DoubleNode *node) {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
}

int main() {
    DoubleLinkedList *doubleLinkedList = new DoubleLinkedList();

    testLinkedList(doubleLinkedList);
    testList(doubleLinkedList);

    return 0;
}