//Onurcan Ataç, 22002194
#include "Stack.h"

// default constructor
//template<typename type>
Stack::Stack() 
{
	topPtr = NULL;
}

//template <typename type>
Stack::Stack(const Stack& aStack)
{
	if (aStack.topPtr == NULL)
	{
		this->topPtr = NULL;
	}
	else
	{
		this->topPtr = new StackNode;
		(this->topPtr)->item = (aStack.topPtr)->item;

		StackNode* newPointer = this->topPtr;

		for (StackNode* originalPointer = (aStack.topPtr)->next; originalPointer != NULL; originalPointer = originalPointer->next)
		{
			newPointer->next = new StackNode;
			newPointer = newPointer->next;
			newPointer->item = originalPointer->item;
		}
		newPointer->next = NULL;
	}
}

//template<typename type>
Stack::~Stack()
{
	while (!isEmpty())
	{
		pop();
	}
}

//template<typename type>
bool Stack::isEmpty() const
{
	return (topPtr == NULL);
}

//template<typename type>
bool Stack::push(type newItem)
{
	StackNode* newPointer = new StackNode;
	newPointer->item = newItem;
	newPointer->next = this->topPtr;
	this->topPtr = newPointer;

	return 1;
}

//template<typename type>
bool Stack::pop()
{
	StackNode* temp;
	temp = topPtr;
	topPtr = topPtr->next;
	delete temp;

	return 1;
}

bool Stack::getTop(type& stackTop) const
{
	stackTop = topPtr->item;

	return 1;
}

bool Stack::pop(type& stackTop)
{
	getTop(stackTop);
	pop();

	return 1;
}

std::string Stack::printStack() const
{
	std::string descriptionString = "Stack: ";

	if (this->topPtr == NULL)
	{
		descriptionString += "Empty";
	}
	else
	{
		StackNode* current;
		current = this->topPtr;

		while (current != NULL)
		{
			descriptionString += current->item;
			if (current->next != NULL)
			{
				descriptionString += ", ";
			}
			current = current->next;
		}
	}
	return descriptionString;
}


