
#include "TreeT.h"

template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {

}

template<class T>
TreeT &TreeT<T>::operator=(const TreeT &otherTree) {
    return <#initializer#>;
}

template<class T>
void TreeT<T>::Add(T value) {

    Node* node = new Node;
    node->value = value;

    if (numNodes == 0){
        root = node;
        numNodes++;
        return;
    }

    Node* currN = root;
    Node* parent = nullptr;

    while (currN != nullptr){
        parent = currN;

        if (value < currN->value){
            currN = currN->left;
        }
        else if (value > currN->value){
            currN = currN->right;
        }
        else{
            delete node;
            return;
        }
    }

    if (value < parent->value){
        parent->left = node;
    }
    else{
        parent->right = node;
    }

    numNodes++;

    //alternate while loop
   /* while (currN != nullptr){
        if (value < currN->value){
            if (currN->left == nullptr){
                currN->left = node;
                break;
            }
            currN = currN->left;
        }
        else if (value > currN->value){
            if (currN->right == nullptr){
                currN->right = node;
                break;
            }
            currN = currN->right;
        }
        else{
            delete node;
            return;
        }
    }

    numNodes++;*/
}

template<class T>
void TreeT<T>::Remove(T value) {

}

template<class T>
bool TreeT<T>::Contains(T value) {
    Node* currN = root;

    while (currN != nullptr){

        if (value < currN->value){
            currN = currN->left;
        }
        else if (value > currN->value){
            currN = currN->right;
        }
        else{
            return true;
        }
    }

    return false;
}

template<class T>
int TreeT<T>::Size() {
    return 0;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {

}

template<class T>
T TreeT<T>::GetNextItem() {
    return nullptr;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::RemoveHelper(TreeT::Node *&subtree, T value) {

}

template<class T>
void TreeT<T>::DeleteNode(TreeT::Node *&subtree) {

}

template<class T>
void TreeT<T>::GetPredecessor(TreeT::Node *curr, T &value) {

}

template<class T>
void TreeT<T>::CopyHelper(TreeT::Node *&thisTree, TreeT::Node *otherTree) {

}

template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {

}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {

}

