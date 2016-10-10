#!/bin/bash

printf "== Moving to *build* directory - creating if needed ... "
mkdir -p build
  printf "OK\n"
cd build


###
printf "== Installing Packages\n"
if conan install .. --build missing ; then
  printf "== Installed Packages OK\n"
else
  printf "== FAILED to Install Packages - Exiting\n"
  exit 1
fi


###
printf "== Creating build system\n"

# TODO - remove the DCONAN_DISABLE_CHECK_COMPILER flag
#        - some issue giving error:
#          "CMake Error at build/conanbuildinfo.cmake:151 (message):
#          "  Incorrect 'gcc' version 'compiler.version=5.3' is not the one detected by
#          "  CMake: 'GNU=5.4'
#        - flag options from https://github.com/conan-io/conan/issues/138)
#        - possible releated issues:
#          - https://github.com/conan-io/conan/issues/199
#          - https://github.com/conan-io/conan/issues/178
if cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release -DCONAN_DISABLE_CHECK_COMPILER=On ; then
  printf "== Created build system OK\n"
else
  printf "== FAILED to created build system - Exiting\n"
  exit 1
fi



###
printf "== Autobuilding (smoke test)\n"

if cmake --build . --config Release; then
  printf "== Autobuild was OK\n"
else
  printf "== FAILED to Autobuild\n - Exiting\n"
  exit 1
fi

###
printf "== Return to child directory ..."
cd ..
printf "OK\n"
exit 0
