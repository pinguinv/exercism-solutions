public class Say {

    static private final String[] underTwenty = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
            "eighteen", "nineteen"};
    static private final String[] tens = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    private String getSuffix(long number, long modulo, String suffix) {
        long a = number / modulo;
        long b = number % modulo;

        if (b == 0) {
            return say(a) + " " + suffix;
        } else {
            return say(a) + " " + suffix + " " + say(b);
        }
    }

    public String say(long number) {

        if (number < 0)
            throw new IllegalArgumentException("Can't be a negative number");

        if (number < 20L)
            return underTwenty[(int) number];

        if (number % 10 == 0 && number < 100) {
            int index = ((int) number - 20) / 10;
            return tens[index];
        }

        if (number < 100) {
            int tens_index = ((int) number - 20) / 10;
            return tens[tens_index] + '-' + underTwenty[(int) number % 10];
        }

        if (number < 1_000) {
            return getSuffix(number, 100, "hundred");
        }

        if (number < 1_000_000) {
            return getSuffix(number, 1_000, "thousand");
        }

        if (number < 1_000_000_000) {
            return getSuffix(number, 1_000_000, "million");
        }

        if (number < 1_000_000_000_000L) {
            return getSuffix(number, 1_000_000_000, "billion");
        }

        throw new IllegalArgumentException("Not supported");
    }
}
