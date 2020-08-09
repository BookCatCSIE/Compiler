/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    //#include <io.h> //hw3
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

    typedef struct { //*//hw3
        int idata;
        float fdata;
        char* sdata;
        bool bdata;
    }Data; //*//hw3

    typedef struct {
        int index;
        char* name;
        char* type;
        int address;
        int line_number;
        char* array_element_type;
        Data data; //*//hw3
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

    /* Global variables */
    bool HAS_ERROR = false;

    FILE* file;

    int label1 = 1; //odd    //*//hw3_in02
    int label2 = 0; //even   //*//hw3_in02
 
    int label3 = 300; //  // For_label_name  //hw3_in09
    int label7 = 301; //  // For_label_name  //hw3_in13

    int label5 = 101; //odd  // If_else_label_name  //hw3_in07 in11
    int label6 = 100; //even  // If_else_label_name  //hw3_in07 in11

    int label9 = 201; //  // For_;_;_label_name  //hw3_in12
    int label8 = 200; //  // For_;_;_label_name  //hw3_in12

    fpos_t file_pos1;
    fpos_t file_pos2;

    int at_bottom_for2 =0;
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
%type <s_val> IfStmt2 ForStmt6 ForStmt5 ForStmt8 ForStmt7 ForOperand ForStmt9 ForStmt10

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
                               //hw3_in04
                               fprintf(file,"\tnewarray int\n");
                               fprintf(file,"\tastore %d\n",total_address);
                               //hw3_in04
                           }
                           else if(strcmp($3,"array float32")==0){
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].type = "array";
                               my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].array_element_type = "float32";
                               //hw3_in04
                               fprintf(file,"\tnewarray float\n");
                               fprintf(file,"\tastore %d\n",total_address);
                               //hw3_in04
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

                           //*//hw3_03
                           int store_register = my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address;

                           if(strcmp($3,"int32")==0){
                               fprintf(file,"\tldc 0\n");
                               fprintf(file,"\tistore %d\n",store_register);
                           }
                           else if(strcmp($3,"float32")==0){
                               fprintf(file,"\tldc 0.0\n");
                               fprintf(file,"\tfstore %d\n",store_register);
                           } //*//hw3_03
                           else if(strcmp($3,"string")==0){ //hw3_in05
                               fprintf(file,"\tldc \"\"\n");
                               fprintf(file,"\tastore %d\n",store_register);
                           } //hw3_in05
                           
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
                                      
                                      //*//hw3_01
                                      int store_register = my_table[now_scope_level].te[my_table[now_scope_level].element_num-1].address;

                                      if(strcmp($3,"int32")==0){
                                          fprintf(file,"\tistore %d\n",store_register);
                                      }
                                      else if(strcmp($3,"float32")==0){
                                          fprintf(file,"\tfstore %d\n",store_register);
                                      }
                                      else if(strcmp($3,"string")==0){ //hw3_03
                                          fprintf(file,"\tastore %d\n",store_register);
                                      }
                                      else if(strcmp($3,"bool")==0){
                                          fprintf(file,"\tistore %d\n",store_register);
                                      } //hw3_03

                                      //*//hw3_01

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
                                   printf("LOR\n");    $$ = "bool"; 
                            
                                   fprintf(file,"\tior\n"); //*//hw3_in02
                                 }
    | Expression2
    ;

Expression2
    : Expression2 LAND Expression3 { if(strcmp($1,"int32")==0 || strcmp($3,"int32")==0){
                                         yyerror("invalid operation: (operator LAND not defined on int32)");
                                     }                                    
                                     printf("LAND\n");   $$ = "bool";

                                     fprintf(file,"\tiand\n"); //*//hw3_in02
                                   }
    | Expression3
    ;

Expression3
    : Expression3 '>' Expression5 { printf("GTR\n");  $$ = "bool"; 
                                    //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3

                                    if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfcmpl\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } //hw3_in02
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in08

                                        int address1 =0;     int ii =0;   
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifgt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in08

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
    | Expression3 '<' Expression5 { printf("LSS\n");  $$ = "bool"; 
                                    //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3

                                    if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1++;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2++;
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfcmpl\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1++;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2++;
                                    } //hw3_in02
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in13

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tiflt L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in13

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
    | Expression3 GEQ Expression5 { printf("GEQ\n");  $$ = "bool";
                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
    | Expression3 LEQ Expression5 { printf("LEQ\n");  $$ = "bool";

                                    if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in11

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifle L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in11

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
    | Expression3 EQL Expression5 { printf("EQL\n");  $$ = "bool"; 

                                    if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in07

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifeq L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in07

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; } //hw3
                                  }
    | Expression3 NEQ Expression5 { printf("NEQ\n");  $$ = "bool"; 

                                    if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in13

                                        int address1 =0;     int ii =0;
                                        for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                            if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                address1 = my_table[now_scope_level].te[ii].address;
                                                break;
                                            }
                                        }

                                        fprintf(file,"\tiload %d\n",address1);
                                        fprintf(file,"\tswap\n");
                                        fprintf(file,"\tisub\n");
                                        fprintf(file,"\tifne L_cmp_%d\n",label1);
                                        fprintf(file,"\ticonst_0\n");
                                        fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                        fprintf(file,"L_cmp_%d:\n",label1);
                                        label1 = label1 +2 ;
                                        fprintf(file,"\ticonst_1\n");
                                        fprintf(file,"L_cmp_%d:\n",label2);
                                        label2 = label2 +2 ;
                                    } // hw3_in13

                                    if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                                  }
    | Expression5
    ;

