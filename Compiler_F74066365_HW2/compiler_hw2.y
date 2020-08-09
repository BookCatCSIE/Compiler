/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol(int);
    static void insert_symbol(char*,int);
    static void lookup_symbol();
    static void dump_symbol(int);
/*
    typedef union _all_type{
        int itype;
        float ftype;
        char* strtype;
        bool btype;
    }all_type;
*/

/*
    typedef struct {
        int unique_value;
        struct Address* prev;
        struct Address* next;
    }Address;
*/

    typedef struct {
        int index;
        char* name;
        char* type;
        int address;
        int line_number;
        char* array_element_type;
    }Table_element;

    typedef struct {
        int element_num;
        Table_element te[100];
        struct Symbol_Table* prev;
        struct Symbol_Table* next;
    }Symbol_Table;

    int now_scope_level = 0;

    Symbol_Table my_table[50];
    
    int total_address = 0;

    int into_block =0; //in09
    int scope_dif =0; //in09
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    float f_val;
    char* s_val;
    /* ... */
    //char* id_val;
    //all_type type;
}

/* Token without return */
%token <s_val> VAR
%token <s_val> INT FLOAT BOOL STRING

%token <s_val> '"'
%token <s_val> '+' '-' '*' '/' '%' INC DEC
%token <s_val> '>' '<' GEQ LEQ EQL NEQ
%token <s_val> '=' ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN QUO_ASSIGN REM_ASSIGN
%token <s_val> LAND LOR '!'
%token <s_val> '(' ')' '[' ']' '{' '}'
%token <s_val> ';' ',' NEWLINE
%token <s_val> PRINT PRINTLN IF ELSE FOR

%token <s_val> TRUE FALSE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <f_val> FLOAT_LIT

%token <s_val> STRING_LIT
%token <s_val> IDENT

/* Nonterminal with return, which need to sepcify type */
%type <s_val> Type TypeName TypeX

%type <s_val> StatementList Statement
%type <s_val> Expression Expression2 Expression3 Expression5 Expression6 Expression7
%type <s_val> UnaryExpr UnaryExprX PrimaryExpr unary_op Operand
%type <s_val> DeclarationStmt SimpleStmt Block IfStmt ForStmt PrintStmt
%type <s_val> IfStmt3 ForClause IfStmt2

/* Yacc will start at this nonterminal */
%start Program

/* Precedence */
%left LOR
%left LAND
%left '>' '<' GEQ LEQ EQL NEQ
%left '+' '-'
%left '*' '/' '%'
%right '!'
%nonassoc '[' ']'
%nonassoc '(' ')'

/* Grammar section */
%%

Program
    : StatementList
;

StatementList
    : StatementList Statement
    | Statement
;

Statement
    : DeclarationStmt NEWLINE
    | SimpleStmt NEWLINE
    | Block NEWLINE
    | IfStmt NEWLINE
    | ForStmt NEWLINE
    | PrintStmt NEWLINE
    | NEWLINE
    ;

DeclarationStmt
    : VAR IDENT Type { int i=0;   int redeclared =0;   int line =0;             //in10 
                       for(i=0;i<my_table[now_scope_level].element_num;i++){  /* i<100 --> segmentation fault */
                           if(strcmp($2,my_table[now_scope_level].te[i].name)==0){
                               redeclared =1;
                               line = my_table[now_scope_level].te[i].line_number;		 
                               break;
                           }
                       }
             
                       if(redeclared == 1){
                           printf("error:%d: %s redeclared in this block. previous declaration at line %d\n",yylineno,$2,line);
                       }                                     //in10
                       else{

                           insert_symbol($2, now_scope_level);

                           my_table[now_scope_level].element_num += 1;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].name = $2;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].index = my_table[now_scope_level].element_num-1;
                           if(strcmp($3,"array int32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "int32";
                           }
                           else if(strcmp($3,"array float32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "float32";
                           }
                           else if(strcmp($3,"array string")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "string";
                           }
                           else if(strcmp($3,"array bool")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "bool";
                           }
                           else{ my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = $3; }

                           // my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = $3;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address = total_address++;
                           my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].line_number = yylineno;
                           if(strcmp(my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type,"array")!=0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "-";
                           }
                       }
                     }
    | VAR IDENT Type '=' Expression { insert_symbol($2, now_scope_level);

                                      my_table[now_scope_level].element_num += 1;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].name = $2;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].index = my_table[now_scope_level].element_num-1;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = $3;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address = total_address++;
                                      my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].line_number = yylineno;
                                      if(strcmp(my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type,"array")!=0){
                                          my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "-";
                                      }

                                    }
    ;

