public class ProxyImage implements Image{
    private Image image = null;
    public ProxyImage(String name){
        if (image == null){
            image = new RealImage(name);
        }
    }
    @Override
    public void display(){
        System.out.println("显示图片");
    }
}
