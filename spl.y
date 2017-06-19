
/// You're going to need to write a top level expression type evaluator...

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <setjmp.h>

//nice to have...
#define TRY do{ jmp_buf ex_buf__; if( !setjmp(ex_buf__) ){
#define CATCH } else {
#define ETRY } }while(0)
#define THROW longjmp(ex_buf__, 1)

// For GCC - determine system arch.
#if __GNUC__
#if __x86_64__ || __ppc64__
#define ARCH_64
#else
#define ARCH_32
#endif
#endif

#ifdef ARCH_64
#define MEM_SIZE long
#else 
#define MEM_SIZE int
#endif
/* 
   Some constants.
*/

  /* These constants are used later in the code */
#define SYMTABSIZE     50
#define IDLENGTH       15
#define NOTHING        -1
#define INDENTOFFSET    2

enum ParseTreeNodeType { 
PROGRAM_NT, BLOCK_NT, DECLARATION_BLOCK_NT, IDENTIFIER_LIST_NT, IDENTIFIER_LIST_SINGLE_NT, STATEMENT_LIST_NT, STATEMENT_NT, ASSIGNMENT_STATEMENT_NT, IF_STATEMENT_NT, DO_STATEMENT_NT,
WHILE_STATEMENT_NT, FOR_STATEMENT_NT, WRITE_STATEMENT_NT, READ_STATEMENT_NT, OUTPUT_LIST_NT, FOR_ITERATOR_NT,
CONSTANT_NT, CONSTANTchl_NT, VALUE_ID_NT, VALUE_CL_NT ,VALUE_EX_NT, INTEGER_CONSTANT_NT, FLOAT_CONSTANT_NT,
COMPARATORet_NT, COMPARATORnet_NT, COMPARATORltet_NT, COMPARATORgtet_NT, COMPARATORgt_NT, COMPARATORlt_NT,
CONDITIONALand_NT, CONDITIONALor_NT, CONDITIONALnot_NT, EXPRESSIONadd_NT, EXPRESSIONminus_NT, 
EXPRESSION_NT, TERM_NT, TERMm_NT, TERMd_NT, 
CONDITIONAL_NT, CONDITIONAL_INNER_NT,
TYPEchar_NT, TYPEint_NT , TYPEreal_NT
};  

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#ifndef NULL
#define NULL 0
#endif

/* ------------- parse tree definition --------------------------- */

struct treeNode {
    MEM_SIZE  item;
    int  nodeIdentifier;
    struct treeNode *first;
    struct treeNode *second;
    struct treeNode *third;
  };
typedef int bool;
typedef  struct treeNode TREE_NODE;
typedef  TREE_NODE        *TERNARY_TREE;

/* ------------- forward declarations --------------------------- */

TERNARY_TREE create_node(int,int,TERNARY_TREE,TERNARY_TREE,TERNARY_TREE);
void destroy_nodes_from(TERNARY_TREE pt);
void diagnosticsMode(TERNARY_TREE pt);
void indentController(int direction, int * current);
void generate_output(TERNARY_TREE ParseTree);
void do_optimisations(TERNARY_TREE pt, TERNARY_TREE * feedback);
int generateTypedTable(TERNARY_TREE pt, int thingof);
void cast(TERNARY_TREE pt, TERNARY_TREE * from);
void maketypelist(TERNARY_TREE pt);
void PRINT_TREE(TERNARY_TREE pt);
void CODE_TREE(TERNARY_TREE pt);
void simplify(TERNARY_TREE pt, TERNARY_TREE * replacetree);

/* ------------- symbol table definition --------------------------- */

struct symTabNode {
    char identifier[IDLENGTH];
};

typedef  struct symTabNode SYMTABNODE;
typedef  SYMTABNODE        *SYMTABNODEPTR;

SYMTABNODEPTR  symTab[SYMTABSIZE]; 

int currentSymTabSize = 0;

%}

/****************/
/* Start symbol */
/****************/

%start  program

/**********************/
/* Action value types */
/**********************/


%union {
    int iVal;
    TERNARY_TREE  tVal;
}

/* We can declare types of tree nodes */

/* These are the types of lexical tokens -> iVal */
%token<iVal> IDENTIFIER NUMBER CHARLITERAL FLOAT
/* Some tokens do not return a value */
%token ENDP DECLARATIONS CODE OF TYPE CHARACTER INTEGER REAL IF THEN ELSE ENDIF DO ENDDO WHILE ENDWHILE FOR IS BY TO ENDFOR WRITE READ NEWLINE AND OR
%token NOT ET NET LT GT LTET GTET ADD MINUS DIVIDE MULTIPLY LCBRAC RCBRAC ASSIGN POINT COMMA SEMICOLON COLON  

/* Whereas Rules return a tVal type (Tree) */
%type<tVal> program block declaration_block identifier_list type statement_list statement assignment_statement if_statement do_statement while_statement
%type<tVal> for_statement write_statement read_statement output_list conditional conditional_inner comparator expression term constant number_constant value


%%
/* ----------------------- grammar rules --------------------------- */

/*TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1, TERNARY_TREE  p2, TERNARY_TREE  p3)*/
program : IDENTIFIER COLON block ENDP IDENTIFIER POINT
		{
			TERNARY_TREE ParseTree;
			ParseTree = create_node($1, PROGRAM_NT, $3, NULL, NULL); 
			if(ParseTree != NULL) 
			{
				generateTypedTable(ParseTree,-1);
				generate_output(ParseTree);
				destroy_nodes_from(ParseTree); //cleanup
				//symbol table also needs a cleanup routine...
			}
		}
