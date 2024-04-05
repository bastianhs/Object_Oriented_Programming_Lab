public class TempatTinggal {
    private int luas;
    private double hargaBahanBangunan;

    public int getLuas()
    {
        return luas;
    }

    public double getHargaBahanBangunan()
    {
        return hargaBahanBangunan;
    }

    public void setLuas(int luas)
    {
        this.luas = luas;
    }
    
    public void setHargaBahanBangunan(double hargaBahanBangunan)
    {
        this.hargaBahanBangunan = hargaBahanBangunan;
    }

    public double hitungBiayaBangun()
    {
        return getLuas() * getHargaBahanBangunan();
    }
}

class Rumah extends TempatTinggal
{
    public Rumah(int luas, double hargaBahanBangunan)
    {
        setLuas(luas);
        setHargaBahanBangunan(hargaBahanBangunan);
    }
    
    public Rumah(int lebar, int panjang, double hargaBahanBangunan)
    {
        setLuas(lebar * panjang);
        setHargaBahanBangunan(hargaBahanBangunan);
    }

    public double hitungBiayaBangun(double biayaOrmas)
    {
        return hitungBiayaBangun() + biayaOrmas;
    }

    public void setLuas(int lebar, int panjang)
    {
        setLuas(lebar * panjang);
    }
}

interface Kendaraan
{
    public float hitungJarakTempuh();
}

class Karavan extends TempatTinggal implements Kendaraan
{
    private float bensin;
    private float pemakaianBensin;

    public float getBensin()
    {
        return bensin;
    }
    
    public float getPemakaianBensin()
    {
        return pemakaianBensin;
    }

    public void setBensin(float bensin)
    {
        this.bensin = bensin;
    }
    
    public void setPemakaianBensin(float pemakaianBensin)
    {
        this.pemakaianBensin = pemakaianBensin;
    }
    
    public double hitungBiayaBangun()
    {
        return super.hitungBiayaBangun() * 3;
    }

    public float hitungJarakTempuh()
    {
        return getBensin() * getPemakaianBensin();
    }
}
