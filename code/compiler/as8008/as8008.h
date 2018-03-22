#ifndef __AS8008_H__
#define __AS8008_H__

typedef enum _oprand_type
{
	OPRAND_IMM,
	OPRAND_ADDRESS
} e_oprand_type;

typedef struct _ins
{
	int length;
	char data[3];
} s_ins;

typedef struct _ins_ref
{
	unsigned char cmd;
	e_oprand_type oprandType;
	char *reflabel;
} s_ins_ref;

typedef struct _ref
{
	char *reflabel;
	int value;
} s_ref;

typedef struct _line
{
	int lineno;
	int type;
	union
	{
		s_ins *pIns;
		s_ins_ref *pInsRef;
	} data;
	struct _line *prev;
	struct _line *next;
} s_line;

#endif
