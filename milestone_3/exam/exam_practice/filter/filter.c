#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

#define READ_SIZE 1024

// ----------------- Error handling -----------------
static int error_exit(const char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
    return 1;
}

// ----------------- Replace occurrences in buffer -----------------
static void replace_and_flush(char **stash_ptr, size_t *stash_len_ptr, const char *pattern, size_t pattern_len)
{
    char *stash = *stash_ptr;
    size_t stash_len = *stash_len_ptr;

    char *pos;
    while ((pos = memmem(stash, stash_len, pattern, pattern_len)))
    {
        // Write everything before the match
        write(STDOUT_FILENO, stash, pos - stash);
        // Write replacement
        for (size_t i = 0; i < pattern_len; i++)
            write(STDOUT_FILENO, "*", 1);

        // Move remaining data to start
        size_t remaining = stash_len - (pos - stash) - pattern_len;
        memmove(stash, pos + pattern_len, remaining);
        stash_len = remaining;
        stash[stash_len] = '\0';
    }

    // Flush safe part, keep last pattern_len chars for overlap
    if (stash_len > pattern_len)
    {
        write(STDOUT_FILENO, stash, stash_len - pattern_len);
        memmove(stash, stash + stash_len - pattern_len, pattern_len);
        stash_len = pattern_len;
        stash[stash_len] = '\0';
    }

    *stash_ptr = stash;
    *stash_len_ptr = stash_len;
}

// ----------------- Read from stdin and feed buffer -----------------
static int process_input(const char *pattern, size_t pattern_len)
{
    char buf[READ_SIZE];
    char *stash = calloc(1, 1);
    if (!stash)
        return error_exit(strerror(errno));

    size_t stash_len = 0;
    ssize_t bytes;

    while ((bytes = read(STDIN_FILENO, buf, READ_SIZE)) > 0)
    {
        char *tmp = realloc(stash, stash_len + bytes + 1);
        if (!tmp)
        {
            free(stash);
            return error_exit(strerror(errno));
        }
        stash = tmp;

        memmove(stash + stash_len, buf, bytes);
        stash_len += bytes;
        stash[stash_len] = '\0';

        replace_and_flush(&stash, &stash_len, pattern, pattern_len);
    }

    if (bytes < 0)
    {
        free(stash);
        return error_exit(strerror(errno));
    }

    // Flush remaining
    if (stash_len > 0)
        write(STDOUT_FILENO, stash, stash_len);

    free(stash);
    return 0;
}

// ----------------- Main -----------------
int main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
        return 1;

    return process_input(argv[1], strlen(argv[1]));
}