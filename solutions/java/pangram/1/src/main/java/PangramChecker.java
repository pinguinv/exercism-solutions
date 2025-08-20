import java.util.HashMap;
import java.util.Map;

public class PangramChecker {

    public boolean isPangram(String input) {
        Map<Character, Integer> characterMap = new HashMap<>();

        for (char c : input.toLowerCase().toCharArray()){
            if (Character.isLetter(c)){
                characterMap.put(c, characterMap.getOrDefault(c, 0) + 1);
            }
        }

        return characterMap.keySet().size() == 26;

    }

}
