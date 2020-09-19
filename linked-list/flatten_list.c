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
