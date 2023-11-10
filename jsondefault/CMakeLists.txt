add_executable( jsondefault jsondefault.cpp)
target_link_libraries(jsondefault PRIVATE nlohmann_json::nlohmann_json)