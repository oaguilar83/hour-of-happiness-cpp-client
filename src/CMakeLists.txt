add_executable(HoHClient main.cpp)

find_package(Curses REQUIRED)

target_include_directories(HoHClient PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(HoHClient PRIVATE ${CURSES_INCLUDE_DIR})

target_link_libraries(HoHClient PRIVATE cpr::cpr)
target_link_libraries(HoHClient PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(HoHClient PRIVATE ${CURSES_LIBRARIES})