Expression5
    : Expression5 '+' Expression6 { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                        yyerror("invalid operation: ADD (mismatched types int32 and float32)");
                                        HAS_ERROR = true; //hw3_in09
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"int32")==0){
                                        yyerror("invalid operation: ADD (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tiadd\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfadd\n");
                                        $$ = "float32";
                                    } //hw3_in02   
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
                                        else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tiadd\n");
                                        } //*//hw3_01
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfadd\n");
                                        } //*//hw3_01


                                    }
                                    //else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //in09 LOR error
                                    //    $$ = "int32";
                                    //}
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($3,"int32")==0){ //in09 for condition error  //hw3_in06
                                        int i=0;  char* c1 = "";   int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"int32")==0){
                                            $$ = "int32";   

                                            fprintf(file,"\tiload %d\n",load_address);
                                            fprintf(file,"\tiadd\n");
                                        }
                                    }  //hw3_in06
                                    else if(strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0 && strcmp($1,"float32")==0){  //hw3_in06
                                        int i=0;  char* c1 = "";  int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            $$ = "float32";

                                            fprintf(file,"\tfload %d\n",load_address);
                                            fprintf(file,"\tfadd\n");
                                        }
                                    } //hw3_in06
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($3,"float32")==0){  //hw3_in13
                                        int i=0;  char* c1 = "";  int load_address = 0;
                                        for(i=0;i<100;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                load_address = my_table[now_scope_level].te[i].address;
                                                break;
                                            }
                                        }
                                        if(strcmp(c1,"float32")==0){
                                            $$ = "float32";

                                            fprintf(file,"\tfload %d\n",load_address);
                                            fprintf(file,"\tfadd\n");
                                        }
                                    } //hw3_in13

                                    printf("ADD\n"); 
                                  }
    | Expression5 '-' Expression6 { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                        yyerror("invalid operation: SUB (mismatched types int32 and float32)");
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"int32")==0){
                                        yyerror("invalid operation: SUB (mismatched types float32 and int32)");
                                    }
                                    else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tisub\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfsub\n");
                                        $$ = "float32";
                                    } //hw3_in02 
                                    else if(strcmp($1,"array int32")==0 && strcmp($3,"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\tisub\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"array float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n"); 
                                        fprintf(file,"\tfload 99\n");
                                        fprintf(file,"\tfsub\n");
                                        $$ = "float32";
                                    } //hw3_in04
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
                                        else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tisub\n");
                                        } //*//hw3_01
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){ //*//hw3_01
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfsub\n");
                                        } //*//hw3_01

                                    }
                                    printf("SUB\n"); }
    | Expression6
    ;

