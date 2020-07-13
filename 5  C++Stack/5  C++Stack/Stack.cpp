#include<iostream>

const int STACK_SIZE = 10;//尽量不用不安全的宏定义
template<typename T>
class Stack
{
public:
	Stack()
	{
		pst = new T[STACK_SIZE]();
		top = 0;
	}
	//释放对象所占的堆资源
	~Stack()
	{
		delete[] pst;
		pst = NULL;
	}
	void push(T val)
	{
		if (!full())
		{
			pst[top++] = val;
		}
	}
	void pop()
	{
		if (!empty())
		{
			top--;
		}
	}
	T gettop()
	{
		if (empty())
		{
			//抛出异常   异常处理机制
			throw std::exception("stack is empty!");
		}
		return pst[top - 1];
	}
	bool empty()
	{
		return top == 0;
	}
	bool full()
	{
		return top == STACK_SIZE;
	}
private:
	T* pst;//pst指向存储元素的数组
	int top;//栈顶指针  当前元素的个数 或 当前可插入的元素下标
};

int main()
{
	Stack<int> st;
	for (int i = 0; i < 5; i++)
	{
		st.push(i + 1);
	}
	int top = st.gettop();
	std::cout << top << std::endl;
	st.pop();
	return 0;
}
