//
// Created by Daniel Thalman on 2020-05-25.
//

#include <stddef.h>
#include "requests.h"

url* getLink(struct url* location) {
    return NULL; // TODO implement getLink
}

char *constructURL(url *input) {
    char* output = malloc(sizeof(input->protocol) + sizeof(input->domain) + sizeof(input->path));
    output = strcat(output, input->protocol);
    output = strcat(output, input->domain);
    output = strcat(output, input->path);
    return output;
}

url *deconstructURL(char *input) {
    int domain, path, i, len;
    len = strlen(input);
    domain = -2;
    path = -2;
    for(i = 0; i < len; i += 1) {
        if(domain == -2 && input[i] == ':' && input[i+1] == '/' && input[i+2] == '/') {
            domain = i+3;
        }
        if(path == -2 && domain != -2 && input[i] == '/') {
            path = i;
            if(path <= domain) path = -2;
        }
    }

    url* output = malloc(sizeof(url));
    output->protocol = malloc(sizeof(char) * domain + 1);
    for(i = 0; i < domain; i += 1) {
        output->protocol[i] = input[i];
    }
    output->protocol[i+1] = '\0';
    output->domain = malloc(sizeof(char) * (path - domain) + 1);
    for(i = domain; i < path; i += 1) {
        output->domain[i-domain] = input[i];
    }
    output->domain[i-domain+1] = '\0';
    output->path = malloc(sizeof(char) * (len - path) + 1);
    for(i = path; i < len; i += 1) {
        output->path[i-path] = input[i];
    }
    output->path[i-path+1] = '\0';
    return output;
}

void freeURL(url * input) {
    free(input->protocol);
    free(input->domain);
    free(input->path);
    free(input);
}

