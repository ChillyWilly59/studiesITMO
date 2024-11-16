
public interface IRotatable
{
    void Rotate();
}

public abstract class Shape 
{ 
    public abstract double CalculateArea();
    public abstract double CalculatePerimeter();

    public virtual void PrintDetails()
    {
        Console.WriteLine($"Area: {CalculateArea()}");
        Console.WriteLine($"Perimeter: {CalculatePerimeter()}");
    }
}

public class Circle : Shape
{
    public double Radius { get; private set; }

    public Circle(double radius)
    {
        Radius = radius;
    }

    public override double CalculateArea()
    {
        return Math.PI * Radius * Radius;
    }

    public override double CalculatePerimeter()
    {
        return 2 * Math.PI * Radius;
    }

    public void PrintRadius()
    {
        Console.WriteLine($"Radius: {Radius}");
    }

    public override void PrintDetails()
    {
        base.PrintDetails();
        PrintRadius();
    }
}

public class Square : Shape, IRotatable
{
    public double Side { get; private set; }

    public Square(double side)
    {
        Side = side;
    }

    public override double CalculateArea()
    {
        return Side * Side;
    }

    public override double CalculatePerimeter()
    {
        return 4 * Side;
    }

    public void PrintSide()
    {
        Console.WriteLine($"Side: {Side}");
    }

    public void Rotate()
    {
        Console.WriteLine("Square rotated 90 degrees.");
    }

    public override void PrintDetails()
    {
        base.PrintDetails();
        PrintSide();
    }
}

public class Triangle : Shape, IRotatable
{
    public double SideA { get; private set; }
    public double SideB { get; private set; }
    public double SideC { get; private set; }

    public Triangle(double sideA, double sideB, double sideC)
    {
        SideA = sideA;
        SideB = sideB;
        SideC = sideC;
    }

    public override double CalculateArea()
    {
        double semiPerimeter = CalculatePerimeter() / 2;
        return Math.Sqrt(semiPerimeter * (semiPerimeter - SideA) * (semiPerimeter - SideB) * (semiPerimeter - SideC));
    }

    public override double CalculatePerimeter()
    {
        return SideA + SideB + SideC;
    }

    public void PrintSides()
    {
        Console.WriteLine($"Side A: {SideA}, Side B: {SideB}, Side C: {SideC}");
    }

    public void Rotate()
    {
        Console.WriteLine("Triangle rotated 90 degrees.");
    }

    public override void PrintDetails()
    {
        base.PrintDetails();
        PrintSides();
    }
}

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter the radius of the circle:");
        double circleRadius = Convert.ToDouble(Console.ReadLine());
        Shape circle = new Circle(circleRadius);

        Console.WriteLine("Enter the side length of the square:");
        double squareSide = Convert.ToDouble(Console.ReadLine());
        Shape square = new Square(squareSide);

        Console.WriteLine("Enter the lengths of the sides of the triangle:");
        Console.Write("Side A: ");
        double sideA = Convert.ToDouble(Console.ReadLine());
        Console.Write("Side B: ");
        double sideB = Convert.ToDouble(Console.ReadLine());
        Console.Write("Side C: ");
        double sideC = Convert.ToDouble(Console.ReadLine());
        Shape triangle = new Triangle(sideA, sideB, sideC);

        Console.WriteLine("\nCircle Details:");
        circle.PrintDetails();
        Console.WriteLine();

        Console.WriteLine("Square Details:");
        square.PrintDetails();
        Console.WriteLine();

        Console.WriteLine("Triangle Details:");
        triangle.PrintDetails();
        Console.WriteLine();

        Console.WriteLine("Rotating shapes...");
        if (square is IRotatable rotatableSquare)
        {
            rotatableSquare.Rotate();
        }
        if (triangle is IRotatable rotatableTriangle)
        {
            rotatableTriangle.Rotate();
        }
    }
}
