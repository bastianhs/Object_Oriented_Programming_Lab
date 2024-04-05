public class Kompleks
{
    private int real;
    private int imaginer;
    static int n_kompleks = 0;

    public Kompleks()
    {
        real = 0;
        imaginer = 0;
        ++n_kompleks;
    }

    public Kompleks(int real, int imaginer)
    {
        this.real = real;
        this.imaginer = imaginer;
        ++n_kompleks;
    }

    public int getReal()
    {
        return real;
    }

    public int getImaginer()
    {
        return imaginer;
    }
    
    public void setReal(int real)
    {
        this.real = real;
    }

    public void setImaginer(int imaginer)
    {
        this.imaginer = imaginer;
    }

    public Kompleks plus(Kompleks b)
    {
        return new Kompleks(
            getReal() + b.getReal(),
            getImaginer() + b.getImaginer()
        );
    }

    public Kompleks minus(Kompleks b)
    {
        return new Kompleks(
            getReal() - b.getReal(),
            getImaginer() - b.getImaginer()
        );
    }

    public Kompleks multiply(Kompleks b)
    {
        return new Kompleks(
            getReal() * b.getReal() - getImaginer() * b.getImaginer(),
            getImaginer() * b.getReal() + getReal() * b.getImaginer()
        );
    }

    public Kompleks multiply(int c)
    {
        return new Kompleks(
            getReal() * c,
            getImaginer() * c
        );
    }

    static int countKompleksInstance()
    {
        return n_kompleks;
    }

    public void print()
    {
        if (getReal() != 0)
        {
            System.out.print(getReal());
        }

        if (getReal() != 0 && getImaginer() > 0)
        {
            System.out.print("+");
        }

        if (getImaginer() != 0)
        {
            System.out.print(getImaginer() + "i");
        }

        if (getReal() == 0 && getImaginer() == 0)
        {
            System.out.print(0);
        }

        System.out.println();
    }
}
