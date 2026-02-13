.PHONY: all run cpp rust clean

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
RUSTC = rustc

TARGET_CPP = main_cpp
TARGET_RUST = main_rs

all: cpp

run:
	@:

cpp:
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET_CPP)
	./$(TARGET_CPP)

rust:
	$(RUSTC) main.rs -o $(TARGET_RUST)
	@if [ -f main.inp ]; then \
		./$(TARGET_RUST) < main.inp; \
	else \
		./$(TARGET_RUST); \
	fi

clean:
	rm -f $(TARGET_CPP) $(TARGET_RUST)
