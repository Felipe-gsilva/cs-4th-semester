#ifdef _33_
#define _33_
#else
typedef struct file_record {
  char *file_name;
  int struct_count;

} file_record;


typedef struct node {
  int num;
  char nome[];
} node;

int main();
#endif 
