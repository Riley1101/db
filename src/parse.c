#include "../include/parse.h"
#include "../include/common.h"
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int create_db_header(int fd, struct dbheader_t **headerOut) {
  struct dbheader_t *header = calloc(1,sizeof(struct dbheader_t));
  if (header == -1) {
    printf("Malloc failed to create db header\n");
    return STATUS_ERROR;
  }
  header->version = 0x1;
  header->count = 0;
  header->magic = HEADER_MAGIC;
  header->filesize = sizeof(struct dbheader_t);

  return STATUS_SUCCESS;
}

int validate_db_header(int fd, struct dbheader_t **headerOut){
  if (fd < 0) {
    printf("Got a bad FD from user\n");
    return STATUS_ERROR;
  }  
  struct dbheader_t *header = calloc(1, sizeof(struct dbheader_t)) ;
  if (header == -1 ) {
    printf("Malloc failed\n");
    return STATUS_ERROR;
  }
}