;
block : DECLARATIONS declaration_block CODE statement_list
		{
			$$ = create_node(NOTHING, BLOCK_NT, $2, $4, NULL); 
		}
	  | CODE statement_list
		{
			$$ = create_node(NOTHING, BLOCK_NT, $2, NULL, NULL);
		}
;
declaration_block : identifier_list OF TYPE type SEMICOLON 
			{
				$$ = create_node(NOTHING, DECLARATION_BLOCK_NT, $1, $4, NULL);
			}
		      | identifier_list OF TYPE type SEMICOLON declaration_block
			{
				$$ = create_node(NOTHING, DECLARATION_BLOCK_NT, $1, $4, $6);
			}
;
identifier_list : IDENTIFIER
				{
					$$ = create_node($1, IDENTIFIER_LIST_SINGLE_NT, NULL, NULL, NULL);
				}
				| identifier_list COMMA IDENTIFIER
				{
					$$ = create_node($3, IDENTIFIER_LIST_NT, $1, NULL, NULL);
				}
;
type : CHARACTER 
		{
			$$ = create_node(NOTHING, TYPEchar_NT, NULL, NULL, NULL);
		}
	| INTEGER 
		{
			$$ = create_node(NOTHING, TYPEint_NT, NULL, NULL, NULL);
		}
	| REAL
		{
			$$ = create_node(NOTHING, TYPEreal_NT, NULL, NULL, NULL);
		}
;
statement_list : statement 
		{
			$$ = create_node(NOTHING, STATEMENT_LIST_NT, $1, NULL, NULL);
		}
		| statement_list SEMICOLON statement
		{
			$$ = create_node(NOTHING, STATEMENT_LIST_NT, $1, $3, NULL);
		}
;	
statement : assignment_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | if_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | do_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | while_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | for_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | write_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
	     | read_statement
			{
				$$ = create_node(NOTHING, STATEMENT_NT, $1, NULL, NULL);
			}
;
assignment_statement : expression ASSIGN IDENTIFIER
			{
				$$ = create_node($3, ASSIGNMENT_STATEMENT_NT, $1, NULL, NULL);
			}
;
if_statement : IF conditional THEN statement_list ELSE statement_list ENDIF 
			{
				$$ = create_node(NOTHING, IF_STATEMENT_NT, $2, $4, $6);
			}
			| IF conditional THEN statement_list ENDIF
			{
				$$ = create_node(NOTHING, IF_STATEMENT_NT, $2, $4, NULL);
			}
;
do_statement : DO statement_list WHILE conditional ENDDO
			{
				$$ = create_node(NOTHING, DO_STATEMENT_NT, $2, $4, NULL);
			}
;
while_statement : WHILE conditional DO statement_list ENDWHILE
			{
				$$ = create_node(NOTHING, WHILE_STATEMENT_NT, $2, $4, NULL);
			}
;
for_statement : FOR IDENTIFIER IS expression BY expression TO expression DO statement_list ENDFOR
			{
				$$ = create_node($2, FOR_STATEMENT_NT,(TERNARY_TREE)(create_node(NOTHING, FOR_ITERATOR_NT, $4, $6, $8)), $10, NULL);
			}
;

write_statement : WRITE LCBRAC output_list RCBRAC 
			{
				$$ = create_node(NOTHING, WRITE_STATEMENT_NT, $3, NULL, NULL);
			}
                   | NEWLINE
			{
				$$ = create_node(NOTHING, WRITE_STATEMENT_NT, NULL, NULL, NULL);
			}
;
read_statement : READ LCBRAC IDENTIFIER RCBRAC
			{
				$$ = create_node($3, READ_STATEMENT_NT, NULL, NULL, NULL);
			}
;
output_list : value
		{
			$$ = create_node(NOTHING, OUTPUT_LIST_NT, $1, NULL, NULL);
		}	
	    |  output_list COMMA value
		{
			$$ = create_node(NOTHING, OUTPUT_LIST_NT, $1, $3, NULL);
		}
;
conditional : conditional_inner
			{
				$$ = create_node(NOTHING, CONDITIONAL_NT, $1, NULL, NULL);
			}
	       |  conditional_inner AND conditional
			{
				$$ = create_node(NOTHING, CONDITIONALand_NT, $1, $3, NULL);
			}
	       | conditional_inner OR conditional
			{
				$$ = create_node(NOTHING, CONDITIONALor_NT, $1, $3, NULL);
			}
	       | NOT conditional
			{
				$$ = create_node(NOTHING, CONDITIONALnot_NT, $2, NULL, NULL);
			}
;
conditional_inner : expression comparator expression 
			{
				$$ = create_node(NOTHING, CONDITIONAL_INNER_NT, $1, $2, $3);
			}
;
comparator : ET
			{
				$$ = create_node(NOTHING, COMPARATORet_NT, NULL, NULL, NULL);
			}
	      | NET
			{
				$$ = create_node(NOTHING, COMPARATORnet_NT, NULL, NULL, NULL);
			}
	      | LT
			{
				$$ = create_node(NOTHING, COMPARATORlt_NT, NULL, NULL, NULL);
			}	
	      | GT
			{
				$$ = create_node(NOTHING, COMPARATORgt_NT, NULL, NULL, NULL);
			}
	      | LTET
			{
				$$ = create_node(NOTHING, COMPARATORltet_NT, NULL, NULL, NULL);
			}
	      | GTET
			{
				$$ = create_node(NOTHING, COMPARATORgtet_NT, NULL, NULL, NULL);
			}
;
expression : term
			{
				$$ = create_node(NOTHING, EXPRESSION_NT, $1, NULL, NULL);
			}
	      | expression ADD term
			{
				$$ = create_node(NOTHING, EXPRESSIONadd_NT, $1, $3, NULL);
			}
	      | expression MINUS term
			{
				$$ = create_node(NOTHING, EXPRESSIONminus_NT, $1, $3, NULL);
			}
