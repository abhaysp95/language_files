<%@ page import = "java.io.*" %>
<%@ include file = "testInc.jsp" %>
<html>
	<body>
		<%
		int a;
		for (a = 1; a < 10; ++a) {
		out.print(a + "<br>");
		}
		%>
	</body>
</html>
