#include <stdio.h>
#include <string.h>

typedef enum {S0, S1, S2, S3, S4, S5} State;

int detect_sequence(const char* input_string) {
    int state = S0;

    for (int i = 0; i < strlen(input_string); ++i) {
        char char_input = input_string[i];

        switch (state) {
            case 0:
                if (char_input == '1')
                    state = S1;
                break;
            case 1:
                if (char_input == '0')
                    state = S2;
                else if (char_input == '1')
                    state = S1;
                break;
            case 2:
                if (char_input == '1')
                    state = S3;
                else if (char_input == '0')
                    state = S0;
                break;
            case 3:
                if (char_input == '1')
                    state = S4;
                else if (char_input == '0')
                    state = S2;
                break;
            case 4:
                if (char_input == '0')
                    state = S5;
                else if (char_input == '1')
                    state = S1;
                break;
            case 5:
                return S1; // Sequence detected
        }
    }

    return state == S5; // Final check if sequence is detected at the end
}

int main() {
    const char* input_string = "1101011010110";

    if (detect_sequence(input_string)) {
        printf("Sequence '10110' detected!\n");
    } else {
        printf("Sequence '10110' not detected.\n");
    }

    return 0;
}
