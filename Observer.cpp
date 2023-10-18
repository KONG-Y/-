#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*
	�۲���ģʽ����һ������״̬�����ı�ʱ���������������Ķ��󶼻�õ�֪ͨ���Զ�����
*/

//����۲�����
class Observer {
public:
	virtual void Update(const string& message) = 0;
};

//����۲�����
class ConcreteObserver :public Observer {
private:
	string name;
public:
	ConcreteObserver(const string& n) :name(n) {}
	void Update(const string& message)override {
		cout << name << " �յ���Ϣ��" << message << endl;
	}
};

//����������(����)
class Subject {
private:
	vector<Observer*>observers;

public:

	//ע��
	void Attach(Observer* observer) {
		observers.push_back(observer);
	}
	//ע��
	void Detach(Observer* observer) {
		observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
	}
	//֪ͨ
	void Notify(const string& message) {
		for (Observer* observer : observers) {
			observer->Update(message);
		}
	}
};
//����������
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