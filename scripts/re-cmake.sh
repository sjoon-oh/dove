#!/bin/bash
#
# github.com/sjoon-oh/dove
# Author: Sukjoon Oh, sjoon@kaist.ac.kr

project_home="dove"
workspace_home=`basename $(pwd)`

warning='\033[0;31m[WARNING]\033[0m '
normalc='\033[0;32m[MESSAGE]\033[0m '

#
# Setting proj home
if [[ ${workspace_home} != ${project_home} ]]; then
    printf "${warning}Currently in wrong directory: `pwd`\n"
    exit
fi

printf "${normalc}$(basename "$0") started.\n"

rm -rf CMakeFiles
rm -rf CMakeCache.txt
cmake .

make -j

printf "${normalc}$(basename "$0") finished.\n"
