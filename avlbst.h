#ifndef AVLBST_H
#define AVLBST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "bst.h"

struct KeyError { };

/**
* A special kind of node for an AVL tree, which adds the balance as a data member, plus
* other additional helper functions. You do NOT need to implement any functionality or
* add additional data members or helper functions.
*/
template <typename Key, typename Value>
class AVLNode : public Node<Key, Value>
{
public:
    // Constructor/destructor.
    AVLNode(const Key& key, const Value& value, AVLNode<Key, Value>* parent);
    virtual ~AVLNode();

    // Getter/setter for the node's height.
    int8_t getBalance () const;
    void setBalance (int8_t balance);
    void updateBalance(int8_t diff);

    // Getters for parent, left, and right. These need to be redefined since they
    // return pointers to AVLNodes - not plain Nodes. See the Node class in bst.h
    // for more information.
    virtual AVLNode<Key, Value>* getParent() const override;
    virtual AVLNode<Key, Value>* getLeft() const override;
    virtual AVLNode<Key, Value>* getRight() const override;

protected:
    int8_t balance_;    // effectively a signed char
};

/*
  -------------------------------------------------
  Begin implementations for the AVLNode class.
  -------------------------------------------------
*/

/**
* An explicit constructor to initialize the elements by calling the base class constructor
*/
template<class Key, class Value>
AVLNode<Key, Value>::AVLNode(const Key& key, const Value& value, AVLNode<Key, Value> *parent) :
    Node<Key, Value>(key, value, parent), balance_(0)
{

}

/**
* A destructor which does nothing.
*/
template<class Key, class Value>
AVLNode<Key, Value>::~AVLNode()
{

}

/**
* A getter for the balance of a AVLNode.
*/
template<class Key, class Value>
int8_t AVLNode<Key, Value>::getBalance() const
{
    return balance_;
}

/**
* A setter for the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::setBalance(int8_t balance)
{
    balance_ = balance;
}

/**
* Adds diff to the balance of a AVLNode.
*/
template<class Key, class Value>
void AVLNode<Key, Value>::updateBalance(int8_t diff)
{
    balance_ += diff;
}

/**
* An overridden function for getting the parent since a static_cast is necessary to make sure
* that our node is a AVLNode.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getParent() const
{
    return static_cast<AVLNode<Key, Value>*>(this->parent_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getLeft() const
{
    return static_cast<AVLNode<Key, Value>*>(this->left_);
}

/**
* Overridden for the same reasons as above.
*/
template<class Key, class Value>
AVLNode<Key, Value> *AVLNode<Key, Value>::getRight() const
{
    return static_cast<AVLNode<Key, Value>*>(this->right_);
}


/*
  -----------------------------------------------
  End implementations for the AVLNode class.
  -----------------------------------------------
*/


template <class Key, class Value>
class AVLTree : public BinarySearchTree<Key, Value>
{
public:
    virtual void insert (const std::pair<const Key, Value> &new_item); // TODO
    virtual void remove(const Key& key);  // TODO
protected:
    virtual void nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2);

    // Add helper functions here
    void insertFix(AVLNode<Key, Value>*& parent, AVLNode<Key, Value>*& child);

    // Double right rotation, for when child and parent have negative balance
    void ZigZigLeft(AVLNode<Key, Value>*& child);

    // Right rotation, left rotation, for when parent has negative bal, and child has positive bal
    void ZigZagLeft(AVLNode<Key, Value>*& child); 

    // Double left rotation, for when child and parent have positive balance
    void ZigZigRight(AVLNode<Key, Value>*& child);

    // Left rotation, right rotation, for when parent has positive bal, and child has negative bal
    void ZigZagRight(AVLNode<Key, Value>*& child);

    virtual int countHeight(AVLNode<Key,Value>* n1); 

    void removeFix(AVLNode<Key, Value>*& node, int diff); 

    // Adjusts balance for each node traversed
    // AVLNode<Key, Value>* avlFind(const Key& key) const; 

};

/*template<class Key, class Value>
AVLNode<Key, Value>* AVLTree<Key, Value>::avlFind (const Key& key) const{
    if (this->root_ == nullptr){
        return nullptr; 
    }
    
    this->root_->setBalance(0);
    if (this->root_->getLeft() != nullptr){
        this->root_->updateBalance(-(countHeight(this->root_->getLeft()))); 
    }

    if (this->root_->getRight() != nullptr){
        this->root_->updateBalance(countHeight(this->root_->getRight()));
    }

    if (this->root_->getKey() == key){
        return this->root_; 
    }

    else if (this->root_->getKey() > key){
        Node<Key, Value>* wantedVal = this->root_->getLeft(); 

        wantedVal->setBalance(0);
        if (wantedVal->getLeft() != nullptr){
            wantedVal->updateBalance(-(countHeight(wantedVal->getLeft()))); 
        }

        if (wantedVal->getRight() != nullptr){
            wantedVal->updateBalance(countHeight(wantedVal->getRight()));
        }

        while (wantedVal != nullptr){
            if (wantedVal->getKey() == key){
                return wantedVal; 
            }

            else if (wantedVal->getKey() > key){
                wantedVal = wantedVal->getLeft(); 
            }

            else if (wantedVal->getKey() < key){
                wantedVal = wantedVal->getRight();
            }
        }

        // If it finished while loop, it means wantedVal is nullptr; 
        return nullptr; 
    }

    else if (this->root_->getKey() <= key){

        Node<Key, Value>* wantedVal = this->root_->getLeft(); 

        wantedVal->setBalance(0);
        if (wantedVal->getLeft() != nullptr){
            wantedVal->updateBalance(-(countHeight(wantedVal->getLeft()))); 
        }

        if (wantedVal->getRight() != nullptr){
            wantedVal->updateBalance(countHeight(wantedVal->getRight()));
        }

        Node<Key, Value>* wantedVal = this->root_->getRight(); 
        while (wantedVal != nullptr){
            if (wantedVal->getKey() == key){
                return wantedVal;
            }

            else if (wantedVal->getKey() > key){
                wantedVal = wantedVal->getLeft(); 
            }

            else if (wantedVal->getKey() < key){
                wantedVal = wantedVal->getRight();
            }
        }
    }

    return nullptr; 
}
*/

