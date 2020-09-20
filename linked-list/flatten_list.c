#include <stdio.h>

typedef struct node {
  struct node *next;
  struct node *prev;
  struct node *child;
  int data;
} Node;

// Appends the child list to the end of the tail and updates * the tail.
void append(Node *child, Node **tail) {
  (*tail)->next = child;
  child->prev = *tail;
  Node *walk;
  for (walk = child; walk->next; walk = walk->next);
  *tail = walk;
}

void flatten_list(Node *head, Node **tail) {
  for (Node *walk = head; walk; walk = walk->next) {
    if (walk->child)
      append(walk->child, tail);
  }
}

static void prune_children(Node *node) {
  for (Node *walk = node; walk; walk = walk->next) {
    if (walk->child) {
      walk->child->prev->next = NULL;
      walk->child->prev = NULL;
      prune_children(walk->child);
    }
  }
}

void unflatten_list(Node *start, Node **tail) {
  Node *walk = start;
  prune_children(walk);
  for (; walk; walk = walk->next);
  *tail = walk;
}
