#include<iostream>
#include<memory>
using namespace std;

/*
���󹤳�ģʽ��һ�����幤�����ɶ��ֲ�Ʒ��������һ������Ҫ�������˺�Ů�����ֲ�Ʒ���������к��˹����ͻ��˹���
*/

// �����Ʒ�ࣨ���ˣ�
class AbstractProductMan {
public:
    virtual void show() = 0;
};

// �����Ʒ�ࣨŮ�ˣ�
class AbstractProductWomen {
public:
    virtual void show() = 0;
};

// �����Ʒ�ࣨ�����ˣ�
class ProductGoodMan : public AbstractProductMan {
public:
    void show() override {
        cout << "Product ������" << endl;
    }
};

// �����Ʒ�ࣨ�����ˣ�
class ProductBadMan : public AbstractProductMan {
public:
    void show() override {
        cout << "Product ������" << endl;
    }
};

// �����Ʒ�ࣨ��Ů�ˣ�
class ProductGoodWomen : public AbstractProductWomen {
public:
    void show() override {
        cout << "Product ��Ů��" << endl;
    }
};

// �����Ʒ�ࣨ��Ů�ˣ�
class ProductBadWomen : public AbstractProductWomen {
public:
    void show() override {
        cout << "Product ��Ů��" << endl;
    }
};

// ���󹤳���
class AbstractFactory {
public:
    virtual unique_ptr<AbstractProductMan> createProductMan() = 0;      //��������
    virtual unique_ptr<AbstractProductWomen> createProductWomen() = 0;  //����Ů��
};

// ���幤���ࣨ���ˣ�
class FactoryGood : public AbstractFactory {
public:
    unique_ptr<AbstractProductMan> createProductMan() override {
        return make_unique<ProductGoodMan>();
    }
    unique_ptr<AbstractProductWomen> createProductWomen() override {
        return make_unique<ProductGoodWomen>();
    }
};

// ���幤���ࣨ���ˣ�
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
    //����
    unique_ptr<AbstractFactory> factory1 = make_unique<FactoryGood>();
    unique_ptr<AbstractProductMan> productA1 = factory1->createProductMan();
    unique_ptr<AbstractProductWomen> productB1 = factory1->createProductWomen();
    productA1->show();
    productB1->show();

    //����
    unique_ptr<AbstractFactory> factory2 = make_unique<FactoryBad>();
    unique_ptr<AbstractProductMan> productA2 = factory2->createProductMan();
    unique_ptr<AbstractProductWomen> productB2 = factory2->createProductWomen();
    productA2->show();
    productB2->show();

    return 0;
}
