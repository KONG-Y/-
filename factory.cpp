#include<iostream>
#include<memory>
using namespace std;

/*
��������ģʽ������һ�����ڴ�������Ľӿڻ�����࣬���������ʵ�����ĸ���
Ҫ����µ�ʵ���࣬������µľ����Ʒ��͹����ࡣ
*/

//�����Ʒ��
class Product {
public:
	virtual void show() = 0;
};

//�����Ʒ��A
class ProductA :public Product {
public:
	void show()override {
		cout << "Product A" << endl;
	}
};

//�����Ʒ��B
class ProductB :public Product {
public:
	void show()override {
		cout << "Product B" << endl;
	}
};

//���󹤳���
class Factory {
public:
	virtual unique_ptr<Product> createProduct() = 0;
};

//���幤����A
class FactoryA :public Factory {
public:
	unique_ptr<Product> createProduct()override {
		return make_unique<ProductA>();
	}
};

//���幤����B
class FactoryB :public Factory {
public:
	unique_ptr<Product> createProduct()override {
		return make_unique<ProductB>();
	}
};

int main() {
	unique_ptr<Factory> factoryA = make_unique<FactoryA>();
	unique_ptr<Product> productA = factoryA->createProduct();
	productA->show();

	unique_ptr<Factory> factoryB = make_unique<FactoryB>();
	unique_ptr<Product> productB = factoryB->createProduct();
	productB->show();
}