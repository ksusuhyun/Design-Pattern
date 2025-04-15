using System;

class Coffee
{
    public virtual int Cost()
    {
        return 5;
    }
}

class CoffeeDecorator : Coffee
{
    protected Coffee _coffee;

    public CoffeeDecorator(Coffee coffee)
    {
        _coffee = coffee;
    }

    public override int Cost()
    {
        return _coffee.Cost();
    }
}

class MilkDecorator : CoffeeDecorator
{
    public MilkDecorator(Coffee coffee) : base(coffee) { }

    public override int Cost()
    {
        return _coffee.Cost() + 2;
    }
}

class SugarDecorator : CoffeeDecorator
{
    public SugarDecorator(Coffee coffee) : base(coffee) { }

    public override int Cost()
    {
        return _coffee.Cost() + 1;
    }
}

class Program
{
    static void Main(string[] args)
    {
        Coffee coffee = new Coffee();
        Console.WriteLine("Plain coffee cost: " + coffee.Cost());

        Coffee coffeeWithMilk = new MilkDecorator(coffee);
        Console.WriteLine("Coffee with milk cost: " + coffeeWithMilk.Cost());

        Coffee coffeeWithSugar = new SugarDecorator(coffee);
        Console.WriteLine("Coffee with sugar cost: " + coffeeWithSugar.Cost());

        Coffee coffeeWithMilkAndSugar = new SugarDecorator(coffeeWithMilk);
        Console.WriteLine("Coffee with milk and sugar cost: " + coffeeWithMilkAndSugar.Cost()); 
    }
}