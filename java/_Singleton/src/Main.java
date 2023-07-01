public class Main {
    public static void main(String[] args) {
        Singleton p1 = Singleton.getInstance();
        Singleton p2 = Singleton.getInstance();
        System.out.println(p1);
        System.out.println(p2);
        p1.testOperation();
        p2.testOperation();
    }
}