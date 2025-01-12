#include "BSNode.h"
BSNode::BSNode(std::string data) : _data(data), _left(nullptr), _right(nullptr), _count(1)
{
}

BSNode::BSNode(const BSNode& other) {
	_data = other._data;
	_left = nullptr;
	_right = nullptr;

	if (other._left != nullptr)
	{
		_left = new BSNode(*other._left);
	}
	if (other._right != nullptr)
	{
		_right = new BSNode(*other._right);
	}

}

BSNode::~BSNode() {
	//Recursive deletion
	if (_left != nullptr) {
		delete _left; // will call the d'tor of left son
	}
	if (_right != nullptr)
	{
		delete _right; // will call thr d'tor of right son
	}
}
void BSNode::insert(const std::string value) {
	// check where should insert the node - right or left
	if (value < this->_data)
	{
		if (_left != nullptr) // if there is already left son
		{
			_left->insert(value);// recursive call on the left son
		}
		else
		{
			_left = new BSNode(value); // add the node as left son
		}
	}
	else if (value > this->_data)
	{
		if (_right != nullptr) // if there is already right son
		{
			_right->insert(value); // recursive call on the right son
		}
		else
		{
			_right = new BSNode(value); // add the node as right son
		}
	}
	else // value == this->data
	{
		this->_count++;
	}

}