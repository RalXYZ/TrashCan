#include <stdio.h>
void accAdd(int x, int y, int *na, int *nb);
int main() {
    struct core {
        char ch[1000]="\0";
        int num[1000]={0};
    } a, b;
    int x,y;
    scanf("%s", &a.ch);
    scanf("%s", &b.ch);
    for (x=0; a.ch[x]!='\0'; x++)
        a.num[x]=a.ch[x]-48;
    for (y=0; b.ch[y]!='\0'; y++)
        b.num[y]=b.ch[y]-48;
    if (x>y)
        accAdd(x, y, a.num, b.num);
    else
        accAdd(y, x, b.num, a.num);
    return 0;
}
void accAdd(int x, int y, int *na, int *nb) {
    int temp=x-1;
    while (x>0&&y>0) { //数组每个元素对应相加
        x--;
        y--;
        na[x]+=nb[y];
    }
    for (int i=temp; i>0; i--) //进位
        if (na[i]>=10) {
            na[i]-=10;
            na[i-1]++;
        }
    for (int i=0; i<=temp; i++)
        printf("%d", na[i]);
    return;
}