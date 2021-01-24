// main file

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

struct document get_document(char* text);
struct paragraph* get_paragraph(char* str, char* delim);
struct sentence* get_sentence(char* str, char* delim);


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

// get a single sentence, which may have multiple words, delim " "
struct sentence* get_sentence(char* str, char* delim) {
	struct sentence* sen = (struct sentence*)malloc(sizeof(struct sentence));
	struct word* words = (struct word*)malloc(sizeof(struct word));
	int count = 0;
	char* token;
	token = strtok(str, delim);
	words[count++].data = token;
	words = realloc(words, sizeof(struct word) * (count + 1));
	while (token != NULL) {
		token = strtok(NULL, delim);
		words[count++].data = token;
		words = realloc(words, sizeof(struct word) * (count + 1));
	}
	sen->data = words;
	sen->word_count = count;
	return sen;
}

// get a single paragraph, which may have multiple sentences, delim "."
struct paragraph* get_paragraph(char* str, char* delim) {
	struct paragraph* para = (struct paragraph*)malloc(sizeof(struct paragraph));
	struct sentence* sentences = (struct sentence*)malloc(sizeof(struct sentence));
	int count = 0;
	char* token;
	token = strtok(str, delim);  // if you have to, add '\0' here
	sentences[count++] = *get_sentence(token, " ");
	sentences = realloc(sentences, sizeof(struct sentence) * (count + 1));
	while (token != NULL) {
		token = strtok(NULL, delim);  // if you have to, add '\0' here
		sentences[count++] = *get_sentence(token, " ");
		sentences = realloc(sentences, sizeof(struct sentence) * (count + 1));
	}
	para->data = sentences;
	para->senetence_count = count;
	return para;
}

// get a single document, which may have multiple paragraphs, delim "\n"
struct document get_document(char* text) {
	struct document* doc = (struct document*)malloc(sizeof(struct document));
	struct paragraph* paragraphs = (struct paragraph*)malloc(sizeof(struct paragraph));
	int count = 0;
	char* token;
	token = strtok(text, "\n");  // if you have to, add '\0' here
	paragraphs[count++] = *get_paragraph(token, ".");
	paragraphs = realloc(paragraphs, sizeof(struct paragraph) * (count + 1));
	while (token != NULL) {
		token = strtok(NULL, "\n");
		paragraphs[count++] = *get_paragraph(token, ".");
		paragraphs = realloc(paragraphs, sizeof(struct paragraph) * (count + 1));
	}
	doc->data = paragraphs;
	doc->paragraph_count = count;
	return *doc;
}

struct paragraph kth_paragraph(struct document Doc, int k) {
	return Doc.data[k];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) {
	return Doc.data[k].data[m];
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {
	return Doc.data[k].data[m].data[n];
}