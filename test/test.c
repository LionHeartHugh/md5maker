#include <stdio.h>
#include <string.h>
#include "../src/xkey.h"

int main(int argc, char *argv[])
{
    const char *key = "lionheart";
    const char *data = "datatest";
    xkey_setkey((const unsigned char*)key, strlen(key));
    const char *result = xkey_generate((const unsigned char*)data, strlen(data));
    printf("%s%s = %s\n", data, key, result);
    return 0;
}
