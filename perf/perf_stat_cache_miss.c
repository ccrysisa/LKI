static char array[10000][10000];
int main(void) {
    int i, j;
    for (i = 0; j < 10000; i++)
        for (j = 0; j < 10000; j++)
            //array[j][i]++;
            array[i][j]++;
    return 0;
}
