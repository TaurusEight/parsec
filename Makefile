# Time-stamp: <2016-03-16 16:26:21 dmendyke>


#
# Makefile:  Builds the classic project
#


##
# Macros
cc := /usr/bin/g++
ccflags := -g -std=c++14  -I/home/dmendyke/dev/cc/ct
sh := /bin/bash
RM := /bin/rm
ARFLAGS := rcs
AR := /usr/bin/ar $(ARFLAGS)
dep := $(sh) ./tools/dep.sh

##
# Rules
%.d : %.cc ; $(dep) $<
%.o : %.cc ; $(cc) $(ccflags) -c -o $@ $<


##
files = chance name hex universe agent ship fleet  \
        combatant line battle application main


##
# Empty macros
dependents =
lib =
libobjs =
cleanable =

##
target := parsec
source = $(addsuffix .cc,$(files))
objects += $(source:.cc=.o)
dependents += $(source:.cc=.d)
cleanable += $(objects) $(target)


##
# Main target
all : $(target) $(dependents) ; @echo Build Completed


##
#includes
include metric/module.mk
include $(dependents)


##
# Main target
$(target) : $(objects) $(libobjs) ; $(cc) $(ccflags) -o $@ $(objects) $(lib)


##
# Run the application and dump the log file
.PHONEY: run
run : ; @./$(target)
#run : ; @./$(target) && cat log.out


##
# Remove build files
.PHONEY:	clean
clean : ; $(RM) --force $(cleanable)
nuke : clean ; $(RM) --force $(dependents)


##
# Remove just the dependent files
.PHONEY: wipe
wipe : ; $(RM) --force *.d
