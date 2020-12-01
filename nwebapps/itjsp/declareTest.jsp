<%! int a = 0; %>
<%! void f1() {
	a--;
} %>
<%! class A {
	String f2() {
		a += 5;
		return null;
	}
} %>

<html>
	<head></head>
	<body>
		<%
		out.println("<h1>" + a++ + "</h1>");
		out.println("<h2>");
		f1();
		f1();
		out.println("</h2>");
		A ob = new A();
		out.println("" + ob.f2());
		%>
	</body>
</html>
