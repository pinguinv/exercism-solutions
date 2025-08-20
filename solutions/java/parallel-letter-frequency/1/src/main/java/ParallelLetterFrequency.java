import java.util.HashMap;
import java.util.Map;

class ParallelLetterFrequency {

    private final String[] texts;

    ParallelLetterFrequency(String[] texts) {
        this.texts = texts;
    }

    Map<Character, Integer> countLetters() {

        Map<Character, Integer> map = new HashMap<>();
//        ExecutorService executorService = Executors.newCachedThreadPool();

        for (String text : texts) {
//            Runnable r = () -> {
                countLettersForOneText(text).forEach((character, integer) -> map.put(character, map.getOrDefault(character, 0) + integer));
//            };

//            executorService.submit(r);
        }

//        executorService.shutdown();

        return map;
    }

    private Map<Character, Integer> countLettersForOneText(String text) {

        Map<Character, Integer> map = new HashMap<>();

        for (int j = 0; j < text.length(); j++) {
            char ch = Character.toLowerCase(text.charAt(j));

            if (!Character.isAlphabetic(ch))
                continue;

            if (map.containsKey(ch)) {
                map.put(ch, map.get(ch) + 1);
            } else {
                map.put(ch, 1);
            }
        }

        return map;
    }

}
