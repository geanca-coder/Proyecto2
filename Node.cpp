//
// Created by geanc on 27 ene. 2022.
//

#include "Node.h"

Node::Node() {
    this->numItems = 0;
    this->parent = nullptr;
    childArray = new Node*[ORDER];
    itemArray = new NodeData*[ORDER];
    for(int i = 0 ; i <ORDER; i++) {
        childArray[i] = nullptr;
        itemArray[i] = nullptr;
    }

}


void Node::connectChild(int childNum, Node* child) {
    childArray[childNum] = child;
    if(child!= nullptr) child->parent = this;
}

Node *Node::disconnectChild(int childNum) {
    Node* tempNode = childArray[childNum];
    childArray[childNum] = nullptr;
    return tempNode;
}

Node *Node::getParent() {
    return parent;
}

Node *Node::getChild(int childNum) {
    return childArray[childNum];
}

bool Node::isLeaf() {
    return childArray[0] == nullptr;
}
int Node::getNumItems() {
    return numItems;
}

void Node::setNumItems(int theValue) {
    numItems = theValue;
}

NodeData *Node::getItem(int index) {
    return itemArray[index];
}

bool Node::isFull() {
    return numItems == ORDER-1;
}

NodeData *Node::setItem(int index, NodeData *theValue) {
    itemArray[index] = theValue;
    return itemArray[index];
}

int Node::insertItem(NodeData *item) {
    numItems++;
    int newKey = item->dData;

    for(int j = ORDER -2; j>=0;j--)
    {
        if(!itemArray[j]) continue;
        else{
            int itsKey = itemArray[j]->dData;
            if(newKey<itsKey) itemArray[j+1] = itemArray[j];
            else{
                itemArray[j+1] = item;
                return j+1;
            }
        }
    }
    itemArray[0] = item;
    return 0;
}

void Node::insertAtFront(NodeData* newItem) {
    int newKey = newItem->dData;
    numItems++;
    for(int j = numItems -1; j>0 ;j--)
    {
        itemArray[j] = itemArray[j-1];
        connectChild(j+1, disconnectChild(j));

    }
    connectChild(1, disconnectChild(0));
    itemArray[0] = newItem;
    connectChild(0, nullptr);
}

NodeData *Node::removeItem() {
    NodeData* temp = itemArray[numItems-1];
    itemArray[numItems-1] = nullptr;
    numItems--;
    return temp;
}

string Node::displayNode() {
    string nodes;
    for(int j = 0; j <numItems; j++) nodes+=*itemArray[j];
    return nodes;
}

string Node::displayValue(int j) {
    return *itemArray[j];
}

void Node::deleteNodeValue(int theValue) {
    int flag = -1;

    for (int i = 0; i < numItems; i++) {
        if (theValue == itemArray[i]->dData)flag = i;

        if (flag != -1 && i + 1 < numItems) itemArray[i]->dData = itemArray[i + 1]->dData;
    }
    itemArray[numItems - 1] = nullptr;
    numItems--;
}

void Node::deleteValue(int theValue, string side) {
    int flag = -1;
    for (int i = 0; i < numItems; i++) {
        if (theValue == itemArray[i]->dData) {
            flag = i;
        }
        if (flag != -1 && i + 1 < numItems) {
            itemArray[i]->dData = itemArray[i + 1]->dData;
        }
    }
    itemArray[numItems - 1] = nullptr;
    numItems--;
}

Node *Node::getSibling(int theValue) {
    Node*x = nullptr;
    Node* p = getParent();
    if (numItems != 0) {
        for (int i = 0; i <= p->numItems; i++) {
            if (p->childArray[i]->itemArray[0]->dData < theValue) {

                x = p->childArray[i];
            }
        }
    } else if (numItems == 0) {
        for (int i = 0; i <= p->numItems; i++) {
            if (p->childArray[i]->itemArray[0] == nullptr) {

                if (i != 0) {
                    x = p->childArray[i - 1];
                }
            }
        }
    }
    return x;
}

Node::~Node() {
    for(int i = 0; i <ORDER; i++){
        delete childArray[i];
        delete itemArray[i];
    }
    delete childArray;
    delete itemArray;
}
