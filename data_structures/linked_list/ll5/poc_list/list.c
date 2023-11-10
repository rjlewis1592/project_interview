#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node node_t;

node_t *create_node(int value)
{
	node_t *new_node = (node_t *)malloc(sizeof(node_t));
	if (new_node == NULL) {
		return NULL;
	}

	new_node->data = value;
	new_node->next = NULL;

	return new_node;
}

void list_delete(node_t *head)
{
	node_t *tmp = NULL;

	if (head == NULL) {
		return;
	}

	while (head != NULL) {
		tmp = head;
		head = head->next;
		free(tmp);
		tmp = NULL; // fix dangling pointer
	}
}

void list_display(node_t *head, const char *title)
{
	printf("%s: ", title);

	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

node_t* list_append(node_t *head, int value)
{
	node_t *tmp = head;

	if (head == NULL) {
		head = create_node(value);
		return head;
	}

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = create_node(value);

	return head;
}

node_t* list_reverse(node_t *head)
{
	node_t *curr = NULL;
	node_t *prev = NULL;

	if (head == NULL) {
		return head;
	}

	prev = NULL;
	while (head != NULL) {
		curr = head;
		head = head->next;
		curr->next = prev;
		prev = curr;
	}

	return curr;
}

node_t* list_kreverse(node_t *head, int k)
{
	node_t *curr = NULL;
	node_t *prev = NULL;
	node_t *th = NULL;
	int c;

	if (head == NULL) {
		return NULL;
	}

	if (k <= 0) {
		return head;
	}

	c = k;
	prev = NULL;
	th = head;
	while ((th != NULL) && (c > 0)) {
		curr = th;
		th = th->next;
		curr->next = prev;
		prev = curr;
		c--;
	}

	if (c > 0) {
		return list_reverse(prev);
	}

	if (th != NULL) {
		head->next = list_kreverse(th, k);
	}

	return prev;
}

node_t* list_kreverse_all(node_t *head, int k)
{
	node_t *curr = NULL;
	node_t *prev = NULL;
	node_t *th = NULL;
	int c;

	if (head == NULL) {
		return NULL;
	}

	if (k <= 0) {
		return head;
	}

	c = k;
	prev = NULL;
	th = head;
	while ((th != NULL) && (c > 0)) {
		curr = th;
		th = th->next;
		curr->next = prev;
		prev = curr;
		c--;
	}

	if (th != NULL) {
		head->next = list_kreverse_all(th, k);
	}

	return prev;
}

int main()
{
	int i, n, k, value;
	node_t *head = NULL;

	printf("Enter n: ");
	scanf("%d", &n);

	printf("Enter %d values: ", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &value);
		head = list_append(head, value);
	}

	list_display(head, "init    list");
#if 0
	head = list_reverse(head);
	list_display(head, "revi    list");

	printf("Enter k: ");
	scanf("%d", &k);
	head = list_kreverse(head, k);
	list_display(head, "krevall  list");
#endif

	printf("Enter k: ");
	scanf("%d", &k);

	head = list_kreverse(head, k);
	list_display(head, "krev    list");

	list_delete(head);
	return 0;
}

