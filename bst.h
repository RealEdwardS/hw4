#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include <cstdlib>
#include <utility>

/**
 * A templated class for a Node in a search tree.
 * The getters for parent/left/right are virtual so
 * that they can be overridden for future kinds of
 * search trees, such as Red Black trees, Splay trees,
 * and AVL trees.
 */
template <typename Key, typename Value>
class Node
{
public:
    Node(const Key& key, const Value& value, Node<Key, Value>* parent);
    virtual ~Node();

    const std::pair<const Key, Value>& getItem() const;
    std::pair<const Key, Value>& getItem();
    const Key& getKey() const;
    const Value& getValue() const;
    Value& getValue();

    virtual Node<Key, Value>* getParent() const;
    virtual Node<Key, Value>* getLeft() const;
    virtual Node<Key, Value>* getRight() const;

    void setParent(Node<Key, Value>* parent);
    void setLeft(Node<Key, Value>* left);
    void setRight(Node<Key, Value>* right);
    void setValue(const Value &value);

protected:
    std::pair<const Key, Value> item_;
    Node<Key, Value>* parent_;
    Node<Key, Value>* left_;
    Node<Key, Value>* right_;
};

/*
  -----------------------------------------
  Begin implementations for the Node class.
  -----------------------------------------
*/

/**
* Explicit constructor for a node.
*/
template<typename Key, typename Value>
Node<Key, Value>::Node(const Key& key, const Value& value, Node<Key, Value>* parent) :
    item_(key, value),
    parent_(parent),
    left_(NULL),
    right_(NULL)
{

}

/**
* Destructor, which does not need to do anything since the pointers inside of a node
* are only used as references to existing nodes. The nodes pointed to by parent/left/right
* are freed by the BinarySearchTree.
*/
template<typename Key, typename Value>
Node<Key, Value>::~Node()
{

}

/**
* A const getter for the item.
*/
template<typename Key, typename Value>
const std::pair<const Key, Value>& Node<Key, Value>::getItem() const
{
    return item_;
}

/**
* A non-const getter for the item.
*/
template<typename Key, typename Value>
std::pair<const Key, Value>& Node<Key, Value>::getItem()
{
    return item_;
}

/**
* A const getter for the key.
*/
template<typename Key, typename Value>
const Key& Node<Key, Value>::getKey() const
{
    return item_.first;
}

/**
* A const getter for the value.
*/
template<typename Key, typename Value>
const Value& Node<Key, Value>::getValue() const
{
    return item_.second;
}

/**
* A non-const getter for the value.
*/
template<typename Key, typename Value>
Value& Node<Key, Value>::getValue()
{
    return item_.second;
}

/**
* An implementation of the virtual function for retreiving the parent.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getParent() const
{
    return parent_;
}

/**
* An implementation of the virtual function for retreiving the left child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getLeft() const
{
    return left_;
}

/**
* An implementation of the virtual function for retreiving the right child.
*/
template<typename Key, typename Value>
Node<Key, Value>* Node<Key, Value>::getRight() const
{
    return right_;
}

/**
* A setter for setting the parent of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setParent(Node<Key, Value>* parent)
{
    parent_ = parent;
}

/**
* A setter for setting the left child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setLeft(Node<Key, Value>* left)
{
    left_ = left;
}

/**
* A setter for setting the right child of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setRight(Node<Key, Value>* right)
{
    right_ = right;
}

/**
* A setter for the value of a node.
*/
template<typename Key, typename Value>
void Node<Key, Value>::setValue(const Value& value)
{
    item_.second = value;
}

/*
  ---------------------------------------
  End implementations for the Node class.
  ---------------------------------------
*/

/**
* A templated unbalanced binary search tree.
*/
template <typename Key, typename Value>
class BinarySearchTree
{
public:
    BinarySearchTree(); //TODO
    virtual ~BinarySearchTree(); //TODO
    virtual void insert(const std::pair<const Key, Value>& keyValuePair); //TODO
    virtual void remove(const Key& key); //TODO
    void clear(); //TODO
    bool isBalanced() const; //TODO
    void print() const;
    bool empty() const;

    template<typename PPKey, typename PPValue>
    friend void prettyPrintBST(BinarySearchTree<PPKey, PPValue> & tree);
public:
    /**
    * An internal iterator class for traversing the contents of the BST.
    */
    class iterator  // TODO
    {
    public:
        iterator();

