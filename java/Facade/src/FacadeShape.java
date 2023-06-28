package src;

public class FacadeShape{
    private Circle c;
    private Rect r;
    private Triangle t;
    public FacadeShape(Circle c,Rect r,Triangle t){
         this.c=c;
         this.r=r;
         this.t=t;
    }
    public void build(){
        c.draw();
        r.draw();
        t.draw();
        System.out.println("绘制完成! ");
    }
}