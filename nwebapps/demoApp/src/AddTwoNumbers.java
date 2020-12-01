package com.server;

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletContext;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Cookie;
import javax.servlet.ServletException;
import javax.servlet.RequestDispatcher;

public class AddTwoNumbers extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException, ServletException {
		int i = Integer.parseInt(req.getParameter("num1"));
		int j = Integer.parseInt(req.getParameter("num2"));
		int k = i + j;
		PrintWriter out = res.getWriter();
		out.println("<html><body><h2>");
		out.println("result is: " + k);
		// or just do, res.getWriter().println();

		// to call the second servlet we have two options
		// RequestDispatcher and Redirect

		// We can send data between servlets using concept of session
		// management which is one of the many ways

		// To send data to SqServlet, we can just use RequestDispatcher, as
		// it's already forwarding our requesting to SqServlet
		// req object is already getting forwarded, so we'll just put data to request object
		//req.setAttribute("k", k);  // key -> value

		// getRequestDispatcher is the instance of interface RequestDispatcher,
		// and you basically pass path(url pattern) as method argument
		//RequestDispatcher rd = req.getRequestDispatcher("sq");  // sq is now known from web.xml
		//rd.forward(req, res);
		// Using this will also throw ServletException

		// With RequestDispatcher client(browser) doesn't knows about any
		// redirection, Request from one servlet with request and response
		// object is sent to another servlet. Also, this is good and works when
		// you have multiple servlets on same website

		// We have sendRedirect() method to this, in which browser is informed
		// about redirection and client(browser) does the redirection, so we
		// have basically two request and response object, one for each
		// servlet, and the data from one servlet to another will passed
		// through concept of session management

		//res.sendRedirect("sq?k=" + k);  // tells the client to got to following path(url)
		// this says, go to sq and give k = (value of)k, this technique comes
		// under URL rewriting, we have to more ways, session and cookies

		// Now, there's a better way and beneficial another way to pass the
		// k(or something else), tomcat server tries to maintain the session
		// for us, session will be there throughout the website, we can use that
		//HttpSession session = req.getSession();  // HttpSession is interface for which tomcat will provide session
		//session.setAttribute("k", k);

		// Let's now work with cookies, cookies are first sent from server and then are recieved back from client
		//Cookie cookie = new Cookie("k", Integer.valueOf(k).toString());  // both arguments require string
		//or just do k + "" to make string
		//res.addCookie(cookie);
		//res.sendRedirect("sq");




		/*
		 * ServletConfig & ServletContext
		 */



		out.println("<br>Hii<br><br>");
		ServletContext ctx = getServletContext();
		String name = ctx.getInitParameter("Name");
		out.println("I'm " + name + "<br>");
		String phone = ctx.getInitParameter("Phone");
		out.println("I'm using phone of: " + phone + "<br>");



		/* If you have multiple servlets and want to share same
		 * parameter(value) from xml, use ServletContext else ServletConfig */











		out.println("</h2></body></html>");








	}

	// you get two more methodsto work with(inplace of service()), doGet and
	// doPost which can be used
	// using doPost will be beneficial cause, a user can just change
	// method="get" from "post" in browser, so you can decide here if you want
	// to work with get or post

	// with HTTP protocol we have 7 methods(5 methods used mostly) and
	// HttpServlet provides method for those like doGet(), doPost(), doPut(),
	// doDelete() etc.

	// Even using doGet() or doPost() service() is called which decides if doGet() is used or doPost()

	// We can have different functionalities for doGet() and doPost() at the same time
	//public void doGet(HttpServletRequest req, HttpServletResponse res) throws IOException {
		//PrintWriter out = res.getWriter();
		//out.println("Will not work with GET HTTP protocol");
	//}
}
