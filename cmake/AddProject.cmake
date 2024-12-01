# Function to simplify adding projects
function(add_project PROJECT_NAME)
    # Create project target
    add_executable(${PROJECT_NAME}
            ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    )

    # Set output directory
    set_target_properties(${PROJECT_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    )
endfunction()