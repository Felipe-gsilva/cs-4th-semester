#include <stdio.h>
#include <string.h>

int main() {
  FILE *in, *out;
  in = fopen("dados.txt", "r");
  out = fopen("indices.txt", "w");

  int stride = 0;
  int offset = 4;
  int c ;
  void* ptr;
  char* c_ptr;
  int unesp;

  while(!feof(in)) {
    fscanf(in, "%d", &c);
    printf("%d", c);

  }

  fclose(in);
  fclose(out);
  return 0;
}
