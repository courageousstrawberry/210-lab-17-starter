#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void addAtHead(Node *&, float);
void addAtTail(Node *&, float);
void deleteNode(Node *&, int);
void insertNode(Node *&, float, float);
void deleteList(Node *&head);

int main() {
    Node *head = nullptr;
    int count = 0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        
        addAtHead(head, tmp_val);
    }
    output(head);

    cout << "Adding 5000 to the end of the linked list." << endl;
    addAtTail(head, 5000);

    output(head);

    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;

    deleteNode(head, entry);
    output(head);

    Node * current = head;
    Node *prev = head;
    // insert a node
    current = head;
    cout << "After which node to insert 10000? " << endl;
    count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;

    insertNode(head, entry, 1000);

    // deleting the linked list
    deleteList(head);

    // Check that list is deleted.
    output(head);
    return 0;
}

void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

void addAtHead(Node *&head, float number){
    Node *newVal = new Node;
    // adds node at head
    if (!head) { // if this is the first node, it's the new head
        head = newVal;
        newVal->next = nullptr;
        newVal->value = number;
    }
    else { // its a second or subsequent node; place at the head
        newVal->next = head;
        newVal->value = number;
        head = newVal;
    }
}

void addAtTail(Node *&head, float number) {
    Node *newVal = new Node;
    Node *current = head;

    newVal->value = number;
    newVal->next = nullptr;
    if (!head) {
        head = newVal;
    }
    else {
        while(current->next){
            current = current->next;
        }
        current->next = newVal;
    }
}

void deleteNode(Node *&head, int choice) {
    // Check if user wants to delete head pointer.
    if (choice == 1) {
        Node *temp = head;
        head = head->next;
        delete temp;
        temp = nullptr;
        return;
    }

    Node * current = head;
    // traverse that many times and delete that node
    Node *prev = head;
    for (int i = 0; i < (choice-1); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
        current = nullptr;
    }
}

void insertNode(Node *&head, float entry, float num){
    Node *current = head;
    Node *prev = head;
    for (int i = 0; i < (entry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = num;
    newnode->next = current;
    prev->next = newnode;
    output(head);
}

void deleteList(Node *&head) {
    Node *current = head;
    while (current) {
        head = current->next;
        delete current;
        current = head;
    }
    head = nullptr;
}