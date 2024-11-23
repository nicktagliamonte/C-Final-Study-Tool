#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void hexArithmetic();
int hexToInt(const char *hex);
void intToHex(int num, char *hex);
void hexBinary();
void powerOfTwo();
void powerOfTen();
void allGame();

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n--- Main Menu ---\n");
        printf("1. Hex Arithmetic\n");
        printf("2. Hex Binary Conversion\n");
        printf("3. 2^x\n");
        printf("4. 10^x\n");
        printf("5. All\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                hexArithmetic();
                break;
            case 2:
                printf("Hexadecimal to Binary Conversion selected.\n");
                hexBinary();
                break;
            case 3:
                printf("2^x Calculation selected.\n");
                powerOfTwo();
                break;
            case 4:
                printf("10^x Naming selected.\n");
                powerOfTen();
                break;
            case 5:
                printf("Full game selected.\n");
                allGame();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                return 0;
            default:
                printf("This option is not implemented yet.\n");
        }
    }
    return 0;
}

void hexArithmetic() {
    char hex1[5], hex2[5], userInput[10], correctAnswer[10];
    int num1, num2, result;
    char operation;

    printf("\n--- Hex Arithmetic ---\n");
    printf("Enter '.' to return to the main menu.\n");

    while (1) {
        num1 = rand() % 0x10000;
        num2 = rand() % 0x10000;

        operation = (rand() % 2 == 0) ? '+' : '-';

        intToHex(num1, hex1);
        intToHex(num2, hex2);

        if (operation == '+') {
            result = num1 + num2;
        } else {
            result = num1 - num2;
        }

        intToHex(result, correctAnswer);

        printf("\nSolve: %s %c %s = ", hex1, operation, hex2);
        scanf("%s", userInput);

        if (strcmp(userInput, ".") == 0) {
            printf("Returning to the main menu...\n");
            break;
        }

        if (strcasecmp(userInput, correctAnswer) == 0) {
            printf("Correct! Well done.\n");
        } else {
            printf("Incorrect. The correct answer is %s.\n", correctAnswer);
        }
    }
}

int hexToInt(const char *hex) {
    int value;
    sscanf(hex, "%x", &value);
    return value;
}

void intToHex(int num, char *hex) {
    sprintf(hex, "%04X", (num & 0xFFFF));
}

void hexToBinaryChar(char hexChar, char *binary) {
    switch (toupper(hexChar)) {
        case '0': strcpy(binary, "0000"); break;
        case '1': strcpy(binary, "0001"); break;
        case '2': strcpy(binary, "0010"); break;
        case '3': strcpy(binary, "0011"); break;
        case '4': strcpy(binary, "0100"); break;
        case '5': strcpy(binary, "0101"); break;
        case '6': strcpy(binary, "0110"); break;
        case '7': strcpy(binary, "0111"); break;
        case '8': strcpy(binary, "1000"); break;
        case '9': strcpy(binary, "1001"); break;
        case 'A': strcpy(binary, "1010"); break;
        case 'B': strcpy(binary, "1011"); break;
        case 'C': strcpy(binary, "1100"); break;
        case 'D': strcpy(binary, "1101"); break;
        case 'E': strcpy(binary, "1110"); break;
        case 'F': strcpy(binary, "1111"); break;
    }
}

void hexToBinaryString(const char *hex, char *binary) {
    binary[0] = '\0';
    for (int i = 0; hex[i] != '\0'; i++) {
        char binarySegment[5];
        hexToBinaryChar(hex[i], binarySegment);
        strcat(binary, binarySegment);
    }
}

void generateRandomHex(char *hex) {
    int value = rand() % 65536;
    sprintf(hex, "%04X", value);
}

void hexBinary() {
    char hex[5];
    char binary[17];
    char userInput[65];

    while (1) {
        generateRandomHex(hex);

        hexToBinaryString(hex, binary);

        printf("Convert the following hexadecimal number to binary (or enter '.' to quit): %s\n", hex);
        scanf("%s", userInput);

        if (strcmp(userInput, ".") == 0) {
            printf("Returning to main menu...\n");
            break;
        }

        if (strcmp(userInput, binary) == 0) {
            printf("Correct! The binary equivalent of %s is %s.\n\n", hex, binary);
        } else {
            printf("Incorrect. The binary equivalent of %s is %s.\n\n", hex, binary);
        }
    }
}

const char* getPowerOfTwoName(int exponent) {
    switch (exponent) {
        case 10: return "thousand";
        case 20: return "million";
        case 30: return "billion";
        case 40: return "trillion";
        case 50: return "quadrillion";
        default: return "unknown";
    }
}

