import java.util.ArrayList;
import java.util.List;

public class Article implements Prototype{
    private List<String> parts;
    Article(){
        parts = new ArrayList<String>();
    }
    Article(List<String> parts){
        this.parts = parts;
    }
    public void load(){
        parts.clear();
        parts.add("老夫聊发少年狂，左牵黄，右擎苍，锦帽貂裘，千骑卷平冈。\n");
        parts.add("为报倾城随太守，亲射虎，看孙郎。\n");
        parts.add("酒酣胸胆尚开张，鬓微霜，又何妨！持节云中，何日遣冯唐？\n");
        parts.add("会挽雕弓如满月，西北望，射天狼。\n");
    }
    public void showContent(){
        System.out.println(parts.toString());
    }
    @Override
    public Prototype clone(){
        return new Article(parts);
    }
}
