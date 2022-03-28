//
// Created by devansh tomar on 3/16/22.
//

#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include "binarySearchTree.h"

string comma(int n)
{
    stringstream ss;
    ss << n;
    string s = ss.str();
    int len = s.length();
    for (int i = len - 3; i > 0; i -= 3)   //inserts commas every 3 digits
        s.insert(i, ",");
    return s;
}

bst* insert(bst *root, SOC &element){

    if(root == nullptr){
        root = new bst;
        root->soc = element;
        return root;
    }
    else if(strcmp(root->soc.occupation, element.occupation) < 0){
        root->right = insert(root->right, element);
    }
    else if(strcmp(root->soc.occupation, element.occupation) > 0){
        root->left = insert(root->left, element);
    }
    return root;
}

void printInorder(struct bst* node, string low, string high)
{
    if (node == nullptr) {
        return;
    }
    /* first recur on left child */
    printInorder(node->left, low, high);

    /* then print the data of node */
    if (strcmp(node->soc.occupation, low.c_str()) >= 0 && strcmp(node->soc.occupation, high.c_str()) <= 0) {
        cout << "\t" << node->soc.occupation << ": " << "YRFT: " << comma(node->soc.total) << ", Female: "
             << comma(node->soc.female) << ", Male: " << comma(node->soc.male) << "\n";
    }
    /* now recur on right child */
    printInorder(node->right, low, high);

}