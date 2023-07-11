public class Main {
    public static void main(String[] args) {
        Director director = new Director();
        AbstractBuilder builder = new LenovoComputer();
        director.makeComputer(builder);
        Computer Lenovo = builder.getProduct();
        Lenovo.showInfo();

        builder = new MacComputer("I7处理器","海力士222");
        director.makeComputer(builder);
        Computer mac = builder.getProduct();
        mac.showInfo();
    }
}