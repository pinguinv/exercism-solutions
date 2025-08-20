import java.util.List;

class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        String digits = String.valueOf(numberToCheck);

        return numberToCheck == digits
                .chars()
                .map(ch -> (int) Math.pow(Character.getNumericValue(ch), digits.length()))
                .sum();
    }

}