        std::pair<const Key,Value>& operator*() const;
        std::pair<const Key,Value>* operator->() const;

        bool operator==(const iterator& rhs) const;
        bool operator!=(const iterator& rhs) const;

        iterator& operator++();

    protected:
        friend class BinarySearchTree<Key, Value>;
        iterator(Node<Key,Value>* ptr);
        Node<Key, Value> *current_;
    };

public:
    iterator begin() const;
    iterator end() const;
    iterator find(const Key& key) const;
    Value& operator[](const Key& key);
    Value const & operator[](const Key& key) const;

protected:
    // Mandatory helper functions
    Node<Key, Value>* internalFind(const Key& k) const; // TODO
    Node<Key, Value> *getSmallestNode() const;  // TODO
    static Node<Key, Value>* predecessor(Node<Key, Value>* current); // TODO
    // Note:  static means these functions don't have a "this" pointer
    //        and instead just use the input argument.

    // Provided helper functions
    virtual void printRoot (Node<Key, Value> *r) const;
    virtual void nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2) ;

    // Add helper functions here
    Node<Key, Value> *getLargestNode() const; 
    virtual int countHeight(const Node<Key, Value>* inputNode) const;

protected:
    Node<Key, Value>* root_;
    // You should not need other data members
};

/*
--------------------------------------------------------------
Begin implementations for the BinarySearchTree::iterator class.
---------------------------------------------------------------
*/

/**
* Explicit constructor that initializes an iterator with a given node pointer.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator(Node<Key,Value> *ptr)
{
    // TODO
    this->current_ = ptr; 
}

/**
* A default constructor that initializes the iterator to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::iterator::iterator() 
{
    // TODO
    this->current_ = nullptr; 
}

/**
* Provides access to the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> &
BinarySearchTree<Key, Value>::iterator::operator*() const
{
    return current_->getItem();
}

/**
* Provides access to the address of the item.
*/
template<class Key, class Value>
std::pair<const Key,Value> *
BinarySearchTree<Key, Value>::iterator::operator->() const
{
    return &(current_->getItem());
}

/**
* Checks if 'this' iterator's internals have the same value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator==(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    if (rhs.current_ == nullptr || this->current_ == nullptr){
        if (rhs.current_ == nullptr && this->current_ == nullptr){
            return true;
        }

        return false; 
    }

    if (this->current_->getKey() == rhs.current_->getKey()){
        if (this->current_->getValue() == rhs.current_->getValue()){
            return true;
        }
    }

    return false;

}

/**
* Checks if 'this' iterator's internals have a different value
* as 'rhs'
*/
template<class Key, class Value>
bool
BinarySearchTree<Key, Value>::iterator::operator!=(
    const BinarySearchTree<Key, Value>::iterator& rhs) const
{
    // TODO
    return !(operator==(rhs)); 
}


