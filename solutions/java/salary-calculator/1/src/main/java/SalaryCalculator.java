public class SalaryCalculator {

    private final int baseSalary = 1000;

    public double salaryMultiplier(int daysSkipped) {
        return daysSkipped >= 5 ? 0.85 : 1;
    }

    public int bonusMultiplier(int productsSold) {
        return productsSold >= 20 ? 13 : 10;
    }

    public double bonusForProductsSold(int productsSold) {
        return productsSold * bonusMultiplier(productsSold);
    }

    public double finalSalary(int daysSkipped, int productsSold) {
        double finalSalary = (double) baseSalary
                * salaryMultiplier(daysSkipped)
                + bonusForProductsSold(productsSold);

        return finalSalary > 2000 ? 2000 : finalSalary;
    }
}
