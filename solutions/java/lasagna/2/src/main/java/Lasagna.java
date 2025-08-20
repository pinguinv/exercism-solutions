public class Lasagna {
    public int expectedMinutesInOven(){
        return 40;
    }

    public int remainingMinutesInOven(int currentTimeInOven){
        return expectedMinutesInOven() - currentTimeInOven;
    }

    public int preparationTimeInMinutes(int preparedLayers){
        return  preparedLayers * 2;
    }

    public int totalTimeInMinutes(int preparedLayers, int currentTimeInOven){
        return this.preparationTimeInMinutes(preparedLayers) + currentTimeInOven;
    }
}
