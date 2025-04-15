using System;

namespace FactoryMethod {

    public interface IAnimal {
        string Speak();
    }

    public class Dog : IAnimal {
        public string Speak() {
            return "Woof!";
        }
    }

    public class Cat : IAnimal {
        public string Speak() {
            return "Meow!";
        }
    }

    public class AnimalFactory {
        public IAnimal CreateAnimal(string animalType) {
            if (animalType == "Dog") {
                return new Dog();
            } else if (animalType == "Cat") {
                return new Cat();
            }
        }
    }

    class Program {
        static void Main(string[] args) {
            AnimalFactory animalFactory = new AnimalFactory();
            IAnimal dog = animalFactory.CreateAnimal("Dog");
            IAnimal cat = animalFactory.CreateAnimal("Cat");

            Console.WriteLine("Dog says: " + dog.Speak());
            Console.WriteLine("Cat says: " + cat.Speak());
        }
    }
}