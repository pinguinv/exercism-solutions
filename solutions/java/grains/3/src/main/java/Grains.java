import java.math.BigInteger;

class Grains {

    BigInteger grainsOnSquare(final int square) {
        if (square > 64 || square < 1)
            throw new IllegalArgumentException("square must be between 1 and 64");
        return BigInteger.TWO.pow(square-1);
    }

    BigInteger grainsOnBoard() {
        return BigInteger.ONE.shiftLeft(64).subtract(BigInteger.ONE);
    }

}
