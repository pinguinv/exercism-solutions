class DifferenceOfSquaresCalculator {

    int computeSquareOfSumTo(int input) {
        int result = 0;
        for(int i = 1; i <= input; i++){
            result += i;
        }
        result *= result;
        return result;
    }

    int computeSumOfSquaresTo(int input) {
        int result = 0;
        for(int i = 1; i <= input; i++){
            result += i * i;
        }
        return result;
    }

    int computeDifferenceOfSquares(int input) {
        int result = computeSquareOfSumTo(input) - computeSumOfSquaresTo(input);
        return result;
    }

}
