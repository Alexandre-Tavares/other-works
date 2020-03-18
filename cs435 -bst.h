#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_INPUT 256

class node{ //node for tree

    public:
        int data;
        node* right;
        node* left;
        node(int INPUT){
            data = INPUT;
        }
};
//(i*2)+1 left
//(i*2)+2 right
node* fromArray(int arr[], int index, int size, node *nodes){
    if(index<size){
        cout << index << endl;
        //checking if tree is possible
        nodes->data = arr[index];
        if(size > (index*2)+1){
        cout << index << endl;
        nodes->left = fromArray(arr, (index*2)+1, size, nodes->left); //recursively build left side of node tree
        }
        if(size > (index*2 +2)){
        cout << index << endl;
        nodes->right = fromArray(arr, (index*2)+2, size, nodes->right); //recursively build right side of node tree
        }
    }
return(nodes);
};

//toArray //returns array repersentation of tree
//isBST //returns true if tree is a binary tree
//preOrder //prints a pre-order reaversal of the tree
//postOrder //prints a post_order traversal of the tree
//numNodeInLookip //prints the number of nodes visted when looking for a specific value


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nodeNum;
    int nodeElement[nodeNum]; //an array of all tree elements
    int commandNum;
    char commandList[commandNum]; //an array of all commands

    cin >> nodeNum;
    cout << nodeNum << "number of node" << endl; //print check

    for(int i = 0; i < nodeNum; i++){
        cin >> nodeElement[i];
    }

    for(int i = 0; i < nodeNum; i++){ //print check
        cout << nodeElement[i]<<"in array" << endl;
    }

    cin >> commandNum;
    cout << commandNum<<"number of commands"<<endl; //print check

    for(int i = 0; i < commandNum; i++){
        cin >> commandList[i];
    }

    for(int i = 0; i < commandNum; i++){ //print check
        cout << commandList[i]<<"in command list" << endl;

    }
    switch(commandList[0]){
        case'a':
            cout << "-A in list-" << endl;
        case'b':
            cout << "-B in list-" << endl;
        default:
             cout << "-not in list-" << endl;
        }

    //switchcase here for commands string comparisions

    int sizeOF = nodeNum;
    cout << sizeOF << "how big" << endl;
    cout << "hello" << endl;
    if(sizeOF > 1){
        node *root;
        cout << "world" << endl;
        root = fromArray(nodeElement, 0, sizeOF, root);
        cout<< "Nyet" << endl;
    }else if(sizeOF <= 1){
        cout << "array size: " << sizeOF << endl;
        cout << "array of size one is a complete tree" << endl;
        return(1);
    }


    return(0);
}