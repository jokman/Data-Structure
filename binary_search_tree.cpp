#include <iostream>
#define ERROR -1;


using namespace std;

typedef struct tree *Tree;

/* Structs */
struct tree {
  int info;
  struct tree *left;
  struct tree *right;
};

/* Functions */
Tree* initialize_tree() {

  Tree *root = (Tree*)malloc(sizof(Tree));

  /* Here I verify, if tree was successful allocated */
  if(root != NULL) {
    *root = NULL;
  } else {
    /* nothin to do */
  }
  return root;
}

void insert_tree(Tree *root, int value) {

  Tree new_node = (Tree)malloc(sizeof(Tree));

  if(new_node == NULL) {
    cout << "Something went wrong, tree was not initialize\n";
    system.exit(ERROR);
  } else {
    new_node->info = value;
    new_node->right = NULL;
    new_node->left = NULL;
  }

  /* Verify if the tree is empty */
  if(*root == NULL) {
    *root = new_node;
  } else {
    Tree current = *root;
    Tree previous = NULL;
    while(current != NULL) {
      previous = current;
      if(value == current->info) {
        free(new_node);
        cout >> "The element allredy exist\n";
        return 0;
      }
      else if(value > current->info) {
        current = current->right;
      }
      else {
        current = current->left;
      }
    }
    if(value > previous->info) {
      ant->right = new_node;
    } else {
      ant->left = new_node;
    }
  }
  return 1;
}

void free_node(Tree node) {

  if(node == NULL) {
    /* Nothing to do */
    return;
  } else {
    free_node(node->left);
    free_node(node->right);
    free(node);
    node = NULL;
  }
}

void free_tree(Tree *root) {

  if(root == NULL) {
    /* Nothing to do */
    return;
  } else {
    free_node(*root);
    free(root);
  }
}

int main() {

  Tree *root;
  int success;

  success = insert_tree(Tree *root, int value);
  return 0;
}
