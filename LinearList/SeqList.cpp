/* 
 *  @File        :   SeqList.cpp
 *  @Time        :   2021/08/01 21:22:54
 *  @Author      :   hyong
 *  @Version     :   1.0
 *  @Contact     :   hyong_cs@outlook.com
 *  @Description :   顺序表实现
 */
#include <LinearList/LinerList.h>

using namespace std;
class SeqList : public LinerList<int> {
  private:
    int *data;
    int length = 0, maxsize = 0;

  public:
    // SeqList(){};
    explicit SeqList(int cap = MaxSize, int length = 0);
    ~SeqList() override;
    int Length() override;
    int LocalElem(int e) override;
    int GetElem(int idx) override;
    void ListInsert(int idx, int e) override;
    int ListDelete(int idx) override;
    void PrintList() override;
};

SeqList::SeqList(int cap, int length) {
    cout << "Create SeqList" << endl;
    this->data = new int[cap];
    this->maxsize = cap;
    this->length = length;
}

SeqList::~SeqList() {
    cout << "Delete SeqList" << endl;
    delete data;
}

int SeqList::Length() { return this->length; }

int SeqList::LocalElem(int e) {
    for (int i = 0; i < this->length; i++) {
        if (data[i] == e) return i;
    }
    return Error;
}

int SeqList::GetElem(int idx) {
    if (!(idx > 0 && idx <= this->length)) {
        cout << "下标超出范围" << endl;
        return 0;
    }
    return this->data[idx];
}

void SeqList::ListInsert(int idx, int e) {
    if (!(idx > 0 && idx <= this->length + 1)) {
        cout << "下标超出范围" << endl;
        return;
    }
    if (this->length >= this->maxsize) {
        cout << "容量已满" << endl;
        return;
    }
    for (int i = this->length; i >= idx; i--) {
        this->data[i] = this->data[i - 1];
    }
    this->data[idx - 1] = e;
    this->length++;
}

int SeqList::ListDelete(int idx) {
    if (!(idx > 0 && idx <= this->length)) {
        cout << "下标超出范围" << endl;
        return Error;
    }

    int e = this->data[idx - 1];
    for (int i = idx; i < this->length; i++) {
        this->data[i - 1] = this->data[i];
    }
    this->length--;
    return e;
}

void SeqList::PrintList() {
    cout << "lenth: " << this->length << "\n{ ";
    for (int i = 0; i < this->length; i++) {
        cout << this->data[i] << ", ";
    }
    cout << "}\n" << endl;
}

int main() {

    SeqList *seqList = new SeqList();

    seqList->PrintList();

    // cout << seqList->Length() << endl;
    seqList->ListInsert(1, 1);
    seqList->PrintList();

    seqList->ListInsert(3, 3);
    seqList->PrintList();

    for (int i = 0; i < MaxSize; i++) {

        seqList->ListInsert(i + 1, i + 6);
        seqList->PrintList();
    }

    cout << "Find 666's idx: " << seqList->LocalElem(666) << endl;
    cout << "Find 999's idx: " << seqList->LocalElem(999) << endl;
    cout << endl;

    for (int i = 0; i < MaxSize; i++) {
        auto DelVal = seqList->ListDelete(i + 1);
        cout << "Del val: " << DelVal << endl << endl;
    }
    seqList->PrintList();

    seqList->ListInsert(3, 9);
    seqList->PrintList();
    seqList->ListInsert(5, 666);
    seqList->PrintList();
}