#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

//懒汉模式（不借助实例）
//class SingleTon
//{
//public:
//	static SingleTon* getInstance( )
//	{
//		if (psing == NULL)
//		{
//			m_mtx.lock();
//			if (psing == NULL)
//			{
//				psing = new SingleTon();
//			}
//			m_mtx.unlock();
//		}
//		
//		return psing;
//	}
//private:
//	SingleTon()
//	{
//	}
//	SingleTon(const SingleTon& );
//	static SingleTon* psing;
//	static mutex m_mtx;
//};
//SingleTon* SingleTon::psing = NULL;
//mutex SingleTon::m_mtx;
//int main()
//{
//	SingleTon* psingle1 = SingleTon::getInstance( );
//	SingleTon* psingle2 = SingleTon::getInstance( );
//	SingleTon* psingle3 = SingleTon::getInstance( );
//	return 0;
//}

//饿汉模式（不借助实例）
class SingleTon
{
public:
	static SingleTon* getInstance()
	{
		return psing;
	}
private:
	SingleTon()
	{
	}
	SingleTon(const SingleTon&);
	static SingleTon* psing;
};
SingleTon* SingleTon::psing = new SingleTon();
int main()
{
	SingleTon* psingle1 = SingleTon::getInstance();
	SingleTon* psingle2 = SingleTon::getInstance();
	SingleTon* psingle3 = SingleTon::getInstance();
	return 0;
}