;
term : value
		{
			$$ = create_node(NOTHING, TERM_NT, $1, NULL, NULL);
		}

     | term MULTIPLY value
		{
			$$ = create_node(NOTHING, TERMm_NT, $1, $3, NULL);
		}
     | term DIVIDE value
		{
			$$ = create_node(NOTHING, TERMd_NT, $1, $3, NULL);
		}
;

value : IDENTIFIER
		{
			$$ = create_node($1, VALUE_ID_NT, NULL, NULL, NULL);
		}
      | constant
		{
			$$ = create_node(NOTHING, VALUE_CL_NT, $1, NULL, NULL);
		}
      | LCBRAC expression RCBRAC
		{
			$$ = create_node(NOTHING, VALUE_EX_NT, $2, NULL, NULL);
		}
;	

constant : number_constant
			{
				$$ = create_node(NOTHING, CONSTANT_NT, $1, NULL, NULL);
			}		
	    | CHARLITERAL
			{
				$$ = create_node($1, CONSTANTchl_NT, NULL, NULL, NULL);
			}
;

number_constant : NUMBER 
			{
				$$ = create_node($1, INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			}
		| MINUS NUMBER
			{
				$$ = create_node((-$2), INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			}
		| FLOAT 
			{
				$$ = create_node($1, FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			}
		| MINUS FLOAT
			{
				*((double*)((MEM_SIZE)$2)) = -*((double*)((MEM_SIZE)$2));
				$$ = create_node($2, FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			}
;
	  
			  
			  

%%

int identityTable[50];

/* Code for routines for managing the Parse Tree */

TERNARY_TREE create_node(int ival, int case_identifier, TERNARY_TREE p1,
			 TERNARY_TREE  p2, TERNARY_TREE  p3)
{
    TERNARY_TREE t;
    t = (TERNARY_TREE)malloc(sizeof(TREE_NODE));
    t->item = ival;
    t->nodeIdentifier = case_identifier;
    t->first = p1;
    t->second = p2;
    t->third = p3;
    return (t);
}

void indentController(int direction, int * current)
{
	*current = *current + (direction * 5);
}

//for write look up table.
char *ntypes[] = {"PROGRAM_NT", "BLOCK_NT", "DECLARATION_BLOCK_NT", "IDENTIFIER_LIST_NT", "IDENTIFIER_LIST_SINGLE_NT", "STATEMENT_LIST_NT", "STATEMENT_NT",
"ASSIGNMENT_STATEMENT_NT", "IF_STATEMENT_NT", "DO_STATEMENT_NT", "WHILE_STATEMENT_NT", "FOR_STATEMENT_NT", "WRITE_STATEMENT_NT", "READ_STATEMENT_NT", "OUTPUT_LIST_NT",
"FOR_ITERATOR_NT", "CONSTANT_NT", "CONSTANTchl_NT", "VALUE_ID_NT", "VALUE_CL_NT" ,"VALUE_EX_NT", "INTEGER_CONSTANT_NT", "FLOAT_CONSTANT_NT","COMPARATORet_NT", "COMPARATORnet_NT",
"COMPARATORltet_NT", "COMPARATORgtet_NT", "COMPARATORgt_NT", "COMPARATORlt_NT", "CONDITIONALand_NT", "CONDITIONALor_NT", "CONDITIONALnot_NT", "EXPRESSIONadd_NT", "EXPRESSIONminus_NT", 
"EXPRESSION_NT", "TERM_NT", "TERMm_NT", "TERMd_NT", "CONDITIONAL_NT", "CONDITIONAL_INNER_NT", "TYPEchar_NT", "TYPEint_NT" , "TYPEreal_NT"};
void generate_output(TERNARY_TREE pt)
{	
	#ifndef DEBUG	
		printf("#include<stdio.h>\n\n");
		CODE_TREE(pt);
	#else
		diagnosticsMode(pt);
	#endif
}	

void diagnosticsMode(TERNARY_TREE pt)
{
	printf("\n/*\n--------------------diagnostics--------------------\n");
	PRINT_TREE(pt);
	printf("\n--------------------end of diag--------------------\n*/\n");
}

void PRINT_TREE(TERNARY_TREE pt)
{
	static int indent =0;
	static bool indenton = TRUE;

	if(pt==NULL) return; 

	printf("%*s",indent, " ");
	
	if(pt->nodeIdentifier == VALUE_ID_NT || pt->nodeIdentifier == CONSTANTchl_NT ||  pt->nodeIdentifier == IDENTIFIER_LIST_NT ||  pt->nodeIdentifier == IDENTIFIER_LIST_SINGLE_NT)
	{
		printf("%s has value: %s\n\n", ntypes[pt->nodeIdentifier], symTab[pt->item]->identifier);
	}
	else if(pt->nodeIdentifier == INTEGER_CONSTANT_NT)
	{
		printf("%s has value: %i\n\n", ntypes[pt->nodeIdentifier], pt->item);
	}
	else if(pt->nodeIdentifier == FLOAT_CONSTANT_NT)
	{
		printf("%s has value: %f\n\n", ntypes[pt->nodeIdentifier], *((double*)((MEM_SIZE)pt->item)));	
	}
	else 
	{
		printf("%s\n", ntypes[pt->nodeIdentifier]);	
	}

	if(indenton)
	{ 
		if(pt->nodeIdentifier == PROGRAM_NT ||  pt->nodeIdentifier == BLOCK_NT || pt->nodeIdentifier == DECLARATION_BLOCK_NT 
		||  pt->nodeIdentifier ==  STATEMENT_NT || (pt->nodeIdentifier >=7 && pt->nodeIdentifier <=13))
		{
			indentController(1, &indent); //incriment
		}
	}
	if(pt->nodeIdentifier != STATEMENT_LIST_NT && pt->nodeIdentifier != IDENTIFIER_LIST_NT)
	{
		PRINT_TREE(pt->first);	
		PRINT_TREE(pt->second);	
		PRINT_TREE(pt->third);	
	}
	else 
	{
		PRINT_TREE(pt->second);	
		PRINT_TREE(pt->first);	
	}
	if(indenton)
	{ 
		if(pt->nodeIdentifier == PROGRAM_NT ||  pt->nodeIdentifier == BLOCK_NT || pt->nodeIdentifier == DECLARATION_BLOCK_NT 
		||  pt->nodeIdentifier ==  STATEMENT_NT || (pt->nodeIdentifier >=7 && pt->nodeIdentifier <=13))
		{
			indentController(-1, &indent); //decriment
		}
	}
	
}

const int stackmaxlimit = 100;
MEM_SIZE stackdata[100];
int stackcounter=0;

void typepop()
{
	if(stackcounter>0)
	stackdata[stackcounter--]=(MEM_SIZE)NULL;
}
void typequeue()
{
	if(stackcounter>1)
	{
		memmove(stackdata, stackdata+1, sizeof(MEM_SIZE) * (stackcounter-1));
		stackcounter--;
	}
}
void typepush(MEM_SIZE newitem)
{
	if(stackcounter<stackmaxlimit)
	stackdata[stackcounter++]=newitem;
	
	//printf("push!%i\n", stackcounter);
}
MEM_SIZE typetop()
{
	if(stackcounter>0)
	return stackdata[stackcounter-1];
	else
	return NULL;
}
MEM_SIZE typebottom()
{
	if(stackcounter>0)
	return stackdata[0];
	else
	return NULL;
}
void typeclearstack()
{
	int i=0;
	for(i=0; i<stackcounter; i++)
	{
		stackdata[i]=(MEM_SIZE)NULL;
	}
	stackcounter=0;
}

int idtypes[50];
int ctype=-1;
bool firstfor=TRUE;

void CODE_TREE(TERNARY_TREE pt)
{	
	static char * carryOverId;
	static int outlistCount=0;
	static int lookAheadOnly=0;

	static int indent =0;
	if(pt==NULL) return;
	
	switch(pt->nodeIdentifier)
	{
		case PROGRAM_NT:			
			printf("int main() /*Program %s*/\n{\n", symTab[pt->item]->identifier);
			CODE_TREE(pt->first);
			printf("}/*End of Program*/\n");
			break;
		case BLOCK_NT:			
			indentController(1, &indent); //incriment
			if(pt->second == NULL)
			{ /*code only*/
				printf("%*s/*CODE*/\n",indent, " ");
				CODE_TREE(pt->first);
			}
			else
			{
				printf("%*s/*DECLARCATION_BLOCK*/\n",indent, " "); 
				CODE_TREE(pt->first);
				printf("%*s/*CODE_BLOCK*/\n",indent, " "); 
				CODE_TREE(pt->second);
			}
			indentController(-1, &indent); //decriment
			break;
		case DECLARATION_BLOCK_NT:
			if(pt->first !=NULL)
			{	
				printf("%*s", indent, "    ");
				CODE_TREE(pt->second);
				printf(" ");
				CODE_TREE(pt->first); 
				printf(";\n");
			}
			ctype=-1;
			CODE_TREE(pt->third); //are there more?
			break;
		case IDENTIFIER_LIST_NT:
			CODE_TREE(pt->first);
			idtypes[pt->item] = ctype;
			printf("%s%s", ", ", symTab[pt->item]->identifier);
			break;
		case IDENTIFIER_LIST_SINGLE_NT:
			printf("%s",symTab[pt->item]->identifier);
			idtypes[pt->item] = ctype;
			break;
		case TYPEchar_NT:
			ctype = TYPEchar_NT;
			printf("char");
			break;
		case TYPEint_NT:
			ctype = TYPEint_NT;
			printf("int");
			break;
		case TYPEreal_NT:
			ctype = TYPEreal_NT;
			printf("float");
			break;
		case STATEMENT_LIST_NT:
			CODE_TREE(pt->first); //statement list
			CODE_TREE(pt->second); //statement
			break;
		case STATEMENT_NT:
			//indentController(1, &indent); //incriment
			printf("%*s", indent, "    ");
			CODE_TREE(pt->first);
			//indentController(-1, &indent); //decriment
			printf("\n");
			break;
		case ASSIGNMENT_STATEMENT_NT:
			printf("%s",symTab[pt->item]->identifier);
			printf(" = ");
			do_optimisations(pt->first, &(pt->first));
			CODE_TREE(pt->first);
			printf(";");
			break;
		case IF_STATEMENT_NT:	
			printf("if(");
			CODE_TREE(pt->first);
			printf(")\n%*s{\n",indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			if(pt->third!=NULL)
			{
				printf("%*s}\n%*selse\n%*s{\n", indent, "    ", indent, "    ", indent, "    ");
				indentController(1, &indent); //incriment
				CODE_TREE(pt->third);
				indentController(-1, &indent); //decriment
			}
			printf("%*s}", indent, "    ");
			break;	
		case DO_STATEMENT_NT:
			printf("do\n%*s{\n", indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->first);
			indentController(-1, &indent); //decriment
			printf("%*s} while (",indent, " ");
			CODE_TREE(pt->second);
			printf(");");
			break;
		case WHILE_STATEMENT_NT:
			printf("while (");	
			CODE_TREE(pt->first);
			printf(")\n%*s{\n", indent, " ");	
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			printf("%*s}", indent, " ");
			break;	
		case FOR_STATEMENT_NT:
			if(firstfor)
			{
				printf("/*for control vars*/\n");
				printf("%*sregister int _by;\n",indent, " ");
 				printf("%*sstatic int _true=(1==1);\n",indent, " ");
				printf("%*s", indent, " ");
				firstfor = FALSE;
			}
			
			carryOverId=symTab[pt->item]->identifier;
			printf("for (%s = ",symTab[pt->item]->identifier);
			CODE_TREE(pt->first);
			printf(")\n%*s{\n",indent, " ");
			indentController(1, &indent); //incriment
			CODE_TREE(pt->second);
			indentController(-1, &indent); //decriment
			printf("%*s}", indent, " ");
			carryOverId=NULL;
			break;	
		case FOR_ITERATOR_NT:
			do_optimisations(pt->first, &(pt->first));
			do_optimisations(pt->third, &(pt->third));
			do_optimisations(pt->second, &(pt->second));
			// for (i=is; _by=by, (i-to)*((_by > 0) - (_by < 0)/_true) <= 0 ; i += _by) magic...
			printf("(");
			CODE_TREE(pt->first);	
			printf("); _by =  (");
			CODE_TREE(pt->second);
			printf("), (%s - (", carryOverId);
			CODE_TREE(pt->third);
			printf("))*(_by >0) - (_by<0/_true) <=0; %s += _by", carryOverId);
			break;	
			//first is IS. Second is BY. Third is TO. i is CarryOverId
		case WRITE_STATEMENT_NT:
			printf("printf(");
			if(pt->first==NULL)
			{
				printf("%s\\n%s);","\"","\"");
			}
			else
			{	
				lookAheadOnly = 1;
				printf("\"");
				CODE_TREE(pt->first); //for the output list...
				int copystack = stackcounter;
				int i;
				for(i=0; i<copystack; i++)
				{
					TERNARY_TREE t = (TERNARY_TREE)typebottom();
					if(t->nodeIdentifier == FLOAT_CONSTANT_NT)
					{
						printf("%%f");
					}
					else if (t->nodeIdentifier == INTEGER_CONSTANT_NT)
					{
						printf("%%i");
					}
					else if (t->nodeIdentifier == CONSTANTchl_NT)
					{
						printf("%%c");
					}
					else 
					{
						if(idtypes[t->item] == TYPEchar_NT)
						{
							printf("%%c");
						}
						else if(idtypes[t->item] == TYPEint_NT)
						{
							printf("%%i");
						}
						else if(idtypes[t->item] == TYPEreal_NT)
						{
							printf("%%f");
						}
						
					}
					
					typequeue();
				}
				typeclearstack();
				lookAheadOnly = 0;
				printf("\", ");	
				CODE_TREE(pt->first);
				printf(");");
				typeclearstack();
			}
			break;
		case READ_STATEMENT_NT:
			printf("scanf(");
			printf("\"%%%c\", ", (idtypes[pt->item] == TYPEreal_NT)? 'f' : ((idtypes[pt->item] == TYPEchar_NT)? 'c' : 'i'));
			printf("&%s",symTab[pt->item]->identifier);
			printf(");");
			break;
		case OUTPUT_LIST_NT:
			
			if(pt->second==NULL)
			{
				do_optimisations(pt->first, &(pt->first));
				maketypelist(pt->first);
				CODE_TREE(pt->first);
			}
			else
			{
				CODE_TREE(pt->first);
				if(lookAheadOnly!=1) printf(", ");
				do_optimisations(pt->second, &(pt->second));
				maketypelist(pt->second);
				CODE_TREE(pt->second);
			}
			break;
		case CONDITIONAL_NT:	
			CODE_TREE(pt->first);
			break;
		case CONDITIONALand_NT:		
			CODE_TREE(pt->first);
			printf(" && ");
			CODE_TREE(pt->second);
			break;
		case CONDITIONALor_NT:
			CODE_TREE(pt->first);
			printf(" || ");
			CODE_TREE(pt->second);
			break;
		case CONDITIONALnot_NT:
			printf("! (");
			CODE_TREE(pt->first);
			printf(")");
			break;
		case CONDITIONAL_INNER_NT:
			do_optimisations(pt->first, &(pt->first));
			CODE_TREE(pt->first);
			do_optimisations(pt->second, &(pt->second));
			CODE_TREE(pt->second);
			do_optimisations(pt->third, &(pt->third));
			CODE_TREE(pt->third);
			break;
		case COMPARATORet_NT:
			printf(" == ");
			break;
		case COMPARATORnet_NT:
			printf(" != ");
			break;
		case COMPARATORlt_NT:
			printf(" < ");
			break;
		case COMPARATORgt_NT:
			printf(" > ");
			break;
		case COMPARATORltet_NT:	
			printf(" <= ");
			break;
		case COMPARATORgtet_NT:
			printf(" >= ");
			break;
		case EXPRESSION_NT:
			CODE_TREE(pt->first);
			break;
		case EXPRESSIONadd_NT:
			CODE_TREE(pt->first);	
			printf(" + ");
			CODE_TREE(pt->second);
			break;
		case EXPRESSIONminus_NT:
			CODE_TREE(pt->first);
			printf(" - ");
			CODE_TREE(pt->second);
			break;
		case TERM_NT:
			CODE_TREE(pt->first);
			break;
		case TERMm_NT:
			CODE_TREE(pt->first);
			printf(" * ");
			CODE_TREE(pt->second);
			break;
		case TERMd_NT:
			CODE_TREE(pt->first);
			printf(" / ");
			CODE_TREE(pt->second);
			break;
		case VALUE_ID_NT:	
			//printf("identifier");
			if(lookAheadOnly==1){outlistCount++; return;};
			printf("%s",symTab[pt->item]->identifier);
			break;
		case VALUE_CL_NT:
			if(lookAheadOnly==1){outlistCount++; return;};
			CODE_TREE(pt->first);
			break;
		case VALUE_EX_NT:
			if(lookAheadOnly==1){outlistCount++; return;};
			printf("(");
			CODE_TREE(pt->first);
			printf(") ");
			break;
		case CONSTANT_NT:
			CODE_TREE(pt->first);
			break;
		case CONSTANTchl_NT:
			printf("'%s'",symTab[pt->item]->identifier);
			//printf("char");
			break;
		case INTEGER_CONSTANT_NT:
			if(lookAheadOnly==1) return;
			printf("%i", pt->item);
			break;
		case FLOAT_CONSTANT_NT:
			if(lookAheadOnly==1) return;
			double * value = (double*)((MEM_SIZE)pt->item);
			printf("%f", *value);
			break;
	}
}


enum STACKTYPE {st_CMD, st_DATA};
enum operations {o_add, o_sub, o_div, o_mul};
int CommandStack[100];

struct cmdStack
{
	MEM_SIZE stk[128];
	int count;
	
}commandStack;

struct Stack
{
	TERNARY_TREE stk[512];
	int count;
	
}nodeStack;

void wipestack(int operationalmode)
{
	if(operationalmode == st_DATA)
	{
		nodeStack.count=0;
		int i;
		for(i=0; i<nodeStack.count; i++)
		{
			nodeStack.stk[i] = NULL;
		}
	}
	else
	{
		commandStack.count=0;
		int i;
		for(i=0; i<commandStack.count; i++)
		{
			commandStack.stk[i] = (MEM_SIZE)NULL;
		}
	}
}
void push(int operationalmode, MEM_SIZE node)
{
	if(operationalmode == st_DATA)
	{
		nodeStack.stk[nodeStack.count++]=(TERNARY_TREE)node;
	}
	else
	{
		commandStack.stk[commandStack.count++]=(MEM_SIZE)node; //yes, I know...
	}
}
void pop(int operationalmode)
{
	if(operationalmode == st_DATA)
	{
		if(nodeStack.count>0)
		{
			nodeStack.stk[nodeStack.count-1];
			nodeStack.count--;
		}
	}
	else
	{
		if(commandStack.count>0)
		{
			commandStack.stk[commandStack.count-1];
			commandStack.count--;
		}
	}
}
TERNARY_TREE top(int operationalmode)
{	
	if(operationalmode == st_DATA)
	{
		if(nodeStack.count >0)
		return nodeStack.stk[nodeStack.count-1];
	}
	else
	{	
		if(commandStack.count >0)
		return commandStack.stk[commandStack.count-1];
	}
}


void do_optimisations(TERNARY_TREE pt, TERNARY_TREE * feedback)
{
	wipestack(st_DATA); wipestack(st_CMD);
	simplify(pt, feedback);
}

void simplify(TERNARY_TREE pt, TERNARY_TREE * replacetree)
{	
	//printf("%i\n", pt->nodeIdentifier);
	if (pt==NULL) return;
	switch(pt->nodeIdentifier)
	{
		case EXPRESSION_NT:
			simplify(pt->first, replacetree);
			break;
		case EXPRESSIONadd_NT:
			//printf("\n-------------------STACK:ADD\n");
			push(st_CMD,(MEM_SIZE)o_add);
			cast(pt, replacetree);
			//printf("ADD EXIT\n");
			break;
		case EXPRESSIONminus_NT:
			//printf("\n-------------------STACK:SUBTRACT\n");
			push(st_CMD,(MEM_SIZE)o_sub);
			cast(pt, replacetree);
			//printf("SUB EXIT\n");
			break;
		case TERM_NT:
			simplify(pt->first, replacetree);
			break;
		case TERMm_NT:
			//printf("\n-------------------STACK:MULTIPLY\n");
			push(st_CMD,(MEM_SIZE)o_mul);
			cast(pt, replacetree);
			//printf("MUL EXIT\n");
			break;
		case TERMd_NT:
			//printf("\n-------------------STACK:DIVIDE\n");
			push(st_CMD,(MEM_SIZE)o_div);
			cast(pt, replacetree);
			break;
		case VALUE_ID_NT:
			push(st_DATA, (MEM_SIZE)pt);
			//printf("\n-------------------STACK:IDENTIFIER\n");
			break;
		case VALUE_CL_NT:
			simplify(pt->first, replacetree);
			break;
		case VALUE_EX_NT:
			simplify(pt->first, replacetree);
			break;
		case CONSTANT_NT:
			simplify(pt->first, replacetree);
			break;
		case CONSTANTchl_NT:
			push(st_DATA,(MEM_SIZE)pt);
			//printf("\n-------------------STACK:CHAR:%c\n", pt->item);
			break;
		case INTEGER_CONSTANT_NT:
			//printf("\n-------------------STACK:INT:%i\n", pt->item);
			push(st_DATA, (MEM_SIZE)pt);
			break;
		case FLOAT_CONSTANT_NT:
			//printf("\n-------------------STACK:FLOAT:%f\n", *((double*)pt->item));
			push(st_DATA, (MEM_SIZE)pt);
			break;
	}
}

void evalDuplicares(MEM_SIZE cpy1, MEM_SIZE cpy2)
{
			bool isFloat1=FALSE, isFloat2=FALSE, isInt1=FALSE, isInt2=FALSE, isChr1=FALSE, isChr2 = FALSE, isID1 = FALSE, isID2 = FALSE;
			switch(((TERNARY_TREE)cpy1)->nodeIdentifier)
			{
				case FLOAT_CONSTANT_NT:
					isFloat1 = TRUE;
					break;
				case INTEGER_CONSTANT_NT:
					isInt1 = TRUE;
					break;
				case CONSTANTchl_NT:
					isChr1 = TRUE;
					break;
				case VALUE_ID_NT:
					isID1 = TRUE;
					break;
			}
			switch(((TERNARY_TREE)cpy2)->nodeIdentifier)
			{
				case FLOAT_CONSTANT_NT:
					isFloat2 = TRUE;
					break;
				case INTEGER_CONSTANT_NT:
					isInt2 = TRUE;
					break;
				case CONSTANTchl_NT:
					isChr2 = TRUE;
					break;
				case VALUE_ID_NT:
					isID2 = TRUE;
					break;
			}
			//if id...
			if(isID1 == TRUE)
			{
				switch(idtypes[((TERNARY_TREE)cpy1)->item])
				{
					case TYPEchar_NT:
						isChr1 = TRUE;
						break;
					case TYPEint_NT:
						isInt1 = TRUE;
						break;
					case TYPEreal_NT:
						isFloat1 = TRUE;
						break;
				}
			}
			if(isID2 == TRUE)
			{
				switch(idtypes[((TERNARY_TREE)cpy2)->item])
				{
					case TYPEchar_NT:
						isChr2 = TRUE;
						break;
					case TYPEint_NT:
						isInt2 = TRUE;
						break;
					case TYPEreal_NT:
						isFloat2 = TRUE;
						break;
				}
			}
			typepop();
			typepop();
			//ghandles float...
			if(isFloat1)
			{
				typepush(cpy1);
			}
			else if(isFloat2)
			{
				typepush(cpy2);
			}
			if(isChr1 && isChr2)
			{
				typepush(cpy1);
			}
			if(isInt1 && isInt2)
			{
				typepush(cpy1);
			}
			
			if(isChr1 && isInt2)
			{
				typepush(cpy2);
			}
			else if(isChr2 && isInt1)
			{
				typepush(cpy1);
			}
}

void maketypelist(TERNARY_TREE pt)
{	
	MEM_SIZE cpy1 = NULL;
	MEM_SIZE cpy2 = NULL;
	//printf("%i\n", pt->nodeIdentifier);
	if (pt==NULL) return;
	switch(pt->nodeIdentifier)
	{
		case EXPRESSION_NT:
			maketypelist(pt->first);
			break;
		case EXPRESSIONadd_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case EXPRESSIONminus_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case TERM_NT:
			maketypelist(pt->first);
			break;
		case TERMm_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case TERMd_NT:
			maketypelist(pt->first);
			cpy1 = typetop();
			maketypelist(pt->second);
			cpy2 = typetop();
			evalDuplicares(cpy1, cpy2);
			break;
		case VALUE_ID_NT:
			typepush((MEM_SIZE)pt);
			break;
		case VALUE_CL_NT:
			maketypelist(pt->first);
			break;
		case VALUE_EX_NT:
			maketypelist(pt->first);
			break;
		case CONSTANT_NT:
			maketypelist(pt->first);
			break;
		case CONSTANTchl_NT:
			typepush((MEM_SIZE)pt);
			break;
		case INTEGER_CONSTANT_NT:
			typepush((MEM_SIZE)pt);
			break;
		case FLOAT_CONSTANT_NT:
			typepush((MEM_SIZE)pt);
			break;
	}
}

int generateTypedTable(TERNARY_TREE pt, int thingof)
{
	if(pt==NULL) return thingof;
	
	switch(pt->nodeIdentifier)
	{
		case PROGRAM_NT:			
			generateTypedTable(pt->first,thingof);
			break;
		case BLOCK_NT:			
			generateTypedTable(pt->first,thingof);
			break;
		case DECLARATION_BLOCK_NT:
			if(pt->first !=NULL)
			{	
				generateTypedTable(pt->first,generateTypedTable(pt->second,thingof));
			}
			generateTypedTable(pt->third,thingof); //are there more?
			break;
		case IDENTIFIER_LIST_NT:
			generateTypedTable(pt->first,thingof);
			return thingof;
		case IDENTIFIER_LIST_SINGLE_NT:
			//printf("id...\n");
			identityTable[pt->item] = thingof;
			return thingof;
		case TYPEchar_NT:
			//printf("char\n");
			return TYPEchar_NT;
		case TYPEint_NT:
			//printf("int\n");
			return TYPEint_NT;
		case TYPEreal_NT:	
			//printf("real\n");
			return TYPEreal_NT;
	}
	return -1;
}

void cast(TERNARY_TREE pt, TERNARY_TREE * from)
{
	//printf("cast\n");
	if(pt==NULL) return;
	
	//search subtrees
	simplify(pt->first, &(pt->first));
	simplify(pt->second, &(pt->second));
	//printf("\n-------------------data:%i. cmd:%i\n", nodeStack.count, commandStack.count);
	if(nodeStack.count >= 2 && commandStack.count>=1)
	{	/*optimise*/
		TERNARY_TREE newsubtree=NULL;
		TERNARY_TREE node1 = top(st_DATA); pop(st_DATA);
		//printf("%i\n", node1->item);
		TERNARY_TREE node2 = top(st_DATA); pop(st_DATA);
		int action = (MEM_SIZE)top(st_CMD); pop(st_CMD);
		//printf("%i\n", action);
		//printf("%i\n", node2->item);	
		//fasle false 
		if(!(node1->nodeIdentifier == VALUE_ID_NT) && !(node2->nodeIdentifier == VALUE_ID_NT))
		{
			//printf("optimise\n");	

			//create vars
			double d_operand1=0.0, d_operand2=0.0;
			int i_operand1=0, i_operand2=0;
			bool isSet_DO1=FALSE, isSet_DO2=FALSE, isSet_IO1=FALSE, isSet_IO2=FALSE;

			//do type check evaluation.
			if(node1->nodeIdentifier==FLOAT_CONSTANT_NT)
			{
				d_operand1 = *((double*)((MEM_SIZE)node1->item));
				isSet_DO1 = TRUE;
				if(node2->nodeIdentifier == FLOAT_CONSTANT_NT)
				{
					d_operand2 = *((double*)((MEM_SIZE)node2->item));
					isSet_DO2 = TRUE;
				}
				else
				{
					i_operand1 = node2->item;
					isSet_IO1 = TRUE;
				}	
			}
			else
			{
				i_operand1 = node1->item;
				isSet_IO1 = TRUE;
				if(node2->nodeIdentifier==FLOAT_CONSTANT_NT)
				{
					d_operand1 = *((double*)((MEM_SIZE)node2->item));
					isSet_DO1 = TRUE;	
				}
				else
				{
					i_operand2 = node2->item;
					isSet_IO2 = TRUE;
				}
			}
			//printf("------------------------%i%i\n", isSet_IO1, isSet_IO2);
			//make result spaces.
			double * d_result = malloc(sizeof(double)); 
			int i_result=0;
			bool result_is_double = FALSE;
			//final type eval. Then calculate using operator.
			if(isSet_DO1 && isSet_DO2) //double double calc.
			{
				//printf("do float calc\n");
				switch(action)
				{
					case o_add:
						*d_result = d_operand2 + d_operand1;
						break;
					case o_sub:
						*d_result =  d_operand2 - d_operand1;
						break;
					case o_mul:
						*d_result =  d_operand2 * d_operand1;
						break;
					case o_div:
						*d_result =  d_operand2 / d_operand1;
						break;
				}
				result_is_double = TRUE;
				//printf("%f\n", *d_result);
			}
			else if(isSet_IO1 && isSet_IO2) //int int calc.
			{
				//printf("do int calc\n");
				switch(action)
				{
					case o_add:
						i_result = i_operand2 + i_operand1;
						break;
					case o_sub:
						i_result =  i_operand2 - i_operand1;
						break;
					case o_mul:
						i_result =  i_operand2 * i_operand1;
						break;
					case o_div:
						i_result =  i_operand2 / i_operand1;
						break;
				}
				//printf("%i\n", i_result);		
			}
			else if(((bool)(isSet_DO1 + isSet_DO2)) && ((bool)(isSet_IO1 + isSet_IO2))) //hyrid calculations...
			{
				//compress...
				d_operand1= d_operand1 + d_operand2;
				i_operand1= i_operand1 + i_operand2;
				if(isSet_DO1) // float is Op_2.
				{
					switch(action)
					{
						case o_add:
							*d_result = d_operand1 + (double)i_operand1;
							break;
						case o_sub:
							*d_result = d_operand1 - (double)i_operand1;
							break;
						case o_mul:
							*d_result = d_operand1 * (double)i_operand1;
							break;
						case o_div:
							*d_result = d_operand1 / (double)i_operand1;
							break;
					}	
				}
				else // int is Op_2.
				{
					switch(action)
					{
						case o_add:
							*d_result = (double)i_operand1 + d_operand1;
							break;
						case o_sub:
							*d_result = (double)i_operand1 - d_operand1;
							break;
						case o_mul:
							*d_result = (double)i_operand1 * d_operand1;
							break;
						case o_div:
							*d_result = (double)i_operand1 / d_operand1;
							break;
					}
				}

				result_is_double = TRUE;
				//printf("%f\n", *d_result);
			}


			//destroy old subtree.
			destroy_nodes_from(*from); pt=NULL;
			//make new subtree, then add it in place of the old.
			newsubtree = create_node(NOTHING, EXPRESSION_NT, NULL, NULL, NULL);
			newsubtree->first = create_node(NOTHING, TERM_NT, NULL, NULL, NULL);
			newsubtree->first->first = create_node(NOTHING, VALUE_CL_NT, NULL, NULL, NULL);
			newsubtree->first->first->first = create_node(NOTHING, CONSTANT_NT, NULL, NULL, NULL);
			if(result_is_double)
				newsubtree->first->first->first->first = create_node((MEM_SIZE)d_result, FLOAT_CONSTANT_NT, NULL, NULL, NULL);
			else
				newsubtree->first->first->first->first = create_node(i_result, INTEGER_CONSTANT_NT, NULL, NULL, NULL);
			*from=newsubtree;
			push(st_DATA,(MEM_SIZE)newsubtree->first->first->first->first);	
		}	
	}
}

void destroy_nodes_from(TERNARY_TREE pt)
{
	if(pt==NULL) return;
	destroy_nodes_from(pt->first);
	destroy_nodes_from(pt->second);
	destroy_nodes_from(pt->third);
	//printf("destroy %i\n", pt);

	if(pt->nodeIdentifier == FLOAT_CONSTANT_NT)
	{
		double * freeme = (double*)((MEM_SIZE)pt->item);
		free(freeme);
	}
	//printf("record deleted");
	free(pt);
	pt=NULL;
}





/* Put other auxiliary functions here */

#include "lex.yy.c"


