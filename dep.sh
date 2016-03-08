#!/bin/bash
# Time-stamp: <2016-03-07 09:06:56 dmendyke>

#
# dep.sh:  Generate the dependency file for source files
#

##
# Variables
dep=${1%.*}.d
obj=${1%.*}.o
std="-std=c++14"

##
# Command to create the dependency file
/usr/bin/g++ ${std} -c -MM -MT ${obj} -MT ${dep} -MF ${dep} $1
