#include <iostream>
using namespace std;
// Node structure
class Node {
public:
    string data;
    Node* next;
    Node(string value) {
        data = value;
        next = nullptr;
    }
};
// Linked List Class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        head = nullptr;  // Start with empty list (Definiteness)
    }
    // Insert node at end (Effective operation)
    void insert(string value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {  // Finite traversal
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // Display list elements
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {  // Finite traversal
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // Search a value in the list
    void search(string key) {
        Node* temp = head;
        while (temp != nullptr) {  // Finite search
            if (temp->data == key) {
                cout << "Value " << key << " found.\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Value " << key << " not found.\n";
    }
    // Delete a node
    void remove(string key) {
        if (head == nullptr) {
            cout << "List empty.\n";
            return;
        }
        if (head->data == key) {
            Node* del = head;
            head = head->next;
            delete del;
            cout << "Deleted " << key << endl;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != key) {
            temp = temp->next;
        }
        if (temp->next == nullptr) {
            cout << "Value not found.\n";
        }
        else {
            Node* del = temp->next;
            temp->next = del->next;
            delete del;
            cout << "Deleted " << key << endl;
        }
    }
};
// Main � finite execution
int main() {
    LinkedList list;
    int choice;
    string value;   // <-- changed from int to string
    do {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert\n2. Display\n3. Search\n4. Delete\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;               // now reads string (keeps leading zeros)
            list.insert(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.remove(value);
            break;

        case 5:
            cout << "Exiting... \n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 5);
    return 0;
}