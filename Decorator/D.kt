// open class는 클래스와 메서드가 상속 및 오버라이드될 수 있도록 허용한다.
open class Coffee {
    open fun cost(): Int {
        return 5
    }
}


open class CoffeeDecorator(private val coffee: Coffee) : Coffee() {
    override fun cost(): Int {
        return coffee.cost()
    }
}


class MilkDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 2
    }
}

class SugarDecorator(coffee: Coffee) : CoffeeDecorator(coffee) {
    override fun cost(): Int {
        return super.cost() + 1
    }
}

fun main() {
    val coffee = Coffee()
    println("Plain coffee cost: ${coffee.cost()}")

    val coffeeWithMilk = MilkDecorator(coffee)
    println("Coffee with milk cost: ${coffeeWithMilk.cost()}") 

    val coffeeWithSugar = SugarDecorator(coffee)
    println("Coffee with sugar cost: ${coffeeWithSugar.cost()}") 

    val coffeeWithMilkAndSugar = SugarDecorator(coffeeWithMilk)
    println("Coffee with milk and sugar cost: ${coffeeWithMilkAndSugar.cost()}") 
}