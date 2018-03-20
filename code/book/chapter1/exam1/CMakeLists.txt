include_directories(. ${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(
	GenSource
	DEPENDS ${GEN_SOURCES}
)

set(GEN_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

set_source_files_properties(${GEN_SOURCES} GENERATED)


add_custom_command(
	SOURCE ${PARSER_DIR}/fb1-1.l
	COMMAND flex ${PARSER_DIR}/fb1-1.l
	TARGET GenSource
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_executable(exam1 
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

add_dependencies(exam1
	GenSource
)

target_link_libraries(exam1
	-lfl
)