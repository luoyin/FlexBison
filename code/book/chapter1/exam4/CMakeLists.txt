include_directories(. ${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(
	GenSource_exam1_4
	DEPENDS ${GEN_SOURCES}
)

set(GEN_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

set_source_files_properties(${GEN_SOURCES} GENERATED)


add_custom_command(
	SOURCE ${PARSER_DIR}/fb1-4.l
	COMMAND flex ${PARSER_DIR}/fb1-4.l
	TARGET GenSource_exam1_4
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_executable(exam4
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

add_dependencies(exam4
	GenSource_exam1_4
)

target_link_libraries(exam4
	-lfl
)