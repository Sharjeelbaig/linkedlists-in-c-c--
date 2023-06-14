#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
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
        Node* prev = nullptr;
        while (curr->next != head) {
            if (curr->data == value) {
                if (prev == nullptr) {
                    Node* lastNode = head;
                    while (lastNode->next != head) {
                        lastNode = lastNode->next;
                    }
                    head = curr->next;
                    lastNode->next = head;
                } else {
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        // Check last node
        if (curr->data == value) {
            if (prev == nullptr) {
                head = nullptr;
            } else {
                prev->next = head;
            }
            delete curr;
        }
    }

    void deleteByIndex(int index) {
        if (head == nullptr || index < 0) {
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;
        int count = 0;

        while (count != index) {
            prev = curr;
            curr = curr->next;
            count++;
            if (curr == head) {
                return;  // Index out of bounds
            }
        }

        if (prev == nullptr) {
            Node* lastNode = head;
            while (lastNode->next != head) {
                lastNode = lastNode->next;
            }
            head = curr->next;
            lastNode->next = head;
        } else {
            prev->next = curr->next;
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
    CircularLinkedList cll;
    cll.insert(3);
    cll.insert(1);
    cll.insert(2);
    cout << "displaying: \n";
    cll.display();

    cout << "Searching: \n";
    Node* searchNode = cll.search(2);
    if (searchNode != nullptr) {
        cout << "Key found: " << searchNode->data << endl;
    } else {
        cout << "Key not found" << endl;
    }

    cout << "removing: \n";
    cll.remove(1);
    cll.display();  // Output: 3 2

    cout << "delete by index: \n";
    cll.deleteByIndex(0);
    cll.display();

    cout << "sorting: \n";
    cll.sort();
    cll.display();  // Output: 2 3

    return 0;
}
