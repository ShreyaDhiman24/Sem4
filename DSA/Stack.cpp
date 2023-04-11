// C++ Program to implement stack having push,pop,peep and display functions, and then finding infix to postfix, evaluate postfix.
#include <bits/stdc++.h>
using namespace std;

class StackNode
{
public:
	int data;
	StackNode *next;

	StackNode(int data)
	{ // constructor
		this->data = data;
		this->next = nullptr;
	}
};

class Stack
{
private:
	StackNode *top; // top node of stack

public:
	Stack()
	{				   // constructor
		top = nullptr; // initialize top node to null
	}

	bool isEmpty()
	{ // check if stack is empty
		return top == nullptr;
	}

	void push(int element)
	{												 // push element onto stack
		StackNode *newNode = new StackNode(element); // create new node
		newNode->next = top;						 // set next of new node to current top node
		top = newNode;								 // set top to new node
		cout << "Pushed element: " << element << endl;
	}

	int pop()
	{ // pop element from stack
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return -1;
		}
		int poppedElement = top->data; // store data of top node
		StackNode *temp = top;		   // store top node temporarily
		top = top->next;			   // set top to next node
		delete (temp);				   // delete temporary node
		cout << "Popped element: " << poppedElement << endl;
		return poppedElement;
	}

	int peek()
	{ // peek at top element of stack
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return -1;
		}
		int topElement = top->data; // store data of top node
		cout << "Top element: " << topElement << endl;
		return topElement;
	}

	void display()
	{ // display elements of stack
		if (isEmpty())
		{
			cout << "Stack is empty!" << endl;
			return;
		}
		cout << "Stack elements: ";
		StackNode *currentNode = top; // start from top node
		while (currentNode != nullptr)
		{ // traverse the stack
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << endl;
	}
};
bool isOperator(char c);
int getPrecedence(char c);
string infixToPostfix(string infix);
int calculate_Postfix(string post_exp);

int main()
{
	Stack stack; // create stack object

	stack.push(10);
	stack.push(20);
	stack.push(30);
	stack.display();
	stack.peek();
	stack.pop();
	stack.display();

	string infix = "5*(6+2)-(12/4)";
	string postfix = infixToPostfix(infix);
	cout << "Infix expression: " << infix << endl;
	cout << "Postfix expression: " << postfix << endl;

	int result = calculate_Postfix("562+*124/-");
	cout << "Result: " << result << endl;

	return 0;
}

// Function to check if a character is an operator
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
	{
		return true;
	}
	return false;
}

// Function to get the precedence of an operator
int getPrecedence(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	return 0;
}

// Function to convert infix to postfix
string infixToPostfix(string infix)
{
	stack<char> s;
	string postfix = "";

	for (int i = 0; i < infix.length(); i++)
	{
		// If the character =operand, add it to the postfix string
		if (isalpha(infix[i]) || isdigit(infix[i]))
		{
			postfix += infix[i];
		}
		// If the character = operator
		else if (isOperator(infix[i]))
		{
			while (!s.empty() && s.top() != '(' && getPrecedence(s.top()) >= getPrecedence(infix[i]))
			{
				postfix += s.top();
				s.pop();
			}
			s.push(infix[i]);
		}
		// If the character=open parenthesis, push it to the stack
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		// If the character = right parenthesis, pop the stack and add operators to the postfix string until a left parenthesis is found
		else if (infix[i] == ')')
		{
			while (!s.empty() && s.top() != '(')
			{
				postfix += s.top();
				s.pop();
			}
			if (!s.empty() && s.top() == '(')
			{
				s.pop();
			}
		}
	}

	// Add any remaining operators in the stack to the postfix string
	while (!s.empty())
	{
		postfix += s.top();
		s.pop();
	}

	return postfix;
}
// Function to evaluate postfix expression
int calculate_Postfix(string post_exp)
{
	stack<int> stack;
	int len = post_exp.length();
	// loop to iterate through the expression
	for (int i = 0; i < len; i++)
	{
		// if the character is an operand we push it in the stack we have considered single digits only here
		if (post_exp[i] >= '0' && post_exp[i] <= '9')
		{
			stack.push(post_exp[i] - '0');
		}
		// if the character is an operator we enter else block
		else
		{
			// we pop the top two elements from the stack and save them in two integers
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			// performing the operation on the operands
			switch (post_exp[i])
			{
			case '+': // addition
				stack.push(b + a);
				break;
			case '-': // subtraction
				stack.push(b - a);
				break;
			case '*': // multiplication
				stack.push(b * a);
				break;
			case '/': // division
				stack.push(b / a);
				break;
			case '^': // exponent
				stack.push(pow(b, a));
				break;
			}
		}
	}
	// returning the calculated result
	return stack.top();
}
