<%@page import="java.sql.*"%>
<%
Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/itjsp", "clg_prac", "clg_prac@mysql");
Statement stmt = con.createStatement();
PreparedStatement ps = con.prepareStatement("insert into std values(?, ?)");

// first param is position of question-mark(?) in ps and second is the value to insert in that postition
ps.setInt(1, 4);
ps.setString(2, "c"); // check here

int i = ps.executeUpdate();
if (i > 0) {
	out.print("value inserted");
}

ResultSet rs = stmt.executeQuery("select * from std");
while (rs.next()) {
out.println("<br>" + rs.getInt(1));
out.println(rs.getString(2) + "<br>");
}
con.close();
%>
