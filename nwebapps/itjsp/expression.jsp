<%! int a = 2; %>
<html>
	<body>
		<%
		out.print(a + "<br>");
		%>
		<%= a %>
		<br>
		<%= a*a %>
		<br>
		<br>
		<%--< let's see benefit of printing like this >--%>
		<input type="text" value="value:  <%= a*a%>"/>
		<br>
		<br>
		<select>
			<option value="<%= a %>"><%= a %></option>
			<option value="<%= a*a %>"><%= a*a %></option>
			<option value="<%= a*a*a %>"><%= a*a*a %></option>
			<option value="<%= a*a*a*a %>"><%= a*a*a*a %></option>
			<option value="<%= a*a*a*a*a %>"><%= a*a*a*a*a %></option>
		</select>
		<br>
		<br>
		<br>
		<br>
		<%
		int a = 1;
		while (a < 11) {
		out.print(a++ + "<br>");
		}
		/** textbox with scriptlet */
		while (a < 21) {
		out.print("<br><input type='text' value='" + a++ + "'/>");
		}
		%>
		<br>
		<br>
		<input type="text" value="<%= a%>"/>

		<%--< or break the scriptlet >--%>

		<% while (a < 31) { %>
		<br>
		<input type="text" value="<%= a++%>"/>
		<%} %>

		<% int c = 11;
		if (c % 2 == 0) { %>
		<h2 style="color:blue">even</h2>
		<%}
		else { %>
		<h2 style="color:green">odd</h2>
		<%} %>

		<%--< so breaking scriptlet resolves the problem of printing html with out.print() >--%>

	</body>
</html>
