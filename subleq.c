#include <stdio.h>

#define BYTES (9999)

static int pc = 0; 
static int mem[BYTES];

static void subleq(){
  int a = mem[pc++],b = mem[pc++],c = mem[pc++];
  if(a < 0) mem[b] += (int)getchar();
  else if(b < 0) printf("%c", (char)mem[a]);
  else if((mem[b] -= mem[a]) <= 0) pc = c;
}

int main(int argc, char *argv[]) {
    FILE *fin = fopen(argv[1], "r");
    int *i = mem;     
    while(fscanf(fin, "%d", i++) > 0);
    while(pc >= 0) subleq();    
    return 0;
}
