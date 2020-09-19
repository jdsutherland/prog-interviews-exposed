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

// Inserts after ele. If ele is NULL, inserts at front.
bool insert_after(Element *ele, int data) {
  Element *new = malloc(sizeof(*new));
  if (!new) return false;
  new->data = data;

  if (!ele) {
    new->next = head;
    head = new;
    if (!tail)
      tail = new;
    return true;
  }

  for (Element *walk = head; walk; walk = walk->next) {
    if (walk == ele) {
      new->next = ele->next;
      ele->next = new;
      if (ele == tail)
        tail = new;
      return true;
    }
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

  /* printf("%d\n", tail->data); */
  /* printf("\n"); */

  insert_after(head->next->next, 69);
  insert_after(NULL, 420);
  /* insert_after(head, 3); */
  print_stack(head);
  printf("\n");

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
