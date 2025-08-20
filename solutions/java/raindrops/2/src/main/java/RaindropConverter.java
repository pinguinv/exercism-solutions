import java.util.HashMap;
import java.util.Map;

class RaindropConverter {

    private static final HashMap<Integer, String> map = new HashMap<>(){{
        put(3, "Pling");
        put(5, "Plang");
        put(7, "Plong");
    }};

    String convert(int number) {
        StringBuilder result = new StringBuilder();

        for(Map.Entry<Integer, String> e : map.entrySet())
            if (number % e.getKey() == 0)
                result.append(e.getValue());

        if (result.isEmpty())
            result.append(number);

        return result.toString();
    }

}
