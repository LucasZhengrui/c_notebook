--连接查询
--查询选修了一门以上课程的学生信息
select elective_course.stu_id,student.stu_name
from elective_course,student
where elective_course.stu_id=student.stu_id
group by elective_course.stu_id,student.stu_name
having count(*)>1;
// stu_id	stu_name
// 200215121	李勇
// 200215122	刘晨
--此为第一次自定义命题                

--嵌套查询
  --查询选了课程编号为1的学生姓名
  SELECT stu_name		           /*外层查询/父查询*/
  FROM student
  WHERE stu_id IN
               (SELECT stu_id             /*内层查询/子查询*/
                FROM elective_course
                WHERE course_id='1');
// stu_name
// 李勇

  --查询选修了一门以上课程的学生的平均成绩并按降序排列
  select student.stu_id,student.stu_name
  from student,elective_course
  where student.stu_id in
			  (select elective_course.stu_id
			   from elective_course,student
			   where elective_course.stu_id=student.stu_id
			   group by elective_course.stu_id,student.stu_name
		  	 having count(*)>1)
  group by student.stu_name,student.stu_id;
// stu_id	stu_name
// 200215121	李勇
// 200215122	刘晨
