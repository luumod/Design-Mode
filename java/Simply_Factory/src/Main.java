public class Main {
    public static void main(String[] args){
        AbstractProduct pro = AbstractFactroy.create(Type.Plane);
        pro.makeProduct();
        pro = AbstractFactroy.create(Type.Rocket);
        pro.makeProduct();
    }
}