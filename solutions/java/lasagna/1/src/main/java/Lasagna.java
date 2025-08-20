public class Lasagna {
    private final int expectedTimeInOven = 40;
    // TODO: define the 'expectedMinutesInOven()' method
    public int expectedMinutesInOven(){
        return expectedTimeInOven;
    }
    // TODO: define the 'remainingMinutesInOven()' method
    public int remainingMinutesInOven(int currentTimeInOven){
        return expectedTimeInOven - currentTimeInOven;
    }

    // TODO: define the 'preparationTimeInMinutes()' method
    public int preparationTimeInMinutes(int preparedLayers){
        return  preparedLayers * 2;
    }

    // TODO: define the 'totalTimeInMinutes()' method
    public int totalTimeInMinutes(int preparedLayers, int currentTimeInOven){
        return this.preparationTimeInMinutes(preparedLayers) + currentTimeInOven;
    }
}
