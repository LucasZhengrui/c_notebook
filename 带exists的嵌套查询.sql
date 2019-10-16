--带exists的嵌套查询
  --例3.63 查询至少选修了学生200215122选修的全部课程的学生号码
    select distinct stu_id
    from elective_course ECX
    where not exists
		  (select *
		   from elective_course ECY
		   where ECY.stu_id = '200215122' and not exists
				(select *
				 from elective_course ECZ
				 where ECZ.stu_id = ECX.stu_id and
					   ECZ.course_id = ECY.course_id)
		  );

      -- stu_id
      -- 200215121
      -- 200215122

  --用另一种除了exists嵌套查询的方法解决
    select stu_id
	from elective_course
	where course_id in
			(select course_id
			 from elective_course
			 where stu_id='200215122')
	group by stu_id;
-- stu_id
-- 200215121
-- 200215122
-- 200215123
