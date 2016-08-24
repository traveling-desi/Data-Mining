export CXX = g++
export CFLAGS = 

BIN = kmeans_tester kernel_kmeans_tester
.PHONY: clean all

all: $(BIN)

kmeans_tester : src/kmeans_main.cpp src/utils/* src/clustering/k_means.h src/evaluation/*
kernel_kmeans_tester : src/kernel_kmeans_main.cpp src/utils/* src/clustering/k_means.h src/clustering/kernel_k_means.h src/evaluation/*

$(BIN) :
	$(CXX) $(CFLAGS) -o $@ $(filter %.cpp %.o %.c, $^)

clean :
	rm -rf $(BIN)
