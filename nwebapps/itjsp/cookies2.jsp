<%
Cookie[] cookieArr = request.getCookies();
if (cookieArr != null) {
// only showing one cookie(uuid)
	for (Cookie cookie: cookieArr) {
		out.println("Name: " + cookie.getName() + ", Value: " + cookie.getValue());
	}
}
%>
