#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char letter;
    struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head) {
    int len = 0;
    node* current = head;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}

// Parses the string in the linkedList.
char* toCString(node* head) {
    int len = length(head);
    char* str = (char*)malloc(sizeof(char) * (len + 1)); // +1 for the null terminator
    node* current = head;
    int i = 0;
    while (current != NULL) {
        str[i++] = current->letter;
        current = current->next;
    }
    str[i] = '\0'; // Null-terminate the string
    return str;
}

// Inserts character to the linkedlist.
void insertChar(node** pHead, char c) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->letter = c;
    new_node->next = NULL;

    if (*pHead == NULL) {
        *pHead = new_node;
    } else {
        node* current = *pHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Deletes all nodes in the linkedList.
void deleteList(node** pHead) {
    node* current = *pHead;
    node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *pHead = NULL; // Set head pointer to NULL
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, "%d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, "%d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile,"%c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}