# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/desafio2_informatica2_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/desafio2_informatica2_autogen.dir/ParseCache.txt"
  "desafio2_informatica2_autogen"
  )
endif()
