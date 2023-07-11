public class LenovoComputer extends AbstractBuilder{
    private Computer computer;
    public LenovoComputer(String cpu, String ram){
        computer = new Computer(cpu,ram);
    }
    @Override
    public void setMouse(){
        computer.setMouse("联想键盘");
    }

    @Override
    public void setDisplay() {
        computer.setDisplay("联想显示器");
    }
    @Override
    public Computer getProduct(){
        return computer;
    }
}
