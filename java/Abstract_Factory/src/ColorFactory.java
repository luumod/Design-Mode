public class ColorFactory extends AbstractFactory{
    @Override
    public AbstractShape getShape(Shape type){
        return null;
    }
    @Override
    public AbstractColor getColor(Color type){
        if (type == Color.Red){
            return new Red();
        }
        else if (type == Color.Blue){
            return new Blue();
        }
        else if (type == Color.Yellow){
            return new Yellow();
        }
        return null;
    }
}
