#include <iostream>
using namespace std;
 class Node {
    public: 
    int data;
    Node* next;

    /*constructor with Data and Next pointer*/

    Node (int value, Node* addre){
        data = value;
        next = addre;
    }
    /*Constructor with only data */ 
    
    Node(int value) {
        data = value;
        next = NULL;
    }
 };

 class LinkedList {
    private :
    Node* head;
    Node* tail;

    public:
    LinkedList(){
        head = NULL;
        tail = NULL;

    }

    /*Insertion at Begining*/ 

    void InsertionAtBegning(int val) {
        Node* newNode = new Node(val);

        if(head == NULL) {
            head = tail= newNode;
            return;
        }
        newNode->next=head;
        head = newNode;
    }

    void InsertionAtEnd(int val) {
        Node* newNode = new Node(val);

        if(head==NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void InsertAtPosition(int val , int pos){
        if(pos<=0){
            cout<<"Invalid Position \n";
            return;
        }
        if(pos == 1){
            InsertionAtBegning(val);
            return;
        }

        Node* temp = head;
        for(int i = 1 ; i < pos-1 && temp != NULL ; i++){
            temp = temp->next;
        }

        if(temp == NULL) {
            cout<<"Invalid Position \n";
            return;
        }

        if(temp == tail) {
            InsertionAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp ->next;
        temp->next = newNode;
    }

    // print 

    void print() {
        Node* temp = head;
        while(temp!= NULL) {
            cout<<temp->data << " ->" ;
            temp = temp->next;
        }

        cout<<"NULL";
    }
 };

int main() {

    LinkedList list;

    list.InsertionAtBegning(20);
    
    list.InsertionAtBegning(21);

    list.InsertionAtEnd(15);
    list.InsertionAtEnd(37);

    list.InsertAtPosition(9 , 3);

    list.print();

    return 0;
}