#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node *next;
    string str;
};

class Queue {
    private:
    Node *Head;
    public:
    Queue() {
        Head = nullptr;
    }
    ~Queue() {
        Node *tmp = Head;
        while (tmp) {
            tmp = tmp->next;
            delete Head;
            Head = tmp;
        }
    }
    void add(string str) {
        if(!Head) {
            Head = new Node;
            Head->str = str;
        }
        else {
            Node *tmp = Head;
            while (tmp->next) tmp = tmp->next;
            tmp->next = new Node;
            tmp->next->str = str;
        }
    }
    void remove() {
        Node *tmp = Head->next;
        delete Head;
        Head = tmp;
    }
    int length() {
        int i = 0;
        Node *tmp = Head;
        while(tmp) {
            i++;
            tmp = tmp->next;
        }
        return i;
    }
    void show() {
        Node *tmp = Head;
        while (tmp) {
            cout << tmp->str << endl;
            tmp = tmp->next;
        }
    }
    string head() {
        return Head->str;
    }
};

int main() {
    string str;
    Queue A[100];
    int i = 0;
    cout << "Queue: ";
    cin >> i;
    while(1) {
        cout << "> ";
        cin >> str;
        if (str == "quit") break;
        if (str == "add") {
            string text;
            cin >> text;
            if (text == "/head") {
                int tmp, tmp1;
                cin >> tmp1;
                cin >> tmp;
                if (tmp1 == 0) {
                    A[i].add(A[tmp].head());
                    A[tmp].remove();
                }
                else A[i].add(A[tmp].head());
            }
            else A[i].add(text);
        }
        if (str == "show") A[i].show();
        if (str == "remove") A[i].remove();
        if (str == "length") cout << A[i].length() << endl;
        if (str == "queue") cin >> i;
        if (str == "head") cout << A[i].head() << endl;
    }
    return 0;
}