SELECT * FROM emp;
SELECT * FROM emp JOIN dept on dept.deptno=emp.deptno WHERE dept.loc= 'NEW YORK';
SELECT * FROM emp WHERE comm>0;

SELECT * FROM emp WHERE mgr IS NOT NULL;
SELECT * FROM emp WHERE mgr is NULL;
SELECT * FROM emp WHERE job = 'SALESMAN' OR job = 'ANALYST'
SELECT * FROM emp JOIN dept ON dept.deptno=emp.deptno WHERE emp.job='CLERK' AND dept.loc='CHICAGO';

SELECT * FROM emp WHERE sal > 3000;

SELECT UPPER(ENAME) FROM emp;
SELECT INITCAP(ENAME) FROM emp;
SELECT SUBSTR(ENAME,3,2) FROM emp;

SELECT * FROM emp order by hiredate desc;
SELECT * FROM emp order by comm desc NULLs last;

SELECT ename, deptno, avg(sal) over(partition by deptno) FROM emp;
SELECT deptno, MIN(sal), MAX(sal), COUNT(empno) FROM emp GROUP BY deptno;

SELECT * FROM emp WHERE deptNO=20 AND sal > ALL (SELECT sal FROM emp WHERE deptNO=30);

SELECT * FROM emp WHERE sal > ALL (SELECT sal FROM emp WHERE deptNO=40);

SELECT * FROM emp WHERE sal>(SELECT min(sal) FROM emp WHERE deptno=20);

SELECT * FROM emp LEFT OUTER JOIN dept on emp.deptno=dept.deptno;

SELECT * FROM emp RIGHT OUTER JOIN dept on emp.deptno=dept.deptno;

SELECT * FROM emp full OUTER JOIN dept on emp.deptno=dept.deptno;

SELECT deptno FROM dept WHERE EXISTS(SELECT deptno FROM emp)
UNION
SELECT deptno FROM emp WHERE EXISTS(SELECT deptno FROM dept);

SELECT * FROM emp WHERE deptno IS NOT NULL;

SELECT * FROM emp WHERE deptno is NULL;

SELECT * FROM dept WHERE deptno not in (SELECT deptno FROM emp);

SELECT * FROM emp WHERE sal>(SELECT avg(sal) FROM emp WHERE deptno=emp.deptno);

SELECT ename, hiredate FROM emp WHERE extract(YEAR FROM HIREDATE) = 1981;

SELECT * FROM emp WHERE ename LIKE 'F%';