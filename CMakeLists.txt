cmake_minimum_required(VERSION 3.15)
project(csi2372_week6 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

# --- Task 1: DataProcessor ---
add_library(DataProcessor src/DataProcessor.cpp)
target_include_directories(DataProcessor PUBLIC include)

add_executable(DataProcessor_tests tests/test_DataProcessor.cpp)
target_link_libraries(DataProcessor_tests PRIVATE DataProcessor)
add_test(NAME DataProcessor_tests COMMAND $<TARGET_FILE:DataProcessor_tests>)

# --- Task 2: Box ---
add_library(Box src/box.cpp)
target_include_directories(Box PUBLIC include)

add_executable(Box_tests tests/test_box.cpp)
target_link_libraries(Box_tests PRIVATE Box)
add_test(NAME Box_tests COMMAND $<TARGET_FILE:Box_tests>)

# --- Task 3: StorageManager ---
add_library(StorageManager src/StorageManager.cpp)
target_include_directories(StorageManager PUBLIC include)

add_executable(StorageManager_tests tests/test_StorageManager.cpp)
target_link_libraries(StorageManager_tests PRIVATE StorageManager)
add_test(NAME StorageManager_tests COMMAND $<TARGET_FILE:StorageManager_tests>)

# --- Task 4: MapContainer ---
add_library(MapContainer src/map_container.cpp)
target_include_directories(MapContainer PUBLIC include)

add_executable(MapContainer_tests tests/test_map_container.cpp)
target_link_libraries(MapContainer_tests PRIVATE MapContainer)
add_test(NAME MapContainer_tests COMMAND $<TARGET_FILE:MapContainer_tests>)

# --- Task 5: NumericPipeline ---
add_library(NumericPipeline src/NumericPipeline.cpp)
target_include_directories(NumericPipeline PUBLIC include)

add_executable(MNumericPipeline_tests tests/test_NumericPipeline.cpp)
target_link_libraries(NumericPipeline_tests PRIVATE NumericPipeline)
add_test(NAME NumericPipeline_tests COMMAND $<TARGET_FILE:NumericPipeline_tests>)