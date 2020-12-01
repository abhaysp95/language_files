<html>
	<head></head>
	<body>
		<form action="session2.jsp" method="get">
			<input type="text" name="t1"/>
			<input type="submit" value="submit"/>
			<%
			String s = request.getParameter("f");
			if (s != null) {
			if (s.equals("1")) {
			out.println("value incorrect");
			}
			else if (s.equals("2")) {
			out.println("no value passed");
			}
			}
			%>
		</form>
	</body>
</html>
