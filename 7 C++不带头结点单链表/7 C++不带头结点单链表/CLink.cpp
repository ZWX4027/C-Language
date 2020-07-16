#include<iostream>


template<typename T>
class CLink//模板
{
public:
	CLink()
	{
		phead = NULL;
	}
	~CLink()
	{
		Node* pCur = phead;
		Node* pNext;
		while (pCur != NULL)
		{
			pNext = pCur->pnext;
			delete pCur;
			pCur = pNext;
		}
		phead = NULL;
	}
	void insertHead(T val)
	{
		Node* pnewnode = new Node(val);

		pnewnode->pnext = phead;
		phead = pnewnode;
	}
	void insertTail(T val)
	{
		Node* pnewnode = new Node(val);
		if (phead == NULL)
		{
			phead = pnewnode;
		}
		else
		{
			Node* ptail = phead;
			while (ptail->pnext != NULL)
			{
				ptail = ptail->pnext;
			}
			ptail->pnext = pnewnode;
		}
	}
	void Show()
	{
		Node* pCur = phead;
		while (pCur != NULL)
		{
			std::cout << pCur->mdata << " ";
			pCur = pCur->pnext;
		}
		std::cout << std::endl;
	}
	//查询函数  返回查询到的第一个数组当前的结点位置
	class Node;
	Node* find(T val);//Node 

private:
	class Node//类
	{
	public:
		Node(T val = T())
			:mdata(val), pnext(NULL)
		{}
	public://任意位置
		T mdata;
		Node* pnext;
	};
	Node* phead;//phead  头指针
};

template<typename T>
typename CLink<T>::Node* CLink<T>::find(T val)
{
	Node* pCur = phead;
	while (pCur != NULL)
	{
		if (pCur->mdata == val)
		{
			return pCur;
		}
		pCur = pCur->pnext;
	}
	return NULL;
};
int main()
{
	CLink<int> cl;
	for (int i = 0; i < 5; i++)
	{
		cl.insertHead(i + 1);
	}
	cl.Show();
	for (int i = 0; i < 5; i++)
	{
		cl.insertTail(i + 1);
	}
	cl.Show();
	auto rt = cl.find(3);
	return 0;
}


