SQL> SELECT * FROM emp;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    

14 rows selected.

SQL> SELECT * FROM emp JOIN dept on dept.deptno=emp.deptno WHERE dept.loc= 'NEW YORK';

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7839 KING       PRESIDENT            17/11/81       5000                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7934 MILLER     CLERK           7782 23/12/82       1300                    10         10 ACCOUNTING     NEW YORK                                                                                 

SQL> SELECT * FROM emp WHERE comm>0;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    

SQL> 
SQL> SELECT * FROM emp WHERE mgr IS NOT NULL;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    

13 rows selected.

SQL> SELECT * FROM emp WHERE mgr is NULL;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    

SQL> SELECT * FROM emp WHERE job = 'SALESMAN' OR job = 'ANALYST'
  2  SELECT * FROM emp JOIN dept ON dept.deptno=emp.deptno WHERE emp.job='CLERK' AND dept.loc='CHICAGO';
SELECT * FROM emp JOIN dept ON dept.deptno=emp.deptno WHERE emp.job='CLERK' AND dept.loc='CHICAGO'
*
ERROR at line 2:
ORA-00933: SQL command not properly ended 


SQL> 
SQL> SELECT * FROM emp WHERE sal > 3000;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    

SQL> 
SQL> SELECT UPPER(ENAME) FROM emp;

