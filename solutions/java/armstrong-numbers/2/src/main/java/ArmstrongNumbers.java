class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        int numCpy = numberToCheck, result = 0;
        int digitCount = String.valueOf(numberToCheck).length();

        while (numCpy > 0){
            int digit = numCpy % 10;
            result += (int) Math.pow(digit, digitCount);
            numCpy /= 10;
        }

        return result == numberToCheck;
    }

}
