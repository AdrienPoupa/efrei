21.03.2017
IL-TP-BASES AVANCEES
POUPA ADRIEN

SELECT ename, deptno,sal, avg(sal) OVER(PARTITION BY deptno) FROM emp;

SELECT ename, sal, dense_rank() OVER (ORDER BY sal) drank FROM emp;

SELECT ename, sal, deptno, LEAD(sal) over (ORDER BY sal) next_sal, LAG(sal) over (ORDER BY sal) prev_sal FROM emp ORDER BY sal ASC;

SELECT ename, SUM(sal) over(PARTITION BY DEPTNO) sum_dept,(SELECT SUM(sal) FROM EMP) sum_tot FROM emp;

SET PAGESIZE 14;
SET LINESIZE 150;
SELECT * FROM emp;

SET PAGESIZE 14;
SET LINESIZE 150;
SELECT empno, ename, job, mgr, hiredate, sal, comm, deptno FROM emp ORDER BY deptno ASC;
COMPUTE SUM OF sal ON report
BREAK ON report
COMPUTE SUM OF sal ON deptno
BREAK ON deptno
ttitle ‘EMP REPORT’
btitle ‘END REPORT’
CLEAR BREAKS;
CLEAR COMPUTE;
CLEAR COLUMNS;

ttitle OFF
btitle OFF
SET PAGESIZE 14;
SET LINESIZE 150;
COMPUTE SUM OF sal ON deptno
BREAK ON deptno
SELECT DEPTNO, JOB, SUM(SAL) FROM EMP GROUP BY CUBE(DEPTNO,JOB) ORDER BY DEPTNO ASC;
CLEAR BREAKS;
CLEAR COMPUTE;
CLEAR COLUMNS;

SET PAGESIZE 14;
SET LINESIZE 150;
COMPUTE SUM OF sal ON deptno
BREAK ON deptno
SELECT DEPTNO, JOB, SUM(SAL) FROM EMP GROUP BY ROLLUP(DEPTNO,JOB) ORDER BY DEPTNO ASC;
CLEAR BREAKS;
CLEAR COMPUTE;
CLEAR COLUMNS;

SELECT ename, sal, HIREDATE, AVG(sal) OVER(ORDER BY HIREDATE ASC ROWS BETWEEN 2 PRECEDING AND 1 PRECEDING) PRECEDINGS FROM emp;

SELECT ename, sal, AVG(sal) OVER (ORDER BY hiredate RANGE 90 PRECEDING) AVG_SAL FROM emp;
