all:
	gcc src/* -o target/fade-away-text.out

ostd:
	gcc src/ostd/* -o target/test.out

tui-lib:
	gcc src/tui-lib/* -o target/tui-lib.out

multi-threading:
	gcc src/multi-threading/* -o target/multi-threading.out

forest:
	gcc src/forest/* -o target/forest.out

refresh-syntax:
	gcc src/refresh-syntax/* -o target/fade-away-text.out
