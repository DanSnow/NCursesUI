build_tool:= $(shell cmake --version && echo 'cmake' || echo 'compile')

all: $(build_tool)

cmake:
	# [ -f build/CMakeCache.txt ]\
	# && [ "$$(pwd)" != "$$(grep 'CMAKE_HOME_DIRECTORY:INTERNAL' build/CMakeCache.txt | cut -d '=' -f 2)" ] \
	# && rm -rf build || true
	rm -rf build
	mkdir -p build && cd build && cmake .. && make

compile: src example
.PHONY: compile

src:
	make -C src
.PHONY: src

example:
	make -C example
.PHONY: example

clean:
	[ -f build/CMakeCache.txt ]\
		&& make -C build clean || true
	rm -rf build
