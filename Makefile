executavel: classes.cpp b.tab.c lex.yy.c b.tab.h classes.hpp
	g++ b.tab.c lex.yy.c classes.cpp -o executavel
	
lex.yy.c: lex.l b.tab.c b.tab.h
	flex lex.l
	
b.tab.c: b.y
	bison -d b.y

clean:
	rm -f b.tab.c
	rm -f b.tab.h 
	rm -f lex.yy.c 
	rm -f executavel