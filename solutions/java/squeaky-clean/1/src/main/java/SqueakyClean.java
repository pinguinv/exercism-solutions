class SqueakyClean {
    static String clean(String identifier) {
        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < identifier.length(); i++) {
            if (identifier.charAt(i) == ' '){
                stringBuilder.append('_');
                continue;
            }

            if (identifier.charAt(i) == '-'){
                i++;
                stringBuilder.append(Character.toUpperCase(identifier.charAt(i)));
                continue;
            }

            if (Character.isDigit(identifier.charAt(i))){
                switch (identifier.charAt(i)){
                    case '4':
                        stringBuilder.append('a');
                        break;

                    case '3':
                        stringBuilder.append('e');
                        break;

                    case '0':
                        stringBuilder.append('o');
                        break;

                    case '1':
                        stringBuilder.append('l');
                        break;

                    case '7':
                        stringBuilder.append('t');
                        break;

                    default:
                }

                continue;
            }

            if (!Character.isAlphabetic(identifier.charAt(i))) {
                continue;
            }

            stringBuilder.append(identifier.charAt(i));
        }

        return stringBuilder.toString();
    }
}
