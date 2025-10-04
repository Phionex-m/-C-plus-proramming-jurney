cmake_minimum_required(VERSION 3.10)
project(Ons LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Windows-specific settings
if(WIN32)
    if(MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
        set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SUBSYSTEM:WINDOWS")
        set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SUBSYSTEM:WINDOWS")
    else()
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
    endif()
    # Ensure Unicode
    add_definitions(-DUNICODE -D_UNICODE)
endif()

# Source files including resource
add_executable(Ons 
    main.cpp
    zikr.cpp
    resource.rc
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