TypeName
    : INT { $$ = "int32"; }
    | FLOAT { $$ = "float32"; }
    | STRING { $$ = "string"; }
    | BOOL { $$ = "bool"; }
    ;

Type
    : TypeX TypeName { if(strcmp($2,"int32")==0){ $$ = "array int32"; }
                       else if(strcmp($2,"float32")==0){ $$ = "array float32"; }
                       else if(strcmp($2,"string")==0){ $$ = "array string"; }
                       else if(strcmp($2,"bool")==0){ $$ = "array bool"; }
                     }
    | TypeName 
    ;

TypeX
    : TypeX '[' Expression ']'
    | '[' Expression ']'
    ;

Expression
    : Expression LOR Expression2 { if(strcmp($1,"int32")==0 || strcmp($3,"int32")==0){
                                       yyerror("invalid operation: (operator LOR not defined on int32)");
                                   }
                                   printf("LOR\n"); $$ = "bool"; }
    | Expression2
    ;

Expression2
    : Expression2 LAND Expression3 { if(strcmp($1,"int32")==0 || strcmp($3,"int32")==0){
                                         yyerror("invalid operation: (operator LAND not defined on int32)");
                                     }                                    
                                     printf("LAND\n"); }
    | Expression3
    ;

Expression3
    : Expression3 '>' Expression5 { printf("GTR\n");  $$ = "bool"; }
    | Expression3 '<' Expression5 { printf("LSS\n");  $$ = "bool"; }
    | Expression3 GEQ Expression5 { printf("GEQ\n");  $$ = "bool"; }
    | Expression3 LEQ Expression5 { printf("LEQ\n");  $$ = "bool"; }
    | Expression3 EQL Expression5 { printf("EQL\n");  $$ = "bool"; }
    | Expression3 NEQ Expression5 { printf("NEQ\n");  $$ = "bool"; 
                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                                  }
    | Expression5
    ;

Expression5
    : Expression5 '+' Expression6 { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                        yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"int32")==0){
                                        yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0){
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<100;j++){
                                            if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;  
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                        }
                                    }
                                    else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //in09 LOR error
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($3,"int32")==0){ //in09 for condition error
                                        int i=0;  char* c1 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0){
                                            $$ = "int32";   
                                        }
                                    }
                                    printf("ADD\n"); 
                                  }
    | Expression5 '-' Expression6 { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                        yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"int32")==0){
                                        yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0){
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<100;j++){
                                            if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                        }
                                    }
                                    printf("SUB\n"); }
    | Expression6
    ;

Expression6
    : Expression6 '*' Expression7 { printf("MUL\n"); }
    | Expression6 '/' Expression7 { printf("QUO\n"); }
    | Expression6 '%' Expression7 { if(strcmp($1,"float32")==0 || strcmp($3,"float32")==0){
                                      yyerror("invalid operation: (operator REM not defined on float32)");
                                    }                                  
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0){
                                        int i=0;  char* c1 = "";
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            yyerror("invalid operation: (operator REM not defined on float32)");
                                        }
                                        else if(strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0){
                                            int j=0;  char* c2 = "";
                                            for(j=0;j<100;j++){
                                                if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                                    c2 = my_table[now_scope_level].te[j].type;
                                                    break;
                                                }
                                            }
                                            if(strcmp(c2,"float32")==0){
                                                yyerror("invalid operation: (operator REM not defined on float32)");
                                            }
                                        }                                      
                                    }                                   
                                    printf("REM\n"); }
    | Expression7
    ;

Expression7
    : UnaryExpr
    ;

UnaryExpr
    : UnaryExprX PrimaryExpr { printf("%s\n",$1);  
                               $$ = $2;/*in09 -> in02*/ }
    | PrimaryExpr
    ;

