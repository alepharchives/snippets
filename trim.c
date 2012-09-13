/*
 * Copyright (c) 2012, Shawn Webb
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * 
 *    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

char *ltrim(char *s)
{
    char *p = s;

    while (*p && isspace((int)(*p)))
        p++;

    return strdup(p);
}

char *rtrim(char *s)
{
    char *p, *r;
    char t;

    p = s + strlen(s) - 1;
    while (p > s && isspace((int)(*p)))
        p--;

    t = *(++p);
    *p = '\0';
    r = strdup(s);
    *p = t;

    return r;
}

char *trim(char *s)
{
    char *r, *t;

    t = ltrim(s);
    r = rtrim(t);

    free(t);

    return r;
}

#if defined(TEST_CODE)
int main(int argc, char *argv[])
{
    char *newstr;

    if (argc != 2) {
        fprintf(stderr, "USAGE: %s <text>\n", argv[0]);
        exit(1);
    }

    newstr = trim(argv[1]);
    printf("%s: %d\n", newstr, strlen(newstr));

    return 0;
}
#endif
