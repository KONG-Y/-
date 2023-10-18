#include<iostream>
#include<memory>
using namespace std;

/*
工厂方法模式：定义一个用于创建对象的接口或抽象类，让子类决定实例化哪个类
要添加新的实例类，则添加新的具体产品类和工厂类。
*/

//抽象产品类
class Product {
public:
	virtual void show() = 0;
};

//具体产品类A
class ProductA :public Product {
public:
	void show()override {
		cout << "Product A" << endl;
	}
};

//具体产品类B
class ProductB :public Product {
public:
	void show()override {
		cout << "Product B" << endl;
	}
};

//抽象工厂类
class Factory {
public:
	virtual unique_ptr<Product> createProduct() = 0;
};

//具体工厂类A
class FactoryA :public Factory {
public:
	unique_ptr<Product> createProduct()override {
		return make_unique<ProductA>();
	}
};

//具体工厂类B
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