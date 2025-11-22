#include <string.h>
#include <ctype.h>

// makes string upper
void make_upper(char* s)
{
    int i = 0;
    while (s[i]) {
        s[i] = toupper(s[i]);
        i++;
    }
}