/*
 * Recall: If key is already in the tree, you should 
 * overwrite the current value with the updated value.
 */
template<class Key, class Value>
void AVLTree<Key, Value>::insert (const std::pair<const Key, Value> &new_item)
{
    // std::cout << new_itemm.first << std::endl; 
    // TODO
    // If root is null, then set root to newItem
    // Else, 
    // find if the node exists, and update value
    // If does not exist, insert like bst
    
    // If key is in tree
    // std::cout << "INSERT: " << new_item.first << std::endl; 
    Node<Key, Value>* checkDup = this->internalFind(new_item.first);

    if (checkDup != nullptr){
        checkDup->setValue(new_item.second);
        return;
    }

    AVLNode<Key, Value>* newNode = new AVLNode<Key, Value>(new_item.first, new_item.second, nullptr);
    
    // If root is nullptr 
    if (this->root_ == nullptr){ 
        this->root_ = newNode;
        newNode->setBalance(0);
        return;
    }

    // If key is not in the tree
    AVLNode<Key, Value>* currNode = static_cast<AVLNode<Key, Value>*>(this->root_);
    while (currNode != nullptr){
        // If newNodei s less than currNode
        if (newNode->getKey() < currNode->getKey()){
            // If left child exists, traverse to left child
            if (currNode->getLeft() != nullptr){
                currNode = currNode->getLeft();
            }

            // If left child doesn't exist, set newNode as left child
            // Set newNode's parent as currNode
            // Adjust balance of both parent and child
            else if (currNode->getLeft() == nullptr){
                currNode->setLeft(newNode);
                newNode->setParent(currNode);

                newNode->setBalance(0); 
                currNode->setBalance(0);

                if (currNode->getLeft() != nullptr){
                    currNode->updateBalance(-1); 
                }

                if (currNode->getRight() != nullptr){
                    currNode->updateBalance(1);
                }

                // If new balance is not 0 (-1 since it is a left insertion)
                if (currNode->getBalance() != 0){
                    insertFix(currNode, newNode); 
                }

                return;
            }
        }

        // If newNode is greater than currNode
        else if (newNode->getKey() > currNode->getKey()){
            // If right child exists, traverse to right child
            if (currNode->getRight() != nullptr){
                currNode = currNode->getRight(); 
            }

            // If right child doesn't exist, set newNode as right child
            // Set newNode's parent as currNode
            // Adjust balnace of both parent and child
            else if (currNode->getRight() == nullptr){
                currNode->setRight(newNode);
                newNode->setParent(currNode); 

                newNode->setBalance(0);
                currNode->setBalance(0);
                
                if (currNode->getLeft() != nullptr){
                    currNode->updateBalance(-1); 
                }

                if (currNode->getRight() != nullptr){
                    currNode->updateBalance(1);
                }
            
                // If new balance is not 0 (-1 or 1)
                if (currNode->getBalance() != 0){
                    insertFix(currNode, newNode); 
                }
                return;
            }
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>::insertFix(AVLNode<Key, Value>*& parent, AVLNode<Key, Value>*& child){
    AVLNode<Key, Value>* grandParent = parent->getParent(); 
    // If parent or grandparent is null, return
    if (parent == nullptr || grandParent == nullptr){
        return; 
    }

    // If parent is the left child of grandparent
    if (parent->getKey() < grandParent->getKey()){
        grandParent->setBalance(0);
        if (grandParent->getLeft() != nullptr){
            grandParent->updateBalance(-(countHeight(grandParent->getLeft()))); 
        }

        if (grandParent->getRight() != nullptr){
            grandParent->updateBalance(countHeight(grandParent->getRight()));
        }
        
        // grandParent->updateBalance(-1);

        if (grandParent->getBalance() == 0){
            return; 
        }

        else if (grandParent->getBalance() == -1){
            insertFix(grandParent, parent); 
        }

        else if (grandParent->getBalance() == -2){
            if (parent->getBalance() < 0){
                ZigZigLeft(child); 
            }


            else if (parent->getBalance() > 0){
                ZigZagLeft(child);
            }
        }
    }

    // If the parent is the right child of grandParent
    else if (parent->getKey() > grandParent->getKey()){
        grandParent->setBalance(0);
        if (grandParent->getLeft() != nullptr){
            grandParent->updateBalance(-(countHeight(grandParent->getLeft()))); 
        }

        if (grandParent->getRight() != nullptr){
            grandParent->updateBalance(countHeight(grandParent->getRight()));
        }
        
        // grandParent->updateBalance(1);

        if (grandParent->getBalance() == 0){
            return;
        }

        else if (grandParent->getBalance() == 1){
            insertFix(grandParent, parent); 
        }

        else if (grandParent->getBalance() == 2){
            // std::cout << parent->getBalance();
            if (parent->getBalance() > 0){
                ZigZigRight(child); 
            }


            
            else if (parent->getBalance() < 0){
                
                ZigZagRight(child);
            }
        }
    }
    
}

template<class Key, class Value>
void AVLTree<Key, Value>::ZigZigLeft(AVLNode<Key, Value>*& child){
    // Case 1: Zig-Zig, reminder it's the left child
    // A Zig-Zig case is when both the grandParent and parent have negative balance for left case


    // Zig-Zig:
    // Set parent as parent of grandparent
    // Set grandparent as right child of parent
    // Keep left child as left child of parent
    // AVLNode<Key, Value>* parentLeft = parent->getLeft();
    AVLNode<Key, Value>* parent = child->getParent(); 
    AVLNode<Key, Value>* grandParent = parent->getParent(); 
    AVLNode<Key, Value>* parentRight = parent->getRight(); 

    parent->setParent(grandParent->getParent());
    if (parent->getParent() != nullptr){
        if (parent->getKey() < parent->getParent()->getKey()){
            parent->getParent()->setLeft(parent); 
        }

        else if (parent->getKey() > parent->getParent()->getKey()){
            parent->getParent()->setRight(parent); 
        }
    }
    
    if (parent->getParent() == nullptr){
        this->root_ = parent; 
    }

    parent->setRight(grandParent);
    grandParent->setParent(parent);

    grandParent->setLeft(parentRight); 
    if (parentRight != nullptr){
        parentRight->setParent(grandParent); 
    }
    
    grandParent->setBalance(0);
    if (grandParent->getLeft() != nullptr){
        grandParent->updateBalance(-1);
    }

    if (grandParent->getRight() != nullptr){
        grandParent->updateBalance(1); 
    }

    parent->setBalance(0); 
    if (parent->getLeft() != nullptr){
        parent->updateBalance(-1);
    }

    if (parent->getRight() != nullptr){
        parent->updateBalance(1); 
    }

    return;
}

template<class Key, class Value>
void AVLTree<Key, Value>::ZigZagLeft(AVLNode<Key, Value>*& child){
    // Case 2: Zig-Zag, reminder it's the left child
    // A Zig-Zag case is when the grandParent has negative balance and parent has positive balance for left case
    // IG:
    // Set child to parent, set parent to left child, set grandparent to right child

    // Original children of child
    // std::cout << "YES" << std::endl;
    
    AVLNode<Key, Value>* parent = child->getParent();
    AVLNode<Key, Value>* grandParent = parent->getParent();
    AVLNode<Key, Value>* greatGrandParent = grandParent->getParent();

    AVLNode<Key, Value>* childLeft = child->getLeft();
    AVLNode<Key, Value>* childRight = child->getRight(); 

    // Make child the parent of originalParent and originalGrandParent
    child->setParent(greatGrandParent);

    // If child's new parent is nullptr, then make it the root 
    if (greatGrandParent== nullptr){
        this->root_ = child; 
    }

    else if (greatGrandParent != nullptr){
        if (child->getKey() > greatGrandParent->getKey()){
            greatGrandParent->setRight(child);
        }

        else if (child->getKey() < greatGrandParent->getKey()){
            greatGrandParent->setLeft(child);
        }
    }

    // originalParent is now the left child
    parent->setParent(child); 
    child->setLeft(parent); 

    // originalGrandParent is now the right child
    grandParent->setParent(child);
    child->setRight(grandParent); 

    // set (original)grandParent's left to (original)child's right 
    // (keep grandParent's right)
    grandParent->setLeft(childRight);
    if (childRight != nullptr){
        childRight->setParent(grandParent);
    }

    // set (original)parent's right to (original)child's left
    // (keep parent's left)
    parent->setRight(childLeft);
    if (childLeft != nullptr){
        childLeft->setParent(parent); 
    }

    parent->setBalance(0); 
    if (parent->getLeft() != nullptr){
        parent->updateBalance(-1);
    }

    if (parent->getRight() != nullptr){
        parent->updateBalance(1); 
    }

    grandParent->setBalance(0);
    if (grandParent->getLeft() != nullptr){
        grandParent->updateBalance(-1);
    }

    if (grandParent->getRight() != nullptr){
        grandParent->updateBalance(1); 
    }

    return; 
}

template<class Key, class Value>
void AVLTree<Key, Value>::ZigZigRight(AVLNode<Key, Value>*& child){
    // Case 1: Zig-Zig, reminder it's the right child
    // A Zig-Zig case is where both the grandParent and parent have postiive balance

    // Zig-Zig:
    // Set parent as parent of grandparent
    // Set gradnparent as left child of parent
    // Keep right child as the right child of parent
    
    AVLNode<Key, Value>* parent = child->getParent();
    AVLNode<Key, Value>* grandParent = parent->getParent();

    AVLNode<Key, Value>* parentLeft = parent->getLeft(); 
    // AVLNode<Key, Value>* parentRight = parent->getRight(); 

    parent->setParent(grandParent->getParent());
    if (parent->getParent() != nullptr){
        if (parent->getKey() < parent->getParent()->getKey()){
            parent->getParent()->setLeft(parent); 
        }

        else if (parent->getKey() > parent->getParent()->getKey()){
            parent->getParent()->setRight(parent); 
        }
    }

    else if (parent->getParent() == nullptr){
        this->root_ = parent;
    }

    parent->setLeft(grandParent);
    grandParent->setParent(parent);

    grandParent->setRight(parentLeft);
    if (parentLeft != nullptr){
        parentLeft->setParent(grandParent);
    }

    parent->setBalance(0); 
    if (parent->getLeft() != nullptr){
        parent->updateBalance(-1);
    }

    if (parent->getRight() != nullptr){
        parent->updateBalance(1); 
    }

    grandParent->setBalance(0);
    if (grandParent->getLeft() != nullptr){
        grandParent->updateBalance(-1);
    }

    if (grandParent->getRight() != nullptr){
        grandParent->updateBalance(1); 
    }

    return;
}

template<class Key, class Value>
void AVLTree<Key, Value>::ZigZagRight(AVLNode<Key, Value>*& child){
    // Case 2: Zig-Zag, reminder it's the right child
    // A Zig-Zag case is when the grandParent has postivie balance and parent has negative balance for left case
    // Original children of child
    
    AVLNode<Key, Value>* parent = child->getParent();
    AVLNode<Key, Value>* grandParent = parent->getParent();

    AVLNode<Key, Value>* childLeft = child->getLeft();
    AVLNode<Key, Value>* childRight = child->getRight(); 

    // Make child the parent of originalParent and originalGrandParent
    child->setParent(grandParent->getParent());

    // If child's new parent is nullptr, then make it the root 
    if (grandParent->getParent() == nullptr){
        this->root_ = child; 
    }

    else if (grandParent->getParent() != nullptr){
        if (child->getKey() > grandParent->getParent()->getKey()){
            grandParent->getParent()->setRight(child);
        }

        else if (child->getKey() < grandParent->getParent()->getKey()){
            grandParent->getParent()->setLeft(child);
        }
    }

    // originalParent is now right child
    child->setRight(parent); 
    parent->setParent(child); 

    // originalGrandParent is now the right child
    child->setLeft(grandParent); 
    grandParent->setParent(child);

    // set (original)grandParent's right to (original)child's left 
    // (keep grandParent's left)
    grandParent->setRight(childLeft);
    if (childLeft != nullptr){
        childLeft->setParent(grandParent);
    }

    // set (original)parent's left to (original)child's right
    // (keep parent's right)
    parent->setLeft(childRight);
    if (childRight != nullptr){
        childRight->setParent(parent); 
    }
    
    parent->setBalance(0); 
    if (parent->getLeft() != nullptr){
        parent->updateBalance(-1);
    }

    if (parent->getRight() != nullptr){
        parent->updateBalance(1); 
    }

    grandParent->setBalance(0);
    if (grandParent->getLeft() != nullptr){
        grandParent->updateBalance(-1);
    }

    if (grandParent->getRight() != nullptr){
        grandParent->updateBalance(1); 
    }

    return;

}

/*
 * Recall: The writeup specifies that if a node has 2 children you
 * should swap with the predecessor and then remove.
 */
template<class Key, class Value>
void AVLTree<Key, Value>:: remove(const Key& key)
{
    // TODO

    

    // std::cout << "REMOVE: " << key << std::endl; 
    AVLNode<Key, Value>* wantedNode = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::internalFind(key)); 
    // std::cout << "REMOVE: " << key << std::endl; 
    // If node does not exist
    if (wantedNode == nullptr){
        return;
    }

    int diff = 0;
    AVLNode<Key, Value>* wantedNodeParent = wantedNode->getParent(); 

    // If 0 children:
    if (wantedNode->getLeft() == nullptr && wantedNode->getRight() == nullptr){
        // std::cout << "NO CHILDREN" << std::endl;
        // If parent exists
        if (wantedNodeParent != nullptr){
            // If wantedNode is the left child

            wantedNodeParent->setBalance(0);
            if (wantedNodeParent->getLeft() != nullptr){
                wantedNodeParent->updateBalance(-(countHeight(wantedNodeParent->getLeft()))); 
            }

            if (wantedNodeParent->getRight() != nullptr){
                wantedNodeParent->updateBalance(countHeight(wantedNodeParent->getRight()));
            }

            if (wantedNode->getKey() < wantedNodeParent->getKey()){
                wantedNodeParent->setLeft(nullptr);
                diff += 1;
            }

            // If wantedNode is the right child
            else if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(nullptr); 
                diff -= 1; 
            }

            delete wantedNode; 
            wantedNode = nullptr;

            // std::cout << diff << std::endl;
            // std::cout << wantedNodeParent->getKey() << std::endl; 
            // std::cout << "wantedNodeParent: " << wantedNodeParent->getKey() << " wantedNodeParent Bal: " << std::to_string(wantedNodeParent->getBalance());
            

            removeFix(wantedNodeParent, diff);

        }

        // If parent does not exist, wantedNode is the root and only node
        else if (wantedNodeParent == nullptr){
            this->root_ = nullptr;
            delete wantedNode; 
            wantedNode = nullptr;

            return; 
        }
    }

    // If 1 child, promote child to wantedNode's position
    else if (wantedNode->getLeft() == nullptr || wantedNode->getRight() == nullptr){
        // Find which of wantedNode's child exist
        // std::cout << "this case" << std::endl;

        
        if (wantedNodeParent != nullptr){
            wantedNodeParent->setBalance(0); 
            if (wantedNodeParent->getLeft() != nullptr){
                wantedNodeParent->updateBalance(-(countHeight(wantedNodeParent->getLeft()))); 
            }

            if (wantedNodeParent->getRight() != nullptr){
                wantedNodeParent->updateBalance(countHeight(wantedNodeParent->getRight()));
            }


            // std::cout << "wantedNodeParent balance" << std::to_string(wantedNodeParent->getBalance()) << std::endl; 
        }

        AVLNode<Key, Value>* wantedNodeChild;
        if (wantedNode->getLeft() != nullptr){
            wantedNodeChild = wantedNode->getLeft(); 
        }

        else if (wantedNode->getRight() != nullptr){
            wantedNodeChild = wantedNode->getRight();
        }
       
       // Set child's new parent to wantedNodeParent
       wantedNodeChild->setParent(wantedNodeParent); 

        // If parent exists
        if (wantedNodeParent != nullptr){
            // If wantedNode is the left child
            if (wantedNode->getKey() < wantedNodeParent->getKey()){
                wantedNodeParent->setLeft(wantedNodeChild);
                
                if (wantedNodeChild != nullptr){
                    wantedNodeChild->setParent(wantedNodeParent); 
                }
                diff += 1;
            }

            // If wantedNode is the right child
            else if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(wantedNodeChild); 
            
                if (wantedNodeChild != nullptr){
                    wantedNodeChild->setParent(wantedNodeParent); 
                }

                diff -= 1; 
            }

            delete wantedNode;
            wantedNode = nullptr;

            removeFix(wantedNodeParent, diff);
        }

        // If parent doesn't exist
        else if (wantedNodeParent == nullptr){
            this->root_ = wantedNodeChild; 
            delete wantedNode;
            wantedNode = nullptr;

            return;
        }
    }

    // If 2 children, find predecessor, promote. 
    // WantedNode is the original pred's parent
    else if (wantedNode->getLeft() != nullptr && wantedNode->getRight() != nullptr){
        // std::cout << "2 children case - Find pred" << std::endl;
        wantedNode->setBalance(0);
        if (wantedNode->getLeft() != nullptr){
            wantedNode->updateBalance(-(countHeight(wantedNode->getLeft()))); 
        }

        if (wantedNode->getRight() != nullptr){
            wantedNode->updateBalance(countHeight(wantedNode->getRight()));
        }

        
        AVLNode<Key, Value>* pred = static_cast<AVLNode<Key, Value>*>(BinarySearchTree<Key, Value>::predecessor(wantedNode)); 
        // std::cout << "Pred - " << pred->getKey() << std::endl;
        
        AVLNode<Key, Value>* predOriginalParent = pred->getParent();
        predOriginalParent->setBalance(0);
        if (predOriginalParent->getLeft() != nullptr){
            predOriginalParent->updateBalance(-(countHeight(predOriginalParent->getLeft()))); 
        }

        if (predOriginalParent->getRight() != nullptr){
            predOriginalParent->updateBalance(countHeight(predOriginalParent->getRight()));
        }
        // std::cout << "PredOriginalParent - " << predOriginalParent->getKey() << " PredOriginalParentBal " << std::to_string(predOriginalParent->getBalance()) << std::endl;


        AVLNode<Key, Value>* predOriginalLeftChild = pred->getLeft();
        // AVLNode<Key, Value>* predOriginalParentLeft = predOriginalParent->getLeft();
        // AVLNode<Key, Value>* predOriginalGrandParent = predOriginalParent->getParent(); 

        pred->setParent(wantedNodeParent); 

        // If wantedNodeParent exists
        if (wantedNodeParent != nullptr){
            // std::cout << "WantedNodeParent exists" << std::endl;
            // wantedNodeParent->setBalance(0);
            // if (wantedNodeParent->getLeft() != nullptr){
            //     wantedNodeParent->updateBalance(-(countHeight(wantedNodeParent->getLeft()))); 
            // }

            // if (wantedNodeParent->getRight() != nullptr){
            //     wantedNodeParent->updateBalance(countHeight(wantedNodeParent->getRight()));
            // }
            // If wantedNode is the left child
            // this->print(); 

            // later come
            if (wantedNode->getKey() < wantedNodeParent->getKey()){
                // std::cout << "wantedNode " << wantedNode->getRight()->getKey() << std::endl;
                // std::cout << "wantedNodeParent" << wantedNodeParent->getKey() << std::endl;
                // std::cout << "WhY" << std::endl;
                wantedNodeParent->setLeft(pred);
                
            }

            // If wantedNode is the right child
            else if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(pred); 
                
            }

            if (pred->getKey() > predOriginalParent->getKey()){
                diff -= 1;
            }

            else if (pred->getKey() < predOriginalParent->getKey()){
                diff += 1;
            }

            
            // Since pred replaces wantedNode, set pred's right to wantedNode right
            pred->setRight(wantedNode->getRight());
            wantedNode->getRight()->setParent(pred);

            // If wantedNode's left is not the pred
            if (wantedNode->getLeft()->getKey() != pred->getKey()){
                // int oldPredOriginalParentBal = predOriginalParent->getBalance(); 

                // std::cout << std::to_string(predOriginalParent->getBalance()) << " << " << std::endl;
                // predOriginalParent->setBalance(oldPredOriginalParentBal); 

                // set pred to wantedNode's left
                pred->setLeft(wantedNode->getLeft()); 
                wantedNode->getLeft()->setParent(pred); 

                // If statement is Precausion (but unnecessary - We know that pred's original parent cannot be nullptr or wantedNode)
                // We know that pred cannot have a right child
                if (predOriginalParent != nullptr && predOriginalParent->getKey() != wantedNode->getKey()){
                    // set pred's original left child as the right child of pred's original parent
                    predOriginalParent->setRight(predOriginalLeftChild);
                    if (predOriginalLeftChild != nullptr){
                        predOriginalLeftChild->setParent(predOriginalParent);
                        
                    }
                    
                    // If predOriginalParent is a child of wantedNode, set pred
                    if (predOriginalParent->getParent()->getKey() == wantedNode->getKey()){
                        predOriginalParent->setParent(pred);
                    }
                }

                // if (predOriginalParent != nullptr){
                //                         predOriginalParent->setBalance(0);
                //     if (predOriginalParent->getLeft() != nullptr){
                //         predOriginalParent->updateBalance(-(countHeight(predOriginalParent->getLeft()))); 
                //     }

                //     if (predOriginalParent->getRight() != nullptr){
                //         predOriginalParent->updateBalance(countHeight(predOriginalParent->getRight()));
                //     }
                // }

                // this->pringt(); 
                delete wantedNode;
                wantedNode = nullptr; 
                // this->print(); 
                // std::cout << "PredOriginalParent" << std::endl; 
                // std::cout << "PredOriginalParentBal" << std::to_string(predOriginalParent->getBalance()) << std::endl;
                // std::cout << "diff" << std::endl; 
                if (predOriginalParent != nullptr){
                    removeFix(predOriginalParent, diff);
                }
            }

            // If wantedNode's left is pred 
            else if (predOriginalParent != nullptr && predOriginalParent->getKey() == wantedNode->getKey()){
                // std::cout << "pred's parent is wantedNode" << std::endl;
                // Declare a new pointer to pred's new parent, which would be wantedNode's parent
                // if (wantedNode->getLeft() == pred){
                //     ++diff; 
                // }

                // if (wantedNodeParent->getLeft() == wantedNode){
                //     std::cout << "NO"; 
                //     diff++;
                // }
                // std::cout << "WantedNode Balance " << std::to_string(wantedNode->getBalance()) << std::endl;
                pred->setBalance(wantedNode->getBalance()); 
                delete wantedNode; 
                wantedNode = nullptr; 

                // std::cout << diff << std::endl;
                // wantedNodeParent->setBalance(0);
                // if (wantedNodeParent->getLeft() != nullptr){
                //     wantedNodeParent->updateBalance(-(countHeight(wantedNodeParent->getLeft()))); 
                // }

                // if (wantedNodeParent->getRight() != nullptr){
                //     wantedNodeParent->updateBalance(countHeight(wantedNodeParent->getRight()));
                // }

                // pred->setBalance(0);
                // if (pred->getLeft() == nullptr && pred->getBalance() > 0){
                //     if (pred->getParent()->getRight() == pred){
                //         diff += 2; 
                //     }
                // }

   

                // std::cout << "Pred " << pred->getKey() << std::endl;
                // std::cout << "Pred Balance " << std::to_string(pred->getBalance()) << std::endl;
                // std::cout << "Diff " << diff << std::endl;
                removeFix(pred, diff); 
                
                // if (predNewParent->getLeft() == pred){
                //     std::cout << predNewParent->getLeft()->getKey() << std::endl; 
                //     AVLNode<Key, Value>* predNewParentLeft = predNewParent->getLeft(); 
                //     removeFix(pred, diff);
                // }

                // else if (predNewParent->getRight() == pred){
                //     AVLNode<Key, Value>* predNewParentRight = predNewParent->getRight(); 
                //     removeFix(predNewParentRight, diff);
                // }
            }

        }

        // If wantedNodeParent doesn't exist
        else if (wantedNodeParent == nullptr){
            // std::cout << "WantedNodeParent doesn't exist" << std::endl; 
            // If pred's left is nut nullptr and pred's parent is not the wantedNode
            // set pred's left parent to pred's parent
            wantedNode->setBalance(0);
            if (wantedNode->getLeft() != nullptr){
                wantedNode->updateBalance(-(countHeight(wantedNode->getLeft()))); 
            }

            if (wantedNode->getRight() != nullptr){
                wantedNode->updateBalance(countHeight(wantedNode->getRight()));
            }

            if (pred->getKey() > predOriginalParent->getKey()){
                diff -= 1;
            }

            else if (pred->getKey() < predOriginalParent->getKey()){
                diff += 1;
            }

            // If pred has a left and pred's parent isn't wantedNode
            if (pred->getLeft() != nullptr && pred->getParent() != wantedNode){
                // pred->getLeft()->setParent(pred->getParent());
                pred->setParent(nullptr);

                this->root_ = pred;
            }

            // If pred has a left and pred's parent is wantedNode
            else if (pred->getLeft() != nullptr && pred->getParent() == wantedNode){
                
                pred->getLeft()->setParent(pred); 
                pred->setParent(nullptr);

                
                this->root_ = pred;
            }

            

            // If pred doesn't have a left
            else if (pred->getLeft() == nullptr){
                pred->setParent(nullptr);
                this->root_ = pred;
            }

            // Pred gets wantedNode's balance
            pred->setBalance(wantedNode->getBalance());

            // Pred's right becomes wantedNode right
            pred->setRight(wantedNode->getRight());
            wantedNode->getRight()->setParent(pred);

            // If wantedNode's left isn't pred
            if (wantedNode->getLeft() != pred){
                // std::cout << "WantedNode isn't pred" << std::endl;
                pred->setLeft(wantedNode->getLeft()); 
                wantedNode->getLeft()->setParent(pred); 

                // If statement is Precausion (but unnecessary - We know that pred's original parent cannot be nullptr or wantedNode)
                // We know that pred cannot have a right child
                
                // If pred originalParent exists and predOrignalParent is not wantedNode
                if (predOriginalParent != nullptr && predOriginalParent != wantedNode){

                    // PredOriginalParent's right is pred's leftChild
                    predOriginalParent->setRight(predOriginalLeftChild);
                    if (predOriginalLeftChild != nullptr){
                        predOriginalLeftChild->setParent(predOriginalParent);
                    }
                    
                    // If predOriginalParent is a child of wantedNode, set pred
                    if (predOriginalParent->getParent() == wantedNode){
                        predOriginalParent->setParent(pred);

                    }
                }
            }


            // If predOriginalParent is wantedNode, we need to set it to nullptr before we can delete wantedNode
            if (predOriginalParent == wantedNode){
                predOriginalParent = nullptr; 
            }

            delete wantedNode;
            wantedNode = nullptr;
            // this->print(); 

            // If predOriginalParent is not nullptr, callFix
            if (predOriginalParent != nullptr){
                removeFix(predOriginalParent, diff);
            }

            else{
                // std::cout << "fnjlsfnlas;kjfdæ" << std::endl;
                // AVLNode<Key, Value>* predNewRight = pred->getRight(); 
                removeFix(pred, diff);
            }

            

            return; 
        }
    }
}

