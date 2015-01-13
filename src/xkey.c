#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "xkey.h"

void md5 (const char *message, long len, char *output);

char keybuffer[256];
unsigned int keysize = 0;
unsigned char codebuffer[16];
char result[33];

void xkey_setkey(const char* key, unsigned int size)
{
    memcpy(keybuffer, key, size);
    keysize = size;
}

const char* xkey_generate(const char* content, unsigned int size)
{
    unsigned int datasize = size + keysize;
    char *buffer = (char*)malloc(datasize);
    assert(buffer != NULL);
    memcpy(buffer, content, size);
    memcpy(buffer + size, keybuffer, keysize);
    md5((const char*)buffer, datasize, (char*)codebuffer);
    for(int i = 0; i < 16; i++) {
        codebuffer[i] = codebuffer[i] & 0xff;
    }
    sprintf(
            result,
            "%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x%x",
            codebuffer[0],
            codebuffer[1],
            codebuffer[2],
            codebuffer[3],
            codebuffer[4],
            codebuffer[5],
            codebuffer[6],
            codebuffer[7],
            codebuffer[8],
            codebuffer[9],
            codebuffer[10],
            codebuffer[11],
            codebuffer[12],
            codebuffer[13],
            codebuffer[14],
            codebuffer[15]
           );
    return result;
}
