SET(BOX "./box.hpp" "./box.cpp")
SET(CUBOID "./cuboid.hpp" "./cuboid.cpp")
SET(TRUCKLOAD "./truckload.hpp" "./truckload.cpp")

add_executable(ex1201 "./ex12_01.cpp" ${BOX})
add_executable(ex1202 "./ex12_02.cpp" ${BOX})
add_executable(ex1203 "./ex12_03.cpp" ${BOX})
add_executable(ex1204 "./ex12_04.cpp" ${BOX})
add_executable(ex1209 "./ex12_09.cpp" ${BOX})
add_executable(ex1210 "./ex12_10.cpp" ${TRUCKLOAD} ${CUBOID})
add_executable(ex1211 "./ex12_11.cpp" ${TRUCKLOAD} ${CUBOID})
add_executable(ex1212 "./ex12_12.cpp" "./message.hpp")

add_executable(functor "./functor.cpp" "./volume.hpp" ${CUBOID})
