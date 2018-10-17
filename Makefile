main : main.c ./modulea/stu.h ./moduleb/cou.h ./include/stucou.h ./release/cou.o ./release/stu.o
	gcc -I./include -I./modulea -I./moduleb -L./release  main.c ./release/cou.o ./release/stu.o -o main -lstu -lcou
main1 : main1.c ./modulea/stu.h ./moduleb/cou.h ./include/stucou.h ./release/cou.o ./release/stu.o
	gcc -I./include -I./modulea -I./moduleb -L./release  main1.c ./release/cou.o ./release/stu.o -o main1 -lstu -lcou
clean :
	rm ./release/*.o ./release/*.a ./release/*.so main main1
