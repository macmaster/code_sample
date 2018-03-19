// main.c
// manipulates a png with libpng
// Author: Ronald Macmaster
// Date: 03/19/2018

#include <stdio.h>
#include <stdlib.h>

#include <zlib.h>
#include <png.h>

// reads a png file
int read_png (char *filename);

int main (int argc, char **argv) {
  if (argc < 2) {
    printf("usage: %s [png_file]\n", argv[0]);
    exit(1);
  } else {
    printf("%s: manipulating %s\n", argv[0], argv[1]);
  }

  return read_png(argv[1]);
}

int read_png (char *filename) {
  png_structp png_ptr;
  png_infop info_ptr;
  png_uint_32 width, height;
  int bit_depth, color_type, interlace_type;
  FILE *fp;
  
  if (!(fp = fopen(filename, "rb")))
    return 1;
  
  png_ptr = png_create_read_struct(
    PNG_LIBPNG_VER_STRING,
    NULL, NULL, NULL
  );

  if (!png_ptr) {
    fclose(fp);
    return 1;
  }

  info_ptr = png_create_info_struct(png_ptr);
  if (!info_ptr) {
    fclose(fp);
    png_destroy_read_struct(
      &png_ptr,
      NULL,
      NULL
    );
    return 1;
  }

  if (setjmp(png_jmpbuf(png_ptr))) {
    fclose(fp);
    png_destroy_read_struct(
      &png_ptr,
      NULL,
      NULL
    );
    return 1;
  }

  png_init_io(png_ptr, fp);
  printf("%s init finished.\n", filename);
  return 0;  
}