UnaryExprX
    : UnaryExprX unary_op { char* s = malloc(sizeof(char)*(strlen($1)+strlen($2)+2));
                            strcpy(s,$2); strcat(s,"\n"); strcat(s,$1);
                            $$ = s;
                          }
    | unary_op 
    ;

unary_op
    : '+' { $$ = "POS"; }
    | '-' { $$ = "NEG"; }
    | '!' { $$ = "NOT"; }
    ;

PrimaryExpr
    : Operand
    | PrimaryExpr '[' Expression ']' { int i =0;
                                       for(i=0;i<100;i++){
                                           if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                               $$ = my_table[now_scope_level].te[i].array_element_type ;
                                               // in04, need IDENT $$ = id
                                               break;
                                           }
                                       }
                                     }
    | Type '(' Expression ')' { if(strcmp($3,"int32")==0 && strcmp($1,"float32")==0){ printf("I to F\n"); }
                                else if(strcmp($3,"float32")==0 && strcmp($1,"int32")==0){ printf("F to I\n"); }
                                else{
                                    int i =0;  char* c = "";
                                    for(i=0;i<100;i++){
                                        if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                            c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                            break;
                                        }
                                    }
                                    if(strcmp(c,"int32")==0 && strcmp($1,"float32")==0){ printf("I to F\n"); }
                                    else if(strcmp(c,"float32")==0 && strcmp($1,"int32")==0){ printf("F to I\n"); }
                                }
			      }
    ;

Operand
    : INT_LIT { printf("INT_LIT %d\n",$1);  $$="int32"; }
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n",$1);  $$="float32"; }
    | TRUE { printf("TRUE\n");   $$="bool";}
    | FALSE { printf("FALSE\n");   $$="bool";}
    | '"' STRING_LIT '"' { printf("STRING_LIT %s\n",$2);   $$="string";}
    | IDENT { int i =0;           int declare =0;//in10
              for(i=0;i<my_table[now_scope_level].element_num;i++){ /* i<100 --> segmentation fault */
                  if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                      printf("IDENT (name=%s, address=%d)\n",$1,my_table[now_scope_level].te[i].address);
                      // $$ = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                      declare =1;//in10
                      break;
                  }
              }
              if(declare == 0){ 
                  if(into_block >0){//in09
                      int j =0;   int k =0;
                      for(j=0;j<now_scope_level;j++){
                          for(k=0;k<my_table[j].element_num;k++){
                              if(strcmp($1,my_table[j].te[k].name)==0){
                                  scope_dif = now_scope_level - j;
                                  now_scope_level -= scope_dif;
                                  printf("IDENT (name=%s, address=%d)\n",$1,my_table[j].te[k].address);
                                  break;
                              }
                          }
                      }//in09
                  }
                  else{
                      printf("error:%d: undefined: %s\n",yylineno+1,$1);//in10
                  }
              }
            }     
    | '(' Expression ')'
    ;

/*--------------------------------------------*/

SimpleStmt
    : Expression '=' Expression { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                      yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                  }
                                  else if(strcmp($3,"string")==0 || strcmp($3,"bool")==0){
                                  }				 
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0){
                                      int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                      for(i=0;i<100;i++){
                                          if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                              c1 = my_table[now_scope_level].te[i].type;
                                              break;
                                          }
                                      }
                                      for(j=0;j<100;j++){
                                          if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                              c2 = my_table[now_scope_level].te[j].type;
                                              break;
                                          }
                                      }
                                      if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                          yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                      }
                                  }
                                  printf("ASSIGN\n"); 
                                }
    | Expression ADD_ASSIGN Expression { if(strcmp($1,"int32")==0){ yyerror("cannot assign to int32"); }
                                         printf("ADD_ASSIGN\n"); }
    | Expression SUB_ASSIGN Expression { printf("SUB_ASSIGN\n"); }
    | Expression MUL_ASSIGN Expression { printf("MUL_ASSIGN\n"); }
    | Expression QUO_ASSIGN Expression { printf("QUO_ASSIGN\n"); }
    | Expression REM_ASSIGN Expression { printf("REM_ASSIGN\n"); }
    | Expression
    | Expression INC { printf("INC\n"); }
    | Expression DEC { printf("DEC\n"); 
                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                     }
    ;

