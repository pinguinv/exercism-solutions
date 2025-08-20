import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.*;

class ParallelLetterFrequency {

    private final String[] texts;

    ParallelLetterFrequency(String[] texts) {
        this.texts = texts;
    }

    Map<Character, Integer> countLetters() {

        Map<Character, Integer> resultMap = new HashMap<>();

        ExecutorService executorService = Executors.newFixedThreadPool(10);

        for (String text : texts) {
            CountLettersTask countLettersTask = new CountLettersTask(text);

            Future<Map<Character, Integer>> future = executorService.submit(countLettersTask);
            Map<Character, Integer> taskResultMap = new HashMap<>();
            try {
                taskResultMap = future.get();
            } catch (InterruptedException | ExecutionException e) {
                e.printStackTrace();
            }

            taskResultMap.forEach((character, integer) -> resultMap.merge(character, integer, Integer::sum));
        }

        executorService.shutdown();

        return resultMap;
    }

    static class CountLettersTask implements Callable<Map<Character, Integer>> {
        private final String text;

        public CountLettersTask(String text) {
            this.text = text;
        }

        @Override
        public Map<Character, Integer> call() throws Exception {
            Map<Character, Integer> map = new HashMap<>();

            for (char c : text.toLowerCase().toCharArray()) {
                if (!Character.isLetter(c))
                    continue;

                if (map.containsKey(c)) {
                    map.put(c, map.get(c) + 1);
                } else {
                    map.put(c, 1);
                }
            }

            return map;
        }
    }
}
