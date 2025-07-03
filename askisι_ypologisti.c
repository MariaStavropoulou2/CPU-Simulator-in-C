// This code is a simple simulation of a computer system with memory and registers.
// It allows for basic operations like loading and storing values in registers, adding and subtracting register
// values, and displaying the contents of registers and memory.
// The program uses binary representation for values and supports commands entered by the user.
// It is designed to run in a console environment and provides feedback on operations performed.
// This code is an optimazation of the program askisi_ypologisti that i write in my university in 2020.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4
#define M 10
#define MAX_LINE 50

int memory[M][N];
int R1[N];
int R2[N];

// Initialize memory and registers with random values
void boot() {
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            memory[i][j] = rand() % 2;

    for (int i = 0; i < N; i++) {
        R1[i] = rand() % 2;
        R2[i] = rand() % 2;
    }
}

// Load memory word into register
int load(int reg[], int address) {
    if (address < 0 || address >= M) return 0;
    for (int i = 0; i < N; i++) reg[i] = memory[address][i];
    return 1;
}

// Store register into memory
int store(int reg[], int address) {
    if (address < 0 || address >= M) return 0;
    for (int i = 0; i < N; i++) memory[address][i] = reg[i];
    return 1;
}

// Convert binary array to decimal
int toDecimal(int bin[]) {
    int value = 0, factor = 1;
    for (int i = N - 1; i >= 0; i--) {
        value += bin[i] * factor;
        factor *= 2;
    }
    return value;
}

// Convert decimal to binary array
void toBinary(int value, int bin[]) {
    for (int i = N - 1; i >= 0; i--) {
        bin[i] = value % 2;
        value /= 2;
    }
}

// Add R1 + R2 → R1 or R2
void addRegisters(int target[]) {
    int sum = toDecimal(R1) + toDecimal(R2);
    if (sum > 15)
        memset(target, 0, N * sizeof(int));
    else
        toBinary(sum, target);
}

// Subtract A - B → target
void subRegisters(int target[], int a[], int b[]) {
    int diff = toDecimal(a) - toDecimal(b);
    if (diff < 0)
        for (int i = 0; i < N; i++) target[i] = 1;
    else
        toBinary(diff, target);
}

// Display register content
void displayRegister(const char *name, int reg[]) {
    printf("%s: ", name);
    for (int i = 0; i < N; i++) printf("%d", reg[i]);
    printf("\n");
}

// Display memory content
void displayMemory() {
    printf("Memory:\n");
    for (int i = 0; i < M; i++) {
        printf("Address %d: ", i);
        for (int j = 0; j < N; j++) printf("%d", memory[i][j]);
        printf("\n");
    }
}

// Split input into words
void splitWords(char *input, char *w1, char *w2, char *w3) {
    sscanf(input, "%s %s %s", w1, w2, w3);
}

int main() {
    char line[MAX_LINE], word1[10], word2[10], word3[10];

    while (1) {
        printf("\nEnter command: ");
        if (!fgets(line, MAX_LINE, stdin)) break;
        line[strcspn(line, "\n")] = '\0'; // remove newline

        splitWords(line, word1, word2, word3);

        if (strcmp(word1, "BOOT") == 0) {
            boot();
            printf("System initialized.\n");

        } else if (strcmp(word1, "LOAD") == 0) {
            int addr = atoi(word3);
            if (strcmp(word2, "R1") == 0)
                printf(load(R1, addr) ? "Loaded into R1.\n" : "Invalid memory address.\n");
            else if (strcmp(word2, "R2") == 0)
                printf(load(R2, addr) ? "Loaded into R2.\n" : "Invalid memory address.\n");
            else
                printf("Invalid register name.\n");

        } else if (strcmp(word1, "STORE") == 0) {
            int addr = atoi(word3);
            if (strcmp(word2, "R1") == 0)
                printf(store(R1, addr) ? "Stored R1 into memory.\n" : "Invalid memory address.\n");
            else if (strcmp(word2, "R2") == 0)
                printf(store(R2, addr) ? "Stored R2 into memory.\n" : "Invalid memory address.\n");
            else
                printf("Invalid register name.\n");

        } else if (strcmp(word1, "ADD") == 0) {
            if (strcmp(word2, "R1") == 0)
                addRegisters(R1), printf("Addition result stored in R1.\n");
            else if (strcmp(word2, "R2") == 0)
                addRegisters(R2), printf("Addition result stored in R2.\n");
            else
                printf("Invalid register name.\n");

        } else if (strcmp(word1, "SUB") == 0) {
            if (strcmp(word2, "R1") == 0)
                subRegisters(R1, R1, R2), printf("Subtraction result stored in R1.\n");
            else if (strcmp(word2, "R2") == 0)
                subRegisters(R2, R2, R1), printf("Subtraction result stored in R2.\n");
            else
                printf("Invalid register name.\n");

        } else if (strcmp(word1, "SHOW") == 0) {
            if (strcmp(word2, "R1") == 0)
                displayRegister("R1", R1);
            else if (strcmp(word2, "R2") == 0)
                displayRegister("R2", R2);
            else
                printf("Invalid register name.\n");

        } else if (strcmp(word1, "MEM") == 0) {
            displayMemory();

        } else if (strcmp(word1, "STOP") == 0) {
            printf("Program terminated.\n");
            break;

        } else {
            printf("Unknown command.\n");
        }
    }

    return 0;
}
