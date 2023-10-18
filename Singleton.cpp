#include<iostream>
using namespace std;

/*
单例模式：一个类只能有一个实例
*/
class Singleton {
public:
	//通过静态局部变量instance的引用，只会被初始化一次。
	//静态局部local static变量允许我们一个变量的生存期相当于整个程序的生存期，而作用范围限制在函数内。
	//函数作用域的static和类作用域static生存期相同，只是类作用域中任何东西都可以访问静态变量
	//Get函数提供唯一通道来访问这个变量。
	static Singleton& Get() {
		static Singleton instance;//第一次调用Get,会初始化instance，后续一直调用这个instance
		return instance;
	}

	void Show() {
		cout << val<< endl;
	}

	void Add() {
		val++;
	}
private:
	int val=0;
};

int main() {
	Singleton::Get().Add();
	Singleton::Get().Show();
	Singleton::Get().Add();
	Singleton::Get().Show();
	Singleton::Get().Add();
	Singleton::Get().Show();
	Singleton::Get().Add();
	Singleton::Get().Show();
	return 0;
}