#include <stdio.h>

typedef struct aluno {
  char nome[10];
  int idade;
  int nro_Unesp;
} _pessoa;

int main() {
  _pessoa pessoa[2];
  FILE* fp;
  fp = fopen("arquivo.txt", "w");
  for(int i = 0; i < 2; i++) {
    scanf("%s", pessoa[i].nome);
    scanf("%d", &pessoa[i].idade);
    scanf("%d", &pessoa[i].nro_Unesp);
    fprintf(fp, "%s %d %d\n", pessoa[i].nome, pessoa[i].idade , pessoa[i].nro_Unesp);
  }

  fclose(fp);

  fp = fopen("arquivo.txt", "r");
  for(int i = 0; i < 2; i++) {
    fscanf(fp, "%s", pessoa[i].nome);
    fscanf(fp, "%d", &pessoa[i].idade);
    fscanf(fp, "%d", &pessoa[i].nro_Unesp);
  }
  

  fclose(fp);
  return 0;
}
