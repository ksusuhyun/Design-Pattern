abstract class Animal {
    abstract fun speak(): String
}

class Dog : Animal() {
    override fun speak(): String {
        return "Woof!"
    }
}

class Cat : Animal() {
    override fun speak(): String {
        return "Meow!"
    }
} 

// Animal?은 Animal 타입이거나 null일 수 있음을 나타낸다.
class AnimalFactory {
    fun createAnimal(animalType: String): Animal? {
        return when (animalType.lowercase()) {
            "dog" -> Dog()
            "cat" -> Cat()
            else -> null
        }
    }
}

// ?. 연산자는 null 안전 호출 연산자로, dog가 null이 아닐 때만 메소드를 호출한다.
fun main() {
    val animalFactory = AnimalFactory()

    val dog = animalFactory.createAnimal("dog")
    val cat = animalFactory.createAnimal("cat")

    println("Dog says: ${dog?.speak()}")
    println("Cat says: ${cat?.speak()}")
}