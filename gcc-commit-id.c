/*
 * gcc-commit-id.c - Display program version with commit id.
 *
 * Copyright(C) 2021 - MT
 *
 * Demonstrates how to display the git commit ID in the program version. 
 * 
 * This  program is free software: you can redistribute it and/or modify it
 * under  the terms of the GNU General Public License as published  by  the
 * Free  Software Foundation, either version 3 of the License, or (at  your
 * option) any later version.
 *
 * This  program  is distributed in the hope that it will  be  useful,  but
 * WITHOUT   ANY   WARRANTY;   without even   the   implied   warranty   of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You  should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * 22 Jun 21   0.1   - Initial version - MT
 * 
 */

#define NAME           "gcc-commit-id"
#define VERSION        "0.1"
#define BUILD          "0001"
#define DATE           "22 Aug 21"
#define AUTHOR         "MT"
 
#include <stdio.h>     /* fprintf(), etc. */
#include "gcc-commit-id.h" 

void v_version(int b_verbose) { /* Display version information */

   fprintf(stderr, "%s: Version %s %s", NAME, VERSION, CHECKSUM);
   if (__DATE__[4] == ' ') fprintf(stderr, " 0"); else fprintf(stderr, " %c", __DATE__[4]);
   fprintf(stderr, "%c %c%c%c %s %s", __DATE__[5],
      __DATE__[0], __DATE__[1], __DATE__[2], __DATE__ +9, __TIME__ );
   fprintf(stderr, " (Build: %s)\n", BUILD );
   if (b_verbose) {
      fprintf(stderr, "Copyright(C) %s %s\n", __DATE__ +7, AUTHOR);
      fprintf(stderr, "License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>.\n");
      fprintf(stderr, "This is free software: you are free to change and redistribute it.\n");
      fprintf(stderr, "There is NO WARRANTY, to the extent permitted by law.\n");
   }
}

int main() {
   v_version(0);
   return(0);
}
