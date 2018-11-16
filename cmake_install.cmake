# Install script for directory: C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/aia_project_template

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/aia")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/utils/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project0/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project1/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project2/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project3/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project4/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project5/cmake_install.cmake")
  include("C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/project6/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/Admin/Documents/Education/MAIA-Italia/AdvancedImageAnalysis/Projects/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
