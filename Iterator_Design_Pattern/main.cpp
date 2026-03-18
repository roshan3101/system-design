#include <bits/stdc++.h>
using namespace std;

template<typename T>
class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual T next() = 0;
	virtual ~Iterator() = default;
};

template<typename T>
class Iterable
{
public:
	virtual Iterator<T>* createIterator() = 0;
	virtual ~Iterable() = default;
};

class LinkedList : public Iterable<int>
{
	private:
		int data;
		LinkedList* next;
	public:
		LinkedList(int value) : data(value), next(nullptr) {}
		Iterator<int>* createIterator() override;
		int getData() { return data; }
		LinkedList* getNext() { return next; }
		void setNext(LinkedList* node) { next = node; }
};

class BinaryTree : public Iterable<int>
{
	private:
		int data;
		BinaryTree* left;
		BinaryTree* right;
	public:
		BinaryTree(int value) : data(value), left(nullptr), right(nullptr) {}
		Iterator<int>* createIterator() override;
		int getData() { return data; }
		BinaryTree* getLeft() { return left; }
		BinaryTree* getRight() { return right; }
		void setLeft(BinaryTree* node) { left = node; }
		void setRight(BinaryTree* node) { right = node; }
};

class LinkedListIterator : public Iterator<int>
{
	private:
		LinkedList* current;
	public:
		LinkedListIterator(LinkedList* head) : current(head) {}
		bool hasNext() override {
			return current != nullptr;
		}
		int next() override {
			int value = current->getData();
			current = current->getNext();
			return value;
		}
};

class BinaryTreeIterator : public Iterator<int>
{
	private:
		stack<BinaryTree*> nodeStack;
	public:
		BinaryTreeIterator(BinaryTree* root) {
			if (root) {
				nodeStack.push(root);
			}
		}
		bool hasNext() override {
			return !nodeStack.empty();
		}
		int next() override {
			BinaryTree* node = nodeStack.top();
			nodeStack.pop();
			int value = node->getData();
			if (node->getRight()) {
				nodeStack.push(node->getRight());
			}
			if (node->getLeft()) {
				nodeStack.push(node->getLeft());
			}
			return value;
		}
};

Iterator<int>* LinkedList::createIterator() {
	return new LinkedListIterator(this);
}

Iterator<int>* BinaryTree::createIterator() {
	return new BinaryTreeIterator(this);
}

int main() {
	LinkedList* head = new LinkedList(1);
	head->setNext(new LinkedList(2));
	head->getNext()->setNext(new LinkedList(3));
	
	Iterator<int>* listIterator = head->createIterator();
	cout << "Linked List: ";
	while (listIterator->hasNext()) {
		cout << listIterator->next() << " ";
	}
	cout << endl;
	delete listIterator;
	
	BinaryTree* root = new BinaryTree(1);
	root->setLeft(new BinaryTree(2));
	root->setRight(new BinaryTree(3));
	
	Iterator<int>* treeIterator = root->createIterator();
	cout << "Binary Tree: ";
	while (treeIterator->hasNext()) {
		cout << treeIterator->next() << " ";
	}
	cout << endl;
	delete treeIterator;
	
	delete head->getNext()->getNext();
	delete head->getNext();
	delete head;
	
	delete root->getLeft();
	delete root->getRight();
	delete root;
	
	return 0;
}
