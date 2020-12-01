<html>
	<body>
		<h1>
			<%
			// s is in page scope
			try {
				String s = request.getParameter("t1");
				if (s.equals("this@is@sparta")) {
					out.print(s);
					%>
					<h2 style="color:green">Access Granted</h2>
					<%
					s += " scriplet working";
				}
				else {
					response.sendRedirect("senddata.jsp?x=false");
				}
			}
			// catch (org.apache.jasper.JasperException e) {
			catch (Exception e) {
				out.println("Password Man, Password !!");
				%>
				<br>
				<br>
				go back to <a href="senddata.jsp">password</a>
				<%
			}
			%>
			<br>
			<br>
			<%--<%= s%>--%>
		</h1>
	</body>
</html>
