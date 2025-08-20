class BottleSong {

    private static final String[] verses = {
            " green bottle", " hanging on the wall,\n",
            "And if one green bottle should accidentally fall,\n",
            "There'll be ",
            " green bottle", " hanging on the wall.\n",
            "\n"
    };

    private static final String[] numbers = {
            "No", "One", "Two",
            "Three", "Four", "Five",
            "Six", "Seven", "Eight",
            "Nine", "Ten"
    };


    String recite(int bottlesNum, int takeDown) {
        StringBuilder sb = new StringBuilder();

        for (int i = bottlesNum; takeDown > 0; i--, takeDown--){
            // first two verses
            sb.append(numbers[i]).append(verses[0])
                    .append(i == 1 ? "" : "s").append(verses[1]);
            sb.append(numbers[i]).append(verses[0])
                    .append(i == 1 ? "" : "s").append(verses[1]);
            // third always the same
            sb.append(verses[2]);
            // fourth verse
            sb.append(verses[3]).append(numbers[i - 1].toLowerCase())
                    .append(verses[4]).append(i - 1 == 1 ? "" : "s")
                    .append(verses[5]);
            // newline if not last verse
            if (takeDown - 1 > 0)
                sb.append(verses[6]);
        }

        return sb.toString();
    }

}