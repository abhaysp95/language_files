import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.PrintWriter;
import java.io.IOException;

public class GetValue extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		//int num1 = Integer.parseInt(req.getParameter("num1"));
		//int num2 = Integer.parseInt(req.getParameter("num2"));
		String val = req.getParameter("t1");
		//PrintWriter pw = res.getWriter();
		//pw.println("sum is: " + (num1 + num2));
		//pw.println("<h1> Value is(from get): " + val + " </h1>");
		//pw.close();
		res.sendRedirect("sqadd");
	}

	public void doPost(HttpServletRequest req, HttpServletResponse res) throws IOException {
		String val = req.getParameter("t2");
		PrintWriter pw = res.getWriter();
		pw.println("<h1> Value is(from post): " + val + " </h1>");
		pw.close();
	}
}
