#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Singly LinkedList class
class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() {
        head = NULL; 
    }

    void addFirst(int value) {
        Node* newNode = new Node{value, head, NULL};
        head = newNode;
        cout << "Added " << value << " at the start.\n";
    }

    void addLast(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Added " << value << " at the end.\n";
    }

    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "First item deleted.\n";
        } else {
            cout << "List is empty!\n";
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void menu() {
        int choice;
        int value;
        do {
            cout << "\n1) Add First\n2) Add Last\n3) Delete First\n4) Display\n5) Return to Main Menu\nSelect: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: "; cin >> value;
                    addFirst(value); break;
                case 2:
                    cout << "Enter value: "; cin >> value;
                    addLast(value); break;
                case 3: deleteFirst(); break;
                case 4: display(); break;
                case 5: break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
};

// Doubly LinkedList class
class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList () {
        head = NULL;  
    }

    void addFirst(int value) {
        Node* newNode = new Node{value, head, NULL};
        if (head) head->prev = newNode;
        head = newNode;
        cout << "Added " << value << " at the start.\n";
    }

    void addLast(int value) {
        Node* newNode = new Node{value, NULL, NULL};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Added " << value << " at the end.\n";
    }

    void deleteFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            if (head) head->prev = NULL;
            delete temp;
            cout << "First item deleted.\n";
        } else {
            cout << "List is empty!\n";
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void menu() {
        int choice;
        int value;
        do {
            cout << "\n1) Add First\n2) Add Last\n3) Delete First\n4) Display\n5) Return to Main Menu\nSelect: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: "; cin >> value;
                    addFirst(value); break;
                case 2:
                    cout << "Enter value: "; cin >> value;
                    addLast(value); break;
                case 3: deleteFirst(); break;
                case 4: display(); break;
                case 5: break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
};

// Circular LinkedList class
class CircularLinkedList {
    Node* head;
public:
    CircularLinkedList() {
        head = NULL;  
    }

    void addFirst(int value) {
        Node* newNode = new Node{value, head, NULL};
        if (!head) {
            head = newNode;
            head->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << "Added " << value << " at the start.\n";
    }

    void addLast(int value) {
        Node* newNode = new Node{value, head, NULL};
        if (!head) {
            head = newNode;
            head->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Added " << value << " at the end.\n";
    }

    void deleteFirst() {
        if (head) {
            if (head->next == head) { 
                delete head;
                head = NULL;
            } else {
                Node* temp = head;
                while (temp->next != head) temp = temp->next;
                Node* toDelete = head;
                head = head->next;
                temp->next = head;
                delete toDelete;
            }
            cout << "First item deleted.\n";
        } else {
            cout << "List is empty!\n";
        }
    }

    void display() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(back to head)\n";
    }

    void menu() {
        int choice;
        int value;
        do {
            cout << "\n1) Add First\n2) Add Last\n3) Delete First\n4) Display\n5) Return to Main Menu\nSelect: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter value: "; cin >> value;
                    addFirst(value); break;
                case 2:
                    cout << "Enter value: "; cin >> value;
                    addLast(value); break;
                case 3: deleteFirst(); break;
                case 4: display(); break;
                case 5: break;
                default: cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }
};

int main() {
    int mainChoice;
    do {
        cout << "\nChoose Linked List Type:\n1) Singly LinkedList\n2) Doubly LinkedList\n3) Circular LinkedList\n4) Exit\nSelect: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {
                SinglyLinkedList sll;
                sll.menu();
                break;
            }
            case 2: {
                DoublyLinkedList dll;
                dll.menu();
                break;
            }
            case 3: {
                CircularLinkedList cll;
                cll.menu();
                break;
            }
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (mainChoice != 4);

    return 0;
}

