#include <stdlib.h>

#include "common.h"
#include "memory.h"
#include "vm.h"

void* reallocate(void* previous, size_t oldSize, size_t newSize)
{
	if(newSize == 0)
	{
		free(previous);
		return NULL;
	}

	return realloc(previous, newSize);
}

static freeObject(Obj* object)
{
	switch(obj->type)
	{
		case OBJ_STRING:
		{
			ObjString* string = (ObjString*)Object;
			FREE_ARRAY(char, string->chars, string->length+1);
			FREE(OBJ_STRING, object);
			break;
		}
	}
}

void freeObjects()
{
	Obj* object = vm.objects;
	while(object != NULL)
	{
		Obj* next = object->next;
		freeObject(object);
		object=next;
	}
}