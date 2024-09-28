#define EXIT_SUCCESS 0;
#define EXIT_FAILURE -1;
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>

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

  printf("New file %d\n", newfile);
  printf("New path %s\n", filepath);

  return EXIT_SUCCESS;
}
