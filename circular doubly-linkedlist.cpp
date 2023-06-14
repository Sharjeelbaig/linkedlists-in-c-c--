#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class CircularDoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    CircularDoublyLinkedList() {
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
            newNode->prev = newNode;
            newNode->next = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    Node* search(int key) {
        if (head == nullptr) {
            return nullptr;
        }

        Node* temp = head;
        do {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        return nullptr;
    }

    void remove(int value) {
        if (head == nullptr) {
            return;
        }

        Node* curr = head;
        while (curr != tail) {
            if (curr->data == value) {
                if (curr == head) {
                    head = curr->next;
                    head->prev = tail;
                    tail->next = head;
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                delete curr;
                return;
            }
            curr = curr->next;
        }

        // Check tail node
        if (curr->data == value) {
            tail = curr->prev;
            tail->next = head;
            head->prev = tail;
            delete curr;
        }
    }

    void deleteByIndex(int index) {
        if (head == nullptr || index < 0) {
            return;
        }

        Node* curr = head;
        int count = 0;

        while (count != index) {
            curr = curr->next;
            count++;
        }

        if (curr == head) {
            head = curr->next;
            head->prev = tail;
            tail->next = head;
        } else if (curr == tail) {
            tail = curr->prev;
            tail->next = head;
            head->prev = tail;
        } else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    void sort() {
        if (head == nullptr || head->next == head) {
            return;
        }

        Node* current = head;
        Node* index = nullptr;
        int temp;

        do {
            index = current->next;
            while (index != head) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularDoublyLinkedList cdll;
    cdll.insert(3);
    cdll.insert(1);
    cdll.insert(2);
    cout << "displaying: \n";
    cdll.display();

    cout << "Searching: \n";
    Node* searchNode = cdll.search(2);
    if (searchNode != nullptr) {
        cout << "Key found: " << searchNode->data << endl;
    } else {
        cout << "Key not found" << endl;
    }

    cout << "removing: \n";
    cdll.remove(1);
    cdll.display();  // Output: 3 2

    cout << "delete by index: \n";
    cdll.deleteByIndex(0);
    cdll.display();

    cout << "sorting: \n";
    cdll.sort();
    cdll.display();  // Output: 2 3

    return 0;
}
