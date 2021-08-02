
/*
 *  @File        :   CircularList.cpp
 *  @Time        :   2021/08/02 10:41:32
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   循环单链表的实现
 */

#include <LinearList/LinerList.h>

class CircularList : public LinkedList<Node> {
  private:
    Node *head;

  public:
    CircularList();
    ~CircularList() override;
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

CircularList::CircularList() {
    cout << "Start to create CircularList" << endl;
    this->head = new Node();
    this->head->next = this->head;
}

CircularList::~CircularList() = default;

int CircularList::Length() {
    int cnt = 0;
    for (auto *p = this->head; p->next != this->head; p = p->next) { cnt++; }
    return cnt;
}

int CircularList::LocalElem(Node *e) {
    int cnt = 0;
    for (auto *p = this->head; p != head; p = p->next, cnt++) {
        if (p->data == e->data) return cnt;
    }
    return Error;
}

Node *CircularList::GetElem(int idx) {
    int cnt = 0;
    if (idx == 0) return this->head;
    for (auto *p = this->head->next; p != this->head; p = p->next, cnt++) {
        // cout << p << endl;
        if (cnt == idx - 1) { return p; }
    }
    return nullptr;
}

void CircularList::ListInsert(int idx, Node *e) {
    Node *pre = this->GetElem(idx - 1);

    if (pre == nullptr) {
        cout << "index error" << endl;
        if (this->head->next == this->head) {
            cout << "the link list is empty" << endl;
        }
    }
    e->next = pre->next;
    pre->next = e;
}

Node *CircularList::ListDelete(int idx) {
    // cout << idx << endl;
    Node *pre = this->GetElem(idx - 1);
    if (pre == nullptr || pre->next == this->head) return nullptr;
    Node *delVal = pre->next;
    pre->next = pre->next->next;
    return delVal;
}

void CircularList::PrintList() {
    cout << "len: " << this->Length() << "\n { ";
    for (auto p = this->head; p->next != this->head; p = p->next) {
        cout << p->next->data << ", ";
    }
    cout << "} \n" << endl;
}

void CircularList::InsertByHead(int *argv) {
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        Node *val = new Node(argv[i]);
        val->next = this->head->next;
        this->head->next = val;
    }
}

void CircularList::InsertByTail(int *argv) {
    Node *tail = this->head;
    for (int i = 0;; i++) {
        if (argv[i] == 9999) break;
        tail->next = new Node(argv[i]);
        tail = tail->next;
        tail->next = this->head;
    }
    tail = nullptr;
}

void CircularList::DeleteItem(Node *node) {
    // cout << "Del Node: " << node << endl;
    for (Node *p = this->head; p->next != this->head; p = p->next) {
        if (p->next->data == node->data) {
            Node *delItem = p->next;
            p->next = p->next->next;
            delete delItem;
            return;
        }
    }
}

int main() {
    CircularList *circularList = new CircularList();
    testLinkedList(circularList);
    testList(circularList);
}
