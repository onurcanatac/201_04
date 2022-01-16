//Onurcan Ataç, 22002194
#ifndef STACK_H
#define STACK_H

#include <string>

typedef std::string type;

//template <typename type>

class Stack {

public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();

    bool isEmpty() const;
    bool push(type newItem);
    bool pop();
    bool pop(type& stackTop);
    bool getTop(type& stackTop) const;
    
    //extra implemented
    std::string printStack() const;
    //bool getTop(type*& stackTop) const;

private:
    struct StackNode {            // a node on the stack
        type item;        // a data item on the stack
        StackNode* next;        // pointer to next node
    };

    StackNode* topPtr;     // pointer to first node in the stack
};

#endif

