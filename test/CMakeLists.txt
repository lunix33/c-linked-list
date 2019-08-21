enable_testing()
#find_package(Check REQUIRED)

#include_directories(${CHECK_INCLUDE_DIRS})
include_directories(. ../src)

add_executable(linkedlist_test
	main.c
)

target_link_libraries(linkedlist_test
	${LIBS}
	check
	m
	pthread
	subunit
	rt
	ini
)

add_test(linkedlist_test ${CMAKE_CURRENT_BINARY_DIR}/linkedlist_test)

