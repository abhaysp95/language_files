<%@ page import="java.sql.*"%>
<html>
	<head>
		<style>
			td {
				border-style: solid;
				border-width: 3px;
				border-color: grey;
				padding: 5px;
				font-size: 30px;
			}
			.insert {
				color: green;
				background-color: grey;
			}
		</style>
	</head>
<body>
	<!-- leave blank action to return back to this page or put the name of this page -->
	<form action="" method="get">
		<input type="text" name="id"/>
		<input type="text" name="name"/>
		<input type="submit" id="insert" name="insert"/>
	</form>
	<form action="" method="get">
		<input type="text" name="did"/>
		<input type="submit" name="delete"/>
	</form>
<%--after submission we are comming back to this page again--%>
<%
String putName = request.getParameter("name");
String sPutId = request.getParameter("id");
// out.print("id: " + putId + ", name: " + putName);
Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/itjsp", "clg_prac", "clg_prac@mysql");
Statement stmt = con.createStatement();

// insert data
try {
	int putId = Integer.parseInt(sPutId);
	PreparedStatement ps = con.prepareStatement("insert into std values(?, ?)");
	ps.setInt(1, putId);
	ps.setString(2, putName);
	ps.executeUpdate();
	sPutId = null;
	putName = null;
}
catch (Exception e) {}
/* problem: everytime on reloading the page previous value gets inserted again */

// delete data
try {
	int delID = Integer.parseInt(request.getParameter("did"));
	int res = stmt.executeUpdate("delete from std where id=" + delID);
}
catch (Exception e) {}
ResultSet rs = stmt.executeQuery("select * from std");
out.print("<table>");
	while (rs.next()) {
		out.print("<tr>");
		out.print("<td>" + rs.getInt(1) + "</td>");
		out.print("<td>" + rs.getString(2) + "</td>");
		out.print("</tr>");
	}
out.print("</table>");
%>
</body>
</html>
