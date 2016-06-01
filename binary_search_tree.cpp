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
    cout << "Something went wrong, tree was not initialize\n";
    system.exit(ERROR);
  }
  return root;
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

  return 0;
}
