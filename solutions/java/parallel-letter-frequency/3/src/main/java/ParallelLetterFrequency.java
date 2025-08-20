import java.util.List;
import java.util.Map;
import java.util.concurrent.*;

class ParallelLetterFrequency {

    private List<String> texts;
    private ConcurrentMap<Character, Integer> letterFrequencyMap;

    ParallelLetterFrequency(String[] texts) {
        this.texts = List.of(texts);
        letterFrequencyMap = new ConcurrentHashMap<>();
    }

    Map<Character, Integer> countLetters() {

        if (texts.isEmpty() || !letterFrequencyMap.isEmpty()) {
            return letterFrequencyMap;
        }

        texts.parallelStream().forEach(text -> {
            for (char ch : text.toLowerCase().toCharArray()) {
                if (!Character.isAlphabetic(ch))
                    continue;

                letterFrequencyMap.merge(ch, 1, Integer::sum);
            }
        });

        return letterFrequencyMap;
    }

}
