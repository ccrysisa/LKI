long int add(long int x) {
    return x + x;
}

double div(long int x) {
    return 1 / x;
}

int main() {
    long int i = 0;
    while(1) {
        i++;
        add(i);
        div(i);
    }
    return 0;
}
