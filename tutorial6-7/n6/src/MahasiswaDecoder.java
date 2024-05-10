import java.lang.reflect.*;

public class MahasiswaDecoder {
    private final Mahasiswa mahasiswa;

    MahasiswaDecoder(Mahasiswa mahasiswa) {
        this.mahasiswa = mahasiswa;
    }

    public void addMatkul(String name) throws Exception {
        Method addMatkul = mahasiswa.getClass().getDeclaredMethod("addMatkul", String.class);
        addMatkul.setAccessible(true);
        addMatkul.invoke(mahasiswa, name);
    }

    public int getNIM() throws Exception {
        Field nim = mahasiswa.getClass().getDeclaredField("NIM");
        nim.setAccessible(true);
        return (int) nim.get(mahasiswa);
    }

    public double getIPK() throws Exception {
        Field ipk = mahasiswa.getClass().getDeclaredField("IPK");
        ipk.setAccessible(true);
        return (double) ipk.get(mahasiswa);
    }
}
