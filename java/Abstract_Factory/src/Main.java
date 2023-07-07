public class Main {
    public static void main(String[] args) {
        /*
        ----------------第一次绘制 ----------------
        绘制矩形
        填充红色
        填充蓝色
        填充黄色
        ----------------第二次绘制 ----------------
        绘制三角形
        填充红色
        填充蓝色
        ----------------第三次绘制 ----------------
        绘制圆形
        绘制三角形
        填充黄色
        */
        AbstractFactory shapefact = FactoryGenerator.getFactory(Factory.ShapeFactory);
        AbstractFactory colorfact = FactoryGenerator.getFactory(Factory.ColorFactory);

        System.out.println("----------------第一次绘制 ----------------");
        AbstractShape shape = shapefact.getShape(Shape.Rectangle);
        AbstractColor color = colorfact.getColor(Color.Red);
        shape.draw();
        color.fill();
        color = colorfact.getColor(Color.Blue);
        color.fill();
        color = colorfact.getColor(Color.Yellow);
        color.fill();

        System.out.println("5352353252");
        shape = shapefact.getShape(Shape.Triangle);
        shape.draw();
        color = colorfact.getColor(Color.Red);
        color.fill();
        color = colorfact.getColor(Color.Blue);
        color.fill();

        System.out.println("----------------第三次绘制 ----------------");
        shape = shapefact.getShape(Shape.Circle);
        shape.draw();
        shape = shapefact.getShape(Shape.Triangle);
        shape.draw();
        color = colorfact.getColor(Color.Yellow);
        color.fill();
    }
}