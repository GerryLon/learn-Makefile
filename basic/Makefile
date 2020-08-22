
special-chars-target: spe1 spe2
	@echo "\$$@:" $@
	@echo "\$$^:" $^
	@echo "\$$<:" $<

spe1:
	@echo "spe1 target"

spe2:
	@echo "spe2 target"



# 演示@command的用法(不回显命令)
no-at:
	echo "no @ running"

at:
	@echo "@ running"


# 演示-command的用法(忽略错误)
no-slash:
	ls /etc/no-such-file
	echo "no-slash running"

slash:
	-ls /etc/no-such-file
	echo "slash running"


# 演示使用变量之 =
Options = -l $(Options_part)
Options_part = -i -a
var:
	@echo $(Options)
	@ls $(Options) /etc | head -5


# 演示使用变量之 :=
Options2 := -l $(Options2_part)
Options2_part = -i -a
var2:
	@echo $(Options2)
	@ls $(Options2) /etc | head -5


# 演示使用变量之 ?=
#PREFIX = /opt/soft
PREFIX ?= /usr/local
default-value:
	echo $(PREFIX)

aaa := hello
aaa-target:
	@echo $(aaa)
	
# 追加 +=
append_value = a b
append_value += c d
append-target:
	@echo $(append_value)


error-target:
	$(error "fatal error...")
	echo "the end"

warning-target:
	$(warning "warning msg...")
	@echo "continue"

.PHONY: test
test:
	echo hello

