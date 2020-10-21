#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

#define MAX_INPUT_INIT_NUM_SIZE 100
#define FROM_STR "--from="
#define TO_STR "--to="
#define FIR_PARAM_LENGTH 7
#define SEC_PARAM_LENGTH 5
#define NOT_ENOUGH_PARAMS -1
#define TOO_MANY_PARAMS -2
#define PAR_REDECLARATION -3
#define INCORRECT_PARAMS -4

extern void sort(long long *input_check, long long input_count);

int main(int argc, char **argv) {
    int from_count = 0, to_count = 0;
    int input_count = 0;
    long long input[MAX_INPUT_INIT_NUM_SIZE];
    long long input_check[MAX_INPUT_INIT_NUM_SIZE];
    long long from_value = 0, to_value = 0;
    long long input_value;
    char place = ' ';
    int count = 0;
    if (argc < 2) {
        return NOT_ENOUGH_PARAMS;
    } else if (argc > 3) {
        return TOO_MANY_PARAMS;
    }

    for (int i = 1; i < argc; i++) {
        if (strncmp(argv[i], FROM_STR, FIR_PARAM_LENGTH) == 0) {
            from_value = strtoll(argv[i] + FIR_PARAM_LENGTH, NULL, 10);
            from_count++;
        } else if (strncmp(argv[i], TO_STR, SEC_PARAM_LENGTH) == 0) {
            to_value = strtoll(argv[i] + SEC_PARAM_LENGTH, NULL, 10);
            to_count++;
        }
    }
    if (from_count > 1 || to_count > 1) {
        return PAR_REDECLARATION;
    } else if (from_count == 0 && to_count == 0) {
        return INCORRECT_PARAMS;
    }
    while (place != '\n') {
        if (scanf("%lld%c", &input_value, &place) != 2) {
            break;
        }
        if (input_value <= from_value) {
            fprintf(stdout, "%lld ", input_value);
        }
        if (input_value >= to_value) {
            fprintf(stderr, "%lld ", input_value);
        }
        if ((input_value > from_value) && (input_value < to_value)) {
            input[input_count] = input_value;
            input_check[input_count] = input_value;
            input_count++;
        }
    }
    sort(input, input_count);
    for (int i = 0; i < input_count; i++) {
        if (input[i] != input_check[i]) {
            count++;
        }
    }
    return count;
}
