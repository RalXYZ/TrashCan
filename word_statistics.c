#include <stdio.h>
#include <stdbool.h>
bool isLetter (char input); // to judge whether a character is a letter
int main () {
    FILE *fp;
    if (!(fp = fopen("input.txt", "r"))) { // change the file name into yours
        printf("File open error!\n");
        exit(0);
    }

    int sum = 0; // max_Amount: 2147483647
    char currentChar;
    bool currentCharJudge = false, previousCharJudge = false; // a necessary initialization, to guarantee the performance of the loop below
    do {
        currentChar = fgetc(fp);
        if (isLetter(currentChar))
            currentCharJudge = true;
        else
            currentCharJudge = false;
        if (!(currentCharJudge) && previousCharJudge)
            ++sum;
        previousCharJudge = currentCharJudge;
    } while (currentChar != EOF);

    printf("The amount of word in this paragraph is: %d", sum);

    if (fclose (fp)) {
        printf("File close error!\n");
        exit(0);
    }
    return 0;
}
bool isLetter (char input) {
    if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
        return true;
    else
        return false;
}
