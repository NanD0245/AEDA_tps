# include <iostream>
# include <stack>

using namespace std;

template <class T>
class StackExt {
    stack<T> stack1;
    stack<T> stack_min;
public:
	StackExt() {};
	bool empty() const; 
	T &top();
	void pop();
	void push(const T & val);
	T &findMin();
};

// a alterar
template <class T> 
bool StackExt<T>::empty() const
{
	return stack1.empty();
}

//a alterar
template <class T> 
T& StackExt<T>::top()
{
    T *novo = new T();
    *novo = stack1.top();
    return *novo;
}

//a alterar
template <class T> 
void StackExt<T>::pop()
{
    if (stack1.top() == stack_min.top()) {
        stack_min.pop();
    }
    stack1.pop();
}

//a alterar
template <class T> 
void StackExt<T>::push(const T & val)
{
    if (stack_min.empty() || val <= stack_min.top()) {
        stack_min.push(val);
    }
    stack1.push(val);
}

//a alterar
template <class T> 
T& StackExt<T>::findMin()
{
    T *novo = new T();
    *novo = stack_min.top();
    return *novo;
}

