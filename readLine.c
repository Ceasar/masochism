#include <stdio.h>
#include <string.h>


/*
 * Read lines from a file until EOF
 * 
 * @param File to read
 * @param buffer to store contents
 * @return number of bytes read or -1
 */
int readLine(FILE *file, char *buffer) {
    if (!feof(file)) {
        fgets(buffer, sizeof(buffer), file);
        return strlen(buffer);
    } else {
        return 0;
    }
}
