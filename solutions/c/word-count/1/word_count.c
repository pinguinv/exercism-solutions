#include "word_count.h"

#include <string.h>
#include <ctype.h>

// Checks if given word already exists in the set.
// Returns index if word is in the collection, else returns -1;
static int get_word_index(word_count_word_t *words, int word_count, char *word)
{
    const int NON_EXISTING_WORD = -1;

    for (int i = 0; i < word_count; i++)
        if (!strcmp(words[i].text, word))
            return i;

    return NON_EXISTING_WORD;
}

int count_words(const char *sentence, word_count_word_t *words)
{
    if (sentence == NULL || words == NULL)
        return NULL_POINTER_PASSED;

    if (strlen(sentence) == 0)
        return 0;

    int unique_words = 0;
    char word_buffer[MAX_WORD_LENGTH + 1] = {0};
    const char *word_start_ptr = sentence, *word_end_ptr;

    while (*word_start_ptr)
    {
        // Find first alphanumeric char
        while (*word_start_ptr && !isalnum(*word_start_ptr))
            word_start_ptr++;

        word_end_ptr = word_start_ptr;

        // Find where alphanumeric chars end
        while (*word_end_ptr && (isalnum(*word_end_ptr) || *word_end_ptr == '\''))
        {
            // If there's an apostrophe check if after it is an alphabetic char,
            // if not, break the loop (end of the word)
            if (*word_end_ptr == '\'' && !isalpha(*(word_end_ptr + 1)))
                break;

            word_end_ptr++;
        }

        if (word_start_ptr == word_end_ptr)
            break;

        memmove(word_buffer, word_start_ptr, word_end_ptr - word_start_ptr);

        for (size_t i = 0; i < strlen(word_buffer); i++)
            word_buffer[i] = tolower(word_buffer[i]);

        int word_index = get_word_index(words, unique_words, word_buffer);
        if (word_index != -1)
            words[word_index].count += 1;
        else
        {
            strcpy(words[unique_words].text, word_buffer);
            words[unique_words++].count = 1;
        }

        word_start_ptr = word_end_ptr;
        memset(word_buffer, 0, MAX_WORD_LENGTH);
    }

    return unique_words;
}
