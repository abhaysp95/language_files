<html>
	<head><h1>Create Session Variable</h1></head>
	<body>
		<%
		session.setAttribute("var", "1");
		session.setMaxInactiveInterval(2);
		%>
	</body>
</html>
