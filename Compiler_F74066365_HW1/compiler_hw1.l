/* Definition section */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define YY_NO_UNPUT
    #define YY_NO_INPUT

    int line_num = 0;
    int comment_num = 0;
    int current_line = 0;

    //-------------------write my code
    #define ADD 300
    #define SUB 301
    #define MUL 302
    #define QUO 303
    #define REM 304
    #define INC 305
    #define DEC 306
    #define GTR 307
    #define LSS 308
    #define GEQ 309
    #define LEQ 310
    #define EQL 311
    #define NEQ 312
    #define ASSIGN 313
    #define ADD_ASSIGN 314
    #define SUB_ASSIGN 315
    #define MUL_ASSIGN 316
    #define QUO_ASSIGN 317
    #define REM_ASSIGN 318
    #define LAND 319
    #define LOR 320
    #define NOT 321
    #define LPAREN 322
    #define RPAREN 323
    #define LBRACK 324
    #define RBRACK 325
    #define LBRACE 326
    #define RBRACE 327
    #define SEMICOLON 328
    #define COMMA 329
    #define QUOTA 330
    #define NEWLINE 331
    #define INT_LIT 332
    #define FLOAT_LIT 333
    #define STRING_LIT 334
    #define IDENT 335
    #define COMMENT 336
    #define PRINT 337
    #define PRINTLN 338
    #define IF 339
    #define ELSE 340
    #define FOR 341
    #define INT 342
    #define FLOAT 343
    #define STRING 344
    #define BOOL 345
    #define TRUE 346
    #define FALSE 347
    #define VAR 348
    //-------------------
%}

/* Define regular expression label */
letter [a-zA-Z_]
digit [0-9]
id {letter}+({letter}|{digit})*
inumber {digit}+
fnumber ({digit}*\.{digit}+)

/*-------------------write my code */
ws [ \t]+

newline \n

/* state */
%x String C_comment

/*---------------------------------*/

/* Rules section */
%%

"+"         { printf("%-8s \t %s\n", yytext, "ADD"); }
"-"         { printf("%-8s \t %s\n", yytext, "SUB"); }

"*"         { printf("%-8s \t %s\n", yytext, "MUL"); }
"/"         { printf("%-8s \t %s\n", yytext, "QUO"); }
"%"         { printf("%-8s \t %s\n", yytext, "REM"); }
"++"        { printf("%-8s \t %s\n", yytext, "INC"); }
"--"        { printf("%-8s \t %s\n", yytext, "DEC"); }
">"         { printf("%-8s \t %s\n", yytext, "GTR"); }
"<"         { printf("%-8s \t %s\n", yytext, "LSS"); }
">="        { printf("%-8s \t %s\n", yytext, "GEQ"); }
"<="        { printf("%-8s \t %s\n", yytext, "LEQ"); }
"=="        { printf("%-8s \t %s\n", yytext, "EQL"); }
"!="        { printf("%-8s \t %s\n", yytext, "NEQ"); }
"="         { printf("%-8s \t %s\n", yytext, "ASSIGN"); }
"+="        { printf("%-8s \t %s\n", yytext, "ADD_ASSIGN"); }
"-="        { printf("%-8s \t %s\n", yytext, "SUB_ASSIGN"); }
"*="        { printf("%-8s \t %s\n", yytext, "MUL_ASSIGN"); }
"/="        { printf("%-8s \t %s\n", yytext, "QUO_ASSIGN"); }
"%="        { printf("%-8s \t %s\n", yytext, "REM_ASSIGN"); }
"&&"        { printf("%-8s \t %s\n", yytext, "LAND"); }
"||"        { printf("%-8s \t %s\n", yytext, "LOR"); }
"!"         { printf("%-8s \t %s\n", yytext, "NOT"); }
"("         { printf("%-8s \t %s\n", yytext, "LPAREN"); }
")"         { printf("%-8s \t %s\n", yytext, "RPAREN"); }
"["         { printf("%-8s \t %s\n", yytext, "LBRACK"); }
"]"         { printf("%-8s \t %s\n", yytext, "RBRACK"); }
"{"         { printf("%-8s \t %s\n", yytext, "LBRACE"); }
"}"         { printf("%-8s \t %s\n", yytext, "RBRACE"); }
";"         { printf("%-8s \t %s\n", yytext, "SEMICOLON"); }
","         { printf("%-8s \t %s\n", yytext, "COMMA"); }

"print"     { printf("%-8s \t %s\n", yytext, "PRINT"); }   
"println"   { printf("%-8s \t %s\n", yytext, "PRINTLN"); }
"if"        { printf("%-8s \t %s\n", yytext, "IF"); }
"else"      { printf("%-8s \t %s\n", yytext, "ELSE"); }
"for"       { printf("%-8s \t %s\n", yytext, "FOR"); }
"int32"     { printf("%-8s \t %s\n", yytext, "INT"); }
"float32"   { printf("%-8s \t %s\n", yytext, "FLOAT"); }
"string"    { printf("%-8s \t %s\n", yytext, "STRING"); }
"bool"      { printf("%-8s \t %s\n", yytext, "BOOL"); }
"true"      { printf("%-8s \t %s\n", yytext, "TRUE"); }
"false"     { printf("%-8s \t %s\n", yytext, "FALSE"); }
"var"       { printf("%-8s \t %s\n", yytext, "VAR"); }

{inumber}   { printf("%-8s \t %s\n", yytext, "INT_LIT"); }
{fnumber}   { printf("%-8s \t %s\n", yytext, "FLOAT_LIT"); }

{id}        { printf("%-8s \t %s\n", yytext, "IDENT"); }

["]         { printf("%-8s \t %s\n", yytext, "QUOTA"); BEGIN String; }
    <String>[^"]* { printf("%-8s \t %s\n", yytext, "STRING"); 
                    for (int i = 0; i < yyleng; i++){
                        if (yytext[i] == '\n'){
                           line_num++;
                        }
                    }
                  }
    <String>["]   { printf("%-8s \t %s\n", yytext, "QUOTA"); BEGIN 0; }


"//".*      { if(current_line == 0){ comment_num++; } 
              printf("%-8s \t %s\n", yytext, "C++ Comment"); }

"/*"        { printf("%s", yytext ); BEGIN C_comment; }
    <C_comment>[^*\n]* { printf("%s", yytext); }
    <C_comment>"*"[^/\n]* { printf("%s", yytext); }
    <C_comment>\n { line_num++;
                    comment_num++; 
                    if(current_line == 1){ current_line = 0; } 
                    printf("%-8s \t %s\n", yytext, "C Comment"); }
    <C_comment>"*/" { current_line = 1; 
                      printf("%-8s \t %s\n", yytext, "C Comment"); 
                      BEGIN 0; } 


{newline}   { if(current_line == 1){ comment_num++; current_line = 0; } 
              line_num++; 
              printf("%-8s \t %s\n", "", "NEWLINE"); }
{ws}        {}

<<EOF>>     { if(current_line == 1){ comment_num++; current_line = 0; }
              line_num++; yyterminate(); }
.           {;}

%%

/*  C Code section */
int yywrap(void)
{
    return 1;
}

int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }
    yylex();
    printf("\nFinish scanning,\n");
    printf("total line: %d\n", line_num);
    printf("comment line: %d\n", comment_num);
    fclose(yyin);
    return 0;
}
