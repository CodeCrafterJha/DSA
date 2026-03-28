/*Dynamic method to create node */

#include <iostream>
using namespace std;
class Node{
    public :
    int data;
    Node* next;

    // Constructor with data and next pointer (addres value)
    Node(int value , Node* addre){
        data = value;
        next = addre;
    } 
// Constructor with only data
    Node(int value) {
        data = value;
        next = NULL;
    }



};

int main () {

    Node *head;

    head = new Node(7);

    cout<<head->data<< " " << head->next << endl;
    return 0;
}