# 
#  makefile - RPN (Reverse Polish) calculator simulator. 
# 
#  Copyright(C) 2019 - MT
# 
#  makefile.
#  
#  This  program is free software: you can redistribute it and/or modify it
#  under  the terms of the GNU General Public License as published  by  the
#  Free  Software Foundation, either version 3 of the License, or (at  your
#  option) any later version.
# 
#  This  program  is distributed in the hope that it will  be  useful,  but
#  WITHOUT   ANY   WARRANTY;   without even   the   implied   warranty   of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
#  Public License for more details.
# 
#  You  should have received a copy of the GNU General Public License along
#  with this program.  If not, see <http://www.gnu.org/licenses/>.
#
#	21 Aug 21   0.1	- Initial version - MT
#                    - Can now compile and link multiple programs - MT
#							- Creates separate backups - MT
# 
PROGRAMS	= gcc-commit-id
SOURCES 	= $(PROGRAMS:%=%.c)
OBJECTS	= $(SOURCES:.c=.o)
FILES		= LICENSE makefile .gitignore
CFLAGS	= -Wall -pedantic -ansi 
LFLAGS	= -lm
INCLUDE	= .
CC			= gcc

all: clean $(PROGRAMS)
.o:
	@($(CC) $^ -o $@ $(LFLAGS)) 

$(OBJECTS) : $(SOURCES)
	@$(CC) $(CFLAGS) -c $(SOURCES) -I $(INCLUDE)

clean:
	@rm -f $(OBJECTS)
	@rm -f $(PROGRAMS)

backup:
	@for name in $(PROGRAMS); do \
		echo ..\/$$name-`date +'%Y%m%d%H%M'`.tar.gz; \
		tar -czpf ..\/$$name-`date +'%Y%m%d%H%M'`.tar.gz $$name.* $(FILES);\
	done
