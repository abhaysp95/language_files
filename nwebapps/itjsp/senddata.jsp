<html>
	<body>
		<form action="senddata2.jsp" method="post">
			<br>
			input:
			<input type="text" name="t1"/>
			<input type="submit" value"submit"/>
			<br>
			<br>
			<br>
			<%
			// if (request.getParameter("x") != null) {
			// if (request.getParameter("x").equals("false")) {

			// you have to first check for null, cause at starting this page
			// isn't recieving x as parameter
			String s = request.getParameter("x");
			if (s != null) {
			if (s.equals("false")) {
			%>
			<h2 style="color:red">Wrong Password, buddy !!</h2>
			<%
			}
			else {
			%>
			<h2 style="color:yellow;display:inline">What the</h2>
			<h2 style="color:red;display:inline"> heck </h2>
			<h2 style="color:yellow;display:inline">did I just got back ?</h2>
			<br>
			<br>
			<h2 style="color:green">What is this ?, <%
				out.println('"' + request.getParameter("x") + '"');
				%></h2>
			<%
			}
			}
			%>
		</form>
	</body>
</html>
