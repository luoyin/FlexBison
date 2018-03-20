include_directories(. ${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(
	GenSource_exam1_5
	DEPENDS ${GEN_SOURCES}
)

set(GEN_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/fb1-5.tab.c
	${CMAKE_CURRENT_BINARY_DIR}/fb1-5.tab.h
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

set_source_files_properties(${GEN_SOURCES} GENERATED)

add_custom_command(
	SOURCE ${PARSER_DIR}/fb1-5.y
	COMMAND bison -d ${PARSER_DIR}/fb1-5.y
	TARGET GenSource_exam1_5
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/fb1-5.tab.c ${CMAKE_CURRENT_BINARY_DIR}/fb1-5.tab.h
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_custom_command(
	SOURCE ${PARSER_DIR}/fb1-5.l
	COMMAND flex ${PARSER_DIR}/fb1-5.l
	TARGET GenSource_exam1_5
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_executable(exam5
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	${CMAKE_CURRENT_BINARY_DIR}/fb1-5.tab.c
)

add_dependencies(exam5
	GenSource_exam1_5
)

target_link_libraries(exam5
	-lfl
)