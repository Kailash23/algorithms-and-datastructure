#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;

/*
   Function to take input level wise using queue.
 */
TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cout<< "Enter root data: " <<endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);		// Creating root node having data 'rootData' (Root node creation).
	queue<TreeNode<int>*> pendingNodes;		// for taking input level wise we are using queue data structure having element of type TreeNode<int>*.
	pendingNodes.push(root);		// Adding root node into queue for processing.

	while (pendingNodes.size() != 0) {		// we can also queue's empty function.
		TreeNode<int>* frontPointer = pendingNodes.front();		// Storing node at front of queue to frontPointer pointer of type TreeNode<T>* (frontPointer pointing to node in front of queue).
		pendingNodes.pop();		// Poping the front element
		cout<< "Enter num of children of " << frontPointer->data <<" : "<<endl;		//Extracting node from queue to frontPointer and work on it.
		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			int childData;
			cout<< "Enter child '"<< i+1 <<"' of "<< frontPointer->data <<" : "<<endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);		// Creating child node with data 'childData' (Child node creation).
			frontPointer->children.push_back(child);		// Creating link between root and child.
			pendingNodes.push(child);		// Pushing child nodes created into queue for there processing.
		}
	}
	return root;
}

/*
   Function will count the number of leaf node in a generic tree.
   Here we are traversing each node of the tree and incrementing count only
   when we got node whose children vector has size 0.
 */
int numLeafNodes(TreeNode<int>* root){
	if(root == NULL){		// If there is no node (no root) then no of leaf node is zero. (side case) (segfault - root->next)
		return 0;
	}
	int count = 0;
	queue<TreeNode<int>*> pendingNodes;		// We are maintaining queue as we are going to traverse whole tree.
	pendingNodes.push(root);

	while(pendingNodes.size() != 0){
		TreeNode<int>* frontPointer = pendingNodes.front();
		pendingNodes.pop();

		if(frontPointer->children.size() == 0){		// If root has no child then increment count. (Leaf node found)
			 ++count;
		}

		for(int i=0 ; i < frontPointer->children.size() ; i++){
			pendingNodes.push(frontPointer->children[i]);		// Pushing child nodes into queue for checking there count of children (ie children vector size).
		}
	}
	return count;		// return count after traversing and checking each node of tree.
}

/*
   Printing will done in Level Wise (Queue is used in order to print in level wise)
   root : child 1 , child 2
   child 1 : child 1.1 , child 1.2
   child 2 : child 2.1 , child 2.2
 */
void printTree(TreeNode<int>* root) {

	if(root == NULL) {		//Side case -> if root is NULL return (to avoid this 'root->data')
		return;
	}

	queue<TreeNode<int>*> pendingNodes;		// We are maintaining queue of nodes whose child is to be printed (in order to print level wise)
	pendingNodes.push(root);		// Pushing root node to queue

	while(pendingNodes.size() != 0){
		TreeNode<int>* frontPointer = pendingNodes.front();		// Taking front out from queue  (frontPointer is pointing to node which is in front of queue)
		pendingNodes.pop();		// Poping the front node (poping ie deletion is done from front in queue)
		cout<< frontPointer->data <<":";
		for(int i = 0; i < frontPointer->children.size(); i++){
			if(i == frontPointer->children.size()-1){		// if last child node don't print comma at end
            	cout<< frontPointer->children[i]->data;			// Displaying child nodes
          	} else {
		    	cout<< frontPointer->children[i]->data <<",";		// Displaying child nodes
          	}
		}
		cout<<endl;
		for(int i = 0; i < frontPointer->children.size(); i++){
		    pendingNodes.push(frontPointer->children[i]);		// Pushing child nodes into queue for printing there child nodes too.
		}
	}
}

/*
   Tree input shortcut just paste below line
   1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
 */

int main(){
	TreeNode<int>* root = takeInputLevelWise();
	printTree(root);
	cout<< "Num of leaf node";
	cout<< numLeafNodes(root);
}
