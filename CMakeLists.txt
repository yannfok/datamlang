project (hello)
include_directories(${CMAKE_JS_INC})
file(GLOB SOURCE_FILES "./src/*.cc" "./include/*.h")
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${CMAKE_JS_SRC} include/Transpiler.h src/Transpiler.cc)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "" SUFFIX ".node")
target_link_libraries(${PROJECT_NAME} ${CMAKE_JS_LIB})
include_directories(C:/Users/yanni/AppData/Local/node-gyp/Cache/12.16.1/include/node)#Change this to your node executable path
include_directories(C:/Users/yanni/CLionProjects/DataMLang/node_modules/nan)