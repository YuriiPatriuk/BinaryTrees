#pragma once
#include <iostream>
using namespace std;
template <typename T>
class BinaryTree
{
public:
	BinaryTree() = default;
	void print() const;
	void add(const T& data);
	void clear();
	~BinaryTree();
	const T& max() const;
	const T& min() const;
	bool find(const T& search);
	//void printBigger(const T& data);
	bool empty() const;
	const size_t getSize() const;

private:
	struct Node 
	{
		T data;
		Node* left, * right, *parent;
		Node(const T& data = T(), Node* left = nullptr, Node* right = nullptr, Node* parent=nullptr)
			:data(data), left(left), right(right), parent(parent)
		{}
	};

	Node* root = nullptr;
	size_t size = 0;

	void printHelper(/*BinaryTree<T>::*/Node * node) const;
	//void printBigger(Node* node,const T& data);
	void clear(Node* node);

};

template<typename T>
inline void BinaryTree<T>::print() const
{
	cout << "Tree: ";
	printHelper(root);
	cout << endl;
}

template<typename T>
inline void BinaryTree<T>::add(const T& data)
{
	Node* addNode = new Node(data);
	++size;
	if (empty()) {
		root = addNode;
		return;
	}
	//empty = false
	bool found = false;
	Node* temp = root;
	while (!found)
	{
		if (data >= temp->data) // new node will be right
		{
			if (temp->right == nullptr) // free place
			{
				temp->right = addNode;
				addNode->parent = temp;
				found = true;
			}
			else
				temp = temp->right;
		}
		else // new node will be left
		{
			if (temp->left == nullptr) // free place
			{
				temp->left = addNode;
				addNode->parent = temp;
				found = true;
			}
			else
				temp = temp->left;
		}
	}
}

template<typename T>
inline void BinaryTree<T>::clear()
{
	clear(root);
	root = nullptr;
	size = 0;
}

template<typename T>
inline BinaryTree<T>::~BinaryTree()
{
	clear();
}

template<typename T>
inline void BinaryTree<T>::clear(Node* node)
{
	if (node != nullptr)
	{
		clear(node->left);
		clear(node->right);
		cout << "~~~~~Delete " << node->data << "~~~~~~~~" << endl;
		delete node;
	}
}

template<typename T>
inline bool BinaryTree<T>::empty() const
{
	return root == nullptr;
}

template<typename T>
inline const size_t BinaryTree<T>::getSize() const
{
	return size;
}

template<typename T>
inline void BinaryTree<T>::printHelper(/*BinaryTree<T>::*/Node* node) const
{
	if (node != nullptr)
	{
		printHelper(node->left);
		cout << node->data << " ";
		printHelper(node->right);
	}
}

template<typename T>
inline const T& BinaryTree<T>::max() const
{
	Node* res = root;
	if (size == 0)
	{
		cerr << "No element!" << endl;
		return T();
	}
	while (res->right != nullptr) {
		res = res->right;
	}
	return res->data;
}

template<typename T>
inline const T& BinaryTree<T>::min() const
{
	Node* res = root;
	if (size == 0 )
	{
		cerr << "No element!" << endl;
		return T();
	}
	while (res->left != nullptr) {
		res = res->left;
	}
	return res->data;
}

template<typename T>
inline bool BinaryTree<T>::find(const T& search)
{
	if (empty())
		return false;
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->data == search)
			return true;
		else if (temp->data < search)
			temp = temp->right;
		else if (temp->data > search)
			temp = temp->left;
	}
	return false;
}

//template<typename T>
//inline void BinaryTree<T>::printBigger(const T& search)
//{
//	if (empty())
//		return;
//	cout << "Bigger than " << search << ": ";
//	printHelper(root,search);
//	cout << endl;
//	
//}
//
//template<typename T>
//inline void BinaryTree<T>::printBigger(Node* node, const T& search)
//{
//	if (node != nullptr)
//	{
//		if(node->left >= search)
//			printBigger(node->left, search)
//	}
//}
