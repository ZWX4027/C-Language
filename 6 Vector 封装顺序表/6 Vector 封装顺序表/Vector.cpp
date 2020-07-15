#include<iostream>

template<typename T>
class Vector
{
public:
	Vector(int size = 2)
	{
		parr = new T[size]();//动态开辟空间
		cursize = 0;
		totalsize = size;
	}
	template<typename U>
	friend class Vector;//（一对多的友元关系）模板的友元：任意用来实例化T类型生成的模板类是任意用U类型类实例化的模板类的朋友

	//模板的重载——模板和普通函数版本
	//拷贝构造函数退化成构造函数
	template<typename E>
	Vector(const Vector<E>& rhs)
	{
		parr = new T[rhs.totalsize]();
		for (int i = 0; i < totalsize; i++)
		{
			parr[i] = rhs.parr[i];
		}
		cursize = rhs.cursize;
		totalsize = rhs.totalsize;
	}

	////拷贝构造函数
	//Vector(const Vector<T>& rhs)
	//{
	//	parr = new T[rhs.totalsize]();//把旧的对象中的元素放在新的对象中
	//	memcpy(parr, rhs.parr, sizeof(T)*totalsize);
	//	cursize = rhs.cursize;
	//	totalsize = rhs.totalsize;
	//}

	~Vector()
	{
		delete[] parr;
		parr = NULL;
	}

	//扩容
	void resize()
	{
		T* tmp = new T[totalsize * 2]();//以2倍的形式扩容
		memcpy(tmp, parr, sizeof(T)*totalsize);//旧的数据拷贝到新的空间
		delete[] parr;//释放旧空间
		parr = tmp;//指针指向新空间
		totalsize *= 2;//调整新空间的总大小
	}

	//尾部插入
	void push_back(T val)//cursize
	{
		//第一种方式
	  /*if (full())
		{
			resize();
		}
		parr[cursize++] = val;*/
		//第二种方式
		insert(cursize, val);
	}

	//按位置插入
	void insert(int pos, T val)
	{
		if (pos < 0 || pos > cursize)//插入的位置不合理
		{
			return;
		}
		if (full())//空间满了
		{
			resize();
		}
		for (int i = cursize; i > pos; i--)
		{
			parr[i] = parr[i - 1];
		}
		parr[pos] = val;
		cursize++;
	}

	//尾删
	void pop_back()
	{
		erase(cursize - 1);
	}

	//按位置删除
	void erase(int pos)
	{
		if (pos < 0 || pos >= cursize)
		{
			return;
		}
		for (int i = pos; i < cursize - 1; i++)
		{
			parr[i] = parr[i + 1];
		}
		cursize--;
	}

	void Show()
	{
		for (int i = 0; i < cursize; i++)
		{
			std::cout << parr[i] << " ";
		}
		std::cout << std::endl;
	}

	//判空
	bool empty()
	{
		return cursize == 0;
	}
private:
	bool full()
	{
		return cursize == totalsize;
	}
	T* parr;//只想存储数据的空间
	int cursize;//当前有效元素的个数  
	//当前数组中可插入元素的下标
	int totalsize;//当前的元素总容量
};
#if 0
int main()
{
	Vector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i + 1);
	}
	vec.Show();
	vec.pop_back();
	vec.Show();
	return 0;
}
#endif

//用来测试构造函数和拷贝构造函数
int main()
{
	Vector<int> ivec;
	for (int i = 0; i < 5; i++)
	{
		ivec.push_back(i + 1);
	}
	Vector<double> dvec = ivec;//用已存在的对象生成新对象，调用拷贝构造函数
	Vector<int> ivec2 = ivec;
	/*拷贝构造函数退化成构造函数，所以现在没有拷贝构造函数，所以系统会提供一个拷贝构造函数（浅拷贝），
	使两个指针指向同一个堆内存，当ivec2生成时把内存释放，而ivec又会释放，重复释放内存导致程序崩溃*/
	return 0;
}
