#include <stdio.h>
#include <stdbool.h>
bool isLetter (char input); // 判断一个字符是否为英文字母
int main () {
    FILE *fp;
    if (!(fp = fopen("input.txt", "r"))) { // 请将文件名改为你想判断的文件的文件名
        printf("File open error!\n");
        exit(0);
    }
////////////////////////////////////////////////////////////////////////////////
    int sum = 0; // 最大单词数: 2147483647
    char currentChar;
    bool currentCharJudge = false, previousCharJudge = false; // 一个必要的初始化，它与以下的do-while的第一次循环的正确执行有关
        currentChar = fgetc(fp);
        if (isLetter(currentChar))
            currentCharJudge = true;
        else
            currentCharJudge = false;
        if (!(currentCharJudge) && previousCharJudge)
            ++sum;
        previousCharJudge = currentCharJudge;
    } while (currentChar != EOF);
    printf("The amount of word in this paragraph is: %d\n", sum);
////////////////////////////////////////////////////////////////////////////////
    fseek(fp, 0L, SEEK_SET);
    long fileStart = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    long fileEnd = ftell(fp);
    printf("%ld", fileEnd - fileStart);
    printf("The amount of character in this paragraph is: %ld\n", fileEnd - fileStart);
////////////////////////////////////////////////////////////////////////////////
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