Expression6
    : Expression6 '*' Expression7 { if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\timul\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfmul\n");
                                        $$ = "float32";
                                    } //hw3_in02
                                    else if(strcmp($1,"array int32")==0 && strcmp($3,"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\timul\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"array float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tfload 99\n"); 
                                        fprintf(file,"\tfmul\n");
                                        $$ = "float32";
                                    } //hw3_in04 
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0){ //*//hw3_01
                                        
                                        //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }

                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        int address1 = 0; int address2 = 0;  int declare1 = 0;  int declare2 = 0; 

                                        for(i=0;i<my_table[now_scope_level].element_num;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                address1 = my_table[now_scope_level].te[i].address ;
                                                declare1 = 1;
                                                break;
                                            }
                                        }
                                        if(declare1 == 0){ //in13
                                            if(into_block >0){
                                                int k1 =0;   int k2 =0;
                                                for(k1=0;k1<50;k1++){
                                                    for(k2=0;k2<my_table[k1].element_num;k2++){
                                                        if(strcmp($1,my_table[k1].te[k2].name)==0){
                                                            c1 = my_table[k1].te[k2].type;
                                                            address1 = my_table[k1].te[k2].address ;

                                                            //scope_dif = now_scope_level - j;
                                                            //now_scope_level -= scope_dif;
                                                            break;
                                                        }
                                                    }
                                                } 
                                            }
                                        } //in13

                                        for(j=0;j<my_table[now_scope_level].element_num;j++){
                                            if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                address2 = my_table[now_scope_level].te[j].address ;
                                                declare2 = 1;
                                                break;
                                            }
                                        }
                                        if(declare2 == 0){ //in13
                                            if(into_block >0){
                                                int k1 =0;   int k2 =0;
                                                for(k1=0;k1<50;k1++){
                                                    for(k2=0;k2<my_table[k1].element_num;k2++){
                                                        if(strcmp($3,my_table[k1].te[k2].name)==0){
                                                            c2 = my_table[k1].te[k2].type;
                                                            address2 = my_table[k1].te[k2].address ;

                                                            //scope_dif = now_scope_level - j;
                                                            //now_scope_level -= scope_dif;
                                                            break;
                                                        }
                                                    }
                                                }
                                            }
                                        } //in13 

                                        /*if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation:  (mismatched types int32 and float32)");
                                            HAS_ERROR = true;
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation:  (mismatched types float32 and int32)");
                                            HAS_ERROR = true;
                                        }*/
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){
                                           /*
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }
                                           */

                                           $$ = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\timul\n");
                                        }
                                        if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfmul\n");
                                        }
                                    } //*//hw3_01

                                    printf("MUL\n");
                                  }
    | Expression6 '/' Expression7 { if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tidiv\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfdiv\n");
                                        $$ = "float32";
                                    } //hw3_in02 
                                    else if(strcmp($1,"array int32")==0 && strcmp($3,"int32")==0){ //hw3_in04
                                        fprintf(file,"\tistore 98\n");
                                        fprintf(file,"\tiaload\n");
                                        //fprintf(file,"\tswap\n");
                                        fprintf(file,"\tiload 98\n");
                                        fprintf(file,"\tidiv\n");
                                        $$ = "int32";
                                    }
                                    else if(strcmp($1,"array float32")==0 && strcmp($3,"float32")==0){
                                        fprintf(file,"\tfstore 99\n");
                                        fprintf(file,"\tfaload\n");
                                        //fprintf(file,"\tswap\n"); 
                                        fprintf(file,"\tfload 99\n");
                                        fprintf(file,"\tfdiv\n");
                                        $$ = "float32";
                                    } //hw3_in04
                                    else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0){ //*//hw3_01
                                        int i=0; int j=0;  char* c1 = ""; char* c2 = "";
                                        for(i=0;i<my_table[now_scope_level].element_num;i++){
                                            if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                                c1 = my_table[now_scope_level].te[i].type;
                                                break;
                                            }
                                        }
                                        for(j=0;j<my_table[now_scope_level].element_num;j++){
                                            if(strcmp($3,my_table[now_scope_level].te[j].name)==0){
                                                c2 = my_table[now_scope_level].te[j].type;
                                                break;
                                            }
                                        }
                                        /*if(strcmp(c1,"int32")==0 && strcmp(c2,"float32")==0){
                                            yyerror("invalid operation:  (mismatched types int32 and float32)");
                                            HAS_ERROR = true;
                                        }
                                        else if(strcmp(c1,"float32")==0 && strcmp(c2,"int32")==0){
                                            yyerror("invalid operation:  (mismatched types float32 and int32)");
                                            HAS_ERROR = true;
                                        }*/
                                        if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "int32";
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tiload %d\n",address2);
                                           fprintf(file,"\tidiv\n");
                                        }
                                        if(strcmp(c1,"float32")==0 && strcmp(c2,"float32")==0){
                                           int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                           for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                               if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                   address1 = my_table[now_scope_level].te[ii].address;
                                                   break;
                                               }
                                           }
                                           for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                               if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                   address2 = my_table[now_scope_level].te[jj].address;
                                                   break;
                                               }
                                           }

                                           $$ = "float32";
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tfload %d\n",address2);
                                           fprintf(file,"\tfdiv\n");
                                        } 

                                    } //*//hw3_01

                                    printf("QUO\n"); 
                                  }
    | Expression6 '%' Expression7 { if(strcmp($1,"float32")==0 || strcmp($3,"float32")==0){
                                      yyerror("invalid operation: (operator REM not defined on float32)");
                                    }
                                    else if(strcmp($1,"int32")==0 && strcmp($3,"int32")==0){ //hw3_in02
                                        fprintf(file,"\tirem\n");
                                        $$ = "int32";
                                    } //hw3_in02  	  
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
                                            else if(strcmp(c1,"int32")==0 && strcmp(c2,"int32")==0){ //*//hw3_01
                                                int address1 =0;   int address2 =0;        int ii =0;      int jj =0;
                                                for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                    if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                        address1 = my_table[now_scope_level].te[ii].address;
                                                        break;
                                                    }
                                                }
                                                for(jj=0;jj<my_table[now_scope_level].element_num;jj++){
                                                    if(strcmp($3,my_table[now_scope_level].te[jj].name)==0){
                                                        address2 = my_table[now_scope_level].te[jj].address;
                                                        break;
                                                    }
                                                }

                                                $$ = "int32";
                                                fprintf(file,"\tiload %d\n",address1);
                                                fprintf(file,"\tiload %d\n",address2);
                                                fprintf(file,"\tirem\n");
                                            } //*//hw3_01

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
                               $$ = $2;/*in09 -> in02*/ 
                               
                               if(strcmp($1,"NEG")==0){ //hw3_in02
                                   if(strcmp($2,"int32")==0){
                                       fprintf(file,"\tineg\n"); 
                                   }
                                   else if(strcmp($2,"float32")==0){
                                       fprintf(file,"\tfneg\n");
                                   }
                               }

                               if(strcmp($1,"NOT\nNOT")==0){

                               }
                               else if(strcmp($1,"NOT")==0){
                                   fprintf(file,"\ticonst_1\n");
                                   fprintf(file,"\tixor\n");
                                   /*if(strcmp($2,"bool")==0){
                                       fprintf(file,"\ticonst_1\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tixor\n");
                                   }*/
                               } //hw3_in02 
                               
 
                             }
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
                                       /*for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                               $$ = my_table[now_scope_level].te[i].array_element_type ;
                                               // in04, need IDENT $$ = id
                                               break;
                                           }
                                       }*/

                                       //hw3_in04
                                       int load_address = 0;   char* c = "";

                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                               load_address = my_table[now_scope_level].te[i].address ;
                                               c = my_table[now_scope_level].te[i].array_element_type ;
                                               break;
                                           }
                                       }

                                       fprintf(file,"\taload %d\n",load_address);
                                       fprintf(file,"\tswap\n");
                                       /*if(strcmp(c,"int32")==0){
                                           fprintf(file,"\tiaload\n");
                                       }
                                       else if(strcmp(c,"float32")==0){
                                           fprintf(file,"\tfaload\n");
                                       }*/
                                       //hw3_in04
                      
                                       if(strcmp(c,"int32")==0){
                                           $$ = "array int32";
                                       }
                                       else if(strcmp(c,"float32")==0){
                                           $$ = "array float32";
                                       }
                                     }
    | Type '(' Expression ')' { if(strcmp($3,"int32")==0 && strcmp($1,"float32")==0){ 
                                    printf("I to F\n"); 
                                    fprintf(file,"\ti2f\n"); //hw3_in06
                                    $$ = "float32";
                                }
                                else if(strcmp($3,"float32")==0 && strcmp($1,"int32")==0){ 
                                    printf("F to I\n");
                                    fprintf(file,"\tf2i\n"); //hw3_in06
                                    $$ = "int32";
                                }
                                else if(strcmp($3,"array float32")==0 && strcmp($1,"int32")==0){ //hw3_in13
                                    printf("F to I\n");
                                    fprintf(file,"\tfaload\n");
                                    fprintf(file,"\tf2i\n");
                                    $$ = "int32";
                                } //hw3_in13
                                else{
                                    int i =0;  char* c = "";
                                    int load_address = 0 ; //hw3_in06
                                    for(i=0;i<my_table[now_scope_level].element_num;i++){
                                        if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                            c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                            load_address = my_table[now_scope_level].te[i].address ; //hw3_in06
                                            break;
                                        }
                                    }

                                    if(strcmp(c,"int32")==0 && strcmp($1,"float32")==0){ 
                                        printf("I to F\n"); 
                                
                                        fprintf(file,"\tiload %d\n",load_address); //hw3_in06
                                        fprintf(file,"\ti2f\n"); //hw3_in06
                                        $$ = "float32";
                                    }
                                    else if(strcmp(c,"float32")==0 && strcmp($1,"int32")==0){ 
                                        printf("F to I\n"); 

                                        fprintf(file,"\tfload %d\n",load_address); //hw3_in06
                                        fprintf(file,"\tf2i\n"); //hw3_in06
                                        $$ = "int32";
                                    }
                                }
			      }
    ;

