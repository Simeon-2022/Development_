
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[38];
};
static const struct sqlcxp sqlfpn =
{
    37,
    "../7_Library/ProCsource/funcReport.pc"
};


static unsigned int sqlctx = 547488187;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
      const short *cud;
   unsigned char  *sqlest;
      const char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned int   sqlpfmem;
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {13,9};

/* SQLLIB Prototypes */
extern void sqlcxt (void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlcx2t(void **, unsigned int *,
                    struct sqlexd *, const struct sqlcxp *);
extern void sqlbuft(void **, char *);
extern void sqlgs2t(void **, char *);
extern void sqlorat(void **, unsigned int *, void *);

/* Forms Interface */
static const int IAPSUCC = 0;
static const int IAPFAIL = 1403;
static const int IAPFTL  = 535;
extern void sqliem(unsigned char *, signed int *);

 static const char *sq0002 = 
"select inv_no ,amount ,amount_due ,currency ,issue_date ,due_date ,customer_\
id ,seq ,original_invoice_id  from invoices where customer_id=:b0           ";

 static const char *sq0003 = 
"select first_name ,family_name ,customer_id ,external_reference  from custom\
ers where customer_id not  in (select i.customer_id  from invoices i ,payments\
 p ,customers c where ((i.inv_no=p.invoice_no and p.payment_dt between TO_DATE\
(:b0,'DDMMYYYY','NLS_DATE_LANGUAGE=English') and TO_DATE(:b1,'DDMMYYYY','NLS_D\
ATE_LANGUAGE=English')) and i.customer_id=c.customer_id)) order by 3,1,2      \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,105,0,4,37,0,0,4,1,0,1,0,2,97,0,0,2,97,0,0,2,97,0,0,1,3,0,0,
36,0,0,2,152,0,9,71,0,0,1,1,0,1,0,1,3,0,0,
55,0,0,2,0,0,13,90,0,0,9,0,0,1,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,
106,0,0,2,0,0,15,123,0,0,0,0,0,1,0,
121,0,0,3,394,0,9,182,0,0,2,2,0,1,0,1,97,0,0,1,97,0,0,
144,0,0,3,0,0,13,199,0,0,4,0,0,1,0,2,97,0,0,2,97,0,0,2,3,0,0,2,97,0,0,
175,0,0,3,0,0,15,231,0,0,0,0,0,1,0,
};


#include "/media/sf_Shared/Final_project/7_Library/Headers/funcReport.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcErrorHandling.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcOpenCloseFile.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/configMacro.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcDirFileEdit.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcSql.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/utility.h"
#include <string.h>
#include <sqlcpr.h>
#include <stdio.h>

#define AFFECTED_ROWS ((int)(sqlca.sqlerrd[2]))

