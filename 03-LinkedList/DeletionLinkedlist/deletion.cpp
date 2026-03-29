#include <iostream>
using namespace std;

// Node class represents each element of the linked list
class Node {
public:
    int data;      // stores value
    Node* next;    // pointer to next node

    // Constructor
    Node(int value) {
        data = value;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;  // points to first node
    Node* tail;  // points to last node

public:
    // Constructor initializes empty list
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Insert element at the beginning
    void Insert_front(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if(head == NULL) {
            head = tail = newNode;
            return;
        }

        // Link new node before head
        newNode->next = head;
        head = newNode;
    }

    // Insert element at the end
    void Insert_back(int value) {
        Node* newNode = new Node(value);

        // If list is empty
        if(head == NULL) {
            head = tail = newNode;
            return;
        }

        // Attach new node after tail
        tail->next = newNode;
        tail = newNode;
    }

    // Insert element at a specific position (0-based index)
    void Insert_at_particu_pos(int value, int pos){
        // Insert at beginning
        if(pos == 0){
            Insert_front(value);
            return;
        }

        // Invalid position check
        if(pos < 0){
            cout << "Invalid Position\n";
            return;
        }

        Node* temp = head;

        // Traverse to (pos-1)th node
        for(int i = 0; i < pos - 1; i++){
            if(temp == NULL){
                cout << "Invalid Position\n";
                return;
            }
            temp = temp->next;
        }

        // Create new node
        Node* newNode = new Node(value);

        // Insert node
        newNode->next = temp->next;
        temp->next = newNode;

        // If inserted at last, update tail
        if(newNode->next == NULL){
            tail = newNode;
        }
    }

    // Delete first node
    void delete_front () {
        // If list is empty
        if (head == NULL){
            cout << "Empty Linked List\n";
            return;
        }

        // Store current head
        Node* temp = head;

        // Move head forward
        head = head->next;

        // Delete old head
        delete temp;

        // If list becomes empty, update tail
        if(head == NULL){
            tail = NULL;
        }
    }

    // Delete last node
    void delete_last () {
        // If list is empty
        if(head == NULL) {
            cout << "Empty Linked List\n";
            return;
        }

        // If only one node exists
        if(head == tail){
            delete head;
            head = tail = NULL;
            return;
        }

        // Traverse to second last node
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }

        // Delete last node
        delete tail;

        // Update tail
        tail = temp;
        tail->next = NULL;
    }

    // Search element and return its index
    int search (int key) {
        Node* temp = head;
        int idx = 0;

        // Traverse list
        while(temp != NULL){
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }

        // If not found
        return -1;
    }

    // Print all elements of linked list
    void PrintLinkedList() {
        Node* temp = head;

        // Traverse and print
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList bhan;

    // Insert at front
    bhan.Insert_front(5);
    bhan.Insert_front(15);
    bhan.Insert_front(25);

    // Insert at back
    bhan.Insert_back(33);
    bhan.Insert_back(53);
    bhan.Insert_back(73);

    // Insert at position
    bhan.Insert_at_particu_pos(100, 2);

    // Delete operations
    bhan.delete_front();
    bhan.delete_last();

    // Print list
    bhan.PrintLinkedList();

    // Search element
    cout << "Index of 33: " << bhan.search(33) << endl;

    return 0;
}