Operand
    : INT_LIT { printf("INT_LIT %d\n",$1);  $$="int32";
                fprintf(file,"\tldc %d\n",$1); //*//hw3_in01
              }
    | FLOAT_LIT { printf("FLOAT_LIT %.6f\n",$1);  $$="float32";
                  fprintf(file,"\tldc %f\n",$1); //*//hw3_in01
                }
    | TRUE { printf("TRUE\n");   $$="bool";
             fprintf(file,"\ticonst_1\n"); //*//hw3_in02
           }
    | FALSE { printf("FALSE\n");   $$="bool";
              fprintf(file,"\ticonst_0\n"); //*//hw3_in02
            }
    | '"' STRING_LIT '"' { printf("STRING_LIT %s\n",$2);   $$="string";
                           fprintf(file,"\tldc \"%s\"\n",$2); //*//hw3_in
                         }
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
                      for(j=0;j<50;j++){ // j<now_scope_level
                          for(k=0;k<my_table[j].element_num;k++){
                              if(strcmp($1,my_table[j].te[k].name)==0){
                                  if(now_scope_level > j){ // hw3_in13
                                      scope_dif = now_scope_level - j;
                                      now_scope_level -= scope_dif;
                                  }
                                  else if(now_scope_level < j){
                                      scope_dif = j - now_scope_level ;
                                      now_scope_level += scope_dif;
                                  } // hw3_in13
                                  printf("IDENT (name=%s, address=%d)\n",$1,my_table[j].te[k].address);
                                  break;
                              }
                          }
                      }//in09
                  }
                  else{
                      printf("error:%d: undefined: %s\n",yylineno+1,$1);//in10

                      HAS_ERROR = true; //hw3_in10
                  }
              }
            }     
    | '(' Expression ')' { $$ = $2; //hw3_in02
                         }
    ;

