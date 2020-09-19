#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct element {
  struct element *next;
  int data;
} Element;

Element *head, *tail;

bool create_stack(Element **stack) {
  *stack = NULL;
  return true;
}

// Remove target from list.
bool delete (Element *target) {
  if (!target) return false;
  Element *current = NULL;
  for (Element **pp_next = &head; 1; pp_next = &(current->next)) {
    if (*pp_next == target) {
      *pp_next = target->next;
      if (!target->next)
        tail = current;
      free(target);
      return true;
    }
    if (!(current = *pp_next)) break;
  }
  return false;
}

// Inserts after target. If target is NULL, inserts at front.
bool insert_after(Element *target, int data) {
  Element *new = malloc(sizeof(*new));
  if (!new) return false;
  new->data = data;

  Element *current = NULL;
  for (Element **pp_next = &head; 1; pp_next = &(current->next)) {
    if (current == target) {
      new->next = *pp_next;
      *pp_next = new;
      if (!new->next)
        tail = new;
      return true;
    }
    if (!(current = *pp_next)) break;
  }
  free(new);
  return false;
}

// Inserts new node at end of the list.
bool push(Element **stack, int data) {
  Element *ele = malloc(sizeof(Element));
  if (!ele) return false;

  ele->data = data;
  ele->next = *stack;
  *stack = ele;
  return true;
}

bool pop(Element **stack, int *data) {
  Element *ele;
  if (!(ele = *stack)) return false;

  *data = ele->data;
  *stack = ele->next;
  free(ele);
  return true;
}

bool delete_stack(Element **stack) {
  if (!stack) return false;

  Element *next;
  for (next = (*stack)->next; *stack; *stack = next) free(*stack);
  return true;
}

void print_stack(Element *stack) {
  if (!head) printf("{}\n");
  for (; stack; stack = stack->next) {
    printf("%d\n", (int)stack->data);
  }
}

Element *find_mth_to_last(Element *head, int m) {
  if (!head) return NULL;
  Element *current = head;
  Element *m_behind = head;
  for (int i = 0; i < m; i++) {
    if (current->next) {
      current = current->next;
    } else
      return NULL;
  }
  while (current->next) {
    current = current->next;
    m_behind = m_behind->next;
  }
  return m_behind;
}

int main() {
  /* int *popped = malloc(sizeof(void *)); */
  Element *stack;
  create_stack(&stack);

  /* push(&stack, 1); */
  /* assert(stack->data == 1); */
  /* push(&stack, 2); */
  /* assert(stack->data == 2); */
  /* push(&stack, (void *)3); */
  /* assert(stack->data == (void *)3); */

  head = stack;
  tail = stack;
  print_stack(head);
  printf("\n");

  /* delete(head); */
  /* print_stack(head); */
  /* printf("\n"); */

  insert_after(tail, 1);
  insert_after(tail, 2);
  insert_after(tail, 3);
  insert_after(tail, 4);
  print_stack(head);
  printf("\n");

  insert_after(NULL, 0);
  print_stack(head);
  printf("\n");

  insert_after(tail, 99);
  print_stack(head);
  printf("\n");
  /* printf("%d\n", tail->data); */
  /* printf("\n"); */

  Element *mth_to_last = find_mth_to_last(head, 6);
  printf("\n");
  if (mth_to_last)
    printf("%d\n", mth_to_last->data);

  /* insert_after(head->next->next, 69); */
  /* delete(head); */
  /* delete(head->next); */
  /* delete(tail); */
  /* insert_after(head, 3); */
  /* print_stack(head); */
  /* printf("\n"); */

  /* assert(tail); */
  /* printf("\n"); */
  /* printf("%d\n", (int)tail->data); */

  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 3); */
  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 2); */
  /* pop(&stack, (void *)popped); */
  /* assert(*popped == 1); */
  /* print_stack(&stack); */

  /* free(popped); */
  /* delete_stack(&stack); */
}
