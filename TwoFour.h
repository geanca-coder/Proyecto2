//
// Created by geanc on 27 ene. 2022.
//

#ifndef DATASTRUCTURESPROJECT2_TWOFOUR_H
#define DATASTRUCTURESPROJECT2_TWOFOUR_H

#include "Node.h"
class TwoFour {
private:
    Node* root;
public:
    TwoFour();
    void insert(int dValue);
    void split(Node* thisNode);
    Node* getNextChild(Node* theNode,int theValue);
    string displayTree(int i);
    void recDisplayTree(Node* thisNode, int level,int childNumber, string &variable);
    void inOrderDisplay(Node* thisNode, int level, int childNumber, string &variable);
    Node* find(int theValue);
    Node* findValue(Node* theNode, int theValue);
    Node* erase(Node* currnode, int theValue);
    Node* deleteleaf_cases(Node* thisNode, int theValue);
    Node* balanceTree(Node* currnode);
    Node* getInOrderNode(Node* thisNode);
    ~TwoFour();
};


#endif //DATASTRUCTURESPROJECT2_TWOFOUR_H