UPPER(ENAM                                                                                                                                                                                              
----------                                                                                                                                                                                              
SMITH                                                                                                                                                                                                   
ALLEN                                                                                                                                                                                                   
WARD                                                                                                                                                                                                    
JONES                                                                                                                                                                                                   
MARTIN                                                                                                                                                                                                  
BLAKE                                                                                                                                                                                                   
CLARK                                                                                                                                                                                                   
SCOTT                                                                                                                                                                                                   
KING                                                                                                                                                                                                    
TURNER                                                                                                                                                                                                  
ADAMS                                                                                                                                                                                                   

UPPER(ENAM                                                                                                                                                                                              
----------                                                                                                                                                                                              
JAMES                                                                                                                                                                                                   
FORD                                                                                                                                                                                                    
MILLER                                                                                                                                                                                                  

14 rows selected.

SQL> SELECT INITCAP(ENAME) FROM emp;

INITCAP(EN                                                                                                                                                                                              
----------                                                                                                                                                                                              
Smith                                                                                                                                                                                                   
Allen                                                                                                                                                                                                   
Ward                                                                                                                                                                                                    
Jones                                                                                                                                                                                                   
Martin                                                                                                                                                                                                  
Blake                                                                                                                                                                                                   
Clark                                                                                                                                                                                                   
Scott                                                                                                                                                                                                   
King                                                                                                                                                                                                    
Turner                                                                                                                                                                                                  
Adams                                                                                                                                                                                                   

INITCAP(EN                                                                                                                                                                                              
----------                                                                                                                                                                                              
James                                                                                                                                                                                                   
Ford                                                                                                                                                                                                    
Miller                                                                                                                                                                                                  

14 rows selected.

SQL> SELECT SUBSTR(ENAME,3,2) FROM emp;

SUBSTR(E                                                                                                                                                                                                
--------                                                                                                                                                                                                
IT                                                                                                                                                                                                      
LE                                                                                                                                                                                                      
RD                                                                                                                                                                                                      
NE                                                                                                                                                                                                      
RT                                                                                                                                                                                                      
AK                                                                                                                                                                                                      
AR                                                                                                                                                                                                      
OT                                                                                                                                                                                                      
NG                                                                                                                                                                                                      
RN                                                                                                                                                                                                      
AM                                                                                                                                                                                                      

SUBSTR(E                                                                                                                                                                                                
--------                                                                                                                                                                                                
ME                                                                                                                                                                                                      
RD                                                                                                                                                                                                      
LL                                                                                                                                                                                                      

14 rows selected.

SQL> 
SQL> SELECT * FROM emp order by hiredate desc;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    

14 rows selected.

SQL> SELECT * FROM emp order by comm desc NULLs last;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    

14 rows selected.

SQL> 
SQL> SELECT ename, deptno, avg(sal) over(partition by deptno) FROM emp;

ENAME          DEPTNO AVG(SAL)OVER(PARTITIONBYDEPTNO)                                                                                                                                                   
---------- ---------- -------------------------------                                                                                                                                                   
CLARK              10                      2916,66667                                                                                                                                                   
KING               10                      2916,66667                                                                                                                                                   
MILLER             10                      2916,66667                                                                                                                                                   
JONES              20                            2175                                                                                                                                                   
FORD               20                            2175                                                                                                                                                   
ADAMS              20                            2175                                                                                                                                                   
SMITH              20                            2175                                                                                                                                                   
SCOTT              20                            2175                                                                                                                                                   
WARD               30                      1566,66667                                                                                                                                                   
TURNER             30                      1566,66667                                                                                                                                                   
ALLEN              30                      1566,66667                                                                                                                                                   

ENAME          DEPTNO AVG(SAL)OVER(PARTITIONBYDEPTNO)                                                                                                                                                   
---------- ---------- -------------------------------                                                                                                                                                   
JAMES              30                      1566,66667                                                                                                                                                   
BLAKE              30                      1566,66667                                                                                                                                                   
MARTIN             30                      1566,66667                                                                                                                                                   

14 rows selected.

SQL> SELECT deptno, MIN(sal), MAX(sal), COUNT(empno) FROM emp GROUP BY deptno;

    DEPTNO   MIN(SAL)   MAX(SAL) COUNT(EMPNO)                                                                                                                                                           
---------- ---------- ---------- ------------                                                                                                                                                           
        30        950       2850            6                                                                                                                                                           
        20        800       3000            5                                                                                                                                                           
        10       1300       5000            3                                                                                                                                                           

SQL> 
SQL> SELECT * FROM emp WHERE deptNO=20 AND sal > ALL (SELECT sal FROM emp WHERE deptNO=30);

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    

SQL> 
SQL> SELECT * FROM emp WHERE sal > ALL (SELECT sal FROM emp WHERE deptNO=40);

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    

14 rows selected.

SQL> 
SQL> SELECT * FROM emp WHERE sal>(SELECT min(sal) FROM emp WHERE deptno=20);

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    

13 rows selected.

SQL> 
SQL> SELECT * FROM emp LEFT OUTER JOIN dept on emp.deptno=dept.deptno;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7934 MILLER     CLERK           7782 23/12/82       1300                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7839 KING       PRESIDENT            17/11/81       5000                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7902 FORD       ANALYST         7566 03/12/81       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20         20 RESEARCH       DALLAS                                                                                   
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7566 JONES      MANAGER         7839 02/04/81       2975                    20         20 RESEARCH       DALLAS                                                                                   
      7369 SMITH      CLERK           7902 17/12/80        800                    20         20 RESEARCH       DALLAS                                                                                   
      7900 JAMES      CLERK           7698 03/12/81        950                    30         30 SALES          CHICAGO                                                                                  
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30         30 SALES          CHICAGO                                                                                  
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30         30 SALES          CHICAGO                                                                                  

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30         30 SALES          CHICAGO                                                                                  
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30         30 SALES          CHICAGO                                                                                  
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30         30 SALES          CHICAGO                                                                                  

14 rows selected.

SQL> 
SQL> SELECT * FROM emp RIGHT OUTER JOIN dept on emp.deptno=dept.deptno;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7369 SMITH      CLERK           7902 17/12/80        800                    20         20 RESEARCH       DALLAS                                                                                   
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30         30 SALES          CHICAGO                                                                                  
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30         30 SALES          CHICAGO                                                                                  
      7566 JONES      MANAGER         7839 02/04/81       2975                    20         20 RESEARCH       DALLAS                                                                                   
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30         30 SALES          CHICAGO                                                                                  
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30         30 SALES          CHICAGO                                                                                  
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7839 KING       PRESIDENT            17/11/81       5000                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30         30 SALES          CHICAGO                                                                                  
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20         20 RESEARCH       DALLAS                                                                                   

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7900 JAMES      CLERK           7698 03/12/81        950                    30         30 SALES          CHICAGO                                                                                  
      7902 FORD       ANALYST         7566 03/12/81       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7934 MILLER     CLERK           7782 23/12/82       1300                    10         10 ACCOUNTING     NEW YORK                                                                                 
                                                                                             40 OPERATIONS     BOSTON                                                                                   

15 rows selected.

SQL> 
SQL> SELECT * FROM emp full OUTER JOIN dept on emp.deptno=dept.deptno;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7369 SMITH      CLERK           7902 17/12/80        800                    20         20 RESEARCH       DALLAS                                                                                   
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30         30 SALES          CHICAGO                                                                                  
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30         30 SALES          CHICAGO                                                                                  
      7566 JONES      MANAGER         7839 02/04/81       2975                    20         20 RESEARCH       DALLAS                                                                                   
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30         30 SALES          CHICAGO                                                                                  
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30         30 SALES          CHICAGO                                                                                  
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7839 KING       PRESIDENT            17/11/81       5000                    10         10 ACCOUNTING     NEW YORK                                                                                 
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30         30 SALES          CHICAGO                                                                                  
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20         20 RESEARCH       DALLAS                                                                                   

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO     DEPTNO DNAME          LOC                                                                                      
---------- ---------- --------- ---------- -------- ---------- ---------- ---------- ---------- -------------- -------------                                                                            
      7900 JAMES      CLERK           7698 03/12/81        950                    30         30 SALES          CHICAGO                                                                                  
      7902 FORD       ANALYST         7566 03/12/81       3000                    20         20 RESEARCH       DALLAS                                                                                   
      7934 MILLER     CLERK           7782 23/12/82       1300                    10         10 ACCOUNTING     NEW YORK                                                                                 
                                                                                             40 OPERATIONS     BOSTON                                                                                   

15 rows selected.

SQL> 
SQL> SELECT deptno FROM dept WHERE EXISTS(SELECT deptno FROM emp)
  2  UNION
  3  SELECT deptno FROM emp WHERE EXISTS(SELECT deptno FROM dept);

    DEPTNO                                                                                                                                                                                              
----------                                                                                                                                                                                              
        10                                                                                                                                                                                              
        20                                                                                                                                                                                              
        30                                                                                                                                                                                              
        40                                                                                                                                                                                              

SQL> 
SQL> SELECT * FROM emp WHERE deptno IS NOT NULL;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                                                                    
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                                                                    
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                                                                    
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                                                                    

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                                                                    

14 rows selected.

SQL> 
SQL> SELECT * FROM emp WHERE deptno is NULL;

no rows selected

SQL> 
SQL> SELECT * FROM dept WHERE deptno not in (SELECT deptno FROM emp);

    DEPTNO DNAME          LOC                                                                                                                                                                           
---------- -------------- -------------                                                                                                                                                                 
        40 OPERATIONS     BOSTON                                                                                                                                                                        

SQL> 
SQL> SELECT * FROM emp WHERE sal>(SELECT avg(sal) FROM emp WHERE deptno=emp.deptno);

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                                                                    
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                                                                    
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                                                                    
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                                                                    
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    

6 rows selected.

SQL> 
SQL> SELECT ename, hiredate FROM emp WHERE extract(YEAR FROM HIREDATE) = 1981;

ENAME      HIREDATE                                                                                                                                                                                     
---------- --------                                                                                                                                                                                     
ALLEN      20/02/81                                                                                                                                                                                     
WARD       22/02/81                                                                                                                                                                                     
JONES      02/04/81                                                                                                                                                                                     
MARTIN     28/09/81                                                                                                                                                                                     
BLAKE      01/05/81                                                                                                                                                                                     
CLARK      09/06/81                                                                                                                                                                                     
KING       17/11/81                                                                                                                                                                                     
TURNER     08/09/81                                                                                                                                                                                     
JAMES      03/12/81                                                                                                                                                                                     
FORD       03/12/81                                                                                                                                                                                     

10 rows selected.

SQL> 
SQL> SELECT * FROM emp WHERE ename LIKE 'F%';

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                                                                    
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                                                                    
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                                                                    

SQL> spool off
