#include "../inc/queryutil.h"

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	char* res_word;
	res_word = *(*(*(document + n - 1) + m - 1) + k - 1);
	return res_word;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {
	char** res_sentence;
	res_sentence = *(*(document + m - 1) + k - 1);
	return res_sentence;
}

char*** kth_paragraph(char**** document, int k) {
	char*** res_paragraph;
	res_paragraph = *(document + k - 1);
	return res_paragraph;
}

/* failed attempt, problem, realloc invalid next value, at count 44, and wIndex = 4 at that time */
/*char**** get_document(char* text) {
	int pIndex = 0;
	int count = 0, pCount = 0;
	char**** madeDocument = (char****)malloc(sizeof(*madeDocument));
	while (*(text + count) != '\0') {
		int sIndex = 0;
		char*** madeParagraph = (char***)malloc(sizeof(*madeParagraph));
		while (*(text + count) != '\n') {
			int wIndex = 0;  // initialize word count
			char** madeSentence = (char**)malloc(sizeof(*madeSentence));  // create new sentence block of size char*
			while (*(text + count) != '.') {
				// increase count for whole string one step at a time
				while ((*(text + count) != ' ') && (*(text + count) != '.') && (*(text + count) != '\n') && (*(text + count) != '\0')) {
					count++;
				}
				// create a new word block of size 'count - pCount' of char and copy word to it
				char* madeWord = (char*)malloc((count - pCount + 1 * sizeof(*madeWord)));  // on one char extra space, strncpy will put '\0'
				[>  copy is going to be explicit from start and implicit from end,
				   means, if given 14 to 17, char included will be at 14, 15, 16 <]
				memcpy(madeWord, text + pCount, count - pCount);
				memset(madeWord + count - pCount + 1, '\0', sizeof(char));
				*(madeSentence + wIndex) = madeWord; // put word in sentence at wIndex index
				if ((*(text + count) == '.') || (*(text + count) == '\n') || (*(text + count) == '\0')) {
					break;
				}
				else {
					wIndex++;  // increase count of word
					// at count = 43, gdb says invalid next size for realloc, and SIGABRT
					madeSentence = realloc(madeSentence, wIndex * sizeof(char*));  // increase word block in sentence space to point to new word
					count++;  // increase the count
					pCount = count;  // set current count to previous
				}
			}
			*(madeParagraph + sIndex) = madeSentence;  // put sentence in sentence block by sIndex index
			if ((*(text + count) == '\n') || (*(text + count) == '\0')) {
				break;
			}
			else {
				sIndex++;  // increase count of sentence
				madeParagraph = realloc(madeParagraph, sIndex * sizeof(char**));  // increase sentence block in paragraph space to point to new sentence
				count++;
				pCount = count;
			}
		}
		*(madeDocument + pIndex) = madeParagraph;
		if ((*(text + count) == '\0')) {
			break;
		}
		else {
			pIndex++;
			madeDocument = realloc(madeDocument, pIndex * sizeof(char***));
			count++;
			pCount = count;
		}
	}
	return madeDocument;
}*/

char** string_split(char* text, char delim) {
	assert(text != NULL);
	char** res_str = malloc(sizeof(*res_str));
	char* substr;

	substr = strtok(text, &delim);
	*res_str = substr;

	int size = 1;
	while (substr != NULL) {
		size++;
		res_str = realloc(res_str, size * sizeof(*res_str));
		substr = strtok(NULL, &delim);
		*(res_str + size - 1) = substr;
	}
	return res_str;
}

char**** get_document(char* text) {
	assert(text != NULL);
	/* get numbers of total paragraphs from text by splitting with '\n' */
	char** madeParagraphs = string_split(text, '\n');
	int pCount = 0;
	while (*(madeParagraphs + pCount) != NULL) {
		pCount++;
	}
	char**** madeDocument = malloc((pCount + 1) * sizeof(*madeDocument));
	/* a document can have pCount paragraphs, set the last position to NULL */
	*(madeDocument + pCount) = NULL;

	int index = 0;
	while (*(madeParagraphs + index) != NULL) {
		/* create sentence with delim of '.' */
		char** madeSentences = string_split(*(madeParagraphs + index), '.');
		int sCount = 0;
		while (*(madeSentences + sCount) != NULL) {
			sCount++;
		}
		*(madeDocument + index) = malloc((sCount + 1) * sizeof(**madeDocument));
		/* set last position for sentence in document to NULL */
		/* *(*(madeDocument + sCount) + index) = NULL; */
		*(*(madeDocument + index) + sCount) = NULL;
		int sIndex = 0;
		while (*(madeSentences + sIndex) != NULL) {
			/** examples:
			 * say you wanna see 3rd word of 4th sentence from 2nd
			 * paragraph
			 * *(*(*(madeDocument + 1) + 3) + 2)
			 *
			 * so you don't actually need to have paragraph with
			 * **pointers, just having it as string and the count of
			 * madeParagraph will act as first dereference for madeDocument
			 */
			*(*(madeDocument + index) + sIndex) = string_split(*(madeSentences + sIndex), ' ');
			sIndex++;
		}
		index++;
	}
	return madeDocument;
}

char* get_input_text() {
	int paragraph_count;
	scanf("%d", &paragraph_count);

	char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
	memset(doc, 0, sizeof(doc));
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

void print_word(char* word) {
	printf("%s", word);
}

void print_sentence(char** sentence) {
	int word_count;
	scanf("%d", &word_count);
	for (int i = 0; i < word_count; ++i) {
		printf("%s", sentence[i]);
		if (i != word_count - 1) {
			printf(" ");
		}
	}
}

void print_paragraph(char*** paragraph) {
	int sentence_count;
	scanf("%d", &sentence_count);
	for (int i = 0; i < sentence_count; ++i) {
		print_sentence(*(paragraph + i));
		printf(".");
	}
}

void free_document(char**** document) {
	int count = 0;
	int sCount = 0;
	int wCount = 0;
	while (*(document + count) != NULL) {
		while (*(*(document + count) + sCount) != NULL) {
			free(*(*(document + count) + sCount));
			sCount++;
		}
		free(*(document + count));
		count++;
	}
	free(document);
}