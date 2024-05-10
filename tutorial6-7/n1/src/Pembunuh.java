/**
 * Note:
 * 1. Tab pada komentar hanya untuk mempermudah pembacaan, tidak ada tab pada saat melakukan print
 * suatu pesan.
 * 2. Self adalah karakter yang melakukan aksi, target adalah karakter yang menjadi target aksi.
 * 3. Pastikan segala aksi yang mengurangi darah target memanggil method terimaSerangan(), dipanggil
 * setelah menampilkan pesan yang berkaitan dengan aksi (serangan, kemampuan, ultimate).
 */

public class Pembunuh implements Kelas {
    private String senjata;

    public Pembunuh(String senjata) {
        this.senjata = senjata;
    }

    // Getter and setter
    public String getSenjata() {
        return senjata;
    }

    public void setSenjata(String senjata) {
        this.senjata = senjata;
    }

    /**
     * Implementasikan method-method yang ada pada interface Kelas
     */
    
    // Menyerang target dan mengurangi health target sebesar 20.
    // Menampilkan pesan
    //      "[nama karakter], sang pembunuh, menyerang [nama target] dengan [senjata]"
    public void serang(Karakter self, Karakter target) {
        System.out.format("%s, sang pembunuh, menyerang %s dengan %s%n", self.getName(), target.getName(), getSenjata());
        target.terimaSerangan(20);
    }

    // Menyerap health target sebesar 20 (tentunya sembari mengurangi health target).
    // Target harus hidup. Apabila darah target kurang dari 20, maka darah target akan diserap 
    // hingga mati. Jika target sudah mati, tidak melakukan apa-apa.
    // Jika target masih hidup, menampilkan pesan
    //      "[nama karakter] menyerap health [nama target] sebesar [jumlah health yang diserap]"
    // Jika target sudah mati, menampilkan pesan
    //      "[nama target] sudah mati, tidak bisa diserap healthnya"
    public void gunakanKemampuan(Karakter self, Karakter target) {
        if (target.isHidup()) {
            int healthDiserap = 20;
            if (target.getHealth() < 20) {
                healthDiserap = target.getHealth();
            }
            self.addHealth(healthDiserap);
            System.out.format("%s menyerap health %s sebesar %s%n", self.getName(), target.getName(), healthDiserap);
            target.terimaSerangan(healthDiserap);
        } else {
            System.out.format("%s sudah mati, tidak bisa diserap healthnya%n", target.getName());
        }
    }

    // Menyalin wujud target (menyalin skillnya) lalu mengisi health sebesar 40 dan mana sebesar 20.
    // Target harus sudah mati. Menyalin skill berarti mengubah kelas yang dimiliki karakter.
    // Menampilkan pesan 
    //      "[nama karakter] menyalin wujud [nama target]"
    // Jika target sudah mati (penyalinan berhasil) menampilkan pesan
    //      "[nama target] berhasil disalin wujudnya"
    //      "[nama karakter] memperoleh 40 health dan 20 mana"
    // Jika target masih hidup, tidak melakukan apa-apa, dan menampilkan pesan
    //      "[nama target] belum mati, tidak bisa disalin wujudnya"
    public void gunakanUltimate(Karakter self, Karakter target) {
        if (!target.isHidup()) {
            System.out.format("%s menyalin wujud %s%n", self.getName(), target.getName());
            self.setKelas(target.getKelas());
            System.out.format("%s berhasil disalin wujudnya%n", target.getName());
            self.addHealth(40);
            self.addMana(20);
            System.out.format("%s memperoleh 40 health dan 20 mana%n", self.getName());
        } else {
            System.out.format("%s belum mati, tidak bisa disalin wujudnya%n", target.getName());
        }
    }
}
