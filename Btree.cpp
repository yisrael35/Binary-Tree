#include "Btree.h"
#include <iostream>
using namespace std;
/* 
 yisrael bar
 update 20-21/12/2019
 */
//empty constructor
Btree::Btree() {
    root = NULL;
}


//////////////////////////////

//print a tree by type in-order
void Btree::print()
{
  print(root);
}
//recrsive_print by type in-order
void Btree::print( node *leaf){
    if(leaf==NULL){
    return ;
  }
    print(leaf->left);
    printf("%d " , leaf->value);
    print(leaf->right);
}

//Destructor free all the leafs and after free the root 
Btree::~Btree() {
    
    delet_haelper(root);
    // free(root);
}
//Destructor helaper works by recorsive- dfs
void Btree::delet_haelper( node *leaf){
    if(leaf==NULL){
    return ;
  }
    delet_haelper(leaf->left);
    delet_haelper(leaf->right);
    delete(leaf);
    // free(leaf->left);
    // free(leaf->right);
    
}

//find the smallest helper-recorsive-go thrwo all the tree and chack for the min
// and only to left  because you can do a mirror and its no longer a binary search tree
int smallestHelper(node *leaf,int temp){
    if(leaf==NULL){
        return INT32_MIN;
    }
if (leaf->value<temp)
{
    temp=leaf->value;
} 
if(smallestHelper(leaf->left,temp)!=INT32_MIN)
 return smallestHelper(leaf->left,temp);
  if(smallestHelper(leaf->right,temp)!=INT32_MIN)
return smallestHelper(leaf->right,temp);

return temp;
}
//find the smallest value in the tree
int Btree:: smallest (){
return smallestHelper(root,root->value);
}



//helper check if the tree is binary
//check by ruls binary search tree all the left are smaller and all the right are bigger
bool checkBinaryHelper(node * leaf){
   if (leaf==NULL)
   {
       return true;
   }
   if(leaf->left!=NULL){
    if(leaf->left->value<leaf->value ){
      return  checkBinaryHelper(leaf->left);
    }else return false;
   }
   if (leaf->right!=NULL)
   {
     if(leaf->right->value>leaf->value ){
   return  checkBinaryHelper(leaf->right);
    }else return false;
   }
   return true;
}

// return 1 if its a binary tree and else 0
int Btree:: checkBinary(){
if (checkBinaryHelper(root)==true)
{
    return 1;
}else return 0;

}
//check the depth of the tree start to count from 0 
int treeDepthHelper(node*  root) {
    if (root == NULL) {
        return -1;
    }
    if (treeDepthHelper(root->left) > treeDepthHelper(root->right)) {
        return treeDepthHelper(root->left) + 1;
    } else {
        return treeDepthHelper(root->right) + 1;
    }
}

//check the depth of the tree
int Btree:: treeDepth(){
return (treeDepthHelper(root)+1);
}

//recorsive_insert by mathod of binary search tree

void Btree::insert(int key, node *leaf) {

    if (key < leaf->value) {
        if (leaf->left != NULL) {
            insert(key, leaf->left);
        }
        else {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        
        }
    }
    else if (key >= leaf->value) {
        if (leaf->right != NULL) {
            insert(key, leaf->right);
        }
        else {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
            
        }
    }

}

// //insert a new node/value by mathod of binary search tree
void Btree::insert(int key) {
    if (root != NULL) {
        insert(key, root);
    }
    else {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
        
        
    }
}


//recorsive_insert by binary search tree mirror mathod
void Btree::insertMirror(int key, node *leaf) {
    if (key <= leaf->value) {
        if (leaf->right != NULL) {
            insertMirror(key, leaf->right);
        }
        else {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->right = NULL;
            leaf->right->left = NULL;
        }
    }

        else if (key > leaf->value) {
        if (leaf->left != NULL) {
            insertMirror(key, leaf->left);
        }
        else {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
}

// insert by binary search tree mirror mathod
void Btree::insertMirror(int key) {
    if (root != NULL) {
        insertMirror(key, root);
    }
    else {
         root = new node;
        root->value = key;
         root->left = NULL;
        root->right = NULL;

    }
}

//go throw the tree and call on each value to insert by mirror mathod with the new tree (newRoot)
void Btree::doTheMirror( node *root,Btree *newRoot){
    if(root==NULL){
    return ;
  }
    doTheMirror(root->left,newRoot);
   newRoot->insertMirror(root->value);
   
    doTheMirror(root->right,newRoot);
    // return newRoot->root;
}


//take one tree and make new tree like mirror and replace the first one
void Btree::  mirror(){
//   node * n1=new node();
  Btree* b1=new Btree();
  
 doTheMirror(root,b1 );
 //delete the old root
delet_haelper (root);
//conect the new tree to the old 
root=b1->root;

}


// node * Btree:: doTheMirror(node *other){
// if(other==NULL){
//     return NULL;
// }

//   node * n1=new node();
//   n1->value=other->value;
// n1->left=this->doTheMirror( other->right);
// n1->right=this->doTheMirror( other->left);
// return n1;
// }

//go throw both of the trees and check if every thing is extcly the same
int checkEqualHelper(node *root,node *other){
// if(root!=NULL || other!=NULL)
    if(root==NULL && other==NULL){
        return 1;
    }
    // else return 0;
if(root!=NULL && other!=NULL){
// if (root->value==other->value)
// {
//    return checkEqualHelper(root->left,other->left);
//    return checkEqualHelper(root->right,other->right);
// }
return root->value==other->value && checkEqualHelper(root->left,other->left) &&checkEqualHelper(root->right,other->right);
}
// else 
return 0;
// return 1;
}


//check between two trees if are they the same- return 1 if they are, and 0 if not
int  Btree:: checkEqual(Btree * other){
if (checkEqualHelper(root,other->root)==1) {
    return 1;
}
    return 0;
}


