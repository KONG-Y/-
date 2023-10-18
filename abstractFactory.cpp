#include<iostream>
#include<memory>
using namespace std;

/*
抽象工厂模式：一个具体工厂生成多种产品对象，例如一个工厂要生成男人和女人两种产品，而工厂有好人工厂和坏人工厂
*/

// 抽象产品类（男人）
class AbstractProductMan {
public:
    virtual void show() = 0;
};

// 抽象产品类（女人）
class AbstractProductWomen {
public:
    virtual void show() = 0;
};

// 具体产品类（好男人）
class ProductGoodMan : public AbstractProductMan {
public:
    void show() override {
        cout << "Product 好男人" << endl;
    }
};

// 具体产品类（坏男人）
class ProductBadMan : public AbstractProductMan {
public:
    void show() override {
        cout << "Product 坏男人" << endl;
    }
};

// 具体产品类（好女人）
class ProductGoodWomen : public AbstractProductWomen {
public:
    void show() override {
        cout << "Product 好女人" << endl;
    }
};

// 具体产品类（坏女人）
class ProductBadWomen : public AbstractProductWomen {
public:
    void show() override {
        cout << "Product 坏女人" << endl;
    }
};

// 抽象工厂类
class AbstractFactory {
public:
    virtual unique_ptr<AbstractProductMan> createProductMan() = 0;      //创建男人
    virtual unique_ptr<AbstractProductWomen> createProductWomen() = 0;  //创建女人
};

// 具体工厂类（好人）
class FactoryGood : public AbstractFactory {
public:
    unique_ptr<AbstractProductMan> createProductMan() override {
        return make_unique<ProductGoodMan>();
    }
    unique_ptr<AbstractProductWomen> createProductWomen() override {
        return make_unique<ProductGoodWomen>();
    }
};

// 具体工厂类（坏人）
class FactoryBad : public AbstractFactory {
public:
    unique_ptr<AbstractProductMan> createProductMan() override {
        return make_unique<ProductBadMan>();
    }
    unique_ptr<AbstractProductWomen> createProductWomen() override {
        return make_unique<ProductBadWomen>();
    }
};

int main() {
    //好人
    unique_ptr<AbstractFactory> factory1 = make_unique<FactoryGood>();
    unique_ptr<AbstractProductMan> productA1 = factory1->createProductMan();
    unique_ptr<AbstractProductWomen> productB1 = factory1->createProductWomen();
    productA1->show();
    productB1->show();

    //坏人
    unique_ptr<AbstractFactory> factory2 = make_unique<FactoryBad>();
    unique_ptr<AbstractProductMan> productA2 = factory2->createProductMan();
    unique_ptr<AbstractProductWomen> productB2 = factory2->createProductWomen();
    productA2->show();
    productB2->show();

    return 0;
}
