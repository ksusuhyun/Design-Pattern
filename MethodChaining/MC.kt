class Calculator {
    private var result: Double = 0.0

    fun add(value: Double): Calculator {
        result += value
        return this 
    }

    fun subtract(value: Double): Calculator {
        result -= value
        return this 
    }

    fun multiply(value: Double): Calculator {
        result *= value
        return this 
    }

    fun divide(value: Double): Calculator {
        if (value != 0.0) {
            result /= value
        } else {
            println("Error: Division by zero!")
        }
        return this 
    }

    fun getResult(): Double {
        return result
    }
}

// C++과 C#에서는 double 타입의 변수에 int 값을 전달하면 암묵적으로 형 변환 허용 O
// Kotlin에서는 Int와 Double이 서로 다른 타입으로 간주되며, 암묵적인 형 변환 허용 X
fun main() {
    val calc = Calculator()
    val finalResult = calc.add(5.0).multiply(2.0).subtract(3.0).divide(2.0).getResult()

    println("Final Result: $finalResult")
}