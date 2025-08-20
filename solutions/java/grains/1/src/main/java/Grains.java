import java.math.BigInteger;

class Grains {

    BigInteger grainsOnSquare(final int square) {
        if (square > 64 || square < 1)
            throw new IllegalArgumentException("square must be between 1 and 64");
        return BigInteger.valueOf(2).pow(square-1);
    }

    BigInteger grainsOnBoard() {
        return new BigInteger("1").shiftLeft(64).subtract(new BigInteger("1"));
    }

}
