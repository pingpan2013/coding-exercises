DIRS = ./Array ./Backtracking ./Dynamic\ Programming ./LinkedList\
       ./OODesign ./Others ./Recursion ./Sort\ and\ Search ./Tree\ and\ Graph\

all:  
	cd OODesign/; make 
	cd Array; make
	cd String; make
	cd Backtracking; make
	cd Recursion; make
	cd Dynamic\ programming; make
	cd Tree\ and\ graph; make
	cd LinkedList; make
	cd Others; make
	cd Sort\ and\ Search; make

clean: 
	cd OODesign/; make clean 
	cd Array; make clean
	cd String; make clean
	cd Backtracking; make clean
	cd Recursion; make clean
	cd Dynamic\ programming; make clean
	cd Tree\ and\ graph; make clean
	cd LinkedList; make clean
	cd Others; make clean
	cd Sort\ and\ Search; make clean

clobber: 
	cd OODesign/; make clobber 
	cd Array; make clobber
	cd String; make clobber
	cd Backtracking; make clobber
	cd Recursion; make clobber
	cd Dynamic\ programming; make clobber
	cd Tree\ and\ graph; make clobber
	cd LinkedList; make clobber
	cd Others; make clobber
	cd Sort\ and\ Search; make clobber


