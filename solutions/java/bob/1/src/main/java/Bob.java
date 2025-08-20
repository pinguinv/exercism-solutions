import java.awt.*;

class Bob {

    private boolean isUppercase(String input) {
        if (input.isBlank())
            return false;

        input = input.chars().filter(Character::isLetter).collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append).toString();

        System.out.println(input);

        if (input.isEmpty())
            return false;

        for (char c : input.toCharArray())
            if (Character.isLowerCase(c))
                return false;

        return true;
    }

    private boolean isQuestion(String input) {
        input = input.trim();
        return input.isBlank() ? false : input.charAt(input.length() - 1) == '?';
    }

    String hey(String input) {
        boolean isUpper = isUppercase(input), isQuestion = isQuestion(input);

        if (isUpper && isQuestion){
            return "Calm down, I know what I'm doing!";
        } else if (isUpper) {
            return "Whoa, chill out!";
        } else if (isQuestion) {
            return "Sure.";
        } else if (input.isBlank()){
            return "Fine. Be that way!";
        }

        return "Whatever.";
    }
}