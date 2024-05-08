public class Strength extends Hero {
    Strength() {}
    Strength(Integer level) {
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Strength Hero (Lvl " + level.toString() + ")");
    }

    public Double value() {
        return level.doubleValue() + 0.2;
    }
}
