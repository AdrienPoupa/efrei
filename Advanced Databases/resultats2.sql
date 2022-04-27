21.03.2017
IL-TP-BASES AVANCEES
POUPA ADRIEN

SQL> SELECT ename, deptno,sal, avg(sal) OVER(PARTITION BY deptno) FROM emp;

ENAME          DEPTNO        SAL AVG(SAL)OVER(PARTITIONBYDEPTNO)                
---------- ---------- ---------- -------------------------------                
CLARK              10       2450                      2916,66667                
KING               10       5000                      2916,66667                
MILLER             10       1300                      2916,66667                
JONES              20       2975                            2175                
FORD               20       3000                            2175                
ADAMS              20       1100                            2175                
SMITH              20        800                            2175                
SCOTT              20       3000                            2175                
WARD               30       1250                      1566,66667                
TURNER             30       1500                      1566,66667                
ALLEN              30       1600                      1566,66667                

ENAME          DEPTNO        SAL AVG(SAL)OVER(PARTITIONBYDEPTNO)                
---------- ---------- ---------- -------------------------------                
JAMES              30        950                      1566,66667                
BLAKE              30       2850                      1566,66667                
MARTIN             30       1250                      1566,66667                

14 rows selected.

SQL> 
SQL> SELECT ename, sal, dense_rank() OVER (ORDER BY sal) drank FROM emp;

ENAME             SAL      DRANK                                                
---------- ---------- ----------                                                
SMITH             800          1                                                
JAMES             950          2                                                
ADAMS            1100          3                                                
WARD             1250          4                                                
MARTIN           1250          4                                                
MILLER           1300          5                                                
TURNER           1500          6                                                
ALLEN            1600          7                                                
CLARK            2450          8                                                
BLAKE            2850          9                                                
JONES            2975         10                                                

ENAME             SAL      DRANK                                                
---------- ---------- ----------                                                
SCOTT            3000         11                                                
FORD             3000         11                                                
KING             5000         12                                                

14 rows selected.

SQL> 
SQL> SELECT ename, sal, deptno, LEAD(sal) over (ORDER BY sal) next_sal, LAG(sal) over (ORDER BY sal) prev_sal FROM emp ORDER BY sal ASC;

ENAME             SAL     DEPTNO   NEXT_SAL   PREV_SAL                          
---------- ---------- ---------- ---------- ----------                          
SMITH             800         20        950                                     
JAMES             950         30       1100        800                          
ADAMS            1100         20       1250        950                          
WARD             1250         30       1250       1100                          
MARTIN           1250         30       1300       1250                          
MILLER           1300         10       1500       1250                          
TURNER           1500         30       1600       1300                          
ALLEN            1600         30       2450       1500                          
CLARK            2450         10       2850       1600                          
BLAKE            2850         30       2975       2450                          
JONES            2975         20       3000       2850                          

ENAME             SAL     DEPTNO   NEXT_SAL   PREV_SAL                          
---------- ---------- ---------- ---------- ----------                          
SCOTT            3000         20       3000       2975                          
FORD             3000         20       5000       3000                          
KING             5000         10                  3000                          

14 rows selected.

SQL> 
SQL> SELECT ename, SUM(sal) over(PARTITION BY DEPTNO) sum_dept,(SELECT SUM(sal) FROM EMP) sum_tot FROM emp;

ENAME        SUM_DEPT    SUM_TOT                                                
---------- ---------- ----------                                                
CLARK            8750      29025                                                
KING             8750      29025                                                
MILLER           8750      29025                                                
JONES           10875      29025                                                
FORD            10875      29025                                                
ADAMS           10875      29025                                                
SMITH           10875      29025                                                
SCOTT           10875      29025                                                
WARD             9400      29025                                                
TURNER           9400      29025                                                
ALLEN            9400      29025                                                

ENAME        SUM_DEPT    SUM_TOT                                                
---------- ---------- ----------                                                
JAMES            9400      29025                                                
BLAKE            9400      29025                                                
MARTIN           9400      29025                                                

