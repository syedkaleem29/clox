#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char* argv[])
{
	Chunk chunk;

	initVM();

	initChunk(&chunk);

	int constant = addConstant(&chunk, 1.2);
	writeChunk(&chunk, OP_CONSTANT, 120);
	writeChunk(&chunk, constant, 120);
	writeChunk(&chunk, OP_RETURN, 130);

	//disassembleChunk(&chunk, "test chunk");

	InterpretResult status = interpret(&chunk);

	freeVM();
	freeChunk(&chunk);
	return 0;
}