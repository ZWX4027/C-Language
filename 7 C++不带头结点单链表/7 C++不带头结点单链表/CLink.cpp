#include<iostream>


template<typename T>
class CLink//ģ��
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
	//��ѯ����  ���ز�ѯ���ĵ�һ�����鵱ǰ�Ľ��λ��
	class Node;
	Node* find(T val);//Node 

private:
	class Node//��
	{
	public:
		Node(T val = T())
			:mdata(val), pnext(NULL)
		{}
	public://����λ��
		T mdata;
		Node* pnext;
	};
	Node* phead;//phead  ͷָ��
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


