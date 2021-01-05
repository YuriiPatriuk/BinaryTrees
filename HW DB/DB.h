#pragma once
#include "Date.h"
#include "Violation.h"
using namespace std;

class DB
{
public:
	void addCar(const double& data, const Violation& vi);
	bool empty() const;
	bool findBool(const double& search);
	void print() const;
private:
	struct Node
	{
	public:
		Node() = default;
		Node(const double& data = 0, Node* left = nullptr, Node* right = nullptr, Node* parent = nullptr)
			:key(data), left(left), right(right), parent(parent)
		{}
		double key;
		vector<Violation> list;
		Node* left, * right, * parent;
	};
	Node* root = nullptr;
	void add(const double& data, const Violation& vi);
	void change(const double& search, const Violation& vi);
	void printHelper(/*BinaryTree<T>::*/Node* node) const;
};

inline void DB::addCar(const double& data, const Violation& vi)
{
	if (findBool(data)==false)
		add(data,vi);
	else
		change(data, vi);
}

inline bool DB::findBool(const double& search)
{
	if (empty())
		return false;
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->key == search)
			return true;
		else if (temp->key < search)
			temp = temp->right;
		else if (temp->key > search)
			temp = temp->left;
	}
	return false;
}

inline bool DB::empty() const
{
	return root == nullptr;
}

inline void DB::add(const double& data, const Violation& vi)
{
	Node* addNode = new Node(data);
	addNode->list.push_back(vi);
	if (empty()) {
		root = addNode;
		return;
	}
	//empty = false
	bool found = false;
	Node* temp = root;
	while (!found)
	{
		if (data > temp->key) // new node will be right
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

inline void DB::change(const double& search, const Violation& vi)
{
	if (empty())
		return;
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->key == search)
		{
			temp->list.push_back(vi);
			break;
		}
		else if (temp->key < search)
			temp = temp->right;
		else if (temp->key > search)
			temp = temp->left;
	}

}

inline void DB::print() const
{
	cout <<"-------------------------------"<< "\n\tDB: " << endl;
	printHelper(root);
	cout << "-------------------------------" << endl;
}

inline void DB::printHelper(Node* node) const
{
	if (node != nullptr)
	{
		int count = 0;
		printHelper(node->left);
		cout <<"Car:"<< node->key << endl;
		for (auto& i : node->list)
		{
			++count;
			cout << "#" << count << endl;
			i.print();

		}
		cout << endl;
		printHelper(node->right);
	}
}
