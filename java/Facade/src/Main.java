package src;

public class Main{
    public static void main(String args[]){
        FacadeShape f = new FacadeShape(new Circle(), new Rect(), new Triangle());
        f.build();
    }
}