#include <iostream>
using namespace std;

class Coffee {
public:
    virtual int cost() const {
        return 5;
    }
    virtual ~Coffee() = default;
};

class CoffeeDecorator : public Coffee {
protected:
    const Coffee* coffee;
public:
    CoffeeDecorator(const Coffee* coffee) : coffee(coffee) {}
    virtual int cost() const override {
        return coffee->cost();
    }
    virtual ~CoffeeDecorator() {
        delete coffee;
    }
};

class MilkDecorator : public CoffeeDecorator {
public:
    MilkDecorator(const Coffee* coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 2;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    SugarDecorator(const Coffee* coffee) : CoffeeDecorator(coffee) {}
    int cost() const override {
        return coffee->cost() + 1;
    }
};

int main() {
    Coffee* coffee = new Coffee();
    cout << "Plain coffee cost: " << coffee->cost() << endl;

    Coffee* coffeeWithMilk = new MilkDecorator(coffee);
    cout << "Coffee with milk cost: " << coffeeWithMilk->cost() << endl;

    Coffee* coffeeWithSugar = new SugarDecorator(coffee);
    cout << "Coffee with sugar cost: " << coffeeWithSugar->cost() << endl; 

    Coffee* coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
    cout << "Coffee with milk and sugar cost: " << coffeeWithMilkAndSugar->cost() << endl; 

    return 0;
}