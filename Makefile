# Time-stamp: <2016-02-29 17:14:29 dmendyke>


#
# Makefile:  Builds the classic project
#


##
# Macros
cc := /usr/bin/g++
ccflags := -std=c++14  -I/home/dmendyke/dev/cc/ct
sh := /bin/bash
RM := /bin/rm
AR := /usr/bin/ar


##
# Rules
%.d : %.cc ; $(sh) ./dep.sh $<
%.o : %.cc ; $(cc) $(ccflags) -c -o $@ $<


##
files = chance name agent ship fleet application main


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


##
# Main target
all : $(target) $(dependents) ; @echo Build Completed

##
#include services/module.mk

include $(dependents)

##
# Main target
$(target) : $(objects) ; $(cc) $(ccflags) -o $@ $^


sample : sample.cc chance.o ; $(cc) $(ccflags) -o $@ $^


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
run : ; @./generate && cat log.out


##
# Remove build files
.PHONEY:	clean
clean : ; $(RM) --force $(target) $(objects) sample
nuke : clean ; $(RM) --force $(dependents)

.PHONEY: wipe
wipe:
	$(RM) --force *.d