/*--------------------------------------------*/

SimpleStmt
    : Expression '=' Expression { if(strcmp($1,"int32")==0 && strcmp($3,"float32")==0){
                                      yyerror("invalid operation: ASSIGN (mismatched types int32 and float32)");
                                  }       							 
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0 && strcmp($3,"array int32")!=0 && strcmp($3,"array float32")!=0){
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
                                  else if(strcmp($1,"array int32")==0 && strcmp($3,"int32")==0){ //hw3_in04
                                  // this condition only can be assigning int to array element of int type
                                      fprintf(file,"\tiastore\n");
                                      //fprintf(file,"\tpop\n");
                                  }
                                  else if(strcmp($1,"array float32")==0 && strcmp($3,"float32")==0){
                                  // this condition only can be assigning float to array element of float type
                                      fprintf(file,"\tfastore\n");
                                      //fprintf(file,"\tpop\n");
                                  } //hw3_in04
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;   
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }
                                                
                                      fprintf(file,"\tistore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"float32")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tfstore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"string")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tastore %d\n",address1);
                                  }//hw3_in05
                                  else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"bool")==0){ //hw3_in05
                                      int address1 =0;    int ii =0;
                                      for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                          if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                              address1 = my_table[now_scope_level].te[ii].address;
                                              break;
                                          }
                                      }

                                      fprintf(file,"\tistore %d\n",address1);
                                  }//hw3_in05

                                  printf("ASSIGN\n"); 
                                }
    | Expression ADD_ASSIGN Expression { if(strcmp($1,"int32")==0){ yyerror("cannot assign to int32"); }
                                         else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tiadd\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }
               
                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tfadd\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("ADD_ASSIGN\n"); 
                                       }
    | Expression SUB_ASSIGN Expression { if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tisub\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfsub\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05
                               
                                         printf("SUB_ASSIGN\n"); 
                                       }
    | Expression MUL_ASSIGN Expression { if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             //fprintf(file,"\tswap\n");
                                             fprintf(file,"\timul\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             //fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfmul\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("MUL_ASSIGN\n"); 
                                       }
    | Expression QUO_ASSIGN Expression { if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tidiv\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05
                                         else if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"float32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tfload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tfdiv\n");
                                             fprintf(file,"\tfstore %d\n",address1);
                                         }//hw3_in05

                                         printf("QUO_ASSIGN\n"); 
                                       }
    | Expression REM_ASSIGN Expression { if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 && strcmp($1,"array int32")!=0 && strcmp($1,"array float32")!=0 && strcmp($3,"int32")==0){ //hw3_in05
                                             int address1 =0;    int ii =0;
                                             for(ii=0;ii<my_table[now_scope_level].element_num;ii++){
                                                 if(strcmp($1,my_table[now_scope_level].te[ii].name)==0){
                                                     address1 = my_table[now_scope_level].te[ii].address;
                                                     break;
                                                 }
                                             }

                                             fprintf(file,"\tiload %d\n",address1);
                                             fprintf(file,"\tswap\n");
                                             fprintf(file,"\tirem\n");
                                             fprintf(file,"\tistore %d\n",address1);
                                         }//hw3_in05 

                                         printf("REM_ASSIGN\n"); 
                                       }
    | Expression
    | Expression INC { printf("INC\n"); 
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tiadd\n");
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tfadd\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
                     }
    | Expression DEC { printf("DEC\n"); 
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11
          
                       if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tisub\n");  // 2nd top - 1st top
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfsub\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

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

/* hw3_in07 */
IfStmt1
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

                      fprintf(file,"\tifeq L_if_false_%d\n",label5); //hw3_in07
                      //label5 = label5 +2 ;
                    }
    ;

IfStmt2
    : IfStmt1 Block { fprintf(file,"\tgoto L_if_exit_%d\n",label6); //hw3_in07
                      //label6 = label6 +2 ;

                      //label5 = label5 -2 ;
                      fprintf(file,"L_if_false_%d :\n",label5); //hw3_in07
                      label5 = label5 +2 ; ///
                    }
    ;

