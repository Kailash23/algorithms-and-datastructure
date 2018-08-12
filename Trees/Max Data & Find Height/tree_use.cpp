#include <iostream>
#include <queue>
#include <stack>
#include "TreeNode.h"

using namespace std;

/*
   Function to take input level wise using queue
 */
TreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<< "Enter root data: " <<endl;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);		// Creating root node
	queue<TreeNode<int>*> pendingNodes;		// for taking input level wise we are using queue data structure having element of type TreeNode<int>*
	pendingNodes.push(root);		// Adding root node into queue for processing

	while (pendingNodes.size() != 0) {		// we can also queue's empty function
		TreeNode<int>* frontPointer = pendingNodes.front();		// Storing node at front of queue to frontPointer pointer of type TreeNode<T>* (frontPointer pointing to node in front of queue)
		pendingNodes.pop();		// Poping the front element
		cout<< "Enter num of children of " << frontPointer->data <<" : "<<endl;
		int numChild;
		cin >> numChild;
		for(int i = 0; i < numChild; i++) {
			int childData;
			cout<< "Enter child '"<< i+1 <<"' of "<< frontPointer->data <<" : "<<endl;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);		// Creating child node
			frontPointer->children.push_back(child);		// Creating link between root and child
			pendingNodes.push(child);		//Pushing child nodes created into queue for there processing
		}
	}
	return root;
}

/*
   Function return the max node in the tree
 */
TreeNode<int>* maxDataNode(TreeNode<int>* root){

	if(root == NULL){		//Side case -> if root is NULL return (to avoid this 'root->data')
		return NULL;		
	}

	queue<TreeNode<int>*> pendingNodes;		//queue is maintain to vist all nodes in tree level wise
	pendingNodes.push(root);

	int max = root->data;		// Initailly data in root is set as max
	TreeNode<int>* maxNode = root;		// root is set as max node initially

	while(pendingNodes.size() != 0){		// while queue is not empty
		TreeNode<int>* frontPointer = pendingNodes.front();		// extracting front, frontPointer point to it extreacted node
		pendingNodes.pop();		// pop the front node as we saved its memory refrence

		for(int i=0; i < frontPointer->children.size(); i++ ){		// Traversing all the child nodes
			if(max < frontPointer->children[i]->data){		// If child node data is greater than max
				maxNode = frontPointer->children[i];		// update maxNode
				max = frontPointer->children[i]->data;		// update max
			}
			pendingNodes.push(frontPointer->children[i]);	// Pushing all child nodes of root node into queue for checking their child too.
		}
	}
	return maxNode;		// return max value containing node
}

/*
   Printing will done in Level Wise (Queue is used in order to print in level wise)
   root : child 1 , child 2
   child 1 : child 1.1 , child 1.2
   child 2 : child 2.1 , child 2.2
 */
void printTree(TreeNode<int>* root) {

	if(root == NULL) {		//Side case
		return;
	}

	queue<TreeNode<int>*> pendingNodes;		// We are maintaining nodes whose child is to be printed (in order to print level wise)
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
		    pendingNodes.push(frontPointer->children[i]);		// Pushing child node of the root node into the queue for the printing (as we are working level wise).
		}
	}
}

/*
   Function return the height of tree.
   root alone is considered as height 1.
 */
int height(TreeNode<int>* root){
	if(root == NULL){
		return 0;
	}
	int ans = 0;
	for(int i=0; i < root->children.size() ;i++) {
		int childHeight = height(root-> children[i]);
		if(childHeight > ans){
			ans = childHeight;
		}
	}
	return ans + 1;		// added 1 for root (root node alone count as height 1)
}

int main(){
	TreeNode<int>* root = takeInputLevelWise();

	printTree(root);

	TreeNode<int>* maxNode;
	maxNode = maxDataNode(root);
	cout << "\nMax Node: " <<maxNode->data;

	cout<< "\nHeight of Tree: ";
	cout<<height(root);
}
