// main file

/* previous solution, not correct(complete) */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
	char* data;
};

struct sentence {
	struct word* data;
	int word_count;
};

struct paragraph {
	struct sentence* data;
	int senetence_count;
};

struct document {
	struct paragraph* data;
	int paragraph_count;
};

char* get_input_text();

typedef struct word s_word;
typedef struct sentence s_sentence;
typedef struct paragraph s_paragraph;
typedef struct document s_document;

struct document get_document(char* text);

s_document* create_new_document();
void doc_add_paragraph(s_document* doc);
void doc_add_sentence(s_document* doc);
void doc_add_word(s_document* doc);
void doc_add_char(s_document* doc, char c);

struct paragraph kth_paragraph(struct document Doc, int k);
struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m);
struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n);

void print_word(struct word w);
void print_sentence(struct sentence sen);
void print_paragraph(struct paragraph para);
void print_document(struct document doc);

int main(int argc, char **argv) {
	char* text = get_input_text();
	struct document Doc = get_document(text);

	int q;
	scanf("%d", &q);

	while (q--) {
		int type;
		scanf("%d", &type);
		if (type == 3) {
			int k, m, n;
			scanf("%d %d %d", &k, &m, &n);
			struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
			print_word(w);
		}
		else if (type == 2) {
			int k, m;
			scanf("%d %d", &k, &m);
			struct sentence sen = kth_sentence_in_mth_paragraph(Doc, k, m);
			print_sentence(sen);
		}
		else {
			int k;
			scanf("%d", &k);
			struct paragraph para = kth_paragraph(Doc, k);
			print_paragraph(para);
		}
		printf("\n");
	}
	return 0;
}

char* get_input_text() {
	int paragraph_count;
	scanf("%d", &paragraph_count);

	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc, 0, sizeof(doc));  // fill with 0
	getchar();
	for (int i = 0; i < paragraph_count; ++i) {
		scanf("%[^\n]%*c", p[i]);
		strcat(doc, p[i]);
		if (i != paragraph_count - 1) {
			strcat(doc, "\n");
		}
	}
	char* returnDoc = (char*)malloc((strlen(doc) + 1) * sizeof(char));
	strcpy(returnDoc, doc);
	return returnDoc;
}

void print_word(struct word w) {
	printf ("%s", w.data);
}

void print_sentence(struct sentence sen) {
	for (int i = 0; i < sen.word_count; ++i) {
		print_word(sen.data[i]);
		if (i != sen.word_count - 1) {
			printf(" ");
		}
	}
}

void print_paragraph(struct paragraph para) {
	for (int i = 0; i < para.senetence_count; ++i) {
		print_sentence(para.data[i]);
		printf(".");
	}
}

void print_document(struct document doc) {
	for (int i = 0; i < doc.paragraph_count; ++i) {
		print_paragraph(doc.data[i]);
		if (i != doc.paragraph_count - 1) {
			printf("\n");
		}
	}
}

s_document* create_new_document() {
	s_document* doc = calloc(1, sizeof(s_document));
	assert(doc != NULL);  // check for memory allocation
	// initialize document structure(info about paragraph)
	doc->data = NULL;  // we don't have allocated any memory to pointer yet
	doc->paragraph_count = 0;
	return doc;
}

void doc_add_paragraph(s_document* doc) {
	// make increment in paragraph count of document
	++doc->paragraph_count;
	doc->data = realloc(doc->data, doc->paragraph_count * sizeof(s_paragraph));
	assert(doc->data != NULL);  // check for memory allocation of paragraph
	// get current paragraph index(it'll always be less than the paragraph_count)
	size_t para_index = doc->paragraph_count - 1;
	// initialize paragraph structure(info about sentence)
	doc->data[para_index].data = NULL;
	doc->data[para_index].senetence_count = 0;
}

void doc_add_sentence(s_document* doc) {
	// get paragraph index
	size_t para_index = doc->paragraph_count - 1;
	++doc->data[para_index].senetence_count;
	size_t sen_count = doc->data[para_index].senetence_count;
	doc->data[para_index].data = realloc(doc->data[para_index].data, sen_count * sizeof(s_sentence));
	assert(doc->data[para_index].data != NULL);  // check for memory allocation of sentence
	// sentence index will always be one less than of senetence_count of a paragraph
	size_t sen_index = doc->data[para_index].senetence_count - 1;
	// initialize sentence structure(info about word)
	doc->data[para_index].data[sen_index].data = NULL;
	doc->data[para_index].data[sen_index].word_count = 0;
}

void doc_add_word(s_document* doc) {
	// get paragraph and sentence index
	size_t para_index = doc->paragraph_count - 1;
	size_t sen_index = doc->data[para_index].senetence_count - 1;
	++doc->data[para_index].data[sen_index].word_count;
	size_t word_count = doc->data[para_index].data[sen_index].word_count;
	doc->data[para_index].data[sen_index].data =
		realloc(doc->data[para_index].data[sen_index].data, word_count * sizeof(s_word));
	assert(doc->data[para_index].data[sen_index].data != NULL);  // check for memory allocation of word
	doc->data[para_index].data[sen_index].data[word_count - 1].data = NULL;
}

void doc_add_char(s_document* doc, char c) {
	// get paragraph, sentence and word index
	size_t para_index = doc->paragraph_count - 1;
	size_t sen_index = doc->data[para_index].senetence_count - 1;
	size_t word_index = doc->data[para_index].data[sen_index].word_count - 1;
	// if string doesn't exist yet, create one
	size_t len_of_string = 0;
	if (doc->data[para_index].data[sen_index].data[word_index].data != NULL) {
		len_of_string = strlen(doc->data[para_index].data[sen_index].data[word_index].data);
	}
	// increase memory size to put new char
	// (len + 2) because one will be for new char and other for '\0'(null char)
	doc->data[para_index].data[sen_index].data[word_index].data =
		realloc(doc->data[para_index].data[sen_index].data[word_index].data, ((len_of_string + 2) * sizeof(char)));
	assert(doc->data[para_index].data[sen_index].data[word_index].data != NULL);
	/*size_t char_index = len_of_string + 1;*/
	doc->data[para_index].data[sen_index].data[word_index].data[len_of_string] = c;
	doc->data[para_index].data[sen_index].data[word_index].data[len_of_string + 1] = '\0';
}

s_document get_document(char* text) {
	// create new document
	s_document* doc = create_new_document();
	// add first paragraph, sentence and word
	doc_add_paragraph(doc);
	doc_add_sentence(doc);
	doc_add_word(doc);

	// iterate upon the text provided
	size_t len_text = strlen(text);
	for (size_t char_index = 0; char_index < len_text; ++char_index) {
		switch (text[char_index]) {
			case ' ':
				doc_add_word(doc);
				break;
			// add sentence, word if it's not the last sentence of paragraph or text
			case '.':
				if ((text[char_index + 1] != '\n') && (text[char_index + 1] != '\0')) {
					doc_add_sentence(doc);
					doc_add_word(doc);
				}
				break;
			// add to paragraph, sentence and word
			case '\n':
				doc_add_paragraph(doc);
				doc_add_sentence(doc);
				doc_add_word(doc);
				break;
			case '\0':
				break;  // do nothing if it's the end of text
			default:
				doc_add_char(doc, text[char_index]);
				break;
		}
	}
	return *doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	return Doc.data[k - 1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
	return Doc.data[k - 1].data[m - 1];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return Doc.data[k - 1].data[m - 1].data[n - 1];
}