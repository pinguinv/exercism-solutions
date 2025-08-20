class BirdWatcher {
    private final int[] birdsPerDay;

    public BirdWatcher(int[] birdsPerDay) {
        this.birdsPerDay = birdsPerDay.clone();
    }

    public int[] getLastWeek() {
        return birdsPerDay;
    }

    public int getToday() {
        return birdsPerDay[birdsPerDay.length-1];
    }

    public void incrementTodaysCount() {
        birdsPerDay[birdsPerDay.length-1] += 1;
    }

    public boolean hasDayWithoutBirds() {
        for (int birdsThisDay : birdsPerDay)
            if (birdsThisDay == 0) return true;

        return false;
    }

    public int getCountForFirstDays(int numberOfDays) {
        int count = 0;

        for (int i = 0; i < numberOfDays && i < birdsPerDay.length; i++)
            count += birdsPerDay[i];

        return count;
    }

    public int getBusyDays() {
        int busyDaysCounter = 0;

        for (int birdsThisDay : birdsPerDay)
            if (birdsThisDay >= 5) busyDaysCounter++;

        return busyDaysCounter;
    }
}
