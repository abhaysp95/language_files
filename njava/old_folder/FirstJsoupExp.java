import java.io.IOException;
import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
public class FirstJsoupExp{
    public static void main(String[] args)throws IOException{
        Document doc;
        doc = Jsoup.connect("http://www.javatpoint.com").get();
        String title = doc.title();
        System.out.println("Title is : "+title);
    }
}