int report_client(int custID, const char* strDirectory)
{
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    InvNo[MAX_INVOICE_NUMBER_LENGHT] = {0};
    float   Amount = 0.0f;
    float   AmountDue = 0.0f;
    char    Currency[MAX_LINE_CURRENCY_LENGHT] = {0};
    char    IssueDate[MAX_DATE_2_LENGHT] ={0};
    char    DueDate[MAX_DATE_2_LENGHT] = {0};
    int     CustomerID = 0;
    int     Seq = 0;
    char    OriginalInvoiceID[MAX_INVOICE_NUMBER_LENGHT] = {0};
    short   AmountDueInd = -1;
    short   OrigInvNoInd = -1;
    char    FirstName[MAX_NAME_LENGHT] = {0};
    char    LastName[MAX_NAME_LENGHT] = {0};
    char    ExtRef[MAX_EXTERNAL_REF_LENGHT] = {0};
    /* EXEC SQL END DECLARE SECTION; */ 


    connect_oracle(USER_CONNECTION);
    CustomerID = custID;

    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_7); */ 

    /* EXEC SQL SELECT first_name, family_name, external_reference 
               INTO :FirstName, :LastName, :ExtRef 
               FROM customers
              WHERE customer_id = :CustomerID; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = "select first_name ,family_name ,external_reference into :\
b0,:b1,:b2  from customers where customer_id=:b3";
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )5;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqhstv[0] = (unsigned char  *)FirstName;
    sqlstm.sqhstl[0] = (unsigned long )61;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)LastName;
    sqlstm.sqhstl[1] = (unsigned long )61;
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)0;
    sqlstm.sqinds[1] = (         int  )0;
    sqlstm.sqharm[1] = (unsigned long )0;
    sqlstm.sqadto[1] = (unsigned short )0;
    sqlstm.sqtdso[1] = (unsigned short )0;
    sqlstm.sqhstv[2] = (unsigned char  *)ExtRef;
    sqlstm.sqhstl[2] = (unsigned long )61;
    sqlstm.sqhsts[2] = (         int  )0;
    sqlstm.sqindv[2] = (         short *)0;
    sqlstm.sqinds[2] = (         int  )0;
    sqlstm.sqharm[2] = (unsigned long )0;
    sqlstm.sqadto[2] = (unsigned short )0;
    sqlstm.sqtdso[2] = (unsigned short )0;
    sqlstm.sqhstv[3] = (unsigned char  *)&CustomerID;
    sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[3] = (         int  )0;
    sqlstm.sqindv[3] = (         short *)0;
    sqlstm.sqinds[3] = (         int  )0;
    sqlstm.sqharm[3] = (unsigned long )0;
    sqlstm.sqadto[3] = (unsigned short )0;
    sqlstm.sqtdso[3] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_7);
}


    if (sqlca.sqlcode != 0)
	{
		OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_7);
        OUTPUT_LOG_MSG(program.programName, "The customer does not exist!");
        printf("The customer does not exist!\n");
        return 0;
    }
    OUTPUT_LOG_MSG("Create report for customer_External_reference", ExtRef);
    
    char reportDirectory[MAX_SIZE_FILEPATH] = { 0 };
    createDirectory(strDirectory, "/Report", reportDirectory);
    OUTPUT_LOG_MSG(program.programName, "Create directory /Report");

    char filePath[MAX_SIZE_FILEPATH] = { 0 };
    fileInit(reportDirectory, filePath, "_CUSTOMER_");
    FILE* reportFile = fileOpen(filePath, "w");
  
    fprintf(reportFile, "REPORT for\nCUSTOMER_ID: %d\nEXTERNAL_REFERENCE: %s\nFIRST_MANE: %s\nLAST_NAME: %s\n", CustomerID, ExtRef, FirstName, LastName);

    /* EXEC SQL DECLARE c_select CURSOR FOR SELECT inv_no, amount, amount_due, currency, issue_date, due_date, customer_id, seq, original_invoice_id
                                           FROM invoices
                                          WHERE customer_id = :CustomerID; */ 

    if (sqlca.sqlcode != 0)
	{
		OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_7);
        ERROR_PRINT(ORA_ERR_FORMAT_7);
        return 0;
    }

    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_8); */ 

    /* EXEC SQL OPEN c_select; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 4;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0002;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )36;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)&CustomerID;
    sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqphsv = sqlstm.sqhstv;
    sqlstm.sqphsl = sqlstm.sqhstl;
    sqlstm.sqphss = sqlstm.sqhsts;
    sqlstm.sqpind = sqlstm.sqindv;
    sqlstm.sqpins = sqlstm.sqinds;
    sqlstm.sqparm = sqlstm.sqharm;
    sqlstm.sqparc = sqlstm.sqharc;
    sqlstm.sqpadto = sqlstm.sqadto;
    sqlstm.sqptdso = sqlstm.sqtdso;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_8);
}


    if (sqlca.sqlcode != 0)
	{
		OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_8);
        ERROR_PRINT(ORA_ERR_FORMAT_8);
        return 0;
    }
    OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_11);

    fprintf(reportFile, "\n");
    fprintf(reportFile, "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(reportFile, "| INV_NO:              | AMOUNT:     | AMOUNT_DUE: | CURRENCY: | ISSUE_DATE:   | DUE_DATE:     | CUST_ID:  | SEQ:      | ORIGINAL_INVOICE_ID:| PAYMENT_STATUS |\n");
    fprintf(reportFile, "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    
    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_10); */ 

    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 


    for (;;)
	{
        /* EXEC SQL FETCH c_select INTO :InvNo, :Amount, :AmountDue:AmountDueInd, :Currency, :IssueDate, :DueDate, :CustomerID, :Seq, :OriginalInvoiceID:OrigInvNoInd; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )55;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)InvNo;
        sqlstm.sqhstl[0] = (unsigned long )51;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&Amount;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&AmountDue;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&AmountDueInd;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)Currency;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)IssueDate;
        sqlstm.sqhstl[4] = (unsigned long )11;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)DueDate;
        sqlstm.sqhstl[5] = (unsigned long )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&CustomerID;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&Seq;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)OriginalInvoiceID;
        sqlstm.sqhstl[8] = (unsigned long )51;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&OrigInvNoInd;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_10);
}


        if (sqlca.sqlcode != 0)
	    {
		    OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_10);
            ERROR_PRINT(ORA_ERR_FORMAT_10);
       }

        nullTerminateString(InvNo);
        nullTerminateString(OriginalInvoiceID);
        char isPayed[10] = {0};
        if (AmountDue > 0)
        {
            strcpy(isPayed, "NOT PAYED");
        }
        else
        {
            strcpy(isPayed, "PAYED");
        }

        fprintf(reportFile, "| %20s |", InvNo);
        fprintf(reportFile, "%12.2f |", Amount);
        fprintf(reportFile, "%12.2f |", AmountDue);
        fprintf(reportFile, "%10s |", Currency);
        fprintf(reportFile, "%14s |", IssueDate);
        fprintf(reportFile, "%14s |", DueDate);
        fprintf(reportFile, "%10d |", CustomerID);
        fprintf(reportFile, "%10d |", Seq);
        fprintf(reportFile, "%20s |", OriginalInvoiceID);
        fprintf(reportFile, "%15s |\n", isPayed);
    }
    fprintf(reportFile, "---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_9); */ 

    /* EXEC SQL CLOSE c_select; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )106;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_9);
}


    if (sqlca.sqlcode != 0)
	{
	    OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_9);
        ERROR_PRINT(ORA_ERR_FORMAT_9);
        return 0;
    }
    OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_12);
   
    exec_commit_all();
    fileClose(reportFile);
	return 1;
}

int report_period(const char* strStartDate, const char* strEndDate,  const char* strDirectory)
{
    connect_oracle(USER_CONNECTION);

    /* EXEC SQL BEGIN DECLARE SECTION; */ 

	    int		c_CustomerID = 0;
	    char	c_FirstName[MAX_NAME_LENGHT] = {0};
	    char	c_FamilytName[MAX_NAME_LENGHT] = {0};
	    char	c_ExternalReference[MAX_EXTERNAL_REF_LENGHT] = {0};
        int     rowsFetched = 0;
        char    startDate[9] = {0};
        char    endDate[9] = {0};
    /* EXEC SQL END DECLARE SECTION; */ 

	
    printf("Please, wait...\n");

    strcpy(startDate, strStartDate);
    strcpy(endDate, strEndDate);

	/* EXEC SQL DECLARE dateRange_cursor 
	CURSOR FOR SELECT first_name, family_name, customer_id, external_reference 
	FROM customers
	WHERE  customer_id NOT IN (
		SELECT i.customer_id
		FROM invoices i, payments p, customers c
		WHERE i.inv_no = p.invoice_no
		AND p.payment_dt BETWEEN TO_DATE(:startDate, 'DDMMYYYY','NLS_DATE_LANGUAGE=English') AND TO_DATE(:endDate, 'DDMMYYYY','NLS_DATE_LANGUAGE=English')
		AND i.customer_id = c.customer_id
		)
	ORDER BY 3,1,2; */ 



    OUTPUT_LOG_MSG("Create report for period", "");
    OUTPUT_LOG_MSG(strStartDate, strEndDate);
		
    char reportDirectory[MAX_SIZE_FILEPATH] = { 0 };
    createDirectory(strDirectory, "/Report", reportDirectory);
    OUTPUT_LOG_MSG(program.programName, "Create directory /Report");

    char filePath[MAX_SIZE_FILEPATH] = { 0 };
    fileInit(reportDirectory, filePath, "_PERIOD_");
    FILE* reportFile = fileOpen(filePath, "w");

    fprintf(reportFile, "REPORT for period: %s - %s\n", strStartDate, strEndDate);
    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_8); */ 

	/* EXEC SQL OPEN dateRange_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 13;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )121;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.sqlpfmem = (unsigned int  )0;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)startDate;
 sqlstm.sqhstl[0] = (unsigned long )9;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)endDate;
 sqlstm.sqhstl[1] = (unsigned long )9;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqphsv = sqlstm.sqhstv;
 sqlstm.sqphsl = sqlstm.sqhstl;
 sqlstm.sqphss = sqlstm.sqhsts;
 sqlstm.sqpind = sqlstm.sqindv;
 sqlstm.sqpins = sqlstm.sqinds;
 sqlstm.sqparm = sqlstm.sqharm;
 sqlstm.sqparc = sqlstm.sqharc;
 sqlstm.sqpadto = sqlstm.sqadto;
 sqlstm.sqptdso = sqlstm.sqtdso;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_8);
}


    if (sqlca.sqlcode != 0)
	{
        OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_8);
        ERROR_PRINT(ORA_ERR_FORMAT_8);
    }
	
	OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_11);
	fprintf(reportFile, "\n");
	fprintf(reportFile, "------------------------------------------------------------------------------------\n");
	fprintf(reportFile, "|          FIRST_NAME:|           LAST_NAME:|    CUSTOMER_ID:|  EXTERNAL_REFERENCE:|\n");
	fprintf(reportFile, "------------------------------------------------------------------------------------\n");

    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_10); */ 

	/* EXEC SQL WHENEVER NOT FOUND DO break; */ 

    for (;;)
	{
	    /* EXEC SQL FETCH dateRange_cursor INTO :c_FirstName, :c_FamilytName, :c_CustomerID, :c_ExternalReference; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 13;
     sqlstm.arrsiz = 9;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )144;
     sqlstm.selerr = (unsigned short)1;
     sqlstm.sqlpfmem = (unsigned int  )0;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlstm.sqfoff = (         int )0;
     sqlstm.sqfmod = (unsigned int )2;
     sqlstm.sqhstv[0] = (unsigned char  *)c_FirstName;
     sqlstm.sqhstl[0] = (unsigned long )61;
     sqlstm.sqhsts[0] = (         int  )0;
     sqlstm.sqindv[0] = (         short *)0;
     sqlstm.sqinds[0] = (         int  )0;
     sqlstm.sqharm[0] = (unsigned long )0;
     sqlstm.sqadto[0] = (unsigned short )0;
     sqlstm.sqtdso[0] = (unsigned short )0;
     sqlstm.sqhstv[1] = (unsigned char  *)c_FamilytName;
     sqlstm.sqhstl[1] = (unsigned long )61;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)0;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&c_CustomerID;
     sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)0;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)c_ExternalReference;
     sqlstm.sqhstl[3] = (unsigned long )61;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)0;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqphsv = sqlstm.sqhstv;
     sqlstm.sqphsl = sqlstm.sqhstl;
     sqlstm.sqphss = sqlstm.sqhsts;
     sqlstm.sqpind = sqlstm.sqindv;
     sqlstm.sqpins = sqlstm.sqinds;
     sqlstm.sqparm = sqlstm.sqharm;
     sqlstm.sqparc = sqlstm.sqharc;
     sqlstm.sqpadto = sqlstm.sqadto;
     sqlstm.sqptdso = sqlstm.sqtdso;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
     if (sqlca.sqlcode == 1403) break;
     if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_10);
}


	     if (0 == sqlca.sqlcode) 
        {
		    if (sqlca.sqlerrd[2] <= 0 && rowsFetched == 0) 
            {
				fprintf(reportFile, "| %19s | %19s | %14s | %19s |\n", "N/A","N/A","N/A","N/A");
				break;
		    }else if (sqlca.sqlerrd[2] <= 0 && rowsFetched != 0)
            {
				break;
            }
	    }
        else
        {
			if (rowsFetched == 0)
			{
			fprintf(reportFile, "| %19s | %19s | %14s | %19s |\n", "N/A","N/A","N/A","N/A");
			}
		    break;
	    }

		nullTerminateString(c_FirstName);
		nullTerminateString(c_FamilytName);
		nullTerminateString(c_ExternalReference);
		
        fprintf(reportFile, "| %19s | %19s | %14d | %19s |\n", c_FirstName, c_FamilytName, c_CustomerID, c_ExternalReference);
        rowsFetched++;
	}
    fprintf(reportFile, "------------------------------------------------------------------------------------\n");
    fprintf(reportFile,"Rows fetched: %d\n",rowsFetched);
    printf("\nRows fetched: %d\n",rowsFetched);
    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_9); */ 

    /* EXEC SQL CLOSE dateRange_cursor; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 9;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )175;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_9);
}


    if (sqlca.sqlcode != 0)
	{
        OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_9);
        ERROR_PRINT(ORA_ERR_FORMAT_9);
    }
	OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_12);

    exec_commit_all();
    fileClose(reportFile);
	return 1;
}
