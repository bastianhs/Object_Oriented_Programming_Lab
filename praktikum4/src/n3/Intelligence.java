public class Intelligence extends Hero {
    Intelligence() {}
    Intelligence(Integer level) {
        super(level);
    }

    @Override
    public void printInfo() {
        System.out.println("Intelligence Hero (Lvl " + level.toString() + ")");
    }

    public Double value() {
        return level.doubleValue() + 0.1;
    }
}
