/*
 *  @File        :   SingleLinkedList.cpp
 *  @Time        :   2021/08/01 21:22:39
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   单链表实现
 */

#include <LinearList/LinerList.h>

class SingleLinkedList : public LinerList<Node *> {
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
    void InsertByHead(int argv[]);
    void InsertByTail(int argv[]);
    void DeleteItem(Node *node);
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
    cout << idx << endl;
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
        Node *valNode = new Node(argv[i]);
        tail->next = valNode;
        tail = tail->next;
    }
    delete tail;
}

int main() {
    SingleLinkedList *singleLinkedList = new SingleLinkedList();
    singleLinkedList->InsertByHead(new int[]{2, 3, 9999});
    singleLinkedList->PrintList();

    SingleLinkedList *tailSingleLinkedList = new SingleLinkedList();
    tailSingleLinkedList->InsertByTail(new int[]{5, 6, 7, 8, 9999});
    tailSingleLinkedList->PrintList(), delete tailSingleLinkedList;

    singleLinkedList->ListInsert(1, new Node(99));
    singleLinkedList->PrintList();

    singleLinkedList->ListInsert(3, new Node(3));
    singleLinkedList->PrintList();

    for (int i = 0; i < MaxSize; i++) {
        singleLinkedList->ListInsert(i + 1, new Node(i + 6));
        singleLinkedList->PrintList();
    }

    cout << "Find 6' idx:" << singleLinkedList->LocalElem(new Node(6)) << endl;
    cout << "Find 999's idx:" << singleLinkedList->LocalElem(new Node(999))
         << endl;

    for (int i = 0; i < MaxSize; i++) {
        auto DelVal = singleLinkedList->ListDelete(i + 1);
        DelVal == nullptr ? cout << "error \n"
                          : cout << "Del val: " << DelVal << "\n\n";
    }
    singleLinkedList->PrintList();

    singleLinkedList->ListInsert(3, new Node(9));
    singleLinkedList->PrintList();

    singleLinkedList->ListInsert(5, new Node(6));
    singleLinkedList->PrintList();

    singleLinkedList->DeleteItem(new Node(9));
    singleLinkedList->PrintList();

    delete singleLinkedList;
}