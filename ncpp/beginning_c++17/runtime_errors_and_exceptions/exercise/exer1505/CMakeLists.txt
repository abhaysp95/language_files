SET(DB "./db.hpp" "./db.cpp")
SET(CUSTOMER "./customer.hpp" "./customer.cpp")

add_executable(exer1505
	"./exer15_05.cpp"
	${DB}
	${CUSTOMER}
	"./dbexception.hpp")
