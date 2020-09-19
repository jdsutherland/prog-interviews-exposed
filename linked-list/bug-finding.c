// Find bug: supposed to remove the head element from a singly linked list
void removeHead(ListElement **head) {
  if (!head || !*head) return;

  ListElement *tmp = (*head)->next;
  free(*head);
  *head = tmp;
}
