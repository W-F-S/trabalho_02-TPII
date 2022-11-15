# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/atendente_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/atendente_autogen.dir/ParseCache.txt"
  "CMakeFiles/sistema_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/sistema_autogen.dir/ParseCache.txt"
  "atendente_autogen"
  "sistema_autogen"
  )
endif()
