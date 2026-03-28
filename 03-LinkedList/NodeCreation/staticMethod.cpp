/* Static way to create node */


#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* Next; 
};

int main () {
    Node A1;
    A1.data = 4;
    A1.Next = NULL;
    cout<<A1.data << endl;
    cout<<A1.Next <<endl;
return 0;
}
