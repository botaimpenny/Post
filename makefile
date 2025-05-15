all:
	g++ main.cpp package.cpp post.cpp -o pack
	./pack
clean:
	rm -f pack
