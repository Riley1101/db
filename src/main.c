#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include "../include/file.h"
#include "../include/common.h"

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
  struct dbhdr_t *header = NULL;

  int dbfd = -1;

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
      return STATUS_ERROR;
    }
  }

  if (filepath == NULL) {
    printf("Filepath is required argument\n");
    print_usage(argv);
    return STATUS_SUCCESS;
  }

  if (newfile) {
    dbfd = create_db_file(filepath);
    if (dbfd == STATUS_ERROR) {
      printf("Unable to create db file\n");
      return STATUS_ERROR;
    }
    if(create_db_header(dbfd, &header) == STATUS_ERROR){
      printf("Failed to create db header\n");
      return STATUS_ERROR;
    }
  }else {
    dbfd = open_db_file(filepath);
    if (dbfd == STATUS_ERROR) {
      printf("Ubable to open database file\n");
      return STATUS_ERROR;
    }
  }

  printf("New file %d\n", newfile);
  printf("New path %s\n", filepath);

  return STATUS_SUCCESS;
}
