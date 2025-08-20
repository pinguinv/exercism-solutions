public class CarsAssemble {

    public double productionRatePerHour(int speed) {
        double productionRate = 221 * speed;

        if (speed >= 5 && speed <= 8)
            productionRate = productionRate * 0.9;
        else if (speed == 9)
            productionRate = productionRate * 0.8;
        else if (speed == 10)
            productionRate = productionRate * 0.77;

        return productionRate;
    }

    public int workingItemsPerMinute(int speed) {
        return (int) (productionRatePerHour(speed)/60);
    }
}
