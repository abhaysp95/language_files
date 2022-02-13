project(wxwidgets_sample)

find_package(wxWidgets)
include("${wxWidgets_USE_FILE}")

set(SOURCES minimal.cpp)

add_executable("${PROJECT_NAME}" WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries("${PROJECT_NAME}" "${wxWidgets_LIBRARIES}")
