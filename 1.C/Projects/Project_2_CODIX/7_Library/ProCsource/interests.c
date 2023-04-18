
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
           char  filnam[37];
};
static const struct sqlcxp sqlfpn =
{
    36,
    "../7_Library/ProCsource/interests.pc"
};


static unsigned int sqlctx = 1873736941;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {13,10};

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
"select i.inv_no ,i.amount ,i.amount_due ,i.currency ,i.issue_date ,i.due_dat\
e ,i.customer_id ,i.seq ,i.original_invoice_id ,c.credit_limit  from invoices \
i ,customers c where ((((c.customer_id=i.customer_id and i.amount_due is  not \
null ) and i.original_invoice_id is null ) and (:b0 is null  or c.external_ref\
erence=:b0)) and  not exists (select inv.inv_no  from invoices inv where inv.o\
riginal_invoice_id=i.inv_no))           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* cud (compilation unit data) array */
static const short sqlcud0[] =
{13,4130,1,0,0,
5,0,0,1,355,0,4,47,0,0,2,1,0,1,0,2,3,0,0,1,97,0,0,
28,0,0,2,428,0,9,79,0,0,2,2,0,1,0,1,97,0,0,1,0,0,0,
51,0,0,2,0,0,13,93,0,0,10,0,0,1,0,2,97,0,0,2,4,0,0,2,4,0,0,2,97,0,0,2,97,0,0,2,
97,0,0,2,3,0,0,2,3,0,0,2,97,0,0,2,3,0,0,
106,0,0,3,61,0,4,103,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
129,0,0,4,197,0,3,133,0,0,9,9,0,1,0,1,97,0,0,1,4,0,0,1,0,0,0,1,97,0,0,1,97,0,0,
1,97,0,0,1,3,0,0,1,3,0,0,1,97,0,0,
180,0,0,2,0,0,15,170,0,0,0,0,0,1,0,
};


#include "/media/sf_Shared/Final_project/7_Library/Headers/interests.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcErrorHandling.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/configMacro.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/funcSql.h"
#include "/media/sf_Shared/Final_project/7_Library/Headers/utility.h"
#include <string.h>
#include <sqlcpr.h>

#define LIMIT1 5000
#define LIMIT2 8000
#define DAYS_FOR_UNDER_LIMIT1 10
#define DAYS_FOR_ABOVE_LIMIT1 15
#define DAYS_FOR_ABOVE_LIMIT2 20
#define INTEREST_PERCENT 0.05
#define DAYS_TO_NEW_ISSUE_DATE 5

