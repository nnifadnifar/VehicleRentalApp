# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\rental_motor_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\rental_motor_autogen.dir\\ParseCache.txt"
  "rental_motor_autogen"
  )
endif()
