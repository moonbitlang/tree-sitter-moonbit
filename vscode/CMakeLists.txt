cmake_minimum_required(VERSION 3.19)
project(tonyfettes/tree_sitter/vscode/grep)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(target_name grep)

include(CMakePrintHelpers)
set(MOON_HOME "$ENV{MOON_HOME}")

add_library(moonbit STATIC "${MOON_HOME}/lib/runtime.c")
target_include_directories(moonbit PUBLIC "${MOON_HOME}/include")

add_custom_target(
  ${target_name}.c
  COMMAND
    moon build --target native --directory ${CMAKE_CURRENT_SOURCE_DIR}/src/grep
    --target-dir ${CMAKE_CURRENT_BINARY_DIR}/target
  BYPRODUCTS
    ${CMAKE_CURRENT_BINARY_DIR}/target/native/release/build/grep/grep.c
    ${CMAKE_CURRENT_BINARY_DIR}/target/native/release/build/grep/grep.exe)

add_executable(grep
  target/native/release/build/grep/grep.c
  .mooncakes/tonyfettes/tree_sitter/src/tree-sitter.c
  .mooncakes/tonyfettes/c/src/c.c
  .mooncakes/illusory0x0/native/src/stub.c
  .mooncakes/tonyfettes/tree_sitter_moonbit/parser.c
  .mooncakes/tonyfettes/tree_sitter_moonbit/scanner.c)
target_link_libraries(grep PRIVATE moonbit)