void powerOfTwo() {
    int exponents[] = {10, 20, 30, 40, 50};
    char userInput[50];
    const char* correctAnswer;

    while (1) {
        int randomIndex = rand() % (sizeof(exponents) / sizeof(exponents[0]));
        int x = exponents[randomIndex];

        correctAnswer = getPowerOfTwoName(x);

        printf("What is the name for 2^%d? (or enter '.' to quit):\n", x);
        scanf(" %49s", userInput);

        if (strcmp(userInput, ".") == 0) {
            printf("Returning to main menu...\n");
            break;
        }

        if (strcasecmp(userInput, correctAnswer) == 0) {
            printf("Correct! 2^%d is approximately a %s.\n\n", x, correctAnswer);
        } else {
            printf("Incorrect. 2^%d is approximately a %s.\n\n", x, correctAnswer);
        }
    }
}

const char* getLargeNumberName(int exponent) {
    switch (exponent) {
        case 3:  return "thousand";
        case 6:  return "million";
        case 9:  return "billion";
        case 12: return "trillion";
        case 15: return "quadrillion";
        default: return "unknown";
    }
}

void powerOfTen() {
    int exponents[] = {3, 6, 9, 12, 15};
    char userInput[50];
    const char* correctAnswer;

    while (1) {
        int randomIndex = rand() % (sizeof(exponents) / sizeof(exponents[0]));
        int x = exponents[randomIndex];

        correctAnswer = getLargeNumberName(x);

        printf("What is the name for 10^%d? (or enter '.' to quit):\n", x);
        scanf(" %49s", userInput);

        if (strcmp(userInput, ".") == 0) {
            printf("Returning to main menu...\n");
            break;
        }

        if (strcasecmp(userInput, correctAnswer) == 0) {
            printf("Correct! 10^%d is called a %s.\n\n", x, correctAnswer);
        } else {
            printf("Incorrect. 10^%d is called a %s.\n\n", x, correctAnswer);
        }
    }
}

void allGame() {
    char userInput[50];
    while (1) {
        int randomOption = rand() % 4;

        switch (randomOption) {
            case 0: {
                char hex1[5], hex2[5], userAnswer[10], correctAnswer[10];
                int num1 = rand() % 0x10000;
                int num2 = rand() % 0x10000;
                char operation = (rand() % 2 == 0) ? '+' : '-';
                int result = (operation == '+') ? num1 + num2 : num1 - num2;

                intToHex(num1, hex1);
                intToHex(num2, hex2);
                intToHex(result, correctAnswer);

                printf("\nSolve: %s %c %s = ", hex1, operation, hex2);
                scanf("%s", userAnswer);

                if (strcmp(userAnswer, ".") == 0) {
                    printf("Exiting All mode...\n");
                    return;
                }

                if (strcasecmp(userAnswer, correctAnswer) == 0) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct answer is %s.\n", correctAnswer);
                }
                break;
            }
            case 1: {
                char hex[5], binary[17], userAnswer[65];
                generateRandomHex(hex);
                hexToBinaryString(hex, binary);

                printf("\nConvert %s to binary: ", hex);
                scanf("%s", userAnswer);

                if (strcmp(userAnswer, ".") == 0) {
                    printf("Exiting All mode...\n");
                    return;
                }

                if (strcmp(userAnswer, binary) == 0) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct binary is %s.\n", binary);
                }
                break;
            }
            case 2: {
                int exponents[] = {10, 20, 30, 40, 50};
                int randomIndex = rand() % (sizeof(exponents) / sizeof(exponents[0]));
                int x = exponents[randomIndex];
                const char* correctAnswer = getPowerOfTwoName(x);

                printf("\nWhat is the name for 2^%d? ", x);
                scanf(" %49s", userInput);

                if (strcmp(userInput, ".") == 0) {
                    printf("Exiting All mode...\n");
                    return;
                }

                if (strcasecmp(userInput, correctAnswer) == 0) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. 2^%d is called a %s.\n", x, correctAnswer);
                }
                break;
            }
            case 3: {
                int exponents[] = {3, 6, 9, 12, 15};
                int randomIndex = rand() % (sizeof(exponents) / sizeof(exponents[0]));
                int x = exponents[randomIndex];
                const char* correctAnswer = getLargeNumberName(x);

                printf("\nWhat is the name for 10^%d? ", x);
                scanf(" %49s", userInput);

                if (strcmp(userInput, ".") == 0) {
                    printf("Exiting All mode...\n");
                    return;
                }

                if (strcasecmp(userInput, correctAnswer) == 0) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. 10^%d is called a %s.\n", x, correctAnswer);
                }
                break;
            }
        }

        printf("\nEnter '.' to quit ALL mode: ");
        fgets(userInput, sizeof(userInput), stdin);

        if (userInput[0] == '.') {
            printf("Exiting All mode...\n");
            break;
        }
    }
}