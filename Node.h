//
// Created by geanc on 27 ene. 2022.
//

#ifndef DATASTRUCTURESPROJECT2_NODE_H
#define DATASTRUCTURESPROJECT2_NODE_H
#include "NodeData.h"
#include <iostream>
using namespace std;
const int ORDER = 4;
class Node {
private:
    int numItems;
    Node *parent;
    Node **childArray;
    NodeData **itemArray;
public:
    Node();

    void connectChild(int childNum, Node* child);

    Node* disconnectChild(int childNum);

    Node* getChild(int childNum);

    Node* getParent();

    bool isLeaf();

    int getNumItems();

    void setNumItems(int theValue);

    NodeData* getItem(int index);

    NodeData* setItem(int index, NodeData*theValue);

    bool isFull();

    int  insertItem(NodeData *item);

    void insertAtFront(NodeData *newitem);

    NodeData *removeItem();

    string displayNode();

    string displayValue(int j);

    void deleteNodeValue(int theValue);

    void deleteValue(int theValue, string side);

    Node* getSibling(int theValue);

    ~Node();

};


#endif //DATASTRUCTURESPROJECT2_NODE_H