/**
* Advances the iterator's location using an in-order sequencing
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator&
BinarySearchTree<Key, Value>::iterator::operator++()
{
    // TODO

    // Notes:
    // Return iterator, but change the iterator's value!! 
    // *this = BinarySearchTree<Key, Value>::iterator nextVal(...)?

    // Declare an end iterator
    BinarySearchTree<Key, Value>::iterator end(NULL);
    // If it is a leaf node
    if (current_->getLeft() == nullptr && current_->getRight() == nullptr){
        // Check parent
        Node<Key, Value>* currParent = current_->getParent(); 

        // If parent doesn't exist, then return end
        if (currParent == nullptr){
            *this = end; 
            
        }
        
        // If currKey is less than parentKey, then iterate to parent (in-order), current becomes parent
        else if (current_->getKey() < currParent->getKey()){
            current_ = current_->getParent();
        }

        // If currKey is greater than parentKey, then compare grandParentKey
        else if (current_->getKey() > currParent->getKey()){
            Node<Key, Value>* grandParent = currParent->getParent(); 
            // If grandParent doesn't exist (rootNode), then the currentNode is greater
            // than the root node and has no children, meaning it is the largest node
            if (grandParent == nullptr){
                *this = end;
            }


            // If grandParent does exist, then compare
            // If currentNode is less than grandParent, that means next value should be
            // the grandParent
            else if (grandParent != nullptr){
                if (currParent->getKey() < grandParent->getKey()){
                    current_ = grandParent;
                }

                // If it is greater than grandParent, that means currNode is greater than Parent
                // currNode is greater than grand parent, and currNode has no children, meaning it's the
                // greatest value
                else if (currParent->getKey() >= grandParent->getKey()){
                    *this = end;
                }
            }
        }

    }

    // If it's not a leaf node
    // We want to advance the iterator to the next value, so we want to go to right child
    else{
        Node<Key, Value>* rightChild = current_->getRight(); 
        // If right child does not exist, go to parent
        if (rightChild == nullptr){
            Node<Key, Value>* currParent = current_->getParent();
            // If currParent doesn't exist, that means curr is the root node
            // If the root node doesn't have a right child, it's the largest val
            if (currParent == nullptr){
                *this = end;
            }

            // If it does have a parent, compare
            else if (currParent != nullptr){
                // If parent is greater than curr, and curr doesn't have any children greater than curr,
                // then the parent is the next val
                if (currParent->getKey() >= current_->getKey()){
                    current_ = currParent; 
                }

                // If parent is less than curr, and curr doens't have any children greater than curr,
                // curr is the largest val
                else if (currParent->getKey() < current_->getKey()){
                    *this = end;
                }
            }
        }

        // If right child exists
        else if (rightChild != nullptr){
            current_ = rightChild;
            // return rightChild; 
        }
    }

    return *this;
}


/*
-------------------------------------------------------------
End implementations for the BinarySearchTree::iterator class.
-------------------------------------------------------------
*/

/*
-----------------------------------------------------
Begin implementations for the BinarySearchTree class.
-----------------------------------------------------
*/

/**
* Default constructor for a BinarySearchTree, which sets the root to NULL.
*/
template<class Key, class Value>
BinarySearchTree<Key, Value>::BinarySearchTree() 
{
    // TODO
    this->root_ = nullptr; 
    
}

template<typename Key, typename Value>
BinarySearchTree<Key, Value>::~BinarySearchTree()
{
    // TODO
    this->clear(); 
}

/**
 * Returns true if tree is empty
*/
template<class Key, class Value>
bool BinarySearchTree<Key, Value>::empty() const
{
    return root_ == NULL;
}

template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::print() const
{
    printRoot(root_);
    std::cout << "\n";
}

/**
* Returns an iterator to the "smallest" item in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::begin() const
{
    BinarySearchTree<Key, Value>::iterator begin(getSmallestNode());
    return begin;
}

/**
* Returns an iterator whose value means INVALID
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::end() const
{
    BinarySearchTree<Key, Value>::iterator end(NULL);
    return end;
}

/**
* Returns an iterator to the item with the given key, k
* or the end iterator if k does not exist in the tree
*/
template<class Key, class Value>
typename BinarySearchTree<Key, Value>::iterator
BinarySearchTree<Key, Value>::find(const Key & k) const
{
    Node<Key, Value> *curr = internalFind(k);
    BinarySearchTree<Key, Value>::iterator it(curr);
    return it;
}

/**
 * @precondition The key exists in the map
 * Returns the value associated with the key
 */
template<class Key, class Value>
Value& BinarySearchTree<Key, Value>::operator[](const Key& key)
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}
template<class Key, class Value>
Value const & BinarySearchTree<Key, Value>::operator[](const Key& key) const
{
    Node<Key, Value> *curr = internalFind(key);
    if(curr == NULL) throw std::out_of_range("Invalid key");
    return curr->getValue();
}