template<class Key, class Value>
void AVLTree<Key, Value>:: removeFix(AVLNode<Key, Value>*& node, int diff){
    
    if (node == nullptr){
        return; 
    }
    // std::cout << "Node: " << node->getKey() << " Node Bal: " << std::to_string(node->getBalance()) << " diff " << diff << std::endl;

    // node->setBalance(0);
    // if (node->getLeft() != nullptr){
    //     node->updateBalance(-(countHeight(node->getLeft()))); 
    // }

    // if (node->getRight() != nullptr){
    //     node->updateBalance(countHeight(node->getRight()));
    // }

    // std::cout << std::to_string(node->getBalance()) << std::endl; 
    AVLNode<Key, Value>* parent = node->getParent(); 

    
    int ndiff = 0;
    if (parent != nullptr){
        if (parent->getLeft() == node){
            ndiff += 1; 
        }

        else if (parent->getRight() == node){
            ndiff -= 1; 
        }
    }

    if (parent != nullptr){
        // std::cout << "Parent: " << parent->getKey(); 
        parent->setBalance(0);
        if (parent->getLeft() != nullptr){
            parent->updateBalance(-(countHeight(parent->getLeft()))); 
        }

        if (parent->getRight() != nullptr){
            parent->updateBalance(countHeight(parent->getRight()));
        }

        // std::cout << "Parent' updated balance: " << std::to_string(parent->getBalance()) << std::endl; 
        if (ndiff == 1){
            parent->updateBalance(-1); 
        }

        else if (ndiff == -1){
            parent->updateBalance(1); 
        }
        
    }


    // Case 1
    // node->getBalance() + diff == -2 or 2
    // std::cout << "equ: " << std::to_string(node->getBalance() + diff) << std::endl;
    if (node->getBalance() + diff == -2){
        // std::cout << "CASE 1 XD" << std::endl;

        // If balance() + diff == -2, then the tallestChild should be the left
        AVLNode<Key, Value>* tallestChild; 
        int leftHeight = countHeight(node->getLeft()); 
        int rightHeight = countHeight(node->getRight());

        if (leftHeight >= rightHeight){
            tallestChild = node->getLeft();
        }

        else if (leftHeight < rightHeight){
            tallestChild = node->getRight();
        }

        tallestChild->setBalance(0);
        if (tallestChild->getLeft() != nullptr){
            tallestChild->updateBalance(-(countHeight(tallestChild->getLeft()))); 
        }

        if (tallestChild->getRight() != nullptr){
            tallestChild->updateBalance(countHeight(tallestChild->getRight()));
        } 

        // Case 1A:
        if (tallestChild->getBalance() == -1){
            AVLNode<Key, Value>* grandChild = tallestChild->getLeft(); 
            // std::cout << "CASE 1A" << std::endl;
            if (parent != nullptr){
                parent->setBalance(0);
                if (parent->getLeft() != nullptr){
                    parent->updateBalance(-(countHeight(parent->getLeft()))); 
                }

                if (parent->getRight() != nullptr){
                    parent->updateBalance(countHeight(parent->getRight()));
                } 
            }
            ZigZigLeft(grandChild); 
            node->setBalance(0);
            tallestChild->setBalance(0); 

            if (parent != nullptr){

                removeFix(parent, ndiff);
            }
            
        }

        // Case 1B:
        else if (tallestChild->getBalance() == 0){
            AVLNode<Key, Value>* grandChild = tallestChild->getLeft(); 
            // std::cout << "CASE 1B" << std::endl;
            ZigZigLeft(grandChild); 
            node->setBalance(-1);
            tallestChild->setBalance(1); 

            if (parent != nullptr){
                removeFix(parent, ndiff);
            }
        }

        // Case 1C:
        else if (tallestChild->getBalance() == 1){
            AVLNode<Key, Value>* grandChildRight = tallestChild->getRight(); 
            // std::cout << "CASE 1C" << std::endl;
            // ZigZigRight(grandChildRight);
            // ZigZagLeft(grandChildRight); 
            if (parent != nullptr){
                parent->setBalance(0);
                if (parent->getLeft() != nullptr){
                    parent->updateBalance(-(countHeight(parent->getLeft()))); 
                }

                if (parent->getRight() != nullptr){
                    parent->updateBalance(countHeight(parent->getRight()));
                }
            }

            else{
                // std::cout << "NO PaREnt" << std::endl; 
            }
       

            // grandChildRight->setBalance(0);
            // if (grandChildRight->getLeft() != nullptr){
            //     grandChildRight->updateBalance(-(countHeight(grandChildRight->getLeft()))); 
            // }

            // if (grandChildRight->getRight() != nullptr){
            //     grandChildRight->updateBalance(countHeight(grandChildRight->getRight()));
            // }
            ZigZagLeft(grandChildRight); 
            
            if (grandChildRight->getBalance() == 1){
                node->setBalance(0);
                tallestChild->setBalance(-1); 
                grandChildRight->setBalance(0); 
            }

            else if (grandChildRight->getBalance() == 0){
                // std::cout << "Node val " << node->getKey() << std::endl; 
                node->setBalance(0);
                tallestChild->setBalance(0); 
                grandChildRight->setBalance(0); 
            }

            else if (grandChildRight->getBalance() == -1){
                node->setBalance(1);
                tallestChild->setBalance(0); 
                grandChildRight->setBalance(0); 
            }

            if (parent != nullptr){
                // std::cout << "parent " << parent->getKey() << " parent balance " << std::to_string(parent->getBalance()) << std::endl;
                // std::cout << "ndiff " << ndiff << std::endl;
                removeFix(parent, ndiff);
            }
        }

        return; 
    }

    // Case 1 Right
    else if (node->getBalance() + diff == 2){
        // std::cout << "CASE 1 - Right" << std::endl;
        // std::cout << "Node: " << std::to_string(node->getKey()) << std::endl;
        // std::cout << "node->getBalance() " << std::to_string(node->getBalance()) << std::endl;
        // std::cout << "diff " << std::to_string(diff) << std::endl;

        AVLNode<Key, Value>* tallestChild; 
        int leftHeight = countHeight(node->getLeft()); 
        int rightHeight = countHeight(node->getRight());

        if (leftHeight >= rightHeight){
            tallestChild = node->getLeft();
        }

        else if (leftHeight < rightHeight){
            tallestChild = node->getRight();
        }

        
        
        tallestChild->setBalance(0); 
        if (tallestChild->getLeft() != nullptr){
            tallestChild->updateBalance(-(countHeight(tallestChild->getLeft()))); 
        }

        if (tallestChild->getRight() != nullptr){
            tallestChild->updateBalance(countHeight(tallestChild->getRight()));
        }

        // std::cout << "tallestChild bal " << std::to_string(tallestChild->getBalance()) << std::endl; 

        // Case 1A:
        if (tallestChild->getBalance() == -1){
            AVLNode<Key, Value>* grandChildLeft = tallestChild->getLeft();
            // std::cout << "CASE 1C - Right" << std::endl;
            
            // ZigZigLeft(node)
            // ZigZigRight(tallestChild);
            ZigZagRight(grandChildLeft); 
             
            if (grandChildLeft->getBalance() == 1){
                node->setBalance(0);
                tallestChild->setBalance(-1); 
                grandChildLeft->setBalance(0); 
            }

            else if (grandChildLeft->getBalance() == 0){
                node->setBalance(0);
                tallestChild->setBalance(0); 
                grandChildLeft->setBalance(0); 
            }

            else if (grandChildLeft->getBalance() == -1){
                node->setBalance(1);
                tallestChild->setBalance(0); 
                grandChildLeft->setBalance(0); 
            }

            if (parent != nullptr){
                parent->setBalance(0);
                if (parent->getLeft() != nullptr){
                    parent->updateBalance(-(countHeight(parent->getLeft()))); 
                }

                if (parent->getRight() != nullptr){
                    parent->updateBalance(countHeight(parent->getRight()));
                }

                // std::cout << "Parent' updated balance: " << std::to_string(parent->getBalance()) << std::endl; 
                if (ndiff == 1){
                    parent->updateBalance(-1); 
                }

                else if (ndiff == -1){
                    parent->updateBalance(1); 
                }

                removeFix(parent, ndiff);
            }
        }

        // Case 1B:
        else if (tallestChild->getBalance() == 0){
            AVLNode<Key, Value>* grandChild = tallestChild->getRight(); 
            // std::cout << "CASE 1B - Right" << std::endl;
            ZigZigRight(grandChild); 
            // this->print(); 
            node->setBalance(1);
            // std::cout << "Node: " << node->getKey() << std::endl;
            tallestChild->setBalance(-1); 
            
            // if (parent != nullptr){
            //     removeFix(parent, ndiff);
            // }

        }

        // Case 1C:
        else if (tallestChild->getBalance() == 1){
            AVLNode<Key, Value>* grandChild = tallestChild->getRight(); 
            // std::cout << "CASE 1A C - Right" << std::endl;
            
            // std::cout << tallestChild->getKey(); 
            // std::cout << tallestChild->getRight()->getKey(); 

            ZigZigRight(grandChild); 
            node->setBalance(0);
            tallestChild->setBalance(0); 
            // this->print();
            

            if (parent != nullptr){
                parent->setBalance(0);
                if (parent->getLeft() != nullptr){
                    parent->updateBalance(-(countHeight(parent->getLeft()))); 
                }

                if (parent->getRight() != nullptr){
                    parent->updateBalance(countHeight(parent->getRight()));
                }

                // std::cout << "Parent' updated balance: " << std::to_string(parent->getBalance()) << std::endl; 
                if (ndiff == 1){
                    parent->updateBalance(-1); 
                }

                else if (ndiff == -1){
                    parent->updateBalance(1); 
                }
            
                removeFix(parent, ndiff);
            }
        }

        return; 
    }

    // Case 2 
    // node->getBalance() + diff == -1 or 1
    else if (node->getBalance() + diff == -1){
        // std::cout << "CASE 2" << std::endl;
        node->setBalance(-1); 
        return;
    }

    // Case 2 Right

    else if (node->getBalance() + diff == 1){
        // std::cout << "CASE 2 Right" << std::endl;
        node->setBalance(1); 
        return; 
    }

    // Case 3
    //node->getBalance() + diff == 0
    else if (node->getBalance() + diff == 0){
        // std::cout << "CASE 3" << std::endl;
        node->setBalance(0);

        if (parent != nullptr){
            
            removeFix(parent, ndiff); 
        }
        
        return; 
    }
    // std::cout << "HELLO"; 
}

template<class Key, class Value>
void AVLTree<Key, Value>::nodeSwap( AVLNode<Key,Value>* n1, AVLNode<Key,Value>* n2)
{
    BinarySearchTree<Key, Value>::nodeSwap(n1, n2);
    int8_t tempB = n1->getBalance();
    n1->setBalance(n2->getBalance());
    n2->setBalance(tempB);
}

template<class Key, class Value>
int AVLTree<Key, Value>::countHeight( AVLNode<Key,Value>* n1){
    return BinarySearchTree<Key, Value>::countHeight(n1); 
}

#endif