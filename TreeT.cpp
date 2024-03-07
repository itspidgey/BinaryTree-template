
#include "TreeT.h"

template<class T>
TreeT<T>::TreeT() {
    root = nullptr;
    numNodes = 0;
}

template<class T>
TreeT<T>::~TreeT() {
    DestroyTree(root);
}

template<class T>
TreeT<T>::TreeT(const TreeT &otherTree) {
    CopyHelper(this->root, otherTree.root);
}

template<class T>
TreeT &TreeT<T>::operator=(const TreeT &otherTree) {

    if (this != &otherTree){
        DestroyTree(root);
        CopyOther(otherTree);
        numNodes = otherTree.numNodes;
    }

    return *this;
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
    return numNodes;
}

template<class T>
void TreeT<T>::ResetIterator(Order traverseOrder) {
    if (traverseOrder == IN_ORDER){
        PlaceInOrder(root);
    }
    else if (traverseOrder == PRE_ORDER){
        PlacePreOrder(root);
    }
    else if (traverseOrder == POST_ORDER){
        PlacePostOrder(root);
    }
}

template<class T>
T TreeT<T>::GetNextItem() {
    T nextItem = iterQue.front();
    iterQue.pop();
    return nextItem;
}

template<class T>
void TreeT<T>::DestroyTree(TreeT::Node *node) {

    if (node == nullptr){
        return;
    }

    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
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
    if (otherTree == nullptr){
        thisTree = nullptr;
        return;
    }
    thisTree = new Node;
    thisTree->value = otherTree->value;
    CopyHelper(thisTree->left,otherTree->left);
    CopyHelper(thisTree->right, otherTree->right);
}

template<class T>
void TreeT<T>::CopyOther(const TreeT &otherTree) {

}


template<class T>
void TreeT<T>::PlacePreOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }

    iterQue.push(node->value);
    PlacePreOrder(node->left);
    PlacePreOrder(node->right);
}

template<class T>
void TreeT<T>::PlacePostOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }

    PlacePostOrder(node->left);
    PlacePostOrder(node->right);
    iterQue.push(node->value);
}

template<class T>
void TreeT<T>::PlaceInOrder(TreeT::Node *node) {
    if (node == nullptr){
        return;
    }

    PlaceInOrder(node->left);
    iterQue.push(node->value);
    PlaceInOrder(node->right);
    iterQue.push(node->value);
}

