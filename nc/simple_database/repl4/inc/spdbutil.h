#ifndef SPDBUTIL_H
#define SPDBUTIL_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define COLUMN_COMPANY_NAME 32
#define COLUMN_MODEL_NAME 128
#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define TABLE_MAX_PAGES 100  // arbitrary

/* struct for InputBuffer */
// small wrapper to interact with getline()
typedef struct {
	char* buffer;
	size_t buffer_length;
	ssize_t input_length;
} InputBuffer;

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNIZED
} MetaCommandResult;

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_SYNTAX_ERROR,
	PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
	EXECUTE_SUCCESS,
	EXECUTE_TABLE_FULL
} ExecuteResult;

// currently our prepared statement just have only two possible values
typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
} StatementType;

typedef struct {
	uint32_t sl_no;
	uint32_t year;
	char company[COLUMN_COMPANY_NAME];
	char model[COLUMN_MODEL_NAME];
	float power;
} Row;

typedef struct {
	StatementType type;
	Row row_to_insert;
} Statement;

InputBuffer* new_input_buffer();
void print_prompt();
void read_input(InputBuffer* input_buffer);
MetaCommandResult do_meta_command(InputBuffer* input_buffer);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement *statement);



extern const uint32_t SLNO_SIZE;
extern const uint32_t YEAR_SIZE;
extern const uint32_t COMPANY_SIZE;
extern const uint32_t MODEL_SIZE;
extern const uint32_t POWER_SIZE;
extern const uint32_t ROW_SIZE;
extern const uint32_t SLNO_OFFSET;
extern const uint32_t YEAR_OFFSET;
extern const uint32_t COMPANY_OFFSET;
extern const uint32_t MODEL_OFFSET;
extern const uint32_t POWER_OFFSET;


void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);


extern const uint32_t PAGE_SIZE;
extern const uint32_t ROWS_PER_PAGE;
extern const uint32_t TABLE_MAX_ROWS;

/* Table structure that points to pages and keeps track of how many rows are there */
typedef struct {
	uint32_t num_rows;
	void* pages[TABLE_MAX_PAGES];
} Table;

void* row_slot(Table* table, uint32_t row_num);

ExecuteResult execute_statement(Table *table, Statement* statement);

// initialization of table
Table* new_table();
void free_table(Table* table);

// print the saved row
void print_row(Row* row);

void close_input_buffer(InputBuffer* input_buffer);
#endif
