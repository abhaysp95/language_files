// operations with stack


#include <stdio.h>

struct address {
	char street[50];
	int housenumber;
	int postcode[5];
	char city[25];
};

// remove the padding
// this results the slower code
struct __attribute__((__packed__)) packed_address {
	char street[50];
	int housenumber;
	int postcode[5];
	char city[25];
};

struct data {
	char val1;
	int val2;
	double val3;
};

struct __attribute__((__packed__)) packed_data {
	char val1;
	int val2;
	double val3;
};

// can modify the padding with #pragma directive
#pragma pack(push)  // pushes the actual alignment setting to internal stack
#pragma push(8)  // sets the max alignment to one byte, followed by structure defination

struct pragma_address {
	char street[50];
	int housenumber;
	int postcode[5];
	char city[25];
};

struct pragma_data {
	char val1;
	int val2;
	double val3;
};

#pragma pack(pop)  // popping it from internal stack

typedef struct address stadd;

int main(int argc, char *argv[]) {
	stadd myAddress = {
		"SomeStreet",
		123,
		{1, 2, 3, 4, 5},
		"SomeCity"
	};

	printf("House Number: %u\n", myAddress.housenumber);
	printf("City: %s\n", myAddress.city);

	printf("\nGet sizes without removing padding: \n\n");
	printf("Size of address struct: %d\n", sizeof(stadd));
	printf("Size of address struct: %d\n", sizeof(myAddress));
	printf("Size of street: %d\n", sizeof(myAddress.street));
	printf("Size of housenumber: %d\n", sizeof(myAddress.housenumber));
	printf("Size of postcode: %d\n", sizeof(myAddress.postcode));
	printf("Size of city: %d\n", sizeof(myAddress.city));
	printf("Size of data: %d\n", sizeof(struct data));

	printf("\nAnother example, packing using attribute __packed__\n\n");

	printf("Size of packed_address: %d\n", sizeof(struct packed_address));
	printf("Size of packed_data: %d\n", sizeof(struct packed_data));

	printf("\nSizes padding modified by pragma directive\n\n");

	printf("Size of pragma_address: %d\n", sizeof(struct pragma_address));
	printf("Size of pragma_data: %d\n", sizeof(struct pragma_data));

	return 0;
}

/* Memory structure of struct if every element is of same datatype in struct,
 * then it's the multiple of the datatype size, like:
 * struct data2 {
	 unit8_t val1;
	 unit8_t val2;
	 unit8_t val3;
 * };
 * but for different types there will be padding, let from above
 * example val2 is of datatype unit32_t, then size of struct will not
 * be 6, but will be 12, as the biggest datatype is of size 4, so the
 * rest of the datatype size will be padded to 4, so 4 * 3 = 12
 *
 * The order of variable also have affect on size
 * struct data2 {
	 unit8_t val1;
	 unit8_t val3;
	 unit32_t val2;
 * };
 * This time size will not be 12 but will be 8, since in the first
 * chunk val1, and val3 will fit but val2 will not
 *
 * links to check:
 * https://stackoverflow.com/questions/45803016/preprocessor-directive-pragma-pack-in-c
 * https://levelup.gitconnected.com/advanced-concepts-in-c-structures-254fe156b3fb
 *
 */
