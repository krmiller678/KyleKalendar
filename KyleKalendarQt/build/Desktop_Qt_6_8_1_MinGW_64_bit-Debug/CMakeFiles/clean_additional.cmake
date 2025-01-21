# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\KyleKalendarQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\KyleKalendarQt_autogen.dir\\ParseCache.txt"
  "KyleKalendarQt_autogen"
  )
endif()
