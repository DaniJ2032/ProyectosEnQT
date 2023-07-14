# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\prueba1_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\prueba1_autogen.dir\\ParseCache.txt"
  "prueba1_autogen"
  )
endif()
