public class Main {
    public static void main(String[] args){
        Article a = new Article();
        a.load(); //加载内容
        a.showContent();

        Article b = (Article) a.clone(); //强转
        b.showContent();
    }
}