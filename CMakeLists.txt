# 本项目的 CMakeLists
cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(gobang)

# 设置C标准
set(CMAKE_C_STANDARD 11)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY         ${CMAKE_SOURCE_DIR}/build                    )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/release/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/debug/bin  )

# 设置输出的字符集
set (CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -g -fexec-charset=GBK")

# 创建一个 SOURCES 变量, 其中包含着所有要编译的 c 文件的链接
set(SOURCES
    src/define.c
    src/evaluate.c
    src/gameover.c
    src/makemove.c
    src/print.c
    src/searchmove.c
    src/main.c

)

# 在可执行文件中添加上述 SOURCES
add_executable(${PROJECT_NAME} ${SOURCES})

# 设置在生成该目标的指令中应该被包含的目录
# 当运行 gcc 时这些目录将像 -I/directory/path/ 被包含进来
target_include_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)
