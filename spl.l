%{
#include <string.h>
#ifdef PRINT
#define TOKEN(token_) printf(#token_); printf("\n");
#define T_FLOAT(token_) printf(#token_); printf(":%s\n", yytext);
#define T_INT(token_) printf(#token_); printf(":%s\n", yytext);
#define T_CHAR(token_) printf(#token_); printf(":%s\n", yytext);
#define T_IDENT(token_) printf(#token_); printf(":%s\n", yytext);
#else
#define TOKEN(token_) return token_;
#define T_FLOAT(token_) double * fpn = malloc(sizeof(double)); *fpn=atof(yytext); yylval.iVal=(MEM_SIZE)fpn; return token_;
#define T_INT(token_) yylval.iVal = atol(yytext); return token_;
#define T_CHAR(token_) char * ch = malloc(2*sizeof(char)); *ch = yytext[1]; *(ch+1)='\0'; yylval.iVal = installId(ch); free(ch); return token_;
#define T_IDENT(token_) yylval.iVal = installId(yytext); return token_;
#endif

#ifndef PRINT
int installId(char *id);
extern SYMTABNODEPTR symTab[SYMTABSIZE];
extern int currentSymTabSize;
#endif
%}

delim [ \t\n]
ws {delim}+
letter [A-Za-z]
digit [0-9]
id {letter}({letter}|{digit})*
number {digit}+
real {number}"."{number}
charconst "'"{letter}"'"

%%

{ws} ; /* white space, do nothing */
ENDP TOKEN(ENDP);
DECLARATIONS TOKEN(DECLARATIONS);
CODE TOKEN(CODE);
OF TOKEN(OF);
TYPE TOKEN(TYPE);
CHARACTER TOKEN(CHARACTER);
INTEGER TOKEN(INTEGER);
REAL TOKEN(REAL);
IF TOKEN(IF);
THEN TOKEN(THEN);
ELSE TOKEN(ELSE);
ENDIF TOKEN(ENDIF);
DO TOKEN(DO);
ENDDO TOKEN(ENDDO);
WHILE TOKEN(WHILE);
ENDWHILE TOKEN(ENDWHILE);
FOR TOKEN(FOR);
IS TOKEN(IS);
BY TOKEN(BY);
TO TOKEN(TO);
ENDFOR TOKEN(ENDFOR);
WRITE TOKEN(WRITE);
READ TOKEN(READ);
NEWLINE TOKEN(NEWLINE);
AND TOKEN(AND);
OR TOKEN(OR);
NOT TOKEN(NOT);
"=" TOKEN(ET);
"<>" TOKEN(NET);
"<" TOKEN(LT);
">" TOKEN(GT);
"<=" TOKEN(LTET);
">=" TOKEN(GTET);
"+" TOKEN(ADD);
"-" TOKEN(MINUS);
"/" TOKEN(DIVIDE);
"*" TOKEN(MULTIPLY);
"(" TOKEN(LCBRAC);
")" TOKEN(RCBRAC);
"->" TOKEN(ASSIGN);
"." TOKEN(POINT);
"," TOKEN(COMMA);
";" TOKEN(SEMICOLON);
":" TOKEN(COLON);

{id} {
		T_IDENT(IDENTIFIER);
	}

{number} {
			T_INT(NUMBER);
		}
{real} {
			T_FLOAT(FLOAT);
		}
{charconst} {
			T_CHAR(CHARLITERAL);
        }    

%%

/* Here is the code for the library of symbol table routines */

/* code for a simple symbol table, which is an array of pointers to
   structs, each of which contains an identifier.
*/

#ifndef PRINT
SYMTABNODEPTR newSymTabNode()
{
    return ((SYMTABNODEPTR)malloc(sizeof(SYMTABNODE)));
}


/* Look up an identifier in the symbol table, if its there return
   its index.  If its not there, put it in the end position,
   as long as the table isn't full, and return its index.
*/

int installId(char *id) 
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE]; 
    extern int currentSymTabSize;
    int index;

    index = lookup(id);
    if (index >= 0)
    {
        return (index);
    }
    else 
       if (currentSymTabSize >= SYMTABSIZE) 
          /* SYMTAB is full */
          return (NOTHING) ;
    else 
    {
       symTab[currentSymTabSize] = newSymTabNode();
       /* Recommended code for preventing buffer overrun on bounded strings */
       strncpy(symTab[currentSymTabSize]->identifier,id,IDLENGTH);
       symTab[currentSymTabSize]->identifier[IDLENGTH-1] = '\0';
       return(currentSymTabSize++);
    }
}

int lookup(char *s)
{
    extern SYMTABNODEPTR symTab[SYMTABSIZE];
    extern int currentSymTabSize;
    int i;

    for(i=0; i<currentSymTabSize; i++)
    {
        if(strcmp(s,symTab[i]->identifier) == 0)
        {
            return (i);
        }
    }
    return (-1);    
}
#endif