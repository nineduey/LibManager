/**
 * @file bintree.cpp
 * @brief BinTee Class Function Definition file,
 * A binary search tree structure that uses a Node class to hold a container
 * class called NodeData. Binary Tree class does not know the nature of or
 * deals with the NodeData class.
 * @author Amanda Todakonzie
 */
 #include "bintree.h"
 #include <stack>
// -----------------------------------------------------------------------------
// operator <<
// Displays tree nodes inorder traversal
ostream& operator<<(ostream& out, const BinTree& T) {
	stack<Node*> nodeStack;
	Node* current = T.root;
	bool done = false;
	while (!done) {
		if (current != nullptr) {
			nodeStack.push(current);
			current = current->left;
		}
		else {
			if (!nodeStack.empty()) {
				current = nodeStack.top();
				out << " " << *current->dataPtr;
				nodeStack.pop();
				current = current->right;
			}
			else {
				done = true;
			}
		}
	}
	out << endl;
	return out;
}
// -----------------------------------------------------------------------------
// Default Constructor for Node
Node::Node() : dataPtr(nullptr), left(nullptr), right(nullptr) {
}
// -----------------------------------------------------------------------------
// Node Destructor
Node::~Node() {
	delete dataPtr;
	dataPtr = nullptr;
	left = nullptr;
	right = nullptr;
}
// -----------------------------------------------------------------------------
// Copy Constructor for Node
Node::Node(NodeData* objPtr) {
	//create deep copy of NodeData object
	this->dataPtr = new NodeData(*objPtr);
	left = nullptr;
	right = nullptr;
}
// -----------------------------------------------------------------------------
// Default Constructor for BinTree
BinTree::BinTree() : root(nullptr) {
}
// -----------------------------------------------------------------------------
// Copy Constructor for BinTree
BinTree::BinTree(const BinTree& treePtr) {
	this->root = copyTree(treePtr.root);
}
// -----------------------------------------------------------------------------
// Copy Constructor Helper for BinTree
Node* BinTree::copyTree(const Node* treePtr) const {
	Node* newTreePtr = nullptr;
	//copy tree nodes during preorder traversal
	if (treePtr != nullptr) {
		//copy nodes recursively
		newTreePtr = new Node(treePtr->dataPtr);
		newTreePtr->left = copyTree(treePtr->left);
		newTreePtr->right = copyTree(treePtr->right);
	}
	return newTreePtr;
}
// -----------------------------------------------------------------------------
// BinTree Destructor
// Removes a Tree from memory
BinTree::~BinTree() {
	destroy(root);
	root = nullptr;
}
// -----------------------------------------------------------------------------
// destroy
// Private member function to deletes all nodes from tree and its descendants
void BinTree::destroy(Node*& nodePtr) {
	if (nodePtr != nullptr) {
		destroy(nodePtr->left);
		destroy(nodePtr->right);
		delete nodePtr;
	}
}
// -----------------------------------------------------------------------------
// isEmpty Function
// Returns true if tree is empty
bool BinTree::isEmpty() const {
	if (root == nullptr) {
		return true;
	}
	return false;
}
// -----------------------------------------------------------------------------
// makeEmpty Function
// removes and deletes all tree nodes
void BinTree::makeEmpty() {
	destroy(root);
	root = nullptr;
}
// -----------------------------------------------------------------------------
// operator=
// Assignment operator to make deep copy of passed in BinTree object
BinTree& BinTree::operator=(const BinTree& toCopy) {
	this->makeEmpty();
	this->root = copyTree(toCopy.root);
	return *this;
}
// -----------------------------------------------------------------------------
// operator==
// Determines if two BinTree objects are equal
bool BinTree::operator==(const BinTree& toCompare) const {
	bool match = compare(root, toCompare.root);
	return match;
}
// -----------------------------------------------------------------------------
// operator!=
// Determines if two BinTree objects are not equal
bool BinTree::operator!=(const BinTree& toCompare) const {
	bool match = !(compare(root, toCompare.root));
	return match;
}
// -----------------------------------------------------------------------------
// compare
// Helper function for operator== and operator!=
bool BinTree::compare(Node* root, Node* toCompare) const {
	Node* current = root;
	Node* contender = toCompare;
	if (current != nullptr && contender != nullptr) {
		compare(current->left, contender->left);
		compare(current->right, contender->right);
		if (*current->dataPtr != *contender->dataPtr) {
			return false;
		}
	}
	return true;
}
// -----------------------------------------------------------------------------
// insert
// Will insert a NodeData object into the BinTree, returns true if inserted
// successfully
bool BinTree::insert(NodeData* input) {
	//search for duplicate first
	if (find(input)) {
		return false;
	}
	// create new node
	Node* ptr = new Node;
	ptr->dataPtr = input;
	input = nullptr;
	ptr->left = ptr->right = nullptr;
	if (isEmpty()) {
		root = ptr;
	}
	else {
		Node* current = root;
		bool inserted = false;

		// if item is less than current item, insert in left subtree
		// otherwise insert in right subtree
		while (!inserted) {
			if (*ptr->dataPtr < *current->dataPtr) {
				// at leaf, insert left
				if (current->left == nullptr) {
					current->left = ptr;
					inserted = true;
				}
				else	// one step left
					current = current->left;
			}
			else {	// at leaf, insert right
				if (current->right == nullptr) {
					current->right = ptr;
					inserted = true;
				}
				else	// one step right
					current = current->right;
			}
		}
	}
	return true;
}
// -----------------------------------------------------------------------------
// find
// Will search for a target NodeData using NodeData ptr
// Returns true if found, false is not
bool BinTree::find(NodeData* target) {
	Node* current = root;
	bool found = false;
	while (!found) {
		if (current == nullptr) { // if node is nullptr,end of branch
			break;
		}
		else if (*current->dataPtr == *target) { // compare data
			found = true;
			break;
		}
		else if (*target > *current->dataPtr) { // step right
			current = current->right;
		}
		else if (*target < *current->dataPtr) { // step left
			current = current->left;
		}
	}
	return found;
}
// -----------------------------------------------------------------------------
// retrieve
// Will retreive a NodeData* pointer to the object being passed in by ref
bool BinTree::retrieve(const NodeData& target, NodeData*& retriever) const {
	// recursive helper to traverse tree looking for target
	Node* retrieverPtr = retrieveHelper(root, target);
	if (retrieverPtr != nullptr) {
		retriever = retrieverPtr->dataPtr;
		return true;
	}
	return false;
}
// -----------------------------------------------------------------------------
// retrieveHelper
// Helper for retrieve function, searches for a target NodeData using root ptr
// Returns a pointer to the Node containing target if found, return nullptr
// if not found
Node* BinTree::retrieveHelper(Node* current, NodeData target) const {
	if (current == nullptr) {
		return nullptr;
	}
	else if (*current->dataPtr == target) {
		return current;
	}
	else if (*current->dataPtr > target) {
		return retrieveHelper(current->left, target);
	}
	else {
		return retrieveHelper(current->right, target);
	}
}
// -----------------------------------------------------------------------------
// displaysSideways
// Will display the tree sideways for viewing
void BinTree::displaySideways() const {
	sidewaysHelper(root, 0);
}
// -----------------------------------------------------------------------------
// getSibling
// Take two NodeData objs passed by reference to search for sibling of target
// Return true if sibling found, returns false if not
bool BinTree::getSibling(const NodeData& target, NodeData& retriever) const {
	Node* parent = nullptr;
	// recursive search for parent node, will return nullptr if not found
	parent = preorderSearch(root, parent, target);
	//check parent's left & right child to confirm target matched
	if (parent != nullptr) {
		if (*parent->left->dataPtr == target) {
			//check for sibling
			if (parent->right == nullptr)
				return false; // no sibling

			retriever = *parent->right->dataPtr;
			return true;
		}
		else if (*parent->right->dataPtr == target) {
			//check for sibling
			if (parent->left == nullptr)
				return false; // no sibling

			retriever = *parent->left->dataPtr;
			return true;
		}
	}
	return false;
}
// -----------------------------------------------------------------------------
// getParent
// Take two NodeData objects passed by reference to search for parent of target
// Return true if parent found, returns false if not
bool BinTree::getParent(const NodeData& target, NodeData& retriever) const {
	Node* parent = nullptr;
	// recursive search for parent node, will return nullptr if not found
	parent = preorderSearch(root, parent, target);
	if (parent == nullptr)
		return false;
	// if node returned is not nullptr, then node is true parent
	retriever = *parent->dataPtr;
	return true;
}
// -----------------------------------------------------------------------------
// preorderSearch
// Takes two Node pointers and a NodeData obj for comparison, this function
// will search for the target and keep track of the prev Node as it searches
// returns a pointer to the prev Node once target is found, if not found it
// returns a nullptr
Node* BinTree::preorderSearch(Node* current, Node* prev,
	const NodeData& target) const {

	if (current != nullptr) {
		// check for target found
		if (*current->dataPtr == target)
			// if found, return prev as parent node
			return prev;
		// save parent node data
		prev = current;
		Node* temp; // temp node will capture node of preOrderSearch
		temp = preorderSearch(current->left, prev, target);
	// check for failed search attempt, which would result in nullptr
		if (temp != nullptr) {
			//parent found, need to return temp as parent
			return temp;
		}
		temp = preorderSearch(current->right, prev, target);
		if (temp != nullptr) {
			//parent found, need to return temp as parent
			return temp;
		}
	}
	return nullptr;
}
// -----------------------------------------------------------------------------
// bstreeToArray
// uses a Node stack to traverse tree in inorder transversal, then creates new
// NodeData objects of Node* contained in BinTree. Erases memory of tree after
void BinTree::bstreeToArray(NodeData* array[]) {
	stack<Node*> nodeStack;
	Node* current = root;
	int i = 0;
	bool done = false;
	while (!done) {
		if (current != nullptr) {
			nodeStack.push(current);
			current = current->left;
		}
		else {
			if (!nodeStack.empty()) {
				current = nodeStack.top();
				NodeData* temp = new NodeData(*current->dataPtr);
				array[i] = temp;
				i++;
				nodeStack.pop();
				current = current->right;
			}
			else {
				done = true;
			}
		}
	}
	this->makeEmpty();
}
// -----------------------------------------------------------------------------
// arrayToBSTree
// must be passed a sorted array, will create a balanced Tree of Nodes holding
// NodeData
void BinTree::arrayToBSTree(NodeData* array[]) {
	// check to see if array is empty
	if (array[0] == nullptr) {
		cout << "Array is empty. Try again.";
		return;
	}
	//get size of array, pass min & max values for balanced tree function
	int i = 0;
	while (array[i] != nullptr) {
		i++;
	}
	int min = 0;
	int max = i - 1;
	root = createBalancedTree(array, min, max);
	
	for (int j = 0; j < i; j++) {
		delete array[j];
	}
}

// -----------------------------------------------------------------------------
// createBalancedTree
// Recursive helper to create balanced tree, takes the array of NodeData*
// and the min & max size of the array. Assumes the array is already sorted.
Node* BinTree::createBalancedTree(NodeData* array[], int min, int max) {
	if (min > max) {
		return nullptr;
	}
	int midpoint = (min + max) / 2;
	Node* current = new Node (array[midpoint]);
	current->left = createBalancedTree(array, min, midpoint - 1);
	current->right = createBalancedTree(array, midpoint + 1, max);
	return current;
}