/**
* An insert method to insert into a Binary Search Tree.
* The tree will not remain balanced when inserting.
* Recall: If key is already in the tree, you should 
* overwrite the current value with the updated value.
*/
template<class Key, class Value>
void BinarySearchTree<Key, Value>::insert(const std::pair<const Key, Value> &keyValuePair)
{
    // TODO
    // Create new node
    BinarySearchTree<Key, Value>::iterator checkDup = find(keyValuePair.first);
    if (checkDup != nullptr){
        checkDup.current_->setValue(keyValuePair.second);
        return;
    }

    Node<Key, Value>* newNode = new Node<Key, Value>(keyValuePair.first, keyValuePair.second, nullptr); 
    
    if (root_ == nullptr){
        root_ = newNode;
        return;
    }

    Node<Key, Value>* currNode = root_;
    while (currNode != nullptr){
        // If newNode is less than currNode
        if (newNode->getKey() < currNode->getKey()){
            // If left child exists, traverse to left child
            if (currNode->getLeft() != nullptr){
                currNode = currNode->getLeft();
            }

            // If left child does not exist, set newNode as the left child
            // set newNode's parent as currNode
            else if (currNode->getLeft() == nullptr){
                currNode->setLeft(newNode);
                newNode->setParent(currNode);
                return;
            }
        }

        // If newNode is greater than currNode
        else if (newNode->getKey() > currNode->getKey()){
            // If right child exists, traverse to right child
            if (currNode->getRight() != nullptr){
                currNode = currNode->getRight();
            }

            // If right child does not exist, set newNode was the right child
            // set newNode's parent as currNode
            else if (currNode->getRight() == nullptr){
                currNode->setRight(newNode);
                newNode->setParent(currNode);
                
                return;
            }
        }
        
        // CORRECTION: They cannot be the same since it was checked in the front
        // If newNode is equal to currNode, replace value
        // else if (newNode->getKey() == currNode->getKey()){
        //     currNode->setValue(keyValuePair.second);
            
        //     // Since nothing is being inserted, we can delete the newNode
        //     delete newNode;
        // }
    }
    
}


