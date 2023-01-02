// a mocked database

#include "db.hpp"

#include <cstring>
#include <string>
#include <memory>
#include <vector>

namespace {
	class QueryResult {
		public:
			size_t index{};

			QueryResult()
				: index{0} {}
			std::vector<std::vector<const char*>> data;
	};

	class Database {
		private:
			bool connected;

		public:
			Database()
				: connected{false} {}

			bool hasConnection() const {
				return this->connected;
			}
			void connect() {
				this->connected = true;
			}
			void disconnect() {
				this->connected = false;
			}

			QueryResult* query(const char* query);
	};
};

DB_CONNECTION* db_connect() {
	// we only have one single database, which allows only one single
	// connection
	static Database theDatabase;

	if (theDatabase.hasConnection()) {
		return nullptr;
	} else {
		theDatabase.connect();
		return &theDatabase;
	}
}

void db_disconnect(DB_CONNECTION *connection) {
	// reinterpret_cast<> is used to cast between pointers/references of
	// unrelated types (such as void* and Database*)

	// ((Database*)(connection))->disconnect();  // or use below
	reinterpret_cast<Database*>(connection)->disconnect();
}

DB_QUERY_RESULT* db_query(DB_CONNECTION* connection, const char* query) {
	return reinterpret_cast<Database*>(connection)->query(query);
}

QueryResult* Database::query(const char *query) {
	if (!hasConnection()) {
		return nullptr;
	}

	// our database only understands single query
	const char* def_query {"SELECT * FROM CUSTOMER_TABLE"};
	if (std::strncmp(query, def_query, std::strlen(def_query)) != 0) {
		return nullptr;
	}

	std::unique_ptr<QueryResult> result = std::make_unique<QueryResult>();
	result->data = std::vector<std::vector<const char*>> {
		{ "Sherlock", "Holmes", "Baker Street", "B221", "London" },
		{ "Donald", "Trump", "Pennsylvania Avenue", "1600", "Washington DC" },
		{ "Donald", "Duck", "Webfoot Walk", "1313", "Duckville" },
		{ "Sirius", "Black", "Grimmauld Place", "12", "London" },
		{ "Nemo", "Clownfish", "Wallaby Way", "42", "Sydney" },
		{ "Sam", "Malone", "Beacon Street", "112", "Boston" }
	};

	return result.release();
}

int db_num_fields(DB_QUERY_RESULT* result) {
	QueryResult* the_result = reinterpret_cast<QueryResult*>(result);

	if (!the_result || the_result->data.empty()) {
		return -1;
	} else {
		return static_cast<int>(the_result->data.front().size());
	}
}

DB_ROW db_fetch_row(DB_QUERY_RESULT *result) {
	QueryResult* the_result = reinterpret_cast<QueryResult*>(result);

	if (!the_result || the_result->data.empty()) {
		return nullptr;
	} else {
		return the_result->data[the_result->index++].data();
	}
}

void db_free_result(DB_QUERY_RESULT *result) {
	delete reinterpret_cast<QueryResult*>(result);
}
