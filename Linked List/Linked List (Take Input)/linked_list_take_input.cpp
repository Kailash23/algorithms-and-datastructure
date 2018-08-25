#include <iostream>
using namespace std;
#include "Node.cpp"

/*
   Function to input data into linked list.
   Time Complexity : O(n^2)
 */

Node* takeInput(){
	int data;
	cin>>data;
	Node *head = NULL;
	while(data != -1) {             // Loop will terminate if data is -1
		Node *newNode = new Node(data);         // newNode will destroy after new iteration of while
		// loop, but Node will not distroy as it is created dynamically.
		if(head == NULL) {               // For making first node as head
			head = newNode;
		} else {
			Node *temp = head;              // Using temp to get to the second last node and linking it to the last node
			while(temp->next != NULL) {              // Will go to second last node
				temp = temp->next;
			}
			temp->next = newNode;           // Linking
		}
		cin>>data;
	}
	return head;            // return head of linked list
}

/*
   Function to input data into linked list.
   Time Complexity : O(n)
   We are maintaining pointer (ie tail) to the last node of linked list along with head
   (which point to first node). So that we can avoid while loop inside else statement
   which travesing to find second last element in the linked list and then linking it.
   This will bring down our time complexity to O(1)
 */

Node* takeInput_Better(){
	int data;
	cin>>data;
	Node *head = NULL;              // Head will point to first node
	Node *tail = NULL;              // Tail will point to last node
	while(data != -1) {
		Node *newNode = new Node(data);         // Dynamically allocating newNode
		if(head == NULL) {               // If linked list is empty initially
			head = newNode;
			tail = newNode;
		} else {
			tail->next = newNode;           // Pointing tail node (currently last node) to the newly formed node.
			tail = tail->next;
			// OR
			// tail = newNode;
		}
		cin>>data;
	}
	return head;
}

/*
   Function to print linked list.
 */

void printLL(Node* head){
	while (head!=NULL) {            //This will traverse to the last node
		cout<<head->data<<" ";
		head = head->next;
	}
}

int main(){
	//Node *head = takeInput();
	Node *head = takeInput_Better();
	printLL(head);
}

/*
   Linked list elements (separated by space and terminated by -1)
 */

/*
   4 5 3 2 1 9 7 -1
   4 5 3 2 1 9 7
 */