/**
* A remove method to remove a specific key from a Binary Search Tree.
* Recall: The writeup specifies that if a node has 2 children you
* should swap with the predecessor and then remove.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::remove(const Key& key)
{
    // TODO
    BinarySearchTree<Key, Value>::iterator wantedNodeIterator = find(key);
    if (wantedNodeIterator == end()){
        // std::cout << "Cannot find Node" << std::endl;
        return;
    }

    Node<Key, Value>* wantedNode = wantedNodeIterator.current_;
    
    // if 0 children
    if (wantedNode->getLeft() == nullptr && wantedNode->getRight() == nullptr){
        // Get parent
        Node<Key, Value>* wantedNodeParent = wantedNode->getParent(); 
        // If parent exists
        if (wantedNodeParent != nullptr){

            // If wantedNode is right child, set right child to nullptr
            if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(nullptr); 
            }

            // If wantedNode is a left child, set left child to nullptr
            else if (wantedNode->getKey() < wantedNodeParent->getKey()){
                wantedNodeParent->setLeft(nullptr);
            }
        }

        // If the parent does not exist, that means wantedNode is the root
        else if (wantedNodeParent == nullptr){
            root_ = nullptr; 
        }

        // Delete node
        delete wantedNode;
        wantedNode = nullptr;

        return;
    }

    // if 1 child, promote child to wantedNode's position
    // Promote:
    // 1) Get parent of wantedNode
    // 2) if parent exists (not null):
    // 2a) find which child of parent is wantedNode (left or right)
    // 2b) set whichever child to wantedNode's child
    // 2c) set wantedNode's child to wantedNode's parent

    else if (wantedNode->getLeft() == nullptr || wantedNode->getRight() == nullptr){
        // Find which child exists
        Node<Key, Value>* child; 
        if (wantedNode->getLeft() != nullptr){
            child = wantedNode->getLeft(); 
        }

        else if (wantedNode->getRight() != nullptr){
            child = wantedNode->getRight(); 
        }

        Node<Key, Value>* wantedNodeParent = wantedNode->getParent(); 
        if (wantedNodeParent != nullptr){
            if (wantedNode->getKey() < wantedNodeParent->getKey()){
                wantedNodeParent->setLeft(child);
            }

            else if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(child);
            }

            child->setParent(wantedNodeParent); 
        }

        // If no parent, then set child's parent to null
        // This also means that wantedNode is the root, so we need to set root to child
        else if (wantedNodeParent == nullptr){
            // We need to make sure that the child doesn't have any grandchildren

            // if (child->getLeft() != nullptr){
            //     child->getLeft()->setParent(child->getParent()); 
            // }

            // if (child->getRight() != nullptr){
            //     child->getRight()->setParent(child->getParent());
            // }
            
            child->setParent(nullptr);
            
            root_ = child;
        }

        // Delete node
        delete wantedNode; 
        wantedNode = nullptr;

        return;
    }

    // If 2 children, promote predecessor, if 2 children, impossible to have no predecessor
    // 
    else if (wantedNode->getLeft() != nullptr && wantedNode->getRight() != nullptr){
        Node<Key, Value>* pred = predecessor(wantedNode);
        Node<Key, Value>* predOriginalParent = pred->getParent(); 
        Node<Key, Value>* predOriginalLeftChild = pred->getLeft(); 
        Node<Key, Value>* predOriginalRightChild = pred->getRight(); // Should be always null since predecessor should have 0 right children

        if (predOriginalRightChild != nullptr){
            // std::cout << "Predecessor is wrong, it has a right child" << std::endl;
            return; 
        }

        Node<Key, Value>* wantedNodeParent = wantedNode->getParent(); 
        if (wantedNodeParent != nullptr){
            if (wantedNode->getKey() < wantedNodeParent->getKey()){
                wantedNodeParent->setLeft(pred); 
            }

            else if (wantedNode->getKey() > wantedNodeParent->getKey()){
                wantedNodeParent->setRight(pred); 
            }

            pred->setParent(wantedNodeParent);
        }

        // If no parent
        else if (wantedNodeParent == nullptr){
            // If pred's left is not null and pred's parent is not the wantedNode
            // set pred's left parent to pred's parent
            if (pred->getLeft() != nullptr && pred->getParent() != wantedNode){
                pred->getLeft()->setParent(pred->getParent());
                pred->setParent(nullptr);

                root_ = pred; 
            }

            // If pred's left is not null and pred's parent is the wantedNode
            // set pred's left parent to pred since pred replaces wantedNode
            else if (pred->getLeft() != nullptr && pred->getParent() == wantedNode){
                pred->getLeft()->setParent(pred);
                pred->setParent(nullptr);

                root_ = pred; 
            }

            else{
                pred->setParent(nullptr);
                root_ = pred; 
            }

            // if (pred->getRight() != nullptr){
            //     pred->getRight()->setParent(pred->getParent());
            // }
        }

        // Pred's original right child doesn't exist so we don't have to worry about that
        // We just need to set pred's new right child to wantedNode's original right child
        pred->setRight(wantedNode->getRight());
        wantedNode->getRight()->setParent(pred); 

        // If wantedNode's leftChild is pred, do nothing pred's new left child
        // So if it's not pred, we need to set pred's new left child to wantedNode's original left child

        // We know that pred is a right child of its original parent
        // We know that pred's original parent cannot be nullptr or wantedNode
        if (wantedNode->getLeft()->getKey() != pred->getKey()){
            pred->setLeft(wantedNode->getLeft()); 
            wantedNode->getLeft()->setParent(pred); 

            // If statement is Precausion (but unnecessary - We know that pred's original parent cannot be nullptr or wantedNode)
            // We know that pred cannot have a right child
            if (predOriginalParent != nullptr && predOriginalParent->getKey() != wantedNode->getKey()){
                predOriginalParent->setRight(predOriginalLeftChild);
                if (predOriginalLeftChild != nullptr){
                    predOriginalLeftChild->setParent(predOriginalParent);
                }
                
                // If predOriginalParent is a child of wantedNode, set pred
                if (predOriginalParent->getParent()->getKey() == wantedNode->getKey()){

                    predOriginalParent->setParent(pred);
                }
            }
        }

        delete wantedNode;
        wantedNode = nullptr;
        return; 
    }
}



template<class Key, class Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::predecessor(Node<Key, Value>* current)
{
    // TODO
    Node<Key, Value>* finalResult; 
    if (current->getLeft() == nullptr && current->getRight() == nullptr){
        // std::cout << "No predecessor" << std::endl; 
        return current; 
    }

    // If left child does not exist, then return nothing because rightChild is successor
    else if (current->getLeft() == nullptr){
        // std::cout << "No predecessor" << std::endl; 
        return current; 
        // // Predecessor of left branch is going to be the right most child
        // Node<Key, Value>* currVal = current->getRight(); 
        // while (currVal->getRight() != nullptr){
        //     currVal = currVal->getRight(); 
        // }

        // return currVal; 
    }

    // // If right child does not exist
    // else if (current->getRight() == nullptr){
    //     // Predecessor of right branch is going to be the left most child
    //     Node<Key, Value>* currVal = current->getLeft();
    //     while (currVal->getLeft() != nullptr){
    //         currVal = currVal->getLeft();
    //     }

    //     return currVal; 
    // }

    // If both children exist
    else{
        // Get right most child of left branch 
        Node<Key, Value>* currValLeft = current->getLeft();
        while (currValLeft->getRight() != nullptr){
            currValLeft = currValLeft->getRight();
        }

        // // Get left most child of right branch 
        // Node<Key, Value>* currValRight = current->getRight(); 
        // while (currValRight->getLeft() != nullptr){
        //     currValRight = currValRight->getLeft();
        // }

        // // Compare difference
        // Value ValueDiffLeft = abs(currValLeft->getKey() - current->getKey());
        // Value ValueDiffRight = abs(currValRight->getKey() - current->getKey());

        // if (ValueDiffLeft < ValueDiffRight){
        //     finalResult = currValLeft;
        // }

        // else{
        //     finalResult = currValRight;
        // }

        finalResult = currValLeft; 
    }

    return finalResult; 
}


/**
* A method to remove all contents of the tree and
* reset the values in the tree for use again.
*/
template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::clear()
{
    // TODO
    // Later
    // Postorder traversal, delete children, then delete parent
    // Recurse left
    // Recurse right
    // Delete node

    // If the tree is already empty, return
    if (empty()){
        return;
    }

    else{
        BinarySearchTree<Key, Value> left; 
        left.root_ = root_->getLeft(); 

        BinarySearchTree<Key, Value> right;
        right.root_ = root_->getRight();

        left.clear();
        right.clear();

        if (root_ != nullptr){
            if (root_->getParent() != nullptr){
                if (root_->getKey() < root_->getParent()->getKey()){
                    root_->getParent()->setLeft(nullptr);
                }

                else if (root_->getKey() >= root_->getParent()->getKey()){
                    root_->getParent()->setRight(nullptr);
                }
            }
            delete root_;
            root_ = nullptr; 
        }

    }

}


