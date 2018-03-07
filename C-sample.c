#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

typedef double (*func_ptr)(double);

int main(int argc, char **argv) {
    char name[] = "/lib/libm.so.6";
    void *lib = dlopen(name, RTLD_LAZY);
    if (lib == NULL) {
        exit(1);
    }
    func_ptr math_func = dlsym(lib, argv[1]);
    if (math_func == NULL) {
        exit(1);
    }
    double number = 0;
    while (scanf("%lf", &number) == 1) {
        double result = math_func(number);
        printf("%.10g\n", result);
    }
}