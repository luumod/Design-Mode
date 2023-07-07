public class FactoryGenerator {
    public static AbstractFactory getFactory(Factory type){
        if (type == Factory.ShapeFactory){
            return new ShapeFactory();
        }
        else if (type == Factory.ColorFactory){
            return new ColorFactory();
        }
        return null;
    }
}
