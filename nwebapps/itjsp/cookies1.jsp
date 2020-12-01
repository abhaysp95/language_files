<%
Cookie cookie = new Cookie("uid", "5");
Cookie cookie2 = new Cookie("uuid", "10");
cookie.setMaxAge(1);  // value in minute
out.println("Cookies created");
response.addCookie(cookie);
response.addCookie(cookie2);
// response.sendRedirect("cookies2.jsp");
%>
<%--<  cookies is request and response based unlike session where you can
access on any page of existing session >--%>
