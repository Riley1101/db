#define EXIT_SUCCESS 0;
#define EXIT_FAILURE -1;
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

void print_usage(char *argv[]){
  printf("Usage %s -n -f <database file>\n", argv[0]);
  printf("\t -n - create new database file\n");
  printf("\t -f - (required) path to database file\n");
  return;
}

int main(int argc, char *argv[]) {
  int c;
  bool newfile = false;
  char *filepath = NULL;

  while ((c = getopt(argc, argv, "nf:")) != -1) {
    switch (c) {
    case 'n':
      newfile = true;
      break;
    case 'f':
      filepath = optarg;
      break;
    case '?':
      printf("Unknown option -%c\n", c);
      break;
    default:
      return EXIT_FAILURE;
    }
  }

  if (filepath == NULL) {
    printf("Filepath is required argument\n");
    print_usage(argv);
    return EXIT_SUCCESS;
  }

  printf("New file %d\n", newfile);
  printf("New path %s\n", filepath);

  return EXIT_SUCCESS;
}
