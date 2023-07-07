public class ShapeFactory extends AbstractFactory{
    @Override
    public AbstractShape getShape(Shape type){
        if (type == Shape.Circle){
            return new Circle();
        }
        else if (type == Shape.Triangle){
            return new Triangle();
        }
        else if (type == Shape.Rectangle){
            return new Rectangle();
        }
        return null;
    }
    @Override
    public AbstractColor getColor(Color type){
        return null;
    }
}
