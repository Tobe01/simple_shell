#include "shell.h"
/**
 * add_node - adds a node to the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: pointer to node
 */
lst_node *add_node(list_t **head, char *lst)
{
lst_node *new_node;
if (lst == NULL)
return (NULL);
new_node = (lst_node *)malloc(sizeof(lst_node));
if (new_node == NULL)
{
perror("Could'nt allocate memory");
exit(EXIT_FAILURE);
}
new_node->lst = lst;
new_node->next = NULL;
return (new_node);
}
/**
 * insertNode - inserts new node
 * @head: head of the list
 * @dir: directory
 *
 */
void insertNode(lst_node **head, char *lst)
{
lst_node *new_node = add_node(lst);
if (new_node == NULL)
return;
if (*head == NULL)
*head = new_node;
else
{
lst_node *current = *head;
while (current->next != NULL)
current = current->next;
current->next = new_node;
}
}
/**
 * free_list - frees node
 * @head: head list
 */
void free_list(lst_node *head)
{
lst_node *current = head;
while (current != NULL)
{
lst_node *temp = current;
current = current->next;
free(temp);
}
}
