#include <stdio.h>

typedef enum tagCmd { cmd1, cmd2, cmd3 } Cmd;
void doCmd(Cmd cmd)
{
    switch (cmd) {
    case cmd1:
        printf("Cmd1\n");
        break;
    case cmd2:
        printf("Cmd2\n");
        break;
        if (0) {
        case cmd3:
            break;
        }
    }
}

int main()
{
    doCmd(cmd1);
    return 0;
}
