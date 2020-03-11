#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int array(int amount);
int linkedList(int amount);

int main() {
    int n;  // n < 10000
    int king;
    const int loop = 1000;
    scanf("%d", &n);

    clock_t startArray = clock();
    for (int i = 0; i < loop; i++)
        king = array(n);
    clock_t endArray = clock();
    printf("The king is monkey[%d].\n", king);
    printf("The solution using array lasts: %.1lf ms.\n", (double)(endArray - startArray) / loop);

    clock_t startLinkedList = clock();
    for (int i = 0; i < loop; i++)
        king = linkedList(n);
    clock_t endLinkedList = clock();
    printf("The king is monkey[%d].\n", king);
    printf("The solution using linked list lasts: %.1lf ms.\n", (double)(endLinkedList - startLinkedList) / loop);
}

int array(int amount) {
    int monkey[10000];

    for (int i = 0; i < amount; i++)
        monkey[i] = true;

    int rest = amount;  // The rest number of the monkey
    for (int position = 0; rest > 1; position = (position + 1) % amount) {
        static int quit = 2;

        if (monkey[position])
            if (quit == 0) {
                monkey[position] = false;
                rest -= 1;
                quit = 2;
            }
            else
                quit -= 1;
    }

    for(int i = 0; ; i++)
        if (monkey[i])
            return i + 1;
}

int linkedList(int amount) {
    struct monkey {
        int number;
        struct monkey* next;
    };

    struct monkey* start = (struct monkey*)malloc(sizeof(struct monkey));
    struct monkey* current = start;
    for (int i = 1; i <= amount; i++, current = current->next) {
        current->number = i;
        if (i < amount)
            current->next = (struct monkey*)malloc(sizeof(struct monkey));
        else
            current->next = start;
    }

    struct monkey *link = NULL;
    for (int time = 0; current->next != current; time = (time + 1) % 3, current = current->next) {
        if (time == 1)
            link = current;
        else if (time == 2) {
            struct monkey* temp = current->next;
            free(current);
            link->next = temp;
            current = link;
        }
    }
    return current->number;
}
