public class RealImage implements Image{
    private String fileName;
    public RealImage(String name){
        fileName = name;
        loadImage(name);
    }
    public void loadImage(String name){
        System.out.println("加载图片 " + name);
    }
    @Override
    public void display(){
        System.out.println("显示图片");
    }
}
