/* Node that uses a static length string implementation */
#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFF 256 /* Maximum buffer size for static length string */

struct Node
{
    char string[MAX_BUFF];
    unsigned int MAX_LENGTH;
    struct Node *next;
    struct Node *prev;
    void (*copy)(struct Node*, char*);
    void (*append)(struct Node*, char*);
};

void Node_copy(struct Node *self, char *s)
{
    if (strlen(s) > self->MAX_LENGTH)
	puts("Error: Source string too large for destination string. Leaving string unchanged.");
    else
	strcpy(self->string, s);
}

void Node_append(struct Node *self, char *s)
{
    if ((strlen(self->string) + strlen(s) + 1) > self->MAX_LENGTH)
	puts("Error: Source string too large for destination string. Leaving string unchanged.");
    else
	strcat(self->string, s);
}

struct Node* makeNode()
{
    struct Node *result = malloc(sizeof(struct Node));
    result->string[0] = '\0';
    result->MAX_LENGTH = MAX_BUFF;
    result->next = NULL;
    result->prev = NULL;
    result->copy = Node_copy;
    result->append = Node_append;
    return result;
}

inline void deleteNode(struct Node *it) /* Does nothing for static length string */
{
    return;
}