Block
    : '{'{ now_scope_level += 1; 
           into_block +=1;/* in09 */ } StatementList '}' { dump_symbol(now_scope_level); 
                                                          create_symbol(now_scope_level);
                                                          now_scope_level -= 1; 
                                                          into_block -=1;/* in09 */ }
    ;

IfStmt
    : IF Expression { if(strcmp($2,"float32")==0){
                         printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition");
                      }
                      else if(strcmp($2,"int32")!=0 && strcmp($2,"float32")!=0 && strcmp($2,"string")!=0 && strcmp($2,"bool")!=0){
                          int i=0;  char* c1 = "";
                          for(i=0;i<100;i++){
                              if(strcmp($2,my_table[now_scope_level].te[i].name)==0){
                                  c1 = my_table[now_scope_level].te[i].type;
                                  break;
                              }
                          }
                          if(strcmp(c1,"int32")==0){
                              printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition");   
                          }
                      }
                    } IfStmt2
    ;

IfStmt2  /* in07 */
    : Block
    | Block ELSE IfStmt3
    ;
/* //in09
    : '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    | '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); } ELSE IfStmt3
    ;
*/

IfStmt3
    : IfStmt
    | Block
    ;

ForStmt /* in11 */
    : FOR Expression '{' { now_scope_level += 1;  into_block +=1;  // in11

                           if(strcmp($2,"float32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition"); 
                           }
                           else if(strcmp($2,"int32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition"); 
                           }  
                         } StatementList '}' { dump_symbol(now_scope_level);  
                                               create_symbol(now_scope_level); 
                                               now_scope_level -= 1; // in11
                                               into_block -=1; // in11
                                             }
    | FOR ForClause '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    ;

/* ForStmt before in11
ForStmt
    : FOR Expression '{' { if(strcmp($2,"float32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition");
                           }
                           else if(strcmp($2,"int32")==0){
                               printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition");
                           }
                         } StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    | FOR ForClause '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    ;
*/

ForClause
    : SimpleStmt ';' Expression ';' SimpleStmt
    ;

PrintStmt
    : PRINT '(' Expression ')' { if(strcmp($3,"int32")==0 || strcmp($3,"float32")==0 || strcmp($3,"string")==0 || strcmp($3,"bool")==0 ){
                                     printf("PRINT %s\n",$3);
                                 }
                                 else{
                                     int i =0;  char* c = "";
                                     for(i=0;i<100;i++){
                                         if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                             c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                             break;
                                         }
                                     }
                                     printf("PRINT %s\n",c);
                                 }
                               }
    | PRINTLN '(' Expression ')' { if(strcmp($3,"int32")==0 || strcmp($3,"float32")==0 || strcmp($3,"string")==0 || strcmp($3,"bool")==0 ){
                                       printf("PRINTLN %s\n",$3);
                                   }
                                   else{
                                       int i =0;  char* c = "";
                                       for(i=0;i<100;i++){
                                           if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                               c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                               break;
                                           }
                                       }
                                       printf("PRINTLN %s\n",c);
                                       
                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }
                                 }
    ;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    /*---*/
    //int now_scope_level = 0;

    //Symbol_Table my_table[50];
    int i=0;
    for(i=0;i<50;i++){
        my_table[i].element_num = 0;
    }
    /*---*/

    yylineno = 0;
    yyparse();

    dump_symbol(now_scope_level);  lookup_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    return 0;
}

static void create_symbol(int now_scope_level) {
    my_table[now_scope_level].element_num = 0;
    
}

static void insert_symbol(char* str, int num) {
    printf("> Insert {%s} into symbol table (scope level: %d)\n", str, num);
    
}

static void lookup_symbol() {
}

static void dump_symbol(int now_scope_level) {
    printf("> Dump symbol table (scope level: %d)\n", now_scope_level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");

    int i = 0;
    for(i=0;i<my_table[now_scope_level].element_num;i++){
        printf("%-10d%-10s%-10s%-10d%-10d%s\n",
        my_table[now_scope_level].te[i].index, my_table[now_scope_level].te[i].name, 
        my_table[now_scope_level].te[i].type, my_table[now_scope_level].te[i].address, 
        my_table[now_scope_level].te[i].line_number, my_table[now_scope_level].te[i].array_element_type);
    }
   
}



