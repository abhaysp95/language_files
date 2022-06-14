set(CUBOID  "./cuboid.cpp" "./cuboid.hpp")
set(CYLINDER "./cylinder.hpp" "./cylinder.cpp")
set(PACKAGE "./package.hpp" "./package.cpp")
set(TLOAD "./truckload.hpp" "./truckload.cpp")

add_executable(cuboid1 "./ex11_02.cpp" ${CUBOID})
add_executable(cuboid2 "./ex11_09.cpp" ${CUBOID})
# add_executable(cylinder "./ex11_11.cpp" ${CYLINDER})
add_executable(truckload "./ex11_14.cpp" ${CUBOID} ${PACKAGE} ${TLOAD})
