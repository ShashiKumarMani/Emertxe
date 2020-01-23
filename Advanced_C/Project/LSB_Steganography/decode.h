#ifndef DECODE_H
#define DECODE_H

#include "types.h" // Contains user defined types

/* 
 * Structure to store information required for
 * encoding secret file to source Image
 * Info about output and intermediate data is
 * also stored
 */

/* Decoding function prototype */

/* Read and validate Encode args from argv */
Status read_and_validate_decode_args(char *argv[], EncodeInfo *encInfo);

/* Perform the encoding */
Status do_decoding(char *argv[], EncodeInfo *encInfo);

/* Get File pointers for i/p and o/p files */
Status open_decode_files(EncodeInfo *encInfo);

/* Store Magic String */
Status decode_magic_string(const char *magic_string, EncodeInfo *encInfo);

/* Encode secret file extenstion */
Status decode_secret_file_extn(EncodeInfo *encInfo);

/* Open out put file*/
Status open_output_file(char *argv[], EncodeInfo *encInfo);

/* Encode secret file size */
Status decode_secret_file_size(EncodeInfo *encInfo);

/* Encode secret file data*/
Status decode_secret_file_data(EncodeInfo *encInfo);

/* Encode function, which does the real encoding */
Status decode_data_to_image(char *data, int size, FILE *fptr_src_image, FILE *fptr_stego_image);

/* Encode a byte into LSB of image data array */
char decode_byte_from_lsb(char *image_buffer);

#endif
