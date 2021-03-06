/* GROUP 15
Group Members:
Pritika Ramu          ID: 2019A7PS1140P
Preetike Verma        ID: 2019A7PS0088P
Aadit Deshpande       ID: 2019A7PS0077P
Sneha                 ID: 2019A7PS0042P
Nandan B Parikh       ID: 2019A7PS0097P
*/

#ifndef _DRIVERDEF_
#define _DRIVERDEF_
#include "typeChecker.h"

int main(int argc, char *argv[])
{

	if (argc < 3)
	{
		printf("Wrong command. Type: ./stage2exe testcase.txt op.txt\n");
		return 0;
	}

	printf("GROUP 15:\nAadit Deshpande\nNandan Bharatkumar Parikh\nPreetika Verma\nPritika Ramu\nSneha\n");
	printf("\n\nIMPLEMENTATION DETAILS OF STAGE 1\n");
	printf("1. Initialized grammar\n");
	printf("2. Automated computation of FIRST\n");
	printf("3. Implemented lexical analyser\n");
	printf("4. Implemented syntax analyser\n");
	printf("5. Implemented PANIC MODE error recovery\n");
	printf("6. Implemented Abstract Syntax Tree Creation\n");
	printf("7. Implemented Symbol Table\n");
	printf("8. Implemented Type Checker\n");

	bool flag = true;

	while (flag)
	{

		printf("\n\nEnter number to perform the function:\n");
		printf("0: For exit\n");
		printf("1: For printing the token list (on the console)\n");
		printf("2: For parsing to verify the syntactic correctness of the input source code and printing the parse tree\n");
		printf("3: For printing the AST on the console\n");
		printf("4: For printing allocated memory and number of nodes in parse tree and AST\n");
		printf("5: For printing the symbol table on the console\n");
		printf("6: For printing the global symbol table on the console\n");
		printf("7: For printing activation record sizes\n");
		printf("8: For printing record types and sizes\n");
		printf("9: Type checking and semantic analysis with error reporting\n");


		printf("\n\nEnter your choice: ");

		int choice;
		scanf("%d", &choice);

		switch (choice)
		{

		case 0:
		{
			printf("THANK YOU!\n");
			flag = false;
			break;
		}
		

		case 1:
		{
			// print tokens from lexer
			line = 1;
			FILE *fp = startLexer(argv[1]);
			initTable();
			while (1)
			{
				tokenInfo pleasework = getNextToken();
				if (pleasework.tid == SENTINEL)
					break;
				if (pleasework.tid != LEX_ERROR)
				{
					if (pleasework.tid == TK_COMMENT)
						printf("Line no. %d\tLexeme \t\t\t%%\t\tTK_COMMENT", pleasework.lineNo);
					else
						printf("Line no. %d\tLexeme %20s", pleasework.lineNo, pleasework.lexeme);
				}
				printf("\t\t");
				if (pleasework.tid != TK_COMMENT)
					printToken(pleasework.tid);
				printf("\n");
			}
			fclose(fp);
			break;
		}

		case 2:
		{
			// parser
			line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			int numNodes = printParseTree(ptree, outfile);
			break;
		}
		case 3:
		{
			// AST
			line = 1;
			printf("TRAVERSAL ORDER - INORDER\n");
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			int numNodes = printAST(astree, outfile);
			printf("\nNumber of Nodes %d\n",numNodes);
			break;
		}
		case 4:
		{
			line = 1;
			// printf("fsjfs");
			// printf("TRAVERSAL ORDER - INORDER\n");
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			int m = printParseTree(ptree, outfile);
			ast *astree = initAST(ptree);
			int n = printAST(astree, outfile);
			int x = sizeof(struct astNode);
			int y = sizeof(struct tree);
			float ans = 100.00*((m*y)-(n*x))/(m*y);

			printf("\nParse tree Number of nodes %d\n",m);
			printf("Allocated memory = %d\n\n",m*y);
			printf("AST Number of nodes %d\n",m);
			printf("Allocated memory = %d\n\n",n*x);
			printf("Compression Ratio: %f %%\n",ans);
			
			break;

		}

		case 5:
		{
			line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			
			initializeSymbolTable(astree);
			// printRecordTable(SymbolTable->RecordUnionTable);
			// printf("\nRecord table printed above\n");
			// printFunctionTable(SymbolTable->FunctionTable);
			// printf("Function table printed above\n");
			// //printIDTable(SymbolTable->IdentifierTable);
			// printf("Identifier table printed above\n");
			printFinalTable(SymbolTable->FunctionTable);
			
			break;

			
		}
		case 6:
		{
			line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			free(ptree);
			
			initializeSymbolTable(astree);
			// printf("Starting Semantic Analysis\n");
			printGlobalTable(SymbolTable->FunctionTable);
			// printf("\nSEMANTIC ERRORS:\n");
    		// printf("_____________________________\n");
			// semanticAnalyser(astree);
			// printf("_____________________________\n");
			//printSemanticErrors();
    		//print_Redeclarations();

			// printf("\nEnd of Semantic Analysis.\n");
			break;
		}
		case 7:
		{
			line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			
			initializeSymbolTable(astree);
			// printRecordTable(SymbolTable->RecordUnionTable);
			// printf("\nRecord table printed above\n");
			printFunctionTable(SymbolTable->FunctionTable);
			printf("Function table printed above\n");
			// //printIDTable(SymbolTable->IdentifierTable);
			// printf("Identifier table printed above\n");
			// printFinalTable(SymbolTable->FunctionTable);
			
			break;

			
		}
		case 8:
		{
			line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			
			initializeSymbolTable(astree);
			printRecordTable(SymbolTable->RecordUnionTable);
			printf("\nRecord table printed above\n");
			// printFunctionTable(SymbolTable->FunctionTable);
			// printf("Function table printed above\n");
			// //printIDTable(SymbolTable->IdentifierTable);
			// printf("Identifier table printed above\n");
			// printFinalTable(SymbolTable->FunctionTable);
			
			break;

			
		}
		case 9:
		{
			clock_t start_time, end_time;
            double total_CPU_time, total_CPU_time_in_seconds;
            start_time = clock();
        	line = 1;
			char *testFile = argv[1];
			char *outfile = argv[2];
			initGrammar(G);
			NO_OF_SEMANTIC_ERRORS = 0;
			populateFirstFollow("First.txt", true);
			populateFirstFollow("Follow.txt", false);
			computeParseTable();
			parseTree ptree = parseInputSourceCode(testFile);
			ast *astree = initAST(ptree);
			free(ptree);
			
			initializeSymbolTable(astree);
			// printf("Starting Semantic Analysis\n");
			//printGlobalTable(SymbolTable->FunctionTable);
			printf("\nSEMANTIC ERRORS:\n");
    		printf("_____________________________\n");
			semanticAnalyser(astree);
			printf("_____________________________\n");
			//printSemanticErrors();
			
    		print_Redeclarations();
			// printf("NO. OF SEMANTIC ERRORS IS %d\n", NO_OF_SEMANTIC_ERRORS);
            end_time = clock();
            total_CPU_time = (double) (end_time - start_time);
            total_CPU_time_in_seconds = total_CPU_time / CLOCKS_PER_SEC;
            printf("\nTotal CPU time = %lf\nTotal CPU time in seconds = %lf\n",total_CPU_time,total_CPU_time_in_seconds);
			break;
		}
		case 10:
		{
			printf("not implemented\n");
			break;
		}

		}
	}

	return 0;
}

#endif