IfStmt
    : IfStmt2 { //label6 = label6 -2 ;
                fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in07
                label6 = label6 +2 ; ///
              } 
    | IfStmt2 ELSE Block { //fprintf(file,"L_if_exit_%d :\n",label2); //hw3_in07
                           //label2 ++;

                           //label6 = label6 -2 ;
                           fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in07
                           label6 = label6 +2 ; ///
                         }
    | IfStmt2 ELSE IfStmt { //label6 = label6 -2 ;
                            fprintf(file,"L_if_exit_%d :\n",label6); //hw3_in11
                            label6 = label6 +2 ; ///
                          }
    ;

/* hw3_in07 */

/*
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

IfStmt2  
    : Block
    | Block ELSE IfStmt3
    ;

IfStmt3
    : IfStmt
    | Block
    ;
*/


/* //in09
    : '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    | '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); } ELSE IfStmt3
    ;
*/


/*  hw3_in08 */

ForOperand
    : FOR { fgetpos(file, &file_pos1); //hw3_in13

            fprintf(file,"L_for_begin_%d :\n",label3); //hw3_in08
            label3 = label3 +2;  //hw3_in13
          }
    ;


ForStmt2
    : ForOperand Expression { fprintf(file,"\tifeq L_for_exit_%d\n",label7); /*hw3_in08*/
                              if(strcmp($2,"float32")==0){
                                  printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition");
                              }
                              else if(strcmp($2,"int32")==0){
                                  printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition");
                              }

                              //label3 ++;
                              label7 = label7 +2;  //hw3_in13
                            }
    ;

ForStmt3 
    : ForStmt2 '{' { now_scope_level += 1;  into_block +=1;  /*in11*/
                   } StatementList { //label3 --;
                                     label3 = label3 -2;  //hw3_in13
                                     label7 = label7 -2;  //hw3_in13

                                     fprintf(file,"\tgoto L_for_begin_%d\n",label3); //hw3_in08
                                     fprintf(file,"L_for_exit_%d :\n",label7); //hw3_in08
                                     //label3 ++; //hw3_in09
                                   }
    ;

ForStmt
    : ForStmt3 '}' { dump_symbol(now_scope_level);
                     create_symbol(now_scope_level);
                     now_scope_level -= 1; // in11
                     into_block -=1; // in11 

                     label3 = label3 +10;  //hw3_in13
                     label7 = label7 +10;  //hw3_in13
                   }
    | ForStmt9
    ;

ForStmt5
    : ForOperand SimpleStmt { fprintf(file,"L_for_begin_%d :\n",label8); //hw3_in12 
                              label8 = label8 +2; ///in12_in13///

                              fgetpos(file, &file_pos2); //hw3_in13

                              fsetpos(file, &file_pos1); //hw3_in13
                              fprintf(file,"L_for_conflict_0 :\n");
                              label3 = label3 -2; //hw3_in13

                              fsetpos(file, &file_pos2); //hw3_in13
                            } ';'
    ;

ForStmt6
    : ForStmt5 Expression { fprintf(file,"\tifeq L_for_exit_%d\n",label9);
                            label9 = label9 +2; ///in12_in13///
                          }
    ;

ForStmt7
    : INC '{' { at_bottom_for2 ++; ///in12_in13///

              }StatementList { //label8 = label8 -2;
                              //fprintf(file,"\tgoto L_for_begin_%d\n",label8); //hw3_in12
                                ////label8 = label8 +2;
                              //label9 = label9 -2;         
                              //fprintf(file,"L_for_exit_%d :\n",label9); //hw3_in12
                                ////label9 = label9 +2;

      } '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1);  
              at_bottom_for2 --; ///in12_in13///
            }
    ;

/*
ForStmt8
    : SimpleStmt ForStmt7
    ;
*/

ForStmt9
    : ForStmt6 ForStmt8
    ;

ForStmt10
    : ';' Expression { $$ = $2; }
    ;

ForStmt8
    : ForStmt10 ForStmt7 { printf("INC\n");
                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       if(strcmp($1,"int32")!=0 && strcmp($1,"float32")!=0 && strcmp($1,"string")!=0 && strcmp($1,"bool")!=0 ){ //*//hw3_in01
                           int i=0;   char* c1 = "";   int address1 =0;
                           for(i=0;i<my_table[now_scope_level].element_num;i++){
                               if(strcmp($1,my_table[now_scope_level].te[i].name)==0){
                                   c1 = my_table[now_scope_level].te[i].type;
                                   address1 = my_table[now_scope_level].te[i].address;
                                   break;
                               }
                           }

                           if(strcmp(c1,"int32")==0 ){
                               fprintf(file,"\tldc 1\n");
                               fprintf(file,"\tiload %d\n",address1);
                               fprintf(file,"\tiadd\n");
                               fprintf(file,"\tistore %d\n",address1);
                           }
                           else if(strcmp(c1,"float32")==0 ){
                               fprintf(file,"\tldc 1.0\n");
                               fprintf(file,"\tfload %d\n",address1);
                               fprintf(file,"\tfadd\n");
                               fprintf(file,"\tfstore %d\n",address1);
                           }

                       }//*//hw3_in01

                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in11

                       // ForStmt7
                       label8 = label8 -2; ///in12_in13///
                       fprintf(file,"\tgoto L_for_begin_%d\n",label8); //hw3_in12
                   
                       label9 = label9 -2; ///in12_in13///
                       fprintf(file,"L_for_exit_%d :\n",label9); //hw3_in12

                       //label8 = label8 +10; //hw3_in13  ///in12_in13/// 
                       //label9 = label9 +10; //hw3_in13  ///in12_in13/// 

                       if(at_bottom_for2 == 0){ ///in12_in13///
                           label8 = label8 +10;
                           label9 = label9 +10;
                       } ///in12_in13///
                     }
    ;


