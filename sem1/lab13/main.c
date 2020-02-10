#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void append(char* s, char c) {
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
}


char *deleteSingleSymbolWords1(char *buffer, int textSize) {
    printf("first method\n");
    char *delimiters = "\" ,.";
    char *resString = (char *) calloc(textSize, sizeof(char));
    strncat(resString, buffer, 1);

    for (int j = 1; j < textSize - 1; ++j) {
        char left = buffer[j - 1];
        char right = buffer[j + 1];
        char middle = buffer[j];


        if (strchr(delimiters, left) != NULL && strchr(delimiters, right) != NULL && strchr(delimiters, middle) == NULL) {
            printf("single letter word %c\n", middle);
        } else {
            append(resString, middle);
        }
    }
    strcat(resString, &buffer[textSize - 1]);
    return resString;
}

char* deleteSingleSymbolWords2(char *buffer, int textSize) {
    printf("\n\nsecond method\n");
    char *resString = (char *) calloc(textSize, sizeof(char));
    strncat(resString, buffer, 1);

    for (int j = 1; j < textSize - 1; ++j) {
        char left = buffer[j - 1];
        char right = buffer[j + 1];
        char middle = buffer[j];


        if ((left == '\"' || left == ',' || left == '.' || left == ' ') &&
                (right == '\"' || right == ',' || right == '.' || right == ' ') &&
                (middle != '\"' && middle != ' ' && middle != ',' && middle != '.')) {
            printf("single letter word %c\n", middle);
        } else {
            append(resString, middle);
        }
    }
    strcat(resString, &buffer[textSize - 1]);
    return resString;
}

int main() {

    FILE *inputFile = fopen("text.txt", "r");

    if (inputFile == NULL) {
        printf("Couldn't open the file\n");
        return 0;
    }

    char *buffer;
    int textSize = 0;

    //getting file size
    fseek(inputFile, 0L, SEEK_END);
    textSize = ftell(inputFile);

    //reset the file position indicator to the beginning of the file
    fseek(inputFile, 0L, SEEK_SET);

    buffer = (char *) calloc(textSize, sizeof(char));

    fread(buffer, sizeof(char), textSize, inputFile);
    fclose(inputFile);


    FILE *outputFile = fopen("new_text1.txt", "w");
    fputs(deleteSingleSymbolWords1(buffer, textSize), outputFile);
    fclose(outputFile);

    outputFile = fopen("new_text2.txt", "w");
    fputs(deleteSingleSymbolWords2(buffer, textSize), outputFile);
    fclose(outputFile);

}
