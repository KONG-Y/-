#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
	观察者模式：当一个对象状态发生改变时，所有依赖于它的对象都会得到通知并自动更新
*/

//抽象观察者类
class Observer {
public:
	virtual void Update(const string& message) = 0;
};

//具体观察者类
class ConcreteObserver :public Observer {
private:
	string name;
public:
	ConcreteObserver(const string& n) :name(n) {}
	void Update(const string& message)override {
		cout << name << " 收到信息：" << message << endl;
	}
};

//抽象主题类(发布)
class Subject {
private:
	vector<Observer*>observers;

public:

	//注册
	void Attach(Observer* observer) {
		observers.push_back(observer);
	}
	//注销
	void Detach(Observer* observer) {
		//remove会把[begin,end]所有等于observer的值移动到尾部，并返回第一个相同值的开始位置
		//erase会把这段区域的值移除掉
		observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
	}
	//通知
	void Notify(const string& message) {
		for (Observer* observer : observers) {
			observer->Update(message);
		}
	}
};
//具体主题类
class ConcreteSubject :public Subject {
public:
	void SomeBusinessLogic(const string& message) {
		Notify(message);
	}
};

int main() {
	ConcreteObserver observer1("Observer 1");
	ConcreteObserver observer2("Observer 2");

	ConcreteSubject subject;
	subject.Attach(&observer1);
	subject.Attach(&observer2);

	subject.SomeBusinessLogic("Hello Observers!");

	subject.Detach(&observer1);

	subject.SomeBusinessLogic("Another message!");

	return 0;
}
