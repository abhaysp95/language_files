<html>
	<head><h1>Create Session Variable</h1></head>
	<body>
		<%
		try {
			String i = (String) session.getAttribute("var")
			if (i != null) {
			%>
			<h2><%= i%></h2>
			<% }
		}
		catch (Exception e) {}
		%>
	</body>
</html>
