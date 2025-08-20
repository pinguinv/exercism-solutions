class SpaceAge {

    final static int secondsInYear = 31_557_600;

    final static double orbitalPeriodMercury = 0.2408467;
    final static double orbitalPeriodVenus = 0.61519726;
    final static double orbitalPeriodEarth = 1.0;
    final static double orbitalPeriodMars = 1.8808158;
    final static double orbitalPeriodJupiter = 11.862615;
    final static double orbitalPeriodSaturn = 	29.447498;
    final static double orbitalPeriodUranus = 84.016846;
    final static double orbitalPeriodNeptune = 164.79132;

    private final double seconds;

    SpaceAge(double seconds) {
        this.seconds = seconds;
    }

    double onEarth() {
        return this.seconds / secondsInYear / orbitalPeriodEarth;
    }

    double onMercury() {
        return this.seconds / secondsInYear / orbitalPeriodMercury ;
    }

    double onVenus() {
        return this.seconds / secondsInYear / orbitalPeriodVenus;
    }

    double onMars() {
        return this.seconds / secondsInYear / orbitalPeriodMars;
    }

    double onJupiter() {
        return this.seconds / secondsInYear / orbitalPeriodJupiter;
    }

    double onSaturn() {
        return this.seconds / secondsInYear / orbitalPeriodSaturn;
    }

    double onUranus() {
        return this.seconds / secondsInYear / orbitalPeriodUranus;
    }

    double onNeptune() {
        return this.seconds / secondsInYear / orbitalPeriodNeptune;
    }

}
