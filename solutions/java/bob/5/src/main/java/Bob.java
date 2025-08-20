class Bob {

    private boolean isUppercase(String input) {
        return input.chars().anyMatch(Character::isLetter) && input.equals(input.toUpperCase());
    }

    String hey(String input) {
        String trimmedInput = input.trim();
        boolean isQuestion = trimmedInput.endsWith("?"),
                isUppercase = isUppercase(trimmedInput);

        if (trimmedInput.isBlank())
            return "Fine. Be that way!";

        if (isUppercase && isQuestion)
            return "Calm down, I know what I'm doing!";

        if (isUppercase)
            return "Whoa, chill out!";

        if (isQuestion)
            return "Sure.";

        return "Whatever.";
    }
}