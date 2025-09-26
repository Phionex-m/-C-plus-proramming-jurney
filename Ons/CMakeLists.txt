
cmake_minimum_required(VERSION 3.10)
project(Ons LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific settings to hide CMD window
if(WIN32)
    if(MSVC)
        # For Visual Studio compiler
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
        set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SUBSYSTEM:WINDOWS")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SUBSYSTEM:WINDOWS")
    else()
        # For MinGW/GCC compiler
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
endif()

# Source files
add_executable(Ons 
    main.cpp
    zikr.cpp
)

# Windows libraries
if(WIN32)
    target_link_libraries(Ons 
        kernel32 
        user32 
        gdi32 
        winmm
        shell32
    )
endif()