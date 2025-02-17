// Binary tree abstract base class
// Created by A. Student
// Modified by: Joseph Monge

#ifndef _BINARY_TREE
#define _BINARY_TREE

#include "BinaryNode.h"
#include "Queue.h"

template <class ItemType>
class BinaryTree
{
protected:
    BinaryNode<ItemType> *rootPtr; // ptr to root node
    int count;                     // number of nodes in tree

public:
    // "admin" functions
    BinaryTree()
    {
        rootPtr = 0;
        count = 0;
    }
    BinaryTree(const BinaryTree<ItemType> &tree) {}
    virtual ~BinaryTree() {}

    // common functions for all binary trees
    bool isEmpty() const { return count == 0; }
    int size() const { return count; }
    void clear()
    {
        destroyTree(rootPtr);
        rootPtr = 0;
        count = 0;
    }
    void preOrder(void visit(ItemType &)) const { _preorder(visit, rootPtr); }
    void inOrder(void visit(ItemType &)) const { _inorder(visit, rootPtr); }
    void postOrder(void visit(ItemType &)) const { _postorder(visit, rootPtr); }

    // abstract functions to be implemented by derived class
    virtual bool insert(const ItemType &newData) = 0;
    virtual bool remove(const ItemType &data) = 0;
    virtual bool getEntry(const ItemType &anEntry, ItemType &returnedItem) const = 0;

private:
    // delete all nodes from the tree
    void destroyTree(BinaryNode<ItemType> *nodePtr);

    // internal traverse
    void _preorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const;
    void _inorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const;
    void _postorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const;
};

//Destroy the entire tree
template <class ItemType>
void BinaryTree<ItemType>::destroyTree(BinaryNode<ItemType> *nodePtr)
{
    if (!nodePtr)
    {
    }

    else if (!nodePtr->getRightPtr() && !nodePtr->getLeftPtr())
    {
        delete nodePtr;
    }

    else if (nodePtr->getRightPtr())
    {
        destroyTree(nodePtr->getRightPtr());
    }

    else
    {
        destroyTree(nodePtr->getLeftPtr());
    }
}

//Preorder Traversal
template <class ItemType>
void BinaryTree<ItemType>::_preorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        visit(item);
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
    }
}

//Inorder Traversal
template <class ItemType>
void BinaryTree<ItemType>::_inorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        _preorder(visit, nodePtr->getLeftPtr());
        visit(item);
        _preorder(visit, nodePtr->getRightPtr());
    }
}

//Postorder Traversal
template <class ItemType>
void BinaryTree<ItemType>::_postorder(void visit(ItemType &), BinaryNode<ItemType> *nodePtr) const
{
    if (nodePtr != 0)
    {
        ItemType item = nodePtr->getItem();
        _preorder(visit, nodePtr->getLeftPtr());
        _preorder(visit, nodePtr->getRightPtr());
        visit(item);
    }
}

#endif