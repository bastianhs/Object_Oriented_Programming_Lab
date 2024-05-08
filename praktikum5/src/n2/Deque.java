import java.util.ArrayList;
import java.util.List;

// Class Deque berikut merupakan suatu kelas Generic yang merepresentasikan suatu Deque.
// Deque merupakan suatu struktur data yang mirip dengan Queue, namun Deque memiliki dua ujung, yaitu front dan back.
// Deque disimpan dengan memanfaatkan ArrayList.
// Elemen front pada Deque disimpan pada indeks paling kiri, sedangkan elemen back disimpan pada indeks paling kanan.
public class Deque<T> {

  private List<T> data;

  private int lastElmIdx, size;

  private final static int DEFAULT_Deque_SIZE = 500;


  //Constructor dengan size default
  public Deque() {
    data = new ArrayList<T>();
    lastElmIdx = -1;
    size = DEFAULT_Deque_SIZE;
  }

  //Constructor dengan size = n
  public Deque(int n) {
    data = new ArrayList<T>();
    lastElmIdx = -1;
    size = n;
  }

  //Copy Constructor dari Deque lain
  public Deque(final Deque<T> q) {
    data = new ArrayList<T>();
    for (int i = 0; i <= q.lastElmIdx; ++i) {
        data.add(q.data.get(i));
    }

    lastElmIdx = q.lastElmIdx;
    size = q.size;
  }

  //Method untuk menambahkan elemen pada ujung front Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushFront(T t) throws Exception {
    if (isFull()) {
        throw new Exception("Deque is full");
    }

    data.add(0, t);
    ++lastElmIdx;
  }

  //Method untuk menambahkan elemen pada ujung back Deque
  //Jika Deque penuh, lempar exception "Deque is full"
  public void pushBack(T t) throws Exception {
    if (isFull()) {
        throw new Exception("Deque is full");
    }

    data.add(t);
    ++lastElmIdx;
  }

  //Method untuk menghapus elemen pada ujung front Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popFront() throws Exception {
    if (isEmpty()) {
        throw new Exception("Deque is empty");
    }

    T temp = data.remove(0);
    --lastElmIdx;
    return temp;
  }

  //Method untuk menghapus elemen pada ujung back Deque
  //Jika Deque kosong, lempar exception "Deque is empty"
  public T popBack() throws Exception {
    if (isEmpty()) {
        throw new Exception("Deque is empty");
    }

    T temp = data.remove(lastElmIdx);
    --lastElmIdx;
    return temp;
  }

  //Method untuk membalikkan urutan elemen pada Deque
  public void reverse() {
    for (int i = 0; i <= lastElmIdx / 2; ++i) {
        T temp = data.get(i);
        data.set(i, data.get(lastElmIdx - i));
        data.set(lastElmIdx - i, temp);
    }
  }

  //Method untuk mengecek apakah Deque kosong
  public boolean isEmpty() {
    return lastElmIdx == -1;
  }
  
  //Method untuk mengecek apakah Deque penuh
  public boolean isFull() {
    return lastElmIdx == size - 1;
  }

  //Method untuk mendapatkan ukuran Deque
  public int size() {
    return size;
  }
}
