/*
 *  @File        :   SingleLinkedList.cpp
 *  @Time        :   2021/08/01 21:22:39
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   单链表实现
 */

#include <LinearList/LinerList.h>

class SingleLinkedList : public LinkedList<Node> {
  private:
    Node *head;

  public:
    SingleLinkedList();
    ~SingleLinkedList() override;
    int Length() override;
    int LocalElem(Node *e) override;
    Node *GetElem(int idx) override;
    void ListInsert(int idx, Node *e) override;
    Node *ListDelete(int idx) override;
    void PrintList() override;

  public:
    void InsertByHead(int argv[]) override;
    void InsertByTail(int argv[]) override;
    void DeleteItem(Node *node) override;
};

SingleLinkedList::SingleLinkedList() {
    cout << "Create SingleLinkedList!" << endl;
    this->head = new Node();
}

SingleLinkedList::~SingleLinkedList() { delete head; }

int SingleLinkedList::Length() {
    int cnt = 0;
    for (Node *p = this->head; p->next != nullptr; p = p->next) { cnt++; }
    return cnt;
}

int SingleLinkedList::LocalElem(Node *e) {
    int cnt = 0;
    for (Node *p = this->head; p != nullptr; p = p->next) {
        if (*p == *e) return cnt;
        cnt++;
    }
    return Error;
}

Node *SingleLinkedList::GetElem(int idx) {
    int cnt = 0;
    for (Node *p = this->head; p != nullptr; p = p->next, cnt++) {
        if (cnt == idx) return p;
    }
    return nullptr;
}

void SingleLinkedList::ListInsert(int idx, Node *e) {
    Node *pre = this->GetElem(idx - 1);
    if (pre == nullptr) {
        cout << "下标错误" << endl;
        if (head->next == nullptr) { cout << "，或者链表为空" << endl; }
        return;
    }
    e->next = pre->next;
    pre->next = e;
}

Node *SingleLinkedList::ListDelete(int idx) {
    Node *pre = this->GetElem(idx - 1);
    if (pre == nullptr || pre->next == nullptr) { return nullptr; }
    Node *DelVal = pre->next;
    pre->next = pre->next->next;
    return DelVal;
}

void SingleLinkedList::PrintList() {
    cout << "lenth: " << this->Length() << "\n{ ";
    for (Node *p = this->head; p->next != nullptr; p = p->next) {
        cout << p->next->data << ", ";
    }
    cout << "}\n" << endl;
}

void SingleLinkedList::InsertByHead(int argv[]) {
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        Node *ValNode = new Node(argv[i]);
        ValNode->next = this->head->next;
        this->head->next = ValNode;
    }
}

void SingleLinkedList::DeleteItem(Node *node) {
    for (Node *p = this->head; p->next != nullptr; p = p->next) {
        if (*p->next == *node) {
            Node *DelItem = p->next;
            p->next = p->next->next;
            delete DelItem;
            return;
        }
    }
}

void SingleLinkedList::InsertByTail(int argv[]) {
    Node *tail = this->head;
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        tail->next = new Node(argv[i]);
        tail = tail->next;
    }
    tail = nullptr;
    // delete tail;
}

int main() {
    SingleLinkedList *singleLinkedList = new SingleLinkedList();

    testLinkedList(singleLinkedList);
    testList(singleLinkedList);
    
    
    delete singleLinkedList;
}