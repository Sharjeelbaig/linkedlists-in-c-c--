#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    Node* search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data == value) {
                if (curr == head) {
                    head = curr->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                } else if (curr == tail) {
                    tail = curr->prev;
                    if (tail != nullptr) {
                        tail->next = nullptr;
                    }
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }
    }

    void deleteByIndex(int index) {
        if (head == nullptr || index < 0) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        Node* curr = head;
        int count = 0;

        while (curr != nullptr && count != index) {
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) {
            return;
        }

        if (curr == tail) {
            tail = curr->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            }
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* current = head;
        Node* index = nullptr;
        int temp;

        while (current != nullptr) {
            index = current->next;
            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert(3);
    dll.insert(1);
    dll.insert(2);
    cout << "displaying: \n";
    dll.display();

    cout << "Searching: \n";
    Node* searchNode = dll.search(2);
    if (searchNode != nullptr) {
        cout << "Key found: " << searchNode->data << endl;
    } else {
        cout << "Key not found" << endl;
    }

    cout << "removing: \n";
    dll.remove(1);
    dll.display();  // Output: 3 2

    cout << "delete by index: \n";
    dll.deleteByIndex(0);
    dll.display();

    cout << "sorting: \n";
    dll.sort();
    dll.display();  // Output: 2 3

    return 0;
}
