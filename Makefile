all:
	mkdir -p build && cd build && cmake .. && make

run:
	./build/generate_profile

clean:
	rm -rf build/
