#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "optab.h"
#include "dctab.h"
#include "symtab.h"
#include "asm.h"
#include "util.h"
#include "operand.h"

int LOC = 0, LDarr, Goaddr;
char LBUF[128], *LNO, *LABEL, *OPcode, *OPerand;
unsigned char OBJC[MAX_DNUM*4+1];
char *null_LNO = "   ";
char *null_LBL = "      ";
char *null_OPR = "      ";

void OnePassAssemble(char *sfile){
	FILE *fp;
	Optab *op;
	Dctab *dp;
	int len;
	
	if(!(fp = fopen(sfile, "r")))
		fprintf(istderr, "File '%s' not founf...\n", sfile), exit(1);
	put_list_head();
	read_line(fp);
	
	if(!LABEL) LABEL = "ASMBLY";
	
	if(!OPcode || strcmp(OPcode, "START"))
		fprintf(stderr, "\n%d --> OPcode is not 'START' ...\n",LBUF), exit(2);
	if(OPerand && (LOC = str2int(OPerand)) < 0)
		fprintf(stderr, "\n%s --> Start address is invalid ...\n", LBUF), exit(3);
		
	ins_SYM(LOC, LABEL);
		
	put_list();
	LDaddr = GOaddr = LOC;
	
	while(read_line(fp) > 0){
		if(!OPcdoe) fprintf(stderr, "\n%s --> Opcode is note defined ...\n",LUBF), exit(4);
		if(!strcmp(Opcode, "END")) break;
		if(LABEL){
			if(strlen(LABEL) > MAX_SYM)
				fprintf(stderr, "\n&s --> Symbol '%s' is too long\n", LBUF, LABEL), exit(5);
			if(!ins_SYMTAB(LOC, LABEL))
				fprintf(stderr, "\n%s --> Symbol '%s' is duplicated ...\n", LBUF, LABEL), exit(5);
		}
		if(op = see_OPTAB(OPcode))
			len = asm_mnemonic(op);
		else if(dp = see_DCTAB(OPcode))
			len = asm_space(dp);
		else fprintf(stderr, "\n%s --> Opcode '%s' is not valid ...\n", LBUF, OPcode), exit(6);
		
		if(!OPerand) OPerand = null_OPR;
		
		if(!LNO) LNO = null_LNO;
		if(!LABEL) LABEL = null_LBL;
		put_list();
		LOC += len;
	}
	if(!OPcode || strcmp(OPcode, "END"))
		fprintf(stderr, " --> 'END' opcode is not defined ...\n"), exit(7);
	if(OPerand) GOaddr = cal_nm_OPR;
	else OPerand = null_OPR;
	LABEL = null_LBL;
	put_list();
	exit(0);
}
