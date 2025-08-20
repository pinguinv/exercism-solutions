import java.util.HashMap;
import java.util.Map;

class RaindropConverter {

    String convert(int number) {
        HashMap<Integer, String> hashMap = new HashMap<>();
        hashMap.put(3, "Pling");
        hashMap.put(5, "Plang");
        hashMap.put(7, "Plong");

        StringBuilder result = new StringBuilder();

        for(Map.Entry<Integer, String> e : hashMap.entrySet()){
            if (number % e.getKey() == 0)
                result.append(e.getValue());
        }

        if (result.isEmpty())
            result.append(number);

        return result.toString();
    }

}
