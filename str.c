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

char *str_replace(char *search, char *replace, char *subject)
{
    char *newstr;
    size_t oldlen, newlen, i, j, k, numreplacements, searchlen;

    newlen = oldlen = strlen(subject) + 1;
    searchlen = strlen(search);
    numreplacements = 0;

    for (i=0; i < oldlen-1; i++)
        if (!strncmp(subject+i, search, searchlen))
            numreplacements++;

    if (!numreplacements)
        return strdup(subject);

    newlen += (strlen(replace) * numreplacements) - (searchlen * numreplacements);
    newstr = calloc(1, newlen);
    if (!newstr)
        return NULL;

    for (i=0, j=0; i < oldlen-1; i++) {
        if (!strncmp(subject+i, search, searchlen)) {
            for (k=0; k < strlen(replace); k++)
                newstr[j++] = replace[k];

            i += searchlen-1;
        } else
            newstr[j++] = subject[i];
    }   

    return newstr;
}

#if defined(TEST_CODE)
int main(int argc, char *argv[])
{
    char *newstr;

    if (argc != 4) {
        fprintf(stderr, "USAGE: %s <search> <replace> <subject>\n", argv[0]);
        exit(1);
    }

    newstr = str_replace(argv[1], argv[2], argv[3]);
    printf("%s\n", newstr);

    free(newstr);

    return 0;
}
#endif
