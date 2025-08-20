class Bob {

    private boolean isUppercase(String input) {
        return input.chars().anyMatch(Character::isLetter) && input.equals(input.toUpperCase());
    }

    String hey(String input) {
        String trimmedInput = input.trim();

        if (trimmedInput.isBlank())
            return "Fine. Be that way!";

        if (isUppercase(trimmedInput) && trimmedInput.endsWith("?"))
            return "Calm down, I know what I'm doing!";

        if (isUppercase(trimmedInput))
            return "Whoa, chill out!";

        if (trimmedInput.endsWith("?"))
            return "Sure.";

        return "Whatever.";
    }
}