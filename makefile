build: compile link clean

compile:
	g++ -c *.cpp -I".\Externals\include"

link:
	g++ *.o -o main -L".\Externals\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

clean:
	rm *.o

debugcompile:
	g++ -c -g *.cpp # -I".\Externals\include" -DSFML_STATIC

debug: debugcompile link clean
	gdb -x debug.gdb main.exe