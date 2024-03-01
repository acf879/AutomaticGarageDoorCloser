# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/13062/.vscode/extensions/v5.1.2/esp-idf/components/bootloader/subproject"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/tmp"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/src/bootloader-stamp"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/src"
  "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/ProgrammingProjects/AutomaticGarageDoorCloser/AutomaticGarageDoorCloser/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
