#######################################################################
# 編譯設定
#######################################################################
CC = gcc
CPP = g++
LD = ld
# 編譯時期想要 define 的變數(-D變數) 或 include 的目錄(-I目錄)
CFLAGS = -Wall -fno-builtin -fno-stack-protector -g

# 連結時要搜尋 LIBS 的目錄(-L目錄)
LDFLAGS = -nostdlib -nodefaultlibs

# 要連結的函式庫(-l函式庫)
LIBS =

#######################################################################
# common modules
#######################################################################

# 最終的程式名稱
PROG = tiny_hello

# 專案中所有要編譯原始碼的目的檔
OBJS = unistd.o crt.o tiny_hello.o

#######################################################################
# Make Rules
#######################################################################

.PHONY: all run clean clean-all

#副檔名列表
.SUFFIXES: .c .o

all: $(PROG)

$(PROG): $(OBJS)
	$(LD) $(LDFLAGS) -o $(PROG) $(OBJS) $(LIBS)

#有列在副檔名列表中的才能使用.c.o，否則可使用 %.o:%.c
#.c.o: 	$(CC) $(CFLAGS) -c $*.c
	
$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $*.c

run: $(PROG)
	./$(PROG)
	
clean:
	rm -f $(OBJS)

dist-clean:
	rm -f $(OBJS) $(PROG)
	
	
#######################################################################
# 自動變數
#######################################################################
# $@  工作目標檔名
# $<  第一個必備條件
# $^  所有必備條件，去掉重複的
# $+  所有必備條件，包含重複的
# $*  工作目標的主檔名
