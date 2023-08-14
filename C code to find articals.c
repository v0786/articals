#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countArticles(const char *paragraph) {
    int count = 0;
    char *word;
    
    // Make a copy of the paragraph to avoid modifying the original
    char paragraphCopy[strlen(paragraph) + 1];
    strcpy(paragraphCopy, paragraph);
    
    // Tokenize the paragraph into words
    word = strtok(paragraphCopy, " ");
    
    while (word != NULL) {
        // Convert the word to lowercase for case-insensitive comparison
        for (int i = 0; word[i]; i++) {
            word[i] = tolower(word[i]);
        }
        
        // Check if the word is an article
        if (strcmp(word, "a") == 0 || strcmp(word, "an") == 0 || strcmp(word, "the") == 0) {
            count++;
        }
        
        // Get the next word
        word = strtok(NULL, " ");
    }
    
    return count;
}

int main() {
    char paragraph[1000];
    
    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);
    
    int articleCount = countArticles(paragraph);
    printf("Number of articles: %d\n", articleCount);
    
    return 0;
}