14 rows selected.

SQL> 
SQL> SET PAGESIZE 14;
SQL> SET LINESIZE 150;
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

SQL> 
SQL> SET PAGESIZE 14;
SQL> SET LINESIZE 150;
SQL> SELECT empno, ename, job, mgr, hiredate, sal, comm, deptno FROM emp ORDER BY deptno ASC;

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                  
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                  
      7782 CLARK      MANAGER         7839 09/06/81       2450                    10                                                                  
      7839 KING       PRESIDENT            17/11/81       5000                    10                                                                  
      7934 MILLER     CLERK           7782 23/12/82       1300                    10                                                                  
      7566 JONES      MANAGER         7839 02/04/81       2975                    20                                                                  
      7902 FORD       ANALYST         7566 03/12/81       3000                    20                                                                  
      7876 ADAMS      CLERK           7788 12/01/83       1100                    20                                                                  
      7369 SMITH      CLERK           7902 17/12/80        800                    20                                                                  
      7788 SCOTT      ANALYST         7566 09/12/82       3000                    20                                                                  
      7521 WARD       SALESMAN        7698 22/02/81       1250        500         30                                                                  
      7844 TURNER     SALESMAN        7698 08/09/81       1500          0         30                                                                  
      7499 ALLEN      SALESMAN        7698 20/02/81       1600        300         30                                                                  

     EMPNO ENAME      JOB              MGR HIREDATE        SAL       COMM     DEPTNO                                                                  
---------- ---------- --------- ---------- -------- ---------- ---------- ----------                                                                  
      7900 JAMES      CLERK           7698 03/12/81        950                    30                                                                  
      7698 BLAKE      MANAGER         7839 01/05/81       2850                    30                                                                  
      7654 MARTIN     SALESMAN        7698 28/09/81       1250       1400         30                                                                  

14 rows selected.

SQL> COMPUTE SUM OF sal ON report
SQL> BREAK ON report
SQL> COMPUTE SUM OF sal ON deptno
SQL> BREAK ON deptno
SQL> ttitle 'EMP REPORT'
SQL> btitle 'END REPORT'
SQL> CLEAR BREAKS;
breaks cleared
SQL> CLEAR COMPUTE;
computes cleared
SQL> CLEAR COLUMNS;
columns cleared
SQL> 
SQL> ttitle OFF
SQL> btitle OFF
SQL> SET PAGESIZE 14;
SQL> SET LINESIZE 150;
SQL> COMPUTE SUM OF sal ON deptno
SQL> BREAK ON deptno
SQL> SELECT DEPTNO, JOB, SUM(SAL) FROM EMP GROUP BY CUBE(DEPTNO,JOB) ORDER BY DEPTNO ASC;

    DEPTNO JOB         SUM(SAL)                                                                                                                       
---------- --------- ----------                                                                                                                       
        10 CLERK           1300                                                                                                                       
           MANAGER         2450                                                                                                                       
           PRESIDENT       5000                                                                                                                       
                           8750                                                                                                                       
        20 ANALYST         6000                                                                                                                       
           CLERK           1900                                                                                                                       
           MANAGER         2975                                                                                                                       
                          10875                                                                                                                       
        30 CLERK            950                                                                                                                       
           MANAGER         2850                                                                                                                       
           SALESMAN        5600                                                                                                                       

    DEPTNO JOB         SUM(SAL)                                                                                                                       
---------- --------- ----------                                                                                                                       
        30                 9400                                                                                                                       
           ANALYST         6000                                                                                                                       
           CLERK           4150                                                                                                                       
           MANAGER         8275                                                                                                                       
           PRESIDENT       5000                                                                                                                       
           SALESMAN        5600                                                                                                                       
                          29025                                                                                                                       

18 rows selected.

