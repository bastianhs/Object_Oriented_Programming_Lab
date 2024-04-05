import java.lang.Comparable;

class MataKuliah implements Comparable<MataKuliah>
{
    private String nama;
    private int kodeJurusan;
    private int tahunPengambilan;
    private float rating;

    public MataKuliah(String nama, int kodeJurusan, int tahunPengambilan, float rating)
    {
        this.nama = nama;
        this.kodeJurusan = kodeJurusan;
        this.tahunPengambilan = tahunPengambilan;
        this.rating = rating;
    }

    public String getNama()
    {
        return nama;
    }
    
    public int getKodeJurusan()
    {
        return kodeJurusan;
    }
    
    public int getTahunPengambilan()
    {
        return tahunPengambilan;
    }
    
    public float getRating()
    {
        return rating;
    }

    public void getNama(String nama)
    {
        this.nama = nama;
    }
    
    public void getKodeJurusan(int kodeJurusan)
    {
        this.kodeJurusan = kodeJurusan;
    }
    
    public void getTahunPengambilan(int tahunPengambilan)
    {
        this.tahunPengambilan = tahunPengambilan;
    }
    
    public void getRating(float rating)
    {
        this.rating = rating;
    }

    public int compareTo(MataKuliah m)
    {
        // compareTo mengembalikan:
        // 0 bila this sama dengan m
        // 1 bila this lebih dari m
        // -1 bila this kurang dari m
        if (getKodeJurusan() < m.getKodeJurusan())
        {
            return -1;
        }
        else if (getKodeJurusan() > m.getKodeJurusan())
        {
            return 1;
        }
        else if (getTahunPengambilan() < m.getTahunPengambilan())
        {
            return -1;
        }
        else if (getTahunPengambilan() > m.getTahunPengambilan())
        {
            return 1;
        }
        else if (getRating() < m.getRating())
        {
            return -1;
        }
        else if (getRating() > m.getRating())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
