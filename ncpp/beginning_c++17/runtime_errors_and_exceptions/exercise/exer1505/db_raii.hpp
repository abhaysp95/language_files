#ifndef _DB_RAII_HPP
#define _DB_RAII_HPP

/* using DB_CONNECTION = void;
using DB_QUERY_RESULT = void;
using DB_ROW = const char**;

// make connection to database
DB_CONNECTION* db_connect();

// query the database
DB_QUERY_RESULT* db_query(DB_CONNECTION* connection, const char* query);

// retrieve the number of fields per row stored in the given query result
int db_num_fields(DB_QUERY_RESULT* result);

// fetch a single row from the result
DB_ROW db_fetch_row(DB_QUERY_RESULT* result);

// release the memory allocated for the result
void db_free_result(DB_QUERY_RESULT* result);

// disconnect from database
void db_disconnect(DB_CONNECTION* connection); */

#include "db.hpp"

class DBConnectionRAII {
	private:
		DB_CONNECTION* theConnection;

	public:
		DBConnectionRAII(DB_CONNECTION* conn) noexcept
			: theConnection{conn} {}

		~DBConnectionRAII() {  // implicitly noexcept
			db_disconnect(theConnection);
		}

		operator DB_CONNECTION*() const noexcept {
			return theConnection;
		}
		operator bool() const noexcept {
			return theConnection != nullptr;
		}
};

class DBQueryResultRAII {
	private:
		DB_QUERY_RESULT* theResult;

	public:
		DBQueryResultRAII(DB_QUERY_RESULT* result) noexcept
			: theResult{result} {}
		~DBQueryResultRAII() {
			db_free_result(theResult);
		}

		operator DB_QUERY_RESULT*() const noexcept {
			return theResult;
		}
		operator bool() const noexcept {
			return theResult != nullptr;
		}
};

#endif
