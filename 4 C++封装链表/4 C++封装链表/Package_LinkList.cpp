#include<iostream>

//对模板CLink进行前置声明 
template<typename T>
class CLink;

template<typename T>
class Node//模板名    ==>    Node<T>
{
public:
	Node(T val = T())//零初始化 ——》零构造
		:mdata(val), pnext(NULL)
	{}
private:
	T mdata;//数据域
	Node<T>* pnext;//指针域
	friend class CLink<T>;//友元函数：因为数据域和指针域是在Node类模板中定义的，如果在CLink中使用就要加上友元函数
};

template<typename T>
class CLink//链表 CLink 模板名称
{
public:
	CLink()
	{
		phead = new Node<T>();
	}
	~CLink();
	void insertHead(T val);
	void insertTail(T val);
	bool empty();
	void deleteHead();
	void deleteTail();
	void Show();

private:
	Node<T>* phead;//头指针 
};

//类作用域
template<typename T>
CLink<T>::~CLink()
{
	Node<T>* pCur = phead;
	Node<T>* pNext;
	while (pCur != NULL)
	{
		pNext = pCur->pnext;
		delete pCur;
		pCur = pNext;
	}
	phead = NULL;
}

template<typename T>
void CLink<T>::insertHead(T val)
{
	Node<T>* pnewnode = new Node<T>(val);//新结点

	pnewnode->pnext = phead->pnext;
	phead->pnext = pnewnode;
}

template<typename T>
void CLink<T>::insertTail(T val)
{
	Node<T>* pnewnode = new Node<T>(val);
	Node<T>* ptail = phead;
	while (ptail->pnext != NULL)
	{
		ptail = ptail->pnext;
	}

	ptail->pnext = pnewnode;
}

template<typename T>
bool CLink<T>::empty()
{
	return phead->pnext == NULL;
}

template<typename T>
void CLink<T>::deleteHead()
{
	if (!empty())
	{
		Node<T>* pCur = phead->pnext;//pCur指向第一个数据结点
		phead->pnext = pCur->pnext;

		delete pCur;
	}
}
/*
类模板的选择性实例化
   ：用到哪个函数实例化哪个函数
*/
template<typename T>
void CLink<T>::deleteTail()
{
	if (!empty())
	{
		Node<T>* ptail2 = phead;//倒数第二个
		Node<T>* ptail = ptail2->pnext;//倒数第一个

		while (ptail->pnext != NULL)
		{
			ptail2 = ptail2->pnext;
			ptail = ptail2->pnext;
		}

		ptail2->pnext = NULL;
		delete ptail;

		/*一个变量的方法
		Node<T>* ptail2 = phead;//ptail2最终要指向倒数第二个结点
		while (ptail2->pnext != NULL)
		{
			if (ptail2->pnext->pnext == NULL)
			{
				break;
			}
			ptail2 = ptail2->pnext;
		}

		delete ptail2->pnext;
		ptail2->pnext = NULL;*/
	}
}
template<typename T>
void CLink<T>::Show()
{
	Node<T>* pCur = phead->pnext;//数据结点
	while (pCur != NULL)
	{
		std::cout << pCur->mdata << " ";
		pCur = pCur->pnext;
	}
	std::cout << std::endl;
}
/*
class CLink<int>
*/
int main()
{
	CLink<int> cl;
	for (int i = 0; i < 5; i++)
	{
		cl.insertHead(i + 1);
	}
	for (int i = 0; i < 5; i++)
	{
		cl.insertTail(i + 1);
	}
	cl.Show();
	cl.deleteHead();
	cl.deleteTail();
	cl.Show();
	return 0;
}