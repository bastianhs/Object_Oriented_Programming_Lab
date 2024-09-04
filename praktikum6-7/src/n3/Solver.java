import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solver {
    private ArrayList<String> prompts;

    public Solver() {
        this.prompts = new ArrayList<String>();
    }

    public void addPiece(String prompt) {
        this.prompts.add(prompt);
    }

    public String scrapeAnswer() {
        // Kode berikut masih melakukan scrap ke GPT secara sekuensial.
        // Agar lebih cepat, ubahlah kode di bawah ini menjadi paralel
        // menggunakan wait dan notify, dengan membuat instance Scraper
        // Perhatikan juga bahwa piece answer di sini belum terurut.
        String answer = "";
        for (String prompt : prompts) {
            Gpt gpt = new Gpt(prompt);
            answer += gpt.getPieceAnswer();
        }
        return answer;
    }
}