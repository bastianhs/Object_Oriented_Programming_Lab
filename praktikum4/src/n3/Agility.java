public class Agility extends Hero {
    Agility() {}
    Agility(Integer level) {
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Agility Hero (Lvl " + level.toString() + ")");
    }

    public Double value() {
        return level.doubleValue() + 0.3;
    }
}
