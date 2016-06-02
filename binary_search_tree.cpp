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
    /* do nothing */
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
      previous->right = new_node;
    } else {
      previous->left = new_node;
    }
  }
  return 1;
}

void free_all_node(Tree node) {

  if(node == NULL) {
    /* do nothing */
    return;
  } else {
    free_all_node(node->left);
    free_all_node(node->right);
    free(node);
    node = NULL;
  }
}

int remove_node_tree(Tree *root, int value) {

  if(root == NULL) {
    cout >> "Tree empty\n";
    return 0;
  } else {
    Tree previous = NULL;
    Tree current = *root;
    while (current != NULL) {
        if(value == current->info) {
          if(current == *root) {
            *root = remove_current_node(current);
          } else {
            if(previous->right == current) {
              previous->right = remove_current_node(current);
            } else {
              previous->left = remove_current_node(current);
            }
          }
          return 1;
        } else {
          previous = current;
          if(value > current->info) {
            current = current->right;
          } else {
            current = current->left;
          }
        }
    }
  }
}


Tree remove_current_node(Tree current) {
  Trre aux1_tree, aux2_tree;
  if(current->left == NULL) {
    aux2_tree = current->right;
    free(current);
    return aux2_tree;
  } else {
    aux1_tree = current;
    aux2_tree = current->left;
    while (aux2_tree->right != NULL) {
      aux1_tree = aux2_tree;
      aux2_tree = aux2_tree->right;
    }
  }

  if(aux1_tree != current) {
    aux1_tree->right = aux2_tree->left;
    aux2_tree->left = current->left;
  } else {
    /* do nothing */
  }
  aux2_tree->right = current->right;
  free(current);
  return aux2_tree;
}

void free_tree(Tree *root) {

  if(root == NULL) {
    /* do nothing */
    return;
  } else {
    free_all_node(*root);
    free(root);
  }
}

int main() {

  Tree *root;
  int success;

  success = insert_tree(Tree *root, int value);
  return 0;
}
