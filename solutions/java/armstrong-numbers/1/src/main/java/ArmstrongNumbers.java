class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {
        int numCpy = numberToCheck, digitCount = 0, result = 0;

        while (numCpy > 0) {
            digitCount++;
            numCpy /= 10;
        }

        numCpy = numberToCheck;

        while (numCpy > 0){
            int digitToPow = 1;
            for (int i = 0; i < digitCount; i++) {
                digitToPow *= numCpy % 10;
            }
            result += digitToPow;
            numCpy /= 10;
        }

        return result == numberToCheck;
    }

}
