#!/bin/sh

# The Following Vars are set by the development flake:
# - BUILD_ROOT
# - PROJECT_ROOT
# - TOP

# Exit on error
set -e

# if ENV vars are not set, error out
if [ "${BUILD_ROOT}" = "" ]; then
    echo "BUILD_ROOT is not set. Exiting..."
    exit 1
fi
if [ "${PROJECT_ROOT}" = "" ]; then
    echo "PROJECT_ROOT is not set. Exiting..."
    exit 1
fi
if [ "${TOP}" = "" ]; then
    echo "TOP is not set. Exiting..."
    exit 1
fi

# Set up build directories
if [ ! -e ${BUILD_ROOT}/synth ]; then 
    mkdir -p ${BUILD_ROOT}/synth
fi
cd ${BUILD_ROOT}/synth

# Running STA
sta -no_init -no_splash -exit ${PROJECT_ROOT}/synth/${TOP}.sta.tcl | tee ${BUILD_ROOT}/synth/timing.rpt
timing=`grep slack ${BUILD_ROOT}/synth/timing.rpt`
if [ -e ${BUILD_ROOT}/synth/timing_slack.rpt ]; then 
    rm -f ${BUILD_ROOT}/synth/timing_slack.rpt
fi
echo -e "$timing" >> ${BUILD_ROOT}/synth/timing_slack.rpt 