int insertInterests(const char* strExtRef)
{
    /* EXEC SQL BEGIN DECLARE SECTION; */ 

    char    ExtRef[MAX_EXTERNAL_REF_LENGHT] = { 0 };
    char    i_InvNo[MAX_INVOICE_NUMBER_LENGHT] = { 0 };
    float   i_Amount = 0.0f;
    float   i_AmountDue = 0.0f;
    char    i_Currency[MAX_LINE_CURRENCY_LENGHT] = { 0 };
    char    i_IssueDate[MAX_DATE_2_LENGHT] = { 0 };
    char    i_DueDate[MAX_DATE_2_LENGHT] = { 0 };
    int     i_CustomerID = 0;
    int     i_Seq = 0;
    char    i_OriginalInvoiceID[MAX_INVOICE_NUMBER_LENGHT] = { 0 };
    int     c_Credit_Limit = 0;
    char    i_NewInvNo[MAX_INVOICE_NUMBER_LENGHT] = { 0 };
    float   i_NewAmount = 0.0f;
    int     i_NewSeq = 0;
    char    i_NewIssueDate[MAX_DATE_2_LENGHT] = { 0 };
    char    i_NewDueDate[MAX_DATE_2_LENGHT] = { 0 };
    short   i_OrigInvNoInd = -1;
    int     MaxSeq = 0;
    int     DaysToNewDueDate = 0;
    int     isIvoiceForInterest = 0;
    /* EXEC SQL END DECLARE SECTION; */ 


    strcpy(ExtRef, strExtRef);

    if (strcmp(ExtRef, ""))
    {
        /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_7); */ 

        /* EXEC SQL SELECT COUNT(*) INTO :isIvoiceForInterest 
                                 FROM customers c, invoices i
                                WHERE c.customer_id = i.customer_id
                                  AND c.external_reference = :ExtRef
                                  AND i.amount_due IS NOT NULL
                                  AND i.original_invoice_id IS NULL
                                  AND i.inv_no NOT IN ( SELECT i2.original_invoice_id
                                                          FROM invoices i2, custmers c2
                                                         WHERE c2.customer_id = i2.customer_id
                                                           AND i2.original_invoice_id IS NOT NULL); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count(*)  into :b0  from customers c ,invoices\
 i where ((((c.customer_id=i.customer_id and c.external_reference=:b1) and i.a\
mount_due is  not null ) and i.original_invoice_id is null ) and i.inv_no not \
 in (select i2.original_invoice_id  from invoices i2 ,custmers c2 where (c2.cu\
stomer_id=i2.customer_id and i2.original_invoice_id is  not null )))";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&isIvoiceForInterest;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)ExtRef;
        sqlstm.sqhstl[1] = (unsigned long )61;
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
        if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_7);
}


        if (sqlca.sqlcode != 0)
	    {
		    ERROR_PRINT(ORA_ERR_FORMAT_7);
            return 0;
        }
        if (isIvoiceForInterest == 0)
        {
            OUTPUT_LOG_MSG("There is no invoice without interests for customer", ExtRef);
            printf("\nThere is no invoice without interests for customer %s\n", ExtRef);
            return 1;
        }
    }

    /* EXEC SQL DECLARE c_not_payed CURSOR FOR SELECT i.inv_no, i.amount, i.amount_due, i.currency, i.issue_date, i.due_date, i.customer_id, i.seq, i.original_invoice_id, c.credit_limit 
                                              FROM invoices i, customers c
                                             WHERE c.customer_id = i.customer_id
                                               AND i.amount_due IS NOT NULL
                                               AND i.original_invoice_id IS NULL 
                                               AND ( :ExtRef IS NULL OR c.external_reference = :ExtRef )
                                               AND NOT EXISTS ( SELECT inv.inv_no FROM invoices inv WHERE inv.original_invoice_id = i.inv_no ); */ 


    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_8); */ 

    /* EXEC SQL OPEN c_not_payed; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.stmt = sq0002;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )28;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.sqlpfmem = (unsigned int  )0;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqcmod = (unsigned int )0;
    sqlstm.sqhstv[0] = (unsigned char  *)ExtRef;
    sqlstm.sqhstl[0] = (unsigned long )61;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)0;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)ExtRef;
    sqlstm.sqhstl[1] = (unsigned long )61;
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
        return 0;
    }
    OUTPUT_LOG_MSG(program.programName, ORA_MSG_FORMAT_11);
    printf("Please, wait...\n");

    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_10); */ 

    /* EXEC SQL WHENEVER NOT FOUND DO break; */ 

 	for (;;)
	{
        /* EXEC SQL FETCH c_not_payed INTO :i_InvNo, :i_Amount, :i_AmountDue, :i_Currency, :i_IssueDate, :i_DueDate, :i_CustomerID, :i_Seq, :i_OriginalInvoiceID:i_OrigInvNoInd, :c_Credit_Limit; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )51;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)i_InvNo;
        sqlstm.sqhstl[0] = (unsigned long )51;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&i_Amount;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&i_AmountDue;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)i_Currency;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)i_IssueDate;
        sqlstm.sqhstl[4] = (unsigned long )11;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)i_DueDate;
        sqlstm.sqhstl[5] = (unsigned long )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&i_CustomerID;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&i_Seq;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)i_OriginalInvoiceID;
        sqlstm.sqhstl[8] = (unsigned long )51;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&i_OrigInvNoInd;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&c_Credit_Limit;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)0;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
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
            return 0;
        }
        OUTPUT_LOG_MSG("Processing invoice", i_InvNo);

        /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_7); */ 

        /* EXEC SQL SELECT MAX(seq) INTO :MaxSeq
                   FROM invoices 
                  WHERE customer_id = :i_CustomerID; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max(seq) into :b0  from invoices where custome\
r_id=:b1";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )106;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.sqlpfmem = (unsigned int  )0;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&MaxSeq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&i_CustomerID;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode == 1403) break;
        if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_7);
}


        i_NewSeq = MaxSeq + 1;

        if (c_Credit_Limit < LIMIT1)
        {
            DaysToNewDueDate = DAYS_FOR_UNDER_LIMIT1;
        }
        else if ((LIMIT1 <= c_Credit_Limit) && (c_Credit_Limit <= LIMIT2))
        {
            DaysToNewDueDate = DAYS_FOR_ABOVE_LIMIT1;
        }
        else
        {
            DaysToNewDueDate = DAYS_FOR_ABOVE_LIMIT2;
        }

        convertDateFormat(i_IssueDate); //from "DD-MON-YY" to "YYYYMMDD"
        convertDateFormat(i_DueDate);

        addDaysToDate(i_DueDate, DAYS_TO_NEW_ISSUE_DATE, i_NewIssueDate);
        addDaysToDate(i_NewIssueDate, DaysToNewDueDate, i_NewDueDate);

        newInviceNo(i_CustomerID, i_NewSeq, i_NewIssueDate, i_NewInvNo);
        nullTerminateString(i_InvNo); 

        i_NewAmount = i_AmountDue * INTEREST_PERCENT;

        /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_5); */ 

        /* EXEC SQL INSERT INTO invoices (inv_no, 
                                      amount, 
                                      amount_due, 
                                      currency,
                                      issue_date, 
                                      due_date, 
                                      customer_id, 
                                      seq, 
                                      original_invoice_id) 
                               VALUES (:i_NewInvNo,
                                      :i_NewAmount,
                                      :i_NewAmount,
                                      :i_Currency,
                                      TO_DATE(:i_NewIssueDate, 'YYYYMMDD'),
                                      TO_DATE(:i_NewDueDate, 'YYYYMMDD'),
                                      :i_CustomerID,
                                      :i_NewSeq,
                                      :i_InvNo); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 13;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "insert into invoices (inv_no,amount,amount_due,curren\
cy,issue_date,due_date,customer_id,seq,original_invoice_id) values (:b0,:b1,:b\
1,:b3,TO_DATE(:b4,'YYYYMMDD'),TO_DATE(:b5,'YYYYMMDD'),:b6,:b7,:b8)";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )129;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)i_NewInvNo;
        sqlstm.sqhstl[0] = (unsigned long )51;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&i_NewAmount;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&i_NewAmount;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(float);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)i_Currency;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)i_NewIssueDate;
        sqlstm.sqhstl[4] = (unsigned long )11;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)i_NewDueDate;
        sqlstm.sqhstl[5] = (unsigned long )11;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&i_CustomerID;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&i_NewSeq;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)i_InvNo;
        sqlstm.sqhstl[8] = (unsigned long )51;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)0;
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
        if (sqlca.sqlcode < 0) sql_error(ORA_ERR_FORMAT_5);
}


        OUTPUT_LOG_MSG("Inserted invoice", i_NewInvNo);
        if (sqlca.sqlcode != 0)
	    {
		    OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_5);
            ERROR_PRINT(ORA_ERR_FORMAT_5);
            return 0;
        }


        /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_4); */ 

        exec_commit();
        if (sqlca.sqlcode != 0)
	    {
		    OUTPUT_LOG_MSG(program.programName, ORA_ERR_FORMAT_4);
            ERROR_PRINT(ORA_ERR_FORMAT_4);
            return 0;
        }
    }
    /* EXEC SQL WHENEVER SQLERROR DO sql_error(ORA_ERR_FORMAT_9); */ 

    /* EXEC SQL CLOSE c_not_payed; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 13;
    sqlstm.arrsiz = 10;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )180;
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

    return 1;
}

