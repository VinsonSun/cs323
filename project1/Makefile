clean:
	@rm -rf bin/
	@rm -rf lex.yy.* syntax.tab.*
splc:
	clean
	@mkdir bin
	touch bin/splc
	@chmod +x bin/splc
	flex lex.l && bsion -t -d syntax.y && gcc main.c tree.c syntax.tab.c -lfl -ly -o ./bin/splc
.PHONY: splc