/*
ForClause
    : SimpleStmt ';' Expression ';' SimpleStmt
    ;
*/

/* FOR ForClause '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); } */
/*  hw3_in08 */

/* ForStmt before hw3_in08
ForStmt // in11
    : FOR { fprintf(file,"L_for_begin :\n"); //hw3_in08
          }Expression { fprintf(file,"\tifeq L_for_exit\n"); //hw3_in08
          }'{' { now_scope_level += 1;  into_block +=1;  //in11
                  if(strcmp($2,"float32")==0){ 
                      printf("error:%d: %s\n", yylineno+1, "non-bool (type float32) used as for condition"); 
                  }
                  else if(strcmp($2,"int32")==0){ 
                      printf("error:%d: %s\n", yylineno+1, "non-bool (type int32) used as for condition"); 
                  } 
      }StatementList { fprintf(file,"\tgoto L_for_begin\n"); //hw3_in08

      }'}' { dump_symbol(now_scope_level);  
              create_symbol(now_scope_level); 
              now_scope_level -= 1; // in11
              into_block -=1; // in11

              fprintf(file,"L_for_exit :\n"); //hw3_in08
      }
    | FOR ForClause '{' StatementList '}' { dump_symbol(now_scope_level+1);  create_symbol(now_scope_level+1); }
    ;
*/

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


