/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

struct listnode
{
	struct node* tnode;
	struct listnode *next;
};
struct Queue
{
	struct listnode *front;
	struct listnode *rear;
};
struct Queue * CreateQueue()
{
	struct Queue *Q = NULL;
	Q = (struct Queue *)malloc(sizeof(struct Queue));
	Q->front = Q->rear = NULL;
	return Q;
}
int isEmptyQueue(struct Queue *Q)
{
	return (Q->front == NULL);
}
void EnQueue(struct Queue *Q, struct node *original)
{
	struct listnode *temp = NULL;
	temp = (struct listnode *)malloc(sizeof(struct listnode));
	temp->tnode = original;
	temp->next = NULL;
	if (Q->front == NULL)
		Q->rear = NULL;
	if (Q->rear)
	{
		Q->rear->next = temp;
		Q->rear = temp;
	}
	else
		Q->rear = temp;
	if (Q->front == NULL)
		Q->front = Q->rear;
	//printf("%d enqueued successfully \n", original->data);
}
struct listnode * DeQueue(struct Queue *Q)
{
	struct listnode *temp = NULL, *temp1 = NULL;
	if (isEmptyQueue(Q))
		return NULL;
	temp = temp1 = Q->front;
	Q->front = Q->front->next;

	//free(temp1);
	//printf("\n%d dequeued successfully:", temp->tnode->data);
	//printf("\n Q->front value is %d", Q->front);
	return temp;

}
int* BSTRighttoLeftRows(struct node* root)
{
	struct node *temp = NULL;
	struct listnode *lisnod = NULL;
	struct Queue *Q = NULL;
	int *arr = NULL, k = 0;
	if (root == NULL)
		return NULL;
	Q = CreateQueue();
	EnQueue(Q, root);
	while (!isEmptyQueue(Q))
	{
		lisnod = DeQueue(Q);
		arr = (int *)realloc(arr, sizeof(int)*(k + 1));
		*(arr + k) = lisnod->tnode->data;
		//printf("a[%d] is %d\n", k, *(arr + k));
		k++;
		if (lisnod->tnode->right)
			EnQueue(Q, lisnod->tnode->right);
		if (lisnod->tnode->left)
			EnQueue(Q, lisnod->tnode->left);
		//free(lisnod);

	}

	return arr;

}