/**
* A helper function to find the smallest node in the tree.
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getSmallestNode() const
{
    // TODO
    // Smallest value is going to be on the very left
    if (root_ == nullptr){
        return nullptr; 
    }

    Node<Key, Value>* smallestVal = root_->getLeft();
    if (smallestVal == nullptr){
        return root_; 
    } 

    while (smallestVal->getLeft() != nullptr){
        smallestVal = smallestVal->getLeft();
    }

    // std::cout << "YES" << std::endl;

    return nullptr;
}

/**
 * MY FUNCTION
 * A helper function to find the largest node in the tree
*/
template<typename Key, typename Value>
Node<Key, Value>*
BinarySearchTree<Key, Value>::getLargestNode() const{
    // Largest value is going to be on the very right
    Node<Key, Value>* largestVal = root_->getRight();
    if (largestVal == nullptr){
        return root_; 
    } 

    while (largestVal->largestVal() != nullptr){
        largestVal = largestVal->getRight();
    }

    return largestVal;
}

/**
* Helper function to find a node with given key, k and
* return a pointer to it or NULL if no item with that key
* exists
*/
template<typename Key, typename Value>
Node<Key, Value>* BinarySearchTree<Key, Value>::internalFind(const Key& key) const
{
    // TODO
    if (root_ == nullptr){
        return nullptr; 
    }

    if (root_->getKey() == key){
        return root_; 
    }

    else if (root_->getKey() > key){
        Node<Key, Value>* wantedVal = root_->getLeft(); 
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

    else if (root_->getKey() <= key){
        Node<Key, Value>* wantedVal = root_->getRight(); 
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

/**
 * Return true iff the BST is balanced.
 */
template<typename Key, typename Value>
bool BinarySearchTree<Key, Value>::isBalanced() const
{
    // TODO
    // If the tree is empty, then it's balanced
    if (root_ == nullptr){
        return true; 
    }

    // Get height of left and right trees
    int leftHeight = countHeight(root_->getLeft()); 
    int rightHeight = countHeight(root_->getRight());

    // If left and right trees have height diff of 1, then they're balanced
    // Need to check next level
    if (abs(leftHeight - rightHeight) <= 1){

        // Get leftTree and rightTrees and set them appropriately
        BinarySearchTree<Key, Value> leftTree; 
        BinarySearchTree<Key, Value> rightTree; 
        leftTree.root_ = root_->getLeft(); 
        rightTree.root_ = root_->getRight(); 

        // If either fails, then it's false
        if (leftTree.isBalanced() == false || rightTree.isBalanced() == false){
            return false;
        }

        // Return true if none fails
        return true;
    }

    // Returns false if the top left and right trees are not balanced
    return false;

}

template<typename Key, typename Value>
int BinarySearchTree<Key, Value>::countHeight(const Node<Key, Value>* inputNode) const{
    // If node is nullptr
    if (inputNode == nullptr){
        return 0; 
    }

    Node<Key, Value>* inputNodeLeft = inputNode->getLeft();
    Node<Key, Value>* inputNodeRight = inputNode->getRight(); 

    int leftHeight = countHeight(inputNodeLeft) + 1;
    int rightHeight = countHeight(inputNodeRight) + 1;

    if (leftHeight >= rightHeight){
        return leftHeight; 
    }

    return rightHeight;
}



template<typename Key, typename Value>
void BinarySearchTree<Key, Value>::nodeSwap( Node<Key,Value>* n1, Node<Key,Value>* n2)
{
    if((n1 == n2) || (n1 == NULL) || (n2 == NULL) ) {
        return;
    }
    Node<Key, Value>* n1p = n1->getParent();
    Node<Key, Value>* n1r = n1->getRight();
    Node<Key, Value>* n1lt = n1->getLeft();
    bool n1isLeft = false;
    if(n1p != NULL && (n1 == n1p->getLeft())) n1isLeft = true;
    Node<Key, Value>* n2p = n2->getParent();
    Node<Key, Value>* n2r = n2->getRight();
    Node<Key, Value>* n2lt = n2->getLeft();
    bool n2isLeft = false;
    if(n2p != NULL && (n2 == n2p->getLeft())) n2isLeft = true;


    Node<Key, Value>* temp;
    temp = n1->getParent();
    n1->setParent(n2->getParent());
    n2->setParent(temp);

    temp = n1->getLeft();
    n1->setLeft(n2->getLeft());
    n2->setLeft(temp);

    temp = n1->getRight();
    n1->setRight(n2->getRight());
    n2->setRight(temp);

    if( (n1r != NULL && n1r == n2) ) {
        n2->setRight(n1);
        n1->setParent(n2);
    }
    else if( n2r != NULL && n2r == n1) {
        n1->setRight(n2);
        n2->setParent(n1);

    }
    else if( n1lt != NULL && n1lt == n2) {
        n2->setLeft(n1);
        n1->setParent(n2);

    }
    else if( n2lt != NULL && n2lt == n1) {
        n1->setLeft(n2);
        n2->setParent(n1);

    }


    if(n1p != NULL && n1p != n2) {
        if(n1isLeft) n1p->setLeft(n2);
        else n1p->setRight(n2);
    }
    if(n1r != NULL && n1r != n2) {
        n1r->setParent(n2);
    }
    if(n1lt != NULL && n1lt != n2) {
        n1lt->setParent(n2);
    }

    if(n2p != NULL && n2p != n1) {
        if(n2isLeft) n2p->setLeft(n1);
        else n2p->setRight(n1);
    }
    if(n2r != NULL && n2r != n1) {
        n2r->setParent(n1);
    }
    if(n2lt != NULL && n2lt != n1) {
        n2lt->setParent(n1);
    }


    if(this->root_ == n1) {
        this->root_ = n2;
    }
    else if(this->root_ == n2) {
        this->root_ = n1;
    }

}

/**
 * Lastly, we are providing you with a print function,
   BinarySearchTree::printRoot().
   Just call it with a node to start printing at, e.g:
   this->printRoot(this->root_) // or any other node pointer

   It will print up to 5 levels of the tree rooted at the passed node,
   in ASCII graphics format.
   We hope it will make debugging easier!
  */

// include print function (in its own file because it's fairly long)
#include "print_bst.h"

/*
---------------------------------------------------
End implementations for the BinarySearchTree class.
---------------------------------------------------
*/

#endif