SQL> CLEAR BREAKS;
breaks cleared
SQL> CLEAR COMPUTE;
computes cleared
SQL> CLEAR COLUMNS;
columns cleared
SQL> 
SQL> SET PAGESIZE 14;
SQL> SET LINESIZE 150;
SQL> COMPUTE SUM OF sal ON deptno
SQL> BREAK ON deptno
SQL> SELECT DEPTNO, JOB, SUM(SAL) FROM EMP GROUP BY ROLLUP(DEPTNO,JOB) ORDER BY DEPTNO ASC;

    DEPTNO JOB         SUM(SAL)                                                                                                                       
---------- --------- ----------                                                                                                                       
        10 CLERK           1300                                                                                                                       
           MANAGER         2450                                                                                                                       
           PRESIDENT       5000                                                                                                                       
                           8750                                                                                                                       
        20 ANALYST         6000                                                                                                                       
           CLERK           1900                                                                                                                       
           MANAGER         2975                                                                                                                       
                          10875                                                                                                                       
        30 CLERK            950                                                                                                                       
           MANAGER         2850                                                                                                                       
           SALESMAN        5600                                                                                                                       

    DEPTNO JOB         SUM(SAL)                                                                                                                       
---------- --------- ----------                                                                                                                       
        30                 9400                                                                                                                       
                          29025                                                                                                                       

13 rows selected.

SQL> CLEAR BREAKS;
breaks cleared
SQL> CLEAR COMPUTE;
computes cleared
SQL> CLEAR COLUMNS;
columns cleared
SQL> 
SQL> SELECT ename, sal, HIREDATE, AVG(sal) OVER(ORDER BY HIREDATE ASC ROWS BETWEEN 2 PRECEDING AND 1 PRECEDING) PRECEDINGS FROM emp;

ENAME             SAL HIREDATE PRECEDINGS                                                                                                             
---------- ---------- -------- ----------                                                                                                             
SMITH             800 17/12/80                                                                                                                        
ALLEN            1600 20/02/81        800                                                                                                             
WARD             1250 22/02/81       1200                                                                                                             
JONES            2975 02/04/81       1425                                                                                                             
BLAKE            2850 01/05/81     2112,5                                                                                                             
CLARK            2450 09/06/81     2912,5                                                                                                             
TURNER           1500 08/09/81       2650                                                                                                             
MARTIN           1250 28/09/81       1975                                                                                                             
KING             5000 17/11/81       1375                                                                                                             
JAMES             950 03/12/81       3125                                                                                                             
FORD             3000 03/12/81       2975                                                                                                             

ENAME             SAL HIREDATE PRECEDINGS                                                                                                             
---------- ---------- -------- ----------                                                                                                             
SCOTT            3000 09/12/82       1975                                                                                                             
MILLER           1300 23/12/82       3000                                                                                                             
ADAMS            1100 12/01/83       2150                                                                                                             

14 rows selected.

SQL> 
SQL> SELECT ename, sal, AVG(sal) OVER (ORDER BY hiredate RANGE 90 PRECEDING) AVG_SAL FROM emp;

ENAME             SAL    AVG_SAL                                                                                                                      
---------- ---------- ----------                                                                                                                      
SMITH             800        800                                                                                                                      
ALLEN            1600       1200                                                                                                                      
WARD             1250 1216,66667                                                                                                                      
JONES            2975 1941,66667                                                                                                                      
BLAKE            2850    2168,75                                                                                                                      
CLARK            2450 2758,33333                                                                                                                      
TURNER           1500       1500                                                                                                                      
MARTIN           1250       1375                                                                                                                      
KING             5000 2583,33333                                                                                                                      
JAMES             950       2340                                                                                                                      
FORD             3000       2340                                                                                                                      

ENAME             SAL    AVG_SAL                                                                                                                      
---------- ---------- ----------                                                                                                                      
SCOTT            3000       3000                                                                                                                      
MILLER           1300       2150                                                                                                                      
ADAMS            1100       1800                                                                                                                      

14 rows selected.

SQL> spool off
