<html>
	<head>Session 3</head>
	<body>
		<br>
		<%
		String s = (String) session.getAttribute("uid");
		if (s != null) {
		%>
		<h2>Got Value: <%= s%></h2>
		<%
		}
		else {
		response.sendRedirect("session4.jsp");
		}
		%>
	</body>
</html>
