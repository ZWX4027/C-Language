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
	//解引用运算符重载 
	T& operator*()
	{
		return *mptr;
	}
	//指向运算符重载（应该理解为单目运算符） 
	T* operator->()
	{
		return mptr;
	}
private:
	T* mptr;//指向堆内存 
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

	SmartPtr<int> sp = new int;//在栈上生成一个sp（由系统判断生存周期，调用析构系统销毁） 
	*sp = 30;//面向对象的指针 
	SmartPtr<Test> sp2 = new Test(40);
	sp2->Show(); //sp2.operator->() ==> (Test*) 
	return 0;
}