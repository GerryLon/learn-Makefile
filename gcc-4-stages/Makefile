
.PHONY: preprocess compile assembly link

# 预处理
preprocess:
	gcc -E hello.c -o hello.i

# 编译
compile: preprocess
	gcc -S hello.i -o hello.s


# 汇编
assembly: compile
	gcc -c hello.s -o hello.o


# 链接
link: assembly
	gcc hello.o -o hello.out

.PHONY: clean
clean:
	rm -vf hello.i hello.s hello.o hello.out
