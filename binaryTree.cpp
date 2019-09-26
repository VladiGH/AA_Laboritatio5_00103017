#include <iostream>
#include<stdio.h>
#include<stdlib.h>
/*
Ejercicio​:crear una función que borre un nodo de un árbol. Crear también función para el preorden.
*/
using namespace std;
struct node{
    int key;
    struct node *left, *right;
};
// A utility function to create a new BST node
struct node *newNode(int item){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

// A utility function to do inorder traversal of BST
void inorder(struct node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key){
    /* If the tree is empty, return a new node */
    if (node == NULL) 
        return newNode(key);
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key);
    else if (key > node->key) 
        node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}
struct node* findNode(struct node* node, int key){
    if(key == node->key){
       // cout << "ENCONTRÉ TU DATO: "<<node->key<<endl;
        return node;
    }else if(key > node->key){
        return findNode(node->right, key);
    }else if(key < node->key){
        return findNode(node->left, key);
    }
    return NULL;
}
/**
 * Falta corregir
 */
struct node* minNode(struct node* node){
    struct node* ant;
    while(node->left){
        ant = node;
        node = node->left;
    }
    ant -> left =NULL;
    return node;
}

struct node* del(struct node* node,int key){
        /* If the tree is empty, return a new node */
    /* Otherwise, recur down the tree */
    if(node->key==key){
        if(node->left==NULL && node->right==NULL){
            //struct node * temp=node;
            free(node);
            return NULL;
        }
        if(node->left == NULL && node->right != NULL){
            struct node *temp=node;
            node = node->right;
            node->right = temp;
            free(node->right);
        }
        if(node->left != NULL && node->right == NULL){
            struct node *temp=node;
            node = node->left;
            node->left = temp;
            free(node->left);
        }
        if(node->left != NULL && node->right != NULL){
            struct node* temp = minNode(node->right);
            temp->right = node->right;
            temp->left = node->left;
            free(node);
            return temp;
        }
    }
    if (key < node->key) 
        node->left = del(node->left, key);
    else if (key > node->key) 
        node->right = del(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}

int main(){
/* Let us create following BST
    50
    / \
    30 70
   / \ / \
  20 40 60 80 */
  struct node *root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  // print inoder traversal of the BST
  inorder(root);
  //findNode(root, 40);
  cout<<endl;
  del(root, 70);
  del(root, 40);
  del(root, 20);
  inorder(root);
    return 0;
}