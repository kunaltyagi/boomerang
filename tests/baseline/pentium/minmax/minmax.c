// address: 0x80488f0
int main(int argc, char *argv[], char *envp[]) {
    __size32 eax; 		// r24

    eax = argc;
    if (argc >= -2) {
        if (argc > 3) {
            eax = 3;
        }
    } else {
        eax = -2;
    }
    printf("MinMax adjusted number of arguments is %d\n", eax);
    return 0;
}

