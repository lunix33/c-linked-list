enable_testing()
#find_package(Check REQUIRED)

#include_directories(${CHECK_INCLUDE_DIRS})
include_directories(. ../src)

set(CMAKE_BUILD_TYPE "Debug")

add_executable(linkedlist_test
	main.c
	create_free/ll_create.c
	create_free/ll_free.c
	push/ll_push_back.c
)

target_link_libraries(linkedlist_test
	${LIBS}
	check
	m
	pthread
	linkedlist
)

add_test(linkedlist_test ${CMAKE_CURRENT_BINARY_DIR}/linkedlist_test)

