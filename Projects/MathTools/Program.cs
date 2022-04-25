// Vector
class Root
{
    public int a, b; // Root(a) / Root (b)
    public Root()
    {
        a = 1;
        b = 1;
    }
    public Root(int a, int b)
    {
        this.a = a;
        this.b = b;
    }
    public Root(int a)
    {
        this.a = a * a;
        this.b = 1;
    }
    private Root Reverse()
    {
        return new Root(this.b, this.a);
    }
    public static Root operator*(Root x,Root y)
    {
        return new Root(x.a * y.a, x.b * y.b);
    }
    public static Root operator/(Root x, Root y)
    {
        return x * (y.Reverse());
    }
    public string output()
    {
        return "√" + this.a + "/√" + this.b; 
    }
    public double value()
    {
        return (Math.Sqrt(this.a) / Math.Sqrt(this.b));
    }
}
class Vector3
{
    public Root x, y, z;
    public Vector3()
    {
        x = new Root();
        y = new Root();
        z = new Root();
    }
    public Vector3(Root a, Root b, Root c)
    {
        x = a;
        y = b;
        z = c;
    }
    public Vector3(int a, int b, int c)
    {
        x = new Root(a);
        y = new Root(b);
        z = new Root(c);
    }
    public static Root operator*(Vector3 a, Vector3 b)
    {

    }
}
