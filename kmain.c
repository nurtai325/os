void kmain() {
    char *nurtai = "Hello from Nurtai";
    char *fb = (char *) 0x000B8000;

    char *p = nurtai;
    for(int i = 0; *p != '\0'; i+=2, p++) {
        *(fb+i)= *p;
    }
}
