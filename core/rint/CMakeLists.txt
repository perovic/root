############################################################################
# CMakeLists.txt file for building ROOT core/rint package
############################################################################

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../base/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../cont/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../meta/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../textinput/inc)

ROOT_GENERATE_DICTIONARY(G__Rint *.h STAGE1 MODULE Rint LINKDEF LinkDef.h OPTIONS "-writeEmptyRootPCM")

ROOT_LINKER_LIBRARY(Rint *.cxx G__Rint.cxx DEPENDENCIES Core)
ROOT_INSTALL_HEADERS()
