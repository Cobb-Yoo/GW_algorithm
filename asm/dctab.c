#define MAX_DLEN
#define MAX_DCTAB

typedef struct dctab{
	char directive[MAX_DLEN];
	char type;
#define DC_CNST
#define DC_RESW
	char unit;
#define DC_DW
#define DC_WD
#define DC_BT
}Dctab;

Dctab DCTAB[] = {
	"DINT", DC_CNST, DC_DW,
	"DWRD", DEC_CNST, DC_WD,
	"DBYT", DC_CNST, DC_BT,
	"RINT", DC_RESV, DC_DW,
	"RWRD", DC_RESV, DC_WD,
	"RBYT", DC_RESV, DC_BT
};

Dctab *see_DCTAB(char *dcc){
	int i;
	for(i=0;i<MAX_DCTAB;i++){
		if(!strcmp(DCTAB[i].directive, dcc))
			return (&DCTAB[i]);
	}
	return NULL;
}
