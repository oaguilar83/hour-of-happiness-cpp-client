add_executable(HoHClient main.cpp)

target_include_directories(HoHClient PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(HoHClient PRIVATE cpr::cpr)
target_link_libraries(HoHClient PRIVATE nlohmann_json::nlohmann_json)
