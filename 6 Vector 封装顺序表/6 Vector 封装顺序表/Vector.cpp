#include<iostream>

template<typename T>
class Vector
{
public:
	Vector(int size = 2)
	{
		parr = new T[size]();//��̬���ٿռ�
		cursize = 0;
		totalsize = size;
	}
	template<typename U>
	friend class Vector;//��һ�Զ����Ԫ��ϵ��ģ�����Ԫ����������ʵ����T�������ɵ�ģ������������U������ʵ������ģ���������

	//ģ������ء���ģ�����ͨ�����汾
	//�������캯���˻��ɹ��캯��
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

	////�������캯��
	//Vector(const Vector<T>& rhs)
	//{
	//	parr = new T[rhs.totalsize]();//�ѾɵĶ����е�Ԫ�ط����µĶ�����
	//	memcpy(parr, rhs.parr, sizeof(T)*totalsize);
	//	cursize = rhs.cursize;
	//	totalsize = rhs.totalsize;
	//}

	~Vector()
	{
		delete[] parr;
		parr = NULL;
	}

	//����
	void resize()
	{
		T* tmp = new T[totalsize * 2]();//��2������ʽ����
		memcpy(tmp, parr, sizeof(T)*totalsize);//�ɵ����ݿ������µĿռ�
		delete[] parr;//�ͷžɿռ�
		parr = tmp;//ָ��ָ���¿ռ�
		totalsize *= 2;//�����¿ռ���ܴ�С
	}

	//β������
	void push_back(T val)//cursize
	{
		//��һ�ַ�ʽ
	  /*if (full())
		{
			resize();
		}
		parr[cursize++] = val;*/
		//�ڶ��ַ�ʽ
		insert(cursize, val);
	}

	//��λ�ò���
	void insert(int pos, T val)
	{
		if (pos < 0 || pos > cursize)//�����λ�ò�����
		{
			return;
		}
		if (full())//�ռ�����
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

	//βɾ
	void pop_back()
	{
		erase(cursize - 1);
	}

	//��λ��ɾ��
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

	//�п�
	bool empty()
	{
		return cursize == 0;
	}
private:
	bool full()
	{
		return cursize == totalsize;
	}
	T* parr;//ֻ��洢���ݵĿռ�
	int cursize;//��ǰ��ЧԪ�صĸ���  
	//��ǰ�����пɲ���Ԫ�ص��±�
	int totalsize;//��ǰ��Ԫ��������
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

//�������Թ��캯���Ϳ������캯��
int main()
{
	Vector<int> ivec;
	for (int i = 0; i < 5; i++)
	{
		ivec.push_back(i + 1);
	}
	Vector<double> dvec = ivec;//���Ѵ��ڵĶ��������¶��󣬵��ÿ������캯��
	Vector<int> ivec2 = ivec;
	/*�������캯���˻��ɹ��캯������������û�п������캯��������ϵͳ���ṩһ���������캯����ǳ��������
	ʹ����ָ��ָ��ͬһ�����ڴ棬��ivec2����ʱ���ڴ��ͷţ���ivec�ֻ��ͷţ��ظ��ͷ��ڴ浼�³������*/
	return 0;
}