PrintStmt
    : PRINT '(' Expression ')' { if(strcmp($3,"int32")==0 || strcmp($3,"float32")==0 || strcmp($3,"string")==0 || strcmp($3,"bool")==0 ){
                                     printf("PRINT %s\n",$3);
                                 }
                                 else if(strcmp($3,"array int32")==0){ // hw3_in04
                                     printf("PRINT int32\n");
                                 }
                                 else if(strcmp($3,"array float32")==0){
                                     printf("PRINT float32\n");
                                 } // hw3_in04
                                 else{
                                     int i =0;  char* c = "";
                                     for(i=0;i<100;i++){
                                         if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                             c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                             break;
                                         }
                                     }
                                     printf("PRINT %s\n",c);

                                     //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//hw3_in13
                                 }

                                 //*//hw3_01
                                   if(strcmp($3,"int32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                   }
                                   else if(strcmp($3,"float32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                   }
                                   else if(strcmp($3,"array int32")==0){ //hw3_in04
                                       fprintf(file,"\tiaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                   }
                                   else if(strcmp($3,"array float32")==0){
                                       fprintf(file,"\tfaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                   } //hw3_in04
                                   else if(strcmp($3,"string")==0){ // hw3_in
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                   } // hw3_in
                                   else if(strcmp($3,"bool")==0){ // hw3_in02
                                       fprintf(file,"\tifne L_cmp_%d\n",label1);
                                       fprintf(file,"\tldc \"%s\"\n","false");
                                       fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                       fprintf(file,"L_cmp_%d:\n",label1);
                                       label1 = label1 +2 ;
                                       fprintf(file,"\tldc \"%s\"\n","true");
                                       fprintf(file,"L_cmp_%d:\n",label2);
                                       label2 = label2 +2 ;                            
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                   } // hw3_in02  
                                   else if(strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0 ){
                                       int i=0;   char* c1 = "";   int address1 =0;
                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                               c1 = my_table[now_scope_level].te[i].type;
                                               address1 = my_table[now_scope_level].te[i].address;
                                               break;
                                           }
                                       }

                                       if(strcmp(c1,"int32")==0 ){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(I)V\n");
                                       }
                                       else if(strcmp(c1,"float32")==0 ){
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(F)V\n");
                                       }
                                       else if(strcmp(c1,"string")==0){ // hw3_in03
                                           fprintf(file,"\taload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                       }
                                       else if(strcmp(c1,"bool")==0){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tifne L_cmp_%d\n",label1);
                                           fprintf(file,"\tldc \"%s\"\n","false");
                                           fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                           fprintf(file,"L_cmp_%d:\n",label1);
                                           label1 = label1 +2 ;
                                           fprintf(file,"\tldc \"%s\"\n","true");
                                           fprintf(file,"L_cmp_%d:\n",label2);
                                           label2 = label2 +2 ;
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
                                       }  // hw3_in03

                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//hw3_in13
                                   }
                                   //*//hw3_01
                               }
    | PRINTLN '(' Expression ')' { if(strcmp($3,"int32")==0 || strcmp($3,"float32")==0 || strcmp($3,"string")==0 || strcmp($3,"bool")==0 ){
                                       printf("PRINTLN %s\n",$3);
                                   }
                                   else if(strcmp($3,"array int32")==0){ // hw3_in04
                                       printf("PRINTLN int32\n");
                                   }
                                   else if(strcmp($3,"array float32")==0){
                                       printf("PRINTLN float32\n");
                                   } // hw3_in04
                                   else{
                                       int i =0;  char* c = "";
                                       for(i=0;i<100;i++){
                                           if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                               c = my_table[now_scope_level].te[i].type;  // in06, need IDENT $$ = type of id
                                               break;
                                           }
                                       }
                                       printf("PRINTLN %s\n",c);
                                       
                                       //if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }

                                   //*//hw3_01
                                   if(strcmp($3,"int32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                   }
                                   else if(strcmp($3,"float32")==0){
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                   }
                                   else if(strcmp($3,"array int32")==0){ //hw3_in04
                                       fprintf(file,"\tiaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                   }
                                   else if(strcmp($3,"array float32")==0){
                                       fprintf(file,"\tfaload\n");
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                   } //hw3_in04
                                   else if(strcmp($3,"string")==0){ // hw3_in
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                   } // hw3_in
                                   else if(strcmp($3,"bool")==0){ // hw3_in02
                                       fprintf(file,"\tifne L_cmp_%d\n",label1);
                                       fprintf(file,"\tldc \"%s\"\n","false");
                                       fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                       fprintf(file,"L_cmp_%d:\n",label1);
                                       label1 = label1 +2 ;
                                       fprintf(file,"\tldc \"%s\"\n","true");
                                       fprintf(file,"L_cmp_%d:\n",label2);
                                       label2 = label2 +2 ;
                                       fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                       fprintf(file,"\tswap\n");
                                       fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                   } // hw3_in02 
                                   else if(strcmp($3,"int32")!=0 && strcmp($3,"float32")!=0 && strcmp($3,"string")!=0 && strcmp($3,"bool")!=0 ){
                                       int i=0;   char* c1 = "";   int address1 =0;
                                       for(i=0;i<my_table[now_scope_level].element_num;i++){
                                           if(strcmp($3,my_table[now_scope_level].te[i].name)==0){
                                               c1 = my_table[now_scope_level].te[i].type;
                                               address1 = my_table[now_scope_level].te[i].address;
                                               break;
                                           }
                                       }

                                       if(strcmp(c1,"int32")==0 ){
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(I)V\n");
                                       }
                                       else if(strcmp(c1,"float32")==0 ){
                                           fprintf(file,"\tfload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(F)V\n");
                                       }
                                       else if(strcmp(c1,"string")==0){ // hw3_in03
                                           fprintf(file,"\taload %d\n",address1);
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                       } 
                                       else if(strcmp(c1,"bool")==0){ 
                                           fprintf(file,"\tiload %d\n",address1);
                                           fprintf(file,"\tifne L_cmp_%d\n",label1);
                                           fprintf(file,"\tldc \"%s\"\n","false");
                                           fprintf(file,"\tgoto L_cmp_%d\n",label2);
                                           fprintf(file,"L_cmp_%d:\n",label1);
                                           label1 = label1 +2 ;
                                           fprintf(file,"\tldc \"%s\"\n","true");
                                           fprintf(file,"L_cmp_%d:\n",label2);
                                           label2 = label2 +2 ;
                                           fprintf(file,"\tgetstatic java/lang/System/out Ljava/io/PrintStream;\n");
                                           fprintf(file,"\tswap\n");
                                           fprintf(file,"\tinvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
                                       } // hw3_in03

                                       if(into_block >0){now_scope_level += scope_dif;  scope_dif =0; }//in09
                                   }
                                   //*//hw3_01
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

    HAS_ERROR = false;
    /*---*/

    /*---*/
    /*if(access("hw3.j",0)==0){
        remove("hw3.j");
    }*/

    file = fopen("hw3.j","w");

    fprintf(file,".source hw3.j\n.class public Main\n.super java/lang/Object\n.method public static main([Ljava/lang/String;)V\n.limit stack 100  ; Define your storage size.\n.limit locals 100 ; Define your local space number.\n");

    /*---*/

    yylineno = 0;
    yyparse();

    dump_symbol(now_scope_level);  lookup_symbol();
	printf("Total lines: %d\n", yylineno);
    fclose(yyin);

    /*---*/
    fprintf(file,"\treturn\n.end method\n");
    fclose(file);
    /*---*/

    if (HAS_ERROR) {
        remove("hw3.j");
    }

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



