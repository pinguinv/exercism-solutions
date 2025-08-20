public class JedliksToyCar {

    private int distanceDriven;
    private int batteryLevel;

    public JedliksToyCar() {
        this.distanceDriven = 0;
        this.batteryLevel = 100;
    }

    public static JedliksToyCar buy() {
        return new JedliksToyCar();
    }

    public String distanceDisplay() {
        return "Driven " + this.distanceDriven + " meters";
    }

    public String batteryDisplay() {
        return "Battery " + (this.batteryLevel > 0 ? "at " + this.batteryLevel + "%" : "empty") ;
    }

    public void drive() {
        if (batteryLevel > 0) {
            this.distanceDriven += 20;
            this.batteryLevel -= 1;
        }
    }
}
