#/bin/bash
read -p "定制产品形态:(输入1从文件读入数据，输入其他从键盘输入数据)" i
if [ $i -eq 1 ]
then
	cd modulea&&make
	cd ..
	cd moduleb&&make
	cd ..
	ar rsv ./release/libstu.a ./release/stu.o
	gcc -shared -o ./release/libcou.so ./release/cou.o
	make main
	LD_LIBRARY_PATH=./release
	clear
	echo "学生表和课程表数据为:"
	./main
else
	cd modulea&&make
	cd ..
	cd moduleb&&make
	cd ..
	ar rsv ./release/libstu.a ./release/stu.o
	gcc -shared -o ./release/libcou.so ./release/cou.o
	make main1
	LD_LIBRARY_PATH=./release
	clear
	./main1
fi
clear
read -p "是否要查看日志文件(输入1查看,其他不查看):" i
if [ $i -eq 1 ]
then
	cat log.log
fi

