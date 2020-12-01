<%
String s = request.getParameter("t1");
if (s != null) {
if (s.equals("123")) {
session.setAttribute("uid", s);
session.setMaxInactiveInterval(4);
out.println("Reached here");
response.sendRedirect("session3.jsp");
}
else {
response.sendRedirect("session1.jsp?f=1");
}
}
else {
response.sendRedirect("session1.jsp?f=2");
}
%>
