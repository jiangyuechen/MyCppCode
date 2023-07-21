using System;

class Program {
    
    public static double sin(double x, uint n, bool output = true) {
        double res = 0.00;
        double _x = x;
        uint div = 1;
        for (int i = 1; i <= n; i++) {
            double ss = x / div;
            x *= _x * _x;
            div *= (div + 1) * (div + 2);
            if (i % 2 == 0)
                ss = -ss;
            res += ss;
        }
        return res;
    }
    public static void Main (string[] args) {
        Console.WriteLine(sin(1, 30));
    }
}
