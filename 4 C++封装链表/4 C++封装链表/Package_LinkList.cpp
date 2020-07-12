#include<iostream>

//��ģ��CLink����ǰ������ 
template<typename T>
class CLink;

template<typename T>
class Node//ģ����    ==>    Node<T>
{
public:
	Node(T val = T())//���ʼ�� �������㹹��
		:mdata(val), pnext(NULL)
	{}
private:
	T mdata;//������
	Node<T>* pnext;//ָ����
	friend class CLink<T>;//��Ԫ��������Ϊ�������ָ��������Node��ģ���ж���ģ������CLink��ʹ�þ�Ҫ������Ԫ����
};

template<typename T>
class CLink//���� CLink ģ������
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
	Node<T>* phead;//ͷָ�� 
};

//��������
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
	Node<T>* pnewnode = new Node<T>(val);//�½��

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
		Node<T>* pCur = phead->pnext;//pCurָ���һ�����ݽ��
		phead->pnext = pCur->pnext;

		delete pCur;
	}
}
/*
��ģ���ѡ����ʵ����
   ���õ��ĸ�����ʵ�����ĸ�����
*/
template<typename T>
void CLink<T>::deleteTail()
{
	if (!empty())
	{
		Node<T>* ptail2 = phead;//�����ڶ���
		Node<T>* ptail = ptail2->pnext;//������һ��

		while (ptail->pnext != NULL)
		{
			ptail2 = ptail2->pnext;
			ptail = ptail2->pnext;
		}

		ptail2->pnext = NULL;
		delete ptail;

		/*һ�������ķ���
		Node<T>* ptail2 = phead;//ptail2����Ҫָ�����ڶ������
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
	Node<T>* pCur = phead->pnext;//���ݽ��
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