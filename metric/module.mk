# Time-stamp: <2016-03-16 16:25:41 dmendyke>


#
# Metric Module
#


#
# Using this library in another Makefile requires the following macros:
#   lib : added to the end of the command line to build the main target
#   libobjs : used to build a list of library objects required
#   cleanable : define the files that are to be deleted
#


##
# Module Macros
metric_target := metric/libmetric.a
metric_list := metric/point.cc
metric_objects := $(metric_list:.cc=.o)

##
# System Macros
lib += -L./metric -lmetric
libobjs += $(metric_target)
cleanable += $(metric_target) $(libobjs) $(metric_objects)
dependents += $(metric_list:.cc=.d)


##
# Module Targets
$(metric_target) : $(metric_objects) ; $(AR) $@ $^
