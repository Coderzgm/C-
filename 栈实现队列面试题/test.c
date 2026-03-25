#include<stdio.h>
#include<stdbool.h>
typedef struct Node
{
	int          val; //数值
	struct Node* next;//后继
}Node;

//232.栈
typedef struct Stack
{
	Node* top;
}Stack;

//232.创建栈
Stack* stackCreate()
{
	//分配内存
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack == NULL)
		return NULL;

	//初始化
	stack->top = NULL;
	return stack;
}

//232.销毁栈
void stackFree(Stack** stack)
{
	//参数检测
	if (stack == NULL || *stack == NULL)
		return;

	//销毁
	Node* temp = (*stack)->top;
	while (temp != NULL)
	{
		Node* current = temp;
		temp = temp->next;
		free(current);
	}
	(*stack)->top = NULL;
	free(*stack);
	*stack = NULL;
}

//232.判空
bool empty(Stack* stack)
{
	//参数检测
	if (stack == NULL)
		return false;

	return stack->top == NULL;
}

//232.入栈
void push(Stack* stack, int val)
{
	//参数检测
	if (stack == NULL)
		return;

	//分配节点内存
	Node* node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
		return;

	//头插
	node->val = val;
	node->next = stack->top;
	stack->top = node;
}

//232.出栈
int pop(Stack* stack)
{
	//参数检测
	if (stack == NULL)
		return 0;

	//栈顶指针移动，销毁内存
	Node* temp = stack->top;
	stack->top = stack->top->next;
	int result = temp->val;
	free(temp);
	return result;
}

//232.获取栈顶元素
int top(Stack* stack)
{
	//参数检测
	if (stack == NULL || stack->top == NULL)
		return 0;

	return stack->top->val;
}

//232.队
typedef struct
{
	Stack* inStack; //入队栈
	Stack* outStack;//出队栈
}MyQueue;

//232.创建队
MyQueue* myQueueCreate()
{
	//分配内存
	MyQueue* myQueue = (MyQueue*)malloc(sizeof(MyQueue));
	if (myQueue == NULL)
		return NULL;

	//初始化
	myQueue->inStack = stackCreate();
	if (myQueue->inStack == NULL)
	{
		free(myQueue);
		return NULL;
	}
	myQueue->outStack = stackCreate();
	if (myQueue->outStack == NULL)
	{
		free(myQueue->inStack);
		free(myQueue);
		return NULL;
	}
	return myQueue;
}

//232.销毁队
void myQueueFree(MyQueue* obj)
{
	//参数检测
	if (obj == NULL)
		return;

	//销毁
	stackFree(&obj->inStack);
	stackFree(&obj->outStack);
	free(obj);
}

//232.判空
bool myQueueEmpty(MyQueue* obj)
{
	//参数检测
	if (obj == NULL)
		return false;

	return empty(obj->inStack) && empty(obj->outStack);
}

//232.入队
void myQueuePush(MyQueue* obj, int x)
{
	//参数检测
	if (obj == NULL)
		return;

	//入队
	push(obj->inStack, x);
}

//232.出队
int myQueuePop(MyQueue* obj)
{
	//参数检测
	if (obj == NULL)
		return 0;

	//判空
	if (myQueueEmpty(obj))
		return 0;

	//出队栈为空，从入队栈出，从入队栈入
	if (empty(obj->outStack))
	{
		int temp = 0;
		while (!empty(obj->inStack))
		{
			temp = pop(obj->inStack);
			push(obj->outStack, temp);
		}
	}

	//出队
	return pop(obj->outStack);
}

//232.获取队首元素
int myQueuePeek(MyQueue* obj)
{
	//参数检测
	if (obj == NULL)
		return 0;

	//判空
	if (myQueueEmpty(obj))
		return 0;

	//出队栈为空，从入队栈出，从入队栈入
	if (empty(obj->outStack))
	{
		int temp = 0;
		while (!empty(obj->inStack))
		{
			temp = pop(obj->inStack);
			push(obj->outStack, temp);
		}
	}

	//查看队首元素
	return top(obj->outStack);
}