<%@ page import="java.sql.*"%>
<html>
	<head></head>
	<body>
		<h1>Table Content</h1>
		<%
		try {
			Class.forName("com.mysql.jdbc.Driver");
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/IT3", "clg_prac", "clg_prac@mysql");
			Statement stmt = con.createStatement();

			/* returns rows affected */
			int i = stmt.executeUpdate("insert into std values(4, 'lmn')");
			int j = stmt.executeUpdate("delete from std where id = 3");
			if (i > 0) {
				out.println("rows affected: " + i);
			}
			if (j > 0) {
				out.println("rows affected: " + j);
			}
			ResultSet rs = stmt.executeQuery("select * from std");  // specially for selection
			rs.next();
			rs.prev();
			while (rs.next()) {
				out.println(rs.getInt(1);)
				out.println(rs.getString(2);)
			}
			con.close();
		}
		catch(Exception e) {}
		%>
	</body>
</html>
