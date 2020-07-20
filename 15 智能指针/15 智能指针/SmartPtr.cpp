#include<iostream>

template<typename T>
class SmartPtr
{
public:
	SmartPtr(T* ptr)
		:mptr(ptr)
	{}
	~SmartPtr()
	{
		delete[] mptr;
	}
	//��������������� 
	T& operator*()
	{
		return *mptr;
	}
	//ָ����������أ�Ӧ�����Ϊ��Ŀ������� 
	T* operator->()
	{
		return mptr;
	}
private:
	T* mptr;//ָ����ڴ� 
};
class Test
{
public:
	Test(int a) :ma(a){}
	void Show()
	{
		std::cout << "ma:" << ma << std::endl;
	}
private:
	int ma;
};


int main()
{
	int* p = new int;
	*p = 20;
	Test* ptest = new Test(10);
	ptest->Show();

	SmartPtr<int> sp = new int;//��ջ������һ��sp����ϵͳ�ж��������ڣ���������ϵͳ���٣� 
	*sp = 30;//��������ָ�� 
	SmartPtr<Test> sp2 = new Test(40);
	sp2->Show(); //sp2.operator->() ==> (Test*) 
	return 0;
}