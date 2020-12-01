package com.server;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Cookie;

public class SqServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {

		//int k = (int) req.getAttribute("k");  // getAttribute() returns object
		//k *= k;

		//System.out.println("Sq called");

		//int k = Integer.parseInt(req.getParameter("k"));  // getAttribute() returns object

		//HttpSession session = req.getSession();
		// you can also remove values from session once you get hold of it,
		// like you can remove k with:
		//session.removeAttribute("k");
		//int k = (int) session.getAttribute("k");

		int k = 0;

		Cookie[] cookies = req.getCookies();
		for (Cookie c: cookies) {
			if (c.getName().equals("k")) {
				k = Integer.parseInt(c.getValue());
			}
		}

		k *= k;
		PrintWriter out = res.getWriter();
		//out.println("Square of addition of two numbers: " + k);
		out.println("<html>"
				+ "<body><h1> Square of addition of two numbers: "
				+ k + "</h1></body>"
				+ "</html>");
	}
}
