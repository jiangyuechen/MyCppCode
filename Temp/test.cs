using System;

class std
{
    private Func<int, int, int> fn = (x, y) => x + y;
    public static void Main()
    {
        Console.WriteLine(fn(1, 2));
    }
}