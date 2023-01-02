// creating RAII classes to manage resource handles
// returned by a C interface (every resource should be
// managed by RAII)

#include "db.hpp"
#include "db_raii.hpp"
#include "dbexception.hpp"
#include "customer.hpp"

#include <iostream>
#include <stdexcept>
#include <vector>

void verify_customer_fields(DB_QUERY_RESULT* result);  // sanity check on the number of fields returned by our query
std::vector<Customer> read_customers(DB_QUERY_RESULT* result);  // conver the DB result to a series of C++ objects
void print(std::ostream& stream, const Customer& customer);  // print a given customer to a given output stream

std::ostream& get_output_stream() {
	return std::cout;
}

int main(void) {
	DBQueryResultRAII connection{ db_connect() };

	try {
		DBQueryResultRAII result{ db_query(connection, "SELECT * FROM CUSTOMER_TABLE") };
		if (!result) {
			throw DatabaseException{"Query failed"};
		}

		std::vector<Customer> customers = read_customers(result);

		if (customers.empty()) {
			std::cerr << "No customers found?" << std::endl;
			return 2;
		}

		for (Customer& customer: customers) {
			print(std::cout, customer);
		}

		db_free_result(result);
	} catch(std::exception& caught) {
		std::cerr << "I caught: " << caught.what() << std::endl;
	}

	return 0;
}

std::vector<Customer> read_customers(DB_QUERY_RESULT* result) {
	// sanity check
	// if the number of fields doesn't match the code below would crash
	verify_customer_fields(result);

	std::vector<Customer> customers{};

	DB_ROW row = db_fetch_row(result);
	while (row) {
		customers.push_back(Customer{
				row[0],             // name
				row[1],             // surname
				row[2],             // street
				std::stoi(row[3]),  // street number
				row[4]              // city
				});

		row = db_fetch_row(result);
	}

	return customers;
}

void verify_customer_fields(DB_QUERY_RESULT* result) {
	int num_fields = db_num_fields(result);
	if (num_fields < 0) {
		throw DatabaseException{"db_num_fields() failed"};
	}

	if (num_fields != 5) {
		throw DatabaseException{"Unexpected numbers of fields: " + std::to_string(num_fields)};
	}
}

void print(std::ostream& stream, const Customer& customer) {
	stream << customer.toString() << std::endl;

	if (std::cout.fail()) {
		std::cout.clear();
		throw std::runtime_error{"Failed to output customer"};
	}
}
