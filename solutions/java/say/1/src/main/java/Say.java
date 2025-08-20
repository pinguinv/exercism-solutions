import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Say {
    final static private HashMap<String, String> basicNumbers = new HashMap<>() {{
        put("0", "zero");
        put("1", "one");
        put("2", "two");
        put("3", "three");
        put("4", "four");
        put("5", "five");
        put("6", "six");
        put("7", "seven");
        put("8", "eight");
        put("9", "nine");
        put("10", "ten");
        put("11", "eleven");
        put("12", "twelve");
        put("13", "thirteen");
        put("14", "fourteen");
        put("15", "fifteen");
        put("16", "sixteen");
        put("17", "seventeen");
        put("18", "eighteen");
        put("19", "nineteen");
        put("20", "twenty");
        put("30", "thirty");
        put("40", "forty");
        put("50", "fifty");
        put("60", "sixty");
        put("70", "seventy");
        put("80", "eighty");
        put("90", "ninety");
    }};

    static private List<String> breakIntoChunks(String numStr) {
        List<String> list = new ArrayList<>();

        for (int i = numStr.length(); i > 0; i -= 3) {
            String chunk = numStr.substring(Math.max(i - 3, 0), i);

            while (chunk.length() < 3)
                chunk = "0" + chunk;

            list.add(chunk);
        }

        return list.reversed();
    }

    static private String getLastTwoDigitsString(String chunkStr) {
        StringBuilder result = new StringBuilder();

        if (chunkStr.substring(1).compareTo("00") == 0)
            return "";

        if (chunkStr.charAt(1) == '0') {
            result.append(basicNumbers.get(chunkStr.substring(2)));
        } else if (chunkStr.charAt(1) == '1') {
            result.append(basicNumbers.get(chunkStr.substring(1)));
        } else {
            result.append(basicNumbers.get(chunkStr.charAt(1) + "0"));
            result.append('-');
            result.append(basicNumbers.get(chunkStr.substring(2)));
        }

        return result.toString();
    }

    static private String getNothingThousandMillionOrBillionString(int chunkNumFromEnd) {
        StringBuilder result = new StringBuilder();

        switch (chunkNumFromEnd) {
            case 1:
                result.append(" thousand ");
                break;

            case 2:
                result.append(" million ");
                break;

            case 3:
                result.append(" billion ");
                break;

            default:
                break;
        }

        return result.toString();
    }

    public String say(long number) {
        if (number < 0 || number > 999_999_999_999L)
            throw new IllegalArgumentException();

        StringBuilder result = new StringBuilder();

        String numStr = String.valueOf(number);

        result.append(basicNumbers.getOrDefault(numStr, ""));

        if (!result.isEmpty())
            return result.toString();

        List<String> chunks = breakIntoChunks(numStr);
        int chunkCount = chunks.size();

        for (int i = 0; i < chunkCount; i++) {
            String chunk = chunks.get(i);

            if (chunk.compareTo("000") == 0 && !result.isEmpty())
                continue;

            if (chunk.charAt(0) != '0') {
                result.append(basicNumbers.get(chunk.charAt(0) + ""));
                result.append(" hundred ");
            }

            result.append(getLastTwoDigitsString(chunk));

            result.append(getNothingThousandMillionOrBillionString(chunkCount - 1 - i));
        }

        return result.toString().trim();
    }
}
