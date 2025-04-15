#include <iostream>
#include <string>

using namespace std;

class Animal {
public:
    virtual ~Animal() = default;
    virtual string speak() const = 0;    
};

class Dog : public Animal {
public:
    string speak() const override {
        return "Woof!";
    }
};

class Cat : public Animal {
public:
    string speak() const override {
        return "Meow!";
    }
};

class AnimalFactory {
public:
    static Animal* createAnimal(const string& animalType) {
        if (animalType == "Dog") {
            return new Dog();
        } else if (animalType == "Cat") {
            return new Cat();
        }
        return nullptr; // c++에서는 모든 코드 경로에서 반환값을 명시해야 한다. 즉, dog와 cat이 아닌 경우에 반환값이 정의되어야 한다.
    }
};

int main() {
    Animal* myDog = AnimalFactory::createAnimal("Dog");
    Animal* myCat = AnimalFactory::createAnimal("Cat");

    cout << "Dog says: " << myDog->speak() << endl;
    cout << "Cat says: " << myCat->speak() << endl;

    delete myDog;
    delete myCat;

    return 0;
}