# CmakeLists.txt in TinyXML dir

# disable annoying warnings on MSVC compilers
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
	warnings_disable(CMAKE_CXX_FLAGS /wd4290) # vs2012: can't properly handle exceptions
	warnings_disable(CMAKE_CXX_FLAGS /wd4996) # vs2012: complains about unsafe standard C++ functions
	warnings_disable(CMAKE_CXX_FLAGS /wd4530) # vs2012: C++ exception handler used, but unwind semantics are not enabled
	warnings_disable(CMAKE_CXX_FLAGS /wd4503) # vs2012: decorated name length exceeded
endif()


# Adds a library called tinyxml (tinyxml.a under Linux, tinyxml.lib under Windows) from the all .h and .cpp files
file(GLOB tinyxml_headers *.h)
file(GLOB tinyxml_sources *.cpp)
add_library(tinyxml STATIC ${tinyxml_headers} ${tinyxml_sources})