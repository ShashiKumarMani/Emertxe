
#ifndef TFTP_FILE
#define TFTP_FILE

#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include "tftp.h"
/* Function design for file operation functions */
int file_open_read();
int file_buffer_from_pos();
int file_open_write();
int file_append_from_buffer();
int file_close();

#endif
