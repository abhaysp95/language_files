import java.sql.*;

Class.forName("com.mysql.jdbc.Driver");
String cs = "jdbc:mysql://localhost:3306/database-name";
Connection con = DriverManager.getConnection(cs,uid,pwd);
Statement stmt = con.createStatement();
//stmt.executeUpdate("show tables;");  // data fetch
ResultSet rs = stmt.executeQuery("show tables;");  // only data fetch
stmt.executeUpdate("insert into tb1 values(1, 2, 3)");  // data updation
