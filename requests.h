//
// Created by Daniel Thalman on 2020-05-25.
//

#ifndef INTERNETMAPPING_REQUESTS_H
#define INTERNETMAPPING_REQUESTS_H

#include <stdlib.h>
#include <string.h>

typedef struct url {
    char* protocol; // ex; "https://"
    char* domain; // ex; "en.wikipedia.com"
    char* path; // ex; "/wiki/C_(programming_language)"
} url;

url* getLink(url*);
char* constructURL(url* input);
url* deconstructURL(char* input);
void freeURL(url*);

#endif //INTERNETMAPPING_REQUESTS_H
