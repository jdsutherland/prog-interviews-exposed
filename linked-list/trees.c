#include <stdlib.h>
#include <stddef.h>

typedef struct node node_t;

struct node {
   node_t *right;
   node_t *left;
   int data;
};

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

static node_t *create_node(int data) {
  node_t *tree = calloc(1, sizeof(node_t));
  if (!tree) return NULL;
  tree->data = data;
  return tree;
}

static void insert(node_t **tree, int data) {
  if (!tree || !*tree) return;

  node_t **direction = (data <= (*tree)->data)
    ? &((*tree)->left)
    : &((*tree)->right);

  if (!*direction) {
    *direction = create_node(data);
  } else {
    insert(direction, data);
  }
}

node_t *build_tree(int *tree_data, size_t tree_data_len) {
  if (!tree_data || tree_data_len < 1) return NULL;
  node_t *tree = create_node(tree_data[0]);
  if (!tree) return NULL;

  for (size_t i = 1; i < tree_data_len; i++) {
    insert(&tree, tree_data[i]);
  }
  return tree;
}

void free_tree(node_t *tree) {
  if (!tree) return;

  if (tree->left) free_tree(tree->left);
  if (tree->right) free_tree(tree->right);
  free(tree);
}

static void sort(node_t *tree, int **result, size_t *idx, size_t *cap) {
  if (!tree) return;

  if (tree->left) sort(tree->left, result, idx, cap);

  if (*idx == *cap) {
    *cap *= 2;
    *result = realloc(*result, *cap * sizeof(int));
  }
  (*result)[(*idx)++] = tree->data;

  if (tree->right) sort(tree->right, result, idx, cap);
}

int *sorted_data(node_t * tree) {
  if (!tree) return NULL;
  size_t idx = 0;
  size_t cap = 4;
  int *sorted = malloc(sizeof(*sorted) * cap);
  sort(tree, &sorted, &idx, &cap);
  return sorted;
}

node_t *search(node_t *root, int data) {
  if (!root) return NULL;
  if (data == root->data) return root;
  return (data < root->data)
    ? search(root->left, data)
    : search(root->right, data);
}

// O(n)
int height(node_t *root) {
  if (!root) return 0;
  return 1 + MAX(
    height(root->left),
    height(root->right)
  );
}
