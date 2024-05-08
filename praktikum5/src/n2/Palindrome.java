public class Palindrome<T> {
    //Method untuk mengecek apakah Deque dq merupakan palindrome
    //Deque dq merupakan palindrome jika elemen-elemen pada Deque dq dapat dibaca sama dari depan dan belakang
    public boolean isPalindrome(Deque<T> dq) {
        Deque<T> dq2 = new Deque<>(dq);
        dq2.reverse();
        try {
            for (int i = 0; i < dq.size(); ++i) {
                if (dq.popFront() != dq2.popFront()) {
                    return false;
                }
            }

            return true;
        } catch (Exception e) {
            return true;
        }
    }
}
