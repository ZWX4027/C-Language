#include<iostream>

const int STACK_SIZE = 10;//�������ò���ȫ�ĺ궨��
template<typename T>
class Stack
{
public:
	Stack()
	{
		pst = new T[STACK_SIZE]();
		top = 0;
	}
	//�ͷŶ�����ռ�Ķ���Դ
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
			//�׳��쳣   �쳣�������
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
	T* pst;//pstָ��洢Ԫ�ص�����
	int top;//ջ��ָ��  ��ǰԪ�صĸ��� �� ��ǰ�ɲ����Ԫ���±�
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
