project("${PROJECT_NAME}.Task1")

file(GLOB_RECURSE SRC_LIST "main/*.cpp")

add_executable(${PROJECT_NAME} ${SRC_LIST})
