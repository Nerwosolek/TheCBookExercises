BUILD_DIR="../../build/ex5.18"

tryText : tryTextRay.c 
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ../../lib/libraylib.a tryTextRay.c -o $(BUILD_DIR)/tryText

run :
	$(BUILD_DIR)/tryText

dcl: dcl.c getch.c
	clang dcl.c getch.c -o dcl
