#include <stdio.h>
#include "requests.h"
#include "main.h"

int main() {
    url* test = deconstructURL("https://github.com/Daniel-Thalman/InternetMapping");
    char* test0 = constructURL(test);
    printf("%s", test0);
    freeURL(test);
}
