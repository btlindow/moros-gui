# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/moros-gui_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/moros-gui_autogen.dir/ParseCache.txt"
  "moros-gui_autogen"
  )
endif()
