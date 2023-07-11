import javax.crypto.MacSpi;

public class MacComputer extends AbstractBuilder{
    private Computer computer;
    MacComputer(String cpu,String ram){
        computer = new Computer(cpu,ram);
    }
    @Override
    public void setMouse() {
        computer.setMouse("苹果鼠标");
    }

    @Override
    public void setDisplay() {
        computer.setDisplay("苹果显示器");
    }

    @Override
    public Computer getProduct() {
        return computer;
    }
}
