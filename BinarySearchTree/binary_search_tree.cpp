#include <iostream>
#include <stdlib.h>
#define ERROR -1;


using namespace std;

typedef struct tree *Tree;

/* Structs */
struct tree {
  int info;
  struct tree *left;
  struct tree *right;
};

/* Pre loader Functions */

int insert_tree(Tree *root, int value);
void pre_sequence_tree(Tree *root);
void sequence_tree(Tree *root);
void post_sequence_tree(Tree *root);
void free_all_node(Tree node);
int remove_node_tree(Tree *root, int value);
struct tree* remove_current_node(struct tree* current);
void free_tree(Tree *root);

/* Functions */
Tree* initialize_tree() {

  Tree *root = (Tree*)malloc(sizeof(Tree));

  /* Here I verify, if tree was successful allocated */
  if(root != NULL) {
    *root = NULL;
  } else {
    /* do nothing */
  }
  return root;
}

int insert_tree(Tree *root, int value) {

  if(root == NULL) {
    return 0;
  } else {
    /* do nothing */
  }
  Tree new_node = (Tree)malloc(sizeof(Tree));

  if(new_node == NULL) {
    cout << "Something went wrong, tree was not initialize\n";
    return 0;
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
        cout << "The element allredy exist\n";
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

void pre_sequence_tree(Tree *root) {
  if(root == NULL) {
    return;
  } else {
    if(*root != NULL) {
      cout << (*root)->info << endl;
      pre_sequence_tree(&((*root)->left));
      pre_sequence_tree(&((*root)->right));
    } else {
      /* do nothing */
    }
  }
}

void sequence_tree(Tree *root) {
  if(root ==  NULL) {
    return;
  } else {
    if(*root != NULL) {
      sequence_tree(&((*root)->left));
      cout << (*root)->info << endl;
      sequence_tree(&((*root)->right));
    } else {
      /* do nothing */
    }
  }
}

void post_sequence_tree(Tree *root) {
  if(root ==  NULL) {
    return;
  } else {
    if(*root != NULL) {
      post_sequence_tree(&((*root)->right));
      post_sequence_tree(&((*root)->left));
      cout << (*root)->info << endl;
    } else {
      /* do nothing */
    }
  }
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
    cout << "Tree empty\n";
    return 0;
  } else {
    /*do nothing */
  }

  struct tree *previous = NULL;
  struct tree *current = *root;
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

struct tree* remove_current_node(struct tree* current) {
  struct tree *aux1_tree, *aux2_tree;
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
  int success_insertion, success_remove, value, option_menu, running=1;

  root = initialize_tree();
  while(running) {
    cout << "Enter an option\n1-Insert value in tree\n2-Print in pre-sequence\n3-Print in sequence\n4-Print in pos-sequence\n5-Remove a node\nAny other option to close\n";
    cin >> option_menu;
    switch (option_menu) {
      case 1:
      cin >> value;
      success_insertion = insert_tree(root, value);
      if(success_insertion) {
        cout << "Success on insertion\n";
      } else {
        cout << "Something were wrong\n";
      }
      break;
      case 2:
      pre_sequence_tree(root);
      break;
      case 3:
      sequence_tree(root);
      break;
      case 4:
      post_sequence_tree(root);
      break;
      case 5:
      cin >> value;
      success_remove = remove_node_tree(root, value);
      if(success_remove) {
        cout << "Success on remove\n";
      } else {
        cout << "Something were wrong\n";
      }
      break;
      default:
        running = 0;
        free_tree(root);
      break;
    }
  }
  return 0;
}
