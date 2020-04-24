# Sandbox CMakeLists.txt

add_executable(Sandbox main/SandboxApp.cpp)

target_link_libraries(Sandbox PUBLIC 
                        Stupefy
                        Qt5::Widgets
                        )