#ifndef RECCHECK
//if you want to add any #includes like <iostream> you must do them here (before the next endif)
#include <iostream>
#endif

#include "equal-paths.h"
using namespace std;


// You may add any prototypes of helper functions here
int maxHeight(Node* root, int& countPaths);

bool equalPaths(Node * root)
{
    // Add your code below
    if (root == nullptr){
        return true; 
    }

    int countPaths = 0; 
    int maxLeftHeight = maxHeight(root->left, countPaths); 
    int maxRightHeight = maxHeight(root->right, countPaths); 

    // If there is only 1 path, return true 
    if (countPaths <= 1){
        return true;
    }

    // If the max height is equal on both sides
    if (maxLeftHeight == maxRightHeight){
        return true;
    }

    return false;

}

int maxHeight(Node* root, int& countPaths){
    if (root == nullptr){
        return 0;
    }

    // If a left child exists, a path exists
    if (root->left != nullptr){
        ++countPaths;
    }

    // If a right child exist, a path exists
    if (root->right != nullptr){
        ++countPaths;
    }

    // Get height of left child
    int leftHeight = maxHeight(root->left, countPaths) + 1; 

    // Get path of right child
    int rightHeight = maxHeight(root->right, countPaths) + 1; 

    // Return the height of the children
    if (leftHeight >= rightHeight){
        return leftHeight;
    }

    return rightHeight;
}

