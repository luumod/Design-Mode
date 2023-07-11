public class Computer {
    private String cpu;
    private String ram;
    private String mouse;
    private String display;
    Computer(String cpu,String ram){
        this.cpu = cpu;
        this.ram = ram;
    }
    void setMouse(String mouse){
        this.mouse = mouse;
    }
    void setDisplay(String display){
        this.display = display;
    }
    void showInfo(){
        System.out.println("电脑基本信息: " + cpu + ", " + ram + ", " + mouse + ", " + display);
    }
}
