//µ¥ÀıÄ£Ê½
#include<iostream>
using namespace std;

class Master
{
public:
	static Master* getInstance(char* name, int age, bool sex)
	{
		if (pm == NULL)
		{
			pm = new Master(name, age, sex);
		}
		return pm;
	}
private:
	Master(char* name, int age, bool sex)
		:mname(new char[strlen(name) + 1]()), mage(age), msex(sex)
	{
			strcpy_s(mname, strlen(name) + 1, name);
		cout << "mname:" << mname << "  mage:" << mage << "  msex:" << msex << endl;
	}
	char* mname;
	int mage;
	bool msex;
	static Master* pm;
};
Master* Master::pm = NULL;
int main()
{
	Master* m1 = Master::getInstance("Zhangsan", 50, true);
	Master* m2 = Master::getInstance("Lisi", 60, true);
	Master* m3 = Master::getInstance("Wangwu", 40, true);
	return 0;
}
