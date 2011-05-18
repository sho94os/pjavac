#ifndef NODE_H
#define NODE_H

#define MAX_SYMBOL_TYPES 4
typedef enum
{
	t_symbol_var = 0,
	t_symbol_func = 1,
	t_symbol_class = 2,
	t_symbol_label = 3
} type_symbol;

typedef struct _SYMBOL
{
	char *id;
	type_symbol type;
	int line;

	union
	{
		struct
		{
			is_type_decl *type;
			bool initialized;
		} var_data;
		struct
		{
			is_type_decl *type;
			int nArgs;
			is_func_def_arg **args;
		} func_data;
/*
		struct
		{
		} class_data;

		struct
		{
		} label_data;
*/
	} data;
} SYMBOL;

typedef struct _NODE
{
	SYMBOL* symbol;

	/* AVL */
	int height;
	struct _NODE* left;
	struct _NODE* right;
} NODE;

typedef struct _SCOPE
{
	struct _SCOPE *parent;
	SYMBOL* symbol; /* the "name" of this scope */
	bool global;

	NODE *node[MAX_SYMBOL_TYPES];
} SCOPE;

#ifdef SYMTAB_C
	SCOPE* symtab;	
#else
	extern SCOPE* symtab;
#endif

/*
	SYMBOLS
*/
SYMBOL* symbol_new_var(char* id, int line, is_type_decl *type);
SYMBOL* symbol_new_func(char* id, int line, is_type_decl *retval, is_func_def_args* args);
SYMBOL* symbol_new_label(char* id, int line /*, ...*/);
SYMBOL* symbol_new_class(char* id, int line /*, ...*/);
void symbol_delete(SYMBOL* symbol);
SYMBOL* symbol_lookup(NODE* node, char* id);
SYMBOL* symbol_local_lookup(NODE* node, char* id);

/*
	SCOPES
*/
SCOPE* scope_new(SYMBOL* symbol, bool global);
void scope_push(SCOPE* scope);
void scope_pop();
void scope_delete(SCOPE* scope);

SYMBOL* scope_insert(SCOPE* scope, SYMBOL* symbol);
SYMBOL* scope_lookup(SCOPE* scope, char *id, type_symbol type);
SYMBOL* scope_local_lookup(SCOPE* scope, char *id, type_symbol type);

/*
	AVL
*/
NODE* node_new(SYMBOL *symbol);
void node_delete(NODE* node);
NODE* node_insert(NODE* node, SYMBOL *symbol);
int node_height(NODE* node);

NODE* RightRot(NODE* root, NODE* pivot);
NODE* LeftRot(NODE* root, NODE* pivot);
NODE* LL(NODE* root);
NODE* RR(NODE* root);
NODE* LR(NODE* root);
NODE* RL(NODE* root);

#endif
