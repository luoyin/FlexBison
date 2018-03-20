include_directories(. ${CMAKE_CURRENT_BINARY_DIR})

set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_custom_target(
	GenSource_parser
	DEPENDS ${GEN_SOURCES}
)

set(GEN_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c
	${CMAKE_CURRENT_BINARY_DIR}/parser.tab.h
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
)

set_source_files_properties(${GEN_SOURCES} GENERATED)

add_custom_command(
	SOURCE ${PARSER_DIR}/parser.y
	COMMAND bison -d ${PARSER_DIR}/parser.y
	TARGET GenSource_parser
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c ${CMAKE_CURRENT_BINARY_DIR}/parser.tab.h
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_custom_command(
	SOURCE ${PARSER_DIR}/parser.l
	COMMAND flex ${PARSER_DIR}/parser.l
	TARGET GenSource_parser
	OUTPUTS ${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	WORKING_DIRECTORY ${PARSER_DIR}
)

add_executable(armas
	${CMAKE_CURRENT_BINARY_DIR}/lex.yy.c
	${CMAKE_CURRENT_BINARY_DIR}/parser.tab.c
	parser.c
)

add_dependencies(armas
	GenSource_parser
)

target_link_libraries(armas
	-lfl
)
