# Examples CMakeLists.txt

# Add example files to installation
install(FILES
    pythagorean.mf
    triangle_inequality.mf
    DESTINATION share/mathforge/examples
)

# Optionally, add a custom target to test examples
add_custom_target(examples
    COMMENT "Example MathForge programs"
)
