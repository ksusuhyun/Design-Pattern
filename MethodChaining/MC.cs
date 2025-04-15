using System;

class Calculator
{
    private double result;

    public Calculator()
    {
        result = 0;
    }

    public Calculator Add(double value)
    {
        result += value;
        return this; 
    }

    public Calculator Subtract(double value)
    {
        result -= value;
        return this; 
    }

    public Calculator Multiply(double value)
    {
        result *= value;
        return this; 
    }

    public Calculator Divide(double value)
    {
        if (value != 0)
        {
            result /= value;
        }
        else
        {
            Console.WriteLine("Error: Division by zero!");
        }
        return this; 
    }

    public double GetResult()
    {
        return result;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Calculator calc = new Calculator();
        double finalResult = calc.Add(5).Multiply(2).Subtract(3).Divide(2).GetResult();

        Console.WriteLine("Final Result: " + finalResult);
    }
}