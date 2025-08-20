public class SquareRoot {
    public int squareRoot(int radicand) {
        for (int i = 0; i*i <= radicand; i++)
            if (i*i == radicand)
                return i;

        return -1;
    }
}
