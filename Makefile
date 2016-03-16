# Time-stamp: <2016-03-15 12:37:12 dmendyke>


#
# Makefile:  Builds the classic project
#


##
# Macros
cc := /usr/bin/g++
ccflags := -g -std=c++14  -I/home/dmendyke/dev/cc/ct
sh := /bin/bash
RM := /bin/rm
AR := /usr/bin/ar
dep := $(sh) ./tools/dep.sh

##
# Rules
%.d : %.cc ; $(dep) $<
%.o : %.cc ; $(cc) $(ccflags) -c -o $@ $<


##
files = chance name hex agent ship fleet combatant line battle application main


##
objects =
dependents =
targets =
libraries =


##
target := parsec
source = $(addsuffix .cc,$(files))
objects += $(source:.cc=.o)
dependents += $(source:.cc=.d)
web_elements = js/parsec.html js/parsec.css

##
# Main target
all : $(target) $(dependents) $(web_elements) ; @echo Build Completed

##
#include services/module.mk
include js/module.mk
include $(dependents)

##
# Main target
$(target) : $(objects) ; $(cc) $(ccflags) -o $@ $^


sample : sample.cc ship.o combatant.o chance.o ; $(cc) $(ccflags) -o $@ $^


##
# Debugging rule
.PHONEY: dump
dump:
	@echo TARGETS: $(target)
	@echo OBJECTS: $(objects)
	@echo DEPENDENTS: $(dependents)
	@echo LIBRARIES: $(libraries)


##
# Run the application and dump the log file
.PHONEY: run
run : ; @./$(target)
#run : ; @./$(target) && cat log.out


##
# Remove build files
.PHONEY:	clean
clean : ; $(RM) --force $(target) $(objects) $(web_elements)
nuke : clean ; $(RM) --force $(dependents)

.PHONEY: wipe
wipe:
	$(RM) --force *.d
