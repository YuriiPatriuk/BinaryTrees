#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include "Date.h"
using namespace std;

class DB
{
public:
	void addCar(const double& data);
	bool empty() const;
	bool findBool(const double& search);

private:
	struct Node
	{
	private:
		class Violation
		{
		private:
			string name;
			Date date;
			float sum;
		};
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
	void add(const double& data);
	Node& find(const double& search);
};

inline void DB::addCar(const double& data)
{
	if (!findBool(data))
		add(data);
	else
	{

	}
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

inline void DB::add(const double& data)
{
	Node* addNode = new Node(data);
	if (empty()) {
		root = addNode;
		return;
	}
	//empty = false
	bool found = false;
	Node* temp = root;
	while (!found)
	{
		if (data >= temp->key) // new node will be right
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

inline DB::Node& DB::find(const double& search)
{
	Node r(0);
	if (empty())
		return;
	Node* temp = root;
	while (temp != nullptr)
	{
		if (temp->key == search)
			return *temp;
		else if (temp->key < search)
			temp = temp->right;
		else if (temp->key > search)
			temp = temp->left;
	}
	return r;
}
