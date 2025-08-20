class Darts {
    final static double outerCircleRadius = 10;
    final static double middleCircleRadius = 5;
    final static double innerCircleRadius = 1;

    int score(double xOfDart, double yOfDart) {
        double distanceFromCenter = Math.sqrt(xOfDart * xOfDart + yOfDart * yOfDart);
        
        if (distanceFromCenter <= innerCircleRadius){
            return 10;
        } else if (distanceFromCenter <= middleCircleRadius) {
            return 5;
        } else if (distanceFromCenter <= outerCircleRadius) {
            return 1;
        }

        return 0;
    }
}
