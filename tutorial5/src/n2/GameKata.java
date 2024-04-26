import java.util.HashMap;
import java.util.Map;

public class GameKata {
    public static void run(String[] tito, String[] wiwid) {
        Map<String, Integer> wordsFromTito = new HashMap<>();
        Map<String, Integer> wordsFromWiwid = new HashMap<>();
        
        for (String word : tito) {
            wordsFromTito.put(word, wordsFromTito.getOrDefault(word, 0) + 1);
        }
        
        for (String word : wiwid) {
            wordsFromWiwid.put(word, wordsFromWiwid.getOrDefault(word, 0) + 1);
        }

        for (String word : wordsFromTito.keySet()) {
            if (wordsFromWiwid.containsKey(word)) {
                System.out.println(word);
            }
        }
    }
}
