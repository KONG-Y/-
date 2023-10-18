#include<iostream>
using namespace std;

/*
����ģʽ��һ����ֻ����һ��ʵ��
*/
class Singleton {
public:
	//ͨ����̬�ֲ�����instance�����ã�ֻ�ᱻ��ʼ��һ�Ρ�
	//��̬�ֲ�local static������������һ���������������൱����������������ڣ������÷�Χ�����ں����ڡ�
	//�����������static����������static��������ͬ��ֻ�������������κζ��������Է��ʾ�̬����
	//Get�����ṩΨһͨ�����������������
	static Singleton& Get() {
		static Singleton instance;//��һ�ε���Get,���ʼ��instance������һֱ�������instance
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