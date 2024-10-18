#ifndef AVL_H
#define AVL_H

#include<string>

using namespace std;

struct Node{
  string key;
  int height;
  int size;
  Node * left;
  Node * right;
};

class AVL{
  private:
    Node * root;
    int height(Node *);
    int size(Node *);
    int balanceFactor(Node *);
    Node * rotateRight(Node *);
    Node * rotateLeft(Node *);
    Node * rotateLeftRight(Node *);
    Node * rotateRightLeft(Node *);
    Node * balance(Node *);
    Node * insert(Node *, const string& key);
    void countInRange(int *, Node * node, const string& lower, const string& upper);
    int findLower(Node *, const string&);
    int findUpper(Node *, const string&);
    void deleteTree(Node *);
    void inorder(Node *);
  public:
    AVL();
    void insert(const string& key);
    int countInRange(const string& lower, const string& upper);
    void inorder();
    void deleteTree();
};

#endif
