#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
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


        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr && curr->data != value) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == nullptr) {
            return;  
        }


        prev->next = curr->next;
        delete curr;
    }

        void deleteByIndex(int index) {
        if (head == nullptr || index < 0) {
            return;
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* curr = head;
        int count = 0;

        while (curr != nullptr && count != index) {
            prev = curr;
            curr = curr->next;
            count++;
        }

        if (curr == nullptr) {
            return;
        }

        prev->next = curr->next;
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
    SinglyLinkedList sll;
    sll.insert(3);
    sll.insert(1);
    sll.insert(2);
    cout << "displaying: \n";
    sll.display();  
    
    cout << "Searching: \n";
    Node* searchNode = sll.search(2);
    if (searchNode != nullptr) {
        cout << "Key found: " << searchNode->data << endl;
    } else {
        cout << "Key not found" << endl;
    }

    cout << "removing: \n";
    sll.remove(1);
    sll.display();  // Output: 3 2

    cout << "delete by index: \n";
    sll.deleteByIndex(0);
    sll.display();

    cout << "sorting: \n";
    sll.sort();
    sll.display();  // Output: 2 3

    return 0;
}
