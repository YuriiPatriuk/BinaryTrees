#include <iostream>
#include "Tree.h"
#include <ctime>
using namespace std;

int main()
{
    srand(unsigned(time(0)));
    cout << "Hello, binary tree!" << endl << endl;

    BinaryTree<int> tree;
   /* cout <<"Size: "<< tree.getSize() << endl;
    cout <<"Is Empty: "<<boolalpha<< tree.empty() << endl;
   */ 
    size_t count = 5;
    for (size_t i = 0; i < count; i++)
    {
        int data = rand() % 100;
        cout << "Add node " << data << endl;
        tree.add(data);
    }
    cout << "Size: " << tree.getSize() << endl << endl;
    tree.print();
    cout << "Max: " << tree.max() << endl;
    cout << "Min: " << tree.min() << endl;
    //tree.clear();
    //tree.print();
    //cout << "Max: " << tree.max() << endl;
    //cout << "Min: " << tree.min() << endl;
    cout <<"Find: "<< boolalpha << tree.find(7) << endl;
    cout <<"Find: "<< boolalpha << tree.find(5) << endl;
    cout <<"Find: "<< boolalpha << tree.find(1) << endl;
    //tree.printBigger(6);
    tree.clear();

    return 0;
}