grammar WPL;

// Parser rules
compilation_unit    : (function | externalFunction | proc | externalProc)+ ;
program             : compilation_unit;

//Useful shortcuts
type                : (INT | BOOLEAN | STR | VAR) ;

//non ; ending things
block               : '{' ((statement ';' |  block | conditional))+ '}' ;
conditional         : IF mathExpression THEN? '{'
                                    ((statement ';' |  flow))+
                               '}' (ELSE '{'
                                    ((statement ';' |  flow))+
                               '}')? ;
function    : (INT | BOOLEAN | STR) FUNC VARIABLE '(' ((type VARIABLE ',')* type VARIABLE)? '){'
                                ((statement ';' |  flow))*
                                returnStatement ';'
                        '}' ;
externalFunction    : EXTERN (INT | BOOLEAN | STR) FUNC VARIABLE '(' ((type VARIABLE ',')* type VARIABLE)? ')' ';' ;
proc                : PROC VARIABLE '(' ((type VARIABLE ',')* type VARIABLE)? '){'
                                ((statement ';' |  flow))+
                        '}' ;
externalProc        : EXTERN PROC VARIABLE '(' ((type VARIABLE ',')* type VARIABLE)? ')' ';' ;
whileLoop           : WHILE mathExpression DO '{'
                            (statement ';' | flow)+
                      '}' ;
select              : SELECT '{'
                            (mathExpression ':' (statement ';' | flow ';'))+
                      '}' ;
flow               : (block | conditional | whileLoop | select) ; //non ; ending things that can be nested inside each other



// must end with ;
//Own
defineStatement     : <assoc=right>type ((VARIABLE | assignStatement) ',')* (VARIABLE | assignStatement) ;
defineStatementArray: <assoc=right>(INT | BOOLEAN | STR) '[' INTEGER ']' (VARIABLE ',')* VARIABLE ;
assignStatement     : <assoc=right>VARIABLE ASSIGN mathExpression ;
returnStatement     : RETURN mathExpression? ;
statement           : (defineStatement | defineStatementArray | assignStatement | returnStatement | funcCall) ; //things that can be called on their own ( can't call '2+3/4' it has to be a <- 2+3/4)
//Part of mathExpression
arrLength           : VARIABLE '.' VARIABLE ;
arrElement          : VARIABLE '[' mathExpression ']' ;
funcCall            : VARIABLE '(' (((VARIABLE | mathExpression) ',')* (VARIABLE | mathExpression))? ')' ;
boolConst           : (TRUE | FALSE) ;
string              : '"' .*? '"' ;
mathExpression      :
                    funcCall
                    | arrLength
                    | arrElement
                    |'(' mathExpression ')'
                    | <assoc=right> ('-' | '~') mathExpression
                    | mathExpression ('*' | '/') mathExpression
                    | mathExpression ('+' | '-') mathExpression
                    | mathExpression ('<' | '>' | '<=' | '>=') mathExpression
                    | mathExpression ('=' | '~=') mathExpression
                    | mathExpression '&' mathExpression
                    | mathExpression '|' mathExpression
                    | string
                    | INTEGER
                    | VARIABLE
                    | boolConst;


// Lexer rules
// Operators
ASSIGN    : '<-' ;
DIVIDE    : '/' ;
MINUS     : '-' ;
MULTIPLY  : '*' ;
PLUS      : '+' ;
GREATER   : '>' ;
GREATEREQ : '>=' ;
LESS      : '<' ;
LESSEQ    : '<=' ;
EQUAL     : '=' ;
NOTEQUAL  : '~=' ;
NOT       : '~' ;
AND       : '&' ;
OR        : '|' ;

// Separators (punctuation)
LPAR      : '(' ;
RPAR      : ')' ;
LBRAC     : '{' ;
RBRAC     : '}' ;
SEMICOLON : ';' ;
COLON     : ':' ;
QUOTE     : '"' ;
LSQ       : '[' ;
RSQ       : ']' ;
DOT       : '.' ;
COMA      : ',' ;

//Key words
//Comments
LCOMMENT  : '(*' ;
RCOMMENT  : '*)' ;
INLINE    : '#' ;

//Types
INT       : 'int' ;
BOOLEAN   : 'boolean' ;
STR       : 'str' ;
VAR       : 'var' ;


//Functions and Procedures
RETURN    : 'return' ;
FUNC      : 'func' ;
PROC      : 'proc' ;
EXTERN    : 'extern' ;

//Statements
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
WHILE     : 'while' ;
DO        : 'do' ;
SELECT    : 'select' ;

// Boolean constants
FALSE     : 'false' ;
TRUE      : 'true' ;

// Other
INTEGER   : [0-9]+ ;
VARIABLE  : [a-zA-Z]+ ;
ANYSTR    : [.]+ ;

INLINECOMMENT: '#' .+? '\n' -> skip ;
WS         : [ \n\t\r]+ -> skip ;
COMMENT    : '(*' .+? '*)' -> skip ;

