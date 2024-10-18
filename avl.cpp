#include <iostream>
#include "avl.h"

using namespace std;

AVL :: AVL(){
  root = NULL;
}

int AVL :: height(Node * node){
  return (node == NULL) ? -1 : node->height;
}

int AVL :: size(Node * node){
  return (node == NULL) ? 0 : node->size;
}

int AVL :: balanceFactor(Node * node){
  return (node == NULL) ? 0 : height(node->left) - height(node->right);
}

Node * AVL :: rotateRight(Node * node){
  Node* newRoot = node->left;
  node->left = newRoot->right;
  newRoot->right = node;
    
  // Update heights
  node->height = max(height(node->left), height(node->right)) + 1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

  // Update subtree sizes
  node->size = size(node->left) + size(node->right) + 1;
  newRoot->size = size(newRoot->left) + size(newRoot->right) + 1;

  return newRoot;
}

Node * AVL :: rotateLeft(Node* node) {
  Node* newRoot = node->right;
  node->right = newRoot->left;
  newRoot->left = node;
    
  // Update heights
  node->height = max(height(node->left), height(node->right)) + 1;
  newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

  // Update subtree sizes
  node->size = size(node->left) + size(node->right) + 1;
  newRoot->size = size(newRoot->left) + size(newRoot->right) + 1;

  return newRoot;
}

Node * AVL :: rotateLeftRight(Node* node) {
  node->left = rotateLeft(node->left);
  return rotateRight(node);
}

Node * AVL :: rotateRightLeft(Node* node) {
  node->right = rotateRight(node->right);
  return rotateLeft(node);
}

Node * AVL :: balance(Node* node) {
  // Update height and size of the current node
  node->height = max(height(node->left), height(node->right)) + 1;
  node->size = size(node->left) + size(node->right) + 1;

  int balanceFactorNode = balanceFactor(node);

  if (balanceFactorNode > 1) {  // Left heavy
    // Left-Right case
    if (balanceFactor(node->left) > 0) {
      node = rotateRight(node);
    }else{
      node = rotateLeftRight(node);
    }
  }else if (balanceFactorNode < -1) {  // Right heavy
    // Right-Left case
    if (balanceFactor(node->right) > 0) {
      node = rotateRightLeft(node);
    }else{
      node = rotateLeft(node);
    }
  }
  return node;
}

Node * AVL :: insert(Node* node, const string& key) {
  if (node == NULL) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 0;
    newNode->size = 1; // Single node in the subtree
    return newNode;
  }

  if (key < node->key) {
    node->left = insert(node->left, key);
  } else if (key > node->key) {
    node->right = insert(node->right, key);
  }

  // Update height and balance factor
  node->height = max(height(node->left), height(node->right)) + 1;
  return balance(node);
}

void AVL :: insert(const string& key) {
  root = insert(root, key);
}

void AVL :: countInRange(int * buffer, Node* node, const string& lower, const string& upper) {
  if (node == NULL) return;

  if(node->key >= lower && node->key <= upper){
    *buffer = node->size - findLower(node->left, lower) - findUpper(node->right, upper);
    return;
  }else if(node->key < lower){
    return countInRange(buffer, node->right, lower, upper);
  }else{
    return countInRange(buffer, node->left, lower, upper);
  }
}

int AVL :: findLower(Node * node, const string& lower){
  if(node == NULL) return 0;

  if(node->key < lower){
    int right = 0;
    if(node->right) right = node->right->size;
    return node->size - right + findLower(node->right,  lower);
  }
  return findLower(node->left, lower);
}

int AVL :: findUpper(Node * node, const string& upper){
  if(node == NULL) return 0;

  if(node->key > upper){
    int left = 0;
    if(node->left) left = node->left->size;
    return node->size - left + findUpper(node->left, upper);
  }
  return findUpper(node->right, upper);
}

int AVL :: countInRange(const string& lower, const string& upper){
  int buffer = 0;
  countInRange(&buffer, root, lower, upper);
  return buffer;
}

void AVL :: inorder(Node* node) {
  if (node == NULL) return;

  inorder(node->left);
  cout << node->key << " ";
  inorder(node->right);
}

void AVL :: inorder() {
  inorder(root);
  cout << endl;
}

void AVL :: deleteTree(Node * node){
  if(node == NULL) return;
  deleteTree(node->left);
  deleteTree(node->right);
  delete node;
}

void AVL :: deleteTree(){
  deleteTree(root);
  root = NULL;
}
