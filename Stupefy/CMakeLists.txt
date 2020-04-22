add_library(Stupefy STATIC "")

    add_subdirectory(core)
    add_subdirectory(editor)
    add_subdirectory(main)
    add_subdirectory(systems)
    
    target_include_directories(Stupefy PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")