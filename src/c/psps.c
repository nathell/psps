/*
 * PSPS 0.1 -- Przeno¶ny S³ownik Polskiego Scrabblisty
 * Copyright (C) 2007, Daniel Janus <nathell@korpus.pl>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <inttypes.h>

int err(const char *s)
{
   fprintf(stderr, "%s\n", s);
   exit(1);
}

void read_lxa(FILE *f, uint32_t *lxa, size_t size)
{
   char *tmp = (char *)lxa;
   size_t numread;
   do {
      numread = fread(tmp, 1, size, f);
      if (numread == -1)
         err("Unexpected error while reading l.lxa");
      tmp += numread;
      size -= numread;
   } while (numread != 0);
   if (size > 0) {
      printf("%d\n", size);
      err("l.lxa not wholly read");
   }
}

char tr(uint8_t ch)
{
   const char *src = "@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_";
   const char *dst = "a±bcædeêfghijkl³mnñoóprs¶tuwyz¼¿";
   const int x = strlen(src);
   int i;
   for (i = 0; i < x; i++)
      if ((uint8_t)src[i] == ch)
         return dst[i];
   return (char)ch;
}

void dump(uint32_t *lxa, uint32_t node, char *word, int pos, FILE *out)
{
   uint32_t dest = (lxa[node] >> 10) & 0x3FFFFF;
   char ch = tr((lxa[node] >> 2) & 0xFF);
   uint32_t flag1 = (lxa[node] >> 1) & 1;
   uint32_t flag2 = lxa[node] & 1;
   word[pos] = ch;
   if (flag2) {
      word[pos + 1] = 0;
      fprintf(out, "%s\n", word);
   }
   if (dest != 0)
      dump(lxa, dest, word, pos + 1, out);
   if (flag1 == 0)
      dump(lxa, node + 1, word, pos, out);
}

int main(int argc, char *argv[]) 
{
   char *fname = "l.lxa";
   FILE *f, *out;
   uint32_t *lxa;
   struct stat statbuf;
   char word[256];
   
   if (argc > 1)
      fname = argv[1];
   f = fopen(fname, "rb");
   if (f == NULL)
      err("Could not open l.lxa.\n");
   out = fopen("words.txt", "w");
   if (out == NULL)
      err("Could not open words.txt for writing.");
   if (stat(fname, &statbuf) == -1)
      err("Error in stat().");
   lxa = malloc(statbuf.st_size);
   if (lxa == NULL)
      err("Out of memory.");
   read_lxa(f, lxa, statbuf.st_size);
   dump(lxa, lxa[0], word, 0, out);
   free(lxa);
   fclose(f);
   fclose(out);
}

