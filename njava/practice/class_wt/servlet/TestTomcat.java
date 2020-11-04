import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;

public class TestTomcat extends HttpServlet {

	public void doGet(HttpServletRequest req, HttpServletRequest res)
		throws ServletException, IOException {
		// or you can use try-catch block to handle exception
		res.setContentType("text/html");
		PrintWriter pw = res.getWriter();  // returns object of PrintWriter
		pw.println("<html>"
			+ "<head></head>"
			+ "<body><h1>Welocome to Servlet</h1></body>"
			+ "</html>");
		pw.close();
	}
}
