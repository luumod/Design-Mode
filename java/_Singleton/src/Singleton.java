public class Singleton {
    private Singleton(){}
    private static Singleton obj=null;
    public static Singleton getInstance(){
        if (obj==null){
            obj = new Singleton();
        }
        return obj;
    }
    public void testOperation(){
        System.out.println("进行操作...");
    }
}
