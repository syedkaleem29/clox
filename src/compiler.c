#include <stdio.h>

#include "common.h"
#include "compiler.h"
#include "scanner.h"

typedef struct{
	Token current;
	Token previous;
} Parser;

Parser parser;

static void advance()
{
	parser.previous = parser.current;

	for(;;)
	{
		parser.current = scanToken();
		if(parser.current.type != TOKEN_ERROR) break;

		errorAtCurrent(parser.current.start);
	}
}

void compile(const char* source, Chunk* chunk)
{
	initScanner(source);
	advance();
	expression();
	consume(TOKEN_EOF, "Expect end of expression");

	int line = -1;
	for(;;)
	{
		Token token = scanToken();
		if(token.line != line)
		{
			printf("%4d ", token.line);
			line = token.line;
		}
		else
		{
			printf("    | ");
		}

		printf("%2d '%.*s'", token.type, token.length, token.start);

		if(token.type == TOKEN_EOF) break;
	}
}