// main file

#include <iostream>
#include <string>
#include <mysql/mysql.h>

struct connection_details {
	std::string server;
	std::string user;
	std::string password;
	std::string database;
};

MYSQL* mysql_connection_setup(struct connection_details mysql_details) {
	// first create a mysql instance and initialize the variables of it
	MYSQL* connection = mysql_init(NULL);
	// connect to the database with the details attached
	if (!mysql_real_connect(connection, mysql_details.server.c_str(),
				mysql_details.user.c_str(), mysql_details.password.c_str(),
				mysql_details.database.c_str(), 0, NULL, 0)) {
		std::cout << "Connection error: %s\n" << mysql_error(connection) << std::endl;
		exit(1);
	}
	return connection;
}

MYSQL_RES* mysql_perform_query(MYSQL* connection, char* sql_query) {
	// send the query to the database
	if (mysql_query(connection, sql_query)) {
		std::cout << "MYSQL query error: " << mysql_error(connection) << std::endl;
		exit(1);
	}
	return mysql_use_result(connection);
}

int main(int argc, char **argv) {
	MYSQL* connection;  // the connection
	MYSQL_RES* res; // the results
	MYSQL_ROW row; // the result's rows

	struct connection_details my_connection;
	my_connection.server = "127.0.0.1";
	my_connection.user = "<enter you user name here>";
	my_connection.password = "<enter password for that user here>";
	my_connection.database = "information_schema";

	// connect to database
	connection = mysql_connection_setup(my_connection);

	res = mysql_perform_query(connection, (char*)"show tables");
	std::cout << "Tables in provided mysql database are: " << std::endl;
	while ((row = mysql_fetch_row(res)) != NULL) {
		std::cout << row[0] << std::endl;
	}
	// cleanup database result
	mysql_free_result(res);
	// cleanup database link(connection)
	mysql_close(connection);
	return 0;
}