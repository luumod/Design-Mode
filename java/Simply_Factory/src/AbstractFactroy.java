public class AbstractFactroy {
    static public AbstractProduct create(Type type){
        assert(type == Type.Rocket || type == Type.Plane);
        if (type == Type.Plane){
            return new PlaneProduct();
        }
        else if (type == Type.Rocket){
            return new RocketProduct();
        }
        return null;
    }
}
