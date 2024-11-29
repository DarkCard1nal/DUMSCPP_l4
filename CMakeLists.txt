# CMakeList.txt: проект CMake для l4; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.15)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("l4")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Добавьте источник в исполняемый файл этого проекта.
#add_executable(task4 main.cpp image.cpp pgma_strategy.hpp ppm_strategy.hpp image_format_strategy.hpp)
add_library(image image.cpp pgma_strategy.hpp ppm_strategy.hpp image_format_strategy.hpp)
add_executable(task4 main.cpp)
target_link_libraries(task4 image)

add_library(image_v2 v2/image.cpp v2/image.hpp v2/pgma_image.hpp v2/ppm_image.hpp)
add_executable(task4_v2 v2/main.cpp)
target_link_libraries(task4_v2 image_v2)

target_include_directories(image_v2 PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(task4_v2 PRIVATE ${CMAKE_SOURCE_DIR})

target_include_directories(image PRIVATE ${CMAKE_SOURCE_DIR})
target_include_directories(task4 PRIVATE ${CMAKE_SOURCE_DIR})
